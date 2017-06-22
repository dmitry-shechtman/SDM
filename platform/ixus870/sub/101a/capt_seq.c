#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

// via _sub_FF935BCC__SsCaptureSeq.c__0
static long *nrflag = (long*)0x9268; // see 0xFF935C3C

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) capt_seq_task() {
 // _sub_FF868B98__SsShootTask.c__13 (via taskcreate_CaptSeqTask)
 asm volatile (
                 "STMFD   SP!, {R3-R9,LR}\n"
                 "LDR     R6, =0x52F0\n"
                 "LDR     R4, =0x1AF4C\n"
                 "MOV     R9, #1\n"
                 "MOV     R7, #0\n"
 "loc_FF861D10:\n"
                 "LDR     R0, [R6,#0xC]\n"
                 "MOV     R2, #0\n"
                 "MOV     R1, SP\n"
                 "BL      sub_FF827098\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FF861D3C\n"
                 "LDR     R1, =0x539\n"
                 "LDR     R0, =0xFF861840\n"
                 "BL      sub_FF81B1CC\n"
                 "BL      sub_FF81B184\n"
                 "LDMFD   SP!, {R3-R9,PC}\n"
 "loc_FF861D3C:\n"
                 "LDR     R0, [SP]\n"
                 "LDR     R1, [R0]\n"
                 "CMP     R1, #0x1F\n"
                 "ADDLS   PC, PC, R1,LSL#2\n"
                 "B       loc_FF861FA0\n"
 "loc_FF861D50:\n"
                 "B       loc_FF861DD0\n"
 "loc_FF861D54:\n"
                 "B       loc_FF861E34\n"
 "loc_FF861D58:\n"
                 "B       loc_FF861E3C\n"
 "loc_FF861D5C:\n"
                 "B       loc_FF861E54\n"
 "loc_FF861D60:\n"
                 "B       loc_FF861E48\n"
 "loc_FF861D64:\n"
                 "B       loc_FF861E5C\n"
 "loc_FF861D68:\n"
                 "B       loc_FF861E64\n"
 "loc_FF861D6C:\n"
                 "B       loc_FF861E6C\n"
 "loc_FF861D70:\n"
                 "B       loc_FF861EC4\n"
 "loc_FF861D74:\n"
                 "B       loc_FF861EEC\n"
 "loc_FF861D78:\n"
                 "B       loc_FF861ED0\n"
 "loc_FF861D7C:\n"
                 "B       loc_FF861EDC\n"
 "loc_FF861D80:\n"
                 "B       loc_FF861EE4\n"
 "loc_FF861D84:\n"
                 "B       loc_FF861EF4\n"
 "loc_FF861D88:\n"
                 "B       loc_FF861EFC\n"
 "loc_FF861D8C:\n"
                 "B       loc_FF861F04\n"
 "loc_FF861D90:\n"
                 "B       loc_FF861F0C\n"
 "loc_FF861D94:\n"
                 "B       loc_FF861F14\n"
 "loc_FF861D98:\n"
                 "B       loc_FF861F1C\n"
 "loc_FF861D9C:\n"
                 "B       loc_FF861F24\n"
 "loc_FF861DA0:\n"
                 "B       loc_FF861F30\n"
 "loc_FF861DA4:\n"
                 "B       loc_FF861F38\n"
 "loc_FF861DA8:\n"
                 "B       loc_FF861F40\n"
 "loc_FF861DAC:\n"
                 "B       loc_FF861F48\n"
 "loc_FF861DB0:\n"
                 "B       loc_FF861F50\n"
 "loc_FF861DB4:\n"
                 "B       loc_FF861F5C\n"
 "loc_FF861DB8:\n"
                 "B       loc_FF861F64\n"
 "loc_FF861DBC:\n"
                 "B       loc_FF861F6C\n"
 "loc_FF861DC0:\n"
                 "B       loc_FF861F74\n"
 "loc_FF861DC4:\n"
                 "B       loc_FF861F7C\n"
 "loc_FF861DC8:\n"
                 "B       loc_FF861F88\n"
 "loc_FF861DCC:\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861DD0:\n"
                 "BL      sub_FF8625F4\n"
                 "BL      shooting_expo_param_override\n"  // +
                 "BL      sub_FF85FDFC\n"

 //  this code added to avoid some incorrect behavior if overrides are used.
 //  but it can cause some unexpected side effects. In this case, remove this code!
/*
                 "MOV     R0, #0\n"
                 "STR     R0, [R4,#0x24]\n"  // fixes overrides  behavior at short shutter press
 */	
 //  end of my code

                 "LDR     R0, [R4,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF861FAC\n"
                 "BL      sub_FF861518\n"
                 "MOV     R5, R0\n"
                 "LDR     R0, [R4,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF861E18\n"
                 "MOV     R0, #0xC\n"
                 "BL      sub_FF865A7C\n"
                 "TST     R0, #1\n"
                 "STRNE   R9, [R6,#4]\n"
                 "LDRNE   R0, [R5,#8]\n"
                 "ORRNE   R0, R0, #0x40000000\n"
                 "STRNE   R0, [R5,#8]\n"
                 "BNE     loc_FF861FAC\n"
 "loc_FF861E18:\n"
                 "MOV     R0, R5\n"
                 "BL      sub_FF8617C4\n"
                 "MOV     R0, R5\n"
                 "BL      sub_FF935BCC_my\n"             // ----------->
                 "BL      capt_seq_hook_raw_here\n"      // +
                 "TST     R0, #1\n"
                 "STRNE   R9, [R6,#4]\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861E34:\n"
"     BL    shooting_set_flash_override\n"
                 "BL      sub_FF8620C4_my\n"             // ----------->
                 "B       loc_FF861E4C\n"
 "loc_FF861E3C:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF86280C\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861E48:\n"
                 "BL      sub_FF862258\n"
 "loc_FF861E4C:\n"
                 "STR     R7, [R4,#0x24]\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861E54:\n"
                 "BL      sub_FF8625D4\n"
                 "B       loc_FF861E4C\n"
 "loc_FF861E5C:\n"
                 "BL      sub_FF8625DC\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861E64:\n"
                 "BL      sub_FF86272C\n"
                 "B       loc_FF861EC8\n"
 "loc_FF861E6C:\n"
                 "LDR     R5, [R0,#0xC]\n"
                 "BL      sub_FF8625E4\n"
                 "MOV     R0, R5\n"
                 "BL      sub_FF934B7C\n"
                 "TST     R0, #1\n"
                 "MOV     R8, R0\n"
                 "BNE     loc_FF861EAC\n"
                 "BL      sub_FF871938\n"
                 "STR     R0, [R5,#0x18]\n"
                 "MOV     R0, R5\n"
                 "BL      sub_FF935A88\n"
                 "MOV     R0, R5\n"
                 "BL      sub_FF935E94\n"
                 "MOV     R8, R0\n"
                 "LDR     R0, [R5,#0x18]\n"
                 "BL      sub_FF871B4C\n"
 "loc_FF861EAC:\n"
                 "BL      sub_FF8625D4\n"
                 "MOV     R2, R5\n"
                 "MOV     R1, #9\n"
                 "MOV     R0, R8\n"
                 "BL      sub_FF860288\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861EC4:\n"
                 "BL      sub_FF86278C\n"
 "loc_FF861EC8:\n"
                 "BL      sub_FF85FDFC\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861ED0:\n"
                 "LDR     R0, [R4,#0x54]\n"
                 "BL      sub_FF862BA0\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861EDC:\n"
                 "BL      sub_FF862E50\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861EE4:\n"
                 "BL      sub_FF862EE0\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861EEC:\n"
                 "BL      sub_FF8625D4\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861EF4:\n"
                 "BL      sub_FF934D98\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861EFC:\n"
                 "BL      sub_FF934F80\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F04:\n"
                 "BL      sub_FF935010\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F0C:\n"
                 "BL      sub_FF9350C4\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F14:\n"
                 "BL      sub_FF9352C4\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F1C:\n"
                 "BL      sub_FF93531C\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F24:\n"
                 "MOV     R0, #0\n"
                 "BL      sub_FF9353A4\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F30:\n"
                 "BL      sub_FF9354DC\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F38:\n"
                 "BL      sub_FF93556C\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F40:\n"
                 "BL      sub_FF93562C\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F48:\n"
                 "BL      sub_FF86298C\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F50:\n"
                 "BL      sub_FF862A2C\n"
                 "BL      sub_FF824944\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F5C:\n"
                 "BL      sub_FF935180\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F64:\n"
                 "BL      sub_FF9351EC\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F6C:\n"
                 "BL      sub_FF864438\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F74:\n"
                 "BL      sub_FF8644A0\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F7C:\n"
                 "BL      sub_FF8644FC\n"
                 "BL      sub_FF8644BC\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861F88:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF9366B4\n"
                 "LDRH    R0, [R4,#0x8C]\n"
                 "CMP     R0, #3\n"
                 "BLNE    sub_FF8646F8\n"
                 "B       loc_FF861FAC\n"
 "loc_FF861FA0:\n"
                 "LDR     R1, =0x65E\n"
                 "LDR     R0, =0xFF861840\n"
                 "BL      sub_FF81B1CC\n"
 "loc_FF861FAC:\n"
                 "LDR     R0, [SP]\n"
                 "LDR     R1, [R0,#4]\n"
                 "LDR     R0, [R6,#8]\n"
                 "BL      sub_FF8694D4\n"
                 "LDR     R5, [SP]\n"
                 "LDR     R0, [R5,#8]\n"
                 "CMP     R0, #0\n"
                 "LDREQ   R1, =0x11D\n"
                 "LDREQ   R0, =0xFF861840\n"
                 "BLEQ    sub_FF81B1CC\n"
                 "STR     R7, [R5,#8]\n"
                 "B       loc_FF861D10\n"
 );
} 



void __attribute__((naked,noinline)) sub_FF8620C4_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R6,LR}\n"
                 "LDR     R4, [R0,#0xC]\n"
                 "LDR     R6, =0x1AF4C\n"
                 "LDR     R0, [R4,#8]\n"
                 "MOV     R5, #0\n"
                 "ORR     R0, R0, #1\n"
                 "STR     R0, [R4,#8]\n"
                 "LDR     R0, [R6,#0x24]\n"
                 "CMP     R0, #0\n"
                 "MOVEQ   R0, #2\n"
                 "BLEQ    sub_FF85BF28\n"
                 "BL      sub_FF8625E4\n"
                 "LDR     R0, [R6,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF862174\n"
                 "MOV     R0, #0\n"
                 "BL      sub_FF9366B4\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF862934\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF9347C4\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF862144\n"
                 "BL      sub_FF9366F4\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF9348A8\n"
                 "TST     R0, #1\n"
                 "MOVNE   R2, R4\n"
                 "LDMNEFD SP!, {R4-R6,LR}\n"
                 "MOVNE   R1, #1\n"
                 "BNE     sub_FF860288\n"
                 "B       loc_FF862150\n"
 "loc_FF862144:\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF934844\n"
                 "BL      sub_FF9366F4\n"
 "loc_FF862150:\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF8617C4\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF935A88\n"
                 "BL      sub_FF936544\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF935BCC_my\n"             //----------->
                 "MOV     R5, R0\n"
                 "BL      capt_seq_hook_raw_here\n"      // +
                 "B       loc_FF862184\n"
 "loc_FF862174:\n"
                 "LDR     R0, =0x52F0\n"
                 "LDR     R0, [R0,#4]\n"
                 "CMP     R0, #0\n"
                 "MOVNE   R5, #0x1D\n"
 "loc_FF862184:\n"
                 "BL      sub_FF8644A0\n"
                 "BL      sub_FF8644E8\n"
                 "BL      sub_FF864528\n"
                 "MOV     R2, R4\n"
                 "MOV     R1, #1\n"
                 "MOV     R0, R5\n"
                 "BL      sub_FF860288\n"
                 "BL      sub_FF935E24\n"
                 "CMP     R0, #0\n"
                 "LDRNE   R0, [R4,#8]\n"
                 "ORRNE   R0, R0, #0x2000\n"
                 "STRNE   R0, [R4,#8]\n"
                 "LDMFD   SP!, {R4-R6,PC}\n"
 );
}



void __attribute__((naked,noinline)) sub_FF935BCC_my(){
 asm volatile(
                 "STMFD   SP!, {R1-R7,LR}\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FF936818\n"
                 "MVN     R1, #0x0\n"
                 "BL      sub_FF869508\n"
                 "MOV     R2, #4\n"
                 "ADD     R1, SP, #0x4\n"
                 "MOV     R0, #0x8A\n"
                 "BL      sub_FF8717A8\n"
                 "TST     R0, #1\n"
                 "LDRNE   R1, =0x373\n"
                 "LDRNE   R0, =0xFF935B98\n"
                 "BLNE    sub_FF81B1CC\n"
                 "LDR     R7, =0x1B00C\n"
                 "LDR     R6, =0x1AF4C\n"
                 "LDRSH   R1, [R7,#0xE]\n"
                 "LDR     R0, [R6,#0x88]\n"
                 "BL      sub_FF8F8F48\n"
                 "BL      sub_FF848C84\n"
                 "LDR     R3, =0x926C\n"
                 "STRH    R0, [R4,#0x94]\n"
                 "STR     R3, [SP]\n"
                 "MOV     R1, R0\n"
                 "LDRH    R0, [R6,#0x5C]\n"
                 "LDRSH   R2, [R7,#0xC]\n"
                 "SUB     R3, R3, #4\n"
                 "BL      sub_FF936E10\n"
                 "BL      wait_until_remote_button_is_released\n"     // +
                 "BL      capt_seq_hook_set_nr\n"                     // +
                 "B       sub_FF935C38\n"                             // continue function in firmware
 );
}

