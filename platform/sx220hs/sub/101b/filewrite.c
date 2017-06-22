
#include "lolevel.h"
#include "platform.h"

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFF2DB3E0 - 0xFF2DB4C0, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R5, =0xD0C8 \n"

"loc_FF2DB3E8:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF02AD50 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #0x348 \n"
"    LDRNE   R0, =0xFF2DB4E0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xA \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF2DB3E8 \n"
"    B       loc_FF2DB4B4 \n"
"    B       loc_FF2DB4B4 \n"
"    B       loc_FF2DB4B4 \n"
"    B       loc_FF2DB4B4 \n"
"    B       loc_FF2DB4B4 \n"
"    B       loc_FF2DB4B4 \n"
"    B       loc_FF2DB4B4 \n"
"    B       loc_FF2DB4BC \n"
"    B       loc_FF2DB444 \n"
"    B       loc_FF2DB4AC \n"

"loc_FF2DB444:\n"
"    MOV     R0, #0 \n"
"    MOV     R4, R5 \n"
"    STR     R0, [SP] \n"

"loc_FF2DB450:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02AF94 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF2DB47C \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02AD50 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF2DB450 \n"

"loc_FF2DB47C:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF2DB4A0 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x114E58 \n"
"    BL      sub_FF06AF88 \n"
"    BL      sub_FF069180 \n"

"loc_FF2DB4A0:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF2DB3E8 \n"

"loc_FF2DB4AC:\n"
"    BL      sub_FF2DB12C_my \n"  // --> Patched. Old value = 0xFF2DB12C.
"    B       loc_FF2DB3E8 \n"

"loc_FF2DB4B4:\n"
"    BL      sub_FF2DB6BC_my \n"  // --> Patched. Old value = 0xFF2DB6BC.
"    B       loc_FF2DB3E8 \n"

"loc_FF2DB4BC:\n"
"    BL      sub_FF2DB26C_my \n"  // --> Patched. Old value = 0xFF2DB26C.
"    B       loc_FF2DB3E8 \n"
);
}

/*************************************************************/
//** sub_FF2DB12C_my @ 0xFF2DB12C - 0xFF2DB184, length=23
void __attribute__((naked,noinline)) sub_FF2DB12C_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0x3C \n"
"    ADD     R0, R0, #0x50 \n"
"    BL      sub_FF06AF88 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF069118 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF00033C \n"
"    LDR     R0, [R4, #0x4C] \n"
"    ADD     R7, R4, #0x50 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
"    LDR     R8, [R4, #8] \n"
"    BL      sub_FF18D07C \n"
"    LDR     R9, =0x1B6 \n"
"    MOV     R1, R8 \n"
"    MOV     R2, R9 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFF2DB188 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2DB6BC_my @ 0xFF2DB6BC - 0xFF2DB73C, length=33
void __attribute__((naked,noinline)) sub_FF2DB6BC_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF2DB6E8 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF2DB700 \n"
"    B       loc_FF2DB6F4 \n"

"loc_FF2DB6E8:\n"
"    LDR     R1, =0x2A2 \n"
"    LDR     R0, =0xFF2DB4E0 \n"
"    BL      _DebugAssert \n"

"loc_FF2DB6F4:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FF2DB794 \n"

"loc_FF2DB700:\n"
"    LDR     R9, =0xD0C8 \n"
"    MOV     R4, R7 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  
"    LDR     PC, =0xFF2DB740 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2DB26C_my @ 0xFF2DB26C - 0xFF2DB2A0, length=14
void __attribute__((naked,noinline)) sub_FF2DB26C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xD0C8 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF2DB2B4 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FF2DB2A0 \n"
"    BL      sub_FF027134 \n"
"    B       sub_FF2DB2A4 \n"

"loc_FF2DB2A0:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF2DB2A4 \n"  // Continue in firmware
);
}
