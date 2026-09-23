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
	lui	t1, 0x1c002
	lw	t2, 0x200(t1)
	addi	t2, t2, 1
	sw	t2, 0x200(t1)
#if defined(V35CNT3)
	li	t0, 3		/* v135v1: 3-й printf = «read value is» (a34e) —
				   ПОСЛЕ sb 'Z' (a332)+puts+lbu — момент v80! */
#elif defined(V137H) || defined(V138PASS)
	li	t0, 0x7f	/* v137v5/v138v2-v4/v7-v8: хук ПАССИВЕН (штатный поток) */
#else
	li	t0, 2
#endif
	beq	t2, t0, 2f
1:	addi	sp, sp, -112
	sd	s1, 24(sp)
#if defined(V143PR)
	/* v143v4: воспроизведение v93-97 (тренировка ПРОХОДИЛА с печатями
	 * хука на каждый printf — тайминг-гипотеза): «N:addr;» */
	mv	t3, a0
	lui	t1, 0x1c00d
	lw	t2, 0x7f0(t1)
	mv	a0, t2
	jal	ra, dbg_hex32
	li	a0, ':'
	jal	ra, dbg_putc
	mv	a0, t3
	jal	ra, dbg_hex32
	li	a0, ';'
	jal	ra, dbg_putc
	mv	a0, t3
#endif
	.word	0xDEAD0005		/* -> j тело printf */
2:
#if defined(V138CSR)
	/* v138v1: маркер МЕЖДУ csrsi и lbu — что виснет? */
	li	a0, 'C'
	jal	ra, dbg_putc
	csrsi	0x7c1, 3
	li	a0, 'c'
	jal	ra, dbg_putc
	lui	t0, 0x21a00
	lbu	t1, 0(t0)
	li	a0, 'r'
	jal	ra, dbg_putc
#endif
#if defined(V138WB)
	/* v138v5: записи w4b/w8b (включение мостов?) на моменте «N3»,
	 * затем проверка 0x20000000 на чтение */
	li	a0, 'W'
	jal	ra, dbg_putc
	lui	t0, 0x40540
	li	t1, 0x5aa7
	sw	t1, 0(t0)
	li	a0, 'w'
	jal	ra, dbg_putc
	lui	t0, 0x66099
	sd	t1, 0(t0)
	li	a0, 'v'
	jal	ra, dbg_putc
	lui	t0, 0x20000
	lbu	t1, 0(t0)
	li	a0, 'r'
	jal	ra, dbg_putc
#endif
#if defined(V138KC)
	/* v138v6: ПОЛНАЯ кэш-настройка zero_stage_boot на «N3»:
	 * MCOR=0x70013, MSMPR=1, MHCR=0x10011FF, fence — затем lbu */
	li	a0, 'K'
	jal	ra, dbg_putc
	lui	t1, 0x70
	addi	t1, t1, 0x13
	csrw	0x7c2, t1		/* MCOR: очистка L1/BTB/BHT */
	li	t1, 1
	csrw	0x7f3, t1		/* MSMPR: когерентность */
	lui	t1, 0x1001
	addi	t1, t1, 0x1ff
	csrw	0x7c1, t1		/* MHCR = 0x10011FF (L1+L2) */
	fence	rw, rw
	li	a0, 'k'
	jal	ra, dbg_putc
	lui	t0, 0x21a00
	lbu	t1, 0(t0)
	li	a0, 'r'
	jal	ra, dbg_putc
#endif
#if defined(V137S)
	/* v137v1: sb 'Z' в 0x20000000 БЕЗ чтения — проходит ли запись? */
	li	a0, 'S'
	jal	ra, dbg_putc
	lui	t0, 0x20000
	li	t1, 0x5a
	sb	t1, 0(t0)
	li	a0, 's'
	jal	ra, dbg_putc
#endif
#if defined(V137C2)
	/* v137v2/v4: csrsi 0x7C1,3 (L1 вкл) + lbu из 0x21A00000 —
	 * работает ли ЧТЕНИЕ DDR после включения кэшей? */
	li	a0, 'C'
	jal	ra, dbg_putc
	csrsi	0x7c1, 3
	lui	t0, 0x21a00
	lbu	t1, 0(t0)
	li	a0, 'r'
	jal	ra, dbg_putc
#endif
#if defined(V137C3)
	/* v137v3: csrsi + sb/lbu в 0x20000000 */
	li	a0, 'C'
	jal	ra, dbg_putc
	csrsi	0x7c1, 3
	lui	t0, 0x20000
	li	t1, 0x5a
	sb	t1, 0(t0)
	li	a0, 's'
	jal	ra, dbg_putc
	lbu	t1, 0(t0)
	li	a0, 'r'
	jal	ra, dbg_putc
#endif
#if defined(V137R6)
	/* v137v6: lbu из 0x21000000 БЕЗ csrsi — есть ли живой регион? */
	li	a0, 'M'
	jal	ra, dbg_putc
	lui	t0, 0x21000
	lbu	t1, 0(t0)
	li	a0, 'm'
	jal	ra, dbg_putc
#endif
#if defined(V136F)
	/* v136v6/v8, гипотеза 1: регистры DDRC/PHY НА МОМЕНТЕ «N3»:
	 * 0xce0048c, 0xce004c0, 0xce00500, PHY 0xd000030, 0xd000304 */
	lui	t0, 0xce00
	lw	a0, 1164(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1216(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1280(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xd000
	lw	a0, 48(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xd000
	lw	a0, 772(t0)
	jal	ra, dbg_hex32
	li	a0, '!'
	jal	ra, dbg_putc
#endif
#if defined(V136G)
	/* v136v7: данные зоны на «N3»: 0x1c00dd78 (параметр частоты),
	 * 0x1c00e0f0 (результат поллинга), 0x1c00e298 (таблица частот) */
	lui	t0, 0x1c00e
	lw	a0, -648(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0x1c00e
	lw	a0, 240(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0x1c00e
	lw	a0, 664(t0)
	jal	ra, dbg_hex32
	li	a0, '!'
	jal	ra, dbg_putc
#endif
	li	a0, 'R'
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

	.globl dbg_puts
dbg_puts:			/* a0 = строка (null-terminated) */
	addi	sp, sp, -16
	sd	ra, 8(sp)
	sd	s0, 0(sp)
	mv	s0, a0
1:	lbu	a0, 0(s0)
	beqz	a0, 2f
	jal	ra, dbg_putc
	addi	s0, s0, 1
	j	1b
2:	ld	s0, 0(sp)
	ld	ra, 8(sp)
	addi	sp, sp, 16
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
	addi	sp, sp, -16
	sd	ra, 8(sp)
	lui	t0, 0x1c00e
	addi	t0, t0, -1952		/* таблица 0x1C00D860 */
	li	t1, 3
	sb	t1, 0(t0)		/* [0] = 0x03 (READ opcode) */
	sb	t1, 1(t0)		/* [1] = 3 (3 address bytes for 24-bit NOR) */
	li	t1, 1
	sb	t1, 2(t0)		/* [2] = 1 (1-wire address mode) */
	sb	x0, 3(t0)		/* [3] = 0 (0 dummy bytes for 0x03 READ) */
	li	t1, 1
	sb	t1, 4(t0)		/* [4] = 1 (1-wire data mode) */
	sb	x0, 5(t0)		/* [5] = 0 (table terminator) */
#if defined(V35Z)
	/* v135v4: имитация ШТАТНОГО прогрева a332-a33a ДО копирования:
	 * sb 'Z' в 0x20000000 + пауза + lbu. Лог: 'z'=совпало, 'Z'=нет. */
	lui	t0, 0x20000
	li	t1, 0x5a
	sb	t1, 0(t0)
	li	t6, 0x1000
1:	addi	t6, t6, -1
	bnez	t6, 1b
	lbu	t2, 0(t0)
	li	a0, 'Z'
	bne	t2, t1, 2f
	li	a0, 'z'
2:	jal	ra, dbg_putc
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
	bne	t2, t1, 1f
	li	a0, 'r'
1:	jal	ra, dbg_putc
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
	lui	s2, 0xC0		/* s2 = 0xC0000 = 768 KB (U-Boot NOR partition) */
3:	beqz	s2, 6f
	li	s3, 512
	bltu	s3, s2, 7f
	mv	s3, s2
7:	mv	a0, s0			/* nor_read2(s0, 0x1c002400, s3) */
	lui	a1, 0x1c002
	addi	a1, a1, 0x400
	mv	a2, s3
	jal	ra, nor_read2
	li	t6, 0x1000
8:	addi	t6, t6, -1
	bnez	t6, 8b

	mv	t4, s3			/* v135v7: ПОБАЙТНОЕ копирование (sb) */
	lui	t5, 0x1c002
	addi	t5, t5, 0x400
9:
	lbu	t0, 0(t5)
	sb	t0, 0(s1)
	addi	t5, t5, 1
	addi	s1, s1, 1
	addi	t4, t4, -1
	bnez	t4, 9b

	sub	s2, s2, s3
	add	s0, s0, s3
	j	3b
6:
	fence	rw, rw
	ld	ra, 8(sp)
	addi	sp, sp, 16
	li	a0, 0			/* a0 = 0 (успех загрузки для FUN_0000334e) */
	ret

/* v150: PIO-чтение NOR побайтно (без диспетчера — он виснет после
 * пост-DDR-кода!). a0=NOR-адрес, a1=буфер, a2=len; '.' каждые 4К. */
	.globl nor_read_pio
nor_read_pio:
	addi	sp, sp, -48
	sd	s0, 0(sp)
	sd	s1, 8(sp)
	sd	s2, 16(sp)
	sd	s3, 24(sp)
	sd	ra, 40(sp)
	mv	s0, a0
	mv	s1, a1
	mv	s2, a2
	li	s3, 0			/* счётчик для точки */
	lui	a4, 0xc200
P_L:
	beqz	s2, P_DONE
	sh	x0, 4(a4)		/* disable SSP */
	li	a5, 2
	sh	a5, 4(a4)		/* enable SSP */
	li	t3, 0x100000
1:	lhu	a5, 12(a4)
	andi	a5, a5, 2
	bnez	a5, 2f
	addi	t3, t3, -1
	bnez	t3, 1b
	j	P_DONE			/* таймаут TX */
2:	li	a5, 0x03
	sh	a5, 8(a4)		/* команда READ */
	li	t3, 0x100000
1:	lhu	a5, 12(a4)
	andi	a5, a5, 2
	bnez	a5, 2f
	addi	t3, t3, -1
	bnez	t3, 1b
	j	P_DONE
2:	srli	a5, s0, 16
	andi	a5, a5, 0xFF
	sh	a5, 8(a4)		/* адрес[23:16] */
	li	t3, 0x100000
1:	lhu	a5, 12(a4)
	andi	a5, a5, 2
	bnez	a5, 2f
	addi	t3, t3, -1
	bnez	t3, 1b
	j	P_DONE
2:	srli	a5, s0, 8
	andi	a5, a5, 0xFF
	sh	a5, 8(a4)		/* адрес[15:8] */
	li	t3, 0x100000
1:	lhu	a5, 12(a4)
	andi	a5, a5, 2
	bnez	a5, 2f
	addi	t3, t3, -1
	bnez	t3, 1b
	j	P_DONE
2:	mv	a5, s0
	andi	a5, a5, 0xFF
	sh	a5, 8(a4)		/* адрес[7:0] */
	li	t3, 0x100000
1:	lhu	a5, 12(a4)
	andi	a5, a5, 2
	bnez	a5, 2f
	addi	t3, t3, -1
	bnez	t3, 1b
	j	P_DONE
2:	li	a5, 0
	sh	a5, 8(a4)		/* dummy */
	li	t3, 0x100000
1:	lhu	a5, 12(a4)
	andi	a5, a5, 4		/* RNE */
	bnez	a5, 2f
	addi	t3, t3, -1
	bnez	t3, 1b
	j	P_DONE
2:	lhu	a5, 8(a4)		/* данные */
	sb	a5, 0(s1)		/* запись в DDR (sb работает!) */
	addi	s0, s0, 1
	addi	s1, s1, 1
	addi	s2, s2, -1
	addi	s3, s3, 1
	li	t0, 4096
	bne	s3, t0, P_L
	li	s3, 0
	li	a0, '.'
	jal	ra, dbg_putc
	j	P_L
P_DONE:
	ld	s0, 0(sp)
	ld	s1, 8(sp)
	ld	s2, 16(sp)
	ld	s3, 24(sp)
	ld	ra, 40(sp)
	addi	sp, sp, 48
	ret

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
#if defined(V136A)
	/* v136v1, план трассировки A: регистры DDRC ДО инициализации:
	 * 0xce0048c, 0xce00430, 0xce004c0, 0xce00500, 0xce0049c, 0xce00480 */
	lui	t0, 0xce00
	lw	a0, 1164(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1072(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1216(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1280(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1180(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1152(t0)
	jal	ra, dbg_hex32
	li	a0, '!'
	jal	ra, dbg_putc
#endif
#if defined(V136D)
	/* v136v3, план трассировки D: sp и ra сразу после пролога */
	mv	t3, ra
	mv	a0, sp
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	mv	a0, t3
	jal	ra, dbg_hex32
	li	a0, '!'
	jal	ra, dbg_putc
#endif
#if defined(V136E)
	/* v136v5, гипотеза 3: сброс DDRC 0xce004c0 (1, пауза, 0) */
	li	a0, 'R'
	jal	ra, dbg_putc
	lui	t0, 0xce00
	li	t1, 1
	sw	t1, 1216(t0)
	li	t6, 0x1000
1:	addi	t6, t6, -1
	bnez	t6, 1b
	sw	x0, 1216(t0)
	li	a0, 'r'
	jal	ra, dbg_putc
#endif
	jal	ra, nor_read2
#if defined(V136B)
	/* v136v2, план трассировки B: регистры ПОСЛЕ загрузки зоны (до шага 1):
	 * 0xce0048c, 0xce004c0, 0xce00500, PHY 0xd0000000/4/30/304 */
	lui	t0, 0xce00
	lw	a0, 1164(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1216(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 1280(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xd000
	lw	a0, 0(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xd000
	lw	a0, 4(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xd000
	lw	a0, 48(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xd000
	lw	a0, 772(t0)
	jal	ra, dbg_hex32
	li	a0, '!'
	jal	ra, dbg_putc
#endif
#if !defined(V49MODE)
#if !defined(V144NOKB)
	lui	a0, 0x9		/* 0x9000 = зона+0x260 (безвредная копия) */
	lui	a1, 0x1c00e		/* 0x1c00e000 */
	li	a2, 1024
	jal	ra, nor_read2
#endif
#if !defined(V144NOHEAD)
	/* ВНИМАНИЕ (v144): этот блок ЗАТИРАЛ 112 б таблицы тренировки
	 * (зона[0x210:0x280], файл[0x8FB0:0x9020], 107 ненулевых байт!)
	 * заголовком NOR[0:0x70] — тренировка висла ВНУТРИ (v116+).
	 * Отключается -DV144NOHEAD (все варианты v144+). */
	li	a0, 0			/* NOR[0] — заголовок 112 б */
	lui	a1, 0x1c00e
	addi	a1, a1, -80		/* 0x1c00dfb0 */
	li	a2, 112
	jal	ra, nor_read2
#endif
#if !defined(V136NOINIT)
	.word	0xDEAD0017		/* -> jal ra, 0x1c00530c (EXSPI-инит) */
#endif
#endif
#if defined(V137H)
	/* v137v5: восстановить заголовок файла[0:0x70] в SRAM по его
	 * РЕАЛЬНОМУ адресу 0x1c004f90 (на NOR-пути IROM его не грузит). */
	li	a0, 0
	lui	a1, 0x1c005
	addi	a1, a1, -112		/* 0x1c004f90 = файл[0] */
	li	a2, 0x70
	jal	ra, nor_read2
	li	a0, 'H'
	jal	ra, dbg_putc
#endif
#if defined(V146DUMP)
	/* v146v1/v6: ДАМП селекторов клоков ДО инициализации:
	 * 0xCE00480 (CLK_SEL0: биты 19/21 = DDR-mux), 0x484, 0x488, 0x48C */
	lui	t0, 0xce00
	lw	a0, 128(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 132(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 136(t0)
	jal	ra, dbg_hex32
	li	a0, ' '
	jal	ra, dbg_putc
	lui	t0, 0xce00
	lw	a0, 140(t0)
	jal	ra, dbg_hex32
	li	a0, '!'
	jal	ra, dbg_putc
#endif
#if defined(V146CLR)
	/* v146v2/v4/v5: СБРОС битов 19/21 в 0xCE00480 (ddrpll_postdiv!)
	 * + строб CFG_LOAD_DIV (0xCE00500 = 1/0) — гипотеза: IROM на
	 * NOR-пути оставил cmnpll-источник (биты=1) -> DDR-клок неверный
	 * -> запись в PHY 0xA040017C виснет! */
	lui	t0, 0xce00
	lw	t1, 128(t0)
	lui	t2, 0xffd8
	addi	t2, t2, -1		/* ~0x280000 */
	and	t1, t1, t2
	sw	t1, 128(t0)
	li	t1, 1
	sw	t1, 256(t0)		/* 0xCE00500 = CFG_LOAD_DIV */
	sw	x0, 256(t0)
	li	a0, 'C'
	jal	ra, dbg_putc
#endif
#if defined(V146SET)
	/* v146v3: обратная проверка — УСТАНОВКА битов 19/21 */
	lui	t0, 0xce00
	lw	t1, 128(t0)
	lui	t2, 0x28		/* 0x280000 */
	or	t1, t1, t2
	sw	t1, 128(t0)
	li	t1, 1
	sw	t1, 256(t0)
	sw	x0, 256(t0)
	li	a0, 'S'
	jal	ra, dbg_putc
#endif
#if !defined(V147NOSTEP)
	li	a1, 0x1000		/* 4096 Мб */
	lui	a0, 0x1c00d
	addi	a0, a0, -1896		/* 0x1c00c898 */
	.word	0xDEAD0002		/* -> jal ra, 0x1c00ab24 (printf) */
#endif
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
	sb	t2, 0(t0)		/* [0] = 0x03 (READ) */
	sb	t2, 1(t0)		/* [1] = 3 (3-byte address) */
	li	t2, 1
	sb	t2, 2(t0)		/* [2] = 1 (1-wire) */
	sb	x0, 3(t0)		/* [3] = 0 (0 dummy) */
	li	t2, 1
	sb	t2, 4(t0)		/* [4] = 1 (1-wire data) */
	sb	x0, 5(t0)		/* [5] = 0 */
	li	t2, 3
	sb	t2, 25(t0)
	sb	t2, 26(t0)
	li	t2, 1
	sb	t2, 27(t0)
	sb	x0, 28(t0)
	li	t2, 1
	sb	t2, 29(t0)
	lui	s3, 0x1c002
	addi	s3, s3, 0x100		/* дескриптор 0x1c002100 */
	lui	t4, 0x1c002
	sw	x0, 0x204(t4)		/* счётчик чанков @0x1c002204 */
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
	addi	sp, sp, -16
	sd	ra, 8(sp)
	mv	t0, a1			/* t0 = len */
	mv	a1, a2			/* a1 = buf (sp+128) */
	mv	a2, t0			/* a2 = len (1024) */
	jal	ra, nor_read2
	ld	ra, 8(sp)
	addi	sp, sp, 16
	li	a0, 0
	ret

	.globl M_SKIP
M_SKIP:
	addi	sp, sp, -16
	sd	ra, 8(sp)

	/* Шаг 0: Запуск тренировки PHY 0x1c008f5a */
	.word	0xDEAD0020		/* -> jal ra, 0x1c008f5a */

	/* Шаг 1: PIR = 96 (PHY Initialization Register) */
	lui	s0, 0xd000
	li	a5, 96
	sw	a5, 432(s0)		/* 0xd00001b0 = 96 (PIR) */

	/* Поллинг PGSR0 (0xd00001bc) bit 0 (IDONE) с таймаутом */
	li	t0, 0x200000
1:	lw	a5, 444(s0)
	andi	a5, a5, 1
	bnez	a5, 2f
	addi	t0, t0, -1
	bnez	t0, 1b
2:
	/* Шаг 2: PIR = 64, затем 65, снятие PWRCTL */
	li	a5, 64
	sw	a5, 432(s0)		/* PIR = 64 */
	li	a5, 65
	sw	a5, 432(s0)		/* PIR = 65 */
	sw	zero, 48(s0)		/* 0xd0000030 = 0 (PWRCTL) */
	sw	zero, 48(s0)

	/* Шаг 3: DFI start (0xd0000320 = 1) */
	li	a5, 1
	sw	a5, 800(s0)		/* 0xd0000320 = 1 */

	/* Поллинг 0xd0000324 bit 0 с таймаутом */
	li	t0, 0x200000
4:	lw	a5, 804(s0)
	andi	a5, a5, 1
	bnez	a5, 5f
	addi	t0, t0, -1
	bnez	t0, 4b
5:
	/* Шаг 4: Поллинг STAT (0xd0000004) bit 1 == 0 (Normal mode) */
	li	t0, 0x200000
7:	lw	s1, 4(s0)
	andi	s1, s1, 2
	beqz	s1, 8f
	addi	t0, t0, -1
	bnez	t0, 7b
8:
	sw	zero, 48(s0)
	sw	zero, 48(s0)
	sw	zero, 48(s0)

	/* Шаг 5: Включение всех 4 AXI Slave портов контроллера UMCTL2 */
	li	a5, 1
	sw	a5, 1168(s0)		/* 0xd0000490: Port 0 enable */
	sw	a5, 1344(s0)		/* 0xd0000540: Port 1 enable */
	sw	a5, 1520(s0)		/* 0xd00005f0: Port 2 enable */
	sw	a5, 1696(s0)		/* 0xd00006a0: Port 3 enable */
	fence	rw, rw

	ld	ra, 8(sp)
	addi	sp, sp, 16
	li	a0, 0			/* a0 = 0 (успех) */
	ret

/* v140: маркерная лестница для локализации виса после «N3»:
 * E = эпилог DDR достигнут; B/b = вокруг csrsi (0x1c008816);
 * D = вызов FUN_0000334e; P = парсер. */
	.globl M_E
M_E:	addi	sp, sp, -16
	sd	ra, 8(sp)
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD000F	/* -> j 0x1c00a40a (эпилог DDR) */

	.globl M_B
M_B:	addi	sp, sp, -16
	sd	ra, 8(sp)
	.word	0xDEAD0011	/* -> jal 0x1c008816 (csrsi 0x7c1,3) */
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD0015	/* -> j 0x1c00b430 (после csrsi-вызова) */

	.globl M_N
M_N:	addi	sp, sp, -16
	sd	ra, 8(sp)
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD0015	/* -> j 0x1c00b430 (БЕЗ csrsi!) */

	.globl M_D
M_D:	addi	sp, sp, -16
	sd	ra, 8(sp)
	jal	a0, 1f
msg_4pda:
	.string "\r\nby sshtome for 4PDA\r\n\r\n"
	.align 2
1:	jal	ra, dbg_puts
	.word	0xDEAD0012	/* -> jal 0x1c00834e (FUN_0000334e) */
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD0016	/* -> j 0x1c00b450 (таймеры/cpu-sysm) */

	.globl M_P
M_P:	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	s0, 16(sp)

	/* Установка _DAT_1c00e0f0 = 0x20000000 (DRAM size = 512MB) */
	lui	t0, 0x1c00e
	lui	t1, 0x20000
	sd	t1, 240(t0)

	.word	0xDEAD0013	/* -> jal ra, 0x1c00837a (парсер FIT с сохранением ra) */

	ld	s0, 16(sp)
	ld	ra, 24(sp)
	addi	sp, sp, 32
1:	wfi
	j	1b

/* v141: обёртка вокруг printf N3 — вис в теле printf или после? */
	.globl M_X
M_X:	addi	sp, sp, -32
	sd	ra, 24(sp)
	sd	a0, 8(sp)
	sd	a1, 16(sp)
	li	a0, 'X'
	jal	ra, dbg_putc
	ld	a1, 16(sp)
	ld	a0, 8(sp)
	.word	0xDEAD0018	/* -> jal 0x1c00ab24 (printf N3) */
	li	a0, 'Y'
	jal	ra, dbg_putc
	ld	ra, 24(sp)
	addi	sp, sp, 32
	.word	0xDEAD0019	/* -> j 0x1c00a40a (эпилог DDR) */

	.globl M_XS
M_XS:	addi	sp, sp, -32
	sd	ra, 24(sp)
	li	a0, 'X'
	jal	ra, dbg_putc
	ld	ra, 24(sp)
	addi	sp, sp, 32
	.word	0xDEAD0019	/* -> j 0x1c00a40a (БЕЗ printf N3) */

/* v142: маркер входа DDR-функции — БЕЗ кадра (dbg_putc стек не трогает):
 * заменяет 0x4b3a (mv a1,s9), затем уходит в ddr_load2 (тот сам печатает
 * префикс, грузит зону, печатает шаг 1 и прыгает в 0x1c009b44). */
	.globl M_W
M_W:	li	a0, 'W'
	jal	ra, dbg_putc
	.word	0xDEAD001A	/* -> j ddr_load2 (не возвращается) */

/* v143: паузы вокруг тренировки — гипотеза таймингов (v93-97 проходили
 * тренировку с печатями-паузами хука, без печатей — вис внутри!). */
	.globl M_T1
M_T1:	addi	sp, sp, -16
	sd	ra, 8(sp)
	.word	0xDEAD001B	/* -> jal 0x1c00ab24 (printf «Now DDR3») */
	lui	t6, 0x100	/* пауза ~1.2 мс */
1:	addi	t6, t6, -1
	bnez	t6, 1b
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD001C	/* -> j 0x1c009ba2 (конфиг PHY) */

	.globl M_T1L
M_T1L:	addi	sp, sp, -16
	sd	ra, 8(sp)
	.word	0xDEAD001F	/* -> jal 0x1c00ab24 (printf) */
	lui	t6, 0x400	/* пауза ~4.8 мс */
1:	addi	t6, t6, -1
	bnez	t6, 1b
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD001C	/* -> j 0x1c009ba2 */

	.globl M_T2
M_T2:	addi	sp, sp, -16
	sd	ra, 8(sp)
	lui	t6, 0x100	/* пауза перед тренировкой */
1:	addi	t6, t6, -1
	bnez	t6, 1b
	.word	0xDEAD001D	/* -> jal 0x1c008f5a (тренировка) */
	ld	ra, 8(sp)
	addi	sp, sp, 16
	.word	0xDEAD001E	/* -> j 0x1c00a190 (bnez->эпилог патч) */
