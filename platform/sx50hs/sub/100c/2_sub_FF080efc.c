
void __attribute__((naked,noinline)) sub_FF080EFC_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R8,LR} \n" 
      "    SUB     SP, SP, #0x50 \n" 
      "    MOV     R8, #0 \n" 
      "    LDR     R5, =0x38B0 \n" 
      "    STR     R8, [SP, #0x40] \n" 
      "    STR     R8, [SP, #0x38] \n" 
      "    STR     R8, [R5, #0xC4] \n" 
      "    LDR     R1, [R5, #0x44] \n" 
      "    MOV     R4, R0 \n" 
      "    CMP     R1, #3 \n" 
      "    MOV     R6, R8 \n" 
      "    MOV     R7, #1 \n" 
      "    BNE     loc_FF080F54 \n" 
      "    LDR     R0, [R5, #0x148] \n" 
      "    LDR     R1, [R5, #0x14C] \n" 
      "    CMP     R0, R1 \n" 
      "    BNE     loc_FF0810E0 \n" 
      "    MOV     R0, #4 \n" 
      "    STR     R0, [R5, #0x44] \n" 
      "    MVN     R0, #0 \n" 
      "    STR     R0, [R5, #0x148] \n" 
      "    B       loc_FF080F5C \n" 
"loc_FF080F54:\n"
      "    CMP     R1, #4 \n" 
      "    BNE     loc_FF0810E0 \n" 
"loc_FF080F5C:\n"
      "    LDRH    R0, [R5, #6] \n" 
      "    CMP     R0, #3 \n" 
      "    BNE     loc_FF080F94 \n" 
      "    LDR     R0, [R5, #0xC8] \n" 
      "    CMP     R0, #0 \n" 
      "    LDREQ   R1, =0x86B \n" 
      "    LDREQ   R0, =0xFF07E60C \n" 
      "    BLEQ    sub_0068B104 \n" 
      "    LDR     R0, [R5, #0x6C] \n" 
      "    LDR     R1, [R5, #0xC8] \n" 
      "    BL      sub_0069092C \n" 
      "    CMP     R1, #0 \n" 
      "    MOVNE   R7, #0 \n" 
      "    BNE     loc_FF080FB0 \n" 
"loc_FF080F94:\n"
      "    ADD     R3, SP, #0x38 \n" 
      "    ADD     R2, SP, #0x3C \n" 
      "    ADD     R1, SP, #0x40 \n" 
      "    ADD     R0, SP, #0x44 \n" 
      "    BL      sub_FF1EEDDC \n" 
      "    MOVS    R8, R0 \n" 
      "    BNE     loc_FF080FCC \n" 
"loc_FF080FB0:\n"
      "    LDR     R0, [R5, #0x34] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FF0810E8 \n" 
      "    LDR     R0, [R5, #0x6C] \n" 
      "    LDR     R1, [R5, #0x48] \n" 
      "    CMP     R0, R1 \n" 
      "    BCC     loc_FF0810E8 \n" 
"loc_FF080FCC:\n"
      "    MOV     R0, R8 \n" 
      "    BL      sub_FF07EEF4 \n" 
      "    BL      loc_FF08202C \n" 
      "    LDR     R2, [R5, #0x64] \n" 
      "    ADD     R3, SP, #0x48 \n" 
      "    MVN     R1, #1 \n" 
      "    MOV     R0, #0 \n" 
      "    ADD     R7, SP, #0x1C \n" 
      "    STMIA   R7, {R0-R3} \n" 
      "    LDR     R3, [R4, #0x1C] \n" 
      "    LDR     R1, [R5, #0x74] \n" 
      "    LDR     R2, [R5, #0x78] \n" 
      "    ADD     R0, SP, #0x4C \n" 
      "    ADD     R4, SP, #0xC \n" 
      "    STMIA   R4, {R0-R3} \n" 
      "    MOV     R3, #0 \n" 
      "    MOV     R1, #0x40 \n" 
      "    STMEA   SP, {R1,R3} \n" 
      "    MOV     R2, #0 \n" 
      "    STR     R3, [SP, #8] \n" 
      "    LDR     R3, =0x43A1C \n" 
      "    MOV     R1, R2 \n" 
      "    MOV     R0, R2 \n" 
      "    BL      sub_FF192968 \n" 
      "    LDR     R0, [R5, #0x1C] \n" 
      "    LDR     R1, [R5, #0x60] \n" 
      "    BL      sub_0068AA1C \n" 
      "    CMP     R0, #9 \n" 
      "    BNE     loc_FF0810B4 \n" 
"loc_FF081040:\n"
      "    MOV     R1, #1 \n" 
      "    B       loc_FF081208 \n" 



      "    .long   0xFF080038 \n" 
      "    ANDEQ   R0, R0, R8, LSR #0x1B \n" 
      "    ANDEQ   R0, R0, SP, LSR LR \n" 
      "    .long   0xFF07EED0 \n" 
"dword_FF081058  DCD 0x4397C \n"
"dword_FF08105C  DCD 0x3928 \n"
"dword_FF081060  DCD 0x43A1C \n"
"dword_FF081064  DCD 0xC25 \n"
"dword_FF081068  DCD 0xFF07E60C \n"
"dword_FF08106C  DCD 0xFFF00 \n"
"dword_FF081070  DCD 0x74C \n"
"dword_FF081074  DCD 0x38B2 \n"
"dword_FF081078  DCD 0x38B4 \n"
"dword_FF08107C  DCD 0x3900 \n"
"dword_FF081080  DCD 0x3904 \n"
"dword_FF081084  DCD 0x3A10 \n"
"dword_FF081088  DCD 0x4A280A60 \n"
"dword_FF08108C  DCD 0x484B4600 \n"
"dword_FF081090  DCD 0x3870600 \n"
"dword_FF081094  DCD 0x39D8 \n"
"dword_FF081098  DCD 0x20F000 \n"
"dword_FF08109C  DCD 0xFF080B18 \n"
"dword_FF0810A0  DCD 0xFF080818 \n"
"dword_FF0810A4  DCD 0xFF080460 \n"
"dword_FF0810A8  DCD 0xFF49F090 \n"
"dword_FF0810AC  DCD 0xFF080454 \n"
"dword_FF0810B0  DCD 0x86B \n"
"loc_FF0810B4:\n"
      "    LDR     R0, [SP, #0x48] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FF0810C8 \n" 
"loc_FF0810C0:\n"
      "    MOV     R1, #1 \n" 
      "    B       loc_FF081220 \n" 
"loc_FF0810C8:\n"
      "    MOV     R0, #1 \n" 
      "    BL      sub_FF192A14 \n" 
      "    BL      sub_FF192AC0 \n" 
      "    MOV     R0, #5 \n" 
      "    STR     R6, [R5, #0x34]! \n" 
      "    STR     R0, [R5, #0x10] \n" 
"loc_FF0810E0:\n"
      "    ADD     SP, SP, #0x50 \n" 
      "    LDMFD   SP!, {R4-R8,PC} \n" 
"loc_FF0810E8:\n"
      "    CMP     R7, #1 \n" 
      "    BNE     loc_FF081334 \n" 
      "    MOV     R0, #1 \n" 
      "    STR     R0, [R5, #0x38] \n" 
      "    LDR     R0, [R5, #0x6C] \n" 
      "    LDR     R7, [R4, #0xC] \n" 
      "    CMP     R0, #0 \n" 
      "    LDRNE   R8, [SP, #0x40] \n" 
      "    LDRNE   R12, [SP, #0x44] \n" 
      "    BNE     loc_FF0811A0 \n" 
      "    LDR     R0, [R4, #0x20] \n" 
      "    LDR     R2, [R5, #0x64] \n" 
      "    ADD     R3, SP, #0x48 \n" 
      "    MVN     R1, #0 \n" 
      "    ADD     R8, SP, #0x1C \n" 
      "    STMIA   R8, {R0-R3} \n" 
      "    LDR     R3, [R4, #0x1C] \n" 
      "    LDR     R1, [R5, #0x74] \n" 
      "    LDR     R2, [R5, #0x78] \n" 
      "    ADD     R0, SP, #0x4C \n" 
      "    ADD     R8, SP, #0xC \n" 
      "    STMIA   R8, {R0-R3} \n" 
      "    LDR     R1, [SP, #0x3C] \n" 
      "    LDR     R2, [SP, #0x40] \n" 
      "    LDR     R3, [SP, #0x38] \n" 
      "    STMFA   SP, {R1,R3} \n" 
      "    STR     R2, [SP] \n" 
      "    LDMIB   R4, {R0,R1} \n" 
      "    LDR     R3, [SP, #0x44] \n" 
      "    MOV     R2, R7 \n" 
      "    BL      sub_FF192968 \n" 
      "    LDR     R0, [R5, #0x1C] \n" 
      "    LDR     R1, [R5, #0x60] \n" 
      "    BL      sub_0068AA1C \n" 
      "    CMP     R0, #9 \n" 
      "    BEQ     loc_FF081040 \n" 
      "    LDR     R0, [SP, #0x48] \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF0810C0 \n" 
      "    MOV     R0, #1 \n" 
      "    BL      sub_FF192A14 \n" 
      "    LDR     R0, [SP, #0x4C] \n" 
      "    LDR     R1, [SP, #0x44] \n" 
      "    ADD     R12, R1, R0 \n" 
      "    LDR     R1, [SP, #0x40] \n" 
      "    SUB     R8, R1, R0 \n" 
"loc_FF0811A0:\n"
      "    LDR     R0, [R4, #0x20] \n" 
      "    LDR     R1, [R5, #0x68] \n" 
      "    LDR     R2, [R5, #0x64] \n" 
      "    ADD     R3, SP, #0x48 \n" 
      "    ADD     LR, SP, #0x1C \n" 
      "    STMIA   LR, {R0-R3} \n" 
      "    LDR     R3, [R4, #0x1C] \n" 
      "    LDR     R1, [R5, #0x74] \n" 
      "    LDR     R2, [R5, #0x78] \n" 
      "    ADD     R0, SP, #0x4C \n" 
      "    ADD     LR, SP, #0xC \n" 
      "    STMIA   LR, {R0-R3} \n" 
      "    LDR     R2, [SP, #0x3C] \n" 
      "    LDR     R3, [SP, #0x38] \n" 
      "    STMFA   SP, {R2,R3} \n" 
      "    STR     R8, [SP] \n" 
      "    LDMIB   R4, {R0,R1} \n" 
      "    MOV     R3, R12 \n" 
      "    MOV     R2, R7 \n" 
      "    BL      sub_FF192968 \n" 
      "    LDR     R0, [R5, #0x1C] \n" 
      "    LDR     R1, [R5, #0x60] \n" 
      "    BL      sub_0068AA1C \n" 
      "    CMP     R0, #9 \n" 
      "    BNE     loc_FF081210 \n" 
      "    MOV     R1, #0 \n" 
"loc_FF081208:\n"
      "    MOV     R0, #0x90000 \n" 
      "    B       loc_FF081224 \n" 
"loc_FF081210:\n"
      "    LDR     R0, [SP, #0x48] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FF08122C \n" 
      "    MOV     R1, #0 \n" 
"loc_FF081220:\n"
      "    MOV     R0, #0xA0000 \n" 
"loc_FF081224:\n"
      "    BL      sub_FF07EE44 \n" 
      "    B       loc_FF0810E0 \n" 
"loc_FF08122C:\n"
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF192A14 \n" 
      "    LDR     R0, [R5, #0x144] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FF0812BC \n" 
      "    LDR     R0, [R5, #0x68] \n" 
      "    LDR     R1, [R5, #0x64] \n" 
      "    BL      sub_0069092C \n" 
      "    MOVS    R4, R1 \n" 
      "    STREQ   R6, [R5, #0x144] \n" 
      "    BEQ     loc_FF0812BC \n" 
      "    LDR     R7, [SP, #0x44] \n" 
      "    MOV     R2, #4 \n" 
      "    ADD     R1, R7, #4 \n" 
      "    ADD     R0, SP, #0x34 \n" 
      "    BL      sub_00690174 \n" 
      "    LDR     R0, [SP, #0x34] \n" 
      "    MOV     R1, R0, LSR #0x18 \n" 
      "    AND     R2, R0, #0xFF0000 \n" 
      "    ORR     R1, R1, R2, LSR #8 \n" 
      "    AND     R2, R0, #0xFF00 \n" 
      "    ORR     R1, R1, R2, LSL #8 \n" 
      "    ORR     R0, R1, R0, LSL #0x18 \n" 
      "    BIC     R0, R0, #0x1E000 \n" 
      "    ORR     R0, R0, R4, LSL #0xD \n" 
      "    MOV     R1, R0, LSR #0x18 \n" 
      "    AND     R2, R0, #0xFF0000 \n" 
      "    ORR     R1, R1, R2, LSR #8 \n" 
      "    AND     R2, R0, #0xFF00 \n" 
      "    ORR     R1, R1, R2, LSL #8 \n" 
      "    ORR     R0, R1, R0, LSL #0x18 \n" 
      "    STR     R0, [SP, #0x34] \n" 
      "    MOV     R2, #4 \n" 
      "    ADD     R1, SP, #0x34 \n" 
      "    ADD     R0, R7, #4 \n" 
      "    BL      sub_00690174 \n" 
"loc_FF0812BC:\n"
      "    LDR     R0, [SP, #0x44] \n" 
      "    LDR     R1, [SP, #0x4C] \n" 
      "    BL      sub_FF1EF054 \n" 
      "    LDR     R0, [R5, #0x68] \n" 
      "    LDR     R3, =0x3928 \n" 
      "    ADD     R1, R0, #1 \n" 
      "    STR     R1, [R5, #0x68] \n" 
      "    LDR     R0, [SP, #0x4C] \n" 
      "    SUB     R2, R3, #4 \n" 
      "    BL      sub_FF1E9D6C \n" 
      "    LDR     R0, [R5, #0x64] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FF081340 \n" 
      "    ADD     R0, SP, #0x30 \n" 
      "    BL      sub_FF1963C4 \n" 
      "    LDR     R1, =0x4394C \n" 
      "    LDR     R0, [R1, #4] \n" 
      "    LDR     R1, [R1] \n" 
      "    SUB     R2, R0, #0x400 \n" 
      "    SUBS    R2, R2, #0x38 \n" 
      "    ADDEQ   R0, R0, #8 \n" 
      "    MOV     R1, R1, LSR #4 \n" 
      "    MOV     R0, R0, LSR #4 \n" 
      "    MUL     R1, R0, R1 \n" 
      "    LDR     R0, [SP, #0x30] \n" 
      "    BL      sub_0069092C \n" 
      "    LDR     R1, =0x4397C \n" 
      "    STR     R0, [SP, #0x30] \n" 
      "    BL      sub_FF1EA0A8 \n" 
      "    B       loc_FF081340 \n" 
"loc_FF081334:\n"
      "    LDRH    R0, [R5, #6] \n" 
      "    CMP     R0, #3 \n" 
      "    BNE     loc_FF0810E0 \n" 
"loc_FF081340:\n"
      "    LDR     R0, [R5, #0x6C] \n" 
      "    ADD     R0, R0, #1 \n" 
      "    STR     R0, [R5, #0x6C] \n" 
      "    LDRH    R1, [R5, #6] \n" 
      "    CMP     R1, #3 \n" 
      "    LDRNE   R1, [R5, #0x54] \n" 
      "    MULNE   R0, R1, R0 \n" 
      "    LDRNE   R1, [R5, #0x50] \n" 
      "    BNE     loc_FF081380 \n" 
      "    LDR     R1, [R5, #0x58] \n" 
      "    CMP     R1, #0x19 \n" 
      "    LDRNE   R1, =0x3E9 \n" 
      "    MOVEQ   R1, #0x3E8 \n" 
      "    MUL     R0, R1, R0 \n" 
      "    LDRNE   R1, =0x1770 \n" 
      "    LDREQ   R1, =0x1388 \n" 
"loc_FF081380:\n"
      "    BL      sub_0069092C \n" 
      "    MOV     R4, R0 \n" 
      "    BL      sub_FF1EF714 \n" 
      "    LDR     R0, [R5, #0x7C] \n" 
      "    CMP     R0, R4 \n" 
      "    BNE     loc_FF0813A4 \n" 
      "    LDR     R0, [R5, #0x3C] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FF0813B8 \n" 
"loc_FF0813A4:\n"
      "    LDR     R1, [R5, #0xA8] \n" 
      "    MOV     R0, R4 \n" 
      "    BLX     R1 \n" 
      "    STR     R4, [R5, #0x7C] \n" 
      "    STR     R6, [R5, #0x3C] \n" 
"loc_FF0813B8:\n"
      "    STR     R6, [R5, #0x38] \n" 
      "    B       loc_FF0810E0 \n" 
 );
}


  