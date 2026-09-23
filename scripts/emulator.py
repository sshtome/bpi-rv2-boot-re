import struct
import sys
import os

from unicorn import *
from unicorn.riscv_const import *

class BPIEmulator:
    def __init__(self, bin_path):
        self.bin_path = bin_path
        self.mu = Uc(UC_ARCH_RISCV, UC_MODE_RISCV64)
        
        self.setup_memory()
        self.load_bin()
        self.setup_hooks()
        
    def setup_memory(self):
        self.mu.mem_map(0x1C000000, 1 * 1024 * 1024)
        self.mu.mem_map(0x0C301000, 4 * 1024)
        self.mu.mem_map(0x0A000000, 8 * 1024 * 1024)
        self.mu.mem_map(0xCE000000, 16 * 1024 * 1024)

    def load_bin(self):
        with open(self.bin_path, 'rb') as f:
            data = f.read()
        self.mu.mem_write(0x1C004F90, data[:0x8da0])
        self.mu.mem_write(0x1C005000 + 0x8da0, data[0x8da0:0x20000])

    def setup_hooks(self):
        self.mu.hook_add(UC_HOOK_MEM_READ, self.hook_mem_read)
        self.mu.hook_add(UC_HOOK_MEM_WRITE, self.hook_mem_write)
        self.mu.hook_add(UC_HOOK_MEM_UNMAPPED, self.hook_unmapped)
        self.mu.hook_add(UC_HOOK_CODE, self.hook_code)
        
    def hook_code(self, mu, address, size, user_data):
        if address == 0x1c005034:
            print("Reached 0x1c005034")

    def hook_unmapped(self, mu, type, address, size, value, user_data):
        print(f"\n[UNMAPPED] type {type} at {address:#x}, pc={mu.reg_read(UC_RISCV_REG_PC):#x}")
        # mu.mem_map(address & ~0xFFF, 0x1000)
        return False
        
    def hook_mem_read(self, mu, access, address, size, value, user_data):
        if address == 0x0C301018:
            mu.mem_write(0x0C301018, b'\x80\x00\x00\x00')
            
    def hook_mem_write(self, mu, access, address, size, value, user_data):
        if address == 0x0C301000:
            b = value & 0xFF
            char = chr(b) if 32 <= b <= 126 or b == 10 or b == 13 else '.'
            sys.stdout.write(char)
            sys.stdout.flush()

    def run(self):
        print("Starting emulation from 0x1C005000...")
        try:
            self.mu.reg_write(UC_RISCV_REG_SP, 0x1C00F000)
            self.mu.emu_start(0x1C005000, 0x1C00837A) 
            print("\nEmulation stopped at parser (0x1C00837A)")
        except UcError as e:
            pc = self.mu.reg_read(UC_RISCV_REG_PC)
            print(f"\nError: {e} at PC={pc:#x}")

if __name__ == '__main__':
    emu = BPIEmulator('build/custom_fbl_157v1_new.bin')
    emu.run()
