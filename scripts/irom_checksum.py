#!/usr/bin/env python3
"""irom_checksum.py — калькулятор/фиксатор контрольной суммы IROM (BootROM) FBL.

Формула (установлена экспериментально):
    add_checksum = ( sum8( файл[0x0000 : 0x8DA0] ) + 0x15 ) mod 256
    условие приёма:  add_checksum == файл[0x08]   (заводское значение 0x42)
    =>  sum8[0:0x8DA0] должно быть равно 0x2D

Подгонка суммы выполняется одним байтом rodata по смещению 0x7D28.
Замечание: поле 0x00 заголовка (размер загружаемого кода, 0x8DA0)
изменять НЕЛЬЗЯ — образ с другим значением отвергается IROM.

Использование:
    python3 irom_checksum.py check <fbl.bin>      # проверить сумму
    python3 irom_checksum.py fix   <fbl.bin>      # подогнать байтом @0x7D28
"""
import sys

CODE_SIZE = 0x8DA0          # размер кода, загружаемого IROM (поле 0x00)
ADD_BIAS  = 0x15            # смещение add_checksum
REQ_ADD   = 0x42            # заводское значение байта 0x08
FIX_OFF   = 0x7D28          # байт подгонки (в rodata)


def load(path):
    data = open(path, 'rb').read()
    if len(data) < CODE_SIZE:
        sys.exit(f"файл слишком мал: {len(data)} < {CODE_SIZE:#x}")
    return bytearray(data)


def report(data, label):
    s = sum(data[:CODE_SIZE]) & 0xFF
    add = (s + ADD_BIAS) & 0xFF
    ok = "OK" if add == REQ_ADD else "НЕ СХОДИТСЯ"
    print(f"{label}: sum8[0:{CODE_SIZE:#x}] = 0x{s:02X}, "
          f"add_checksum = 0x{add:02X} (нужно 0x{REQ_ADD:02X}) -> {ok}")
    return add == REQ_ADD


def main():
    if len(sys.argv) != 3 or sys.argv[1] not in ("check", "fix"):
        sys.exit(__doc__)
    cmd, path = sys.argv[1], sys.argv[2]
    data = load(path)

    if cmd == "check":
        report(data, path)
        return

    # fix: подгонка байтом FIX_OFF (сохраняет разницу при повторном прогоне)
    s = sum(data[:CODE_SIZE]) & 0xFF
    delta = (0x2D - s) & 0xFF
    old = data[FIX_OFF]
    data[FIX_OFF] = (old + delta) & 0xFF
    open(path, 'wb').write(data)
    print(f"fix: байт @0x{FIX_OFF:X}: 0x{old:02X} -> 0x{data[FIX_OFF]:02X}")
    report(data, path)
    if not report(data, path):
        sys.exit("ошибка подгонки")


if __name__ == "__main__":
    main()
