#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"


//VERIFY_SD780 ALL stuff below...

static long *nrflag = (long*)0x6048; // see below
#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FF91F5BC_my() {
	asm volatile (
"                 STMFD   SP!, {R0-R8,LR}\n"
"                 MOV     R4, R0\n"
"                 BL      sub_FF920314\n" // SsShootEvent.c:60\n"
"                 MVN     R1, #0\n"
"                 BL      sub_FF8661AC\n"
"                 LDR     R5, =0x6048\n"
"                 LDR     R0, [R5, #0xC]\n"
"                 CMP     R0, #0\n"
"                 BNE     loc_FF91F60C\n"
"                 MOV     R1, #1\n"
"                 MOV     R0, #0\n"
"                 BL      sub_FF8271C0\n"
"                 STR     R0, [R5, #0xC]\n"
"                 MOV     R3, #0\n"
"                 STR     R3, [SP]\n"
"                 LDR     R3, =0xFF91F078\n"
"                 LDR     R0, =0xFF91F83C\n"  //VERIFY_SD780 "ADR R0, aShuttersoundta"
"                 MOV     R2, #0x400\n"
"                 MOV     R1, #0x17\n"
"                 BL      sub_FF82718C\n"
"loc_FF91F60C:\n"
"                 MOV     R2, #4\n"
"                 ADD     R1, SP, #8\n"
"                 MOV     R0, #0x8A\n"
"                 BL      sub_FF86E284\n" // PT_GetPropertyCaseString_0 ; LOCATION: PropertyCase.c:0\n"
"                 TST     R0, #1\n"
"                 LDRNE   R1, =0x3AE\n"
"                 LDRNE   R0, =0xFF91F310\n" // "SsCaptureSeq.c"
"                 BLNE    sub_FF81B284\n" // DebugAssert\n"
"                 LDR     R8, =0x145E4\n"
"                 LDR     R7, =0x14520\n"
"                 LDRSH   R1, [R8,#0xE]\n"
"                 LDR     R0, [R7,#0x8C]\n"
"                 BL      sub_FF8E18CC\n"
"                 BL      sub_FF845EBC\n" // GetCCDTemperature ; LOCATION: Thermometer.c:250\n"
"                 LDR     R3, =0x6050\n"
"                 STRH    R0, [R4,#0x9C]\n"
"                 SUB     R2, R3, #4\n"
//"                 STRD    R2, [SP]\n"
"                 STR    R2, [SP]\n"
"                 MOV     R1, R0\n"
"                 LDRH    R0, [R7,#0x5C]\n"
"                 LDRSH   R2, [R8,#0xC]\n"
"                 SUB     R3, R3, #8\n"
"                 BL      sub_FF92194C\n" // NRTable.c:219\n"
"                 BL      wait_until_remote_button_is_released\n"
"                 BL      capt_seq_hook_set_nr\n"
"                 B       sub_FF91F668\n" // -> continue function in firmware
    );
}

void __attribute__((naked,noinline)) sub_FF85DB34_my() {
	asm volatile (
"                STMFD   SP!, {R4-R6,LR}\n"
"                LDR     R4, [R0,#0xC]\n"
"                LDR     R6, =0x14520\n"
"                LDR     R0, [R4,#8]\n"
"                MOV     R5, #0\n"
"                ORR     R0, R0, #1\n"
"                STR     R0, [R4,#8]\n"
"                LDR     R0, [R6,#0x24]\n"
"                CMP     R0, #0\n"
"                MOVEQ   R0, #2\n"
"                BLEQ    sub_FF858E7C\n"
"                BL      sub_FF85E064\n"
"                LDR     R0, [R6,#0x24]\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF85DBE4\n"
"                MOV     R0, #0\n"
"                BL      sub_FF9201A4\n"
"                MOV     R0, R4\n"
"                BL      sub_FF85E3B4\n"
"                MOV     R0, R4\n"
"                BL      sub_FF91E1F0\n"
"                CMP     R0, #0\n"
"                BEQ     loc_FF85DBB4\n"
"                BL      sub_FF9201E4\n"
"                MOV     R0, R4\n"
"                BL      sub_FF91E2D4\n" // SsPrePreSeq.c:0
"                TST     R0, #1\n"
"                MOVNE   R2, R4\n"
"                LDMNEFD SP!, {R4-R6,LR}\n"
"                MOVNE   R1, #1\n"
"                BNE     sub_FF85BABC\n" // SsShootCtrl.c:0
"                B       loc_FF85DBC0\n"
"loc_FF85DBB4:\n"
"                MOV     R0, R4\n"
"                BL      sub_FF91E270\n"
"                BL      sub_FF9201E4\n"
"loc_FF85DBC0:\n"
"                MOV     R0, R4\n"
"                BL      sub_FF85D260\n"
"                MOV     R0, R4\n"
"                BL      sub_FF91F4D4\n" // SsCaptureSeq.c:1
"                BL      sub_FF920034\n" // SsShootLib.c:32768
"                MOV     R0, R4\n"
"                BL      sub_FF91F5BC_my\n" // SsCaptureSeq.c:0 nr setup
//"                BL      sub_FF91F5BC\n" // SsCaptureSeq.c:0 nr setup
"                BL      capt_seq_hook_raw_here\n"
"                MOV     R5, R0\n"
"                B       loc_FF85DBF4\n"
"loc_FF85DBE4:\n"
"                LDR     R0, =0x291C\n"
"                LDR     R0, [R0,#0x10]\n"
"                CMP     R0, #0\n"
"                MOVNE   R5, #0x1D\n"
"loc_FF85DBF4:\n"
"                BL      sub_FF860908\n"
"                BL      sub_FF860950\n"
"                BL      sub_FF860990\n"
"                MOV     R2, R4\n"
"                MOV     R1, #1\n"
"                MOV     R0, R5\n"
"                BL      sub_FF85BABC\n" // SsShootCtrl.c:0
"                BL      sub_FF91F868\n"
"                CMP     R0, #0\n"
"                LDRNE   R0, [R4,#8]\n"
"                ORRNE   R0, R0, #0x2000\n"
"                STRNE   R0, [R4,#8]\n"
"                LDMFD   SP!, {R4-R6,PC}\n"
    );
}


//VERIFY_SD780 - Below this is good ASM but needs work still...
void __attribute__((naked,noinline)) task_CaptSeqTask_my() {
	asm volatile (
"                STMFD   SP!, {R3-R9,LR}\n"
"                LDR     R6, =0x291C\n"
"                LDR     R4, =0x14520\n"
"                MOV     R9, #1\n"
"                MOV     R7, #0\n"
"loc_FF85D768:\n"
"                LDR     R0, [R6,#0x4]\n"
"                MOV     R2, #0\n"
"                MOV     R1, SP\n"
"                BL      sub_FF826978\n" //  KerQueue.c
"                TST     R0, #1\n"
"                BEQ     loc_FF85D794\n"
"                LDR     R1, =0x588\n"
"                LDR     R0, =0xFF85D2E0\n" // "SsShootTask.c"
"                BL      sub_FF81B284\n" // DebugAssert
"                BL      sub_FF81B23C\n" // ExitTask
"                LDMFD   SP!, {R3-R9,PC}\n"
"loc_FF85D794:\n"
"                LDR     R0, [SP]\n"
"                LDR     R1, [R0]\n"
"                CMP     R1, #0x1D\n"
"                ADDLS   PC, PC, R1,LSL#2\n"
"                B       loc_FF85DA10\n"
"loc_FF85D7A8:\n"
"                B       loc_FF85D820\n"
"loc_FF85D7AC:\n"
"                B       loc_FF85D884\n"
"loc_FF85D7B0:\n"
"                B       loc_FF85D8C0\n"
"loc_FF85D7B4:\n"
"                B       loc_FF85D8D4\n"
"loc_FF85D7B8:\n"
"                B       loc_FF85D8CC\n"
"loc_FF85D7BC:\n"
"                B       loc_FF85D8DC\n"
"loc_FF85D7C0:\n"
"                B       loc_FF85D8E4\n"
"loc_FF85D7C4:\n"
"                B       loc_FF85D8EC\n"
"loc_FF85D7C8:\n"
"                B       loc_FF85D944\n"
"loc_FF85D7CC:\n"
"                B       loc_FF85D96C\n"
"loc_FF85D7D0:\n"
"                B       loc_FF85D950\n"
"loc_FF85D7D4:\n"
"                B       loc_FF85D95C\n"
"loc_FF85D7D8:\n"
"                B       loc_FF85D964\n"
"loc_FF85D7DC:\n"
"                B       loc_FF85D974\n"
"loc_FF85D7E0:\n"
"                B       loc_FF85D97C\n"
"loc_FF85D7E4:\n"
"                B       loc_FF85D984\n"
"loc_FF85D7E8:\n"
"                B       loc_FF85D98C\n"
"loc_FF85D7EC:\n"
"                B       loc_FF85D994\n"
"loc_FF85D7F0:\n"
"                B       loc_FF85D9A0\n"
"loc_FF85D7F4:\n"
"                B       loc_FF85D9A8\n"
"loc_FF85D7F8:\n"
"                B       loc_FF85D9B0\n"
"loc_FF85D7FC:\n"
"                B       loc_FF85D9B8\n"
"loc_FF85D800:\n"
"                B       loc_FF85D9C0\n"
"loc_FF85D804:\n"
"                B       loc_FF85D9CC\n"
"loc_FF85D808:\n"
"                B       loc_FF85D9D4\n"
"loc_FF85D80C:\n"
"                B       loc_FF85D9DC\n"
"loc_FF85D810:\n"
"                B       loc_FF85D9E4\n"
"loc_FF85D814:\n"
"                B       loc_FF85D9EC\n"
"loc_FF85D818:\n"
"                B       loc_FF85D9F8\n"
"loc_FF85D81C:\n"
"                B       loc_FF85DA1C\n"
"loc_FF85D820:\n"
// jumptable FF85D7A0 entry 0: halfpress in shoot mode, or full press if quick
"                BL      sub_FF85E074\n" // SsPrepareSeq_c
////"                BL      shooting_expo_param_override\n"  // +
"    STMFD   SP!, {R1-R12,LR}\n"
"    BL      captseq_hack_override_active\n" // returns 1 if tv or sv override in effect
"    LDMFD   SP!, {R1-R12,LR}\n"
"    STR     R0,[SP,#-4]!\n" // push return value
"    BL      shooting_expo_param_override\n" // saves all regs
//"                BL      sub_FF863F08\n"
"                BL      sub_FF85B5A8\n"
"    LDR     R0,[SP],#4\n" // pop override hack
"    CMP     R0, #1\n"
"    MOVEQ   R0, #0\n"
"    STREQ   R0, [R4,#0x24]\n"  // fixes overrides behavior at short shutter press
////"                BL      sub_FF863F08\n"
///*
// //  this code added to avoid some incorrect behavior if overrides are used.
// //  but it can cause some unexpected side effects. In this case, remove this code!

//                 "LDR     R0, =ovr_disable\n"
//                 "LDR     R0, [R0]\n"
//                 "LDR     R0, [R0]\n"
//                 "CMP     R0, #1\n"
//                 "BEQ     locA\n"
//                 "MOV     R0, #0\n"
//                 "STR     R0, [R4,#0x24]\n"  // fixes overrides  behavior at short shutter press
////               "STR     R0, [R4,#0x1C]\n"
//                 "B       loc_FF8661C8\n"
//"locA:\n"

// //  end of my code
//*/

//"                BL      sub_FF85E074\n" // SsPrepareSeq_c
//"				 BL		 sub_FF85B5A8\n"  //above removes this????
"                LDR     R0, [R4,#0x24]\n"
"                CMP     R0, #0\n"
"                BEQ     loc_FF85DA1C\n" // -> jt 32, loop
"                BL      sub_FF85CFBC\n"
"                MOV     R5, R0\n"
"                LDR     R0, [R4,#0x24]\n"
"                CMP     R0, #0\n"
"                BEQ     loc_FF85D868\n"
"                MOV     R0, #0xC\n"
"                BL      sub_FF862090\n"
"                TST     R0, #1\n"
"                STRNE   R9, [R6,#0x10]\n"
"                LDRNE   R0, [R5,#8]\n"
"                ORRNE   R0, R0, #0x40000000\n"
"                STRNE   R0, [R5,#8]\n"
"                BNE     loc_FF85DA1C\n" // -> jt 32, loop
"loc_FF85D868:\n"
"                MOV     R0, R5\n"
"                BL      sub_FF85D260\n"
"                MOV     R0, R5\n"
"                BL      sub_FF91F5BC\n" // nr setup, hook here too ?
"                TST     R0, #1\n"
"                STRNE   R9, [R6,#0x10]\n"
"                B       loc_FF85DA1C\n" // -> jt 32, loop

"loc_FF85D884:\n"
// jumptable FF865F58 entry 1: called 1+ sec after entry 0, i.e. shooting near complete
"     BL    shooting_set_flash_override\n"
"				 LDR     R0, [R4,#0x24]\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF85D8B0\n"
"                MOV     R0, #0xC\n"
"                BL      sub_FF862090\n"
"                TST     R0, #1\n"
"                LDRNE   R0, [SP]\n"
"                MOVNE   R1, #1\n"
"                LDRNE   R2, [R0,#0xC]\n"
"                MOVNE   R0, #1\n"
"                BNE     loc_FF85D93C\n"

"loc_FF85D8B0:\n"
"                LDR     R0, [SP]\n"
"                BL      sub_FF85DB34_my\n"  //HERE is the above functions...

"loc_FF85D8B8:\n"
"                STR     R7, [R4,#0x24]\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D8C0:\n"
// jumptable FF865F58 entry 2
"                MOV     R0, #1\n"
"                BL      sub_FF85E28C\n"
"                B       loc_FF85DA1C\n" // jt 32, loop

"loc_FF85D8CC:\n"
// jumptable FF865F58 entry 4 // called in shooting, after first call to 32
"                BL      sub_FF85DCBC\n"
"                B       loc_FF85D8B8\n"

"loc_FF85D8D4:\n"
// jumptable FF865F58 entry 3: last call after shot, also called switching from play->shoot
"                BL      sub_FF85E054\n"
"                B       loc_FF85D8B8\n" // -> middle of jt 4

"loc_FF85D8DC:\n"
// jumptable FF865F58 entry 5
"                BL      sub_FF85E05C\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D8E4:\n"
// jumptable FF865F58 entry 6
"                BL      sub_FF85E1AC\n"
"                B       loc_FF85D948\n" // -> middle of jt 8

"loc_FF85D8EC:\n"
// jumptable FF865F58 entry 7
"                LDR     R5, [R0,#0xC]\n"
"                BL      sub_FF85E064\n"
"                MOV     R0, R5\n"
"                BL      sub_FF91E5A0\n"
"                TST     R0, #1\n"
"                MOV     R8, R0\n"
"                BNE     loc_FF85D92C\n"
"                BL      sub_FF86E414\n"
"                STR     R0, [R5,#0x18]\n"
"                MOV     R0, R5\n"
"                BL      sub_FF91F4D4\n"
"                MOV     R0, R5\n"
"                BL      sub_FF91F8C4\n"
"                MOV     R8, R0\n"
"                LDR     R0, [R5,#0x18]\n"
"                BL      sub_FF86E628\n"

"loc_FF85D92C:\n"
"                BL      sub_FF85E054\n"
"                MOV     R2, R5\n"
"                MOV     R1, #9\n"
"                MOV     R0, R8\n"

"loc_FF85D93C:\n"
"                BL      sub_FF85BABC\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D944:\n"
// jumptable FF865F58 entry 8: movie mode half press ?
"                BL      sub_FF85E20C\n"
"loc_FF85D948:\n"
"                BL      sub_FF85B5A8\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D950:\n"
// jumptable FF865F58 entry 10
"                LDR     R0, [R4,#0x54]\n"
"                BL      sub_FF85E620_my\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D95C:\n"
// jumptable FF865F58 entry 11
"                BL      sub_FF85E8D4\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D964:\n"
// jumptable FF865F58 entry 12
"                BL      sub_FF85E968\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D96C:\n"
// jumptable FF865F58 entry 9
"                BL      sub_FF85E054\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D974:\n"
// jumptable FF865F58 entry 13
"                BL      sub_FF91E7B0\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D97C:\n"
// jumptable FF865F58 entry 14
"                BL      sub_FF91E998\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D984:\n"
// jumptable FF865F58 entry 15
"                BL      sub_FF91EA28\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D98C:\n"
// jumptable FF865F58 entry 16
"                BL      sub_FF91EADC\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D994:\n"
// jumptable FF865F58 entry 17
"                MOV     R0,#0\n"
"                BL      sub_FF91ED00\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9A0:\n"
// jumptable FF865F58 entry 18
"                BL      sub_FF91EE38\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9A8:\n"
// jumptable FF865F58 entry 19
"                BL      sub_FF91EEC8\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9B0:\n"
// jumptable FF865F58 entry 20
"                BL      sub_FF91EF88\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9B8:\n"
// jumptable FF865F58 entry 21: focus mode to mf
"                BL      sub_FF85E40C\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9C0:\n"
// jumptable FF865F58 entry 22: halfpress to shoot, focus mode change except MF
"                BL      sub_FF85E4AC\n"
"                BL      sub_FF824A04\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9CC:\n"
// jumptable FF865F58 entry 23
"                BL      sub_FF91EB98\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9D4:\n"
// jumptable FF865F58 entry 24
"                BL      sub_FF91EC04\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9DC:\n"
// jumptable FF865F58 entry 25
"                BL      sub_FF8608A0\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9E4:\n"
// jumptable FF865F58 entry 26
"                BL      sub_FF860908\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9EC:\n"
// jumptable FF865F58 entry 27: iso change
"                BL      sub_FF860964\n"
"                BL      sub_FF860924\n"
"                B       loc_FF85DA1C\n"

"loc_FF85D9F8:\n"
// jumptable FF865F58 entry 28
"                MOV     R0, #1\n"
"                BL      sub_FF9201A4\n"
"                LDRH    R0, [R4, #0x98]\n"
"                CMP     R0, #4\n"
"                BLNE    sub_FF860BD0\n"
"                B       loc_FF85DA1C\n"
"loc_FF85DA10:\n"
// jumptable FF865F58 default entry
"                LDR     R1, =0x6C9\n"
"                LDR     R0, =0xFF85D2E0\n" // "SsShootTask.c"
"                BL      sub_FF81B284\n" // DebugAssert

"loc_FF85DA1C:\n"
// jumptable FF865F58 entry 29: Most continue here
// also called explicitly in shoot after 1 and 30, and on pb -> shoot 2x
"                LDR     R0, [SP]\n"
"                LDR     R1, [R0,#4]\n"
"                LDR     R0, [R6]\n"
"                BL      sub_FF866178\n"
"                LDR     R5, [SP]\n"
"                LDR     R0, [R5,#8]\n"
"                CMP     R0, #0\n"
"                LDREQ   R1, =0x12B\n"
"                LDREQ   R0, =0xFF85D2E0\n" // "SsShootTask.c"
"                BLEQ    sub_FF81B284\n" // DebugAssert
"                STR     R7, [R5,#8]\n"
"                B       loc_FF85D768\n" // -> main loop
    );
}

void __attribute__((naked,noinline)) sub_FF85E620_my() {
	asm volatile (
			"                 STMFD   SP!, {R4-R9,LR}\n"
			"                 MOV     R9, R0\n"
			"                 MOV     R0, #0x41\n"
			"                 SUB     SP, SP, #0x3C\n"
			"                 MOV     R6, #0\n"
			"                 STR     R0, [SP,#0x38]\n"
			"                 BL      sub_FF85E5F0\n"
			"                 CMP     R0, #0\n"
			"                 LDRNE   R1, =0x18F\n"
			"                 BNE     sub_FF85E7E4\n"
			"                 LDR     R5, =0x2944\n"
			"                 LDR     R1, =0x40E\n"
			"                 LDR     R0, [R5,#4]\n"
			"                 BL      sub_FF8661AC\n"
			"                 BL      sub_FF86E414\n"
			"                 STR     R0, [R5,#8]\n"
			"                 MOV     R0, #0\n"
			"                 BL      sub_FF868480\n"
			"                 STR     R0, [SP,#0x2C]\n"
			"                 ADD     R0, SP, #0x2C\n"
			"                 ADD     R1, SP, #0x4\n"
			"                 BL      sub_FF867F08\n"
			"                 ADD     R0, SP, #0x4\n"
			"                 BL      sub_FF867DF0\n"
			"                 STR     R0, [SP,#0x30]\n"
			"                 LDR     R0, [R5,#8]\n"
			"                 MOV     R3, #4\n"
			"                 ADD     R2, SP, #0x30\n"
			"                 MOV     R1, #0x34\n"
			"                 BL      sub_FF86E734\n"
			"                 LDR     R8, [SP,#0x30]\n"
			"                 BL      sub_FF85EA6C_my\n"
			"                 B       sub_FF85E6A0\n"
    );
}

void __attribute__((naked,noinline)) sub_FF85EA6C_my() {
	asm volatile (
			"                 STMFD   SP!, {R4,LR}\n"
			"                 SUB     SP, SP, #0x18\n"
			"                 ADD     R1, SP, #0x14\n"
			"                 MOV     R2, #1\n"
			"                 MOV     R0, #0x5F\n"
			"                 BL      sub_FF86E284\n" //PT_GetPropertyCaseString_0
			"                 TST     R0, #1\n"
			"                 LDRNE   R1, =0x105\n"
			"                 LDRNE   R0, =0xFF85E930\n" //aSsmovierec_c
			"                 BLNE    sub_FF81B284\n" //DebugAssert
			"                 MOV     R0, #0\n"
			"                 BL      sub_FF8AF4F8\n"
			"                 STR     R0, [SP,#0x10]\n"
			"                 MOV     R0, #0\n"
			"                 BL      sub_FF8B130C\n"
			"                 STR     R0, [SP,#0xC]\n"
			"                 LDRB    R0, [SP,#0x14]\n"
			"                 BL      sub_FF8AF4F8\n"
			"                 STR     R0, [SP,#0x8]\n"
			"                 LDRB    R0, [SP,#0x14]\n"
			"                 BL      sub_FF8B130C\n"
			"                 LDR     R4, =0x2944\n"
			"                 STR     R0, [SP,#0x4]\n"
			"                 LDR     R0, [R4,#8]\n"
			"                 MOV     R3, #4\n"
			"                 ADD     R2, SP, #0x10\n"
			"                 MOV     R1, #0x99\n"
			"                 BL      sub_FF86E734\n"
			"                 LDR     R0, [R4,#8]\n"
			"                 MOV     R3, #4\n"
			"                 ADD     R2, SP, #0xC\n"
			"                 MOV     R1, #0x9A\n"
			"                 BL      sub_FF86E734\n"
			"                 LDR     R1, =0x111\n"
			"                 LDR     R0, [R4,#8]\n"
			"                 MOV     R3, #4\n"
			"                 ADD     R2, SP, #0x8\n"
			"                 BL      sub_FF86E734\n"
			"                 LDR     R1, =0x112\n"
			"                 LDR     R0, [R4,#8]\n"
			"                 MOV     R3, #4\n"
			"                 ADD     R2, SP, #0x4\n"
			"                 BL      sub_FF86E734\n"
			"                 LDR     R0, =0x14520\n"
			"                 ADD     R2, SP, #0xC\n"
			"                 LDRH    R0, [R0,#0x44]\n"
			"                 ADD     R1, SP, #0x10\n"
			"                 BL      sub_FF8621C4_my\n"  //mine mine mine!!!!
			"                 B       sub_FF85EB2C\n"
    );
}

void __attribute__((naked,noinline)) sub_FF8621C4_my() {
	asm volatile (
			"                CMP     R0, #4\n"
			"                MOV     R3, #0\n"
			"                MOV     R12, #0\n"
			"                ADDLS   PC, PC, R0,LSL#2\n"
			"                B       loc_FF862218\n"
			"loc_FF8621D8:\n"
			"                B       loc_FF8621EC\n"
			"loc_FF8621DC:\n"
			"                B       loc_FF8621F8\n"
			"loc_FF8621E0:\n"
			"                B       loc_FF862204\n"
			"loc_FF8621E4:\n"
			"                B       loc_FF862218\n"
			"loc_FF8621E8:\n"
			"                B       loc_FF862210\n"
			"loc_FF8621EC:\n"
			//; jumptable FF8621D0 entry 0
			"                MOV     R3, #0x500\n" //0xA0
			"                MOV     R12, #0x2D0\n" //0x78
			"                B       sub_FF862218\n"
			"loc_FF8621F8:\n"
			//; jumptable FF8621D0 entry 1
			"                MOV     R3, #0x500\n" //0x140
			"                MOV     R12, #0x2D0\n" //0xF0
			"                B       sub_FF862218\n"
			"\n"
			"loc_FF862204:\n"

			//; jumptable FF8621D0 entry 2
			"                MOV     R3, #0x500\n" //0x280
			"                MOV     R12, #0x2D0\n" //0x1E0
			"                B       sub_FF862218\n"
			"loc_FF862210:\n"
			//; jumptable FF8621D0 entry 4
			"                MOV     R3, #0x500\n" //0x500
			"                MOV     R12, #0x2D0\n" //0x2D0
			"loc_FF862218:\n"
			//; jumptable FF8621D0 default entry
			//; jumptable FF8621D0 entry 3
			"                CMP     R1, #0\n"
			"                STRNE   R3, [R1]\n"
			"                CMP     R2, #0\n"
			"                STRNE   R12, [R2]\n"
			"                BX      LR\n"
    );
}

