#!/usr/bin/env python3
"""gen_placeholders.py — генератор и искатель плейсхолдеров DEAD000N.

Ассемблерные хуки (src/nor_stubs.S) ссылаются на абсолютные адреса
через плейсхолдеры .word 0xDEAD0000 + N, поскольку objcopy -O binary
не выполняет релокацию. На этапе сборки каждый плейсхолдер заменяется
настоящей инструкцией JAL (см. enc_j.py).

Реестр плейсхолдеров (актуальная схема):
    N=1  nor_read      (из ddr_load)
    N=2  printf 0x1C00AB24
    N=3  j 0x1C009B44  (продолжение DDR-функции)
    N=5  j тело printf (0x1C00AB28) — продолжение хука
    N=9  диспетчер 0x1C005DD4 (nor_read2)
    N=0xC j 0x1C009B44 (ddr_load2 -> DDR-функция)
    N=0xE j парсер 0x1C00837A (nor_load)
    N=0x10 диспетчер 0x1C005DD4 (nor_read)
    N=0x17 jal 0x1C00530C (EXSPI-инит)

Использование:
    python3 gen_placeholders.py enc <N_hex> <pc_hex> <target_hex> [rd]
        -> байты замены для плейсхолдера N на позиции pc
    python3 gen_placeholders.py find <binary> [N_hex]
        -> список смещений плейсхолдеров в бинарнике
"""
import sys

DEAD = 0xDEAD0000


def find_all(data, n=None):
    out = []
    for i in range(0, len(data) - 3, 2):
        w = int.from_bytes(data[i:i + 4], 'little')
        if (w & 0xFFFF0000) == DEAD & 0xFFFF0000 and w >> 16 == 0xDEAD:
            if n is None or w == DEAD + n:
                out.append((i, w - DEAD))
    return out


def main():
    a = sys.argv[1:]
    if not a:
        sys.exit(__doc__)
    if a[0] == "enc":
        n, pc, target = int(a[1], 16), int(a[2], 16), int(a[3], 16)
        rd = int(a[4]) if len(a) > 4 else 1
        # импорт enc_j из того же каталога
        import importlib.util, os
        spec = importlib.util.spec_from_file_location(
            "enc_j", os.path.join(os.path.dirname(__file__), "enc_j.py"))
        m = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(m)
        instr, delta = m.enc_j(rd, pc, target)
        b = instr.to_bytes(4, 'little')
        print(f"DEAD{n:04X} @{pc:#x} -> jal x{rd}, {target:#x} "
              f"(delta {delta:+d})  байты: {b.hex(' ')}")
    elif a[0] == "find":
        data = open(a[1], 'rb').read()
        n = int(a[2], 16) if len(a) > 2 else None
        hits = find_all(data, n)
        if not hits:
            print("плейсхолдеры не найдены")
        for off, num in hits:
            print(f"0x{off:05X}: DEAD{num:04X}")
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
