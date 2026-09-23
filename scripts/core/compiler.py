import subprocess
import os
import logging

logger = logging.getLogger(__name__)

class Compiler:
    def __init__(self, defs: list[str], vnum: int):
        self.defs = defs
        self.vnum = vnum
        self.gcc_cmd = 'riscv64-linux-gnu-gcc'
        self.objcopy_cmd = 'riscv64-linux-gnu-objcopy'

    def compile_stubs(self, src_file: str, obj_file: str):
        cmd = [self.gcc_cmd] + self.defs + [f'-DVNUM={self.vnum}', '-c', '-nostdlib', '-o', obj_file, src_file]
        logger.debug(f"Compiling: {' '.join(cmd)}")
        subprocess.run(cmd, check=True)

    def extract_section(self, obj_file: str, section: str, bin_file: str):
        cmd = [self.objcopy_cmd, '-O', 'binary', '-j', section, obj_file, bin_file]
        logger.debug(f"Extracting section {section}: {' '.join(cmd)}")
        subprocess.run(cmd, check=True)

    def read_section(self, obj_file: str, section: str) -> bytes:
        tmp_bin = f"{obj_file}.tmp.bin"
        self.extract_section(obj_file, section, tmp_bin)
        with open(tmp_bin, 'rb') as f:
            data = f.read()
        os.remove(tmp_bin)
        return data

    def get_symbols(self, obj_file: str) -> dict[str, int]:
        out = subprocess.check_output(['riscv64-linux-gnu-readelf', '-s', obj_file]).decode()
        symbols = {}
        for line in out.splitlines():
            parts = line.split()
            if len(parts) >= 8 and parts[4] == 'GLOBAL':
                name = parts[7]
                addr = int(parts[1], 16)
                symbols[name] = addr
        return symbols

