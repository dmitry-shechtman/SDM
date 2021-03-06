#include "lolevel.h"
#include "platform.h"
#include "core.h"
static long *nrflag = (long*)0x9F90;
#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FFD0CAE8_my(){ 
 asm volatile(
                "STMFD   SP!, {R0-R10,LR}\n"
                "MOV     R6, #0\n"
                "MOV     R4, R0\n"
                "BL      sub_FFD0D5E8\n"
                "MVN     R1, #0\n"
                "BL      sub_FFC173EC\n"
                "MOV     R2, #4\n"
                "ADD     R1, SP, #0x30-0x28\n"
                "MOV     R0, #0x8A\n"
                "BL      sub_FFC56F08\n"
                "TST     R0, #1\n"
                "MOVNE   R1, #0x218\n"
                "LDRNE   R0, =0xFFD0CCFC\n"
                "BLNE    sub_FFC0BDB8\n"
                "LDR     R8, =0x1973C\n"
                "LDR     R5, =0x19690\n"
                "LDRSH   R1, [R8,#0xE]\n"
                "LDR     R0, [R5,#0x74]\n"
                "BL      sub_FFCCB1F0\n"
                "BL      sub_FFC32B68\n"
                "LDR     R2, =0x888C\n"
                "ADD     R3, R4, #0x8C\n"
                "STRH    R0, [R4,#0x88]\n"
                "STR     R2, [SP]\n"  //Was "STRD    R2, [SP,#0x30-0x30]\n"
                "STR     R3, [SP,#4]\n" //
                "MOV     R1, R0\n"
                "LDRH    R0, [R5,#0x4C]\n"
                "LDRSH   R2, [R8,#0xC]\n"
                "LDR     R3, =0x8888\n"
                "BL      sub_FFD0DAD4\n"
                "BL      wait_until_remote_button_is_released\n"
                "BL      capt_seq_hook_set_nr\n"
				"BL      sub_FFD0CB5C\n"
 );
}


void __attribute__((naked,noinline)) task_CaptSeqTask_my() //#fs
{
	asm volatile (
                "STMFD   SP!, {R3-R7,LR}\n"
                "LDR     R6, =0x52D0\n"
"loc_FFC488AC:\n"
                "LDR     R0, [R6,#8]\n"
                "MOV     R2, #0\n"
                "MOV     R1, SP\n"
                "BL      sub_FFC1763C\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFC488D8\n"
                "LDR     R1, =0x48E\n"
                "LDR     R0, =0xFFC485CC\n"
                "BL      sub_FFC0BDB8\n"
                "BL      sub_FFC0BB70\n"
                "LDMFD   SP!, {R3-R7,PC}\n"
"loc_FFC488D8:\n"
                //"LDR     R0, [SP,#0x18-0x18]\n"
				"LDR     R0, [SP]\n" //+
                "LDR     R1, [R0]\n"
				
                "LDR     R2, =0x1850\n"         // DEBUG: Save jumptable-target ...
                "STR     R1, [R2]\n"            // ...to some unused space. Read and displayed in GUI in core/gui.c
				
                "CMP     R1, #0x19\n"
                "ADDLS   PC, PC, R1,LSL#2\n"
                "B       loc_FFC48AEC\n"
"loc_FFC488EC:\n"
                "B       loc_FFC48954\n"
"loc_FFC488F0:\n"
                "B       loc_FFC4895C\n"
"loc_FFC488F4:\n"
                "B       loc_FFC489DC\n"
"loc_FFC488F8:\n"
                "B       loc_FFC489F0\n"
"loc_FFC488FC:\n"
                "B       loc_FFC489E8\n"
"loc_FFC48900:\n"
                "B       loc_FFC489F8\n"
"loc_FFC48904:\n"
                "B       loc_FFC48A00\n"
"loc_FFC48908:\n"
                "B       loc_FFC48A0C\n"
"loc_FFC4890C:\n"
                "B       loc_FFC48A64\n"
"loc_FFC48910:\n"
                "B       loc_FFC489F0\n"
"loc_FFC48914:\n"
                "B       loc_FFC48A6C\n"
"loc_FFC48918:\n"
                "B       loc_FFC48A74\n"
"loc_FFC4891C:\n"
                "B       loc_FFC48A7C\n"
"loc_FFC48920:\n"
                "B       loc_FFC48A84\n"
"loc_FFC48924:\n"
                "B       loc_FFC48A8C\n"
"loc_FFC48928:\n"
                "B       loc_FFC48A98\n"
"loc_FFC4892C:\n"
                "B       loc_FFC48AA0\n"
"loc_FFC48930:\n"
                "B       loc_FFC48AA8\n"
"loc_FFC48934:\n"
                "B       loc_FFC48AB0\n"
"loc_FFC48938:\n"
                "B       loc_FFC48ABC\n"
"loc_FFC4893C:\n"
                "B       loc_FFC48AC4\n"
"loc_FFC48940:\n"
                "B       loc_FFC48ACC\n"
"loc_FFC48944:\n"
                "B       loc_FFC48AD4\n"
"loc_FFC48948:\n"
                "B       loc_FFC48ADC\n"
"loc_FFC4894C:\n"
                "B       loc_FFC48AE4\n"
"loc_FFC48950:\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48954:\n" //1
                "BL      sub_FFD0B650\n"
		    "BL      shooting_expo_param_override\n"  // +
                "B       loc_FFC48A04\n"
"loc_FFC4895C:\n" //2
"     BL    shooting_set_flash_override\n"
                "LDR     R4, [R0,#0xC]\n"
                "LDR     R0, [R4,#8]\n"
                "ORR     R0, R0, #1\n"
                "STR     R0, [R4,#8]\n"
                "BL      sub_FFD0B640\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0BA28\n"
                "TST     R0, #1\n"
                "MOVNE   R2, R4\n"
                "MOVNE   R1, #1\n"
                "BNE     loc_FFC48A5C\n"
                "BL      sub_FFD2A16C\n"
                "BL      sub_FFC57098\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0CA20\n"
                "BL      sub_FFD0D484\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0CAE8_my\n"  //-------------->
				"BL      capt_seq_hook_raw_here\n"  //-------------->
                "MOV     R5, R0\n"
                "BL      sub_FFD0E464\n"
                "BL      sub_FFD0E4A0\n"
                "MOV     R2, R4\n"
                "MOV     R1, #1\n"
                "MOV     R0, R5\n"
                "BL      sub_FFC47080\n"
                "BL      sub_FFD0CE98\n"
                "CMP     R0, #0\n"
                "LDRNE   R0, [R4,#8]\n"
                "ORRNE   R0, R0, #0x2000\n"
                "STRNE   R0, [R4,#8]\n"
                "B       loc_FFC48AF8\n"
"loc_FFC489DC:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD0B7E4\n"
                "B       loc_FFC48AF8\n"
"loc_FFC489E8:\n"
                "BL      sub_FFD0B2B0\n"
                "B       loc_FFC48AF8\n"
"loc_FFC489F0:\n"
                "BL      sub_FFD0B630\n"
                "B       loc_FFC48AF8\n"
"loc_FFC489F8:\n"
                "BL      sub_FFD0B638\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A00:\n"
                "BL      sub_FFD0B704\n"
"loc_FFC48A04:\n"
                "BL      sub_FFC46D00\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A0C:\n"
                "LDR     R4, [R0,#0xC]\n"
                "BL      sub_FFD0B640\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0BDA8\n"
                "TST     R0, #1\n"
                "MOV     R5, R0\n"
                "BNE     loc_FFC48A4C\n"
                "BL      sub_FFC57098\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0CA20\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0CEF8\n"
                "MOV     R5, R0\n"
                "LDR     R0, [R4,#0x14]\n"
                "BL      sub_FFC572A4\n"
"loc_FFC48A4C:\n"
                "BL      sub_FFD0B630\n"
                "MOV     R2, R4\n"
                "MOV     R1, #9\n"
                "MOV     R0, R5\n"
"loc_FFC48A5C:\n"
                "BL      sub_FFC47080\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A64:\n"
                "BL      sub_FFD0B764\n"
                "B       loc_FFC48A04\n"
"loc_FFC48A6C:\n"
                "BL      sub_FFD0C024\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A74:\n"
                "BL      sub_FFD0C20C\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A7C:\n"
                "BL      sub_FFD0C29C\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A84:\n"
                "BL      sub_FFD0C350\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A8C:\n"
                "MOV     R0, #0\n"
                "BL      sub_FFD0C4F4\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48A98:\n"
                "BL      sub_FFD0C644\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48AA0:\n"
                "BL      sub_FFD0C6D8\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48AA8:\n"
                "BL      sub_FFD0C7A0\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48AB0:\n"
                "BL      sub_FFD0B900\n"
                "BL      sub_FFC149A0\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48ABC:\n"
                "BL      sub_FFD0C40C\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48AC4:\n"
                "BL      sub_FFD0C450\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48ACC:\n"
                "BL      sub_FFD0E448\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48AD4:\n"
                "BL      sub_FFD0E464\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48ADC:\n"
                "BL      sub_FFD0E474\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48AE4:\n"
                "BL      sub_FFD0E4A0\n"
                "B       loc_FFC48AF8\n"
"loc_FFC48AEC:\n"
                "LDR     R1, =0x58E\n"
                "LDR     R0, =0xFFC485CC\n"
                "BL      sub_FFC0BDB8\n"
"loc_FFC48AF8:\n"
                //"LDR     R0, [SP,#0x18-0x18]\n"
				"LDR     R0, [SP]\n" //+
                "LDR     R1, [R0,#4]\n"
                "LDR     R0, [R6,#4]\n"
                "BL      sub_FFC173B8\n"
                //"LDR     R4, [SP,#0x18-0x18]\n"
				"LDR     R4, [SP]\n" //+
                "LDR     R0, [R4,#8]\n"
                "CMP     R0, #0\n"
                "LDREQ   R1, =0x10D\n"
                "LDREQ   R0, =0xFFC485CC\n"
                "BLEQ    sub_FFC0BDB8\n"
                "MOV     R0, #0\n"
                "STR     R0, [R4,#8]\n"
                "B       loc_FFC488AC\n"
    );
} //#fe
