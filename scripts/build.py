import argparse
import logging
import os
import sys

from scripts.core.patcher import Patcher
from scripts.core.compiler import Compiler
from scripts.core.firmware import FirmwareImage
from scripts.patches.base import Context
from scripts.variants import VARIANTS

def setup_logging(debug: bool):
    level = logging.DEBUG if debug else logging.INFO
    logging.basicConfig(level=level, format='%(levelname)s: %(message)s')

def main():
    parser = argparse.ArgumentParser(description="BPI-RV2 FBL Builder")
    parser.add_argument("--variant", type=int, default=149, help="Variant number (default: 149 - release)")
    parser.add_argument("--debug", action="store_true", help="Enable debug logging")
    args = parser.parse_args()

    setup_logging(args.debug)
    logger = logging.getLogger("builder")

    if args.variant not in VARIANTS:
        logger.error(f"Variant {args.variant} not found in VARIANTS configuration")
        sys.exit(1)

    var_config = VARIANTS[args.variant]
    logger.info(f"== Building Variant {args.variant}: {var_config['name']} ==")

    # Prepare base firmware
    with open('bin_orig/fbl.bin', 'rb') as f:
        fbl_orig = f.read()
    with open('bin_orig/fbl_v2_tail.bin', 'rb') as f:
        fbl_tail = f.read()
        
    base_data = bytearray(fbl_orig + fbl_tail)
    
    # 0x0c is the size field in FBL header, historically v2 base had it updated
    base_data[0x0c:0x10] = len(base_data).to_bytes(4, 'little')

    patcher = Patcher(base_data)

    # Prepare context and compile ASM
    ctx = Context(variant=args.variant, vnum=53, defs=['-DV138PASS', '-DV139RET', '-DV144NOHEAD', '-DV35SB', '-DV157'])
    
    compiler = Compiler(defs=ctx.defs, vnum=ctx.vnum)
    os.makedirs('build', exist_ok=True)
    compiler.compile_stubs('src/nor_stubs.S', 'build/nor_stubs.o')
    
    ctx.dbg_code = compiler.read_section('build/nor_stubs.o', '.text.dbg')
    ctx.normini_code = compiler.read_section('build/nor_stubs.o', '.text.normini')
    ctx.ddrload_code = compiler.read_section('build/nor_stubs.o', '.text.ddrload')
    ctx.symbols = compiler.get_symbols('build/nor_stubs.o')

    logger.info(f"Sections compiled: nor_read={len(ctx.normini_code)}, ddr_load={len(ctx.ddrload_code)}, dbg={len(ctx.dbg_code)}")
    logger.info(f"Loaded {len(ctx.symbols)} symbols from object file")

    # Apply patches
    for patch in var_config['patches']:
        logger.info(f"Applying patch: {patch.name}")
        patch.apply(patcher, ctx)

    # Checksum and write
    patcher.calc_irom_checksum()
    
    out_fbl = "build/custom_fbl.bin"
    with open(out_fbl, 'wb') as f:
        f.write(patcher.data)
    logger.info(f"Saved custom FBL to {out_fbl}")

    # Build final NOR image
    with open('bin_orig/uboot.itb', 'rb') as f:
        uboot_data = f.read()
        
    fw = FirmwareImage(patcher.data, uboot_data)
    nor_img = fw.generate_nor_image()
    
    out_nor = "build/nor_full.bin"
    with open(out_nor, 'wb') as f:
        f.write(nor_img)
    logger.info(f"Saved final NOR image to {out_nor} ({len(nor_img)} bytes)")

if __name__ == '__main__':
    main()
