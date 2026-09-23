from scripts.patches.base import Patch, Context
from scripts.core.patcher import Patcher
import logging

logger = logging.getLogger(__name__)

class LinkStubsPatch(Patch):
    @property
    def name(self) -> str:
        return "Link ASM Stubs and Hooks"

    def apply(self, patcher: Patcher, ctx: Context):
        # V2 base minimal patch
        patcher.write_bytes(0x0d06, bytes.fromhex("6ff00143"))

        # 1. Inject sections
        dbg_len = len(ctx.dbg_code)
        if ctx.DBG_OFF + dbg_len > 0x8DA0:
            raise ValueError(f"dbg section too large: {dbg_len} bytes")
        
        patcher.write_bytes(ctx.DBG_OFF, ctx.dbg_code)
        logger.info(f"Injected dbg section at {ctx.DBG_OFF:#x} (VMA: {ctx.DBG_VMA:#x}), length: {dbg_len}")

        patcher.write_bytes(0xd08, ctx.normini_code)
        patcher.write_bytes(0x35c, ctx.ddrload_code)

        # Helper to find PRO sequence
        PRO = b'\x13\x01\x01\xff\x23\x34\x11\x00'

        def DEAD(code: int) -> bytes:
            return (0xDEAD0000 + code).to_bytes(4, "little")

        # 2. Find hook markers using symbols or pattern fallback
        def find_marker(name: str, pattern1: bytes, pattern2: bytes = b'') -> int:
            if name in ctx.symbols:
                return ctx.DBG_VMA + ctx.symbols[name]
            idx = ctx.dbg_code.find(pattern1)
            if idx == -1 and pattern2:
                idx = ctx.dbg_code.find(pattern2)
            if idx == -1:
                raise ValueError(f"Marker {name} not found in dbg code")
            return ctx.DBG_VMA + idx

        ctx.M_SKIP = find_marker('M_SKIP', PRO + b'\x13\x05\xc0\x03', b'\x37\x05\x55\x08\x67\x80\x00\x00')
        ctx.M_B = find_marker('M_B', PRO + b'\x13\x05\x20\x04')
        ctx.M_N = find_marker('M_N', PRO + b'\x13\x05\xe0\x04')
        ctx.M_D = find_marker('M_D', PRO + b'\x13\x05\x40\x04')
        ctx.M_P = find_marker('M_P', PRO + b'\x13\x05\x00\x05', b'\x13\x01\x01\xfe\x23\x3c\x11\x00\x23\x38\x81\x00\x13\x05\x00\x05')

        # 3. Resolve DEAD markers inside dbg
        targets = [
            (0x11, 0x1c008816, 1),
            (0x12, 0x1c00834e, 1),
            (0x16, 0x1c00b450, 0),
            (0x13, 0x1c00837a, 1 if ctx.variant >= 139 else 0)
        ]
        for code, target, rd in targets:
            p = ctx.dbg_code.find(DEAD(code))
            if p == -1:
                raise ValueError(f"DEAD{code:04X} not found")
            patcher.patch_jump(ctx.DBG_OFF + p, target, rd)

        # DEAD0015 -> 0x1c00b430 (multiple)
        idx = 0
        n15 = 0
        while True:
            idx = ctx.dbg_code.find(DEAD(0x15), idx)
            if idx == -1:
                break
            patcher.patch_jump(ctx.DBG_OFF + idx, 0x1c00b430, 0)
            idx += 4
            n15 += 1
        if n15 != 2:
            raise ValueError(f"Expected 2 DEAD0015, found {n15}")

        # P1 FUN_00000348 -> epilogue
        patcher.patch_jump(0x0356, patcher.load_addr + 0x38e, rd=0)

        # nor_load and printf hook
        if 'nor_load' in ctx.symbols:
            nor_load_vma = ctx.DBG_VMA + ctx.symbols['nor_load']
        else:
            p_nl = ctx.dbg_code.find(b'\x13\x01\x01\xff\x23\x34\x11\x00\x13\x05\x30\x05')
            nor_load_vma = ctx.DBG_VMA + p_nl if p_nl != -1 else 0
        if nor_load_vma:
            patcher.patch_jump(0x136e, nor_load_vma, rd=0)

        p_hook = ctx.dbg_code.find(b'\x37\x23\x00\x1c')
        if p_hook == -1:
            p_hook = ctx.dbg_code.find(b'\x37\xd3\x00\x1c')
        if p_hook != -1:
            printf_hook_vma = ctx.DBG_VMA + p_hook
            patcher.patch_jump(0x5b24, printf_hook_vma, rd=0)

        p5 = ctx.dbg_code.find(DEAD(5))
        if p5 != -1:
            patcher.patch_jump(ctx.DBG_OFF + p5, 0x1c00ab28, rd=0)

        # 4. Patch original code to jump to hooks
        patcher.patch_jump(0x518a, ctx.M_SKIP, rd=1, name="0x518a -> M_SKIP (SKIP PHY / Training, jal)")
        patcher.patch_jump(0x5190, 0x1c00a40a, rd=0, name="0x5190 -> epilogue")
        
        # M_B or M_N hook
        patcher.patch_jump(0x642c, ctx.M_B, rd=0, name="0x642c -> M_B (B+csrsi+b)")
        
        # M_D and M_P hooks
        patcher.patch_jump(0x644c, ctx.M_D, rd=0, name="0x644c -> M_D (D+FUN_0000334e)")
        patcher.patch_jump(0x647c, ctx.M_P, rd=0, name="0x647c -> M_P (P+parser)")

        # Fix C: Bypass calibration block hash check at 0x1c0093ac (file 0x43ac) -> jump directly to 0x1c0093ea
        patcher.patch_jump(0x43ac, 0x1c0093ea, rd=0, name="bypass calib hash check -> 0x1c0093ea")

        # Link M_SKIP internal jump
        p20 = ctx.dbg_code.find(DEAD(0x20))
        if p20 != -1:
            patcher.patch_jump(ctx.DBG_OFF + p20, 0x1c008f5a, rd=1, name="M_SKIP -> training")

        # P-DDR -> ddr_load2
        if 'ddr_load2' in ctx.symbols:
            ctx.DDR_LOAD2 = ctx.DBG_VMA + ctx.symbols['ddr_load2']
        else:
            p_dl = ctx.dbg_code.find(b'\x13\x01\x01\xff\x23\x34\x11\x00\x37\x95\x00\x00')
            if p_dl == -1:
                raise ValueError("ddr_load2 signature not found")
            ctx.DDR_LOAD2 = ctx.DBG_VMA + p_dl
        patcher.patch_jump(0x4b40, ctx.DDR_LOAD2, rd=1, name="P-DDR -> ddr_load2")

        # 0x1c009b44 link
        pc_ = ctx.dbg_code.find(DEAD(0x0C))
        if pc_ != -1:
            patcher.patch_jump(ctx.DBG_OFF + pc_, 0x1c009b44, rd=0)

        # nor_read_emul
        if 'nor_read_emul' in ctx.symbols:
            ctx.NOR_READ_EMUL = ctx.DBG_VMA + ctx.symbols['nor_read_emul']
        else:
            p_emul = ctx.dbg_code.find(b'\x13\x01\x01\xfe\x23\x3c\x11\x00')
            if p_emul == -1:
                p_emul = ctx.dbg_code.find(b'\x13\x01\x01\xff\x23\x34\x11\x00\xef')
            ctx.NOR_READ_EMUL = ctx.DBG_VMA + p_emul
        patcher.patch_jump(0xdc2, ctx.NOR_READ_EMUL, rd=0, name="0x1c005dc2 -> nor_read_emul")

        # EXSPI-init link
        p17 = ctx.dbg_code.find(DEAD(0x17))
        if p17 != -1:
            patcher.patch_jump(ctx.DBG_OFF + p17, 0x1c00530c, rd=1)

        # Keep libfdt intact in vendor FBL (0x2c46, 0x2572, 0x2b0c, 0x2592 are libfdt, not UBI!)

        # nor_read / ddrload resolution
        p10 = ctx.normini_code.find(DEAD(0x10))
        if p10 != -1:
            off10 = 0xd08 + p10
            patcher.patch_jump(off10, patcher.load_addr + 0xdd4, rd=1)

        for code, vma in [(1, ctx.NOR_READ_VMA), (2, 0x1c00ab24), (3, patcher.load_addr + 0x4b44)]:
            p = ctx.ddrload_code.find(DEAD(code))
            if p != -1:
                off = 0x35c + p
                patcher.patch_jump(off, vma, rd=1 if code != 3 else 0)

        # nor_read2 -> 0x1c005dd4
        p9 = ctx.dbg_code.find(DEAD(0x09))
        if p9 != -1:
            patcher.patch_jump(ctx.DBG_OFF + p9, 0x1c005dd4, rd=1)

        # nor_load->ret or printf hooks
        p2 = ctx.dbg_code.find(DEAD(0x02))
        if p2 != -1:
            patcher.patch_jump(ctx.DBG_OFF + p2, 0x1c00ab24, rd=1)


        
