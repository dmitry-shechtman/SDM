#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table[24]={0x2000, 0x38D, 0x788, 0x5800, 0x9C5, 0x14B8, 0x10000, 0x1C6A, 0x3C45, 0x8000, 0xE35, 0x1E23,
           0x1CCD, -0x2E1, -0x579, 0x4F33, -0x7EB, -0xF0C, 0xE666, -0x170A, -0x2BC6, 0x7333, -0xB85, -0x15E3};

long table[24];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<24;i++) table[i]=(def_table[i]*a)/b; 
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


/*----------------------------------------------------------------------
	movie_record_task()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) movie_record_task()
{ 
	asm volatile (
 "		STMFD	SP!, {R2-R8,LR}\n"
"		LDR	R8, =0x346\n"
"		LDR	R7, =0x2710\n"
"		LDR	R4, =0x5748\n"
"		MOV	R6, #0\n"
"		MOV	R5, #1\n"
 "loc_FFD1BDC8:\n"                     // counts frames, single led flash
"           BL      synch_led \n" 
"		LDR	R0, [R4,#0x18]\n"
"		MOV	R2, #0\n"
"		ADD	R1, SP,	#4 \n"
"		BL	sub_FFC2936C\n"
"		LDR	R0, [R4,#0x20]\n"
"		CMP	R0, #0\n"
"		BNE	loc_FFD1BE98\n"
"		LDR	R0, [SP,#0x4]\n"
"		LDR	R1, [R0]\n"
"		SUB	R1, R1,	#2\n"
"		CMP	R1, #9\n"
"		ADDLS	PC, PC,	R1,LSL#2\n"
"		B	loc_FFD1BE98\n"
"loc_FFD1BEDFC:\n"
"		B	loc_FFD1BE4C\n"
"loc_FFD1BEB0:\n"
"		B	loc_FFD1BE6C\n"
"loc_FFD1BEB4:\n"
"		B	loc_FFD1BE7C\n"
"loc_FFD1BEB8:\n"
"		B	loc_FFD1BE84\n"
"loc_FFD1BEBC:\n"
"		B	loc_FFD1BE54\n"
"loc_FFD1BEC0:\n"
"		B	loc_FFD1BE8C\n"
"loc_FFD1BEC4:\n"
"		B	loc_FFD1BE5C\n"
"loc_FFD1BEC8:\n"
"		B	loc_FFD1BE98\n"
"loc_FFD1BECC:\n"
"		B	loc_FFD1BE94\n"
"loc_FFD1BED0:\n"
"		B	loc_FFD1BE24\n"

"loc_FFD1BE24:\n"
// jumptable FFD1BDF4 entry 9              // single blink on start
// "BL      mute_on_zoom\n"
"		LDR	R0, =0xFFD1BB7C\n"
"		STR	R6, [R4,#0x34]\n"
"		STR	R0, [R4,#0xA8]\n"
"		LDR	R0, =0xFFD1B4EC\n"
"		LDR	R2, =0xFFD1B408\n"
"		LDR	R1, =0x72318\n"
"		STR	R6, [R4,#0x24]\n"
"		BL	sub_FFCBDC74\n"
"		STR	R5, [R4,#0x38]\n"
"		B	loc_FFD1BE98\n"

"loc_FFD1BE4C:\n"
// jumptable FFD1BDF4 entry 0                 single blink on start
// "BL      mute_on_zoom\n"
"		BL	unlock_optical_zoom\n"   // added to unlock the zoom
"		BL	sub_FFD1BBC4\n"
"		B	loc_FFD1BE98\n"

"loc_FFD1BE54:\n"
// jumptable FFD1BDF4 entry 4
// "BL      mute_on_zoom\n"
"		BL	sub_FFD1B8CC_my\n"      // patched
"		B	loc_FFD1BE98\n"

"loc_FFD1BE5C:\n"
// "BL      mute_on_zoom\n"              // single blink on start and stop
"		LDR	R1, [R0,#0x10]\n"
"		LDR	R0, [R0,#4]\n"
"		BL	sub_FFE16D60\n"
"		B	loc_FFD1BE98\n"

"loc_FFD1BE6C:\n"
// "BL      mute_on_zoom\n"              // single blink on start and stop
"		LDR	R0, [R4,#0x38]\n"
"		CMP	R0, #5\n"
"		STRNE	R5, [R4,#0x28]\n"
"		B	loc_FFD1BE98\n"

"loc_FFD1BE7C:\n"
// "BL      mute_on_zoom\n"              // single blink on start and stop
"		BL	sub_FFD1B6A8\n"
"		B	loc_FFD1BE98\n"

"loc_FFD1BE84:\n"
//  "BL      mute_on_zoom\n"             // single blink on start and stop
"		BL	sub_FFD1B538\n"
"		B	loc_FFD1BE98\n"

"loc_FFD1BE8C:\n"                       // single blink on start
// "BL      mute_on_zoom\n"
"		BL	sub_FFD1B394\n"
"		B	loc_FFD1BE98\n"

"loc_FFD1BE94:\n"
// "BL      mute_on_zoom\n"               // gDebug counter not incremented
"		BL	sub_FFD1C000\n"

"loc_FFD1BE98:\n"
// jumptable default entry
"		LDR	R1, [SP,#0x4]\n"
"		LDR	R3, =0xFFD1B224\n" // MovieRecorder.c
"		STR	R6, [R1]\n"
"		STR	R8, [SP,#0x0]\n"
"		LDR	R0, [R4,#0x1C]\n"
"		MOV	R2, R7\n"
"		BL	sub_FFC29CC0\n"
"		B	loc_FFD1BDC8\n"
	);
}


/*----------------------------------------------------------------------
	sub_FFD1B8CC_my()
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) sub_FFD1B8CC_my()
{ 
	asm volatile (
"		STMFD	SP!, {R4-R8,LR}\n"
"		SUB	SP, SP,	#0x40\n"
"		MOV	R6, #0\n"
"		LDR	R5, =0x5748\n"
"		MOV	R4, R0\n"
"		STR	R6, [SP,#0x30]\n"
"		STR	R6, [SP,#0x28]\n"
"		LDR	R0, [R5,#0x38]\n"
"		MOV	R8, #4\n"
"		CMP	R0, #3\n"
"		STREQ	R8, [R5,#0x38]\n"
"		LDR	R0, [R5,#0xA8]\n"
"		BLX	R0\n"
"		LDR	R0, [R5,#0x38]\n"
"		CMP	R0, #4\n"
"		BNE	loc_FFD1B9A4\n"
"		ADD	R3, SP,	#0x28\n"
"		ADD	R2, SP,	#0x2C\n"
"		ADD	R1, SP,	#0x30\n"
"		ADD	R0, SP,	#0x34\n"
"		BL	sub_FFE16EF4\n"
"		CMP	R0, #0\n"
"		MOV	R7, #1\n"
"		BNE	loc_FFD1B948\n"
"		LDR	R1, [R5,#0x28]\n"
"		CMP	R1, #1\n"
"		BNE	loc_FFD1B9AC\n"
"		LDR	R1, [R5,#0x60]\n"
"		LDR	R2, [R5,#0x3C]\n"
"		CMP	R1, R2\n"
"		BCC	loc_FFD1B9AC\n"
"loc_FFD1B948:\n"
"		CMP	R0, #0x80000001\n"
"		STREQ	R8, [R5,#0x64]\n"
"		BEQ	loc_FFD1B980\n"
"		CMP	R0, #0x80000003\n"
"		STREQ	R7, [R5,#0x64]\n"
"		BEQ	loc_FFD1B980\n"
"		CMP	R0, #0x80000005\n"
"		MOVEQ	R0, #2\n"
"		BEQ	loc_FFD1B97C\n"
"		CMP	R0, #0x80000007\n"
"		STRNE	R6, [R5,#0x64]\n"
"		BNE	loc_FFD1B980\n"
"		MOV	R0, #3\n"
"loc_FFD1B97C:\n"
"		STR	R0, [R5,#0x64]\n"
"loc_FFD1B980:\n"
"		LDR	R0, =0x72348\n"
"		LDR	R0, [R0,#8]\n"
"		CMP	R0, #0\n"
"		BEQ	loc_FFD1B998\n"
"		BL	sub_FFC48DE4\n"
"		B	loc_FFD1B99C\n"
"loc_FFD1B998:\n"
"		BL	sub_FFD1B394\n"
"loc_FFD1B99C:\n"
"		MOV	R0, #5\n"
"		STR	R0, [R5,#0x38]\n"
"loc_FFD1B9A4:\n"
"		ADD	SP, SP,	#0x40\n"
"		LDMFD	SP!, {R4-R8,PC}\n"
"loc_FFD1B9AC:\n"
"		LDR	LR, [SP,#0x30]\n"
"		CMP	LR, #0\n"
"		BEQ	loc_FFD1BA74\n"
"		STR	R7, [R5,#0x2C]\n"
"		LDR	R0, [R5,#0x7C]\n"
"		LDR	R1, [R4,#0x14]\n"
"		LDR	R2, [R4,#0x18]\n"
"		LDR	R12, [R4,#0xC]\n"
"		ADD	R3, SP,	#0x38\n"
"		ADD	R8, SP,	#0x14\n"
"		STMIA	R8, {R0-R3}\n"
"		LDR	R3, [R5,#0x68]\n"
"		ADD	R2, SP,	#0x3C\n"
"		ADD	R8, SP,	#0x8\n"
"		LDRD	R0, [SP,#0x28]\n"
"		STMIA	R8, {R0,R2,R3}\n"
"		STR	R1, [SP,#0x4]\n"
"		STR	LR, [SP,#0x0]\n"
"		LDMIB	R4, {R0,R1}\n"
"		LDR	R3, [SP,#0x34]\n"
"		MOV	R2, R12\n"
"		BL	sub_FFDEA468\n"
"		LDR	R0, [R5,#0x10]\n"
"		LDR	R1, [R5,#0x58]\n"
"		BL	sub_FFC29788\n"      // eventproc_export_TakeSemaphore
"		CMP	R0, #9\n"
"		BNE	loc_FFD1BA28\n"
"		BL	sub_FFE174E0\n"
"		MOV	R0, #0x90000\n"
"		STR	R7, [R5,#0x38]\n"
"		B	loc_FFD1BA40\n"
"loc_FFD1BA28:\n"
"		LDR	R0, [SP,#0x38]\n"
"		CMP	R0, #0\n"
"		BEQ	loc_FFD1BA48\n"
"		BL	sub_FFE174E0\n"
"		MOV	R0, #0xA0000\n"
"		STR	R7, [R5,#0x38]\n"
"loc_FFD1BA40:\n"
"		BL	sub_FFC74754\n"     // eventproc_export_HardwareDefect
"		B	loc_FFD1B9A4\n"
"loc_FFD1BA48:\n"
"		BL	sub_FFDEA52C\n"
"		LDR	R0, [SP,#0x34]\n"
"		LDR	R1, [SP,#0x3C]\n"
"		BL	sub_FFE17288\n"
"		LDR	R0, [R5,#0x5C]\n"
"		LDR	R1, =0x57C4\n"
"		ADD	R0, R0,	#1\n"
"		STR	R0, [R5,#0x5C]\n"
"		LDR	R0, [SP,#0x3C]\n"
"		MOV	R2, #0\n"
"		BL	sub_FFE150AC\n"
"loc_FFD1BA74:\n"
"		LDR	R0, [R5,#0x60]\n"
"		ADD	R0, R0,	#1\n"
"		STR	R0, [R5,#0x60]\n"
"		LDR	R1, [R5,#0x4C]\n"
"		MUL	R0, R1,	R0\n"
"		LDR	R1, [R5,#0x48]\n"
"		BL	sub_FFEA4850\n"
"		MOV	R4, R0\n"
"		BL	sub_FFE17518\n"
"		LDR	R1, [R5,#0x80]\n"
"		CMP	R1, R4\n"
"		BNE	loc_FFD1BAB0\n"
"		LDR	R0, [R5,#0x30]\n"
"		CMP	R0, #1\n"
"		BNE	loc_FFD1BAC4\n"
"loc_FFD1BAB0:\n"
"		LDR	R1, [R5,#0x8C]\n"
"		MOV	R0, R4\n"
"		BLX	R1\n"
"		STR	R4, [R5,#0x80]\n"
"		STR	R6, [R5,#0x30]\n"
"loc_FFD1BAC4:\n"
"		STR	R6, [R5,#0x2C]\n"
"		B	loc_FFD1B9A4\n"
	);
}

