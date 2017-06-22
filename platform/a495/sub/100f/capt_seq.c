#include "lolevel.h"
#include "platform.h"
#include "core.h"
static long *nrflag = (long*)0x5828;	// ??? ROM:FFD10EE0 "ShutterSoundTask"

#include "../../../generic/capt_seq.c"

// ROM:FFC59274 task_CaptSeqTask()

void __attribute__((naked,noinline)) capt_seq_task() {
	asm volatile (
			"STMFD   SP!, {R3-R7,LR}\n"
			"LDR     R7, =0x33324\n"
			"LDR     R6, =0x26C0\n"
"loc_FFC59280:\n"
			"LDR     R0, [R6,#4]\n"
			"MOV     R2, #0\n"
			"MOV     R1, SP\n"
			"BL      sub_FFC28AA0\n"
			"TST     R0, #1\n"
			"BEQ     loc_FFC592AC\n"
			"LDR     R1, =0x5B4\n"
			"LDR     R0, =0xFFC58E80\n"
			"BL      sub_FFC0F680\n"
			"BL      sub_FFC0F438\n"
			"LDMFD   SP!, {R3-R7,PC}\n"
"loc_FFC592AC:\n"
			"LDR     R0, [SP]\n"
			"LDR     R1, [R0]\n"
			"CMP     R1, #0x1D\n"
			"ADDLS   PC, PC, R1,LSL#2\n"
			"B       loc_FFC594BC\n"
			"B       loc_FFC59338\n"
			"B       loc_FFC59340\n"
			"B       loc_FFC59368\n"
			"B       loc_FFC5937C\n"
			"B       loc_FFC59374\n"
			"B       loc_FFC59384\n"
			"B       loc_FFC5938C\n"
			"B       loc_FFC59398\n"
			"B       loc_FFC593F0\n"
			"B       loc_FFC5937C\n"
			"B       loc_FFC593F8\n"
			"B       loc_FFC59404\n"
			"B       loc_FFC5940C\n"
			"B       loc_FFC59414\n"
			"B       loc_FFC5941C\n"
			"B       loc_FFC59424\n"
			"B       loc_FFC5942C\n"
			"B       loc_FFC59434\n"
			"B       loc_FFC59440\n"
			"B       loc_FFC59448\n"
			"B       loc_FFC59450\n"
			"B       loc_FFC59458\n"
			"B       loc_FFC59460\n"
			"B       loc_FFC5946C\n"
			"B       loc_FFC59474\n"
			"B       loc_FFC5947C\n"
			"B       loc_FFC59484\n"
			"B       loc_FFC5948C\n"
			"B       loc_FFC59498\n"
			"B       loc_FFC594C8\n"
"loc_FFC59338:\n"
			"BL      sub_FFC59B54\n"
			"BL      shooting_expo_param_override\n"      // +
			"B       loc_FFC59390\n"
"loc_FFC59340:\n"
"     BL    shooting_set_flash_override\n"
			"MOV     R0, #0xC\n"
			"BL      sub_FFC5D830\n"
			"TST     R0, #1\n"
			"LDR     R0, [SP]\n"
			"MOVNE   R1, #1\n"
			"LDRNE   R2, [R0,#0xC]\n"
			"MOVNE   R0, #1\n"
			"BNE     loc_FFC593E8\n"
			"BL      sub_FFC595E8_my\n"  //--------->
			"B       loc_FFC594C8\n"
"loc_FFC59368:\n"
			"MOV     R0, #1\n"
			"BL      sub_FFC59DDC\n"
			"B       loc_FFC594C8\n"
"loc_FFC59374:\n"
			"BL      sub_FFC597C0\n"
			"B       loc_FFC594C8\n"
"loc_FFC5937C:\n"
			"BL      sub_FFC59B34\n"
			"B       loc_FFC594C8\n"
"loc_FFC59384:\n"
			"BL      sub_FFC59B3C\n"
			"B       loc_FFC594C8\n"
"loc_FFC5938C:\n"
			"BL      sub_FFC59CEC\n"
"loc_FFC59390:\n"
			"BL      sub_FFC5758C\n"
			"B       loc_FFC594C8\n"
"loc_FFC59398:\n"
			"LDR     R4, [R0,#0xC]\n"
			"BL      sub_FFC59B44\n"
			"MOV     R0, R4\n"
			"BL      sub_FFD0FE90\n"
			"TST     R0, #1\n"
			"MOV     R5, R0\n"
			"BNE     loc_FFC593D8\n"
			"BL      sub_FFC6970C\n"
			"STR     R0, [R4,#0x18]\n"
			"MOV     R0, R4\n"
			"BL      sub_FFD10E04\n"
			"MOV     R0, R4\n"
			"BL      sub_FFD111A4\n"
			"MOV     R5, R0\n"
			"LDR     R0, [R4,#0x18]\n"
			"BL      sub_FFC69944\n"
"loc_FFC593D8:\n"
			"BL      sub_FFC59B34\n"
			"MOV     R2, R4\n"
			"MOV     R1, #9\n"
			"MOV     R0, R5\n"
"loc_FFC593E8:\n"
			"BL      sub_FFC57984\n"
			"B       loc_FFC594C8\n"
"loc_FFC593F0:\n"
			"BL      sub_FFC59D54\n"
			"B       loc_FFC59390\n"
"loc_FFC593F8:\n"
			"LDR     R0, [R7,#0x4C]\n"
			"BL      sub_FFC5A0F8\n"
			"B       loc_FFC594C8\n"
"loc_FFC59404:\n"
			"BL      sub_FFC5A3A8\n"
			"B       loc_FFC594C8\n"
"loc_FFC5940C:\n"
			"BL      sub_FFC5A43C\n"
			"B       loc_FFC594C8\n"
"loc_FFC59414:\n"
			"BL      sub_FFD100BC\n"
			"B       loc_FFC594C8\n"
"loc_FFC5941C:\n"
			"BL      sub_FFD102B4\n"
			"B       loc_FFC594C8\n"
"loc_FFC59424:\n"
			"BL      sub_FFD10348\n"
			"B       loc_FFC594C8\n"
"loc_FFC5942C:\n"
			"BL      sub_FFD10408\n"
			"B       loc_FFC594C8\n"
"loc_FFC59434:\n"
			"MOV     R0, #0\n"
			"BL      sub_FFD10600\n"
			"B       loc_FFC594C8\n"
"loc_FFC59440:\n"
			"BL      sub_FFD10750\n"
			"B       loc_FFC594C8\n"
"loc_FFC59448:\n"
			"BL      sub_FFD107E0\n"
			"B       loc_FFC594C8\n"
"loc_FFC59450:\n"
			"BL      sub_FFD108A0\n"
			"B       loc_FFC594C8\n"
"loc_FFC59458:\n"
			"BL      sub_FFC59F38\n"
			"B       loc_FFC594C8\n"
"loc_FFC59460:\n"
			"BL      sub_FFC59F74\n"
			"BL      sub_FFC26C78\n"
			"B       loc_FFC594C8\n"
"loc_FFC5946C:\n"
			"BL      sub_FFD104D4\n"
			"B       loc_FFC594C8\n"
"loc_FFC59474:\n"
			"BL      sub_FFD10518\n"
			"B       loc_FFC594C8\n"
"loc_FFC5947C:\n"
			"BL      sub_FFC5C070\n"
			"B       loc_FFC594C8\n"
"loc_FFC59484:\n"
			"BL      sub_FFC5C0F0\n"
			"B       loc_FFC594C8\n"
"loc_FFC5948C:\n"
			"BL      sub_FFC5C14C\n"
			"BL      sub_FFC5C10C\n"
			"B       loc_FFC594C8\n"
"loc_FFC59498:\n"
			"LDRH    R0, [R7,#0x8C]\n"
			"CMP     R0, #4\n"
			"LDRNEH  R0, [R7]\n"
			"SUBNE   R12, R0, #0x8200\n"
			"SUBNES  R12, R12, #0x2A\n"
			"BNE     loc_FFC594C8\n"
			"BL      sub_FFC5C0F0\n"
			"BL      sub_FFC5C490\n"
			"B       loc_FFC594C8\n"
"loc_FFC594BC:\n"
			"LDR     R1, =0x70B\n"
			"LDR     R0, =0xFFC58E80\n"
			"BL      sub_FFC0F680\n"
"loc_FFC594C8:\n"
			"LDR     R0, [SP]\n"
			"LDR     R1, [R0,#4]\n"
			"LDR     R0, [R6]\n"
			"BL      sub_FFC28810\n"
			"LDR     R4, [SP]\n"
			"LDR     R0, [R4,#8]\n"
			"CMP     R0, #0\n"
			"LDREQ   R1, =0x132\n"
			"LDREQ   R0, =0xFFC58E80\n"
			"BLEQ    sub_FFC0F680\n"
			"MOV     R0, #0\n"
			"STR     R0, [R4,#8]\n"
			"B       loc_FFC59280\n"
	);
} 



void __attribute__((naked,noinline)) sub_FFC595E8_my(){ // 
	asm volatile(
			"STMFD   SP!, {R3-R5,LR}\n"
			"LDR     R4, [R0,#0xC]\n"
			"LDR     R0, [R4,#8]\n"
			"ORR     R0, R0, #1\n"
			"STR     R0, [R4,#8]\n"
			"BL      sub_FFC59B44\n"
			"MOV     R0, R4\n"
			"BL      sub_FFC59EEC\n"
			"MOV     R0, R4\n"
			"BL      sub_FFD0FAFC\n"
			"CMP     R0, #0\n"
			"MOV     R0, R4\n"
			"BEQ     loc_FFC59638\n"
			"BL      sub_FFD0FB88\n"
			"TST     R0, #1\n"
			"MOVNE   R2, R4\n"
			"LDMNEFD SP!, {R3-R5,LR}\n"
			"MOVNE   R1, #1\n"
			"BNE     sub_FFC57984\n"
			"B       loc_FFC5963C\n"
"loc_FFC59638:\n"
			"BL      sub_FFD0FB4C\n"
"loc_FFC5963C:\n"
			"MOV     R0, #0\n"
			"STR     R0, [SP]\n"
			"LDR     R0, =0x33324\n"
			"MOV     R2, #2\n"
			"LDRH    R0, [R0,#0x8A]\n"
			"MOV     R1, SP\n"
			"CMP     R0, #3\n"
			"LDRNE   R0, [R4,#0xC]\n"
			"CMPNE   R0, #1\n"
			"MOVHI   R0, #1\n"
			"STRHI   R0, [SP]\n"
			"LDR     R0, =0x127\n"
			"BL      sub_FFC6944C\n"
			"BL      sub_FFD2F710\n"
			"BL      sub_FFC6970C\n"
			"STR     R0, [R4,#0x18]\n"
			"MOV     R0, R4\n"
			"BL      sub_FFD10E04\n"
			"BL      sub_FFD11820\n"
			"MOV     R0, R4\n"
			"BL      sub_FFD10ECC_my\n"			//---------->
			"MOV     R5, R0\n"
			"BL      capt_seq_hook_raw_here\n"	// +
			"BL      sub_FFC5C0F0\n"
			"BL      sub_FFC5C138\n"
			"BL      sub_FFC5C178\n"
			"MOV     R2, R4\n"
			"MOV     R1, #1\n"
			"MOV     R0, R5\n"
			"BL      sub_FFC57984\n"
			"BL      sub_FFD11158\n"
			"CMP     R0, #0\n"
			"LDRNE   R0, [R4,#8]\n"
			"ORRNE   R0, R0, #0x2000\n"
			"STRNE   R0, [R4,#8]\n"
			"LDMFD   SP!, {R3-R5,PC}\n"
	);
}




void __attribute__((naked,noinline)) sub_FFD10ECC_my(){ // 
	asm volatile(
			"STMFD   SP!, {R0-R8,LR}\n"
			"MOV     R4, R0\n"
			"BL      sub_FFD119B4\n"
			"MOV     R1, #0xFFFFFFFF\n"
			"BL      sub_FFC28844\n"
			"LDR     R5, =0x5828\n"
			"LDR     R0, [R5,#0xC]\n"
			"CMP     R0, #0\n"
			"BNE     loc_FFD10F1C\n"
			"MOV     R1, #1\n"
			"MOV     R0, #0\n"
			"BL      sub_FFC0F4B4\n"
			"STR     R0, [R5,#0xC]\n"
			"MOV     R3, #0\n"
			"STR     R3, [SP]\n"
			"LDR     R3, =0xFFD10990\n"
			"LDR     R0, =0xFFD11128\n"
			"MOV     R2, #0x400\n"
			"MOV     R1, #0x17\n"
			"BL      sub_FFC0F480\n"
"loc_FFD10F1C:\n"
			"MOV     R2, #4\n"
			"ADD     R1, SP, #8\n"
			"MOV     R0, #0x8A\n"
			"BL      sub_FFC6957C\n"
			"TST     R0, #1\n"
			"LDRNE   R1, =0x3BA\n"
			"LDRNE   R0, =0xFFD10BBC\n"
			"BLNE    sub_FFC0F680\n"
			"LDR     R6, =0x333E0\n"
			"LDR     R7, =0x33324\n"
			"LDR     R3, [R6]\n"
			"LDRSH   R2, [R6,#0xC]\n"
			"LDRSH   R1, [R6,#0xE]\n"
			"LDR     R0, [R7,#0x80]\n"
		//	"BL      nullsub_56\n"
			"BL      sub_FFC455A8\n"
			"LDR     R3, =0x5830\n"
			"STRH    R0, [R4,#0xA4]\n"
			"SUB     R2, R3, #4\n"
			"STRD    R2, [SP]\n"
			"MOV     R1, R0\n"
			"LDRH    R0, [R7,#0x54]\n"
			"LDRSH   R2, [R6,#0xC]\n"
			"SUB     R3, R3, #8\n"
			"BL      sub_FFD12020\n"
			"BL      wait_until_remote_button_is_released\n"     // +
			"BL      capt_seq_hook_set_nr\n"                     // +
			"B       sub_FFD10F80\n"                             // continue function in firmware
	);
}
