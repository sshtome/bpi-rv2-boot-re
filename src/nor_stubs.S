/* nor_stubs.S — v135: веер 8 вариантов против виса записи в DDR.
 * ЛОГ v134: «E» без точек => вис на 1-8-й записи в 0x21a00000 (до 1-й паузы!)
 * => НЕ подрядность. Векторы: момент «N3» vs «read value» (CNT3), адрес
 * 0x21400000 (BUF), пауза на КАЖДОЙ записи (EACH), прогрев 'Z' (Z),
 * мини-эпилог DDRC/PHY (EPI), прогрев самого 0x21a00000 (P21A),
 * побайтное копирование (SB), сканер карты DDR (SCAN). */
	.option norvc

	.section .text.normini
	.globl nor_read
nor_read:			/* a0=адрес, a1=буфер, a2=len (мёртвый, для ddr_load) */
	addi	sp, sp, -48
	sd	s0, 0(sp)
	sd	s1, 8(sp)
	sd	s2, 16(sp)
	sd	s3, 24(sp)
	sd	s4, 32(sp)
	sd	ra, 40(sp)
	mv	s0, a0
	mv	s1, a1
	mv	s2, a2
	lui	t0, 0x1c00e
	addi	t0, t0, -1952
	li	t2, 3
	sb	t2, 26(t0)
	sb	x0, 28(t0)
	lui	s3, 0x1c00e
L:
	beqz	s2, DONE
	li	t2, 3
	sb	t2, 0(s3)
	sd	x0, 16(s3)
	sd	x0, 24(s3)
	li	t2, 256
	bltu	t2, s2, 1f
	mv	t2, s2
1:
	mv	s4, t2
	sd	s0, 8(s3)
	sw	t2, 32(s3)
	sd	s1, 40(s3)
	sd	x0, 48(s3)
	addi	a0, s3, 104
	mv	a1, s3
	.word	0xDEAD0010	/* -> jal диспетчер */
	lui	t0, 0xc200
	sw	x0, 4(t0)
	add	s0, s0, s4
	add	s1, s1, s4
	sub	s2, s2, s4
	j	L
DONE:
	ld	s0, 0(sp)
	ld	s1, 8(sp)
	ld	s2, 16(sp)
	ld	s3, 24(sp)
	ld	s4, 32(sp)
	ld	ra, 40(sp)
	addi	sp, sp, 48
	ret

	.section .text.ddrload
	.globl ddr_load
ddr_load:			/* мёртвый (P-DDR -> ddr_load2), 48 б ровно */
	lui	a0, 0x9
	addi	a0, a0, -608
	lui	a1, 0x1c00e
	addi	a1, a1, -608
	lui	a2, 0x17
	addi	a2, a2, 608
	.word	0xDEAD0001	/* -> jal nor_read */
	mv	a1, s2
	lui	a0, 0x1c00d
	addi	a0, a0, -1784
	.word	0xDEAD0002	/* -> jal printf */
	.word	0xDEAD0003	/* -> j 0x1c009b44 */

	.section .text.dbg
	.globl dbg_printf_hook
dbg_printf_hook:
	/* v133: ВЕТКА 2 по счётчику==2 («N3»-вызов — ПОСЛЕ полного
	 * «DDR init»-printf'а = прогрев как v80!). RR + сброс стека +
	 * j nor_load (ИТБ -> 0x21a00000 -> QQ -> j парсер ДО csrsi!). */
	lui	t1, 0x1c00d
	lw	t2, 0x7f0(t1)
	addi	t2, t2, 1
	sw	t2, 0x7f0(t1)
#if defined(V35CNT3)
	li	t0, 3		/* v135v1: 3-й printf = «read value is» (a34e) —
				   ПОСЛЕ sb 'Z' (a332)+puts+lbu — момент v80! */
#else
	li	t0, 2
#endif
	beq	t2, t0, 2f
1:	addi	sp, sp, -112
	sd	s1, 24(sp)
	.word	0xDEAD0005		/* -> j тело printf */
2:	li	a0, 'R'
	jal	ra, dbg_putc
	li	a0, 'R'
	jal	ra, dbg_putc
	lui	sp, 0x1c005		/* сброс стека */
	j	nor_load

	.globl dbg_putc
dbg_putc:			/* a0 = байт; UART1 0x0c301000, FR@+0x18 бит 0x80 */
	lui	t1, 0xc301
1:	lw	t2, 0x18(t1)
	andi	t2, t2, 0x80
	beqz	t2, 1b
	sb	a0, 0(t1)
	ret

	.globl dbg_hex32
dbg_hex32:			/* печать 8 hex-цифр из a0 (оригинал в t4) */
	addi	sp, sp, -32
	sd	ra, 0(sp)
	sd	t3, 8(sp)
	sd	t4, 16(sp)
	mv	t4, a0
	li	t3, 28
1:	srl	t1, t4, t3
	andi	t1, t1, 15
	addi	t1, t1, 48
	li	t2, 57
	ble	t1, t2, 2f
	addi	t1, t1, 39
2:	mv	a0, t1
	jal	ra, dbg_putc
	addi	t3, t3, -4
	bgez	t3, 1b
	ld	t3, 8(sp)
	ld	t4, 16(sp)
	ld	ra, 0(sp)
	addi	sp, sp, 32
	ret

	.globl M_A
M_A:					/* 0x1c009a32: после «Now DDR3» */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lhu	a2, 0(s0)
	li	a0, 'A'
	jal	ra, dbg_putc
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

	.globl M_9
M_9:					/* 0x8f92: первая рабочая инструкция */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lui	a4, 0xa040
	li	a0, '9'
	jal	ra, dbg_putc
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

	.globl M_A8
M_A8:					/* 0x8fae: после CS1-NOP (lui a4,0xa000) */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lui	a4, 0xa000
	li	a0, '8'
	jal	ra, dbg_putc
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

	.globl M_A7
M_A7:					/* 0x8fb6: после записи 0xa000154 */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lui	a4, 0xa004
	li	a0, '7'
	jal	ra, dbg_putc
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

	.globl M_6
M_6:					/* 0x900a: ЧТЕНИЕ таблицы */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lw	a4, 44(a5)
	li	a0, '6'
	jal	ra, dbg_putc
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

	.globl M_A5
M_A5:					/* 0x9058: после записи 0xa080314 */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lw	a5, 44(s0)
	li	a0, '5'
	jal	ra, dbg_putc
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

	.globl M_A4
M_A4:					/* 0x90be: ЗАПИСЬ 0xa080158 */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	sw	a5, 344(s2)
	li	a0, '4'
	jal	ra, dbg_putc
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

	.globl nor_load
nor_load:
	/* v112: вызывается вместо 0x1c00636e (обёртка чтения NAND в
	 * 0x21a00000) из FUN_0000334e ПОСЛЕ всего штатного DDR-этапа.
	 * Читаем ИТБ с NOR @0x40000 кусками 512 б в SRAM + копируем в
	 * 0x21a00000 -> QQ -> li a0,0 -> ret (штатная проверка магии ->
	 * парсер -> u-boot!). */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	li	a0, 'S'
	jal	ra, dbg_putc
	li	a0, 'S'
	jal	ra, dbg_putc
	li	a0, 'N'
	jal	ra, dbg_putc
	li	a0, 'N'
	jal	ra, dbg_putc
	li	a0, 'K'
	jal	ra, dbg_putc
	li	a0, 'K'
	jal	ra, dbg_putc
	lui	t0, 0x1c00d
	addi	t0, t0, -1952		/* сброс таблицы команд */
	sd	x0, 0(t0)
	sd	x0, 8(t0)
	sd	x0, 16(t0)
	sd	x0, 24(t0)
	sd	x0, 32(t0)
	sd	x0, 40(t0)
	sd	x0, 48(t0)
	sd	x0, 56(t0)
	li	a0, 'T'
	jal	ra, dbg_putc
	li	a0, 'T'
	jal	ra, dbg_putc
	li	a0, 'D'
	jal	ra, dbg_putc
	li	a0, 'D'
	jal	ra, dbg_putc
	li	a0, 'L'
	jal	ra, dbg_putc
	li	a0, 'L'
	jal	ra, dbg_putc
#if defined(V35Z)
	/* v135v4: имитация ШТАТНОГО прогрева a332-a33a ДО копирования:
	 * sb 'Z' в 0x20000000 + пауза + lbu. Лог: 'z'=совпало, 'Z'=нет. */
	lui	t0, 0x20000
	li	t1, 0x5a
	sb	t1, 0(t0)
	li	t6, 0x1000
Z1:	addi	t6, t6, -1
	bnez	t6, Z1b
	lbu	t2, 0(t0)
	li	a0, 'Z'
	bne	t2, t1, Z2f
	li	a0, 'z'
Z2:	jal	ra, dbg_putc
#endif
#if defined(V35EPI)
	/* v135v5: МИНИ-ЭПИЛОГ 9b44 (без jal-каскада таймингов):
	 * DDRC 0xce0048c ori 1536, сброс 0xce00500 1/0, PHY 0xd000304/30 =1. */
	lui	t0, 0xce00
	lw	t1, 1164(t0)
	ori	t1, t1, 1536
	sw	t1, 1164(t0)
	li	t1, 1
	sw	t1, 1280(t0)
	sw	x0, 1280(t0)
	lui	t0, 0xd000
	sw	t1, 772(t0)
	sw	t1, 48(t0)
	fence	rw, rw
	li	a0, 'G'
	jal	ra, dbg_putc
#endif
#if defined(V35P21A)
	/* v135v6: прогрев САМОГО 0x21a00000: sb 0x5a + 'p' + lbu +
	 * 'q'=не совпало, 'r'=совпало. Если sb виснет — 'p' НЕ выйдет. */
	lui	t0, 0x21a00
	li	t1, 0x5a
	sb	t1, 0(t0)
	li	a0, 'p'
	jal	ra, dbg_putc
	lbu	t2, 0(t0)
	li	a0, 'q'
	bne	t2, t1, P1f
	li	a0, 'r'
P1:	jal	ra, dbg_putc
#endif
#if defined(V35SCAN)
	/* v135v8: КАРТА DDR на моменте «N3»: 5 адресов sb/lbu,
	 * печать символа адреса + '!'=жив, '?'=не совпало (вис=стоп). */
	lui	t6, 0x20000
	li	a0, '0'
	jal	ra, dbg_putc
	jal	ra, scan1
	lui	t6, 0x21000
	li	a0, '1'
	jal	ra, dbg_putc
	jal	ra, scan1
	lui	t6, 0x21400
	li	a0, '4'
	jal	ra, dbg_putc
	jal	ra, scan1
	lui	t6, 0x21800
	li	a0, '8'
	jal	ra, dbg_putc
	jal	ra, scan1
	lui	t6, 0x21a00
	li	a0, 'A'
	jal	ra, dbg_putc
	jal	ra, scan1
	j	SCDONE
scan1:
	li	t1, 0x5a
	sb	t1, 0(t6)
	lbu	t2, 0(t6)
	li	a0, '!'
	beq	t2, t1, 3f
	li	a0, '?'
3:	jal	ra, dbg_putc
	ret
SCDONE:
#endif
	lui	s0, 0x40		/* s0 = NOR-адрес 0x40000 */
#if defined(V35BUF)
	lui	s1, 0x21400		/* v135v2: буфер 0x21400000 (в окне v97) */
#else
	lui	s1, 0x21a00		/* s1 = DDR-буфер 0x21a00000 */
#endif
	li	s2, 0x8AD5E		/* s2 = остаток */
	lui	t4, 0x1c00d
	sw	x0, 0x7fc(t4)
	li	s4, 1			/* s4 = первая итерация (C/D/E/F) */
3:	beqz	s2, 6f
	lw	t6, 0x7fc(t4)
	addi	t6, t6, 1
	sw	t6, 0x7fc(t4)
	andi	t6, t6, 63
	bnez	t6, 5f
	li	a0, '.'
	jal	ra, dbg_putc
5:	beqz	s4, 11f
	li	a0, 'C'
	jal	ra, dbg_putc
11:	li	s3, 512
	bltu	s3, s2, 7f
	mv	s3, s2
7:	mv	a0, s0			/* nor_read2(s0, 0x1c00dda0, s3) */
	lui	a1, 0x1c00e
	addi	a1, a1, -608
	mv	a2, s3
	jal	ra, nor_read2
	beqz	s4, 12f
	li	a0, 'D'
	jal	ra, dbg_putc
12:	li	t6, 0x1000
8:	addi	t6, t6, -1
	bnez	t6, 8b
	beqz	s4, 13f
	li	a0, 'E'
	jal	ra, dbg_putc
13:
#if defined(V35SB)
	mv	t4, s3			/* v135v7: ПОБАЙТНОЕ копирование (sb) */
#else
	srli	t4, s3, 2
#endif
	lui	t5, 0x1c00e
	addi	t5, t5, -608
9:
#if defined(V35SB)
	lbu	t0, 0(t5)
	sb	t0, 0(s1)
	addi	t5, t5, 1
	addi	s1, s1, 1
#else
	lw	t0, 0(t5)
	sw	t0, 0(s1)
	addi	t5, t5, 4
	addi	s1, s1, 4
#endif
	addi	t4, t4, -1
#if defined(V35EACH)
	/* v135v3: точка-пауза после КАЖДОЙ записи (~12 c на ИТБ) */
	li	a0, '.'
	jal	ra, dbg_putc
#elif defined(V35SB)
	/* v135v7: точка каждые 64 байта (~0.8 c) */
	andi	t6, t4, 63
	bnez	t6, 10f
	li	a0, '.'
	jal	ra, dbg_putc
10:
#elif defined(VPAUSE)
	/* v134: точка-пауза каждые 8 слов */
	andi	t6, t4, 7
	bnez	t6, 10f
	li	a0, '.'
	jal	ra, dbg_putc
10:
#endif
	bnez	t4, 9b
	beqz	s4, 14f
	li	a0, 'F'
	jal	ra, dbg_putc
14:	sub	s2, s2, s3
	add	s0, s0, s3
	li	s4, 0
	lui	t4, 0x1c00d
	j	3b
6:	li	a0, 'Q'
	jal	ra, dbg_putc
	li	a0, 'Q'
	jal	ra, dbg_putc
	fence	rw, rw
	fence.i
	.word	0xDEAD000E		/* v133: -> j парсер 0x1c00837a НАПРЯМУЮ,
					   ДО csrsi (записи в DDR ещё работают!) */

	.globl ddr_load2
ddr_load2:
	/* v92/v113/v116/v118: загрузка зоны ДО тренировки (P-DDR), затем
	 * 1КБ 0x9000->0x1c00e000, ЗАГОЛОВОК 112 б в 0x1c00dfb0,
	 * EXSPI-инит 0x1c00530c, ШТАТНЫЙ ШАГ 1 printf -> j 0x1c009b44. */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lui	a0, 0x9
	addi	a0, a0, -608		/* 0x8da0 */
	lui	a1, 0x1c00e
	addi	a1, a1, -608		/* 0x1c00dda0 */
	lui	a2, 0x17
	addi	a2, a2, 608		/* 0x17260 */
	jal	ra, nor_read2
	/* префикс версии «135v<VNUM>» */
	li	a0, '1'
	jal	ra, dbg_putc
	li	a0, '3'
	jal	ra, dbg_putc
	li	a0, '5'
	jal	ra, dbg_putc
	li	a0, 'v'
	jal	ra, dbg_putc
	li	a0, VNUM
	jal	ra, dbg_putc
#if !defined(V49MODE)
	lui	a0, 0x9		/* 0x9000 = зона+0x260 */
	lui	a1, 0x1c00e		/* 0x1c00e000 */
	li	a2, 1024
	jal	ra, nor_read2
	li	a0, 0			/* NOR[0] — заголовок 112 б */
	lui	a1, 0x1c00e
	addi	a1, a1, -80		/* 0x1c00dfb0 */
	li	a2, 112
	jal	ra, nor_read2
	.word	0xDEAD0017		/* -> jal ra, 0x1c00530c (EXSPI-инит) */
#endif
	li	a1, 0x1000		/* 4096 Мб */
	lui	a0, 0x1c00d
	addi	a0, a0, -1896		/* 0x1c00c898 */
	.word	0xDEAD0002		/* -> jal ra, 0x1c00ab24 (printf) */
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD000C		/* -> j x0, 0x1c009b44 */

	.globl nor_read2
nor_read2:			/* a0=адрес, a1=буфер, a2=len; точки каждые 128 */
	addi	sp, sp, -48
	sd	s0, 0(sp)
	sd	s1, 8(sp)
	sd	s2, 16(sp)
	sd	s3, 24(sp)
	sd	s4, 32(sp)
	sd	ra, 40(sp)
	mv	s0, a0
	mv	s1, a1
	mv	s2, a2
	lui	t0, 0x1c00e
	addi	t0, t0, -1952		/* таблица 0x1c00d860 */
	li	t2, 3
	sb	t2, 26(t0)
	sb	x0, 28(t0)
	lui	s3, 0x1c00d
	addi	s3, s3, 0x600		/* дескриптор 0x1c00d600 */
	lui	t4, 0x1c00d
	sw	x0, 0x7f4(t4)		/* счётчик чанков @0x1c00d7f4 */
L2:
	beqz	s2, DONE2
	li	t2, 3
	sb	t2, 0(s3)
	sd	x0, 16(s3)
	sd	x0, 24(s3)
	li	t2, 256
	bltu	t2, s2, 1f
	mv	t2, s2
1:
	mv	s4, t2
	sd	s0, 8(s3)
	sw	t2, 32(s3)
	sd	s1, 40(s3)
	sd	x0, 48(s3)
	addi	a0, s3, 104
	mv	a1, s3
	.word	0xDEAD0009		/* -> jal диспетчер 0x1c005dd4 */
	lui	t0, 0xc200
	sw	x0, 4(t0)		/* CR1 = 0 */
	lui	t4, 0x1c00d
	lw	t5, 0x7f4(t4)
	addi	t5, t5, 1
	sw	t5, 0x7f4(t4)
	andi	t0, t5, 127
	bnez	t0, 2f
	li	a0, '.'
	jal	ra, dbg_putc
2:
	add	s0, s0, s4
	add	s1, s1, s4
	sub	s2, s2, s4
	j	L2
DONE2:
	ld	s0, 0(sp)
	ld	s1, 8(sp)
	ld	s2, 16(sp)
	ld	s3, 24(sp)
	ld	s4, 32(sp)
	ld	ra, 40(sp)
	addi	sp, sp, 48
	ret

	.globl nor_read_emul
nor_read_emul:
	/* v117: замена 0x1c005dc2 (NAND-чтение конфига) — читаем с NOR. */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	jal	ra, nor_read2
	li	a0, 0
	ld	ra, 8(sp)
	addi	sp, sp, 16
	ret

/* v131v2: ПРОПУСК тренировки — вернуть зашитый код частоты 1066 */
	.globl M_SKIP
M_SKIP:
	li	a0, 0x08550000		/* код частоты (как после тренировки) */
	ret
