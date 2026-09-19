// ==================== FBL_entry @ 00000070 ====================

void FBL_entry(void)

{
  FUN_00000084();
  FUN_00006382(0);
  return;
}



// ==================== FUN_00000084 @ 00000084 ====================

/* WARNING: Removing unreachable block (ram,0x000000a8) */

void FUN_00000084(void)

{
  do {
    custom0();
  } while( true );
}



// ==================== FUN_000000aa @ 000000aa ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000000aa(byte *param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  int iVar9;
  
  iVar2 = *(int *)(param_1 + 0x28);
  bVar1 = param_1[8];
  uVar4 = (uint)bVar1;
  uVar3 = (ushort)param_1[1];
  if (param_1[1] == 4) {
    uVar3 = 3;
  }
  uVar6 = (uint)param_1[9];
  if (param_1[9] == 4) {
    uVar6 = 3;
  }
  uVar5 = (uint)param_1[0x20];
  if (param_1[0x20] == 4) {
    uVar5 = 3;
  }
  iVar7 = iVar2;
  iVar9 = 0;
  if ((iVar2 != 0) && (*(int *)(param_1 + 0x24) != 1)) {
    iVar7 = 0;
    iVar9 = iVar2;
  }
  if (3 < bVar1) {
    uVar4 = 3;
  }
  _DAT_0c200034 = (ushort)(uVar6 << 2) & 0xc | uVar3 & 3 | (ushort)(uVar5 << 4) & 0x30;
  uVar8 = (long)(iVar7 << 4) & 0x7ff0U | (ulong)param_1[0x18] & 0xf;
  custom0.rs1.rs2(uVar8,0);
  _DAT_0c200030 = (short)uVar8;
  custom0.rs1.rs2((ulong)*param_1 & 1 | (long)(int)((uint)(3 < bVar1) << 3) |
                  (long)(iVar9 << 4) & 0x7ff0U | (long)(int)(uVar4 << 1),0);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_000002c4 @ 000002c4 ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_000002c4(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1 + (uint)param_1[8] + (uint)param_1[0x18];
  if (0xff < uVar1) {
    return 0xffffffffffffffa1;
  }
  if (*(int *)(param_1 + 0x24) != 1) {
    custom0.rs1.rs2((long)(int)(0x100 - uVar1),0);
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_0000030c @ 0000030c ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0000030c(void)

{
  custom0.rs1.rs2((ulong)_DAT_0c200000,0);
  custom0.rs1.rs2((ulong)(_DAT_0c200000 | 0x37),0);
  _DAT_0c200010 = 2;
  _DAT_0c200000 = _DAT_0c200000 & 0xff | 0x437;
  _DAT_0c200028 = 0x2020;
  return 0;
}



// ==================== FUN_00000348 @ 00000348 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_00000348(void)

{
  long lVar1;
  
  lVar1 = FUN_0000030c();
  if (-1 < lVar1) {
    FUN_00000db8();
    FUN_00000dc2(0,0x70,&DAT_1c00dfb0);
    lVar1 = 0;
    if (_DAT_1c00dfb4 != 0x38316173) {
      FUN_00005b24(0x1c00b418);
      lVar1 = -0x16;
    }
  }
  return lVar1;
}



// ==================== FUN_00000396 @ 00000396 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_00000396(void)

{
  return (long)(_DAT_1c00dfb0 + 0x70);
}



// ==================== FUN_000003a4 @ 000003a4 ====================

long FUN_000003a4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined2 local_50 [4];
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined8 uStack_38;
  
  FUN_00005f3e(local_50,0,0x30);
  local_50[0] = 0x11f;
  uStack_40 = 1;
  uStack_48 = param_2;
  uStack_38 = param_3;
  lVar1 = FUN_00000dd4(param_1,local_50);
  if (lVar1 < 0) {
    FUN_00005b24(0x1c00b438,lVar1,param_2);
  }
  return lVar1;
}



// ==================== FUN_000003fc @ 000003fc ====================

void FUN_000003fc(long param_1,uint param_2,ulong param_3,uint param_4,undefined8 param_5)

{
  undefined8 local_40;
  ulong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  ulong uStack_20;
  undefined8 uStack_18;
  
  local_40 = (ulong)CONCAT11(2,*(undefined1 *)(param_1 + 0x12));
  custom0.rs1.rs2(param_3,0);
  uStack_38 = 2;
  uStack_30 = 0;
  uStack_28 = 0;
  if ((*(uint *)(param_1 + 0x34) & 1) != 0) {
    uStack_38 = (long)(int)((param_2 >>
                            ((long)(int)((uint)*(byte *)(param_1 + 0x2d) -
                                        (uint)*(byte *)(param_1 + 0x2e)) & 0x1fU)) << 0xc) & 0x1000U
                | param_3;
    custom0.rs1.rs2(uStack_38,0);
  }
  uStack_20 = (ulong)param_4;
  uStack_18 = param_5;
  FUN_00000dd4(&local_40);
  return;
}



// ==================== FUN_00000452 @ 00000452 ====================

void FUN_00000452(long param_1,ulong param_2)

{
  undefined1 auStack_21 [9];
  
  if (*(byte *)(param_1 + 0x3d) != param_2) {
    auStack_21[0] = 0x40;
    if (param_2 != 1) {
      auStack_21[0] = 0;
    }
    FUN_000003a4(0xd0,auStack_21);
    *(char *)(param_1 + 0x3d) = (char)param_2;
    return;
  }
  return;
}



// ==================== FUN_00000492 @ 00000492 ====================

void FUN_00000492(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  local_40 = 0x10f;
  uStack_30 = 0;
  uStack_28 = 0;
  uStack_20 = 1;
  uStack_38 = param_1;
  uStack_18 = param_2;
  lVar1 = FUN_00000dd4(&local_40);
  if (lVar1 < 0) {
    FUN_00005b24(0x1c00b458,lVar1,param_1);
  }
  return;
}



// ==================== FUN_000004d4 @ 000004d4 ====================

undefined8 FUN_000004d4(undefined8 param_1,byte *param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte bStack_21;
  
  iVar1 = 100000;
  do {
    FUN_00000492(param_1,0xc0,&bStack_21);
    if ((bStack_21 & 1) == 0) {
      uVar2 = 0;
      goto LAB_0000050c;
    }
    FUN_0000391e(10);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  uVar2 = 0xffffffffffffff92;
LAB_0000050c:
  if (param_2 != (byte *)0x0) {
    *param_2 = bStack_21;
  }
  return uVar2;
}



// ==================== FUN_00000526 @ 00000526 ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_00000526(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4,
                 undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  byte abStack_171 [17];
  undefined2 auStack_160 [4];
  undefined8 uStack_158;
  
  custom0();
  FUN_00005f3e(auStack_160,0,0x30);
  auStack_160[0] = 0x313;
  custom0.rs1.rs2(param_2,0);
  uStack_158 = 0x313;
  FUN_00000dd4(param_1,auStack_160);
  lVar1 = FUN_000004d4(param_1,abStack_171);
  puVar3 = (undefined4 *)custom0.rd();
  if (lVar1 < 0) {
    FUN_00005b24(0x1c00b478,lVar1,param_2);
    return lVar1;
  }
  if (param_4 != 0) goto LAB_000005f0;
  bVar2 = abStack_171[0] & 0x70;
  if (bVar2 == 0x30) {
    uVar4 = 6;
  }
  else if (bVar2 < 0x31) {
    if ((abStack_171[0] & 0x70) == 0) {
      *puVar3 = 0;
      goto LAB_000005f0;
    }
    if (bVar2 != 0x10) {
      if (bVar2 == 0x20) {
        FUN_00005b24(0x1c00b4a0,param_2);
        lVar1 = -0x4a;
      }
      goto LAB_000005f0;
    }
    uVar4 = 3;
  }
  else {
    if (bVar2 != 0x50) goto LAB_000005f0;
    uVar4 = 8;
  }
  *puVar3 = uVar4;
LAB_000005f0:
  if (_DAT_1c00e0b0 == 0) {
    FUN_000003fc(param_1,param_2,param_3,param_6,param_5);
    return lVar1;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_000006d6 @ 000006d6 ====================

void FUN_000006d6(undefined8 param_1)

{
  byte abStack_11 [9];
  
  abStack_11[0] = 0;
  FUN_00000492(0xb0,abStack_11);
  if ((abStack_11[0] & 0x10) == 0) {
    abStack_11[0] = abStack_11[0] | 0x10;
    FUN_000003a4(param_1,0xb0,abStack_11);
  }
  return;
}



// ==================== FUN_00000712 @ 00000712 ====================

void FUN_00000712(undefined8 param_1)

{
  byte abStack_11 [9];
  
  abStack_11[0] = 0;
  FUN_00000492(0xb0,abStack_11);
  if ((abStack_11[0] & 0x10) != 0) {
    abStack_11[0] = abStack_11[0] & 0xef;
    FUN_000003a4(param_1,0xb0,abStack_11);
  }
  return;
}



// ==================== FUN_0000074c @ 0000074c ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0x000008e6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_0000074c(long param_1,long param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  bool bVar9;
  undefined4 auStack_74 [3];
  
  iVar2 = *param_3;
  auStack_74[0] = 0;
  if (iVar2 == 1) {
    uVar4 = (ulong)*(int *)(*(long *)(param_1 + 0x40) + 0xaa4);
  }
  else {
    uVar4 = (ulong)*(ushort *)(param_1 + 0x2a);
  }
  lVar6 = (long)_DAT_1c00e0b0;
  bVar9 = lVar6 != 0 || iVar2 == 2;
  if ((long)param_3[10] < (long)uVar4) {
    custom0.rs1.rs2((long)(int)*(uint *)(param_1 + 0x20),0);
    if (param_2 < lVar6) {
      lVar8 = param_2 >> ((ulong)*(byte *)(param_1 + 0x2e) & 0x3f);
      lVar7 = (long)(int)(*(uint *)(param_1 + 0x20) >> ((ulong)*(byte *)(param_1 + 0x2e) & 0x1f));
      custom0.rs1.rs2(lVar7,0);
      if ((long)(param_3[6] + param_3[10]) <= (long)((lVar7 - lVar8) * uVar4)) {
        bVar1 = *(byte *)(param_1 + 0x2c);
        lVar7 = (long)(int)lVar8;
        uVar3 = *(uint *)(param_1 + 0x34);
        param_3[8] = 0;
        param_3[9] = 0;
        if ((uVar3 & 2) != 0) {
          FUN_00000452(param_1,param_2 >> ((ulong)bVar1 & 0x3f) & 0xff);
        }
        if (bVar9) {
          FUN_00000712(param_1);
        }
        lVar8 = FUN_00000526(param_1,lVar7,*(undefined2 *)(param_1 + 0x28),bVar9,auStack_74,
                             *(undefined8 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x2a));
        if ((lVar8 != -0x4a) && (lVar8 != 0)) {
          FUN_00005b24(0x1c00b520,lVar8,lVar7);
          if (lVar6 == 0 && iVar2 != 2) {
            return lVar8;
          }
          FUN_000006d6(param_1);
          return lVar8;
        }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
        halt_unimplemented();
      }
    }
    uVar5 = 0x1c00b4f0;
  }
  else {
    uVar5 = 0x1c00b4c8;
  }
  FUN_00005b24(uVar5,0x1c00b5b8);
  return -0x16;
}



// ==================== FUN_000008ec @ 000008ec ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000008ec(long param_1,long param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  
  bVar2 = _DAT_1c00e0b0 != 0;
  if (*param_3 == 1) {
    uVar5 = (ulong)*(int *)(*(long *)(param_1 + 0x40) + 0xaa4);
  }
  else {
    uVar5 = (ulong)*(ushort *)(param_1 + 0x2a);
  }
  custom0.rs1.rs2((long)(int)*(uint *)(param_1 + 0x20),0);
  if (param_2 < 1) {
    if ((int)*(undefined8 *)(param_3 + 6) < 1) {
LAB_000009c4:
      if (bVar2 || *param_3 == 2) {
        FUN_00000712(param_1);
      }
      bVar1 = *(byte *)(param_1 + 0x2c);
      uVar3 = *(uint *)(param_1 + 0x34);
      param_3[4] = 0;
      param_3[5] = 0;
      if ((uVar3 & 2) != 0) {
        FUN_00000452(param_1,param_2 >> ((ulong)bVar1 & 0x3f) & 0xff);
      }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    if (uVar5 <= (ulong)(long)param_3[10]) {
      uVar4 = 0x1c00b540;
      goto LAB_00000956;
    }
    lVar6 = (long)((int)*(undefined8 *)(param_3 + 6) + param_3[10]);
    custom0.rs1.rs2(lVar6,0);
    lVar7 = (long)(int)(*(uint *)(param_1 + 0x20) >> ((ulong)*(byte *)(param_1 + 0x2e) & 0x1f));
    custom0.rs1.rs2(lVar7,0);
    if (lVar6 <= (long)((lVar7 - (param_2 >> ((ulong)*(byte *)(param_1 + 0x2e) & 0x3f))) * uVar5)) {
      param_3[8] = 0;
      param_3[9] = 0;
      goto LAB_000009c4;
    }
  }
  uVar4 = 0x1c00b4f0;
LAB_00000956:
  FUN_00005b24(uVar4,0x1c00b5d0);
  return 0xffffffffffffffea;
}



// ==================== FUN_00000b32 @ 00000b32 ====================

void FUN_00000b32(undefined1 param_1)

{
  undefined1 auStack_11 [9];
  
  auStack_11[0] = param_1;
  FUN_000003a4(0xa0,auStack_11);
  return;
}



// ==================== FUN_00000b4c @ 00000b4c ====================

void FUN_00000b4c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puStack_68;
  undefined1 auStack_60 [8];
  undefined8 uStack_58;
  undefined8 uStack_50;
  
  custom0();
  FUN_00005f3e(auStack_60,0,0x40);
  uStack_58 = param_3;
  FUN_000008ec(param_1,param_2,auStack_60);
  *puStack_68 = uStack_50;
  return;
}



// ==================== FUN_00000b8e @ 00000b8e ====================

bool FUN_00000b8e(long param_1,long param_2)

{
  long lVar1;
  undefined2 uStack_68;
  undefined1 auStack_60 [24];
  undefined8 uStack_48;
  undefined2 *puStack_28;
  
  FUN_00005f3e(auStack_60,0,0x38);
  lVar1 = (long)((int)(param_2 >> ((ulong)*(byte *)(param_1 + 0x2d) & 0x3f)) <<
                ((ulong)*(byte *)(param_1 + 0x2d) & 0x1f));
  uStack_48 = 2;
  puStack_28 = &uStack_68;
  custom0.rs1.rs2(lVar1,0);
  uStack_68 = 0;
  FUN_0000074c(param_1,lVar1,auStack_60);
  return ((byte)uStack_68 & uStack_68._1_1_) != 0xff;
}



// ==================== FUN_00000be6 @ 00000be6 ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00000be6(undefined8 *param_1)

{
  long lVar1;
  undefined2 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined2 *puStack_28;
  
  uStack_58 = 0;
  if (_DAT_1c00e020 == 0) {
    FUN_00005f3e(0,0x48);
    *(undefined2 *)((long)param_1 + 0x12) = 0x23b;
    *(undefined1 *)((long)param_1 + 0x14) = 0x84;
    FUN_00005f3e(&uStack_50,0,0x30);
    uStack_50 = CONCAT71(uStack_50._1_7_,0xff);
    lVar1 = FUN_00000dd4(param_1,&uStack_50);
    if (lVar1 < 0) {
      FUN_00005b8a(0x1c00b568);
    }
    FUN_0000391e(2000);
    uStack_48 = 0;
    uStack_50 = 0x9f;
    uStack_30 = 2;
    puStack_28 = &uStack_58;
    uStack_40 = 0;
    uStack_38 = 0;
    FUN_00000dd4(param_1,&uStack_50);
    FUN_00005b24(0x1c00b580,(undefined1)uStack_58,uStack_58._1_1_);
    *param_1 = 0x1c00b5a8;
    *(undefined2 *)(param_1 + 2) = uStack_58;
    param_1[4] = 0x2000008000000;
    *(undefined4 *)(param_1 + 5) = 0x400800;
    *(undefined2 *)((long)param_1 + 0x2c) = 0x111b;
    *(undefined1 *)((long)param_1 + 0x2e) = 0xb;
    *(undefined2 *)(param_1 + 6) = 0x7ff;
    param_1[3] = 0x1c00e028;
    param_1[8] = 0x1c00ccb8;
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  return 0;
}



// ==================== FUN_00000d06 @ 00000d06 ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_00000d06(long param_1,ulong param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    if (param_2 < (ulong)(long)*(int *)(param_1 + 0x20)) {
      custom0.rs1.rs2(param_2,0);
      custom0.rs1.rs2((long)(*(int *)(param_1 + 0x24) + -1),0);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    uVar1 = 0xffffffffffffffff;
  }
  return uVar1;
}



// ==================== FUN_00000db8 @ 00000db8 ====================

void FUN_00000db8(void)

{
  FUN_00000be6(0x1c00e068);
  return;
}



// ==================== FUN_00000dc2 @ 00000dc2 ====================

void FUN_00000dc2(int param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00000d06(0x1c00e068,(long)param_1,param_2,param_3);
  return;
}



// ==================== FUN_00000dd4 @ 00000dd4 ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_00000dd4(char *param_1)

{
  char *pcVar1;
  undefined1 auStack_58 [64];
  
  FUN_00005f3e(auStack_58,0,0x38);
  pcVar1 = &DAT_1c00d860;
  while( true ) {
    if (*pcVar1 == '\0') {
      FUN_00005b24(0x1c00b5e8);
      return 0xffffffffffffffea;
    }
    if (*param_1 == *pcVar1) break;
    pcVar1 = pcVar1 + 5;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00000ea2 @ 00000ea2 ====================

void FUN_00000ea2(long param_1,long param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  uint uVar14;
  undefined8 unaff_s0;
  ulong uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  ulong uVar22;
  byte bVar23;
  ulong uVar24;
  uint unaff_s2;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  uint uVar28;
  
  custom0.rs1.rs2(param_2,unaff_s0);
  uVar24 = 0;
  uVar14 = 0;
  uVar15 = 0;
  for (uVar28 = 0; uVar28 != ((uint)param_2 >> 8) << 2; uVar28 = uVar28 + 1) {
    uVar16 = custom0.rd();
    uVar8 = *(uint *)(param_1 + 8) ^ *(uint *)(param_1 + 0xc) ^ (uint)uVar16 ^ unaff_s2;
    uVar6 = *(uint *)(param_1 + 0x20) ^ *(uint *)(param_1 + 0x24);
    uVar7 = *(uint *)(param_1 + 0x28) ^ *(uint *)(param_1 + 0x2c);
    unaff_s2 = *(uint *)(param_1 + 0x38);
    uVar14 = uVar8 ^ uVar14 ^ uVar7 ^ uVar6;
    uVar22 = (ulong)(int)(*(uint *)(param_1 + 0x18) ^ *(uint *)(param_1 + 0x1c) ^
                          *(uint *)(param_1 + 0x10) ^ *(uint *)(param_1 + 0x14) ^ uVar8 ^
                          uVar6 ^ unaff_s2 ^
                                  *(uint *)(param_1 + 0x34) ^ uVar7 ^ *(uint *)(param_1 + 0x30) ^
                         *(uint *)(param_1 + 0x3c));
    uVar24 = uVar24 ^ uVar22;
    if ((uVar28 & 2) == 0) {
      uVar15 = uVar15 ^ uVar22;
    }
    param_1 = param_1 + 0x40;
  }
  uVar14 = uVar14 ^ uVar14 >> 0x10;
  uVar15 = uVar15 ^ (long)(int)((uint)uVar15 >> 0x10);
  uVar15 = (uVar15 ^ (long)(int)((uint)uVar15 >> 8)) & 0xff;
  custom0.rs1.rs2(uVar24,uVar15);
  uVar24 = uVar24 ^ (long)(int)((uint)uVar24 >> 0x10);
  custom0.rs1.rs2(uVar24,uVar15);
  bVar13 = (byte)uVar24 ^ (byte)(uVar24 >> 8) ^ (byte)uVar14 ^ (byte)(uVar14 >> 8);
  uVar16 = custom0.rd();
  uVar25 = custom0.rd();
  uVar27 = custom0.rd();
  uVar26 = custom0.rd();
  uVar21 = custom0.rd();
  uVar17 = custom0.rd();
  uVar18 = custom0.rd();
  uVar19 = custom0.rd();
  uVar20 = custom0.rd();
  *param_3 = (byte)((int)uVar21 << 6) |
             (byte)((int)uVar16 << 3) | (byte)uVar27 | (byte)((int)uVar25 << 2) |
             (byte)((int)uVar26 << 1) | (byte)((int)uVar17 << 4) | (byte)((int)uVar18 << 7) |
             (byte)((int)uVar19 << 5);
  uVar26 = custom0.rd();
  uVar16 = custom0.rd();
  uVar17 = custom0.rd();
  uVar18 = custom0.rd();
  uVar19 = custom0.rd();
  uVar21 = custom0.rd();
  uVar25 = custom0.rd();
  param_3[1] = (byte)((int)uVar26 << 6) | (byte)((int)uVar20 << 4) | (byte)uVar16 |
               (byte)((int)uVar17 << 2) | (byte)((int)uVar18 << 7) | (byte)((int)uVar19 << 5) |
               (byte)((int)uVar21 << 3) | (byte)((int)uVar25 << 1);
  uVar16 = custom0.rd();
  custom0.rs1((long)((int)uVar16 << 7));
  uVar20 = custom0.rd();
  uVar19 = custom0.rd();
  uVar16 = custom0.rd();
  uVar17 = custom0.rd();
  uVar18 = custom0.rd();
  iVar1 = (int)uVar20 << 6;
  iVar2 = (int)uVar19 << 5;
  iVar3 = (int)uVar16 << 4;
  iVar4 = (int)uVar17 << 3;
  iVar5 = (int)uVar18 << 2;
  custom0.rs1((long)iVar1);
  custom0.rs1((long)iVar2);
  custom0.rs1((long)iVar3);
  custom0.rs1((long)iVar4);
  custom0.rs1((long)iVar5);
  bVar9 = (byte)iVar4;
  bVar10 = (byte)iVar3;
  bVar11 = (byte)iVar2;
  bVar12 = (byte)iVar1;
  bVar23 = (byte)iVar5;
  if (param_2 == 1) {
    bVar23 = bVar10 | bVar11 | bVar12 | bVar13 | bVar23 | bVar9 | 3;
  }
  else {
    uVar16 = custom0.rd();
    uVar17 = custom0.rd();
    bVar23 = bVar10 | bVar11 | bVar13 | bVar12 | bVar9 | bVar23 | (byte)uVar16 |
             (byte)((int)uVar17 << 1);
  }
  param_3[2] = bVar23;
  return;
}



// ==================== FUN_00001232 @ 00001232 ====================

undefined8 FUN_00001232(byte *param_1,byte *param_2,long param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined8 unaff_s0;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  bVar1 = *param_1 ^ *param_2;
  bVar2 = param_1[1] ^ param_2[1];
  bVar3 = param_1[2] ^ param_2[2];
  if ((bVar1 == 0 && bVar2 == 0) && bVar3 == 0) {
    return 0;
  }
  if (((bVar1 ^ bVar1 >> 1) & 0x55) == 0x55) {
    if (((bVar2 ^ bVar2 >> 1) & 0x55) == 0x55) {
      custom0.rs1.rs2(param_3,unaff_s0);
      if (param_3 == 1) {
        if (((bVar3 >> 1 ^ bVar3) & 0x54) != 0x54) goto LAB_0000131a;
        custom0.rd();
      }
      else {
        if ((param_3 != 2) || (((bVar3 >> 1 ^ bVar3) & 0x55) != 0x55)) goto LAB_0000131a;
        custom0.rd();
        custom0.rd();
      }
      custom0.rd();
      custom0.rd();
      custom0.rd();
      custom0();
      return 1;
    }
  }
LAB_0000131a:
  uVar4 = custom0.rd();
  uVar5 = custom0.rd();
  uVar6 = custom0.rd();
  if ((int)uVar4 + (int)uVar5 + (int)uVar6 != 1) {
    FUN_00005b24(0x1c00b608,0x1c00b628,bVar1,0x1c00b740);
    return 0xffffffffffffffb6;
  }
  return 1;
}



// ==================== FUN_0000136e @ 0000136e ====================

void FUN_0000136e(undefined8 param_1)

{
  undefined4 auStack_48 [2];
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  uStack_18 = 0x1c0062f0;
  uStack_38 = 0x23000000;
  uStack_30 = 0x80000020000;
  uStack_28 = 0x40000001000;
  auStack_48[0] = 0;
  uStack_20 = 1;
  uStack_40 = param_1;
  FUN_0000177e(&uStack_38,auStack_48,1);
  return;
}



// ==================== FUN_000013ae @ 000013ae ====================

void FUN_000013ae(void)

{
  custom0();
  return;
}



// ==================== FUN_000013b4 @ 000013b4 ====================

ulong FUN_000013b4(long param_1)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = FUN_000013ae((long)(int)param_1);
  uVar2 = FUN_000013ae(param_1 >> 0x20);
  custom0.rs1.rs2(uVar2,0);
  return uVar2 | (long)iVar1 << 0x20;
}



// ==================== FUN_000013e2 @ 000013e2 ====================

ulong FUN_000013e2(ulong param_1)

{
  ulong uVar1;
  
  uVar1 = custom0.rd();
  return (long)(1 << (param_1 & 7)) & uVar1;
}



// ==================== FUN_000013f6 @ 000013f6 ====================

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_000013f6(void)

{
  custom0.rd();
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00001408 @ 00001408 ====================

void FUN_00001408(undefined8 *param_1,undefined8 param_2,int param_3,int param_4,int param_5)

{
                    /* WARNING: Could not recover jumptable at 0x00001420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)((long)(*(int *)(param_1 + 2) + param_3),(long)param_4,(long)param_5,param_2,
                      (code *)*param_1);
  return;
}



// ==================== FUN_00001422 @ 00001422 ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_00001422(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = FUN_000013e2(param_2,param_1 + 0x381a8);
  if (lVar1 == 0) {
    custom0.rd();
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  return 3;
}



// ==================== FUN_000015a0 @ 000015a0 ====================

undefined8 FUN_000015a0(long param_1,undefined8 param_2,ulong param_3)

{
  undefined8 uVar1;
  
  if ((param_3 < (ulong)(long)*(int *)(param_1 + 0xc)) && (-1 < (long)param_3)) {
    uVar1 = FUN_00001422((long)(int)param_3,param_2);
    return uVar1;
  }
  return 0xffffffffffffffea;
}



// ==================== FUN_000015b8 @ 000015b8 ====================

/* WARNING: Control flow encountered unimplemented instructions */

long FUN_000015b8(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  
  if (param_3 < (ulong)(long)*(int *)(param_1 + 0xc)) {
    if ((long)param_3 < 0) {
      return -0x16;
    }
    lVar2 = FUN_00001422((long)(int)param_3,param_2);
    if (lVar2 != 0) {
      return lVar2;
    }
    iVar1 = FUN_000013ae((long)*(int *)(param_2 + 8));
    if (iVar1 == 0x7ffff000) {
      if (*(int *)(param_1 + 0x38090) == 0) {
        return 0;
      }
      return 6;
    }
    if (iVar1 != 0) {
      return 0;
    }
    if (*(char *)(param_2 + 5) != '\x02') {
      return 0;
    }
    if ((*(byte *)(param_1 + 0x38230) & 1) == 0) {
      return 0;
    }
    iVar1 = FUN_000013ae((long)*(int *)(param_2 + 0xc));
    if ((ulong)(long)iVar1 < 6) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    FUN_00005b24(0x1c00b9f8,0,(long)iVar1,6);
  }
  return -0x16;
}



// ==================== FUN_0000170e @ 0000170e ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_0000170e(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = custom0.rd();
    iVar1 = FUN_000013ae(uVar2);
    uVar3 = (ulong)iVar1;
    if ((uVar3 < (ulong)(long)*(int *)(param_1 + 0xc)) && (-1 < (long)uVar3)) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    FUN_00005b24(0x1c00ba20,uVar3);
    uVar2 = 2;
  }
  return uVar2;
}



// ==================== FUN_0000177e @ 0000177e ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0x00001a76) */
/* WARNING: Removing unreachable block (ram,0x00001a88) */

undefined8 FUN_0000177e(long *param_1,int *param_2,long param_3)

{
  ushort uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  int *piVar16;
  uint uVar17;
  long lStack_d0;
  
  iVar2 = *(int *)((long)param_1 + 0x1c);
  plVar3 = (long *)*param_1;
LAB_000017c6:
  FUN_00005f3e(plVar3,0,0x482e0);
  lVar4 = param_1[1];
  uVar17 = *(uint *)(param_1 + 2);
  lVar8 = param_1[3];
  *plVar3 = param_1[4];
  uVar7 = *(uint *)((long)param_1 + 0xc);
  plVar3[3] = (ulong)uVar7;
  plVar3[4] = (ulong)uVar17;
  custom0.rs1.rs2((long)(int)lVar4,0);
  uVar12 = (ulong)uVar7 - (ulong)uVar17;
  iVar5 = *(int *)((long)param_1 + 0x14);
  *(int *)(plVar3 + 2) = (int)lVar8;
  plVar3[5] = uVar12;
  lVar4 = 0;
  custom0();
  custom0.rs1.rs2((long)iVar5,0);
  custom0();
  custom0();
  plVar3[7] = (((long)iVar5 + 0x402U) / uVar12) * uVar12;
  *(int *)(plVar3 + 0x7012) = iVar2;
  for (; (int)lVar4 < param_3; lVar4 = lVar4 + 1) {
    uVar9 = custom0.rd();
    FUN_000013f6(uVar9,plVar3 + 0x7046,param_2,lVar4 << 4);
  }
  lVar4 = (long)(plVar3 + 0x705c);
  uVar12 = 0;
  while( true ) {
    lVar8 = FUN_000015b8(plVar3,lVar4,uVar12);
    if (lVar8 == 7) {
      *(int *)((long)plVar3 + 0xc) = (int)uVar12;
      goto LAB_00001870;
    }
    if ((lVar8 == 6) && (*(int *)(plVar3 + 0x7012) != 0)) break;
    uVar12 = (ulong)((int)uVar12 + 1);
    lVar4 = lVar4 + 0x40;
    if (uVar12 == 0x1ffd) goto code_r0x00001e7e;
  }
  lVar4 = FUN_00001408(plVar3,plVar3 + 8,uVar12,plVar3[4],&DAT_00010020);
  if (lVar4 != 0) {
    if (lVar4 != 5) goto LAB_000018f4;
    custom0();
    DAT_00010090 = 1;
  }
  iVar5 = FUN_000013ae((long)*(int *)(plVar3 + 8));
  uVar10 = (ulong)iVar5;
  uVar11 = 0x7b11d69f;
  if (uVar10 != 0x7b11d69f) {
    uVar9 = 0x1c00ba50;
    goto LAB_000018f0;
  }
  uVar10 = (ulong)*(byte *)((long)plVar3 + 0x44);
  if (uVar10 != 1) {
    uVar9 = 0x1c00ba88;
    uVar11 = 1;
    goto LAB_000018f0;
  }
  iVar5 = FUN_000013ae((long)*(int *)((long)plVar3 + 0x4c));
  uVar11 = (ulong)iVar5;
  if (0x1ffc < iVar5 - 1U) {
    uVar9 = 0x1c00bac0;
LAB_00001964:
    FUN_00005b24(uVar9,uVar11);
    goto LAB_000018f4;
  }
  lVar4 = uVar11 * plVar3[5];
  if (lVar4 != plVar3[7]) {
    FUN_00005b24(0x1c00baf8,lVar4);
    goto LAB_000018f4;
  }
  uVar10 = 0;
  if (0 < (long)uVar11) {
    uVar9 = custom0.rd();
    iVar5 = FUN_000013ae(uVar9,plVar3 + 10);
    uVar11 = (ulong)iVar5;
    if (((ulong)(long)*(int *)((long)plVar3 + 0xc) <= uVar11) || ((long)uVar11 < 0))
    goto LAB_000018f4;
    lVar4 = FUN_00001422(plVar3,uVar11,plVar3 + 0x200c);
    if ((lVar4 == 0) || (lVar4 == 5)) {
      if (uVar12 == uVar11) {
        FUN_00005f4e(plVar3 + 0x200c,plVar3 + (long)(s__aliases_00007058 + uVar12 * 8 + 4),
                     &DAT_00017fe8);
      }
      iVar5 = FUN_000013ae((long)*(int *)(plVar3 + 0x200d));
      uVar10 = (ulong)iVar5;
      if (uVar10 == 0x7ffff000) {
        FUN_000013b4(plVar3[0x2011]);
        custom0.rd();
        custom0();
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
        halt_unimplemented();
      }
      uVar9 = 0x1c00bb68;
      uVar11 = 0x7ffff000;
    }
    else {
      uVar9 = 0x1c00bb30;
    }
    goto LAB_000018f0;
  }
  iVar6 = FUN_000013ae((long)*(int *)(plVar3 + 0x905d));
  lVar8 = (long)(plVar3 + 0x905c);
  uVar10 = (ulong)iVar6;
  *(undefined4 *)(plVar3 + 0x905d) = 0;
  iVar6 = FUN_000062de(0xffffffffffffffff,lVar8,lVar4);
  uVar11 = (ulong)iVar6;
  if (uVar10 != uVar11) {
    FUN_00005b8a(0x1c00bc28);
    uVar9 = 0x1c00bc50;
    goto LAB_000018f0;
  }
  plVar3[0xb05b] = 0;
  *(int *)((long)plVar3 + 0x28084) = iVar5;
  uVar12 = plVar3[7];
  FUN_00005f3e(plVar3 + 0x7013,0,0x88);
  if (uVar12 < 0x10041) goto LAB_000018f4;
  iVar5 = FUN_000013ae((long)*(int *)(plVar3 + 0xb060));
  uVar10 = (ulong)iVar5;
  uVar11 = 0xffffffffd4b82ef7;
  if (uVar10 != 0xffffffffd4b82ef7) {
    uVar9 = 0x1c00bc80;
    goto LAB_000018f0;
  }
  if (uVar12 < 0x1804d) goto LAB_000018f4;
  iVar5 = FUN_000013ae((long)*(int *)(plVar3 + 0xb064));
  uVar10 = (ulong)iVar5;
  if (uVar10 == 0x67af4d08) {
    if (uVar12 < 0x20059) goto LAB_000018f4;
    iVar5 = FUN_000013ae((long)*(int *)((long)plVar3 + 0x6032c),0x67af4d08);
    uVar10 = (ulong)iVar5;
    if (uVar10 == 0x67af4d08) {
      uVar1 = *(ushort *)((long)plVar3 + 0x58324);
      uVar15 = (ulong)(int)((uint)uVar1 << 8);
      custom0.rs1.rs2((ulong)uVar1,plVar3);
      custom0.rs1.rs2(uVar15 | uVar1,0);
      uVar1 = *(ushort *)(plVar3 + 0xc066);
      custom0.rs1.rs2((ulong)uVar1,plVar3);
      uVar13 = (long)(int)((uint)uVar1 << 8) | (ulong)uVar1;
      custom0.rs1.rs2(uVar13,0);
      uVar1 = *(ushort *)((long)plVar3 + 0x58326);
      custom0.rs1.rs2((ulong)uVar1,plVar3);
      uVar10 = (long)(int)((uint)uVar1 << 8) | (ulong)uVar1;
      uVar1 = *(ushort *)((long)plVar3 + 0x60332);
      custom0.rs1.rs2(uVar10,0);
      custom0.rs1.rs2((ulong)uVar1,plVar3);
      uVar11 = (long)(int)((uint)uVar1 << 8) | (ulong)uVar1;
      custom0.rs1.rs2(uVar11,0);
      *(int *)(plVar3 + 0x5011) = (int)uVar10;
      *(int *)((long)plVar3 + 0x2808c) = (int)uVar11;
      if (uVar15 < 0x1ffe) {
        if (uVar13 < 0x1ffe) {
          if (0x1ffd < uVar10) {
            uVar9 = 0x1c00bd48;
            uVar11 = uVar10;
            goto LAB_00001964;
          }
          if (uVar11 < 0x1ffe) {
            iVar6 = FUN_000013ae((long)*(int *)((long)plVar3 + 0x58304));
            uVar14 = 0x20058;
            iVar5 = 0;
            goto LAB_00001c28;
          }
          uVar9 = 0x1c00bd70;
        }
        else {
          uVar9 = 0x1c00bd20;
          uVar11 = uVar13;
        }
      }
      else {
        uVar9 = 0x1c00bd00;
        uVar11 = uVar15;
      }
      goto LAB_00001964;
    }
  }
  uVar11 = 0x67af4d08;
  uVar9 = 0x1c00bcc0;
  goto LAB_000018f0;
LAB_00001c28:
  if (iVar5 == iVar6) goto code_r0x00001c2c;
  uVar14 = uVar14 + 8;
  if (uVar12 <= uVar14) goto LAB_000018f4;
  iVar5 = iVar5 + 1;
  goto LAB_00001c28;
code_r0x00001c2c:
  for (uVar17 = 0; uVar7 = FUN_000013ae((long)*(int *)(plVar3 + 0xb061)), uVar17 < uVar7;
      uVar17 = uVar17 + 1) {
    uVar14 = uVar14 + 8;
    if (uVar12 <= uVar14) goto LAB_000018f4;
    uVar9 = custom0.rd();
    iVar5 = FUN_000013ae(uVar9);
    FUN_000013f6((long)iVar5,plVar3 + 0x7013);
  }
  iVar6 = FUN_000013ae((long)*(int *)((long)plVar3 + 0x5830c));
  for (iVar5 = 0; iVar6 != iVar5; iVar5 = iVar5 + 1) {
    uVar14 = uVar14 + 8;
    if (uVar12 <= uVar14) goto LAB_000018f4;
  }
  iVar6 = FUN_000013ae((long)*(int *)((long)plVar3 + 0x58314));
  for (iVar5 = 0; iVar6 != iVar5; iVar5 = iVar5 + 1) {
    uVar14 = uVar14 + 8;
    if (uVar12 <= uVar14) goto LAB_000018f4;
  }
  iVar5 = FUN_000013ae((long)*(int *)(plVar3 + 0xb063));
  if (iVar5 == 0) {
    lVar4 = FUN_0000170e(plVar3,plVar3 + 0xb065,uVar15);
    if ((lVar4 == 0) && (lVar4 = FUN_0000170e(plVar3,(long)plVar3 + 0x60334,uVar13), lVar4 == 0)) {
      uVar9 = custom0.rd();
      plVar3[0x2014] = (long)(plVar3 + 0x2015);
      *(undefined4 *)((long)plVar3 + 0x3008c) = *(undefined4 *)(plVar3 + 0x5011);
      *(undefined4 *)((long)plVar3 + 0x3808c) = *(undefined4 *)((long)plVar3 + 0x2808c);
      FUN_00005b24(0x1c00be20,uVar9);
      goto LAB_00001870;
    }
  }
  else if (uVar14 + 0x20 < uVar12) {
    uVar9 = custom0.rd();
    iVar5 = FUN_000013ae(uVar9);
    uVar11 = 0xfffffffffa370ed1;
    uVar10 = (ulong)iVar5;
    if (uVar10 == 0xfffffffffa370ed1) {
      FUN_000013ae((long)*(int *)(lVar8 + uVar14 + 4));
      FUN_000013ae((long)*(int *)(lVar8 + uVar14 + 0x10));
      FUN_000013ae((long)*(int *)(lVar8 + uVar14 + 0x20 + 4));
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    uVar9 = 0x1c00bda0;
LAB_000018f0:
    FUN_00005b24(uVar9,uVar10,uVar11);
  }
LAB_000018f4:
  FUN_00005b8a(0x1c00be50);
  uVar17 = 0;
  plVar3[0x7057] = 0;
  plVar3[0x7058] = 0;
  plVar3[0x7059] = 0;
  plVar3[0x705a] = 0;
  plVar3[0x705b] = 0;
LAB_00001916:
  if (uVar17 < *(uint *)((long)plVar3 + 0xc)) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
LAB_00001870:
  lStack_d0 = 0;
  piVar16 = param_2;
  while( true ) {
    if (param_3 <= lStack_d0) {
      return 0;
    }
    FUN_00005b24(0x1c00be88,(long)*piVar16);
    if (*piVar16 != 0) break;
    if (*(int *)(plVar3 + 0x7057) != -1) {
      custom0();
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    piVar16 = piVar16 + 4;
    lStack_d0 = (long)((int)lStack_d0 + 1);
  }
  if (iVar2 == 0) {
    FUN_00005b8a(0x1c00bf90);
    return 0xffffffffffffffea;
  }
  iVar2 = 0;
  goto LAB_000017c6;
code_r0x00001e7e:
  uVar17 = 0x1ffd;
  goto LAB_00001916;
}



// ==================== FUN_000020e6 @ 000020e6 ====================

long FUN_000020e6(int *param_1)

{
  custom0();
  return (long)*param_1;
}



// ==================== FUN_000020ee @ 000020ee ====================

ulong FUN_000020ee(ulong param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  iVar1 = FUN_000020e6(param_1 + 4);
  if ((param_1 & 7) != 0) {
    return 0xffffffffffffffed;
  }
  iVar2 = FUN_000020e6(param_1);
  if (iVar2 == -0x2ff20113) {
    uVar3 = FUN_000020e6(param_1 + 0x14);
    if (uVar3 < 2) {
      return 0xfffffffffffffff6;
    }
    uVar3 = FUN_000020e6(param_1 + 0x18);
    if (0x11 < uVar3) {
      return 0xfffffffffffffff6;
    }
  }
  else {
    if (iVar2 != 0x2ff20112) {
      return 0xfffffffffffffff7;
    }
    iVar2 = FUN_000020e6(param_1 + 0x24);
    if (iVar2 == 0) {
      return 0xfffffffffffffff9;
    }
  }
  uVar4 = 0xfffffffffffffff8;
  if ((ulong)(long)iVar1 < 0x7fffffff) {
    uVar4 = (long)iVar1;
  }
  return uVar4;
}



// ==================== FUN_00002184 @ 00002184 ====================

undefined8 FUN_00002184(ulong param_1)

{
  undefined8 uVar1;
  
  if (param_1 < 2) {
    uVar1 = 0x1c;
  }
  else {
    uVar1 = 0x20;
    if ((param_1 != 2) && (uVar1 = 0x24, 0x10 < param_1)) {
      uVar1 = 0x28;
    }
  }
  return uVar1;
}



// ==================== FUN_000021aa @ 000021aa ====================

void FUN_000021aa(long param_1)

{
  int iVar1;
  
  iVar1 = FUN_000020e6(param_1 + 0x14);
  FUN_00002184((long)iVar1);
  return;
}



// ==================== FUN_000021bc @ 000021bc ====================

undefined8 FUN_000021bc(ulong param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  
  if ((param_1 & 7) != 0) {
    return 0xffffffffffffffed;
  }
  iVar4 = FUN_000020e6();
  uVar7 = 0xfffffffffffffff7;
  if (iVar4 == -0x2ff20113) {
    iVar4 = FUN_000020e6(param_1 + 0x14);
    uVar10 = (ulong)iVar4;
    uVar7 = 0xfffffffffffffff6;
    if (1 < uVar10) {
      iVar4 = FUN_000020e6(param_1 + 0x18);
      uVar9 = (ulong)iVar4;
      uVar7 = 0xfffffffffffffff6;
      if ((uVar9 < 0x12) && (uVar9 <= uVar10)) {
        uVar6 = FUN_000021aa(param_1);
        uVar7 = FUN_000020e6(param_1 + 4);
        uVar2 = (uint)uVar7;
        custom0.rs1.rs2(uVar7,0);
        uVar7 = 0xfffffffffffffff8;
        if ((uVar6 <= uVar9) && (-1 < (int)uVar2)) {
          uVar5 = FUN_000020e6(param_1 + 0x10);
          uVar3 = (uint)uVar6;
          uVar7 = 0xfffffffffffffff8;
          if ((uVar3 <= uVar5) && (uVar5 <= uVar2)) {
            uVar5 = FUN_000020e6(param_1 + 8);
            if (uVar10 < 0x11) {
              if (uVar5 < uVar3) {
                return 0xfffffffffffffff8;
              }
            }
            else {
              iVar4 = FUN_000020e6(param_1 + 0x24);
              if (uVar5 < uVar3) {
                return 0xfffffffffffffff8;
              }
              if (uVar2 < uVar5) {
                return 0xfffffffffffffff8;
              }
              bVar1 = iVar4 + uVar5 < uVar5;
              uVar5 = iVar4 + uVar5;
              if (bVar1) {
                return 0xfffffffffffffff8;
              }
            }
            uVar7 = 0xfffffffffffffff8;
            if (uVar5 <= uVar2) {
              uVar5 = FUN_000020e6(param_1 + 0xc);
              iVar4 = FUN_000020e6(param_1 + 0x20);
              uVar8 = 0xfffffffffffffff8;
              uVar7 = 0xfffffffffffffff8;
              if ((((uVar3 <= uVar5) && (uVar7 = uVar8, uVar5 <= uVar2)) && (uVar5 <= iVar4 + uVar5)
                  ) && (iVar4 + uVar5 <= uVar2)) {
                uVar7 = 0;
              }
            }
          }
        }
      }
    }
  }
  return uVar7;
}



// ==================== FUN_000022d0 @ 000022d0 ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_000022d0(long param_1,long param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (uint)param_2;
  iVar2 = FUN_000020e6(param_1 + 8);
  uVar4 = iVar2 + uVar1;
  if (((((-1 < param_2) && (uVar1 <= uVar4)) && (uVar4 <= uVar4 + param_3)) &&
      (uVar3 = FUN_000020e6(param_1 + 4), uVar4 + param_3 <= uVar3)) &&
     ((uVar4 = FUN_000020e6(param_1 + 0x14), uVar4 < 0x11 ||
      ((uVar1 <= uVar1 + param_3 && (uVar4 = FUN_000020e6(param_1 + 0x24), uVar1 + param_3 <= uVar4)
       ))))) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  return 0;
}



// ==================== FUN_00002364 @ 00002364 ====================

undefined8 FUN_00002364(undefined4 *param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 unaff_s0;
  uint *puVar2;
  code *pcVar3;
  
  *param_1 = 0xfffffff8;
  puVar2 = (uint *)FUN_000022d0(4);
  if (puVar2 != (uint *)0x0) {
    uVar1 = *puVar2;
    custom0.rs1.rs2((long)(int)uVar1,unaff_s0);
    custom0.rs1.rs2((long)(int)uVar1,param_2);
    *param_1 = 0xfffffff5;
    if ((uVar1 << 0x18 | uVar1 >> 0x18 | (uVar1 >> 0x18) << 0x10 | (uVar1 & 0xff) << 8) - 1 < 9) {
      pcVar3 = (code *)custom0.rd();
                    /* WARNING: Does not return */
      (*pcVar3)();
    }
  }
  return 9;
}



// ==================== FUN_00002496 @ 00002496 ====================

long FUN_00002496(ulong param_1)

{
  int iVar1;
  long lVar2;
  uint auStack_14 [3];
  
  auStack_14[0] = (uint)param_1;
  if ((((long)param_1 < 0) || ((param_1 & 3) != 0)) ||
     (iVar1 = FUN_00002364(auStack_14), iVar1 != 1)) {
    lVar2 = -4;
  }
  else {
    lVar2 = (long)(int)auStack_14[0];
  }
  return lVar2;
}



// ==================== FUN_000024c0 @ 000024c0 ====================

long FUN_000024c0(ulong param_1)

{
  int iVar1;
  long lVar2;
  uint auStack_14 [3];
  
  auStack_14[0] = (uint)param_1;
  if ((((long)param_1 < 0) || ((param_1 & 3) != 0)) ||
     (iVar1 = FUN_00002364(auStack_14), iVar1 != 3)) {
    lVar2 = -4;
  }
  else {
    lVar2 = (long)(int)auStack_14[0];
  }
  return lVar2;
}



// ==================== FUN_000024ea @ 000024ea ====================

long FUN_000024ea(undefined8 param_1,long param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  int aiStack_44 [3];
  
  aiStack_44[0] = 0;
  if (-1 < param_2) {
    lVar1 = FUN_00002496();
    aiStack_44[0] = (int)lVar1;
    if (lVar1 < 0) {
      return lVar1;
    }
  }
  while( true ) {
    while( true ) {
      lVar1 = (long)aiStack_44[0];
      iVar2 = FUN_00002364(param_1,lVar1,aiStack_44);
      if (iVar2 != 2) break;
      if ((param_3 != (int *)0x0) && (iVar2 = *param_3, *param_3 = iVar2 + -1, iVar2 + -1 < 0)) {
        return (long)aiStack_44[0];
      }
    }
    if (iVar2 == 9) break;
    if (iVar2 == 1) {
      if (param_3 == (int *)0x0) {
        return lVar1;
      }
      *param_3 = *param_3 + 1;
      return lVar1;
    }
  }
  lVar1 = (long)aiStack_44[0];
  if (lVar1 < 0) {
    if (lVar1 != -8) {
      return lVar1;
    }
    if (param_3 != (int *)0x0) {
      return -8;
    }
  }
  return -1;
}



// ==================== FUN_00002572 @ 00002572 ====================

long FUN_00002572(void)

{
  long lVar1;
  int aiStack_14 [3];
  
  aiStack_14[0] = 0;
  lVar1 = FUN_000024ea(aiStack_14);
  if ((lVar1 < 0) || (aiStack_14[0] != 1)) {
    lVar1 = -1;
  }
  return lVar1;
}



// ==================== FUN_00002592 @ 00002592 ====================

long FUN_00002592(undefined8 param_1,long param_2)

{
  int aiStack_24 [3];
  
  aiStack_24[0] = 1;
  while ((param_2 = FUN_000024ea(param_1,param_2,aiStack_24), -1 < param_2 && (0 < aiStack_24[0])))
  {
    if (aiStack_24[0] == 1) {
      return param_2;
    }
  }
  return -1;
}



// ==================== FUN_000025ca @ 000025ca ====================

ulong FUN_000025ca(ulong param_1,long param_2,undefined8 param_3)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = FUN_0000600c(param_3);
  uVar1 = (param_2 - (iVar2 + 1)) + param_1;
  while( true ) {
    if (uVar1 < param_1) {
      return 0;
    }
    lVar3 = FUN_00005fd4(param_1,param_3,(long)(iVar2 + 1));
    if (lVar3 == 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



// ==================== FUN_00002612 @ 00002612 ====================

ulong FUN_00002612(undefined8 param_1)

{
  uint uVar1;
  undefined8 unaff_s0;
  uint *puVar2;
  ulong uVar3;
  ulong uVar4;
  int aiStack_14 [3];
  
  puVar2 = (uint *)FUN_00002b0c(aiStack_14);
  if (puVar2 == (uint *)0x0) {
    uVar3 = (long)aiStack_14[0];
  }
  else {
    uVar3 = 0xfffffffffffffff2;
    if (aiStack_14[0] == 4) {
      uVar1 = *puVar2;
      custom0.rs1.rs2((long)(int)uVar1,unaff_s0);
      custom0.rs1.rs2((long)(int)uVar1,param_1);
      uVar4 = (ulong)(int)(uVar1 << 0x18 | uVar1 >> 0x18 | (uVar1 >> 0x18) << 0x10 |
                          (uVar1 & 0xff) << 8);
      uVar3 = 0xfffffffffffffff2;
      if (uVar4 < 5) {
        uVar3 = uVar4;
      }
    }
  }
  return uVar3;
}



// ==================== FUN_00002664 @ 00002664 ====================

long FUN_00002664(void)

{
  long lVar1;
  
  lVar1 = FUN_00002612(0x1c00bfc8);
  if (lVar1 == 0) {
    lVar1 = -0xe;
  }
  else if (lVar1 == -1) {
    lVar1 = 2;
  }
  return lVar1;
}



// ==================== FUN_00002688 @ 00002688 ====================

long FUN_00002688(void)

{
  long lVar1;
  
  lVar1 = FUN_00002612(0x1c00bfd8);
  if (lVar1 == -1) {
    lVar1 = 1;
  }
  return lVar1;
}



// ==================== FUN_000026a6 @ 000026a6 ====================

long FUN_000026a6(int *param_1)

{
  custom0();
  return (long)*param_1;
}



// ==================== FUN_000026ae @ 000026ae ====================

long FUN_000026ae(undefined8 param_1,long param_2)

{
  int iVar1;
  int aiStack_34 [3];
  
  while( true ) {
    iVar1 = FUN_00002364(param_1,aiStack_34);
    if (iVar1 == 3) {
      return param_2;
    }
    param_2 = (long)aiStack_34[0];
    if (iVar1 == 9) break;
    if (iVar1 != 4) {
      return -1;
    }
  }
  if (param_2 < 0) {
    return param_2;
  }
  return -0xb;
}



// ==================== FUN_000026f8 @ 000026f8 ====================

void FUN_000026f8(void)

{
  custom0();
  return;
}



// ==================== FUN_000026fe @ 000026fe ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_000026fe(long param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = FUN_000024c0();
  if (lVar1 < 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = (int)lVar1;
    }
    return 0;
  }
  FUN_000026a6(param_1 + 8);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00002742 @ 00002742 ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_00002742(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  
  lVar3 = FUN_000020ee();
  if (-1 < lVar3) {
    iVar1 = FUN_000026a6(param_1 + 0xc);
    uVar4 = (uint)param_2;
    if (iVar1 + uVar4 < (uint)lVar3) {
      uVar5 = (ulong)(int)((uint)lVar3 - (iVar1 + uVar4));
      iVar1 = FUN_000026a6(param_1);
      custom0.rs1.rs2(uVar5,0);
      if (iVar1 == -0x2ff20113) {
        if (-1 < param_2) {
          uVar2 = FUN_000026a6(param_1 + 0x14);
          if (uVar2 < 0x11) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
            halt_unimplemented();
          }
          uVar2 = FUN_000026a6(param_1 + 0x20);
          if (uVar4 < uVar2) {
            if (uVar5 <= (ulong)(long)(int)(uVar2 - uVar4)) {
              halt_unimplemented();
            }
            custom0.rs1.rs2((long)(int)(uVar2 - uVar4),0);
            halt_unimplemented();
          }
        }
      }
      else {
        if (iVar1 != 0x2ff20112) {
          lVar3 = -0xd;
          goto LAB_00002824;
        }
        if (param_2 < 0) {
          iVar1 = FUN_000026a6(param_1 + 0x20);
          uVar6 = (ulong)(int)-uVar4;
          if (uVar6 <= (ulong)(long)iVar1) {
            if (uVar5 <= uVar6) {
              halt_unimplemented();
            }
            custom0.rs1.rs2(uVar6,0);
            halt_unimplemented();
          }
        }
      }
    }
    lVar3 = -4;
  }
LAB_00002824:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = (int)lVar3;
  }
  return 0;
}



// ==================== FUN_00002838 @ 00002838 ====================

/* WARNING: Control flow encountered unimplemented instructions */

undefined8 FUN_00002838(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  
  FUN_000026a6(param_1 + 8);
  lVar1 = FUN_000020ee(param_1);
  if ((-1 < lVar1) && (lVar1 = FUN_00002496(param_1,param_2), -1 < lVar1)) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = (int)lVar1;
  }
  return 0;
}



// ==================== FUN_000028ba @ 000028ba ====================

long FUN_000028ba(undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iStack_48;
  int aiStack_44 [3];
  
  lVar1 = FUN_000020ee();
  if (-1 < lVar1) {
    iStack_48 = 0;
    for (; -1 < param_2; param_2 = FUN_000024ea(param_1,param_2,&iStack_48)) {
      if (iStack_48 < 0) goto LAB_000028ee;
      if ((((iStack_48 == 1) && (lVar1 = FUN_00002838(param_1,param_2,aiStack_44), lVar1 != 0)) &&
          (param_4 <= aiStack_44[0])) && (lVar1 = FUN_00005fd4(param_3,param_4), lVar1 == 0)) {
        lVar1 = custom0.rd();
        if (lVar1 == 0) {
          return param_2;
        }
        lVar2 = FUN_00005ff0(param_3,0x40,param_4);
        if ((lVar2 == 0) && (lVar1 == 0x40)) {
          return param_2;
        }
      }
    }
    lVar1 = param_2;
    if (iStack_48 < 0) {
LAB_000028ee:
      lVar1 = -1;
    }
  }
  return lVar1;
}



// ==================== FUN_00002958 @ 00002958 ====================

void FUN_00002958(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  custom0();
  iVar1 = FUN_0000600c(param_2);
  uVar2 = custom0.rd();
  FUN_000028ba(param_1,uVar2,(long)iVar1);
  return;
}



// ==================== FUN_0000297c @ 0000297c ====================

void FUN_0000297c(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_00002496();
  if (-1 < lVar1) {
    FUN_000026ae(param_1,lVar1);
    return;
  }
  return;
}



// ==================== FUN_000029a0 @ 000029a0 ====================

void FUN_000029a0(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_000024c0();
  if (-1 < lVar1) {
    FUN_000026ae(param_1,lVar1);
    return;
  }
  return;
}



// ==================== FUN_000029c4 @ 000029c4 ====================

long FUN_000029c4(undefined8 param_1,undefined8 param_2,long param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iStack_44;
  
  lVar2 = FUN_0000297c();
  do {
    if (lVar2 < 0) {
LAB_000029ea:
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = (int)lVar2;
      }
      return 0;
    }
    lVar3 = FUN_000026fe(param_1,lVar2,param_4);
    if (lVar3 == 0) {
      lVar2 = -0xd;
      goto LAB_000029ea;
    }
    iVar1 = FUN_000026f8((long)*(int *)(lVar3 + 8));
    lVar4 = FUN_00002742(param_1,(long)iVar1,&iStack_44);
    if (((lVar4 != 0) && (iStack_44 == param_3)) &&
       (lVar4 = FUN_00005fd4(param_2,param_3), lVar4 == 0)) {
      if (param_5 == (undefined4 *)0x0) {
        return lVar3;
      }
      *param_5 = (int)lVar2;
      return lVar3;
    }
    lVar2 = FUN_000029a0(param_1,lVar2);
  } while( true );
}



// ==================== FUN_00002a56 @ 00002a56 ====================

undefined8 FUN_00002a56(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  custom0();
  custom0();
  uVar1 = FUN_000026a6(param_1 + 0x14);
  puVar3 = (undefined4 *)custom0.rd();
  uVar2 = custom0.rd();
  if (uVar1 < 0x10) {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0xfffffff6;
    }
    return 0;
  }
  uVar2 = FUN_000029c4(param_1,uVar2,0);
  return uVar2;
}



// ==================== FUN_00002a98 @ 00002a98 ====================

void FUN_00002a98(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0000600c(param_3);
  FUN_00002a56(param_1,param_2,param_3,(long)iVar1,param_4);
  return;
}



// ==================== FUN_00002ac0 @ 00002ac0 ====================

long FUN_00002ac0(long param_1)

{
  uint uVar1;
  long lVar2;
  int aiStack_24 [3];
  
  lVar2 = FUN_000029c4(aiStack_24);
  if (lVar2 != 0) {
    uVar1 = FUN_000026a6(param_1 + 0x14);
    if (((uVar1 < 0x10) && (((long)aiStack_24[0] + 0xcU & 7) != 0)) &&
       (uVar1 = FUN_000026f8((long)*(int *)(lVar2 + 4)), 7 < uVar1)) {
      lVar2 = lVar2 + 0x10;
    }
    else {
      lVar2 = lVar2 + 0xc;
    }
  }
  return lVar2;
}



// ==================== FUN_00002b0c @ 00002b0c ====================

void FUN_00002b0c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0000600c(param_3);
  FUN_00002ac0(param_1,param_2,param_3,(long)iVar1,param_4);
  return;
}



// ==================== FUN_00002b34 @ 00002b34 ====================

char * FUN_00002b34(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char *pcVar2;
  int aiStack_24 [3];
  
  lVar1 = FUN_00002c46(0x1c00bfe8);
  if ((((lVar1 < 0) ||
       (pcVar2 = (char *)FUN_00002ac0(param_1,lVar1,param_2,param_3,aiStack_24),
       pcVar2 == (char *)0x0)) || ((long)aiStack_24[0] < 1)) ||
     ((pcVar2[(long)aiStack_24[0] + -1] != '\0' || (*pcVar2 != '/')))) {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}



// ==================== FUN_00002b88 @ 00002b88 ====================

long FUN_00002b88(undefined8 param_1,char *param_2,long param_3)

{
  long lVar1;
  char *pcVar2;
  char *pcVar3;
  
  lVar1 = FUN_000020ee();
  if (lVar1 < 0) {
    return lVar1;
  }
  if (param_3 < 1) {
LAB_00002bae:
    lVar1 = -5;
  }
  else {
    pcVar3 = param_2 + param_3;
    if (*param_2 == '/') {
      lVar1 = 0;
    }
    else {
      pcVar2 = (char *)FUN_00005ff0(param_2,0x2f);
      custom0();
      lVar1 = FUN_00002b34(param_1,param_2,(long)((int)pcVar2 - (int)param_2));
      if (lVar1 == 0) goto LAB_00002bae;
      lVar1 = FUN_00002c46(param_1,lVar1);
      param_2 = pcVar2;
    }
    while (param_2 < pcVar3) {
      while (*param_2 == '/') {
        param_2 = param_2 + 1;
        if (pcVar3 == param_2) {
          return lVar1;
        }
      }
      pcVar2 = (char *)FUN_00005ff0(param_2,0x2f,(long)pcVar3 - (long)param_2);
      custom0();
      lVar1 = FUN_000028ba(param_1,lVar1,param_2,(long)((int)pcVar2 - (int)param_2));
      param_2 = pcVar2;
      if (lVar1 < 0) {
        return lVar1;
      }
    }
  }
  return lVar1;
}



// ==================== FUN_00002c46 @ 00002c46 ====================

void FUN_00002c46(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0000600c(param_2);
  FUN_00002b88(param_1,param_2,(long)iVar1);
  return;
}



// ==================== FUN_00002c66 @ 00002c66 ====================

void FUN_00002c66(void)

{
  custom0();
  return;
}



// ==================== FUN_00002c6c @ 00002c6c ====================

long FUN_00002c6c(int *param_1)

{
  custom0();
  return (long)*param_1;
}



// ==================== FUN_00002c74 @ 00002c74 ====================

bool FUN_00002c74(long param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = FUN_00002c6c(param_1 + 0x10);
  if (uVar2 < 0x28) {
    bVar1 = true;
  }
  else {
    uVar3 = FUN_00002c6c(param_1 + 8);
    bVar1 = true;
    if ((param_2 + uVar2 <= uVar3) &&
       (uVar2 = FUN_00002c6c(param_1 + 0xc), param_3 + uVar3 <= uVar2)) {
      uVar3 = FUN_00002c6c(param_1 + 4);
      iVar4 = FUN_00002c6c(param_1 + 0x20);
      bVar1 = uVar3 < iVar4 + uVar2;
    }
  }
  return bVar1;
}



// ==================== FUN_00002cf6 @ 00002cf6 ====================

undefined8 FUN_00002cf6(ulong param_1,ulong param_2,ulong param_3,long param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong unaff_s5;
  
  iVar1 = FUN_00002c6c(param_1 + 0xc);
  iVar2 = FUN_00002c6c(param_1 + 0x20);
  iVar2 = iVar2 + iVar1;
  uVar4 = 0xfffffffffffffffc;
  if (-1 < (long)param_3) {
    uVar5 = param_3 + (param_2 - param_1);
    uVar4 = 0xfffffffffffffffc;
    if (((param_2 - param_1 <= uVar5) && (custom0.rs1.rs2((long)iVar2,0), uVar5 <= unaff_s5)) &&
       (param_1 <= param_2)) {
      if (param_3 <= (ulong)(long)(iVar2 + (int)param_4)) {
        uVar3 = FUN_00002c6c(param_1 + 4);
        uVar4 = 0xfffffffffffffffd;
        if ((uint)(((int)param_4 - (int)param_3) + iVar2) <= uVar3) {
          FUN_00005f98(param_2 + param_4,(param_1 + unaff_s5) - (param_2 + param_3));
          uVar4 = 0;
        }
      }
    }
  }
  return uVar4;
}



// ==================== FUN_00002d92 @ 00002d92 ====================

long FUN_00002d92(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = FUN_000020ee();
  if (-1 < lVar3) {
    uVar1 = FUN_00002c6c(param_1 + 0x14);
    lVar3 = -10;
    if (0x10 < uVar1) {
      iVar2 = FUN_00002c6c(param_1 + 0x24);
      lVar3 = FUN_00002c74(param_1,0x10,(long)iVar2);
      if (lVar3 == 0) {
        lVar3 = 0;
        if (uVar1 != 0x11) {
          *(undefined4 *)(param_1 + 0x14) = 0x11000000;
        }
      }
      else {
        lVar3 = -0xc;
      }
    }
  }
  return lVar3;
}



// ==================== FUN_00002de8 @ 00002de8 ====================

long FUN_00002de8(long param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = FUN_00002cf6();
  if (lVar3 == 0) {
    iVar1 = FUN_00002c6c(param_1 + 0x24);
    uVar2 = FUN_00002c66((long)(iVar1 + (param_3 - param_2)));
    *(undefined4 *)(param_1 + 0x24) = uVar2;
    iVar1 = FUN_00002c6c(param_1 + 0xc);
    uVar2 = FUN_00002c66((long)(iVar1 + (param_3 - param_2)));
    *(undefined4 *)(param_1 + 0xc) = uVar2;
  }
  return lVar3;
}



// ==================== FUN_00002e36 @ 00002e36 ====================

/* WARNING: Control flow encountered unimplemented instructions */

long FUN_00002e36(long param_1)

{
  long lVar1;
  
  lVar1 = FUN_00002496();
  if (-1 < lVar1) {
    FUN_00002c6c(param_1 + 0xc);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  return lVar1;
}



// ==================== FUN_00002f74 @ 00002f74 ====================

long FUN_00002f74(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 long *param_5)

{
  undefined4 uVar1;
  long lVar2;
  int iStack_4c;
  long alStack_48 [2];
  
  lVar2 = FUN_00002d92();
  if (lVar2 != 0) {
    return lVar2;
  }
  alStack_48[0] = FUN_00002a98(param_1,param_2,param_3,&iStack_4c);
  if (alStack_48[0] == 0) {
    lVar2 = (long)iStack_4c;
    if (lVar2 == -1) goto LAB_00002ffc;
  }
  else {
    lVar2 = FUN_00002de8(param_1,alStack_48[0] + 0xc,(long)(int)(iStack_4c + 3U & 0xfffffffc),
                         (long)(int)((int)param_4 + 3U & 0xfffffffc));
    if (lVar2 == 0) {
      uVar1 = FUN_00002c66((long)(int)param_4);
      *(undefined4 *)(alStack_48[0] + 4) = uVar1;
      goto LAB_00002fea;
    }
    if (lVar2 != -1) {
      return lVar2;
    }
LAB_00002ffc:
    lVar2 = FUN_00002e36(param_1,param_2,param_3,param_4,alStack_48);
  }
  if (lVar2 != 0) {
    return lVar2;
  }
LAB_00002fea:
  *param_5 = alStack_48[0] + 0xc;
  return 0;
}



// ==================== FUN_0000300c @ 0000300c ====================

long FUN_0000300c(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uStack_28;
  
  lVar1 = FUN_00002f74(param_2,&uStack_28);
  if ((lVar1 == 0) && (param_2 != 0)) {
    FUN_00005f4e(uStack_28,param_1,param_2);
  }
  return lVar1;
}



// ==================== FUN_00003040 @ 00003040 ====================

/* WARNING: Control flow encountered unimplemented instructions */

long FUN_00003040(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int iStack_44;
  
  lVar2 = FUN_00002d92();
  if (lVar2 == 0) {
    lVar2 = FUN_000028ba(param_1,param_2,param_3,param_4);
    if (lVar2 < 0) {
      if (lVar2 == -1) {
        iVar1 = FUN_00002364(param_1,param_2,&iStack_44);
        lVar2 = -0xd;
        if (iVar1 == 1) {
          do {
            iVar1 = FUN_00002364(param_1,(long)iStack_44,&iStack_44);
          } while (iVar1 - 3U < 2);
          FUN_00002c6c(param_1 + 8);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
          halt_unimplemented();
        }
      }
    }
    else {
      lVar2 = -2;
    }
  }
  return lVar2;
}



// ==================== FUN_0000310c @ 0000310c ====================

void FUN_0000310c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  custom0();
  iVar1 = FUN_0000600c(param_2);
  uVar2 = custom0.rd();
  FUN_00003040(param_1,uVar2,(long)iVar1);
  return;
}



// ==================== FUN_00003130 @ 00003130 ====================

long FUN_00003130(long param_1)

{
  long lVar1;
  
  if (0 < param_1) {
    return 0x1c00c018;
  }
  if (param_1 != 0) {
    if ((param_1 < -0x13) || (lVar1 = custom0.rd(), lVar1 == 0)) {
      lVar1 = 0x1c00bff8;
    }
    return lVar1;
  }
  return 0x1c00c008;
}



// ==================== FUN_0000316c @ 0000316c ====================

undefined8 FUN_0000316c(long param_1,ulong *param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  undefined1 auStack_30 [12];
  int aiStack_24 [3];
  
  lVar2 = param_1;
  lVar1 = FUN_00002b0c(aiStack_24);
  if (lVar1 != 0) {
    lVar1 = 0;
    uVar4 = 0;
    custom0.rs1.rs2((long)aiStack_24[0],auStack_30);
    for (; lVar1 != lVar2; lVar1 = lVar1 + 1) {
      uVar3 = custom0.rd();
      custom0();
      custom0.rs1.rs2(uVar3,0);
      uVar4 = uVar4 << 0x20 | uVar3;
    }
    if ((ulong)(long)aiStack_24[0] < 9) {
      *param_2 = uVar4;
      return 0;
    }
    custom0.rs1.rs2(uVar4,0);
    FUN_00005b24(0x1c00c280,param_1);
  }
  return 0xffffffffffffffff;
}



// ==================== FUN_000031ce @ 000031ce ====================

void FUN_000031ce(undefined8 param_1)

{
  FUN_0000316c(0x1c00c2a0,param_1);
  return;
}



// ==================== FUN_000031da @ 000031da ====================

void FUN_000031da(undefined8 param_1)

{
  FUN_0000316c(0x1c00c2a8,param_1);
  return;
}



// ==================== FUN_000031e6 @ 000031e6 ====================

ulong FUN_000031e6(long *param_1)

{
  long lVar1;
  undefined1 auStack_14 [4];
  
  lVar1 = FUN_00002b0c(0x1c00c2b0,auStack_14);
  *param_1 = lVar1;
  custom0.rs1((ulong)(lVar1 == 0));
  return (ulong)(lVar1 == 0);
}



// ==================== FUN_0000320e @ 0000320e ====================

undefined8 FUN_0000320e(long *param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 auStack_24 [3];
  
  lVar1 = FUN_00002b0c(0x1c00c2b8,auStack_24);
  *param_1 = lVar1;
  if (lVar1 == 0) {
    auStack_24[0] = 0;
    uVar2 = 0xffffffffffffffff;
  }
  else {
    uVar2 = 0;
  }
  *param_2 = auStack_24[0];
  return uVar2;
}



// ==================== FUN_00003242 @ 00003242 ====================

long FUN_00003242(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iStack_a4;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined1 auStack_90 [32];
  undefined1 auStack_70 [40];
  
  lVar2 = FUN_00002572();
  lVar1 = -2;
  do {
    if (lVar2 < 0) {
      return lVar1;
    }
    FUN_00002838(param_1,lVar2,0);
    lVar3 = FUN_0000603a(0x1c00c2c0,4);
    if ((lVar3 == 0) && (lVar3 = FUN_000031e6(param_1,lVar2,&uStack_a0), lVar3 == 0)) {
      lVar3 = FUN_0000601e(uStack_a0,0x1c00c2c8);
      if (lVar3 == 0) {
        lVar3 = FUN_0000320e(param_1,lVar2,&uStack_98,&iStack_a4);
        if (lVar3 == 0) {
          if (iStack_a4 != 0x20) {
            return -0x16;
          }
          FUN_00005f4e(auStack_90,uStack_98,0x20);
          lVar1 = FUN_00006244(param_2,param_3,auStack_70);
          if (lVar1 != 0) {
            return lVar1;
          }
          lVar1 = FUN_00005fd4(auStack_70,auStack_90,0x20);
          if (lVar1 != 0) {
            FUN_00005b8a(0x1c00c2e8);
            return -0x16;
          }
        }
      }
      else {
        FUN_00005b8a(0x1c00c2d0);
      }
    }
    lVar2 = FUN_00002592(param_1,lVar2);
  } while( true );
}



// ==================== FUN_00003320 @ 00003320 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003320(code *UNRECOVERED_JUMPTABLE,undefined8 param_2)

{
  _DAT_1c00e0b8 = 0x4942534f;
  _DAT_1c00e0e0 = 0;
  _DAT_1c00e0c0 = 2;
  _DAT_1c00e0d0 = 1;
  _DAT_1c00e0d8 = 0;
  _DAT_1c00e0c8 = param_2;
                    /* WARNING: Could not recover jumptable at 0x0000334c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,&DAT_1c00e0b8,UNRECOVERED_JUMPTABLE);
  return;
}



// ==================== FUN_0000334e @ 0000334e ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_0000334e(void)

{
  long lVar1;
  
  lVar1 = FUN_0000136e(&DAT_21a00000);
  if ((lVar1 == 0) && (custom0(), _DAT_21a00000 != -0x2ff20113)) {
    lVar1 = -0x16;
  }
  return lVar1;
}



// ==================== FUN_0000337a @ 0000337a ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_0000337a(void)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  long lVar10;
  int iStack_80;
  int iStack_7c;
  code *apcStack_78 [2];
  
  custom0();
  if (_DAT_21a00000 != -0x2ff20113) {
    return -0x16;
  }
  lVar2 = FUN_00002c46(&DAT_21a00000,0x1c00c300);
  if (lVar2 < 0) {
    FUN_00005b24(0x1c00c308);
  }
  lVar2 = FUN_00002572(&DAT_21a00000,lVar2);
  pcVar7 = (code *)0x0;
  pcVar1 = (code *)0x0;
  pcVar8 = (code *)0x0;
  do {
    if (lVar2 < 0) {
      if (pcVar7 != (code *)0x0) {
        uVar3 = FUN_00004aee();
        FUN_000037c4(pcVar7,0x20000000,uVar3);
      }
      if (pcVar1 == (code *)0x0) {
        if (pcVar8 != (code *)0x0) {
          FUN_00005b24(0x1c00c458,pcVar8);
          (*pcVar8)(0,pcVar7);
        }
      }
      else {
        FUN_00003320(pcVar1,pcVar7,pcVar8);
      }
      return -1;
    }
    lVar4 = FUN_00002b0c(&DAT_21a00000,lVar2,0x1c00c328,&iStack_80);
    if (lVar4 == 0) {
      FUN_00005b24(0x1c00c330,(long)iStack_80);
      return (long)iStack_80;
    }
    lVar5 = FUN_0000601e(0x1c00c350);
    if (lVar5 == 0) {
      lVar5 = FUN_00004aee();
      pcVar7 = (code *)(lVar5 + 0x1ff00000);
      pcVar9 = pcVar7;
LAB_00003480:
      lVar5 = FUN_00002b0c(&DAT_21a00000,lVar2,0x1c00c3d8,&iStack_7c);
      lVar10 = (long)iStack_7c;
      if ((lVar5 == 0) && (lVar10 != 0)) {
        lVar4 = 0x3e0;
LAB_00003524:
        FUN_00005b8a(lVar4 + 0x1c00c000);
      }
      else {
        lVar6 = FUN_00003242(&DAT_21a00000,lVar2,lVar5,lVar10);
        if (((int)lVar6 + 2U & 0xfffffffd) != 0) {
          return lVar6;
        }
        lVar6 = FUN_00002b0c(&DAT_21a00000,lVar2,0x1c00c408,&iStack_80);
        if ((lVar6 != 0) && (lVar6 = FUN_0000601e(0x1c00c418), lVar6 == 0)) {
          FUN_00005b8a(0x1c00c420);
          return -0x5f;
        }
        FUN_00005b24(0x1c00c438,lVar4,pcVar9);
        FUN_00005f4e(pcVar9,lVar5,lVar10);
      }
    }
    else {
      lVar5 = FUN_0000601e(lVar4,0x1c00c358);
      if (lVar5 == 0) {
        if (pcVar8 == (code *)0x0) {
          lVar5 = FUN_000031ce(&DAT_21a00000,lVar2,apcStack_78);
          pcVar9 = apcStack_78[0];
          if (lVar5 != 0) {
            FUN_00005b8a(0x1c00c368);
            return -1;
          }
          lVar5 = FUN_000031da(&DAT_21a00000,lVar2,apcStack_78);
          pcVar8 = pcVar9;
          if (lVar5 == 0) {
            pcVar8 = apcStack_78[0];
          }
          goto LAB_00003480;
        }
      }
      else {
        lVar5 = FUN_0000601e(lVar4,0x1c00c3a0);
        if (lVar5 != 0) {
          lVar4 = 0x3b0;
          goto LAB_00003524;
        }
        if (pcVar1 == (code *)0x0) {
          lVar5 = FUN_000031ce(&DAT_21a00000,lVar2,apcStack_78);
          pcVar1 = apcStack_78[0];
          pcVar9 = apcStack_78[0];
          if (lVar5 != 0) {
            lVar5 = FUN_00004aee();
            pcVar1 = (code *)(lVar5 + 0x1fe00000);
            pcVar9 = (code *)(lVar5 + 0x1fe00000);
          }
          goto LAB_00003480;
        }
      }
    }
    lVar2 = FUN_00002592(&DAT_21a00000,lVar2);
  } while( true );
}



// ==================== FUN_000035c0 @ 000035c0 ====================

void FUN_000035c0(undefined8 param_1,undefined8 *param_2)

{
  custom0();
  *param_2 = param_1;
  return;
}



// ==================== FUN_000035c8 @ 000035c8 ====================

long FUN_000035c8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00002958();
  if (lVar1 == -1) {
    lVar1 = FUN_0000310c(param_1,param_2,param_3);
  }
  if (lVar1 < 0) {
    uVar2 = FUN_00003130();
    FUN_00005b24(0x1c00c478,0x1c00c540,param_3,uVar2);
  }
  return lVar1;
}



// ==================== FUN_0000361c @ 0000361c ====================

long FUN_0000361c(undefined8 param_1,long *param_2,long *param_3,long param_4,undefined8 param_5)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  uint local_50 [4];
  
  if (param_4 < 2) {
    lVar2 = FUN_000021bc();
    if (lVar2 < 0) {
      uVar3 = FUN_00003130();
      uVar6 = 0x1c00c528;
      uVar4 = 0x1c00c4e0;
LAB_0000368c:
      FUN_00005b24(uVar4,uVar6,uVar3);
    }
    else {
      lVar5 = FUN_000035c8(param_1,0,0x1c00c4e8);
      lVar2 = lVar5;
      if (-1 < lVar5) {
        lVar8 = 7;
        lVar2 = FUN_0000300c(param_1,lVar5,0x1c00c4f0,0x1c00c4e8,7);
        lVar9 = 0;
        if (lVar2 < 0) {
          uVar3 = FUN_00003130();
          FUN_00005b24(0x1c00c500,0x1c00c4f0,uVar3);
        }
        else {
          do {
            uVar7 = (uint)lVar8;
            if (param_4 <= lVar9) {
              if (lVar9 != 0) {
                lVar2 = FUN_00002664(param_1,0);
                lVar8 = FUN_00002688(param_1,0);
                lVar9 = *param_2;
                if (lVar2 == 2) {
                  FUN_000035c0(local_50);
                }
                else {
                  uVar1 = (uint)lVar9;
                  custom0.rs1.rs2(lVar9,lVar5);
                  custom0.rs1.rs2(lVar9,param_5);
                  uVar7 = (uVar1 >> 0x18) << 0x10;
                  local_50[0] = (uVar1 & 0xff) << 8 | uVar1 << 0x18 | uVar1 >> 0x18 | uVar7;
                }
                lVar9 = *param_3;
                if (lVar8 == 2) {
                  FUN_000035c0((long)local_50 + (long)((int)lVar2 << 2));
                }
                else {
                  custom0.rs1.rs2(lVar9,lVar5);
                  uVar7 = (uint)lVar9 >> 0x18;
                  custom0.rs1.rs2(lVar9,param_5);
                  custom0();
                }
                custom0.rs1(lVar8);
                custom0();
                lVar2 = FUN_0000300c(param_1,lVar5,0x1c00c520,local_50,
                                     (long)(int)(uVar7 - (int)local_50));
                if (lVar2 < 0) {
                  uVar3 = FUN_00003130();
                  uVar6 = 0x1c00c520;
                  uVar4 = 0x1c00c500;
                  goto LAB_0000368c;
                }
              }
              break;
            }
            lVar8 = *param_2;
            lVar9 = 1;
          } while ((lVar8 != 0) || (lVar8 = *param_3, lVar8 != 0));
          lVar2 = 0;
        }
      }
    }
  }
  else {
    FUN_00005b24(0x1c00c488,0x1c00c528,param_4,1);
    lVar2 = -1;
  }
  return lVar2;
}



// ==================== FUN_000037c4 @ 000037c4 ====================

void FUN_000037c4(void)

{
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [16];
  
  custom0();
  FUN_0000361c(auStack_18,auStack_20,1);
  return;
}



// ==================== FUN_000037dc @ 000037dc ====================

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_000037dc(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00003816 @ 00003816 ====================

void FUN_00003816(void)

{
  return;
}



// ==================== FUN_0000381c @ 0000381c ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0000381c(void)

{
  int iVar1;
  
  iVar1 = -1;
  do {
    if ((_DAT_0c600010 & 1) != 0) {
      return 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00005b8a(0x1c00c558);
  return 0xffffffffffffffea;
}



// ==================== FUN_00003848 @ 00003848 ====================

void FUN_00003848(int param_1)

{
  uint *puVar1;
  
  custom0();
  puVar1 = (uint *)(long)((param_1 + 0xc600) * 0x1000 + 8);
  custom0.rs1.rs2(puVar1,0);
  *puVar1 = *puVar1 & 6;
  return;
}



// ==================== FUN_0000386a @ 0000386a ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0000386a(ulong param_1,ulong param_2,long param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  uint *puVar4;
  
  uVar2 = 0xffffffffffffffff;
  if ((param_1 < 2) && (uVar2 = 0xffffffffffffffff, param_2 < 2)) {
    FUN_00003848();
    iVar1 = ((int)param_1 + 0xc600) * 0x1000;
    piVar3 = (int *)(long)iVar1;
    custom0();
    custom0.rs1.rs2((long)(iVar1 + 0xc),0);
    puVar4 = (uint *)(long)(iVar1 + 8);
    custom0.rs1.rs2(puVar4,0);
    *puVar4 = *puVar4 & 5 | (int)param_3 << 1;
    custom0.rs1.rs2(piVar3,0);
    if (param_3 == 1) {
      custom0();
      custom0();
      *piVar3 = param_4 * _DAT_1c00d8d0;
    }
    else {
      *piVar3 = -1;
    }
    uVar2 = 0;
    *puVar4 = *puVar4 & 6 | 1;
  }
  return uVar2;
}



// ==================== FUN_0000391e @ 0000391e ====================

void FUN_0000391e(undefined8 param_1)

{
  FUN_0000386a(0,0,1,0,0,param_1);
  FUN_0000381c();
  return;
}



// ==================== FUN_00003938 @ 00003938 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003938(void)

{
  custom0.rs1.rs2((long)_DAT_0ce0001c,0);
  if ((DAT_0c700000 & 1) != 0) {
    DAT_0c700000 = DAT_0c700000 & 0xfe;
  }
  return;
}



// ==================== FUN_00003962 @ 00003962 ====================

void FUN_00003962(int param_1,int param_2,long param_3,int param_4,long param_5)

{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  
  uVar3 = 0x59682f0 / (uint)(param_2 << 4);
  param_1 = param_1 * 0x1000;
  custom0.rs1.rs2((long)(int)uVar3,0);
  custom0();
  custom0.rs1.rs2((uint *)(long)(param_1 + 0xc300024),0);
  *(uint *)(long)(param_1 + 0xc300024) = uVar3;
  custom0.rs1.rs2((uint *)(long)(param_1 + 0xc300028),0);
  puVar1 = (uint *)(long)(param_1 + 0xc30002c);
  custom0.rs1.rs2(puVar1,0);
  *(uint *)(long)(param_1 + 0xc300028) = 0x65a0bc00U / (uint)(param_2 << 4) & 0x3f;
  uVar3 = *puVar1;
  if (param_3 == 5) {
    uVar3 = uVar3 & 0x9f;
  }
  else if (param_3 == 6) {
    uVar3 = uVar3 & 0xbf | 0x20;
  }
  else if (param_3 == 7) {
    uVar3 = uVar3 & 0xdf | 0x40;
  }
  else {
    if (param_3 != 8) goto LAB_000039c8;
    uVar3 = uVar3 & 0xff | 0x60;
  }
  *puVar1 = uVar3;
LAB_000039c8:
  if (param_4 - 1U < 5) {
    pcVar2 = (code *)custom0.rd();
                    /* WARNING: Does not return */
    (*pcVar2)();
  }
  uVar3 = *puVar1 & 0xff | 8;
  if (param_5 == 1) {
    uVar3 = *puVar1 & 0xf7;
  }
  *puVar1 = uVar3 | 0x10;
  return;
}



// ==================== FUN_00003a54 @ 00003a54 ====================

void FUN_00003a54(int param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(long)(param_1 * 0x1000 + 0xc300030);
  custom0.rs1.rs2(puVar1,0);
  custom0.rs1.rs2((long)(int)*puVar1,0);
  *puVar1 = *puVar1 | 0x301;
  FUN_00003962((long)param_1,&DAT_0001c200,8,5,1);
  return;
}



// ==================== FUN_00003a84 @ 00003a84 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003a84(ulong param_1)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = 0;
  while (uVar4 < param_1) {
    iVar3 = (int)uVar4;
    if ((uint)((int)param_1 - iVar3) < 0x21) {
      do {
        uVar2 = custom0.rd();
        iVar1 = (int)uVar4 + 1;
        uVar4 = (ulong)iVar1;
        _DAT_0c301000 = (undefined4)uVar2;
      } while ((uint)(iVar1 - iVar3) < (uint)((int)param_1 - iVar1));
      do {
      } while ((_DAT_0c301018 & 0x80) == 0);
    }
    else {
      do {
        uVar2 = custom0.rd();
        _DAT_0c301000 = (undefined4)uVar2;
        uVar4 = (ulong)((int)uVar4 + 1);
      } while (uVar4 != (long)(iVar3 + 0x20));
      do {
        uVar4 = (long)(iVar3 + 0x20);
      } while ((_DAT_0c301018 & 0x80) == 0);
    }
  }
  return;
}



// ==================== FUN_00003ad8 @ 00003ad8 ====================

void FUN_00003ad8(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(long)((param_1 + 0x2800000) * 4);
  custom0.rs1.rs2(puVar1,0);
  *puVar1 = param_2;
  return;
}



// ==================== FUN_00003aea @ 00003aea ====================

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_00003aea(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00003c12 @ 00003c12 ====================

ulong FUN_00003c12(ulong param_1,ulong param_2)

{
  if (param_2 < 2) {
    if (param_1 != 0) {
      if ((long)param_1 < 0x1d) {
        return 0x3f;
      }
      if ((long)param_1 < 0x1f) {
        return 0x3e;
      }
      if ((long)param_1 < 0x21) {
        return 0x3b;
      }
      if ((long)param_1 < 0x23) {
        return 0x3a;
      }
      if ((long)param_1 < 0x26) {
        return 0x39;
      }
      if ((long)param_1 < 0x29) {
        return 0x38;
      }
      if ((long)param_1 < 0x2d) {
        return 0x1b;
      }
      if ((long)param_1 < 0x32) {
        return 0x1a;
      }
      if ((long)param_1 < 0x38) {
        return 0x19;
      }
      if ((long)param_1 < 0x40) {
        return 0x18;
      }
      if ((long)param_1 < 0x4a) {
        return 0xb;
      }
      if ((long)param_1 < 0x58) {
        return 10;
      }
      if ((long)param_1 < 0x6c) {
        return 9;
      }
      if ((long)param_1 < 0x8c) {
        return 8;
      }
      if ((long)param_1 < 200) {
        return 3;
      }
      if ((long)param_1 < 0x168) {
        return 2;
      }
      return (ulong)((long)param_1 < 0x1e1);
    }
  }
  else if ((param_2 == 2) || (param_2 == 3)) {
    if (param_1 != 0) {
      if ((long)param_1 < 0xf) {
        return 0x3f;
      }
      if (param_1 == 0xf) {
        return 0x3e;
      }
      if (param_1 == 0x10) {
        return 0x3b;
      }
      if (param_1 == 0x11) {
        return 0x3a;
      }
      if ((long)param_1 < 0x14) {
        return 0x39;
      }
      if (param_1 == 0x14) {
        return 0x38;
      }
      if ((long)param_1 < 0x17) {
        return 0x1b;
      }
      if ((long)param_1 < 0x1a) {
        return 0x1a;
      }
      if ((long)param_1 < 0x1d) {
        return 0x19;
      }
      if ((long)param_1 < 0x21) {
        return 0x18;
      }
      if ((long)param_1 < 0x26) {
        return 0xb;
      }
      if ((long)param_1 < 0x2d) {
        return 10;
      }
      if ((long)param_1 < 0x37) {
        return 9;
      }
      if ((long)param_1 < 0x47) {
        return 8;
      }
      if ((long)param_1 < 0x65) {
        return 3;
      }
      if ((long)param_1 < 0xb5) {
        return 2;
      }
      return (ulong)((long)param_1 < 0xf1);
    }
  }
  else if ((int)param_2 - 4U < 2) {
    if (param_1 == 0x78) {
      return 0;
    }
    if (param_1 == 0x3c) {
      return 1;
    }
    if (param_1 == 0x28) {
      return 3;
    }
    if (param_1 == 0x1e) {
      return 7;
    }
    if (param_1 == 0x18) {
      param_1 = 0xf;
    }
    else if (param_1 == 0x14) {
      return 0x1f;
    }
  }
  return param_1;
}



// ==================== FUN_00003db2 @ 00003db2 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_00003db2(long param_1)

{
  uint uVar1;
  
  do {
  } while ((_DAT_0a340010 & 1) != 0);
  uVar1 = _DAT_0a3400c8;
  if (param_1 == 0x20) {
    uVar1 = _DAT_0a3400c8 | _DAT_0a3400d0 << 0x10;
  }
  do {
  } while ((_DAT_0a340010 & 1) == 0);
  _DAT_0a3400c4 = 1;
  return (long)(int)uVar1;
}



// ==================== FUN_00003dee @ 00003dee ====================

void FUN_00003dee(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x1c00c580;
  }
  else if (param_1 == 1) {
    uVar1 = 0x1c00c598;
  }
  else if (param_1 == 2) {
    uVar1 = 0x1c00c5b8;
  }
  else if (param_1 == 3) {
    uVar1 = 0x1c00c5d8;
  }
  else if (param_1 == 4) {
    uVar1 = 0x1c00c600;
  }
  else if (param_1 == 5) {
    uVar1 = 0x1c00c628;
  }
  else if (param_1 == 6) {
    uVar1 = 0x1c00c660;
  }
  else if (param_1 == 9) {
    uVar1 = 0x1c00c698;
  }
  else if (param_1 == 10) {
    uVar1 = 0x1c00c6c0;
  }
  else if (param_1 == 0xb) {
    uVar1 = 0x1c00c6e0;
  }
  else if (param_1 == 0xc) {
    uVar1 = 0x1c00c6f0;
  }
  else if (param_1 == 0xd) {
    uVar1 = 0x1c00c708;
  }
  else if (param_1 == 0xfd) {
    uVar1 = 0x1c00c720;
  }
  else if (param_1 == 0xfe) {
    uVar1 = 0x1c00c750;
  }
  else if (param_1 == 7) {
    uVar1 = 0x1c00c778;
  }
  else {
    if (param_1 != 0xff) {
      return;
    }
    uVar1 = 0x1c00c798;
  }
  FUN_00005b8a(uVar1);
  return;
}



// ==================== FUN_00003ef4 @ 00003ef4 ====================

undefined8 FUN_00003ef4(void)

{
  long lVar1;
  
  FUN_00005b8a(0x1c00c7b0);
  while( true ) {
    lVar1 = FUN_00003db2(0x10);
    FUN_00003dee();
    if (lVar1 == 7) {
      return 0;
    }
    if (lVar1 == 0xff) break;
    if (lVar1 == 8) {
      FUN_00005b8a(0x1c00c7c8);
    }
  }
  FUN_00005b8a(0x1c00c7d8);
  return 0;
}



// ==================== FUN_00003f5a @ 00003f5a ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003f5a(void)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  _DAT_0a04017c = 0x344;
  _DAT_0a04057c = 0x344;
  _DAT_0a04417c = 0x344;
  _DAT_0a04457c = 0x344;
  _DAT_0a000154 = 0x344;
  _DAT_0a004154 = 0x344;
  _DAT_0a008154 = 0x344;
  _DAT_0a00c154 = 0x344;
  _DAT_0a010154 = 0x44;
  _DAT_0a014154 = 0x44;
  _DAT_0a018154 = 0x344;
  _DAT_0a01c154 = 0x344;
  _DAT_0a020154 = 0x344;
  _DAT_0a024154 = 0x344;
  _DAT_0a080314 = 7;
  if ((((0x1d5 < _DAT_1c00e2c4) && (_DAT_0a080314 = 6, 0x271 < _DAT_1c00e2c4)) &&
      (_DAT_0a080314 = 0xb, 0x3a9 < _DAT_1c00e2c4)) &&
     ((_DAT_0a080314 = 10, 0x4e1 < _DAT_1c00e2c4 && (_DAT_0a080314 = 0x19, 0x753 < _DAT_1c00e2c4))))
  {
    _DAT_0a080314 = (0x855 < _DAT_1c00e2c4) + 0x18;
  }
  _DAT_0a0800b8 = (0x3a4 < _DAT_1c00e2c4) + 1;
  if (_DAT_1c00e2d4 == 1) {
    _DAT_0a0800b8 = (0x3a4 < _DAT_1c00e2c4) + 2;
  }
  _DAT_0a080090 = 0;
  _DAT_0a0800e8 = 0;
  _DAT_0a0801f4 = 0x212;
  _DAT_0a0801f0 = 0x61;
  _DAT_0a080158 = 10;
  if (0x3a5 < _DAT_1c00e2c4) {
    if (_DAT_1c00e2c4 < 0x4b1) {
      _DAT_0a080158 = 2;
      if (_DAT_1c00e1a0 != 1) {
        _DAT_0a080158 = 6;
      }
    }
    else {
      _DAT_0a080158 = 3;
      if (_DAT_1c00e1a0 != 1) {
        _DAT_0a080158 = 7;
      }
    }
  }
  lVar4 = (long)_DAT_1c00e1d4;
  lVar3 = (long)_DAT_1c00e2fc;
  uVar1 = FUN_00003c12(lVar4,2);
  iVar2 = FUN_00003c12(lVar4,3,lVar3);
  _DAT_0a040134 = iVar2 << 6 | uVar1;
  lVar4 = (long)_DAT_1c00e1e4;
  lVar3 = (long)_DAT_1c00e2fc;
  _DAT_0a040534 = _DAT_0a040134;
  _DAT_0a044134 = _DAT_0a040134;
  _DAT_0a044534 = _DAT_0a040134;
  uVar1 = FUN_00003c12(lVar4,0);
  iVar2 = FUN_00003c12(lVar4,1,lVar3);
  _DAT_0a040124 = iVar2 << 6 | uVar1;
  lVar4 = (long)_DAT_1c00e1f4;
  lVar3 = (long)_DAT_1c00e2fc;
  _DAT_0a040524 = _DAT_0a040124;
  _DAT_0a044124 = _DAT_0a040124;
  _DAT_0a044524 = _DAT_0a040124;
  uVar1 = FUN_00003c12(lVar4,4);
  iVar2 = FUN_00003c12(lVar4,5,lVar3);
  _DAT_0a00010c = iVar2 << 5 | uVar1;
  _DAT_0a00410c = _DAT_0a00010c;
  _DAT_0a00810c = _DAT_0a00010c;
  _DAT_0a00c10c = _DAT_0a00010c;
  _DAT_0a01010c = _DAT_0a00010c;
  _DAT_0a01410c = _DAT_0a00010c;
  _DAT_0a01810c = _DAT_0a00010c;
  _DAT_0a01c10c = _DAT_0a00010c;
  _DAT_0a02010c = _DAT_0a00010c;
  _DAT_0a02410c = _DAT_0a00010c;
  _DAT_0a080060 = 1;
  _DAT_0a0801d4 = 0;
  _DAT_0a080140 = _DAT_1c00e1c0 | _DAT_1c00e1c0 << 4;
  _DAT_0a080020 = _DAT_1c00e2c4 / 2;
  _DAT_0a080220 = 9;
  if (0x7f < (((uint)DAT_1c00e104 * 100000) / 64000 + 1 & 0xff)) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_000048ba @ 000048ba ====================

long FUN_000048ba(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = 1;
  lVar1 = 0;
  if (param_1 != 0) {
    for (; lVar1 < param_1; lVar1 = (long)((int)lVar1 + 1)) {
      lVar2 = (long)((int)lVar2 << 1);
    }
  }
  return lVar2;
}



// ==================== FUN_000048d0 @ 000048d0 ====================

ulong FUN_000048d0(int param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; uVar2 != (long)param_1; uVar2 = (ulong)((int)uVar2 + 1)) {
    uVar1 = uVar1 | (long)(1 << (uVar2 & 0x1f));
  }
  return uVar1;
}



// ==================== FUN_000048ea @ 000048ea ====================

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_000048ea(undefined8 param_1,undefined8 param_2)

{
  custom0();
  FUN_000048d0(param_2);
  custom0.rs1.rs2(param_1,0);
  custom0.rd();
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00004920 @ 00004920 ====================

void FUN_00004920(void)

{
  FUN_000048ea(&DAT_0ce004c0,8,1,0);
  return;
}



// ==================== FUN_00004930 @ 00004930 ====================

void FUN_00004930(void)

{
  FUN_000048ea(&DAT_0ce004c0,0xb,1,0);
  return;
}



// ==================== FUN_00004940 @ 00004940 ====================

void FUN_00004940(void)

{
  FUN_000048ea(&DAT_0ce004c0,0xc,1,0);
  return;
}



// ==================== FUN_00004950 @ 00004950 ====================

void FUN_00004950(void)

{
  FUN_000048ea(&DAT_0ce004c0,9,1,0);
  return;
}



// ==================== FUN_00004960 @ 00004960 ====================

void FUN_00004960(void)

{
  FUN_000048ea(&DAT_0ce004c0,0xb,1,1);
  return;
}



// ==================== FUN_00004970 @ 00004970 ====================

void FUN_00004970(void)

{
  FUN_000048ea(&DAT_0ce004c0,0xc,1,1);
  return;
}



// ==================== FUN_00004980 @ 00004980 ====================

void FUN_00004980(void)

{
  FUN_000048ea(&DAT_0ce004c0,9,1,1);
  return;
}



// ==================== FUN_00004990 @ 00004990 ====================

void FUN_00004990(undefined8 param_1)

{
  FUN_000048ea(&DAT_0ce004c0,10,1,param_1);
  return;
}



// ==================== FUN_000049a0 @ 000049a0 ====================

void FUN_000049a0(void)

{
  FUN_000048ea(&DAT_0ce004c0,8,1,1);
  return;
}



// ==================== FUN_000049b0 @ 000049b0 ====================

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_000049b0(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  uVar1 = param_1[1];
  if (uVar1 == 800) {
LAB_000049fc:
    puVar5 = &DAT_1c00da00;
  }
  else if (uVar1 < 0x321) {
    if (uVar1 == 400) {
      puVar5 = (undefined1 *)0x1c00dc50;
    }
    else {
      if (uVar1 != 0x215) goto LAB_000049d8;
      puVar5 = (undefined1 *)0x1c00d8d8;
    }
  }
  else {
    if (uVar1 != 0x42a) {
LAB_000049d8:
      FUN_00005b24(0x1c00c828);
      param_1[1] = 800;
      FUN_00005b24(0x1c00c850,800);
      goto LAB_000049fc;
    }
    puVar5 = (undefined1 *)0x1c00db28;
  }
  *(undefined1 **)(param_1 + 4) = puVar5;
  FUN_00005b24(0x1c00c870,param_1[1]);
  uVar1 = *param_1;
  puVar3 = *(uint **)(param_1 + 4);
  uVar2 = *puVar3;
  if (uVar1 == 0x800) {
    iVar4 = 159999;
    goto LAB_00004a84;
  }
  if (uVar1 < 0x801) {
    if (uVar1 == 0x200) {
      iVar4 = 89999;
      goto LAB_00004a84;
    }
    if (uVar1 == 0x400) {
      iVar4 = 109999;
      goto LAB_00004a84;
    }
  }
  else if (uVar1 == 0x1000) {
    iVar4 = 259999;
    goto LAB_00004a84;
  }
  iVar4 = 349999;
LAB_00004a84:
  puVar3[0x21] = (iVar4 + uVar2) / uVar2;
  puVar3[0x1b] = puVar3[0x1a] + puVar3[0x19];
  puVar3[0x1c] = puVar3[0x18] + puVar3[0x19];
  puVar3[0x3d] = puVar3[0x3a] + 1;
  puVar3[0x26] = puVar3[0x24];
  puVar3[0x25] = puVar3[0x1d] * 9;
  custom0.rs1.rs2((long)(int)((uVar2 + 9999) / uVar2 + puVar3[0x21]),0);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00004aee @ 00004aee ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00004aee(void)

{
  return _DAT_1c00e0f0;
}



// ==================== FUN_00004af8 @ 00004af8 ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004af8(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 local_70;
  uint *puStack_68;
  
  FUN_00005b24(0x1c00c898,0x1000);
  puStack_68 = (uint *)0x0;
  local_70._0_4_ = CONCAT22((short)_DAT_1c00dd78,0x1000);
  local_70 = (ulong)CONCAT24(0x808,(undefined4)local_70);
  _DAT_0ce0048c = _DAT_0ce0048c | 0x600;
  FUN_00004920();
  FUN_00004930();
  FUN_00004940();
  FUN_00004950();
  FUN_00004960();
  FUN_00004990(1);
  FUN_00004970();
  FUN_00004980();
  FUN_00003aea(0);
  _DAT_1c00e2c4 = (uint)local_70._2_2_;
  FUN_000049b0(&local_70);
  puVar1 = puStack_68;
  if (local_70._2_2_ == 400) {
    _DAT_0ce0049c = _DAT_0ce0049c & 0xffffff00 | 7;
  }
  else {
    if (local_70._2_2_ == 0x215) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
    if (local_70._2_2_ == 800) {
      _DAT_0ce0049c = _DAT_0ce0049c & 0xffffff00 | 3;
    }
    else if (local_70._2_2_ == 0x42a) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
      halt_unimplemented();
    }
  }
  _DAT_0ce00500 = 0;
  _DAT_0d000304 = 1;
  _DAT_0d000000 = (uint)(local_70._4_1_ >> 1) << 0x10 | 0x80000001;
  _DAT_0d000010 = 0xd010;
  _DAT_0d000014 = 0x37c0b;
  _DAT_0d00001c = 0x8541c500;
  _DAT_0d000028 = 1;
  _DAT_0d000030 = 0x20;
  _DAT_0d000034 = 2;
  _DAT_0d000038 = 0x70003;
  _DAT_0d000050 = 0x11c040;
  _DAT_0d000060 = (uint)local_70._6_1_ << 4;
  uVar2 = FUN_000048ba(local_70._6_1_);
  _DAT_0d000064 = (puVar1[0x1d] >> 6) / uVar2 << 0x10 | puVar1[0x21] + 1 >> 1;
  _DAT_0d0000c0 = 0;
  _DAT_0d0000c4 = 0;
  _DAT_0d0000d0 =
       (((*puVar1 + 499999999) / *puVar1 + 0x3ff >> 10) + 1 >> 1) + 1 |
       ((puVar1[0x30] + 0x3ff >> 10) + 1 >> 1) << 0x10 | 0xc0000000;
  _DAT_0d0000d4 = (((*puVar1 + 199999999) / *puVar1 + 0x3ff >> 10) + 1 >> 1) << 0x10;
  uVar2 = puVar1[0x20];
  if (uVar2 < 9) {
    uVar2 = (uVar2 - 4) * 0x200 & 0xe00;
  }
  else {
    if (0xe < uVar2) {
      puVar1[1] = 0;
      goto LAB_00004cd8;
    }
    uVar2 = (uVar2 >> 1) << 9;
  }
  puVar1[1] = uVar2;
LAB_00004cd8:
  uVar2 = puVar1[0x18];
  if (uVar2 < 0xc) {
    uVar4 = puVar1[1] | (uVar2 - 4) * 0x10;
  }
  else {
    uVar4 = puVar1[1] | (uVar2 - 0xc) * 0x10 | 4;
  }
  puVar1[1] = uVar4 | 0x1100;
  uVar3 = 0;
  if (uVar2 - puVar1[0x19] < 3) {
    uVar3 = (uVar2 - puVar1[0x19]) * 8;
  }
  uVar3 = (DAT_1c00e0e8 & 3) << 1 | uVar3;
  _DAT_0d0000dc = (uVar4 | 0x1100) << 0x10 | uVar3;
  puVar1[2] = uVar3;
  puVar1[3] = (puVar1[0x1a] - 5) * 8;
  puVar1[4] = (uint)local_70._6_1_ << 6;
  _DAT_0d0000e0 = (puVar1[0x1a] - 5) * 0x80000 | (uint)local_70._6_1_ << 6;
  _DAT_0d0000e4 = ((puVar1[0x32] >> 5) + 1 >> 1) << 0x10;
  _DAT_0d0000e8 = 0;
  _DAT_0d0000ec = 0;
  _DAT_1c00e156 = (short)puVar1[1];
  _DAT_1c00e158 = (short)puVar1[2];
  _DAT_1c00e15a = (short)puVar1[3];
  _DAT_0d0000f0 = 0;
  _DAT_0d000100 =
       (puVar1[0x1e] + 1 >> 1) << 0x10 | puVar1[0x24] >> 1 |
       (puVar1[0x1b] + puVar1[0x20] + (uint)(local_70._4_1_ >> 1) >> 1) << 0x18 |
       ((puVar1[0x25] >> 10) - 1 >> 1) << 8;
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_00005428 @ 00005428 ====================

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_00005428(ulong param_1,ulong param_2,ulong param_3)

{
  bool bVar1;
  
  if ((param_3 & 0x10) != 0) {
    param_3 = param_3 & 0xfffffffffffffffe;
  }
  if (((param_3 & 2) != 0) && ((long)param_1 < 0)) {
    param_1 = -param_1;
  }
  if (param_1 != 0) {
    do {
      custom0.rd();
      custom0();
      bVar1 = param_2 <= param_1;
      param_1 = param_1 / param_2;
    } while (bVar1);
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_000055d6 @ 000055d6 ====================

/* WARNING: Control flow encountered unimplemented instructions */

long FUN_000055d6(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  ulong uVar12;
  code *pcVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  undefined8 uVar17;
  undefined1 local_78 [32];
  
  lVar16 = 0;
  pbVar4 = param_1;
  do {
    bVar1 = *param_2;
    if (bVar1 == 0) {
      *pbVar4 = 0;
      return (long)((int)pbVar4 - (int)param_1);
    }
    if (bVar1 == 0x25) {
      bVar3 = false;
      do {
        while( true ) {
          while( true ) {
            do {
              pbVar5 = param_2;
              bVar1 = pbVar5[1];
              param_2 = pbVar5 + 1;
            } while (bVar1 == 0x2b);
            if (0x2b < bVar1) break;
            if ((bVar1 != 0x20) && (bVar1 != 0x23)) goto LAB_0000569c;
          }
          if (bVar1 != 0x2d) break;
          bVar3 = true;
        }
      } while (bVar1 == 0x30);
LAB_0000569c:
      if ((byte)(bVar1 - 0x30) < 10) {
        lVar8 = 0;
        for (; (byte)(*param_2 - 0x30) < 10; param_2 = param_2 + 1) {
          custom0();
          lVar8 = (long)(int)(*param_2 - 0x30);
        }
      }
      else {
        lVar8 = -1;
        if (bVar1 == 0x2a) {
          lVar8 = custom0.rd();
          param_2 = pbVar5 + 2;
          if (lVar8 < 0) {
            lVar8 = (long)-(int)lVar8;
            bVar3 = true;
          }
        }
      }
      if (*param_2 == 0x2e) {
        pbVar5 = param_2 + 1;
        param_2 = param_2 + 1;
        if ((byte)(*pbVar5 - 0x30) < 10) {
          for (; (byte)(*param_2 - 0x30) < 10; param_2 = param_2 + 1) {
            custom0();
          }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
          halt_unimplemented();
        }
        if (*pbVar5 == 0x2a) {
          custom0.rd();
          halt_unimplemented();
        }
      }
      uVar12 = (ulong)*param_2;
      if ((uVar12 == 0x68) || (uVar6 = 0xffffffffffffffff, (uVar12 & 0xdf) == 0x4c)) {
        param_2 = param_2 + 1;
        uVar6 = uVar12;
      }
      bVar1 = *param_2;
      if (bVar1 == 0x41) {
        custom0.rd();
        iVar9 = (int)lVar8;
        if (uVar6 == 0x6c) {
          custom0();
          lVar7 = 0;
          puVar11 = local_78;
          while( true ) {
            custom0.rd();
            uVar17 = custom0.rd();
            uVar14 = custom0.rd();
            *puVar11 = (char)uVar17;
            puVar11[1] = (char)uVar14;
            lVar7 = lVar7 + 1;
            if (lVar7 == 6) break;
            puVar11[2] = 0x3a;
            puVar11 = puVar11 + 3;
          }
          if (!bVar3) {
            for (iVar10 = 0; 0x11 < iVar9 - iVar10; iVar10 = iVar10 + 1) {
              custom0();
            }
            if (0x10 < lVar8) {
              custom0.rs1.rs2((long)(iVar9 + -0x11),0);
            }
            iVar10 = 0;
            if (0x10 < lVar8) {
              iVar10 = -(iVar9 + -0x11);
            }
            lVar8 = (long)(iVar9 + -1 + iVar10);
          }
          lVar7 = 0;
          do {
            custom0.rd();
            custom0();
            lVar7 = lVar7 + 1;
          } while (lVar7 != 0x11);
          pbVar4 = pbVar4 + 0x11;
          for (iVar9 = 0; 0x11 < (int)lVar8 - iVar9; iVar9 = iVar9 + 1) {
            custom0();
          }
          if (0x10 < lVar8) {
            custom0.rs1.rs2((long)((int)lVar8 + -0x11),0);
          }
        }
        else {
          lVar7 = 0;
          iVar10 = 0;
          while( true ) {
            lVar15 = custom0.rd();
            iVar2 = iVar10 + 1;
            if (lVar15 == 0) {
              custom0();
            }
            else {
              if (lVar15 < 100) {
                if (9 < lVar15) {
                  custom0.rd();
                  custom0();
                  iVar10 = iVar2;
                }
              }
              else {
                custom0.rd();
                custom0();
                custom0.rd();
                custom0();
                iVar10 = iVar10 + 2;
              }
              custom0.rd();
              iVar2 = iVar10 + 1;
              custom0();
            }
            lVar15 = (long)iVar2;
            lVar7 = lVar7 + 1;
            if (lVar7 == 4) break;
            iVar10 = iVar2 + 1;
            custom0();
          }
          if (!bVar3) {
            for (iVar10 = 0; lVar15 < iVar9 - iVar10; iVar10 = iVar10 + 1) {
              custom0();
            }
            if (lVar15 <= lVar8) {
              custom0.rs1.rs2((long)(iVar9 - iVar2),0);
            }
            iVar10 = 0;
            if (lVar15 <= lVar8) {
              iVar10 = -(iVar9 - iVar2);
            }
            lVar8 = (long)(iVar9 + -1 + iVar10);
          }
          iVar9 = 0;
          do {
            custom0.rd();
            custom0();
            iVar9 = iVar9 + 1;
          } while (iVar9 < lVar15);
          pbVar4 = pbVar4 + lVar15;
          for (iVar9 = 0; lVar15 < (int)lVar8 - iVar9; iVar9 = iVar9 + 1) {
            custom0();
          }
          if (lVar15 <= lVar8) {
            custom0.rs1.rs2((long)((int)lVar8 - iVar2),0);
          }
        }
      }
      else {
        if ((byte)(bVar1 + 0xa8) < 0x21) {
          pcVar13 = (code *)custom0.rd();
                    /* WARNING: Does not return */
          (*pcVar13)();
        }
        if (bVar1 != 0x25) {
          custom0();
        }
        if (*param_2 == 0) {
          param_2 = param_2 + -1;
        }
        else {
          custom0();
        }
      }
    }
    else {
      *pbVar4 = bVar1;
      lVar16 = (long)((int)lVar16 + 1);
      if (0xff < lVar16) {
        return lVar16;
      }
      pbVar4 = pbVar4 + 1;
    }
    param_2 = param_2 + 1;
  } while( true );
}



// ==================== FUN_00005b24 @ 00005b24 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_00005b24(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_000055d6(&DAT_1c00e340,param_1);
  if (lVar1 < 0x100) {
    uVar2 = 0xd;
    lVar1 = (long)((int)lVar1 + 1);
    custom0();
  }
  else {
    uVar2 = 0xd0a;
    lVar1 = 0x102;
    _DAT_1c00e440 = 0xd0a;
  }
  FUN_00003a84(&DAT_1c00e340,lVar1,uVar2);
  return lVar1;
}



// ==================== FUN_00005b8a @ 00005b8a ====================

long FUN_00005b8a(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = &DAT_1c00e340;
  iVar2 = 0;
  while( true ) {
    cVar1 = *param_1;
    iVar3 = iVar2 + 1;
    if ((cVar1 == '\0') || (0xff < iVar2)) break;
    *pcVar4 = cVar1;
    param_1 = param_1 + 1;
    if (cVar1 == '\n') {
      pcVar4[1] = '\r';
      pcVar4 = pcVar4 + 2;
    }
    else {
      pcVar4 = pcVar4 + 1;
      iVar3 = iVar2;
    }
    iVar2 = iVar3 + 1;
  }
  custom0();
  custom0();
  FUN_00003a84(&DAT_1c00e340,(long)(iVar2 + 2),0xd,&DAT_1c00e340);
  return (long)(iVar2 + 2);
}



// ==================== FUN_00005bf4 @ 00005bf4 ====================

void FUN_00005bf4(ulong param_1,undefined4 *param_2)

{
  code *pcVar1;
  
  if (param_1 < 0x11) {
    pcVar1 = (code *)custom0.rd();
                    /* WARNING: Does not return */
    (*pcVar1)();
  }
  *param_2 = 0xff00ff;
  FUN_00005b8a(0x1c00cb38);
  return;
}



// ==================== FUN_00005caa @ 00005caa ====================

undefined8 FUN_00005caa(ulong param_1,ulong param_2)

{
  code *pcVar1;
  
  if (0x28 < param_1) {
    return 0xffffffffffffffea;
  }
  if (param_2 < 6) {
    pcVar1 = (code *)custom0.rd();
                    /* WARNING: Does not return */
    (*pcVar1)();
  }
  FUN_00005b24(0x1c00cba8,param_1,param_2);
  return 0xffffffffffffffea;
}



// ==================== FUN_00005dce @ 00005dce ====================

undefined8 FUN_00005dce(ulong param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  if (param_1 < 0x29) {
    puVar1 = (undefined1 *)(long)(((int)param_1 + 0x320000) * 0x40 + 4);
    custom0.rs1.rs2(puVar1,0);
    *puVar1 = param_2;
    return 0;
  }
  return 0xffffffffffffffea;
}



// ==================== FUN_00005df6 @ 00005df6 ====================

undefined8 FUN_00005df6(void)

{
  ulong uVar1;
  undefined8 uVar2;
  ushort uStack_18;
  ushort uStack_16;
  int iStack_14;
  
  FUN_00005bf4(&uStack_18);
  uVar2 = 0xffffffffffffffea;
  if (uStack_18 < 0x29) {
    uVar1 = (ulong)uStack_16;
    uVar2 = 0xffffffffffffffea;
    if (uVar1 < 0x29) {
      for (; (long)uVar1 <= (long)(ulong)uStack_18; uVar1 = (ulong)((int)uVar1 + 1)) {
        FUN_00005caa(uVar1,(long)iStack_14);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



// ==================== FUN_00005e38 @ 00005e38 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005e38(void)

{
  _DAT_0ce08804 = 0xff;
  _DAT_0ce08800 = 0;
  _DAT_0ce0880c = 0xf;
  return;
}



// ==================== FUN_00005e54 @ 00005e54 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005e54(void)

{
  _DAT_0ce08c04 = 0xff;
  _DAT_0ce08c00 = 0;
  _DAT_0ce08c0c = 0xf;
  return;
}



// ==================== FUN_00005e70 @ 00005e70 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005e70(void)

{
  _DAT_0ce09804 = 0xff;
  _DAT_0ce09800 = 0;
  _DAT_0ce0980c = 0xf;
  return;
}



// ==================== FUN_00005e8c @ 00005e8c ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005e8c(void)

{
  _DAT_0ce09c04 = 0xff;
  _DAT_0ce09c00 = 0;
  _DAT_0ce09c0c = 0xf;
  return;
}



// ==================== FUN_00005ea8 @ 00005ea8 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005ea8(void)

{
  _DAT_0ce0a004 = 0xff;
  _DAT_0ce0a000 = 0;
  _DAT_0ce0a00c = 0xf;
  return;
}



// ==================== FUN_00005ec4 @ 00005ec4 ====================

void FUN_00005ec4(void)

{
  FUN_00005e38();
  FUN_00005e54();
  FUN_00005e70();
  FUN_00005e8c();
  return;
}



// ==================== FUN_00005eda @ 00005eda ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005eda(void)

{
  _DAT_0ce004c0 = _DAT_0ce004c0 | 0x1000080;
  _DAT_0ce01888 = 0;
  FUN_0000391e(10);
  _DAT_0ce01888 = 0x3ff;
  return;
}



// ==================== FUN_00005f14 @ 00005f14 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00005f14(void)

{
  _DAT_11200018 = 0x2400000e;
  _DAT_1120001c = 0x2400000e;
  _DAT_11200020 = 0x2400000e;
  _DAT_11200024 = 0x2400000e;
  return;
}



// ==================== FUN_00005f28 @ 00005f28 ====================

void FUN_00005f28(void)

{
  FUN_00005ec4();
  FUN_00005ea8();
  FUN_00005eda();
  FUN_00005f14();
  return;
}



// ==================== FUN_00005f3e @ 00005f3e ====================

void FUN_00005f3e(long param_1)

{
  long lVar1;
  
  for (lVar1 = 0; param_1 != lVar1; lVar1 = lVar1 + 1) {
    custom0();
  }
  return;
}



// ==================== FUN_00005f4e @ 00005f4e ====================

void FUN_00005f4e(ulong param_1,ulong param_2,long param_3)

{
  ulong uVar1;
  long lVar2;
  
  if (param_1 != param_2) {
    uVar1 = (param_1 | param_2) & 7;
    if (uVar1 == 0) {
      for (; 7 < param_3 - uVar1; uVar1 = uVar1 + 8) {
        custom0.rd();
        custom0();
      }
      custom0();
      custom0();
      custom0();
    }
    for (lVar2 = 0; param_3 != lVar2; lVar2 = lVar2 + 1) {
      custom0.rd();
      custom0();
    }
  }
  return;
}



// ==================== FUN_00005f98 @ 00005f98 ====================

ulong FUN_00005f98(ulong param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  
  if ((param_2 < param_1) && (param_1 < param_2 + param_3)) {
    uVar1 = 0;
    while (uVar1 = uVar1 - 1, ~param_3 != uVar1) {
      custom0.rd();
      custom0();
    }
    return param_1;
  }
  uVar1 = FUN_00005f4e(param_1);
  return uVar1;
}



// ==================== FUN_00005fd4 @ 00005fd4 ====================

long FUN_00005fd4(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar2 = 0;
  do {
    if (param_1 == lVar2) {
      return 0;
    }
    uVar3 = custom0.rd();
    uVar1 = custom0.rd();
    lVar2 = lVar2 + 1;
    lVar4 = (long)((int)uVar3 - (int)uVar1);
  } while (lVar4 == 0);
  return lVar4;
}



// ==================== FUN_00005ff0 @ 00005ff0 ====================

long FUN_00005ff0(long param_1,ulong param_2,long param_3)

{
  ulong uVar1;
  
  do {
    if (param_1 == param_3 + param_1) {
      return 0;
    }
    uVar1 = custom0.rd();
  } while (uVar1 != (param_2 & 0xff));
  return param_1;
}



// ==================== FUN_0000600c @ 0000600c ====================

long FUN_0000600c(char *param_1)

{
  char *pcVar1;
  
  for (pcVar1 = param_1; *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
  }
  return (long)pcVar1 - (long)param_1;
}



// ==================== FUN_0000601e @ 0000601e ====================

long FUN_0000601e(void)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  do {
    lVar1 = custom0.rd();
    uVar2 = custom0.rd();
    lVar3 = (long)((int)lVar1 - (int)uVar2);
    custom0.rs1(lVar3);
    if (lVar3 != 0) {
      return lVar3;
    }
  } while (lVar1 != 0);
  return 0;
}



// ==================== FUN_0000603a @ 0000603a ====================

long FUN_0000603a(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar2 = 0;
  while( true ) {
    if (param_1 == lVar2) {
      return 0;
    }
    lVar1 = custom0.rd();
    uVar3 = custom0.rd();
    lVar4 = (long)((int)uVar3 - (int)lVar1);
    if (lVar4 != 0) break;
    lVar2 = lVar2 + 1;
    if (lVar1 == 0) {
      return 0;
    }
  }
  return lVar4;
}



// ==================== FUN_00006058 @ 00006058 ====================

char * FUN_00006058(char *param_1,char param_2)

{
  long lVar1;
  char *pcVar2;
  
  lVar1 = FUN_0000600c();
  pcVar2 = param_1 + lVar1;
  do {
    if (*pcVar2 == param_2) {
      return pcVar2;
    }
    pcVar2 = pcVar2 + -1;
  } while (param_1 <= pcVar2);
  return (char *)0x0;
}



// ==================== FUN_00006086 @ 00006086 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00006086(void)

{
  _DAT_0ce00500 = _DAT_0ce00500 & 0xfffffffe;
  return 0;
}



// ==================== FUN_000060a0 @ 000060a0 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000060a0(undefined8 *param_1)

{
  _DAT_0e010904 = 0x11;
  *param_1 = 0;
  return;
}



// ==================== FUN_000060b0 @ 000060b0 ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0x0000613a) */
/* WARNING: Removing unreachable block (ram,0x0000618e) */
/* WARNING: Removing unreachable block (ram,0x0000619a) */
/* WARNING: Removing unreachable block (ram,0x00006192) */
/* WARNING: Removing unreachable block (ram,0x0000613c) */
/* WARNING: Removing unreachable block (ram,0x00006140) */
/* WARNING: Removing unreachable block (ram,0x00006142) */
/* WARNING: Removing unreachable block (ram,0x0000614a) */
/* WARNING: Removing unreachable block (ram,0x000061a0) */
/* WARNING: Removing unreachable block (ram,0x00006178) */

void FUN_000060b0(ulong *param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = *param_1 & 0x3f;
  *param_1 = *param_1 + param_2;
  if (param_2 + uVar2 < 0x40) {
    custom0.rs1.rs2(0,0);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  if (uVar2 != 0) {
    lVar1 = (long)(0x40 - (int)uVar2);
    custom0.rs1.rs2(lVar1,0);
    FUN_00005f4e((long)param_1 + uVar2 + 8,lVar1);
  }
  do {
    custom0.rd();
    custom0();
    custom0();
  } while( true );
}



// ==================== FUN_000061ac @ 000061ac ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_000061ac(ulong *param_1)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  long alStack_28 [2];
  
  alStack_28[0] = *param_1 << 3;
  custom0();
  uVar1 = *param_1 & 0x3f;
  if (uVar1 < 0x38) {
    iVar3 = 0x38;
  }
  else {
    iVar3 = 0x78;
  }
  lVar2 = (long)(iVar3 - (int)uVar1);
  custom0.rs1.rs2(lVar2,0);
  lVar2 = FUN_000060b0(param_1,0x1c00cbf0,lVar2,0);
  if ((lVar2 == 0) && (lVar2 = FUN_000060b0(param_1,alStack_28,8,1), lVar2 == 0)) {
    iVar3 = 0xf4242;
    do {
      if ((_DAT_0e010900 & 3) != 0) {
        puVar4 = &DAT_0e0108e0;
        do {
          custom0();
          custom0();
          puVar4 = puVar4 + 4;
        } while (puVar4 != &DAT_0e010900);
        return 0;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    lVar2 = -5;
  }
  return lVar2;
}



// ==================== FUN_00006244 @ 00006244 ====================

void FUN_00006244(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined1 auStack_68 [80];
  
  FUN_000060a0(auStack_68);
  lVar1 = FUN_000060b0(auStack_68,param_1,param_2,0);
  if (lVar1 == 0) {
    FUN_000061ac(auStack_68,param_3);
  }
  return;
}



// ==================== FUN_0000627a @ 0000627a ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000627a(undefined8 param_1,long param_2)

{
  long lVar1;
  
  for (lVar1 = 0; param_2 != lVar1; lVar1 = lVar1 + 1) {
    custom0.rd();
  }
  custom0.rs1.rs2(param_1,0);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}



// ==================== FUN_000062de @ 000062de ====================

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000062de(undefined8 param_1,ulong param_2,ulong param_3)

{
  if (((param_2 & 7) != 0) && (param_3 != 0)) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  if (param_3 >> 3 != 0) {
    custom0.rd();
    custom0.rs1.rs2(param_1,0);
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  custom0();
  if ((param_3 & 7) != 0) {
    FUN_0000627a(param_1,_DAT_1c00cc30,0xedb8832000000000);
    return;
  }
  return;
}



// ==================== FUN_00006370 @ 00006370 ====================

void FUN_00006370(void)

{
  FUN_00005b8a(0x1c00cc38);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==================== FUN_00006382 @ 00006382 ====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00006382(long param_1)

{
  long lVar1;
  
  if (param_1 == 0) {
    FUN_000037dc();
    custom0.rs1.rs2((long)(int)_DAT_0ce004a0,0);
    _DAT_0ce004a0 = _DAT_0ce004a0 | 0x2c000000;
    FUN_00006086();
    _DAT_0ce0048c = _DAT_0ce0048c | 0xf0317f;
    FUN_00005f28();
    FUN_00005df6(6);
    FUN_00005caa(6,5);
    FUN_00005dce(6,1);
    FUN_00005caa(7,5);
    FUN_00005dce(7,1);
    lVar1 = 0x15;
    do {
      if (lVar1 != 0x16) {
        FUN_00005caa(lVar1,0);
      }
      lVar1 = (long)((int)lVar1 + 1);
    } while (lVar1 != 0x22);
    FUN_00005df6(0xb);
    FUN_00005df6(0xc);
    FUN_00005df6(2);
    FUN_00003938();
    FUN_00003a54(1);
    lVar1 = FUN_00000348();
    if (-1 < lVar1) goto LAB_00006428;
    do {
      FUN_00006370();
LAB_00006428:
      FUN_00004af8();
      FUN_00003816();
      FUN_00005b24(0x1c00cc88,0x1c00cc78,0x1c00cc68);
      lVar1 = FUN_0000334e();
      _DAT_0ce09804 = 0;
      _DAT_0ce00c04 = _DAT_0ce00c04 & 0xfffffff7 | 8;
      _DAT_0ce09800 = 0;
      if (lVar1 == 0) {
        FUN_0000337a();
      }
    } while( true );
  }
  return 0;
}



