#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"
#define LED_AF 0xC02200F4
static long *nrflag = (long*)(0x6b30+0x08);  // Found @ ff970fcc & ff971010
#define NR_AUTO (0)                         // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 100          // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF87AA8C 

void __attribute__((naked,noinline)) capt_seq_task(  ) { 
asm volatile (
      "STMFD   SP!, {R3-R9,LR}\n"
      "LDR     R5, =0x3A27C\n"
      "LDR     R7, =0x2B90\n"
      "MOV     R6, #0\n"
"loc_FF87AA9C:\n"
      "LDR     R0, [R7, #4]\n"
      "MOV     R2, #0\n"
      "MOV     R1, SP\n"
      "BL      sub_FF839B84\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF87AAC8\n"
      "LDR     R1, =0x476\n"
      "LDR     R0, =0xFF87A62C\n"
      "BL      _DebugAssert\n"
      "BL      sub_FF81EC40\n"
      "LDMFD   SP!, {R3-R9,PC}\n"
"loc_FF87AAC8:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x20\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF87ACE8\n"
      "B       loc_FF87AB5C\n"
      "B       loc_FF87AB74\n"
      "B       loc_FF87ABA0\n"
      "B       loc_FF87ABB4\n"
      "B       loc_FF87ABAC\n"
      "B       loc_FF87ABC0\n"
      "B       loc_FF87ABC8\n"
      "B       loc_FF87ABD0\n"
      "B       loc_FF87ABEC\n"
      "B       loc_FF87AC14\n"
      "B       loc_FF87ABF8\n"
      "B       loc_FF87AC04\n"
      "B       loc_FF87AC0C\n"
      "B       loc_FF87AC1C\n"
      "B       loc_FF87AC24\n"
      "B       loc_FF87AC2C\n"
      "B       loc_FF87AC34\n"
      "B       loc_FF87AC3C\n"
      "B       loc_FF87AC48\n"
      "B       loc_FF87AC50\n"
      "B       loc_FF87AC58\n"
      "B       loc_FF87AC60\n"
      "B       loc_FF87AC68\n"
      "B       loc_FF87AC74\n"
      "B       loc_FF87AC7C\n"
      "B       loc_FF87AC84\n"
      "B       loc_FF87AC8C\n"
      "B       loc_FF87AC94\n"
      "B       loc_FF87AC9C\n"
      "B       loc_FF87ACA4\n"
      "B       loc_FF87ACB0\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AB5C:\n"
      "BL		shooting_expo_iso_override \n"		// added
      "BL      sub_FF87B26C\n"
      "BL		shooting_expo_param_override \n"	// added
      "BL      sub_FF8786B8\n"
      "LDR     R0, [R5, #0x28]\n"
      "CMP     R0, #0\n"
      "BLNE    sub_FF96E9FC\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AB74:\n"
"     BL    shooting_set_flash_override\n"
      "LDR     R8, [R0, #0xC]\n"
      "MOV     R0, R8\n"
//      "BL      sub_FF96E91C\n"              //original
      "BL      sub_FF96E91C_my\n"             //patch
      "BL		 capt_seq_hook_raw_here \n"	  // added
      "MOV     R4, R0\n"
      "MOV     R2, R8\n"
      "MOV     R1, #1\n"
      "BL      sub_FF878CAC\n"
      "TST     R4, #1\n"
      "MOVEQ   R0, R8\n"
      "BLEQ    sub_FF96E3BC\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ABA0:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF87B50C\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ABAC:\n"
      "BL      sub_FF87AF00\n"
      "B       loc_FF87ABB8\n"
"loc_FF87ABB4:\n"
      "BL      sub_FF87B24C\n"
"loc_FF87ABB8:\n"
      "STR     R6, [R5, #0x28]\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ABC0:\n"
      "BL      sub_FF87B254\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ABC8:\n"
      "BL      sub_FF87B420\n"
      "B       loc_FF87ABF0\n"
"loc_FF87ABD0:\n"
      "LDR     R4, [R0, #0xC]\n"
      "MOV     R0, R4\n"
      "BL      sub_FF96EA50\n"
      "MOV     R2, R4\n"
      "MOV     R1, #9\n"
      "BL      sub_FF878CAC\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ABEC:\n"
      "BL      sub_FF87B484\n"
"loc_FF87ABF0:\n"
      "BL      sub_FF8786B8\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ABF8:\n"
      "LDR     R0, [R5, #0x58]\n"
      "BL      sub_FF87B950\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC04:\n"
      "BL      sub_FF87BCC8\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC0C:\n"
      "BL      sub_FF87BD2C\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC14:\n"
      "BL      sub_FF87B24C\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC1C:\n"
      "BL      sub_FF96D7C4\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC24:\n"
      "BL      sub_FF96D9D0\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC2C:\n"
      "BL      sub_FF96DA74\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC34:\n"
      "BL      sub_FF96DB44\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC3C:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF96DD4C\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC48:\n"
      "BL      sub_FF96DEC4\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC50:\n"
      "BL      sub_FF96DF68\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC58:\n"
      "BL      sub_FF96E048\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC60:\n"
      "BL      sub_FF87B678\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC68:\n"
      "BL      sub_FF87B6A4\n"
      "BL      sub_FF837A54\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC74:\n"
      "BL      sub_FF96DC08\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC7C:\n"
      "BL      sub_FF96DC48\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC84:\n"
      "BL      sub_FF87E034\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC8C:\n"
      "BL      sub_FF87E0A4\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC94:\n"
      "BL      sub_FF96E180\n"
      "B       loc_FF87ACF4\n"
"loc_FF87AC9C:\n"
      "BL      sub_FF96E1E4\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ACA4:\n"
      "BL      sub_FF87E100\n"
      "BL      sub_FF87E0C0\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ACB0:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF96F1C8\n"
      "MOV     R0, #1\n"
      "BL      sub_FF96F2F0\n"
      "LDRH    R0, [R5, #0x98]\n"
      "CMP     R0, #4\n"
      "LDRNEH  R0, [R5]\n"
      "SUBNE   R1, R0, #0x4200\n"
      "SUBNES  R1, R1, #0x2A\n"
      "BNE     loc_FF87ACF4\n"
      "BL      sub_FF87E0A4\n"
      "BL      sub_FF87E6A4\n"
      "BL      sub_FF87E524\n"
      "B       loc_FF87ACF4\n"
"loc_FF87ACE8:\n"
      "LDR     R1, =0x5D7\n"
      "LDR     R0, =0xFF87A62C\n"
      "BL      _DebugAssert\n"
"loc_FF87ACF4:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0, #4]\n"
      "LDR     R0, [R7]\n"
      "BL      sub_FF884CD0\n"
      "LDR     R4, [SP]\n"
      "LDR     R0, [R4, #8]\n"
      "CMP     R0, #0\n"
      "LDREQ   R0, =0xFF87A62C\n"
      "MOVEQ   R1, #0x118\n"
      "BLEQ    _DebugAssert\n"
      "STR     R6, [R4, #8]\n"
      "B       loc_FF87AA9C\n"
	);
}


//** sub_FF96E91C_my  @ 0xFF96E91C 

void __attribute__((naked,noinline)) sub_FF96E91C_my(  ) { 
asm volatile (
      "STMFD   SP!, {R3-R7,LR}\n"
      "LDR     R6, =0x3A27C\n"
      "MOV     R5, R0\n"
      "LDR     R0, [R6, #0x28]\n"
      "MOV     R4, #0\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF96E94C\n"
      "MOV     R0, #0xC\n"
      "BL      sub_FF87FBB8\n"
      "TST     R0, #1\n"
      "MOVNE   R0, #1\n"
      "BNE     loc_FF96E9F8\n"
"loc_FF96E94C:\n"
      "BL      sub_FF87B25C\n"
      "LDR     R0, [R6, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF96E9E0\n"
      "MOV     R0, R5\n"
      "BL      sub_FF96E2D0\n"
      "TST     R0, #1\n"
      "BNE     loc_FF96E9F8\n"
      "MOV     R0, R5\n"
      "BL      sub_FF96E644\n"
      "BL      sub_FF96EFA4\n"
      "MOV     R4, #1\n"
      "MOV     R0, #2\n"
      "BL      sub_FF881378\n"
      "BL      wait_until_remote_button_is_released \n"		// added
      "BL      capt_seq_hook_set_nr \n"						// added
      "LDRH    R0, [R6]\n"
      "SUB     R1, R0, #0x8200\n"
      "SUBS    R1, R1, #0x2D\n"
      "BNE     loc_FF96E9D0\n"
      "MOV     R2, #2\n"
      "MOV     R1, SP\n"
      "ADD     R0, R2, #0x15C\n"
      "STR     R4, [SP]\n"
      "BL      _GetPropertyCase\n"
      "TST     R0, #1\n"
      "MOVNE   R1, #0xBC\n"
      "LDRNE   R0, =0xFF96EAA8\n"
      "BLNE    _DebugAssert\n"
      "LDRH    R0, [SP]\n"
      "CMP     R0, #1\n"
      "STRHI   R4, [R5, #0xD4]\n"
      "BHI     loc_FF96E9F0\n"
      "MOV     R0, #0\n"
      "STR     R0, [R5, #0xD4]\n"
"loc_FF96E9D0:\n"
      "MOV     R0, R5\n"
      "BL      sub_FFAB514C\n"
      "MOV     R4, R0\n"
      "B       loc_FF96E9F4\n"
"loc_FF96E9E0:\n"
      "LDR     R0, =0x6ADC\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0\n"
      "BEQ     loc_FF96E9F4\n"
"loc_FF96E9F0:\n"
      "MOV     R4, #0x1D\n"
"loc_FF96E9F4:\n"
      "MOV     R0, R4\n"
"loc_FF96E9F8:\n"
      "LDMFD   SP!, {R3-R7,PC}\n"
	);
}

