#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
 
static long *nrflag = (long*)(0x757c+0x08);
#define NR_AUTO (0)
#include "../../../generic/capt_seq.c"

void afOn()
{
	*((long*) 0xC0223030) = 0x46;	// af on
}

/*----------------------------------------------------------------------
	capt_seq_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) capt_seq_task()
{
	asm volatile (
"		STMFD	SP!, {R3-R7,LR} \n"
"		LDR	R7, =0x2E6C \n"
"		LDR	R4, =0x3CFBC \n"
"		MOV	R6, #0 \n"
"loc_FF88323C: \n"
"		LDR	R0, [R7,#4] \n"
"		MOV	R2, #0 \n"
"		MOV	R1, SP \n"
"		BL	sub_FF83A2F8 \n"
"		TST	R0, #1 \n"
"		BEQ	loc_FF883268 \n"
"		LDR	R1, =0x43F \n"
"		LDR	R0, =0xFF882CF4 \n"					// aSsshoottask_c
"		BL	sub_FF81EB78 \n"					// DebugAssert
"		BL	sub_FF81EB30 \n"					// eventproc_export_ExitTask
"		LDMFD	SP!, {R3-R7,PC} \n"
"loc_FF883268: \n"
"		LDR	R0, [SP] \n"
"		LDR	R1, [R0] \n"
"		CMP	R1, #0x23 \n"
"		ADDLS	PC, PC,	R1,LSL#2 \n"
"		B	loc_FF8834A0 \n"
"loc_FF88327C: \n"
"		B	loc_FF88330C \n"
"loc_FF883280: \n"
"		B	loc_FF883324 \n"
"loc_FF883284: \n"
"		B	loc_FF883348 \n"
"loc_FF883288: \n"
"		B	loc_FF88335C \n"
"loc_FF88328C: \n"
"		B	loc_FF883354 \n"
"loc_FF883290: \n"
"		B	loc_FF883368 \n"
"loc_FF883294: \n"
"		B	loc_FF883370 \n"
"loc_FF883298: \n"
"		B	loc_FF883378 \n"
"loc_FF88329C: \n"
"		B	loc_FF883384 \n"
"loc_FF8832A0: \n"
"		B	loc_FF8833AC \n"
"loc_FF8832A4: \n"
"		B	loc_FF883390 \n"
"loc_FF8832A8: \n"
"		B	loc_FF88339C \n"
"loc_FF8832AC: \n"
"		B	loc_FF8833A4 \n"
"loc_FF8832B0: \n"
"		B	loc_FF8833B4 \n"
"loc_FF8832B4: \n"
"		B	loc_FF8833BC \n"
"loc_FF8832B8: \n"
"		B	loc_FF8833C4 \n"
"loc_FF8832BC: \n"
"		B	loc_FF8833CC \n"
"loc_FF8832C0: \n"
"		B	loc_FF8833D4 \n"
"loc_FF8832C4: \n"
"		B	loc_FF8833DC \n"
"loc_FF8832C8: \n"
"		B	loc_FF8833E4 \n"
"loc_FF8832CC: \n"
"		B	loc_FF8833EC \n"
"loc_FF8832D0: \n"
"		B	loc_FF8833F4 \n"
"loc_FF8832D4: \n"
"		B	loc_FF8833FC \n"
"loc_FF8832D8: \n"
"		B	loc_FF883408 \n"
"loc_FF8832DC: \n"
"		B	loc_FF883410 \n"
"loc_FF8832E0: \n"
"		B	loc_FF88341C \n"
"loc_FF8832E4: \n"
"		B	loc_FF883424 \n"
"loc_FF8832E8: \n"
"		B	loc_FF88342C \n"
"loc_FF8832EC: \n"
"		B	loc_FF883434 \n"
"loc_FF8832F0: \n"
"		B	loc_FF88343C \n"
"loc_FF8832F4: \n"
"		B	loc_FF883444 \n"
"loc_FF8832F8: \n"
"		B	loc_FF88344C \n"
"loc_FF8832FC: \n"
"		B	loc_FF883454 \n"
"loc_FF883300: \n"
"		B	loc_FF88345C \n"
"loc_FF883304: \n"
"		B	loc_FF883468 \n"
"loc_FF883308: \n"
"		B	loc_FF8834AC \n"

// jump table entry 0
// half-press / shot setup
"loc_FF88330C: \n"
"		BL	sub_FF8839D4 \n"

"		BL	shooting_expo_param_override\n"  		// added

"		BL	sub_FF880B34 \n"

// force call to next function
"		MOV     R0, #0\n"
"		STR     R0, [R4,#0x24]\n"  			// fixes overrides  behavior at short shutter press

"		LDR	R0, [R4,#0x24] \n"
"		CMP	R0, #0 \n"
"		BLNE	sub_FF98AEB4 \n"
"		B	loc_FF8834AC \n"

// jump table entry 1
"loc_FF883324: \n"
"		LDRH	R1, [R4] \n"
"		LDR	R0, [R0,#0xC] \n"
"		SUB	R12, R1, #0x4200 \n"
"		SUBS	R12, R12, #0x2E \n"
"		BNE	loc_FF883340 \n"
"		BL	sub_FF98BC9C \n"
"		B	loc_FF8834AC \n"
"loc_FF883340: \n"
"     BL    shooting_set_flash_override\n"
// ******************** gets here just before picture is taken

//"		BL	sub_FF98ACE0 \n"
"		BL	sub_FF98ACE0_my \n"					// patched

// ******************* gets here just after picture is taken


"		B	loc_FF8834AC \n"

// jump table entry 2
"loc_FF883348: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF883CB8 \n"
"		B	loc_FF8834AC \n"

"loc_FF883354: \n"
"		BL	sub_FF88366C \n"
"		B	loc_FF883360 \n"

"loc_FF88335C: \n"
"		BL	sub_FF8839B4 \n"
"loc_FF883360: \n"
"		STR	R6, [R4,#0x24] \n"
"		B	loc_FF8834AC \n"

"loc_FF883368: \n"
"		BL	sub_FF8839BC \n"
"		B	loc_FF8834AC \n"

"loc_FF883370: \n"
"		BL	sub_FF883BBC \n"
"		B	loc_FF883388 \n"

"loc_FF883378: \n"
"		LDR	R0, [R0,#0xC] \n"
"		BL	sub_FF98AF1C \n"
"		B	loc_FF8834AC \n"

"loc_FF883384: \n"
"		BL	sub_FF883C28 \n"
"loc_FF883388: \n"
"		BL	sub_FF880B34 \n"
"		B	loc_FF8834AC \n"

"loc_FF883390: \n"
"		LDR	R0, [R4,#0x54] \n"
"		BL	sub_FF884614 \n"
"		B	loc_FF8834AC \n"

"loc_FF88339C: \n"
"		BL	sub_FF884968 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833A4: \n"
"		BL	sub_FF8849CC \n"
"		B	loc_FF8834AC \n"

"loc_FF8833AC: \n"
"		BL	sub_FF8839B4 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833B4: \n"
"		BL	sub_FF989FF0 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833BC: \n"
"		BL	sub_FF98A1FC \n"
"		B	loc_FF8834AC \n"

"loc_FF8833C4: \n"
"		BL	sub_FF98A294 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833CC: \n"
"		BL	sub_FF98A380 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833D4: \n"
"		BL	sub_FF98A478 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833DC: \n"
"		MOV	R0, #0 \n"
"		B	loc_FF883400 \n"

"loc_FF8833E4: \n"
"		BL	sub_FF98A6B4 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833EC: \n"
"		BL	sub_FF98A758 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833F4: \n"
"		BL	sub_FF98A838 \n"
"		B	loc_FF8834AC \n"

"loc_FF8833FC: \n"
"		MOV	R0, #1 \n"
"loc_FF883400: \n"
"		BL	sub_FF98A53C \n"
"		B	loc_FF8834AC \n"

"loc_FF883408: \n"
"		BL	sub_FF883EC4 \n"
"		B	loc_FF8834AC \n"

"loc_FF883410: \n"
"		BL	sub_FF883F6C \n"
"		BL	sub_FF98C1C4 \n"
"		B	loc_FF8834AC \n"

"loc_FF88341C: \n"
"		BL	sub_FF884350 \n"
"		B	loc_FF8834AC \n"

"loc_FF883424: \n"
"		BL	sub_FF884490 \n"
"		B	loc_FF8834AC \n"

"loc_FF88342C: \n"
"		BL	sub_FF98C294 \n"
"		B	loc_FF8834AC \n"

"loc_FF883434: \n"
"		BL	sub_FF837C6C \n"
"		B	loc_FF8834AC \n"

"loc_FF88343C: \n"
"		BL	sub_FF886FE4 \n"
"		B	loc_FF8834AC \n"

"loc_FF883444: \n"
"		BL	sub_FF887070 \n"
"		B	loc_FF8834AC \n"

"loc_FF88344C: \n"
"		BL	sub_FF98A970 \n"
"		B	loc_FF8834AC \n"

"loc_FF883454: \n"
"		BL	sub_FF98A9D4 \n"
"		B	loc_FF8834AC \n"

"loc_FF88345C: \n"
"		BL	sub_FF8870CC \n"
"		BL	sub_FF88708C \n"
"		B	loc_FF8834AC \n"

"loc_FF883468: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF98B6C4 \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF98B7F4 \n"
"		LDRH	R0, [R4,#0x9C] \n"
"		CMP	R0, #4 \n"
"		LDRNEH	R0, [R4] \n"
"		SUBNE	R12, R0, #0x4200 \n"
"		SUBNES	R12, R12, #0x2A \n"
"		BNE	loc_FF8834AC \n"
"		BL	sub_FF887070 \n"
"		BL	sub_FF887670 \n"
"		BL	sub_FF8874EC \n"
"		B	loc_FF8834AC \n"

"loc_FF8834A0: \n"
"		LDR	R1, =0x591 \n"
"		LDR	R0, =0xFF882CF4 \n"				// "SsShootTask.c"
"		BL	sub_FF81EB78 \n"				// DebugAssert

"loc_FF8834AC: \n"
"		LDR	R0, [SP] \n"
"		LDR	R1, [R0,#4] \n"
"		LDR	R0, [R7] \n"
"		BL	sub_FF88E1E4 \n"
"		LDR	R5, [SP] \n"
"		LDR	R0, [R5,#8] \n"
"		CMP	R0, #0 \n"
"		LDREQ	R1, =0x115 \n"
"		LDREQ	R0, =0xFF882CF4 \n"			// "SsShootTask.c"
"		BLEQ	sub_FF81EB78 \n"			// DebugAssert
"		STR	R6, [R5,#8] \n"
"		B	loc_FF88323C \n"
	);
}


/*----------------------------------------------------------------------
	sub_FF98AEB4_my()
-----------------------------------------------------------------------*/
/*
void __attribute__((naked,noinline)) sub_FF98AEB4_my()
{
	asm volatile (
"		STMFD	SP!, {R4-R6,LR} \n"
"		BL	sub_FF8829C4 \n"
"		MOV	R4, R0 \n"
"		LDR	R0, =0x3CFBC \n"
"		LDR	R5, =0x7514 \n"
"		LDR	R0, [R0,#0x24] \n"
"		MOV	R6, #1 \n"
"		CMP	R0, #0 \n"
"		BEQ	loc_FF98AEF8 \n"
"		MOV	R0, #0xC \n"
"		BL	sub_FF889040 \n"
"		TST	R0, #1 \n"
"		STRNE	R6, [R5] \n"
"		LDRNE	R0, [R4,#8] \n"
"		ORRNE	R0, R0,	#0x40000000 \n"
"		STRNE	R0, [R4,#8] \n"
"		LDMNEFD	SP!, {R4-R6,PC} \n"
"loc_FF98AEF8: \n"
"		MOV	R0, R4 \n"
"		BL	sub_FF98AAB8 \n"
"		MOV	R0, R4 \n"
"		BL	sub_FFAF8E54 \n"
"		MOV	R0, R4 \n"

//"		BL	sub_FFAF97E0 \n"
"		BL	sub_FFAF97E0_my \n"					// patched

"		TST	R0, #1 \n"
"		STRNE	R6, [R5] \n"
"		LDMFD	SP!, {R4-R6,PC} \n"
	);
}
*/

/*----------------------------------------------------------------------
	sub_FFAF97E0_my()
-----------------------------------------------------------------------*/
/*
void __attribute__((naked,noinline)) sub_FFAF97E0_my()
{
	asm volatile (
"		STMFD	SP!, {R2-R6,LR} \n"
"		MOV	R5, R0 \n"
"		BL	sub_FF98B9B8 \n"
"		MVN     R1, #0 \n"
"		BL	sub_FF88E218 \n"
"		LDR	R0, =0xFFAF9048 \n"
"		MOV	R1, R5 \n"
"		BL	sub_FF8C4DDC \n"
"		MOV	R0, R5 \n"
"		BL	sub_FFAF8F60 \n"
"		MOV	R0, R5 \n"
"		BL	sub_FFAF93D4 \n"
"		MOV	R4, R0 \n"
"		LDR	R1, =0xE7E0 \n"
"		MOV	R0, #0x8A \n"
"		MOV	R2, #4 \n"
"		BL	sub_FF896414 \n"				// PT_GetPropertyCaseString
"		TST	R0, #1 \n"
"		LDRNE	R1, =0x1F6 \n"
"		LDRNE	R0, =0xFFAF9968 \n"			// "SsStandardCaptureSeq.c"
"		BLNE	sub_FF81EB78 \n"			// DebugAssert
"		BL	sub_FF88663C \n"
"		MOV	R0, R4 \n"
"		CMP	R0, #1 \n"
"		MOV	R4, #0 \n"
"		BEQ	loc_FFAF9880 \n"
"		CMP	R0, #2 \n"
"		BEQ	loc_FFAF9890 \n"
"		CMP	R0, #3 \n"
"		BEQ	loc_FFAF98B4 \n"
"		CMP	R0, #7 \n"
"		BNE	loc_FFAF98D0 \n"
"		MOV	R0, #0 \n"
"		BL	sub_FF8C4E0C \n"
"		MOV	R0, #4 \n"
"		STR	R0, [SP,#0x04] \n"

"loc_FFAF9870: \n"
"		ADD	R1, SP,	#0x14 \n"
"		MOV	R0, R5 \n"
"		BL	sub_FFAF9644 \n"
"		B	loc_FFAF98AC \n"

"loc_FFAF9880: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF8C4E0C \n"
"		STR	R4, [SP,#0x04] \n"
"		B	loc_FFAF9870 \n"

"loc_FFAF9890: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF8C4E0C \n"
"		MOV	R0, #1 \n"
"		STR	R0, [SP,#0x04] \n"
"		MOV	R0, R5 \n"
"		ADD	R1, SP,	#0x04 \n"
"		BL	sub_FFAF9A3C \n"

"loc_FFAF98AC: \n"
"		MOV	R6, R0 \n"
"		B	loc_FFAF98DC \n"

"loc_FFAF98B4: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF8C4E0C \n"
"		ADD	R1, SP,	#0x04 \n"
"		MOV	R0, R5 \n"
"		STR	R4, [SP,#0x04] \n"
"		BL	sub_FFAF96C0 \n"
"		B	loc_FFAF98AC \n"

"loc_FFAF98D0: \n"
"		MOV	R1, #0x22C \n"
"		LDR	R0, =0xFFAF9968 \n"			// "SsStandardCaptureSeq.c"
"		BL	sub_FF81EB78 \n"			// DebugAssert

"loc_FFAF98DC: \n"
"		TST	R6, #1 \n"
"		MOVNE	R0, R6 \n"
"		BNE	loc_FFAF9948 \n"
"		MOV	R1, #0 \n"
"		LDR	R0, =0xFFAF95B4 \n"			// nullsub_364
"		BL	sub_FF8C4DDC \n"
"		LDR	R0, =0x3CFBC \n"
"		LDRH	R0, [R0] \n"
"		SUB	R12, R0, #0x4000 \n"
"		SUBS	R12, R12, #0x20C \n"
"		BLEQ	sub_FF8ADB14 \n"

// *************  doesn't get here
//"		BL     capt_seq_hook_raw_here \n"		// added

"		MOV	R0, R5 \n"
"		BL	sub_FFAF947C \n"
"		BL	sub_FF98B9B8 \n"
"		MOV	R3, #0x244 \n"
"		STR	R3, [SP] \n"
"		LDR	R2, =0x3A98 \n"
"		LDR	R3, =0xFFAF9968 \n"			// "SsStandardCaptureSeq.c"
"		MOV	R1, #4 \n"
"		BL	sub_FF8893B8 \n"
"		CMP	R0, #0 \n"
"		MOVNE	R1, #0x244 \n"
"		LDRNE	R0, =0xFFAF9968 \n"		// "SsStandardCaptureSeq.c"
"		BLNE	sub_FF81EB78 \n"		// DebugAssert
"		LDRH	R0, [SP,#0x04] \n"
"		STRH	R0, [R5,#0x14] \n"
"		MOV	R0, #0 \n"

"loc_FFAF9948: \n"
"		LDMFD	SP!, {R2-R6,PC} \n"
	);
}
*/

/*----------------------------------------------------------------------
	sub_FF98ACE0_my()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FF98ACE0_my()
{
	asm volatile (
"		STMFD	SP!, {R3-R7,LR} \n"
"		LDR	R5, =0x3CFBC \n"
"		MOV	R4, R0 \n"
"		LDR	R0, [R5,#0x24] \n"
"		MOV	R6, #0 \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF98AD1C \n"
"		MOV	R0, #0xC \n"
"		BL	sub_FF889040 \n"
"		TST	R0, #1 \n"
"		MOVNE	R2, R4 \n"
"		LDMNEFD	SP!, {R3-R7,LR} \n"
"		MOVNE	R1, #1 \n"
"		MOVNE	R0, #1 \n"
"		BNE	sub_FF8811F8 \n"
"loc_FF98AD1C: \n"
"		LDR	R0, [R4,#8] \n"
"		LDR	R7, =0x420C \n"
"		ORR	R0, R0,	#1 \n"
"		STR	R0, [R4,#8] \n"
"		LDRH	R0, [R5] \n"
"		CMP	R0, R7 \n"
"		BEQ	loc_FF98ADAC \n"
"		LDRH	R0, [R5,#0x9A] \n"
"		CMP	R0, #3 \n"
"		BEQ	loc_FF98ADF4 \n"
"		LDR	R0, [R4,#0xC] \n"
"		CMP	R0, #1 \n"
"		BLS	loc_FF98ADB8 \n"
"		LDRH	R0, [R5,#0x98] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF98ADF4 \n"
"		LDRH	R0, [R5,#0x94] \n"
"		CMP	R0, #2 \n"
"		BNE	loc_FF98ADC4 \n"
"		BL	sub_FF88402C \n"
"		LDRH	R0, [R5] \n"
"		CMP	R0, R7 \n"
"		BEQ	loc_FF98ADAC \n"
"		LDRH	R0, [R5,#0x9A] \n"
"		CMP	R0, #3 \n"
"		BEQ	loc_FF98ADF4 \n"
"		LDR	R0, [R4,#0xC] \n"
"		CMP	R0, #1 \n"
"		BLS	loc_FF98ADB8 \n"
"		LDRH	R0, [R5,#0x98] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF98ADF4 \n"
"		LDRH	R0, [R5,#0x94] \n"
"		CMP	R0, #2 \n"
"		BEQ	loc_FF98ADF0 \n"
"		B	loc_FF98ADC4 \n"
"loc_FF98ADAC: \n"
"		LDRH	R0, [R5,#0x9A] \n"
"		CMP	R0, #3 \n"
"		BEQ	loc_FF98ADF4 \n"
"loc_FF98ADB8: \n"
"		LDRH	R0, [R5,#0x98] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF98ADF4 \n"
"loc_FF98ADC4: \n"
"		LDRH	R0, [R5,#0x94] \n"
"		CMP	R0, #1 \n"
"		BNE	loc_FF98ADF4 \n"
"		LDRH	R0, [R5] \n"
"		CMP	R0, R7 \n"
"		LDRNE	R0, [R4,#0xC] \n"
"		CMPNE	R0, #1 \n"
"		BLS	loc_FF98ADF4 \n"
"		LDR	R0, [R4,#0x10] \n"
"		CMP	R0, #1 \n"
"		BNE	loc_FF98ADF4 \n"
"loc_FF98ADF0: \n"
"		BL	sub_FF98C2CC \n"
"loc_FF98ADF4: \n"
"		BL	sub_FF98C294 \n"
"		BL	sub_FF8839C4 \n"
"		LDR	R0, [R5,#0x24] \n"
"		CMP	R0, #0 \n"
"		BNE	loc_FF98AE8C \n"
"		MOV	R0, R4 \n"
"		BL	sub_FFAF8ECC \n"
"		TST	R0, #1 \n"
"		BNE	locret_FF98AEB0 \n"
"		MOV	R0, R4 \n"
"		BL	sub_FFAF92EC \n"
"		BL	sub_FF98B48C \n"
"		MOV	R6, #1 \n"
"		MOV	R0, #2 \n"
"		BL	sub_FF87EFF8 \n"

// ***************** gets here just before taking picture

"		BL      wait_until_remote_button_is_released \n"	// added
"		BL      capt_seq_hook_set_nr \n"					// added

"		LDRH	R0, [R5] \n"
"		SUB	R12, R0, #0x8200 \n"
"		SUBS	R12, R12, #0x2D \n"
"		BNE	loc_FF98AE7C \n"
"		MOV	R2, #2 \n"
"		ADD	R0, R2,	#0x15C \n"
"		MOV	R1, SP \n"
"		STR	R6, [SP] \n"
"		BL	sub_FF896414 \n"				// PT_GetPropertyCaseString
"		TST	R0, #1 \n"
"		MOVNE	R1, #0xC3 \n"
"		LDRNE	R0, =0xFF98AF90 \n"			// "SsCaptureSeq.c"
"		BLNE	sub_FF81EB78 \n"			// DebugAssert
"		LDRH	R0, [SP] \n"
"		CMP	R0, #1 \n"
"		STRHI	R6, [R4,#0xE4] \n"
"		BHI	loc_FF98AE9C \n"
"		MOV	R0, #0 \n"
"		STR	R0, [R4,#0xE4] \n"
"loc_FF98AE7C: \n"
"		MOV	R0, R4 \n"
// ** the following function captures the image **
"		BL	sub_FFAF97E0 \n"
"		BL     capt_seq_hook_raw_here \n"		// added
"		MOV	R6, R0 \n"
"		B	loc_FF98AEA0 \n"
"loc_FF98AE8C: \n"
"		LDR	R0, =0x7514 \n"
"		LDR	R0, [R0] \n"
"		CMP	R0, #0 \n"
"		BEQ	loc_FF98AEA0 \n"
"loc_FF98AE9C: \n"
"		MOV	R6, #0x1D \n"
"loc_FF98AEA0: \n"

"		MOV	R1, R6 \n"
"		MOV	R0, R4 \n"
"		LDMFD	SP!, {R3-R7,LR} \n"
"		B	sub_FFAF8FD8 \n"
"locret_FF98AEB0: \n"
"		LDMFD	SP!, {R3-R7,PC} \n"
	);
}
