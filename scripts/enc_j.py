#!/usr/bin/env python3
"""enc_j.py — транслятор абсолютных адресов в инструкции JAL/J (RISC-V RV64).

Правила трансляции адресов проекта (установлены экспериментально):
    файловое_смещение = dis_адрес − 0x1C005000
    реальная память:    файл[X] → 0x1C004F90 + X   (код)
                        файл[X≥0x8DA0] → 0x1C005000 + X  (зона, БЕЗ −0x70)
Диапазон JAL: ±1 МБ (imm[20:1]).

Использование:
    python3 enc_j.py pc <pc_hex> target <target_hex> [rd N]
        -> байты инструкции (little-endian) и обратная проверка
    python3 enc_j.py dis2file <dis_hex>          -> файловое смещение
    python3 enc_j.py file2real <file_hex>        -> реальный адрес (код)
"""
import sys

LOAD = 0x1C005000       # база дизассемблера (VMA)


def enc_j(rd, pc, target):
    delta = target - pc
    assert delta % 2 == 0 and -2**20 <= delta < 2**20, \
        f"переход вне диапазона ±1 МБ: {hex(delta)}"
    instr  = ((delta >> 20) & 1) << 31
    instr |= ((delta >> 1) & 0x3FF) << 21
    instr |= ((delta >> 11) & 1) << 20
    instr |= ((delta >> 12) & 0xFF) << 12
    instr |= (rd & 0x1F) << 7
    instr |= 0x6F
    return instr, delta


def dec_j(instr):
    rd = (instr >> 7) & 0x1F
    imm  = ((instr >> 31) & 1) << 20
    imm |= ((instr >> 12) & 0xFF) << 12
    imm |= ((instr >> 20) & 1) << 11
    imm |= ((instr >> 21) & 0x3FF) << 1
    if imm & (1 << 20):
        imm -= 1 << 21
    return rd, imm


def main():
    a = sys.argv[1:]
    if a and a[0] == "pc":
        pc, target, rd = int(a[1], 16), int(a[3], 16), 1
        if "rd" in a:
            rd = int(a[a.index("rd") + 1])
        instr, delta = enc_j(rd, pc, target)
        b = instr.to_bytes(4, 'little')
        print(f"pc={pc:#x} target={target:#x} delta={delta:+d}")
        print(f"jal x{rd}, target  ->  байты: {b.hex(' ')}  (LE u32: 0x{instr:08X})")
        rrd, rdelta = dec_j(instr)
        print(f"обратная проверка: rd={rrd}, delta={rdelta}, "
              f"pc+delta={pc + rdelta:#x}")
    elif a and a[0] == "dis2file":
        dis = int(a[1], 16)
        print(f"{dis:#x} -> файл 0x{dis - LOAD:X}")
    elif a and a[0] == "file2real":
        off = int(a[1], 16)
        print(f"файл 0x{off:X} -> 0x{0x1C004F90 + off:X} (код) / "
              f"0x{LOAD + off:X} (зона, ≥0x8DA0)")
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
