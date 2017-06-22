#include "lolevel.h"
#include "platform.h"
#include "core.h"
static long *nrflag = (long*)0xA5CC;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) capt_seq_task() {   // ROM:FF86CB80
 asm volatile (
                 "STMFD   SP!, {R3-R9,LR}\n"
                 "LDR     R5, =0x5700\n"
                 "LDR     R4, =0x1CF68\n"
                 "MOV     R9, #1\n"
                 "MOV     R7, #0\n"
 "loc_FF86CB94:\n"
                 "LDR     R0, [R5,#0x14]\n"
                 "MOV     R2, #0\n"
                 "MOV     R1, SP\n"
                 "BL      sub_FF82759C\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FF86CBC0\n"
                 "LDR     R1, =0x588\n"
                 "LDR     R0, =0xFF86C220\n"
                 "BL      sub_FF81B1CC\n"
                 "BL      sub_FF81B184\n"
                 "LDMFD   SP!, {R3-R9,PC}\n"
 "loc_FF86CBC0:\n"
                 "LDR     R0, [SP, #0]\n"
                 "LDR     R1, [R0]\n"
                 "CMP     R1, #0x25\n"
                 "ADDLS   PC, PC, R1,LSL#2\n"
                 "B       loc_FF86CEE8\n"
 "loc_FF86CBD4:\n"
                 "B       loc_FF86CC6C\n"
 "loc_FF86CBD8:\n"
                 "B       loc_FF86CCD8\n"
 "loc_FF86CBDC:\n"
                 "B       loc_FF86CD14\n"
 "loc_FF86CBE0:\n"
                 "B       loc_FF86CD34\n"
 "loc_FF86CBE4:\n"
                 "B       loc_FF86CD2C\n"
 "loc_FF86CBE8:\n"
                 "B       loc_FF86CD4C\n"
 "loc_FF86CBEC:\n"
                 "B       loc_FF86CD54\n"
 "loc_FF86CBF0:\n"
                 "B       loc_FF86CD5C\n"
 "loc_FF86CBF4:\n"
                 "B       loc_FF86CDB4\n"
 "loc_FF86CBF8:\n"
                 "B       loc_FF86CDDC\n"
 "loc_FF86CBFC:\n"
                 "B       loc_FF86CDC0\n"
 "loc_FF86CC00:\n"
                 "B       loc_FF86CDCC\n"
 "loc_FF86CC04:\n"
                 "B       loc_FF86CDD4\n"
 "loc_FF86CC08:\n"
                 "B       loc_FF86CDE4\n"
 "loc_FF86CC0C:\n"
                 "B       loc_FF86CDEC\n"
 "loc_FF86CC10:\n"
                 "B       loc_FF86CDF4\n"
 "loc_FF86CC14:\n"
                 "B       loc_FF86CDFC\n"
 "loc_FF86CC18:\n"
                 "B       loc_FF86CE04\n"
 "loc_FF86CC1C:\n"
                 "B       loc_FF86CE0C\n"
 "loc_FF86CC20:\n"
                 "B       loc_FF86CE14\n"
 "loc_FF86CC24:\n"
                 "B       loc_FF86CE1C\n"
 "loc_FF86CC28:\n"
                 "B       loc_FF86CE24\n"
 "loc_FF86CC2C:\n"
                 "B       loc_FF86CE2C\n"
 "loc_FF86CC30:\n"
                 "B       loc_FF86CE34\n"
 "loc_FF86CC34:\n"
                 "B       loc_FF86CE3C\n"
 "loc_FF86CC38:\n"
                 "B       loc_FF86CE48\n"
 "loc_FF86CC3C:\n"
                 "B       loc_FF86CE50\n"
 "loc_FF86CC40:\n"
                 "B       loc_FF86CE5C\n"
 "loc_FF86CC44:\n"
                 "B       loc_FF86CE64\n"
 "loc_FF86CC48:\n"
                 "B       loc_FF86CE94\n"
 "loc_FF86CC4C:\n"
                 "B       loc_FF86CE9C\n"
 "loc_FF86CC50:\n"
                 "B       loc_FF86CEA4\n"
 "loc_FF86CC54:\n"
                 "B       loc_FF86CEAC\n"
 "loc_FF86CC58:\n"
                 "B       loc_FF86CEB4\n"
 "loc_FF86CC5C:\n"
                 "B       loc_FF86CEBC\n"
 "loc_FF86CC60:\n"
                 "B       loc_FF86CEC8\n"
 "loc_FF86CC64:\n"
                 "B       loc_FF86CEE0\n"
 "loc_FF86CC68:\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CC6C:\n"
                 "BL      sub_FF86D504\n"
                 "BL      shooting_expo_param_override\n"  // +
                 "BL      sub_FF86A444\n"

 //  this code added to avoid some incorrect behavior if overrides are used.
 //  but it can cause some unexpected side effects. In this case, remove this code!

            "MOV     R0, #0\n"
            "STR     R0, [R4,#0x24]\n"  // fixes overrides  behavior at short shutter press
 	
 //  end of my code

                 "LDR     R0, [R4,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF86CEF4\n"
                 "BL      sub_FF86BEEC\n"  
                 "MOV     R6, R0\n"
                 "LDR     R0, [R4,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF86CCB4\n"
                 "MOV     R0, #0xC\n"
                 "BL      sub_FF871600\n"
                 "TST     R0, #1\n"
                 "STRNE   R9, [R5,#4]\n"
                 "LDRNE   R0, [R6,#8]\n"
                 "ORRNE   R0, R0, #0x40000000\n"
                 "STRNE   R0, [R6,#8]\n"
                 "BNE     loc_FF86CEF4\n"
 "loc_FF86CCB4:\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF960564\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF86C2D4\n"
                 "MOV     R0, R6\n"
		//		 "BL      sub_FF960CD4\n"     // Original Routine
                 "BL      sub_FF960CD4_my\n"             // ----------->
                 "BL      capt_seq_hook_raw_here\n"      // +
                 "TST     R0, #1\n"
                 "STRNE   R9, [R5,#4]\n"
                 "B       loc_FF86CEF4\n"

"loc_FF86CCD8:\n"
"     BL    shooting_set_flash_override\n"
                 "LDR     R0, [R4,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF86CD04\n"
                 "MOV     R0, #0xC\n"
                 "BL      sub_FF871600\n"
                 "TST     R0, #1\n"
                 "LDRNE   R0, [SP,#0]\n"
                 "MOVNE   R1, #1\n"
                 "LDRNE   R2, [R0,#0xC]\n"
                 "MOVNE   R0, #1\n"
                 "BNE     loc_FF86CDAC\n"
"loc_FF86CD04:\n"
                 "LDR     R0, [SP,#0]\n"
	     //		 "BL       sub_FF86C34C\n"         //Original 
                 "BL       sub_FF86C34C_my\n"      // ----------> 
"loc_FF86CD0C:\n"
                 "STR     R7, [R4,#0x24]\n"
                 "B       loc_FF86CEF4\n"
"loc_FF86CD14:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF86D778\n"
                 "LDR     R0, [R4,#0xC]\n"
                 "CMP     R0, #0\n"
                 "BLNE    sub_FF86E3F8\n"
                 "B       loc_FF86CEF4\n"

"loc_FF86CD2C:\n"
                 "BL      sub_FF86D1D0\n"
                 "B       loc_FF86CD0C\n"
 
"loc_FF86CD34:\n"
                 "BL      sub_FF86D4E4\n"
                 "LDR     R0, [R5,#0x1C]\n"
                 "CMP     R0, #0\n"
                 "STRNE   R7, [R5,#0x1C]\n"
                 "BLNE    sub_FF86CAC4\n"
                 "B       loc_FF86CD0C\n"
				 
 "loc_FF86CD4C:\n"
                 "BL      sub_FF86D4EC\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CD54:\n"
                 "BL      sub_FF86D668\n"
                 "B       loc_FF86CDB8\n"
 "loc_FF86CD5C:\n"
                 "LDR     R6, [R0,#0xC]\n"
                 "BL      sub_FF86D4F4\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF95F550\n"
                 "TST     R0, #1\n"
                 "MOV     R8, R0\n"
                 "BNE     loc_FF86CD9C\n"
                 "BL      sub_FF87DD5C\n"
                 "STR     R0, [R6,#0x18]\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF960BEC\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF961028\n"
                 "MOV     R8, R0\n"
                 "LDR     R0, [R6,#0x18]\n"
                 "BL      sub_FF87DF70\n"
 "loc_FF86CD9C:\n"
                 "BL      sub_FF86D4E4\n"
                 "MOV     R2, R6\n"
                 "MOV     R1, #9\n"
                 "MOV     R0, R8\n"

 "loc_FF86CDAC:\n"
                 "BL      sub_FF86A9F0\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDB4:\n"
                 "BL      sub_FF86D6F8\n"
 "loc_FF86CDB8:\n"
                 "BL      sub_FF86A444\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDC0:\n"
                 "LDR     R0, [R4,#0x54]\n"
                 "BL      sub_FF86DED8\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDCC:\n"
                 "BL      sub_FF86E1D8\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDD4:\n"
                 "BL      sub_FF86E230\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDDC:\n"
                 "BL      sub_FF86D4E4\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDE4:\n"
                 "BL      sub_FF95F788\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDEC:\n"
                 "BL      sub_FF95F9B4\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDF4:\n"
                 "BL      sub_FF95FA48\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CDFC:\n"
                 "BL      sub_FF95FB70\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE04:\n"
                 "BL      sub_FF95FC24\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE0C:\n"
                 "BL      sub_FF9600B4\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE14:\n"
                 "BL      sub_FF96010C\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE1C:\n"
                 "MOV     R0, #0\n"
                 "B       loc_FF86CE40\n"
 "loc_FF86CE24:\n"
                 "BL      sub_FF9602A8\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE2C:\n"
                 "BL      sub_FF960338\n"
                 "B       loc_FF86CEF4\n" 
 "loc_FF86CE34:\n"
                 "BL      sub_FF9603F8\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE3C:\n"
                 "MOV     R0, #1\n"
 "loc_FF86CE40:\n"
                 "BL      sub_FF960180\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE48:\n"
                 "BL      sub_FF86D9B0\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE50:\n"
                 "BL      sub_FF86DA50\n"
                 "BL      sub_FF86D01C\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE5C:\n"
                 "BL      sub_FF95FEDC\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE64:\n"
                 "MOV     R2, #2\n"
                 "ADD     R1, R4, #0x68\n"
                 "MOV     R0, #0x6F\n"
                 "BL      sub_FF87DBCC\n"
                 "TST     R0, #1\n"
                 "LDRNE   R1, =0x681\n"
                 "LDRNE   R0, =0xFF86C220\n"
                 "BLNE    sub_FF81B1CC\n"
                 "LDRH    R0, [R4,#0x68]\n"
                 "CMP     R0, #1\n"
                 "BLEQ    sub_FF95FED0\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE94:\n"
                 "BL      sub_FF960008\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CE9C:\n"
                 "BL      sub_FF86C1AC\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CEA4:\n"
                 "BL      sub_FF824944\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CEAC:\n"
                 "BL      sub_FF86FC84\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CEB4:\n"
                 "BL      sub_FF86FCEC\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CEBC :\n"
                 "BL      sub_FF86FD48\n"
                 "BL      sub_FF86FD08\n"
                 "B       loc_FF86CEF4\n"
 "loc_FF86CEC8:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF96180C\n"
                 "LDRH    R0, [R4,#0x94]\n"
                 "CMP     R0, #3\n"
                 "BLNE    sub_FF86FF04\n"
                 "B       loc_FF86CEF4\n"

 "loc_FF86CEE0:\n"
                 "BL      sub_FF86CAC4\n"
                 "B       loc_FF86CEF4\n"

 "loc_FF86CEE8:\n"
                 "LDR     R1, =0x6CB\n"
                 "LDR     R0, =0xFF86C220\n"
                 "BL      sub_FF81B1CC\n"
 "loc_FF86CEF4:\n"
                 "LDR     R0, [SP,#0]\n"
                 "LDR     R1, [R0,#4]\n"
                 "LDR     R0, [R5,#0x10]\n"
                 "BL      sub_FF8758B4\n"
                 "LDR     R6, [SP,#0]\n"
                 "LDR     R0, [R6,#8]\n"
                 "CMP     R0, #0\n"
                 "LDREQ   R1, =0x12B\n"
                 "LDREQ   R0, =0xFF86C220\n"
                 "BLEQ    sub_FF81B1CC\n"
                 "STR     R7, [R6,#8]\n"
                 "B       loc_FF86CB94\n"
 );
} 

void __attribute__((naked,noinline)) sub_FF86C34C_my(){ // 
 asm volatile(
                 "STMFD   SP!, {R3-R9,LR}\n"
                 "LDR     R4, [R0,#0xC]\n"
                 "LDR     R5, =0x1CF68\n"
                 "LDR     R0, [R4,#8]\n"
                 "MOV     R8, #0\n"
                 "ORR     R0, R0, #1\n"
                 "STR     R0, [R4,#8]\n"
                 "LDR     R0, [R5]\n"
                 "SUB     R9, R8, #0x20000\n"
                 "LDR     R6, =0x5700\n"
                 "CMP     R9, R0, LSL#17\n"
                 "TSTNE   R0, #0x800\n"
                 "BEQ   loc_FF86C398\n"
                 "LDR   R0, [R5, #0xC]\n"
                 "CMP   R0, #0\n"
                 "MOVEQ   R0, #1\n"
                 "STREQ   R0, [R6, #0x1C]\n"
                 "MOVEQ   R0, #0\n"
                 "BLEQ   sub_FF933024\n"
 "loc_FF86C398:\n"
                 "LDRH    R0, [R5]\n"
                 "LDR     R7, =0x820A\n"
                 "CMP     R0, R7\n"
                 "BEQ     loc_FF86C41C\n"
                 "LDRH    R0, [R5,#0x9A]\n"
                 "CMP     R0, #3\n"
                 "BEQ     loc_FF86C47C\n"
                 "LDR     R0, [R4,#0xC]\n"
                 "CMP     R0, #1\n"
                 "BLS     loc_FF86C428\n"
                 "LDRH    R0, [R5,#0x98]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF86C47C\n"
                 "LDRH    R0, [R5,#0x94]\n"
                 "CMP     R0, #2\n"
                 "BNE     loc_FF86C434\n"
                 "BL      sub_FF86DB00\n"
                 "LDRH    R0, [R5]\n"
                 "CMP     R0, R7\n"
                 "BEQ     loc_FF86C41C\n"
                 "LDRH    R0, [R5,#0x9A]\n"
                 "CMP     R0, #3\n"
                 "BEQ     loc_FF86C47C\n"
                 "LDR     R0, [R4,#0xC]\n"
                 "CMP     R0, #1\n"
                 "BLS     loc_FF86C428\n"
                 "LDRH    R0, [R5,#0x98]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF86C47C\n"
                 "LDRH    R0, [R5,#0x94]\n"
                 "CMP     R0, #2\n"
                 "BEQ     loc_FF86C460\n"
                 "B       loc_FF86C434\n"
 "loc_FF86C41C:\n"
                 "LDRH    R0, [R5,#0x9A]\n"
                 "CMP     R0, #3\n"
                 "BEQ     loc_FF86C47C\n"
 "loc_FF86C428:\n"
                 "LDRH    R0, [R5,#0x98]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF86C47C\n"
 "loc_FF86C434:\n"
                 "LDRH    R0, [R5,#0x94]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF86C47C\n"
                 "LDRH    R0, [R5]\n"
                 "CMP     R0, R7\n"
                 "LDRNE   R0, [R4,#0xC]\n"
                 "CMPNE   R0, #1\n"
                 "BLS     loc_FF86C47C\n"
                 "LDR     R0, [R4,#0x10]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF86C47C\n"
 "loc_FF86C460:\n"
                 "LDR     R3, =0x262\n"
                 "LDR     R2, =0xEA60\n"
                 "STR     R3, [SP,#0]\n"
                 "LDR     R0, [R8,#0x10]\n"
                 "LDR     R3, =0xFF86C220\n"
                 "MOV     R1, #0x40000000\n"
                 "BL      sub_FF87199C\n"
 "loc_FF86C47C:\n"
                 "BL      sub_FF86C1AC\n"
                 "LDR     R0, [R5,#0x24]\n"
                 "CMP     R0, #0\n"
                 "MOVEQ   R0, #2\n"
                 "BLEQ    sub_FF864F9C\n"
                 "BL      sub_FF86D4F4\n"
                 "LDR     R0, [R5,#0x24]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF86C54C\n"
                 "MOV     R0, #0\n"
                 "BL      sub_FF96180C\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF960564\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF86D918\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF95F0A0\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF86C4EC\n"
                 "BL      sub_FF96184C\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF95F240\n"
                 "TST     R0, #1\n"
                 "MOVNE   R2, R4\n"
                 "LDMNEFD SP!, {R3-R9,LR}\n"
                 "MOVNE   R1, #1\n"
                 "BNE     sub_FF86A9F0\n"
                 "B       loc_FF86C528\n"
 "loc_FF86C4EC:\n"
                 "LDR     R0, [R5,#0xC]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF86C500\n"
                 "BL      sub_FF86E37C\n"
                 "BL      sub_FF866768\n"
 "loc_FF86C500:\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF95F198\n"
                 "LDRH    R0, [R5]\n"
                 "CMP     R9, R0,LSL#17\n"
                 "TSTNE   R0, #0x800\n"
                 "BEQ     loc_FF86C524\n"
                 "LDR     R0, [R5,#0xC]\n"
                 "CMP     R0, #0\n"
                 "BLEQ    sub_FF962960\n"
 "loc_FF86C524:\n" 
                 "BL      sub_FF96184C\n"
 "loc_FF86C528:\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF86C2D4\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF960BEC\n"
                 "BL      sub_FF96169C\n"
                 "MOV     R0, R4\n"
      //         "BL      sub_FF960CD4\n"             // Original
                 "BL      sub_FF960CD4_my\n"          //----------->
                 "MOV     R8, R0\n"
                 "BL      capt_seq_hook_raw_here\n"      // + added
                 "B       loc_FF86C558\n"
 "loc_FF86C54C:\n"
                 "LDR     R0, [R6,#4]\n"
                 "CMP     R0, #0\n"
                 "MOVNE   R8, #0x1D\n"
 "loc_FF86C558:\n"
                 "BL      sub_FF86FCEC\n"
                 "BL      sub_FF86FD34\n"
                 "BL      sub_FF86FD74\n"
                 "MOV     R2, R4\n"
                 "MOV     R1, #1\n"
                 "MOV     R0, R8\n"
                 "BL      sub_FF86A9F0\n"
                 "BL      sub_FF960FB8\n"
                 "CMP     R0, #0\n"
                 "LDRNE   R0, [R4,#8]\n"
                 "ORRNE   R0, R0, #0x2000\n"
                 "STRNE   R0, [R4,#8]\n"
                 "LDR     R0, [R4,#0x1C]\n"
                 "CMP     R0, #0\n"
                 "BLNE    sub_FF866780\n"
                 "LDRH    R0, [R5,#0x9A]\n"
                 "CMP     R0, #3\n"
                 "BEQ     loc_FF86C5BC\n"
                 "LDRH    R0, [R5,#0x98]\n"
                 "CMP     R0, #0\n"
                 "LDREQH  R0, [R5,#0x94]\n"
                 "CMPEQ   R0, #2\n"
                 "MOVEQ   R0, R4\n"
                 "LDMEQFD SP!, {R3-R9,LR}\n"
                 "BEQ     sub_FF86DB54\n"
 "loc_FF86C5BC:\n"
                 "LDMFD   SP!, {R3-R9,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FF960CD4_my(){ // 
 asm volatile(
                 "STMFD   SP!, {R1-R9,LR}\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FF96197C\n"
                 "MVN     R1, #0\n"
                 "BL      sub_FF8758E8\n"				 
				 "LDR     R6, =0xA5CC\n"
				 "LDR     R0, [R6,#8]\n"
				 "CMP     R0, #0\n"
				 "BNE     loc_FF960D24\n"
				 "MOV     R1, #1\n"
				 "MOV     R0, #0\n"
				 "BL      sub_FF827DE4\n"
				 "STR     R0, [R6,#8]\n"
				 "MOV     R3, #0\n"
				 "STR     R3, [SP, #0]\n"
				 "LDR     R3, =0xFF96078C\n"
				 "LDR     R0, =0xFF960F84\n"
				 "MOV     R2, #0x400\n"
				 "MOV     R1, #0x17\n"
				 "BL      sub_FF827DB0\n"
"loc_FF960D24:\n"
                 "MOV     R2, #4\n"
                 "ADD     R1, SP, #4\n"
                 "MOV     R0, #0x8A\n"
                 "BL      sub_FF87DBCC\n"
                 "TST     R0, #1\n"
                 "LDRNE   R1, =0x3C5\n"
                 "LDRNE   R0, =0xFF960A24\n"
                 "BLNE    sub_FF81B1CC\n"
                 "LDR     R8, =0x1D038\n"
                 "LDR     R7, =0x1CF68\n"
                 "LDRSH   R1, [R7,#0xE]\n"
                 "LDR     R0, [R6,#0x90]\n"
                 "BL      sub_FF91C79C\n"
                 "BL      sub_FF850A90\n"
                 "LDR     R3, =0xA5D0\n"
                 "STRH    R0, [R4,#0x9C]\n"
                 "STR     R3, [SP,#0]\n"
                 "MOV     R1, R0\n"
                 "LDRH    R0, [R7,#0x64]\n"
                 "LDRSH   R2, [R8,#0xC]\n"
                 "SUB     R3, R3, #4\n"
                 "BL      sub_FF961FA0\n"
                 "BL      wait_until_remote_button_is_released\n"
                 "BL      capt_seq_hook_set_nr\n"                     // +
                 "B       sub_FF960D7C\n"                             // continue function in firmware
 );
}

