#include "lolevel.h"
#include "platform.h"
#include "core.h"
static long *nrflag = (long*)(0x5a8c+0x08);  // Found @ ffd1d88c & ffd1d8d0 - both from stubs_entry.s
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 150          // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"		//here from defined NR_AUTO definido initializes nrflag


//ffc5b06c
void __attribute__((naked,noinline)) capt_seq_task() 
{
asm volatile (
      "    STMFD   SP!, {R3-R7,LR} \n" 
      "    LDR     R5, =0x33D88 \n" 
      "    LDR     R6, =0x2710 \n" 
"loc_FFC5B078:\n"
      "    MOV     R2, #0 \n" 
      "    LDR     R0, [R6, #4] \n" 
      "    MOV     R1, SP \n" 
      "    BL      sub_FFC2905C \n" 
      "    TST     R0, #1 \n" 
      "    BEQ     loc_FFC5B0A4 \n" 
      "    LDR     R1, =0x476 \n" 
      "    LDR     R0, =0xFFC5AC5C \n" 
      "    BL      sub_FFC0F768 \n" 
      "    BL      sub_FFC0F520 \n" 
      "    LDMFD   SP!, {R3-R7,PC} \n" 
"loc_FFC5B0A4:\n"
      "    LDR     R0, [SP] \n" 
      "    LDR     R1, [R0] \n" 
      "    CMP     R1, #0x1E \n" 
      "    ADDCC   PC, PC, R1, LSL #2 \n" 
      "    B       loc_FFC5B27C \n" 
      "    B       loc_FFC5B130 \n" 
      "    B       loc_FFC5B138 \n" 
      "    B       loc_FFC5B164 \n" 
      "    B       loc_FFC5B178 \n" 
      "    B       loc_FFC5B170 \n" 
      "    B       loc_FFC5B180 \n" 
      "    B       loc_FFC5B188 \n" 
      "    B       loc_FFC5B194 \n" 
      "    B       loc_FFC5B1B0 \n" 
      "    B       loc_FFC5B178 \n" 
      "    B       loc_FFC5B1B8 \n" 
      "    B       loc_FFC5B1C4 \n" 
      "    B       loc_FFC5B1CC \n" 
      "    B       loc_FFC5B1D4 \n" 
      "    B       loc_FFC5B1DC \n" 
      "    B       loc_FFC5B1E4 \n" 
      "    B       loc_FFC5B1EC \n" 
      "    B       loc_FFC5B1F4 \n" 
      "    B       loc_FFC5B200 \n" 
      "    B       loc_FFC5B208 \n" 
      "    B       loc_FFC5B210 \n" 
      "    B       loc_FFC5B218 \n" 
      "    B       loc_FFC5B220 \n" 
      "    B       loc_FFC5B22C \n" 
      "    B       loc_FFC5B234 \n" 
      "    B       loc_FFC5B23C \n" 
      "    B       loc_FFC5B244 \n" 
      "    B       loc_FFC5B24C \n" 
      "    B       loc_FFC5B258 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B130:\n"
  //  "    BL		shooting_expo_iso_override\n"  		// added - as ixus220 - but not defined for a800
      "    BL      sub_FFC5B7BC \n" 
      "    BL      shooting_expo_param_override\n"      // +	  
      "    B       loc_FFC5B18C \n" 
"loc_FFC5B138:\n"
"     BL    shooting_set_flash_override\n"
      "    BL      capt_seq_hook_set_nr\n"           		// +++ as in ixus310
      "    LDR     R7, [R0, #0xC] \n" 
      "    MOV     R0, R7 \n" 
      "    BL	 sub_FFD1CA20_my\n"
      "    BL      capt_seq_hook_raw_here\n"               // as in ixus220		  
      "    MOV     R4, R0 \n" 
      "    MOV     R2, R7 \n" 
      "    MOV     R1, #1 \n" 
      "    BL      sub_FFC59678 \n" 
      "    TST     R4, #1 \n" 
      "    MOVEQ   R0, R7 \n" 
      "    BLEQ    sub_FFD1C558 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B164:\n"
      "    MOV     R0, #1 \n" 
      "    BL      sub_FFC5BA38 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B170:\n"
      "    BL      sub_FFC5B494 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B178:\n"
      "    BL      sub_FFC5B79C \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B180:\n"
      "    BL      sub_FFC5B7A4 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B188:\n"
      "    BL      sub_FFC5B94C \n" 
"loc_FFC5B18C:\n"
      "    BL      sub_FFC591B0 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B194:\n"
      "    LDR     R4, [R0, #0xC] \n" 
      "    MOV     R0, R4 \n" 
      "    BL      sub_FFD1CAC8 \n" 
      "    MOV     R2, R4 \n" 
      "    MOV     R1, #9 \n" 
      "    BL      sub_FFC59678 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1B0:\n"
      "    BL      sub_FFC5B9B0 \n" 
      "    B       loc_FFC5B18C \n" 
"loc_FFC5B1B8:\n"
      "    LDR     R0, [R5, #0x50] \n" 
      "    BL      sub_FFC5BE4C \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1C4:\n"
      "    BL      sub_FFC5C194 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1CC:\n"
      "    BL      sub_FFC5C1F8 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1D4:\n"
      "    BL      sub_FFD1BAEC \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1DC:\n"
      "    BL      sub_FFD1BCD8 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1E4:\n"
      "    BL      sub_FFD1BD78 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1EC:\n"
      "    BL      sub_FFD1BE38 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B1F4:\n"
      "    MOV     R0, #0 \n" 
      "    BL      sub_FFD1C030 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B200:\n"
      "    BL      sub_FFD1C19C \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B208:\n"
      "    BL      sub_FFD1C240 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B210:\n"
      "    BL      sub_FFD1C320 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B218:\n"
      "    BL      sub_FFC5BBA0 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B220:\n"
      "    BL      sub_FFC5BBCC \n" 
      "    BL      sub_FFC270EC \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B22C:\n"
      "    BL      sub_FFD1BEFC \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B234:\n"
      "    BL      sub_FFD1BF3C \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B23C:\n"
      "    BL      sub_FFC5DFDC \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B244:\n"
      "    BL      sub_FFC5E048 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B24C:\n"
      "    BL      sub_FFC5E0A4 \n" 
      "    BL      sub_FFC5E064 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B258:\n"
      "    LDRH    R0, [R5, #0x90] \n" 
      "    CMP     R0, #4 \n" 
      "    LDRNEH  R0, [R5] \n" 
      "    SUBNE   R1, R0, #0x8200 \n" 
      "    SUBNES  R1, R1, #0x2A \n" 
      "    BNE     loc_FFC5B288 \n" 
      "    BL      sub_FFC5E048 \n" 
      "    BL      sub_FFC5E3D8 \n" 
      "    B       loc_FFC5B288 \n" 
"loc_FFC5B27C:\n"
      "    LDR     R1, =0x5D7 \n" 
      "    LDR     R0, =0xFFC5AC5C \n" 
      "    BL      sub_FFC0F768 \n" 
"loc_FFC5B288:\n"
      "    LDR     R0, [SP] \n" 
      "    LDR     R1, [R0, #4] \n" 
      "    LDR     R0, [R6] \n" 
      "    BL      sub_FFC28DCC \n" 
      "    LDR     R4, [SP] \n" 
      "    LDR     R0, [R4, #8] \n" 
      "    CMP     R0, #0 \n" 
      "    LDREQ   R0, =0xFFC5AC5C \n" 
      "    MOVEQ   R1, #0x118 \n" 
      "    BLEQ    sub_FFC0F768 \n" 
      "    MOV     R0, #0 \n" 
      "    STR     R0, [R4, #8] \n" 
      "    B       loc_FFC5B078 \n" 
	);
   }

//** sub_FFD1CA20
void __attribute__((naked,noinline)) sub_FFD1CA20_my() 
{
asm volatile (
"		STMFD	SP!, {R3-R5,LR}\n"
"		MOV	R4, R0\n"
"		MOV	R0, #0xC\n"
"		BL	sub_FFC5F898\n"
"		TST	R0, #1\n"
"		MOVNE	R0, #1\n"
"		BNE	loc_FFD1CAC4\n"
"		BL	sub_FFC5B7AC\n"
"		MOV	R0, R4\n"
"		BL	sub_FFD1C46C\n"
"		TST	R0, #1\n"
"		BNE	loc_FFD1CAC4\n"
"		MOV	R0, R4\n"
"		BL	sub_FFD1C70C\n"
"		BL	sub_FFD1D030\n"
"           BL     wait_until_remote_button_is_released\n"
"		LDR	R0, =0x33D88\n"
"		LDRH	R0, [R0]\n"
"		SUB	R1, R0,	#0x8200\n"
"		SUBS	R1, R1,	#0x2D\n"
"		MOVNE	R0, R4\n"
"		LDMNEFD	SP!, {R3-R5,LR}\n"
"		BNE	sub_FFE16E3C\n"
"		MOV	R5, #1\n"
"		MOV	R2, #2\n"
"		MOV	R1, SP\n"
"		ADD	R0, R2,	#0x15C\n"
"		STR	R5, [SP,#0]\n"
"		BL	sub_FFC6BA84\n"
"		TST	R0, #1\n"
"		MOVNE	R1, #0xBB\n"
"		LDRNE R0, =0xFFD1CB20\n" // "SsShootTask.c"
"		BLNE	sub_FFC0F768\n"
"		LDRH	R0, [SP,#0]\n"
"		CMP	R0, #1\n"
"		MOVHI	R0, #0x1D\n"
"		STRHI	R5, [R4,#0xD4]\n"
"		BHI	loc_FFD1CAC4\n"
"		MOV	R0, #0\n"
"		STR	R0, [R4,#0xD4]\n"
"		MOV	R0, R4\n"
"		BNE	sub_FFE16E3C\n"
"loc_FFD1CAC4:\n"
"		LDMFD	SP!, {R3-R5,PC}\n"
);

}
