import struct
import logging

logger = logging.getLogger(__name__)

class Patcher:
    def __init__(self, data: bytearray, load_addr: int = 0x1c005000):
        self.data = data
        self.load_addr = load_addr

    def find(self, pattern: bytes, start: int = 0) -> int:
        idx = self.data.find(pattern, start)
        return idx

    def find_all(self, pattern: bytes) -> list[int]:
        res = []
        idx = 0
        while True:
            idx = self.data.find(pattern, idx)
            if idx == -1:
                break
            res.append(idx)
            idx += len(pattern)
        return res

    def read_bytes(self, offset: int, length: int) -> bytes:
        return bytes(self.data[offset:offset+length])

    def write_bytes(self, offset: int, b: bytes):
        self.data[offset:offset+len(b)] = b

    def read_u32(self, offset: int) -> int:
        return struct.unpack_from('<I', self.data, offset)[0]

    def enc_j(self, rd: int, pc: int, target: int) -> bytes:
        imm = target - pc
        if not (-1048576 <= imm <= 1048574):
            raise ValueError(f"Jump too far: offset {imm:#x} from {pc:#x} to {target:#x}")
        
        imm19_12 = (imm >> 12) & 0xff
        imm11_j  = (imm >> 11) & 0x1
        imm10_1  = (imm >> 1)  & 0x3ff
        imm20_j  = (imm >> 20) & 0x1
        
        imm_enc = (imm20_j << 31) | (imm10_1 << 21) | (imm11_j << 20) | (imm19_12 << 12)
        instr = imm_enc | ((rd & 0x1f) << 7) | 0x6f
        return struct.pack('<I', instr)

    def patch_jump(self, file_off: int, target_vma: int, rd: int = 1, name: str = ""):
        if not (0 <= file_off < len(self.data) - 4):
            raise ValueError(f"Invalid file offset: {file_off:#x}")
        
        pc = self.load_addr + file_off
        jmp_bytes = self.enc_j(rd, pc, target_vma)
        self.write_bytes(file_off, jmp_bytes)
        
        if name:
            instr = 'jal' if rd else 'j'
            logger.debug(f"[{name}] @0x{file_off:05x}: {instr} 0x{target_vma:x} (bytes: {jmp_bytes.hex()})")

    def calc_irom_checksum(self):
        # IROM Checksum: sum8[0:0x8da0] + 0x15 == byte[0x08] (which is 0x42)
        # So sum8[0:0x8da0] must equal 0x2D. Adjustment byte is at 0x7D28.
        s = sum(self.data[:0x8da0]) & 0xFF
        delta = (0x2D - s) & 0xFF
        old = self.data[0x7D28]
        self.data[0x7D28] = (old + delta) & 0xFF
        
        s2 = sum(self.data[:0x8da0]) & 0xFF
        if s2 != 0x2D:
            raise RuntimeError(f"IROM Checksum calculation failed: expected 0x2D, got {s2:#x}")
        
        logger.debug(f"IROM Checksum updated: byte 0x7D28 was {old:#x}, now {self.data[0x7D28]:#x}. Sum matches.")

