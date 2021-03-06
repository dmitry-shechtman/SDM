#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

//found at ROM:FFD18E60
static long *nrflag = (long*)0x6690;

#include "../../../generic/capt_seq.c"
void __attribute__((naked,noinline)) capt_seq_task() {
 asm volatile (
                 "STMFD   SP!, {R3-R7,LR}\n"
                 "LDR     R7, =0x13C94\n"
                 "LDR     R6, =0x2AD0\n"
 "loc_FFC4F64C:\n"
                 "LDR     R0, [R6,#4]\n"
                 "MOV     R2, #0\n"
                 "MOV     R1, SP\n"
                 "BL      sub_FFC1659C\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FFC4F678\n"
                 "LDR     R1, =0x5B4\n"
                 "LDR     R0, =0xFFC4EF30\n"	// aSsshoottask_c
                 "BL      sub_FFC0B048\n"	// DebugAssert
                 "BL      sub_FFC0B000\n"	// eventproc_export_ExitTask
                 "LDMFD   SP!, {R3-R7,PC}\n"
 "loc_FFC4F678:\n"
                 "LDR     R0, [SP]\n"
                 "LDR     R1, [R0]\n"
                 "CMP     R1, #0x21\n"
                 "ADDLS   PC, PC, R1,LSL#2\n"
                 "B       loc_FFC4F8AC\n"
 "loc_FFC4F68C:\n"
                 "B       loc_FFC4F714\n"
 "loc_FFC4F690:\n"
                 "B       loc_FFC4F71C\n"
 "loc_FFC4F694:\n"
                 "B       loc_FFC4F744\n"
 "loc_FFC4F698:\n"
                 "B       loc_FFC4F758\n"
 "loc_FFC4F69C:\n"
                 "B       loc_FFC4F750\n"
 "loc_FFC4F6A0:\n"
                 "B       loc_FFC4F760\n"
 "loc_FFC4F6A4:\n"
                 "B       loc_FFC4F768\n"
 "loc_FFC4F6A8:\n"
                 "B       loc_FFC4F774\n"
 "loc_FFC4F6AC:\n"
                 "B       loc_FFC4F7CC\n"
 "loc_FFC4F6B0:\n"
                 "B       loc_FFC4F758\n"
 "loc_FFC4F6B4:\n"
                 "B       loc_FFC4F7D4\n"
 "loc_FFC4F6B8:\n"
                 "B       loc_FFC4F7E0\n"
 "loc_FFC4F6BC:\n"
                 "B       loc_FFC4F7E8\n"
 "loc_FFC4F6C0:\n"
                 "B       loc_FFC4F7F0\n"
 "loc_FFC4F6C4:\n"
                 "B       loc_FFC4F7F8\n"
 "loc_FFC4F6C8:\n"
                 "B       loc_FFC4F800\n"
 "loc_FFC4F6CC:\n"
                 "B       loc_FFC4F808\n"
 "loc_FFC4F6D0:\n"
                 "B       loc_FFC4F810\n"
 "loc_FFC4F6D4:\n"
                 "B       loc_FFC4F818\n"
 "loc_FFC4F6D8:\n"
                 "B       loc_FFC4F820\n"
 "loc_FFC4F6DC:\n"
                 "B       loc_FFC4F828\n"
 "loc_FFC4F6E0:\n"
                 "B       loc_FFC4F830\n"
 "loc_FFC4F6E4:\n"
                 "B       loc_FFC4F838\n"
 "loc_FFC4F6E8:\n"
                 "B       loc_FFC4F844\n"
 "loc_FFC4F6EC:\n"
                 "B       loc_FFC4F84C\n"
 "loc_FFC4F6F0:\n"
                 "B       loc_FFC4F858\n"
 "loc_FFC4F6F4:\n"
                 "B       loc_FFC4F860\n"
 "loc_FFC4F6F8:\n"
                 "B       loc_FFC4F868\n"
 "loc_FFC4F6FC:\n"
                 "B       loc_FFC4F870\n"
 "loc_FFC4F700:\n"
                 "B       loc_FFC4F878\n"
 "loc_FFC4F704:\n"
                 "B       loc_FFC4F880\n"
 "loc_FFC4F708:\n"
                 "B       loc_FFC4F888\n"
 "loc_FFC4F70C:\n"
                 "B       loc_FFC4F894\n"
 "loc_FFC4F710:\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F714:\n"
                 "BL      sub_FFC4FF14\n"
		     "BL      shooting_expo_param_override\n"	//------------>
                 "B       loc_FFC4F76C\n"
 "loc_FFC4F71C:\n"
"     BL    shooting_set_flash_override\n"
                 "MOV     R0, #0xC\n"
                 "BL      sub_FFC541E4\n"
                 "TST     R0, #1\n"
                 "LDR     R0, [SP]\n"
                 "MOVNE   R1, #1\n"
                 "LDRNE   R2, [R0,#0xC]\n"
                 "MOVNE   R0, #1\n"
                 "BNE     loc_FFC4F7C4\n"
                 "BL      sub_FFC4EFE8_my\n"			//------------>
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F744:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FFC50154\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F750:\n"
                 "BL      sub_FFC4FBE0\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F758:\n"
                 "BL      sub_FFC4FEF4\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F760:\n"
                 "BL      sub_FFC4FEFC\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F768:\n"
                 "BL      sub_FFC50074\n"
 "loc_FFC4F76C:\n"
                 "BL      sub_FFC4D318\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F774:\n"
                 "LDR     R4, [R0,#0xC]\n"
                 "BL      sub_FFC4FF04\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFD17BE4\n"
                 "TST     R0, #1\n"
                 "MOV     R5, R0\n"
                 "BNE     loc_FFC4F7B4\n"
                 "BL      sub_FFC60E70\n"
                 "STR     R0, [R4,#0x18]\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFD18D84\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFD19150\n"
                 "MOV     R5, R0\n"
                 "LDR     R0, [R4,#0x18]\n"
                 "BL      sub_FFC61074\n"
 "loc_FFC4F7B4:\n"
                 "BL      sub_FFC4FEF4\n"
                 "MOV     R2, R4\n"
                 "MOV     R1, #9\n"
                 "MOV     R0, R5\n"
 "loc_FFC4F7C4:\n"
                 "BL      sub_FFC4D7DC\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F7CC:\n"
                 "BL      sub_FFC500D4\n"
                 "B       loc_FFC4F76C\n"
 "loc_FFC4F7D4:\n"
                 "LDR     R0, [R7,#0x4C]\n"
                 "BL      sub_FFC50660\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F7E0:\n"
                 "BL      sub_FFC50908\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F7E8:\n"
                 "BL      sub_FFC5099C\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F7F0:\n"
                 "BL      sub_FFD17E0C\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F7F8:\n"
                 "BL      sub_FFD18004\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F800:\n"
                 "BL      sub_FFD18088\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F808:\n"
                 "BL      sub_FFD18168\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F810:\n"
                 "BL      sub_FFD18228\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F818:\n"
                 "MOV     R0, #0\n"
                 "B       loc_FFC4F83C\n"
 "loc_FFC4F820:\n"
                 "BL      sub_FFD185E8\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F828:\n"
                 "BL      sub_FFD18678\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F830:\n"
                 "BL      sub_FFD18738\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F838:\n"
                 "MOV     R0, #1\n"
 "loc_FFC4F83C:\n"
                 "BL      sub_FFD18498\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F844:\n"
                 "BL      sub_FFC502FC\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F84C:\n"
                 "BL      sub_FFC50328\n"
                 "BL      sub_FFC4F9E4\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F858:\n"
                 "BL      sub_FFD18370\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F860:\n"
                 "BL      sub_FFD18408\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F868:\n"
                 "BL      sub_FFC4EEC0\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F870:\n"
                 "BL      sub_FFC14638\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F878:\n"
                 "BL      sub_FFC528BC\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F880:\n"
                 "BL      sub_FFC52918\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F888:\n"
                 "BL      sub_FFC52974\n"
                 "BL      sub_FFC52934\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F894:\n"
                 "LDRH    R0, [R7,#0x98]\n"
                 "CMP     R0, #4\n"
                 "BNE     loc_FFC4F8B8\n"
                 "BL      sub_FFC52918\n"
                 "BL      sub_FFC52D60\n"
                 "B       loc_FFC4F8B8\n"
 "loc_FFC4F8AC:\n"
                 "LDR     R1, =0x709\n"
                 "LDR     R0, =0xFFC4EF30\n"	// aSsshoottask_c
                 "BL      sub_FFC0B048\n"	// DebugAssert
 "loc_FFC4F8B8:\n"
                 "LDR     R0, [SP]\n"
                 "LDR     R1, [R0,#4]\n"
                 "LDR     R0, [R6]\n"
                 "BL      sub_FFC58E7C\n"
                 "LDR     R4, [SP]\n"
                 "LDR     R0, [R4,#8]\n"
                 "CMP     R0, #0\n"
                 "LDREQ   R1, =0x132\n"
                 "LDREQ   R0, =0xFFC4EF30\n"	// aSsshoottask_c
                 "BLEQ    sub_FFC0B048\n"	// DebugAssert
                 "MOV     R0, #0\n"
                 "STR     R0, [R4,#8]\n"
                 "B       loc_FFC4F64C\n"
    );
} 


void __attribute__((naked,noinline)) sub_FFC4EFE8_my(){
    asm volatile(
                 "STMFD   SP!, {R3-R7,LR}\n"
                 "LDR     R4, [R0,#0xC]\n"
                 "LDR     R5, =0x13C94\n"
                 "LDR     R0, [R4,#8]\n"
                 "ORR     R0, R0, #1\n"
                 "STR     R0, [R4,#8]\n"
                 "LDRH    R0, [R5,#0x96]\n"
                 "CMP     R0, #3\n"
                 "BEQ     loc_FFC4F0B8\n"
                 "LDR     R0, [R4,#0xC]\n"
                 "CMP     R0, #1\n"
                 "BLS     loc_FFC4F068\n"
                 "LDRH    R0, [R5,#0x94]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FFC4F0B8\n"
                 "LDRH    R0, [R5,#0x90]\n"
                 "CMP     R0, #2\n"
                 "BNE     loc_FFC4F074\n"
                 "BL      sub_FFC503E4\n"
                 "LDRH    R0, [R5,#0x96]\n"
                 "CMP     R0, #3\n"
                 "BEQ     loc_FFC4F0B8\n"
                 "LDR     R0, [R4,#0xC]\n"
                 "CMP     R0, #1\n"
                 "BLS     loc_FFC4F068\n"
                 "LDRH    R0, [R5,#0x94]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FFC4F0B8\n"
                 "LDRH    R0, [R5,#0x90]\n"
                 "CMP     R0, #2\n"
                 "BEQ     loc_FFC4F098\n"
                 "B       loc_FFC4F074\n"
 "loc_FFC4F068:\n"
                 "LDRH    R0, [R5,#0x94]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FFC4F0B8\n"
 "loc_FFC4F074:\n"
                 "LDRH    R0, [R5,#0x90]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FFC4F0B8\n"
                 "LDR     R0, [R4,#0xC]\n"
                 "CMP     R0, #1\n"
                 "BLS     loc_FFC4F0B8\n"
                 "LDR     R0, [R4,#0x10]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FFC4F0B8\n"
 "loc_FFC4F098:\n"
                 "LDR     R3, =0x269\n"
                 "LDR     R0, =0x2AD0\n"
                 "STR     R3, [SP]\n"
                 "LDR     R0, [R0]\n"
                 "LDR     R2, =0xEA60\n"
                 "LDR     R3, =0xFFC4EF30\n"	// aSsshoottask_c
                 "MOV     R1, #0x40000000\n"
                 "BL      sub_FFC54530\n"
 "loc_FFC4F0B8:\n"
                 "BL      sub_FFC4EEC0\n"
                 "MOV     R0, #2\n"
                 "BL      sub_FFC4BB58\n"
                 "BL      sub_FFC4FF04\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFC50284\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFD17804\n"
                 "CMP     R0, #0\n"
                 "MOV     R0, R4\n"
                 "BEQ     loc_FFC4F100\n"
                 "BL      sub_FFD178E4\n"
                 "TST     R0, #1\n"
                 "MOVNE   R2, R4\n"
                 "LDMNEFD SP!, {R3-R7,LR}\n"
                 "MOVNE   R1, #1\n"
                 "BNE     sub_FFC4D7DC\n"
                 "B       loc_FFC4F104\n"
 "loc_FFC4F100:\n"
                 "BL      sub_FFD17878\n"
 "loc_FFC4F104:\n"
                 "MOV     R0, #0\n"
                 "STR     R0, [SP]\n"
                 "LDRH    R0, [R5,#0x96]\n"
                 "MOV     R2, #2\n"
                 "MOV     R1, SP\n"
                 "CMP     R0, #3\n"
                 "LDRNE   R0, [R4,#0xC]\n"
                 "CMPNE   R0, #1\n"
                 "MOVHI   R0, #1\n"
                 "STRHI   R0, [SP]\n"
                 "LDR     R0, =0x127\n"
                 "BL      sub_FFC60BE4\n"
                 "BL      sub_FFD39CAC\n"
                 "BL      sub_FFC60E70\n"
                 "STR     R0, [R4,#0x18]\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFD18D84\n"
                 "BL      sub_FFD197CC\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFD18E4C_my\n"		//-------------------->
                 "MOV     R6, R0\n"
                 "BL      capt_seq_hook_raw_here\n"	// added
                 "BL      sub_FFC52918\n"
                 "BL      sub_FFC52960\n"
                 "BL      sub_FFC529A0\n"
                 "MOV     R2, R4\n"
                 "MOV     R1, #1\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FFC4D7DC\n"
                 "BL      sub_FFD190F4\n"
                 "CMP     R0, #0\n"
                 "LDRNE   R0, [R4,#8]\n"
                 "ORRNE   R0, R0, #0x2000\n"
                 "STRNE   R0, [R4,#8]\n"
                 "LDRH    R0, [R5,#0x96]\n"
                 "CMP     R0, #3\n"
                 "BEQ     locret_FFC4F1B0\n"
                 "LDRH    R0, [R5,#0x94]\n"
                 "CMP     R0, #0\n"
                 "LDREQH  R0, [R5,#0x90]\n"
                 "CMPEQ   R0, #2\n"
                 "MOVEQ   R0, R4\n"
                 "LDMEQFD SP!, {R3-R7,LR}\n"
                 "BEQ     sub_FFC50438\n"
 "locret_FFC4F1B0:\n"
                 "LDMFD   SP!, {R3-R7,PC}\n"
    );
}


void __attribute__((naked,noinline)) sub_FFD18E4C_my(){
 asm volatile(
                 "STMFD   SP!, {R0-R8,LR}\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FFD1992C\n"
                 "MVN     R1, #0\n"
                 "BL      sub_FFC58EB0\n"
                 "LDR     R5, =0x6690\n"
                 "LDR     R0, [R5,#0xC]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FFD18E9C\n"
                 "MOV     R1, #1\n"
                 "MOV     R0, #0\n"
                 "BL      sub_FFC16DE4\n"
                 "STR     R0, [R5,#0xC]\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [SP]\n"
                 "LDR     R3, =0xFFD18828\n"
                 "LDR     R0, =0xFFD190B8\n"	// aShuttersoundtask
                 "MOV     R2, #0x400\n"
                 "MOV     R1, #0x17\n"
                 "BL      sub_FFC16DB0\n"	// KernelCreateTask
 "loc_FFD18E9C:\n"
                 "MOV     R2, #4\n"
                 "ADD     R1, SP, #0x8\n"
                 "MOV     R0, #0x8A\n"
                 "BL      sub_FFC60CE0\n"	// PT_GetPropertyCaseString_0
                 "TST     R0, #1\n"
                 "LDRNE   R1, =0x3C5\n"
                 "LDRNE   R0, =0xFFD18A94\n"	// aSscaptureseq_c
                 "BLNE    sub_FFC0B048\n"	// DebugAssert
                 "LDR     R6, =0x13D58\n"
                 "LDR     R8, =0x13C94\n"
                 "LDRSH   R2, [R6,#0xC]\n"
                 "LDRSH   R1, [R6,#0xE]\n"
                 "LDR     R0, [R8,#0x8C]\n"
                 "BL      sub_FFCDE6FC\n"
                 "BL      sub_FFC39464\n"	// GetCCDTemperature
                 "LDR     R3, =0x6698\n"
                 "STRH    R0, [R4,#0xA4]\n"
                 "SUB     R2, R3, #4\n"
                 "STRD    R2, [SP]\n"
                 "MOV     R1, R0\n"
                 "LDRH    R0, [R8,#0x54]\n"
                 "LDRSH   R2, [R6,#0xC]\n"
                 "SUB     R3, R3, #8\n"
                 "BL      sub_FFD1AF5C\n"
                 "BL      wait_until_remote_button_is_released\n"	//---------->
                 "BL      capt_seq_hook_set_nr\n"			//---------->
                 "B       sub_FFD18EFC\n"		// continue function in firmware
    );
}

