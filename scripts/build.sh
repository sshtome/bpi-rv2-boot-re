#!/bin/bash
# build.sh — сборка кастомного FBL для загрузки BPI-RV2 с NOR.
# ---------------------------------------------------------------------------
# Вход:   bin_orig/fbl.bin      — оригинальный заводской FBL (источник истины)
#         bin_orig/fbl_v2_tail.bin — хвост 0x3E8 б исторической базы v2
#         bin_orig/uboot.itb    — заводской FIT-образ u-boot
#         src/nor_stubs.S       — ассемблерные хуки (nor_read, ddr_load2,
#                                 nor_read2, nor_load, хук printf, dbg-UART)
# Выход:  build/custom_fbl_<TAG>.bin — пропатченный FBL
#         build/nor_full_<TAG>.bin   — полный образ NOR 16 МБ
#
# Запуск (WSL или Linux с toolchain RISC-V):
#     wsl bash scripts/build.sh [ВАРИАНТ]
#
# Требует: riscv64-linux-gnu-gcc, riscv64-linux-gnu-objcopy, python3.
#
# КЛЮЧЕВЫЕ ФАКТЫ (подробно — docs/BPI-RV2-TRM.md):
#  * IROM грузит ТОЛЬКО файл[0:0x8DA0] (поле 0x00 заголовка; менять нельзя);
#    заголовок [0:0x70] в память не попадает (сдвиг IROM).
#  * Чексумма IROM: sum8[0:0x8DA0] + 0x15 (mod 256) == файл[0x08] (0x42)
#    => sum8[0:0x8DA0] == 0x2D; подгонка байтом @0x7D28.
#  * Трансляция адресов: файл = dis − 0x1C005000; реальная память
#    файл[X] → 0x1C004F90 + X; зона файл[X≥0x8DA0] → 0x1C005000 + X.
#  * Абсолютные переходы — через плейсхолдеры DEAD000N (см. gen_placeholders.py).
# ---------------------------------------------------------------------------
set -e
cd "$(dirname "$0")/.."

FBL_ORIG="bin_orig/fbl.bin"
FBL_TAIL="bin_orig/fbl_v2_tail.bin"
ITB="bin_orig/uboot.itb"
STUBS="src/nor_stubs.S"
mkdir -p build

# ---------------------------------------------------------------------------
# 0. Подготовка базы из ОРИГИНАЛЬНОГО fbl.bin:
#    историческая база v2 = fbl.bin + поле размера @0x0C = 0x203E8 + хвост
# ---------------------------------------------------------------------------
make_base() {
    python3 - "$FBL_ORIG" "$FBL_TAIL" "build/.base.bin" <<'EOF'
import sys
orig, tail, out = sys.argv[1:4]
d = bytearray(open(orig, 'rb').read())
assert len(d) == 0x20000, f"неожиданный размер fbl.bin: {len(d):#x}"
assert d[0x04:0x08] == b"sa18", "заголовок sa18 не найден"

# Исторические патчи базы v2 (воспроизведены побайтово с custom_fbl_v2.bin):
#  * поле размера @0x0C = 0x203E8;
#  * 5 JAL-патчей в парсерной зоне — вызовы 0x1C007C46/7572/7B0C/7592
#    перенаправлены в стабы хвоста (0x1C025136/5204/523C/5240/534A);
#  * JAL @0xD06 — мёртвое тело FUN_00000d06 (перекрывается nor_read@0xD08).
V2_PATCHES = (
    (0x0D06, "6ff00143"),
    (0x33BB, "c0b164"),
    (0x33D9, "c05166"),
    (0x342D, "c05161"),
    (0x3491, "c0115b"),
    (0x352F, "c0d161"),
)
for off, hx in V2_PATCHES:
    b = bytes.fromhex(hx)
    d[off:off + len(b)] = b
d[0x0C:0x10] = (0x203E8).to_bytes(4, 'little')   # размер @0x0C
d += open(tail, 'rb').read()
assert len(d) == 0x203E8, f"размер базы: {len(d):#x}"
open(out, 'wb').write(d)
print(f"база готова: {len(d):#x} б (fbl.bin + {len(V2_PATCHES) + 1} патчей v2 + хвост)")
EOF
}
make_base
BASE="build/.base.bin"

# ---------------------------------------------------------------------------
# 1. Выбор варианта (веер гипотез; актуальная схема v135, варианты 35–42)
# ---------------------------------------------------------------------------
VARIANT="${1:-42}"
if   [ "$VARIANT" = "35" ]; then DEF="-DV35CNT3 -DVPAUSE"; VNUM=49; TAG="135v1";
elif [ "$VARIANT" = "36" ]; then DEF="-DV35BUF -DVPAUSE";  VNUM=50; TAG="135v2";
elif [ "$VARIANT" = "37" ]; then DEF="-DV35EACH";          VNUM=51; TAG="135v3";
elif [ "$VARIANT" = "38" ]; then DEF="-DV35Z -DVPAUSE";    VNUM=52; TAG="135v4";
elif [ "$VARIANT" = "39" ]; then DEF="-DV35EPI -DVPAUSE";  VNUM=53; TAG="135v5";
elif [ "$VARIANT" = "40" ]; then DEF="-DV35P21A -DVPAUSE"; VNUM=54; TAG="135v6";
elif [ "$VARIANT" = "41" ]; then DEF="-DV35SB";            VNUM=55; TAG="135v7";
elif [ "$VARIANT" = "42" ]; then DEF="-DV35SCAN -DVPAUSE"; VNUM=56; TAG="135v8";
else DEF=""; VNUM=$((21 + VARIANT)); TAG="v${VARIANT}"; fi
OUT_FBL="build/custom_fbl_${TAG}.bin"
OUT_NOR="build/nor_full_${TAG}.bin"
echo "== вариант $VARIANT: $TAG =="

# ---------------------------------------------------------------------------
# 2. Ассемблирование хуков
# ---------------------------------------------------------------------------
riscv64-linux-gnu-gcc $DEF -DVNUM=$VNUM -c -nostdlib -o build/nor_stubs.o "$STUBS"
riscv64-linux-gnu-objcopy -O binary -j .text.normini build/nor_stubs.o build/nor_normini.bin
riscv64-linux-gnu-objcopy -O binary -j .text.ddrload build/nor_stubs.o build/nor_ddrload.bin
riscv64-linux-gnu-objcopy -O binary -j .text.dbg     build/nor_stubs.o build/nor_dbg.bin

# ---------------------------------------------------------------------------
# 3. Патчинг бинарника (python)
# ---------------------------------------------------------------------------
python3 - "$BASE" "$ITB" "$OUT_FBL" "$OUT_NOR" "$VARIANT" <<'EOF'
import sys
BASE, ITB, OUT_FBL, OUT_NOR = sys.argv[1:5]
VARIANT = int(sys.argv[5])
LOAD = 0x1c005000          # база дизассемблера
DBG_OFF = 0x7DAC           # нулевой rodata-паддинг (грузится IROM сразу)

data = bytearray(open(BASE, 'rb').read())
assert len(data) == 0x203e8

normini = open('build/nor_normini.bin', 'rb').read()
ddrload = open('build/nor_ddrload.bin', 'rb').read()
dbg     = open('build/nor_dbg.bin', 'rb').read()
print(f"   размеры: nor_read={len(normini)} ddr_load={len(ddrload)} dbg={len(dbg)}")

assert 0 <= DBG_OFF and DBG_OFF + len(dbg) <= 0x8da0, "dbg вне [0:0x8da0]!"
assert all(b == 0 for b in data[DBG_OFF:DBG_OFF + len(dbg)]), "в паддинге не нули!"
data[DBG_OFF:DBG_OFF + len(dbg)] = dbg
DBG_VMA = LOAD + DBG_OFF
print(f"   dbg@{DBG_VMA:x} ({len(dbg)} б)")

NOR_READ_VMA = LOAD + 0xd08
DDR_LOAD_VMA = LOAD + 0x35c
assert 0xd08 + len(normini) <= 0xdc1, "nor_read не влезает!"
assert 0x35c + len(ddrload) <= 0x38c, "ddr_load не влезает!"
data[0xd08:0xd08 + len(normini)] = normini
data[0x35c:0x35c + len(ddrload)] = ddrload

def enc_j(rd, pc, target):
    delta = target - pc
    assert delta % 2 == 0 and -2**20 <= delta < 2**20, hex(pc)
    instr  = ((delta >> 20) & 1) << 31
    instr |= ((delta >> 1) & 0x3FF) << 21
    instr |= ((delta >> 11) & 1) << 20
    instr |= ((delta >> 12) & 0xFF) << 12
    instr |= (rd & 0x1F) << 7
    instr |= 0x6F
    return instr.to_bytes(4, 'little')

def patch(off, target, rd=1, name=''):
    j = enc_j(rd, LOAD + off, target)
    print(f"   {name:28s} @0x{off:05x}: jal 0x{target:x}")
    data[off:off + 4] = j

print("== патчи ==")
# P1: детект NAND -> эпилог (пройти детект на NOR-пути)
patch(0x0356, LOAD + 0x38e, rd=0, name="P1 FUN_00000348 -> эпилог")

# nor_load: вызывается из хука printf (ветка 2)
p_nl = dbg.find(b"\x13\x01\x01\xff\x23\x34\x11\x00\x13\x05\x30\x05")
assert p_nl >= 0, "nor_load не найден"
NOR_LOAD = DBG_VMA + p_nl

p_hook = dbg.find(b"\x37\xd3\x00\x1c")     # lui t1,0x1c00d (хук)
assert p_hook >= 0, "dbg_printf_hook не найден"
PRINTF_HOOK = DBG_VMA + p_hook
patch(0x5b24, PRINTF_HOOK, rd=0, name="printf -> хук")

p5 = dbg.find((0xDEAD0000 + 5).to_bytes(4, "little"))
assert p5 != -1, "плейсхолдер j хука не найден"
data[DBG_OFF + p5:DBG_OFF + p5 + 4] = enc_j(0, LOAD + DBG_OFF + p5, 0x1c00ab28)

pe = dbg.find((0xDEAD0000 + 0xE).to_bytes(4, "little"))
assert pe != -1, "плейсхолдер парсера не найден"
data[DBG_OFF + pe:DBG_OFF + pe + 4] = enc_j(0, LOAD + DBG_OFF + pe, 0x1c00837a)
print("   nor_load->парсер j->0x1c00837a")

# v135v2 (36): патч парсера — буфер ИТБ 0x21A00000 -> 0x21400000
if VARIANT == 36:
    assert data[0x337a:0x337e] == bytes.fromhex("b707a021"), "парсер a5 не там!"
    data[0x337a:0x337e] = bytes.fromhex("b7071402")
    assert data[0x339c:0x33a0] == bytes.fromhex("3705a021"), "парсер a0 не там!"
    data[0x339c:0x33a0] = bytes.fromhex("37051402")
    print("   парсер: 0x21a00000 -> 0x21400000")

# nor_read2 -> диспетчер
p9 = dbg.find((0xDEAD0000 + 9).to_bytes(4, "little"))
assert p9 != -1, "плейсхолдер диспетчера не найден"
data[DBG_OFF + p9:DBG_OFF + p9 + 4] = enc_j(1, LOAD + DBG_OFF + p9, 0x1c005dd4)

# ddr_load2 (загрузка зоны до тренировки) — P-DDR -> ddr_load2
p_dl = dbg.find(b"\x37\x95\x00\x00\x13\x05\x05\xda")
assert p_dl != -1, "ddr_load2 не найден"
DDR_LOAD2 = DBG_VMA + p_dl
patch(0x4b40, DDR_LOAD2, name="P-DDR -> ddr_load2")

pc_ = dbg.find((0xDEAD0000 + 0xC).to_bytes(4, "little"))
assert pc_ != -1, "плейсхолдер 0x1c009b44 не найден"
data[DBG_OFF + pc_:DBG_OFF + pc_ + 4] = enc_j(0, LOAD + DBG_OFF + pc_, 0x1c009b44)

# ddr_load2 -> printf (штатный шаг 1 «DDR init...»)
p22 = dbg.find((0xDEAD0000 + 2).to_bytes(4, "little"))
assert p22 != -1, "плейсхолдер printf в ddr_load2 не найден"
data[DBG_OFF + p22:DBG_OFF + p22 + 4] = enc_j(1, LOAD + DBG_OFF + p22, 0x1c00ab24)

# nor_read_emul (0x1c005dc2 — NAND-чтение конфига DDR -> чтение с NOR)
p_emul = dbg.find(b"\x13\x01\x01\xff\x23\x34\x11\x00\xef")
assert p_emul != -1, "nor_read_emul не найден"
NOR_READ_EMUL = DBG_VMA + p_emul
patch(0xdc2, NOR_READ_EMUL, rd=0, name="0x1c005dc2 -> nor_read_emul")

# EXSPI-инит 0x1c00530c (пропускается только в режиме v49)
p17 = dbg.find((0xDEAD0000 + 0x17).to_bytes(4, "little"))
assert p17 != -1, "плейсхолдер 0x1c00530c не найден"
data[DBG_OFF + p17:DBG_OFF + p17 + 4] = enc_j(1, LOAD + DBG_OFF + p17, 0x1c00530c)

# стабы UBI-вызовов FUN_0000337a (для штатного пути FUN_0000334e)
data[0x2c46:0x2c4e] = bytes.fromhex("1305000067800000")   # attach -> li a0,0; ret
data[0x2572:0x257a] = bytes.fromhex("1305000067800000")   # vol find -> li a0,0; ret
data[0x2b0c:0x2b20] = bytes.fromhex(
    "37051A02B7020B009382E6D523A0560067800000")          # read LEB -> a0=0x21a00000
data[0x2592:0x259a] = bytes.fromhex("1305F0FF67800000")   # end vol -> li a0,-1; ret

# плейсхолдеры nor_read/ddr_load (секции .normini/.ddrload)
p10 = normini.find((0xDEAD0000 + 0x10).to_bytes(4, "little"))
assert p10 != -1, "плейсхолдер диспетчера (nor_read) не найден"
off10 = 0xd08 + p10
data[off10:off10 + 4] = enc_j(1, LOAD + off10, LOAD + 0xdd4)
for code, vma in ((1, NOR_READ_VMA), (2, 0x1c00ab24), (3, LOAD + 0x4b44)):
    p = ddrload.find((0xDEAD0000 + code).to_bytes(4, "little"))
    assert p != -1, f"ddr_load DEAD{code:04X} не найден"
    off = 0x35c + p
    data[off:off + 4] = enc_j(1 if code != 3 else 0, LOAD + off, vma)

print("== чексумма IROM: sum8[0:0x8da0] + 0x15 == byte[0x08] (0x42) ==")
s = sum(data[:0x8da0]) & 0xFF
delta = (0x2D - s) & 0xFF
old = data[0x7d28]
data[0x7d28] = (old + delta) & 0xFF
s2 = sum(data[:0x8da0]) & 0xFF
print(f"   sum было 0x{s:02x}, байт 0x7d28: 0x{old:02x} -> 0x{data[0x7d28]:02x}, "
      f"sum стало 0x{s2:02x}")
assert s2 == 0x2D, "чексумма не сошлась!"

open(OUT_FBL, 'wb').write(data)
print(f"== FBL записан: {OUT_FBL} ({len(data)} б) ==")

print("== полный NOR-образ ==")
itb = open(ITB, 'rb').read()
assert len(itb) == 0x8AD5E, hex(len(itb))
NOR_SIZE = 16 * 1024 * 1024
img = bytearray(data) + bytearray([0xFF]) * (0x40000 - len(data)) + itb
img += bytearray([0xFF]) * (NOR_SIZE - len(img))
open(OUT_NOR, 'wb').write(img)
print(f"   {OUT_NOR}: {len(img)} б; FBL @0x0, u-boot.itb @0x40000")
EOF

# ---------------------------------------------------------------------------
# 4. Верификация (независимая: скрипт irom_checksum.py)
# ---------------------------------------------------------------------------
python3 scripts/irom_checksum.py check "$OUT_FBL"
python3 - <<PYEOF
import struct
d = open("$OUT_FBL","rb").read()
print("P1 @0x356: 0x%08x" % struct.unpack_from("<I", d, 0x356)[0])
print("P-DDR @0x4b40: 0x%08x" % struct.unpack_from("<I", d, 0x4b40)[0])
n = open("$OUT_NOR","rb").read()
print("FIT-магия @0x40000:", n[0x40000:0x40004].hex())
PYEOF
echo "ГОТОВО: $OUT_FBL, $OUT_NOR"
