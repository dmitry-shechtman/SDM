#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"
static long *nrflag = (long*)(0x873c+0x00);  // Found @ ff9df3a8 & ff9df408 a810
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

#define PAUSE_FOR_FILE_COUNTER 150           // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF86ECA8 

void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
      "STMFD   SP!, {R3-R7,LR} \n"
      "LDR     R5, =0x36C14 \n"
      "LDR     R6, =0x2ACC \n"
"loc_FF86ECB4:\n"
      "MOV     R2, #0 \n"
      "LDR     R0, [R6, #4] \n"
      "MOV     R1, SP \n"
      "BL      sub_003F7218 \n" // RAM
      "TST     R0, #1 \n"
      "BEQ     loc_FF86ECE0 \n"
      "LDR     R1, =0x493 \n"
      "LDR     R0, =0xFF86E814 \n" // **"SsShootTask.c"
      "BL      _DebugAssert \n"
      "BL      _ExitTask \n"
      "LDMFD   SP!, {R3-R7,PC} \n"
"loc_FF86ECE0:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0] \n"
      "CMP     R1, #0x20 \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF86EF20 \n"
      "B       loc_FF86ED74 \n"
      "B       loc_FF86ED7C \n"
      "B       loc_FF86EDE0 \n"
      "B       loc_FF86EDF4 \n"
      "B       loc_FF86EDEC \n"
      "B       loc_FF86EDFC \n"
      "B       loc_FF86EE04 \n"
      "B       loc_FF86EE10 \n"
      "B       loc_FF86EE2C \n"
      "B       loc_FF86EDF4 \n"
      "B       loc_FF86EE34 \n"
      "B       loc_FF86EE40 \n"
      "B       loc_FF86EE48 \n"
      "B       loc_FF86EE54 \n"
      "B       loc_FF86EE5C \n"
      "B       loc_FF86EE64 \n"
      "B       loc_FF86EE6C \n"
      "B       loc_FF86EE74 \n"
      "B       loc_FF86EE80 \n"
      "B       loc_FF86EE88 \n"
      "B       loc_FF86EE90 \n"
      "B       loc_FF86EE98 \n"
      "B       loc_FF86EEA0 \n"
      "B       loc_FF86EEAC \n"
      "B       loc_FF86EEB4 \n"
      "B       loc_FF86EEBC \n"
      "B       loc_FF86EEC4 \n"
      "B       loc_FF86EECC \n"
      "B       loc_FF86EED8 \n"
      "B       loc_FF86EEE0 \n"
      "B       loc_FF86EEEC \n"
      "B       loc_FF86EF2C \n"
"loc_FF86ED74:\n"  // jump table entry 0
      "BL      sub_FF86F50C \n"
      "BL      shooting_expo_param_override\n"      // added     
      "B       loc_FF86EE08 \n"
"loc_FF86ED7C:\n" // jump table entry 1
"     BL    shooting_set_flash_override\n"
      "LDR     R4, [R0, #0x10] \n"
      "LDR     R0, [R5, #0x84] \n"
      "TST     R0, #0x30 \n"
      "BLNE    sub_FF87066C \n"
      "BL      sub_FF87034C \n"
      "MOV     R1, R4 \n"
      "BL      sub_FF8703A4 \n"
      "LDR     R0, =0x10F \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R4, #0x24 \n"
      "BL      sub_FF87E744 \n"
      "MOV     R2, #4 \n"
      "ADD     R1, R4, #0x28 \n"
      "MOV     R0, #0x2C \n"
      "BL      sub_FF87E744 \n"
      "MOV     R0, R4 \n"
//      "BL      sub_FF960B9C \n" //original
      "BL      sub_FF960B9C_my \n" //patched
      "BL      capt_seq_hook_raw_here \n" // patch
      "MOV     R7, R0 \n"
      "MOV     R2, R4 \n"
      "MOV     R1, #1 \n"
      "BL      sub_FF86D0F8 \n"
      "TST     R7, #1 \n"
      "MOVEQ   R0, R4 \n"
      "BLEQ    sub_FF9605A4 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDE0:\n" // jump table entry 2
      "MOV     R0, #1 \n"
      "BL      sub_FF86F7D0 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDEC:\n"
      "BL      sub_FF86F154 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDF4:\n"
      "BL      sub_FF86F4EC \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EDFC:\n"
      "BL      sub_FF86F4F4 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE04:\n"
      "BL      sub_FF86F6B8 \n"
"loc_FF86EE08:\n"
      "BL      sub_FF86CC78 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE10:\n"
      "LDR     R4, [R0, #0x10] \n"
      "MOV     R0, R4 \n"
      "BL      sub_FF960CA0 \n"
      "MOV     R2, R4 \n"
      "MOV     R1, #9 \n"
      "BL      sub_FF86D0F8 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE2C:\n"
      "BL      sub_FF86F738 \n"
      "B       loc_FF86EE08 \n"
"loc_FF86EE34:\n"
      "LDR     R0, [R5, #0x50] \n"
      "BL      sub_FF86FB70 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE40:\n"
      "BL      sub_FF86FF08 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE48:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF86FF6C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE54:\n"
      "BL      sub_FF95F974 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE5C:\n"
      "BL      sub_FF95FBD4 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE64:\n"
      "BL      sub_FF95FC8C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE6C:\n"
      "BL      sub_FF95FD60 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE74:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF95FFC0 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE80:\n"
      "BL      sub_FF960130 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE88:\n"
      "BL      sub_FF9601C4 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE90:\n"
      "BL      sub_FF96027C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EE98:\n"
      "BL      sub_FF86F94C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEA0:\n"
      "BL      sub_FF86F978 \n"
      "BL      sub_FF830FB0 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEAC:\n"
      "BL      sub_FF95FE30 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEB4:\n"
      "BL      sub_FF95FE70 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEBC:\n"
      "BL      sub_FF871844 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEC4:\n"
      "BL      sub_FF8718B8 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EECC:\n"
      "LDR     R0, [R0, #0xC] \n"
      "BL      sub_FF960394 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EED8:\n"
      "BL      sub_FF960404 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEE0:\n"
      "BL      sub_FF871920 \n"
      "BL      sub_FF8718D8 \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EEEC:\n"
      "MOV     R0, #1 \n"
      "BL      sub_FF9613B8 \n"
      "MOV     R0, #1 \n"
      "BL      sub_FF9614E0 \n"
      "LDRH    R0, [R5, #0x94] \n"
      "CMP     R0, #4 \n"
      "LDRNEH  R0, [R5] \n"
      "SUBNE   R1, R0, #0x8200 \n"
      "SUBNES  R1, R1, #0x2E \n"
      "BNE     loc_FF86EF2C \n"
      "BL      sub_FF8718B8 \n"
      "BL      sub_FF871D7C \n"
      "B       loc_FF86EF2C \n"
"loc_FF86EF20:\n"
      "LDR     R1, =0x5F4 \n"
      "LDR     R0, =0xFF86E814 \n" // *"SsShootTask.c"
      "BL      _DebugAssert \n"
"loc_FF86EF2C:\n"
      "LDR     R0, [SP] \n"
      "LDR     R1, [R0, #4] \n"
      "LDR     R0, [R6] \n"
      "BL      sub_003FAC6C \n" // RAM
      "LDR     R4, [SP] \n"
      "LDR     R0, [R4, #8] \n"
      "CMP     R0, #0 \n"
      "LDREQ   R1, =0x117 \n"
      "LDREQ   R0, =0xFF86E814 \n" // *"SsShootTask.c"
      "BLEQ    _DebugAssert \n"
      "MOV     R0, #0 \n"
      "STR     R0, [R4, #8] \n"
      "B       loc_FF86ECB4 \n"
	);
}

//**  sub_FF960B9C_my  @ 0xFF960B9C

void __attribute__((naked,noinline)) sub_FF960B9C_my() {
asm volatile (
      "STMFD   SP!, {R3-R5,LR} \n"
      "MOV     R5, R0 \n"
      "MOV     R0, #0xC \n"
      "BL      sub_FF873300 \n"
      "TST     R0, #1 \n"
      "MOVNE   R0, #1 \n"
      "BNE     sub_FF960C9C \n"
      "BL      sub_FF86F4FC \n"
      "MOV     R0, R5 \n"
      "BL      sub_FF9604F4 \n"
      "TST     R0, #1 \n"
      "BNE     sub_FF960C9C \n"
      "LDR     R4, =0x36C14 \n"
      "LDR     R0, [R4, #0x84] \n"
      "AND     R0, R0, #0x40 \n"
      "CMP     R0, #0 \n"
      "LDRNEH  R0, [R4, #0x92] \n"
      "CMPNE   R0, #3 \n"
      "LDRNE   R0, [R5, #8] \n"
      "CMPNE   R0, #1 \n"
      "BLS     loc_FF960C0C \n"
      "BL      sub_FF9616A0 \n"
      "MOV     R3, #0xC0 \n"
      "STR     R3, [SP] \n"
      "LDR     R2, =0x3A98 \n"
      "LDR     R3, =0xFF960D2C \n" //SsCaptureSeq.c
      "MOV     R1, #0x8000 \n"
      "BL      sub_FF873568 \n"
"loc_FF960C0C:\n"
      "MOV     R0, R5 \n"
      "BL      sub_FF9607DC \n"
      "BL      sub_FF961198 \n"     
      "BL      wait_until_remote_button_is_released \n"  //before shoot XXX
      "BL      capt_seq_hook_set_nr \n"      
      "LDR     R0, [R4, #0x84] \n"
      "TST     R0, #0x40 \n"
      "BEQ     sub_FF960C80 \n"
      "LDR     R0, =0x181 \n"
      "MOV     R2, #4 \n"
      "MOV     R1, SP \n"
      "BL      _GetPropertyCase \n"
      "TST     R0, #1 \n"
      "MOVNE   R1, #0xD4 \n"
      "LDRNE   R0, =0xFF960D2C \n" //SsCaptureSeq.c
      "BLNE    _DebugAssert \n" //RAM
      "LDR     R0, [SP] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF960C60 \n"
      "BL      sub_FF9616A0 \n"
      "MOV     R1, #0x8000 \n"
      "BL      sub_003FAC6C \n" //RAM 
      "B       sub_FF960C80 \n"
"loc_FF960C60:\n"
      "BL      sub_FF9616A0 \n"
      "MOV     R1, #0x8000 \n"
      "BL      sub_003FACA0 \n" // RAM
      "LDR     R2, =0xFF960B88 \n"
      "LDR     R0, [SP] \n"
      "MOV     R3, #0x8000 \n"
      "ADD     R1, R2, #0 \n"
      "BL      sub_FF833200 \n"
      "LDR     R0, [R4, #0x84] \n"
      "TST     R0, #0x10 \n"
      "MOV     R0, R5 \n"
      "LDMEQFD SP!, {R3-R5,LR} \n"
	);
}
