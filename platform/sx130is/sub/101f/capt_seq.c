#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)0x5CB4;
#include "../../../generic/capt_seq.c"


int capt_seq_hook_set_nr_my(int orig)
{
 
  shutter_open_time=_time((void*)0);
   if(conf.PulseOption==1)
   {
    ubasic_set_led(9,1,100);
    _SleepTask(10);
    ubasic_set_led(9,0,0);
   }  

	// Firmware also tests for 3 and 7, meaning unknown, so we don't touch them
	if (orig!=NR_ON && orig!=NR_OFF)
		return orig;

	switch (core_get_noise_reduction_value()){
	case NOISE_REDUCTION_OFF:
		return NR_OFF;
	case NOISE_REDUCTION_ON:
		return NR_ON;
	case NOISE_REDUCTION_AUTO_CANON: // leave it alone
	default: // shut up compiler 
		return orig;
	};
}

/*----------------------------------------------------------------------
	capt_seq_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) capt_seq_task()
{
  // FF87B564
	asm volatile (
"		STMFD	SP!, {R3-R7,LR} \n"
"		LDR	R6, =0x2C6C \n"
"		LDR	R5, =0x38B44 \n"
"loc_FF87B570: \n"
"		LDR	R0, [R6,#4] \n"
"		MOV	R2, #0 \n"
"		MOV	R1, SP \n"
"		BL	sub_FF839B8C \n"
"		TST	R0, #1 \n"
"		BEQ	loc_FF87B59C \n"
"		LDR	R1, =0x43F \n"
"		LDR	R0, =0xFF87B07C \n" // "SsShootTask.c"
"		BL	_DebugAssert \n" 
"		BL	sub_FF81EB30 \n" // eventproc_export_ExitTask
"		LDMFD	SP!, {R3-R7,PC} \n"
"loc_FF87B59C: \n"
"		LDR	R0, [SP] \n"
"		LDR	R1, [R0] \n"
"		CMP	R1, #0x21 \n"
"		ADDLS	PC, PC,	R1,LSL#2 \n"
"		B	loc_FF87B794 \n"
"loc_FF87B5B0: \n"
"		B	loc_FF87B638 \n"
"loc_FF87B5B4: \n"
"		B	loc_FF87B640 \n"
"loc_FF87B5B8: \n"
"		B	loc_FF87B658 \n"
"loc_FF87B5BC: \n"
"		B	loc_FF87B66C \n"
"loc_FF87B5C0: \n"
"		B	loc_FF87B664 \n"
"loc_FF87B5C4: \n"
"		B	loc_FF87B674 \n"
"loc_FF87B5C8: \n"
"		B	loc_FF87B67C \n"
"loc_FF87B5CC: \n"
"		B	loc_FF87B688 \n"
"loc_FF87B5D0: \n"
"		B	loc_FF87B694 \n"
"loc_FF87B5D4: \n"
"		B	loc_FF87B66C \n"
"loc_FF87B5D8: \n"
"		B	loc_FF87B69C \n"
"loc_FF87B5DC: \n"
"		B	loc_FF87B6A8 \n"
"loc_FF87B5E0: \n"
"		B	loc_FF87B6B0 \n"
"loc_FF87B5E4: \n"
"		B	loc_FF87B6B8 \n"
"loc_FF87B5E8: \n"
"		B	loc_FF87B6C0 \n"
"loc_FF87B5EC: \n"
"		B	loc_FF87B6C8 \n"
"loc_FF87B5F0: \n"
"		B	loc_FF87B6D0 \n"
"loc_FF87B5F4: \n"
"		B	loc_FF87B6D8 \n"
"loc_FF87B5F8: \n"
"		B	loc_FF87B6E0 \n"
"loc_FF87B5FC: \n"
"		B	loc_FF87B6E8 \n"
"loc_FF87B600: \n"
"		B	loc_FF87B6F0 \n"
"loc_FF87B604: \n"
"		B	loc_FF87B6F8 \n"
"loc_FF87B608: \n"
"		B	loc_FF87B700 \n"
"loc_FF87B60C: \n"
"		B	loc_FF87B70C \n"
"loc_FF87B610: \n"
"		B	loc_FF87B714 \n"
"loc_FF87B614: \n"
"		B	loc_FF87B720 \n"
"loc_FF87B618: \n"
"		B	loc_FF87B728 \n"
"loc_FF87B61C: \n"
"		B	loc_FF87B730 \n"
"loc_FF87B620: \n"
"		B	loc_FF87B738 \n"
"loc_FF87B624: \n"
"		B	loc_FF87B740 \n"
"loc_FF87B628: \n"
"		B	loc_FF87B748 \n"
"loc_FF87B62C: \n"
"		B	loc_FF87B750 \n"
"loc_FF87B630: \n"
"		B	loc_FF87B75C \n"
"loc_FF87B634: \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B638: \n"
// jumptable FF87B5A8 entry 0
"		BL	sub_FF87BD1C \n"
"		BL	shooting_expo_param_override \n"	// Added ------------>
"		B	loc_FF87B680 \n"
"loc_FF87B640: \n"
// jumptable FF87B5A8 entry 1
"     BL    shooting_set_flash_override\n"
"		LDRH	R1, [R5] \n"
"		SUB	R12, R1, #0x8200 \n"
"		SUBS	R12, R12, #0x2E \n"
"		LDRNE	R0, [R0,#0xC] \n"
//"		BLNE	sub_FF96E09C \n"
"		BLNE	sub_FF96E09C_my \n" // Patched ------------>
"		B	loc_FF87B7A0 \n"
"loc_FF87B658: \n"
// jumptable FF87B5A8 entry 2
"		MOV	R0, #1 \n"
"		BL	sub_FF87BFA8 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B664: \n"
// jumptable FF87B5A8 entry 4
"		BL	sub_FF87B9CC \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B66C: \n"
// jumptable FF87B5A8 entries 3,9
"		BL	sub_FF87BCFC \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B674: \n"
// jumptable FF87B5A8 entry 5
"		BL	sub_FF87BD04 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B67C: \n"
// jumptable FF87B5A8 entry 6
"		BL	sub_FF87BEBC \n"
"loc_FF87B680: \n"
"		BL	sub_FF879260 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B688: \n"
// jumptable FF87B5A8 entry 7
"		LDR	R0, [R0,#0xC] \n"
"		BL	sub_FF96E20C \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B694: \n"
// jumptable FF87B5A8 entry 8
"		BL	sub_FF87BF20 \n"
"		B	loc_FF87B680 \n"
"loc_FF87B69C: \n"
// jumptable FF87B5A8 entry 10
"		LDR	R0, [R5,#0x4C] \n"
"		BL	sub_FF87C57C \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6A8: \n"
// jumptable FF87B5A8 entry 11
"		BL	sub_FF87C8C8 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6B0: \n"
// jumptable FF87B5A8 entry 12
"		BL	sub_FF87C92C \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6B8: \n"
// jumptable FF87B5A8 entry 13
"		BL	sub_FF96D5DC \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6C0: \n"
// jumptable FF87B5A8 entry 14
"		BL	sub_FF96D7E8 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6C8: \n"
// jumptable FF87B5A8 entry 15
"		BL	sub_FF96D86C \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6D0: \n"
// jumptable FF87B5A8 entry 16
"		BL	sub_FF96D958 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6D8: \n"
// jumptable FF87B5A8 entry 17
"		BL	sub_FF96DA28 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6E0: \n"
// jumptable FF87B5A8 entry 18
"		MOV	R0, #0 \n"
"		B	loc_FF87B704 \n"
"loc_FF87B6E8: \n"
// jumptable FF87B5A8 entry 19
"		BL	sub_FF96DE24 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6F0: \n"
// jumptable FF87B5A8 entry 20
"		BL  sub_FF96DEC8 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B6F8: \n"
// jumptable FF87B5A8 entry 21
"		BL  sub_FF96DFA8 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B700: \n"
// jumptable FF87B5A8 entry 22
"		MOV	R0, #1 \n"
"loc_FF87B704: \n"
"		BL	sub_FF96DCC4 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B70C: \n"
// jumptable FF87B5A8 entry 23
"		BL	sub_FF87C178 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B714: \n"
// jumptable FF87B5A8 entry 24
"		BL	sub_FF87C1A4 \n"
"		BL	sub_FF96EE48 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B720: \n"
// jumptable FF87B5A8 entry 25
"		BL	sub_FF96DB9C \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B728: \n"
// jumptable FF87B5A8 entry 26
"		BL	sub_FF96DC34 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B730: \n"
// jumptable FF87B5A8 entry 27
"		BL	sub_FF96EF18 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B738: \n"
// jumptable FF87B5A8 entry 28
"		BL	sub_FF83790C \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B740: \n"
// jumptable FF87B5A8 entry 29
"		BL	sub_FF87E998 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B748: \n"
// jumptable FF87B5A8 entry 30
"		BL	sub_FF87EA18 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B750: \n"
// jumptable FF87B5A8 entry 31
"		BL	sub_FF87EA74 \n"
"		BL	sub_FF87EA34 \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B75C: \n"
// jumptable FF87B5A8 entry 32
"		MOV	R0, #1 \n"
"		BL	sub_FF96E990 \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF96EAB4 \n"
"		LDRH	R0, [R5,#0x94] \n"
"		CMP	R0, #4 \n"
"		LDRNEH	R0, [R5] \n"
"		SUBNE	R12, R0, #0x4200 \n"
"		SUBNES	R12, R12, #0x2A \n"
"		BNE	loc_FF87B7A0 \n"
"		BL	sub_FF87EA18 \n"
"		BL	sub_FF87EF84 \n"
"		BL	sub_FF87EE94  \n"
"		B	loc_FF87B7A0 \n"
"loc_FF87B794: \n"
// jumptable FF87B5A8 default entry
"		LDR	R1, =0x591 \n"
"		LDR	R0, =0xFF87B07C \n" // "SsShootTask.c"
"		BL	_DebugAssert \n" 
"loc_FF87B7A0: \n"
// jumptable FF87B5A8 entry 33
"		LDR	R0, [SP] \n"
"		LDR	R1, [R0,#4] \n"
"		LDR	R0, [R6] \n"
"		BL	sub_FF8855D8 \n"
"		LDR	R4, [SP] \n"
"		LDR	R0, [R4,#8] \n"
"		CMP	R0, #0 \n"
"		LDREQ	R1, =0x115 \n"
"		LDREQ	R0, =0xFF87B07C \n" // "SsShootTask.c"
"		BLEQ	_DebugAssert \n" 
"		MOV	R0, #0 \n"
"		STR	R0, [R4,#8] \n"
"		B	loc_FF87B570 \n"
	);
}

void __attribute__((naked,noinline)) sub_FF96E09C_my(){
    asm volatile(
"		STMFD	SP!, {R3-R7,LR}\n"
"		MOV	R4, R0 \n"
"		MOV	R0, #0xC \n"
"		BL	sub_FF880578 \n"
"		TST	R0, #1 \n"
"		MOVNE	R2, R4 \n"
"		LDMNEFD	SP!, {R3-R7,LR} \n"
"		MOVNE	R1, #1 \n"
"		MOVNE	R0, #1 \n"
"		BNE	sub_FF879734 \n"
"		LDR	R0, [R4,#8] \n"
"		LDR	R5, =0x38B44 \n"
"		ORR	R0, R0,	#1 \n"
"		STR	R0, [R4,#8] \n"
"		LDRH	R0, [R5,#0x92] \n"
"		CMP	R0, #3 \n"
"		BEQ	loc_FF96E170 \n"
"		LDR	R0, [R4,#0xC] \n"
"		CMP	R0, #1 \n"
"		BLS	loc_FF96E13C \n"
"		LDRH	R0, [R5,#0x90] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF96E170 \n"
"		LDRH	R0, [R5,#0x8C] \n"
"		CMP	R0, #2 \n"
"		BNE	loc_FF96E148 \n"
"		BL	sub_FF87C270 \n"
"		LDRH	R0, [R5,#0x92] \n"
"		CMP	R0, #3 \n"
"		BEQ	loc_FF96E170 \n"
"		LDR	R0, [R4,#0xC] \n"
"		CMP	R0, #1 \n"
"		BLS	loc_FF96E13C \n"
"		LDRH	R0, [R5,#0x90] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF96E170 \n"
"		LDRH	R0, [R5,#0x8C] \n"
"		CMP	R0, #2 \n"
"		BEQ	loc_FF96E16C \n"
"		B	loc_FF96E148 \n"
"loc_FF96E13C: \n"
"		LDRH	R0, [R5,#0x90] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF96E170 \n"
"loc_FF96E148: \n"
"		LDRH	R0, [R5,#0x8C] \n"
"		CMP	R0, #1 \n"
"		BNE	loc_FF96E170 \n"
"		LDR	R0, [R4,#0xC] \n"
"		CMP	R0, #1 \n"
"		BLS	loc_FF96E170 \n"
"		LDR	R0, [R4,#0x10] \n"
"		CMP	R0, #1 \n"
"		BNE	loc_FF96E170 \n"
"loc_FF96E16C: \n"
"		BL	sub_FF96EF50 \n"
"loc_FF96E170: \n"
"		BL	sub_FF96EF18 \n"
"		BL	sub_FF87BD0C \n"
"		MOV	R0, R4 \n"
"		BL	sub_FFAAFCA8 \n" 		// before shot (G12) ?
"		TST	R0, #1 \n"
"		BNE	locret_FF96E208 \n"
"		MOV	R0, R4 \n"
"		BL	sub_FFAB0088 \n"
"		BL	sub_FF96E774 \n"		// after pre-flash, before shot (G12) ? 
"		MOV	R6, #1 \n"			
"		MOV	R0, #2 \n"
"		BL	sub_FF877954 \n"
"		LDRH	R0, [R5] \n"
"		SUB	R12, R0, #0x8200 \n"
"		SUBS	R12, R12, #0x2D \n"
"		BNE	loc_FF96E1F0 \n"
"		MOV	R2, #2 \n"
"		ADD	R0, R2,	#0x15C \n"
"		MOV	R1, SP \n"
"		STR	R6, [SP] \n"
"		BL	sub_FF88D7A0 \n"
"		TST	R0, #1 \n"
"		MOVNE	R1, #0xC3 \n"
//"		ADRNE	R0, aSscaptureseq_c \n" // "SsCaptureSeq.c"
"		LDRNE	R0, =0xFF96E27C \n"
"		BLNE	_DebugAssert \n"
"		LDRH	R0, [SP] \n"
"		CMP	R0, #1 \n"
"		MOVHI	R0, #0x1D \n"
"		STRHI	R6, [R4,#0xD4] \n"
"		BHI	loc_FF96E1F8 \n"
"		MOV	R0, #0 \n"
"		STR	R0, [R4,#0xD4] \n"
"loc_FF96E1F0: \n"
"		MOV	R0, R4 \n"
//"		BL	sub_FFAB050C \n"
"		BL	sub_FFAB050C_my \n" // Patched ------------>
"		BL	capt_seq_hook_raw_here \n"	// Added ---------->
"loc_FF96E1F8: \n"
"		MOV	R1, R0 \n"
"		MOV	R0, R4 \n"
"		LDMFD	SP!, {R3-R7,LR} \n"
"		B	sub_FFAAFDAC \n"
"locret_FF96E208: \n"
"		LDMFD	SP!, {R3-R7,PC} \n"
	);	
}

void __attribute__((naked,noinline)) sub_FFAB050C_my()
{
	asm volatile(
"		STMFD	SP!, {R2-R6,LR} \n"
"		MOV	R5, R0 \n"
"		BL	sub_FF96EC78 \n"
"		MOV	R1, #0xFFFFFFFF \n"
"		BL	sub_FF88560C \n"
"		LDR	R0, =0xFFAAFE18 \n" 		// sub_FFAAFE18
"		MOV	R1, R5 \n"
"		BL	sub_FF8B571C \n"
"		MOV	R0, R5 \n"
"		BL	sub_FFAAFD34 \n"
"		MOV	R0, R5 \n"
"		BL	sub_FFAB0150 \n"
"		MOV	R4, R0 \n"
"		LDR	R1, =0xC918 \n"
"		MOV	R0, #0x8A \n"
"		MOV	R2, #4 \n"
"		BL	sub_FF88D7A0 \n"		// PT_GetPropertyCaseString
"		TST	R0, #1 \n"
"		LDRNE	R1, =0x1F6 \n"
//"		ADRNE	R0, aSsstandardcapt \n" // "SsStandardCaptureSeq.c"
"		LDRNE	R0, =0xFFAB067C \n"
"		BLNE	_DebugAssert \n"
"		BL	sub_FF87E0F8 \n"
"		MOV	R0, R4 \n"

"		BL	wait_until_remote_button_is_released\n" // Added (not tested) -------->
"		BL	capt_seq_hook_set_nr_my \n"	// Added ------------->

"		B	sub_FFAB0568 \n"		// Return to firmware --------->
	); 
}

