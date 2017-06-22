#include "lolevel.h"
#include "platform.h"
#include "core.h"
static long *nrflag = (long*)0x9F90;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FFD0D528_my(){ 
 asm volatile(
                 "STMFD   SP!, {R0-R10,LR}\n"
                 "MOV     R6, #0\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FFD0E028\n"
                 "MVN     R1, #0\n"
                 "BL      sub_FFC173EC\n"
                 "MOV     R2, #4\n"
                 "ADD     R1, SP, #8\n"
                 "MOV     R0, #0x8A\n"
                 "BL      sub_FFC57424\n"
                 "TST     R0, #1\n"
                 "LDRNE   R1, =0x218\n"
                 "LDRNE   R0, =0xFFD0D73C\n"
                 "BLNE    sub_FFC0BDB8\n"
                 "LDR     R8, =0x1977C\n"
                 "LDR     R5, =0x196D0\n"
                 "LDRSH   R1, [R8,#0xE]\n"
                 "LDR     R0, [R5,#0x74]\n"
                 "BL      sub_FFCCBC30\n"
                 "BL      sub_FFC3302C\n"
                 "LDR     R2, =0x88DC\n"
                 "ADD     R3, R4, #0x8C\n"
                 "STRH    R0, [R4,#0x88]\n"
                 "STR     R2, [SP]\n"  //Was "STRD    R2, [SP,#0x30-0x30]\n"
                 "STR     R3, [SP,#4]\n" //
                 "MOV     R1, R0\n"
                 "LDRH    R0, [R5,#0x4C]\n"
                 "LDRSH   R2, [R8,#0xC]\n"
                 "LDR     R3, =0x88D8\n"
				 "BL      sub_FFD0E514\n"
                 "BL      wait_until_remote_button_is_released\n"
                 "BL      capt_seq_hook_set_nr\n"
                 "B       sub_FFD0D59C\n"
 );
}

void __attribute__((naked,noinline)) task_CaptSeqTask_my() //#fs
{
	asm volatile (
                "STMFD   SP!, {R3-R7,LR}\n"
                "LDR     R6, =0x52F8\n"

"loc_FFC48DC8:\n"
                "LDR     R0, [R6,#8]\n"
                "MOV     R2, #0\n"
                "MOV     R1, SP\n"
                "BL      sub_FFC1763C\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFC48DF4\n"
                "LDR     R1, =0x48E\n"
                "LDR     R0, =0xFFC48AE8\n" // aSsshoottask_c ; SsShootTask.c
                "BL      sub_FFC0BDB8\n"    // Assert
                "BL      sub_FFC0BB70\n"    // ExitTask
                "LDMFD   SP!, {R3-R7,PC}\n"

"loc_FFC48DF4:\n"
                //LDR     R0, [SP,#0x18+var_18]
                "LDR     R0, [SP]\n"
                "LDR     R1, [R0]\n"

                "LDR     R2, =0x1850\n"         // DEBUG: Save jumptable-target ...
                "STR     R1, [R2]\n"            // ...to some unused space. Read and displayed in GUI in core/gui.c

                "CMP     R1, #0x19\n"
                "ADDLS   PC, PC, R1,LSL#2\n"
                "B       loc_FFC49008\n"        // 0: error handler (invalid jump offset) (also when shutter half-pressed?)

                "B       loc_FFC48E70\n"        // 1: immediately after shutter release, !modify this one!
                "B       loc_FFC48E78\n"
                "B       loc_FFC48EF8\n"        // 3: default if shutter not pressed
                "B       loc_FFC48F0C\n"        // 4: after shutter release, when timed image preview active
                "B       loc_FFC48F04\n"        // 5: after shutter release, in detailed image review
                "B       loc_FFC48F14\n"
                "B       loc_FFC48F1C\n"
                "B       loc_FFC48F28\n"
                "B       loc_FFC48F80\n"        // 9: also ends with continuation of #1
                "B       loc_FFC48F0C\n"        // 10:
                "B       loc_FFC48F88\n"        // 11:
                "B       loc_FFC48F90\n"        // 12:
                "B       loc_FFC48F98\n"        // 13:
                "B       loc_FFC48FA0\n"        // 14:
                "B       loc_FFC48FA8\n"        // 15: in image-viewer
                "B       loc_FFC48FB4\n"
                "B       loc_FFC48FBC\n"
                "B       loc_FFC48FC4\n"
                "B       loc_FFC48FCC\n"
                "B       loc_FFC48FD8\n"
                "B       loc_FFC48FE0\n"
                "B       loc_FFC48FE8\n"
                "B       loc_FFC48FF0\n"
                "B       loc_FFC48FF8\n"
                "B       loc_FFC49000\n"
                "B       loc_FFC49014\n"
"loc_FFC48E70:\n"                               // #1
                "BL      sub_FFD0C090\n"        
                "BL      shooting_expo_param_override\n"  // +
                "B       loc_FFC48F20\n"
"loc_FFC48E78:\n" 
"     BL    shooting_set_flash_override\n"                              // #2
                "LDR     R4, [R0,#0xC]\n"
                "LDR     R0, [R4,#8]\n"
                "ORR     R0, R0, #1\n"
                "STR     R0, [R4,#8]\n"
				"BL      sub_FFD0C080\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0C468\n"
                "TST     R0, #1\n"
                "MOVNE   R2, R4\n"
                "MOVNE   R1, #1\n"
                "BNE     loc_FFC48F78\n"
                "BL      sub_FFD2ABAC\n"
                "BL      sub_FFC575B4\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D460\n"
                "BL      sub_FFD0DEC4\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D528_my\n"         //--------------> 
                "BL      capt_seq_hook_raw_here\n"  //-------------->
				"MOV     R5, R0\n"
				"BL		 sub_FFD0EEA4\n"
				"BL      sub_FFD0EEE0\n"
                "MOV     R2, R4\n"
                "MOV     R1, #1\n"
				"MOV     R0, R5\n"
                "BL      sub_FFC4759C\n"
                "BL      sub_FFD0D8D8\n"
                "CMP     R0, #0\n"
                "LDRNE   R0, [R4,#8]\n"
                "ORRNE   R0, R0, #0x2000\n"
                "STRNE   R0, [R4,#8]\n"
                "B       loc_FFC49014\n"
"loc_FFC48EF8:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD0C224\n"
                "B       loc_FFC49014\n"
"loc_FFC48F04:\n"
                "BL      sub_FFD0BCF0\n"
                "B       loc_FFC49014\n"
"loc_FFC48F0C:\n"
                "BL      sub_FFD0C070\n"
                "B       loc_FFC49014\n"
"loc_FFC48F14:\n"
                "BL      sub_FFD0C078\n"
                "B       loc_FFC49014\n"
"loc_FFC48F1C:\n"
                "BL      sub_FFD0C144\n"
"loc_FFC48F20:\n"
                "BL      sub_FFC4721C\n"
                "B       loc_FFC49014\n"
"loc_FFC48F28:\n"
                "LDR     R4, [R0,#0xC]\n"
                "BL      sub_FFD0C080\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0C7E8\n"
                "TST     R0, #1\n"
                "MOV     R5, R0\n"
                "BNE     loc_FFC48F68\n"
                "BL      sub_FFC575B4\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D460\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D938\n"
                "MOV     R5, R0\n"
                "LDR     R0, [R4,#0x14]\n"
                "BL      sub_FFC577C0\n"
"loc_FFC48F68:\n"
                "BL      sub_FFD0C070\n"
                "MOV     R2, R4\n"
                "MOV     R1, #9\n"
                "MOV     R0, R5\n"
"loc_FFC48F78:\n"
                "BL      sub_FFC4759C\n"
                "B       loc_FFC49014\n"
"loc_FFC48F80:\n"
                "BL      sub_FFD0C1A4\n"
                "B       loc_FFC48F20\n"
"loc_FFC48F88:\n"
                "BL      sub_FFD0CA64\n"
                "B       loc_FFC49014\n"
"loc_FFC48F90:\n"
                "BL      sub_FFD0CC4C\n"
                "B       loc_FFC49014\n"
"loc_FFC48F98:\n"
                "BL      sub_FFD0CCDC\n"
                "B       loc_FFC49014\n"
"loc_FFC48FA0:\n"
                "BL      sub_FFD0CD90\n"
                "B       loc_FFC49014\n"
"loc_FFC48FA8:\n"
                "MOV     R0, #0\n"
				"BL      sub_FFD0CF34\n"
                "B       loc_FFC49014\n"
"loc_FFC48FB4:\n"
                "BL      sub_FFD0D084\n"
                "B       loc_FFC49014\n"
"loc_FFC48FBC:\n"
                "BL      sub_FFD0D118\n"
                "B       loc_FFC49014\n"
"loc_FFC48FC4:\n"
                "BL      sub_FFD0D1E0\n"
                "B       loc_FFC49014\n"
"loc_FFC48FCC:\n"
				"BL      sub_FFD0C340\n"
				"BL      sub_FFC149A0\n"
				"B       loc_FFC49014\n"
"loc_FFC48FD8:\n"
				"BL      sub_FFD0CE4C\n"
				"B       loc_FFC49014\n"
"loc_FFC48FE0:\n"
                "BL      sub_FFD0CE90\n"
				"B       loc_FFC49014\n"
"loc_FFC48FE8:\n"
                "BL      sub_FFD0EE88\n"
                "B       loc_FFC49014\n"
"loc_FFC48FF0:\n"
                "BL      sub_FFD0EEA4\n"
                "B       loc_FFC49014\n"
"loc_FFC48FF8:\n"
                "BL      sub_FFD0EEB4\n"
                "B       loc_FFC49014\n"
"loc_FFC49000:\n"
                "BL      sub_FFD0EEE0\n"
                "B       loc_FFC49014\n"
"loc_FFC49008:\n"
                "LDR     R1, =0x58E\n"
                "LDR     R0, =0xFFC48AE8\n" // aSsshoottask_c ; SsShootTask.c
                "BL      sub_FFC0BDB8\n"    // Assert
"loc_FFC49014:\n"
                //"LDR     R0, [SP,#0x18+var_18]\n"
                "LDR     R0, [SP]\n"
                "LDR     R1, [R0,#4]\n"
                "LDR     R0, [R6,#4]\n"
                "BL      sub_FFC173B8\n"
                //"LDR     R4, [SP,#0x18+var_18]\n"
                "LDR     R4, [SP]\n"
                "LDR     R0, [R4,#8]\n"
                "CMP     R0, #0\n"
                "LDREQ   R1, =0x10D\n"
                "LDREQ   R0, =0xFFC48AE8\n" // aSsshoottask_c ; SsShootTask.c
                "BLEQ    sub_FFC0BDB8\n"    // Assert
                "MOV     R0, #0\n"
                "STR     R0, [R4,#8]\n"
                "B       loc_FFC48DC8\n"
    );
} //#fe
