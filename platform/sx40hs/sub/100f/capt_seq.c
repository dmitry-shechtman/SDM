#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"

static long *nrflag = (long*)(0xC3F8);         // 0xC3F8 SX40 (  @FF29E39C ) + 0 (@FF29E3D8)
#define NR_AUTO (0)                            // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 150             // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) capt_seq_task(){
 
 asm volatile (

	        "STMFD   SP!, {R3-R7,LR}\n"
	        "LDR     R4, =0x3F64C\n"
	        "LDR     R7, =0x30DC\n"
	        "MOV     R6, #0\n"
	"loc_FF07C47C:\n"
	        "LDR     R0, [R7,#4]\n"
	        "MOV     R2, #0\n"
	        "MOV     R1, SP\n"
	        "BL      sub_FF02B0F4\n"
	        "TST     R0, #1\n"
	        "BEQ     loc_FF07C4A8\n"
	        "LDR     R1, =0x491\n"
	        "LDR     R0, =0xFF07BDB8\n"
	        "BL      sub_FF00EDC8\n"
	        "BL      sub_FF00ED80\n"
	        "LDMFD   SP!, {R3-R7,PC}\n"
	"loc_FF07C4A8:\n"
	        "LDR     R0, [SP]\n"
	        "LDR     R1, [R0]\n"
	        "CMP     R1, #0x28\n"
	        "ADDCC   PC, PC, R1,LSL#2\n"
	        "B       loc_FF07C740\n"
	"loc_FF07C4BC:\n"
	        "B       loc_FF07C55C\n"
	"loc_FF07C4C0:\n"
	        "B       loc_FF07C574\n"
	"loc_FF07C4C4:\n"
	        "B       loc_FF07C580\n"
	"loc_FF07C4C8:\n"
	        "B       loc_FF07C5A0\n"
	"loc_FF07C4CC:\n"
	        "B       loc_FF07C598\n"
	"loc_FF07C4D0:\n"
	        "B       loc_FF07C5AC\n"
	"loc_FF07C4D4:\n"
	        "B       loc_FF07C5B4\n"
	"loc_FF07C4D8:\n"
	        "B       loc_FF07C5BC\n"
	"loc_FF07C4DC:\n"
	        "B       loc_FF07C5D8\n"
	"loc_FF07C4E0:\n"
	        "B       loc_FF07C618\n"
	"loc_FF07C4E4:\n"
	        "B       loc_FF07C5E4\n"
	"loc_FF07C4E8:\n"
	        "B       loc_FF07C5F0\n"
	"loc_FF07C4EC:\n"
	        "B       loc_FF07C5F8\n"
	"loc_FF07C4F0:\n"
	        "B       loc_FF07C600\n"
	"loc_FF07C4F4:\n"
	        "B       loc_FF07C608\n"
	"loc_FF07C4F8:\n"
	        "B       loc_FF07C610\n"
	"loc_FF07C4FC:\n"
	        "B       loc_FF07C620\n"
	"loc_FF07C500:\n"
	        "B       loc_FF07C628\n"
	"loc_FF07C504:\n"
	        "B       loc_FF07C630\n"
	"loc_FF07C508:\n"
	        "B       loc_FF07C638\n"
	"loc_FF07C50C:\n"
	        "B       loc_FF07C640\n"
	"loc_FF07C510:\n"
	        "B       loc_FF07C648\n"
	"loc_FF07C514:\n"
	        "B       loc_FF07C650\n"
	"loc_FF07C518:\n"
	        "B       loc_FF07C658\n"
	"loc_FF07C51C:\n"
	        "B       loc_FF07C660\n"
	"loc_FF07C520:\n"
	        "B       loc_FF07C668\n"
	"loc_FF07C524:\n"
	        "B       loc_FF07C674\n"
	"loc_FF07C528:\n"
	        "B       loc_FF07C67C\n"
	"loc_FF07C52C:\n"
	        "B       loc_FF07C688\n"
	"loc_FF07C530:\n"
	        "B       loc_FF07C690\n"
	"loc_FF07C534:\n"
	        "B       loc_FF07C6C0\n"
	"loc_FF07C538:\n"
	        "B       loc_FF07C6C8\n"
	"loc_FF07C53C:\n"
	        "B       loc_FF07C6D0\n"
	"loc_FF07C540:\n"
	        "B       loc_FF07C6D8\n"
	"loc_FF07C544:\n"
	        "B       loc_FF07C6E0\n"
	"loc_FF07C548:\n"
	        "B       loc_FF07C6E8\n"
	"loc_FF07C54C:\n"
	        "B       loc_FF07C6F4\n"
	"loc_FF07C550:\n"
	        "B       loc_FF07C6FC\n"
	"loc_FF07C554:\n"
	        "B       loc_FF07C708\n"
	"loc_FF07C558:\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C55C:\n"
//			"BL      shooting_expo_iso_override\n" // +->
	        "BL      sub_FF07CD70\n"
			"BL      shooting_expo_param_override\n"    //+->
	        "BL      sub_FF0795B8\n"
	        
	        
	        //"LDR     R0, [R4,#0x28]\n"
	        //"CMP     R0, #0\n"
	        //"BLNE    sub_FF1D57C4\n"

			"MOV     R0, #0\n"	// +
	        "STR     R0, [R4,#0x28]\n"  //+ fixes overrides  behavior at short shutter press

			"B       loc_FF07C74C\n"

	"loc_FF07C574:\n"
"     BL    shooting_set_flash_override\n"
	        "LDR     R0, [R0,#0x10]\n"
	        //"BL      sub_FF07C894\n"
			"BL      sub_FF07C894_my\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C580:\n"
	        "MOV     R0, #1\n"
	        "BL      sub_FF07D0CC\n"
	        "LDR     R0, [R4,#0xC]\n"
	        "CMP     R0, #0\n"
	        "BLNE    sub_FF07DF90\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C598:\n"
	        "BL      sub_FF07C9DC\n"
	        "B       loc_FF07C5A4\n"
	"loc_FF07C5A0:\n"
	        "BL      sub_FF07CD50\n"
	"loc_FF07C5A4:\n"
	        "STR     R6, [R4,#0x28]\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C5AC:\n"
	        "BL      sub_FF07CD58\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C5B4:\n"
	        "BL      sub_FF07CF74\n"
	        "B       loc_FF07C5DC\n"
	"loc_FF07C5BC:\n"
	        "LDR     R5, [R0,#0x10]\n"
	        "MOV     R0, R5\n"
	        "BL      sub_FF1D5854\n"
	        "MOV     R2, R5\n"
	        "MOV     R1, #9\n"
	        "BL      sub_FF07A07C\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C5D8:\n"
	        "BL      sub_FF07D030\n"
	"loc_FF07C5DC:\n"
	        "BL      sub_FF0795B8\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C5E4:\n"
	        "LDR     R0, [R4,#0x58]\n"
	        "BL      sub_FF07D9EC\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C5F0:\n"
	        "BL      sub_FF07DCD8\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C5F8:\n"
	        "BL      sub_FF07DD3C\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C600:\n"
	        "BL      sub_FF07E080\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C608:\n"
	        "BL      sub_FF07E4D0\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C610:\n"
	        "BL      sub_FF07E580\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C618:\n"
	        "BL      sub_FF07CD50\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C620:\n"
	        "BL      sub_FF1D33A0\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C628:\n"
	        "BL      sub_FF1D368C\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C630:\n"
	        "BL      sub_FF1D3740\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C638:\n"
	        "BL      sub_FF1D3828\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C640:\n"
	        "BL      sub_FF1D38FC\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C648:\n"
	        "MOV     R0, #0\n"
	        "B       loc_FF07C66C\n"
	"loc_FF07C650:\n"
	        "BL      sub_FF1D3F18\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C658:\n"
	        "BL      sub_FF1D3FAC\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C660:\n"
	        "BL      sub_FF1D4068\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C668:\n"
	        "MOV     R0, #1\n"
	"loc_FF07C66C:\n"
	        "BL      sub_FF1D3DA8\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C674:\n"
	        "BL      sub_FF07D33C\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C67C:\n"
	        "BL      sub_FF07D3D0\n"
	        "BL      sub_FF1D645C\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C688:\n"
	        "BL      sub_FF1D3BE8\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C690:\n"
	        "MOV     R2, #2\n"
	        "ADD     R1, R4, #0x6C\n"
	        "MOV     R0, #0x6F\n"
	        "BL      sub_FF0910A4\n"
	        "TST     R0, #1\n"
	        "LDRNE   R1, =0x592\n"
	        "LDRNE   R0, =0xFF07BDB8\n"
	        "BLNE    sub_FF00EDC8\n"
	        "LDRH    R0, [R4,#0x6C]\n"
	        "CMP     R0, #1\n"
	        "BLEQ    sub_FF1D3BDC\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6C0:\n"
	        "BL      sub_FF1D3D08\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6C8:\n"
	        "BL      sub_FF1D6528\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6D0:\n"
	        "BL      sub_FF028484\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6D8:\n"
	        "BL      sub_FF080D00\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6E0:\n"
	        "BL      sub_FF080D88\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6E8:\n"
	        "LDR     R0, [R0,#0xC]\n"
	        "BL      sub_FF1D4190\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6F4:\n"
	        "BL      sub_FF1D4200\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C6FC:\n"
	        "BL      sub_FF080DF0\n"
	        "BL      sub_FF080DA8\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C708:\n"
	        "MOV     R0, #1\n"
	        "BL      sub_FF1D5F64\n"
	        "MOV     R0, #1\n"
	        "BL      sub_FF1D6098\n"
	        "LDRH    R0, [R4,#0xA8]\n"
	        "CMP     R0, #4\n"
	        "LDRNEH  R0, [R4]\n"
	        "SUBNE   R1, R0, #0x4200\n"
	        "SUBNES  R1, R1, #0x2B\n"
	        "BNE     loc_FF07C74C\n"
	        "BL      sub_FF080D88\n"
	        "BL      sub_FF081504\n"
	        "BL      sub_FF081218\n"
	        "B       loc_FF07C74C\n"
	"loc_FF07C740:\n"
	        "LDR     R1, =0x5F2\n"
	        "LDR     R0, =0xFF07BDB8\n"
	        "BL      sub_FF00EDC8\n"
	"loc_FF07C74C:\n"
	        "LDR     R0, [SP]\n"
	        "LDR     R1, [R0,#4]\n"
	        "LDR     R0, [R7]\n"
	        "BL      sub_FF088B74\n"
	        "LDR     R5, [SP]\n"
	        "LDR     R0, [R5,#8]\n"
	        "CMP     R0, #0\n"
	        "LDREQ   R1, =0x117\n"
	        "LDREQ   R0, =0xFF07BDB8\n"
	        "BLEQ    sub_FF00EDC8\n"
	        "STR     R6, [R5,#8]\n"
	        "B       loc_FF07C47C\n"

	);
}		

void __attribute__((naked,noinline))  sub_FF07C894_my(){

	asm volatile(
	        "STMFD   SP!, {R4-R6,LR}\n"
	        "LDR     R4, =0x3F64C\n"
	        "MOV     R5, R0\n"
	        "LDR     R0, [R4,#0x28]\n"
	        "CMP     R0, #0\n"
	        "BNE     loc_FF07C8F0\n"
	        "LDRH    R0, [R4]\n"
	        "SUB     R1, R0, #0x8200\n"
	        "SUBS    R1, R1, #0x2F\n"
	        "SUBNE   R1, R0, #0x4200\n"
	        "SUBNES  R1, R1, #0x2E\n"
	        "BLEQ    sub_FF07F06C\n"
	        "BL      sub_FF07ECB0\n"
	        "MOV     R1, R5\n"
	        "BL      sub_FF07ED08\n"
	        "LDR     R0, =0x10F\n"
	        "MOV     R2, #4\n"
	        "ADD     R1, R5, #0x68\n"
	        "BL      sub_FF090F1C\n"
	        "MOV     R2, #4\n"
	        "ADD     R1, R5, #0x6C\n"
	        "MOV     R0, #0x2C\n"
	        "BL      sub_FF090F1C\n"
	"loc_FF07C8F0:\n"
	        "MOV     R0, R5\n"
	        //"BL      sub_FF1D557C\n"
			"BL      sub_FF1D557C_my\n" // ----------->

			"BL     capt_seq_hook_raw_here\n"   // +++->

	        "MOV     R6, R0\n"
	        "MOV     R2, R5\n"
	        "MOV     R1, #1\n"
	        "BL      sub_FF07A07C\n"
	        "TST     R6, #1\n"
	        "MOVEQ   R0, R5\n"
	        "BLEQ    sub_FF1D4788\n"
	        "LDR     R0, [R4,#0xCC]\n"
	        "CMP     R0, #2\n"
	        "LDMNEFD SP!, {R4-R6,PC}\n"
	        "MOV     R0, R5\n"
	        "LDMFD   SP!, {R4-R6,LR}\n"
	        "B       sub_FF07A460\n"
	);
}

void __attribute__((naked,noinline))  sub_FF1D557C_my(){//SX40
	asm volatile(
    "STMFD   SP!, {R3-R7,LR}\n"
    "LDR     R5, =0x3F64C\n"
    "MOV     R4, R0\n"
    "LDR     R0, [R5,#0x28]\n"
    "LDR     R6, =0x420D\n"
    "CMP     R0, #0\n"
    "MOV     R7, #0\n"
    "BNE     loc_FF1D560C\n"
    "LDR     R0, [R5,#0xCC]\n"
    "CMP     R0, #0\n"
    "BNE     loc_FF1D55BC\n"
    "MOV     R0, #0xC\n"
    "BL      sub_FF083430\n"
    "TST     R0, #1\n"
    "BEQ     loc_FF1D560C\n"
    "B       loc_FF1D5604\n"
"loc_FF1D55BC:\n"
    "LDRH    R0, [R5]\n"
    "CMP     R0, R6\n"
    "LDRNEH  R0, [R5,#0xA6]\n"
    "CMPNE   R0, #3\n"
    "LDRNE   R0, [R4,#8]\n"
    "CMPNE   R0, #1\n"
    "BLS     loc_FF1D55EC\n"
    "BL      sub_FF022080\n"
    "TST     R0, #1\n"
    "BEQ     loc_FF1D560C\n"
    "BL      sub_FF083490\n"
    "B       loc_FF1D5604\n"
"loc_FF1D55EC:\n"
    "MOV     R0, #0xC\n"
    "BL      sub_FF083430\n"
    "TST     R0, #1\n"
    "BEQ     loc_FF1D560C\n"
    "BL      sub_FF1D5DDC\n"
    "BL      sub_FF079D48\n"
"loc_FF1D5604:\n"
    "MOV     R0, #1\n"
    "LDMFD   SP!, {R3-R7,PC}\n"
"loc_FF1D560C:\n"
    "LDRH    R0, [R5]\n"
    "CMP     R0, R6\n"
    "LDRNEH  R0, [R5,#0xA6]\n"
    "CMPNE   R0, #3\n"
    "LDRNE   R0, [R4,#8]\n"
    "CMPNE   R0, #1\n"
    "BLS     loc_FF1D563C\n"
    "LDRH    R0, [R5,#0xA4]\n"
    "CMP     R0, #0\n"
    "LDREQH  R0, [R5,#0xA0]\n"
    "CMPEQ   R0, #2\n"
    "BLEQ    sub_FF07D4A4\n"
"loc_FF1D563C:\n"
    "LDRH    R1, [R5]\n"
    "LDRH    R0, [R5,#0xA6]\n"
    "CMP     R1, R6\n"
    "BEQ     loc_FF1D567C\n"
    "CMP     R0, #3\n"
    "BEQ     loc_FF1D56BC\n"
    "LDR     R0, [R4,#8]\n"
    "CMP     R0, #1\n"
    "BLS     loc_FF1D5684\n"
    "LDRH    R0, [R5,#0xA4]\n"
    "CMP     R0, #0\n"
    "BNE     loc_FF1D56BC\n"
    "LDRH    R0, [R5,#0xA0]\n"
    "CMP     R0, #2\n"
    "BEQ     loc_FF1D56B8\n"
    "B       loc_FF1D5690\n"
"loc_FF1D567C:\n"
    "CMP     R0, #3\n"
    "BEQ     loc_FF1D56BC\n"
"loc_FF1D5684:\n"
    "LDRH    R0, [R5,#0xA4]\n"
    "CMP     R0, #0\n"
    "BNE     loc_FF1D56BC\n"
"loc_FF1D5690:\n"
    "LDRH    R0, [R5,#0xA0]\n"
    "CMP     R0, #1\n"
    "BNE     loc_FF1D56BC\n"
    "CMP     R1, R6\n"
    "LDRNE   R0, [R4,#8]\n"
    "CMPNE   R0, #1\n"
    "BLS     loc_FF1D56BC\n"
    "LDR     R0, [R4,#0x10]\n"
    "CMP     R0, #1\n"
    "BNE     loc_FF1D56BC\n"
"loc_FF1D56B8:\n"
    "BL      sub_FF1D6560\n"
"loc_FF1D56BC:\n"
    "BL      sub_FF1D6528\n"
    "BL      sub_FF07CD60\n"
    "LDR     R0, [R5,#0x28]\n"
    "CMP     R0, #0\n"
    "BNE     loc_FF1D57AC\n"
    "MOV     R0, R4\n"
    "BL      sub_FF1D4660\n"
    "TST     R0, #1\n"
    "LDMNEFD SP!, {R3-R7,PC}\n"
    "LDR     R0, [R5,#0xCC]\n"
    "CMP     R0, #0\n"
    "LDRNEH  R0, [R5]\n"
    "CMPNE   R0, R6\n"
    "LDRNEH  R0, [R5,#0xA6]\n"
    "CMPNE   R0, #3\n"
    "LDRNE   R0, [R4,#8]\n"
    "CMPNE   R0, #1\n"
    "BHI     loc_FF1D571C\n"
    "MOV     R0, R4\n"
    "BL      sub_FF1D4A80\n"
    "BL      sub_FF1D5D20\n"
    "LDR     R0, [R5,#0xCC]\n"
    "CMP     R0, #0\n"
    "BEQ     loc_FF1D5738\n"
"loc_FF1D571C:\n"
    "LDRH    R0, [R5]\n"
    "CMP     R0, R6\n"
    "LDRNEH  R0, [R5,#0xA6]\n"
    "CMPNE   R0, #3\n"
    "LDRNE   R0, [R4,#8]\n"
    "CMPNE   R0, #1\n"
    "BHI     loc_FF1D5740\n"
"loc_FF1D5738:\n"
    "MOV     R0, #2\n"
    "BL      sub_FF084BA0\n"
	"BL      wait_until_remote_button_is_released\n"	// ++
	"BL      capt_seq_hook_set_nr\n"	// ++
"loc_FF1D5740:\n"
    "LDRH    R0, [R5]\n"
    "SUB     R1, R0, #0x4200\n"
    "SUBS    R1, R1, #0x2E\n"
    "BNE     loc_FF1D579C\n"
    "MOV     R5, #1\n"
    "MOV     R2, #2\n"
    "MOV     R1, SP\n"
    "ADD     R0, R2, #0x15C\n"
    "STR     R5, [SP]\n"
    "BL      sub_FF0910A4\n"
    "TST     R0, #1\n"
    "MOVNE   R1, #0xC5\n"
    "LDRNE   R0, =0xFF1D58E8\n"
    "BLNE    sub_FF00EDC8\n"
    "LDRH    R0, [SP]\n"
    "CMP     R0, #1\n"
    "BLS     loc_FF1D5794\n"
    "MOV     R0, R4\n"
    "STR     R5, [R4,#0x11C]\n"
    "BL      sub_FF3583B0\n"
    "B       loc_FF1D57A4\n"
"loc_FF1D5794:\n"
    "MOV     R0, #0\n"
    "STR     R0, [R4,#0x11C]\n"
"loc_FF1D579C:\n"
    "MOV     R0, R4\n"
    "BL      sub_FF1D5200\n"
"loc_FF1D57A4:\n"
    "MOV     R7, R0\n"
    "B       loc_FF1D57BC\n"
"loc_FF1D57AC:\n"
    "LDR     R0, =0x9958\n"
    "LDR     R0, [R0]\n"
    "CMP     R0, #0\n"
    "MOVNE   R7, #0x1D\n"
"loc_FF1D57BC:\n"
    "MOV     R0, R7\n"
    "LDMFD   SP!, {R3-R7,PC}\n"

	);
}

#if defined(OPT_EXT_TV_RANGE)
void __attribute__((naked,noinline)) exp_drv_task(){
	asm volatile(

	        "STMFD   SP!, {R4-R9,LR}\n"
	        "SUB     SP, SP, #0x24\n"
	        "LDR     R6, =0x4BF0\n"
	        "LDR     R7, =0xBB8\n"
	        "LDR     R4, =0x5CDA0\n"
	        "MOV     R0, #0\n"
	        "ADD     R5, SP, #0x14\n"
	        "STR     R0, [SP,#0x10]\n"
	"loc_FF0CC450:\n"
	        "LDR     R0, [R6,#0x20]\n"
	        "MOV     R2, #0\n"
	        "ADD     R1, SP, #0x20\n"
	        "BL      sub_FF02B0F4\n"
	        "LDR     R0, [SP,#0x10]\n"
	        "CMP     R0, #1\n"
	        "BNE     loc_FF0CC49C\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "LDR     R0, [R0]\n"
	        "CMP     R0, #0x14\n"
	        "CMPNE   R0, #0x15\n"
	        "CMPNE   R0, #0x16\n"
	        "CMPNE   R0, #0x17\n"
	        "BEQ     loc_FF0CC5FC\n"
	        "CMP     R0, #0x29\n"
	        "BEQ     loc_FF0CC584\n"
	        "ADD     R1, SP, #0x10\n"
	        "MOV     R0, #0\n"
	        "BL      sub_FF0CC3E0\n"
	"loc_FF0CC49C:\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "LDR     R1, [R0]\n"
	        "CMP     R1, #0x2F\n"
	        "BNE     loc_FF0CC4C8\n"
	        "BL      sub_FF0CD864\n"
	        "LDR     R0, [R6,#0x1C]\n"
	        "MOV     R1, #1\n"
	        "BL      sub_FF088B74\n"
	        "BL      sub_FF00ED80\n"
	        "ADD     SP, SP, #0x24\n"
	        "LDMFD   SP!, {R4-R9,PC}\n"
	"loc_FF0CC4C8:\n"
	        "CMP     R1, #0x2E\n"
	        "BNE     loc_FF0CC4E4\n"
	        "LDR     R2, [R0,#0x8C]!\n"
	        "LDR     R1, [R0,#4]\n"
	        "MOV     R0, R1\n"
	        "BLX     R2\n"
	        "B       loc_FF0CCA8C\n"
	"loc_FF0CC4E4:\n"
	        "CMP     R1, #0x27\n"
	        "BNE     loc_FF0CC534\n"
	        "LDR     R0, [R6,#0x1C]\n"
	        "MOV     R1, #0x80\n"
	        "BL      sub_FF088BA8\n"
	        "LDR     R0, =0xFF0C7464\n"
	        "MOV     R1, #0x80\n"
	        "BL      sub_FF1BD7E4\n"
	        "LDR     R0, [R6,#0x1C]\n"
	        "MOV     R2, R7\n"
	        "MOV     R1, #0x80\n"
	        "BL      sub_FF088AB4\n"
	        "TST     R0, #1\n"
	        "LDRNE   R1, =0x14FE\n"
	        "BNE     loc_FF0CC5F0\n"
	"loc_FF0CC520:\n"
	        "LDR     R1, [SP,#0x20]\n"
	        "LDR     R0, [R1,#0x90]\n"
	        "LDR     R1, [R1,#0x8C]\n"
	        "BLX     R1\n"
	        "B       loc_FF0CCA8C\n"
	"loc_FF0CC534:\n"
	        "CMP     R1, #0x28\n"
	        "BNE     loc_FF0CC57C\n"
	        "ADD     R1, SP, #0x10\n"
	        "BL      sub_FF0CC3E0\n"
	        "LDR     R0, [R6,#0x1C]\n"
	        "MOV     R1, #0x100\n"
	        "BL      sub_FF088BA8\n"
	        "LDR     R0, =0xFF0C7474\n"
	        "MOV     R1, #0x100\n"
	        "BL      sub_FF1BE5CC\n"
	        "LDR     R0, [R6,#0x1C]\n"
	        "MOV     R2, R7\n"
	        "MOV     R1, #0x100\n"
	        "BL      sub_FF088AB4\n"
	        "TST     R0, #1\n"
	        "BEQ     loc_FF0CC520\n"
	        "LDR     R1, =0x1508\n"
	        "B       loc_FF0CC5F0\n"
	"loc_FF0CC57C:\n"
	        "CMP     R1, #0x29\n"
	        "BNE     loc_FF0CC594\n"
	"loc_FF0CC584:\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "ADD     R1, SP, #0x10\n"
	        "BL      sub_FF0CC3E0\n"
	        "B       loc_FF0CC520\n"
	"loc_FF0CC594:\n"
	        "CMP     R1, #0x2C\n"
	        "BNE     loc_FF0CC5AC\n"
	        "BL      sub_FF0B7960\n"
	        "BL      sub_FF0B864C\n"
	        "BL      sub_FF0B81B0\n"
	        "B       loc_FF0CC520\n"
	"loc_FF0CC5AC:\n"
	        "CMP     R1, #0x2D\n"
	        "BNE     loc_FF0CC5FC\n"
	        "LDR     R0, [R6,#0x1C]\n"
	        "MOV     R1, #4\n"
	        "BL      sub_FF088BA8\n"
	        "LDR     R1, =0xFF0C7494\n"
	        "LDR     R0, =0xFFFFF400\n"
	        "MOV     R2, #4\n"
	        "BL      sub_FF0B73B0\n"
	        "BL      sub_FF0B7640\n"
	        "LDR     R0, [R6,#0x1C]\n"
	        "MOV     R2, R7\n"
	        "MOV     R1, #4\n"
	        "BL      sub_FF0889D0\n"
	        "TST     R0, #1\n"
	        "BEQ     loc_FF0CC520\n"
	        "LDR     R1, =0x1530\n"
	"loc_FF0CC5F0:\n"
	        "LDR     R0, =0xFF0C7C24\n"
	        "BL      sub_FF00EDC8\n"
	        "B       loc_FF0CC520\n"
	"loc_FF0CC5FC:\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "MOV     R8, #1\n"
	        "LDR     R1, [R0]\n"
	        "CMP     R1, #0x12\n"
	        "CMPNE   R1, #0x13\n"
	        "BNE     loc_FF0CC664\n"
	        "LDR     R1, [R0,#0x7C]\n"
	        "ADD     R1, R1, R1,LSL#1\n"
	        "ADD     R1, R0, R1,LSL#2\n"
	        "SUB     R1, R1, #8\n"
	        "LDMIA   R1, {R2,R3,R9}\n"
	        "STMIA   R5, {R2,R3,R9}\n"
	        "BL      sub_FF0CA65C\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "LDR     R1, [R0,#0x7C]\n"
	        "LDR     R3, [R0,#0x8C]\n"
	        "LDR     R2, [R0,#0x90]\n"
	        "ADD     R0, R0, #4\n"
	        "BLX     R3\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "BL      sub_FF0CDC70\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "LDR     R1, [R0,#0x7C]\n"
	        "LDR     R2, [R0,#0x98]\n"
	        "LDR     R3, [R0,#0x94]\n"
	        "B       loc_FF0CC978\n"
	"loc_FF0CC664:\n"
	        "CMP     R1, #0x14\n"
	        "CMPNE   R1, #0x15\n"
	        "CMPNE   R1, #0x16\n"
	        "CMPNE   R1, #0x17\n"
	        "BNE     loc_FF0CC71C\n"
	        "ADD     R3, SP, #0x10\n"
	        "ADD     R2, SP, #4\n"
	        "ADD     R1, SP, #0x14\n"
	        "BL      sub_FF0CA8C4\n"
	        "CMP     R0, #1\n"
	        "MOV     R9, R0\n"
	        "CMPNE   R9, #5\n"
	        "BNE     loc_FF0CC6B8\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "MOV     R2, R9\n"
	        "LDR     R1, [R0,#0x7C]!\n"
	        "LDR     R12, [R0,#0x10]!\n"
	        "LDR     R3, [R0,#4]\n"
	        "ADD     R0, SP, #4\n"
	        "BLX     R12\n"
	        "B       loc_FF0CC6F0\n"
	"loc_FF0CC6B8:\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "CMP     R9, #2\n"
	        "LDR     R3, [R0,#0x90]\n"
	        "CMPNE   R9, #6\n"
	        "BNE     loc_FF0CC704\n"
	        "LDR     R12, [R0,#0x8C]\n"
	        "MOV     R2, R9\n"
	        "MOV     R1, #1\n"
	        "ADD     R0, SP, #4\n"
	        "BLX     R12\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "ADD     R2, SP, #4\n"
	        "ADD     R1, SP, #0x14\n"
	        "BL      sub_FF0CC12C\n"
	"loc_FF0CC6F0:\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "LDR     R2, [SP,#0x10]\n"
	        "MOV     R1, R9\n"
	        "BL      sub_FF0CC380\n"
	        "B       loc_FF0CC980\n"
	"loc_FF0CC704:\n"
	        "LDR     R1, [R0,#0x7C]\n"
	        "LDR     R12, [R0,#0x8C]\n"
	        "MOV     R2, R9\n"
	        "ADD     R0, R0, #4\n"
	        "BLX     R12\n"
	        "B       loc_FF0CC980\n"
	"loc_FF0CC71C:\n"
	        "CMP     R1, #0x23\n"
	        "CMPNE   R1, #0x24\n"
	        "BNE     loc_FF0CC768\n"
	        "LDR     R1, [R0,#0x7C]\n"
	        "ADD     R1, R1, R1,LSL#1\n"
	        "ADD     R1, R0, R1,LSL#2\n"
	        "SUB     R1, R1, #8\n"
	        "LDMIA   R1, {R2,R3,R9}\n"
	        "STMIA   R5, {R2,R3,R9}\n"
	        "BL      sub_FF0C93B4\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "LDR     R1, [R0,#0x7C]\n"
	        "LDR     R3, [R0,#0x8C]\n"
	        "LDR     R2, [R0,#0x90]\n"
	        "ADD     R0, R0, #4\n"
	        "BLX     R3\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "BL      sub_FF0C98A8\n"
	        "B       loc_FF0CC980\n"
	"loc_FF0CC768:\n"
	        "ADD     R1, R0, #4\n"
	        "LDMIA   R1, {R2,R3,R9}\n"
	        "STMIA   R5, {R2,R3,R9}\n"
	        "LDR     R1, [R0]\n"
	        "CMP     R1, #0x27\n"
	        "ADDCC   PC, PC, R1,LSL#2\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC784:\n"
	        "B       loc_FF0CC820\n"
	"loc_FF0CC788:\n"
	        "B       loc_FF0CC820\n"
	"loc_FF0CC78C:\n"
	        "B       loc_FF0CC828\n"
	"loc_FF0CC790:\n"
	        "B       loc_FF0CC830\n"
	"loc_FF0CC794:\n"
	        "B       loc_FF0CC830\n"
	"loc_FF0CC798:\n"
	        "B       loc_FF0CC830\n"
	"loc_FF0CC79C:\n"
	        "B       loc_FF0CC820\n"
	"loc_FF0CC7A0:\n"
	        "B       loc_FF0CC828\n"
	"loc_FF0CC7A4:\n"
	        "B       loc_FF0CC830\n"
	"loc_FF0CC7A8:\n"
	        "B       loc_FF0CC830\n"
	"loc_FF0CC7AC:\n"
	        "B       loc_FF0CC848\n"
	"loc_FF0CC7B0:\n"
	        "B       loc_FF0CC848\n"
	"loc_FF0CC7B4:\n"
	        "B       loc_FF0CC954\n"
	"loc_FF0CC7B8:\n"
	        "B       loc_FF0CC95C\n"
	"loc_FF0CC7BC:\n"
	        "B       loc_FF0CC95C\n"
	"loc_FF0CC7C0:\n"
	        "B       loc_FF0CC95C\n"
	"loc_FF0CC7C4:\n"
	        "B       loc_FF0CC95C\n"
	"loc_FF0CC7C8:\n"
	        "B       loc_FF0CC964\n"
	"loc_FF0CC7CC:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC7D0:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC7D4:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC7D8:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC7DC:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC7E0:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC7E4:\n"
	        "B       loc_FF0CC838\n"
	"loc_FF0CC7E8:\n"
	        "B       loc_FF0CC840\n"
	"loc_FF0CC7EC:\n"
	        "B       loc_FF0CC840\n"
	"loc_FF0CC7F0:\n"
	        "B       loc_FF0CC854\n"
	"loc_FF0CC7F4:\n"
	        "B       loc_FF0CC854\n"
	"loc_FF0CC7F8:\n"
	        "B       loc_FF0CC85C\n"
	"loc_FF0CC7FC:\n"
	        "B       loc_FF0CC894\n"
	"loc_FF0CC800:\n"
	        "B       loc_FF0CC8CC\n"
	"loc_FF0CC804:\n"
	        "B       loc_FF0CC904\n"
	"loc_FF0CC808:\n"
	        "B       loc_FF0CC93C\n"
	"loc_FF0CC80C:\n"
	        "B       loc_FF0CC93C\n"
	"loc_FF0CC810:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC814:\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC818:\n"
	        "B       loc_FF0CC944\n"
	"loc_FF0CC81C:\n"
	        "B       loc_FF0CC94C\n"
	"loc_FF0CC820:\n"
	        "BL      sub_FF0C7A58\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC828:\n"
	        "BL      sub_FF0C7D50\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC830:\n"
	        "BL      sub_FF0C7FB8\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC838:\n"
	        "BL      sub_FF0C82AC\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC840:\n"
	        "BL      sub_FF0C84C4\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC848:\n"
	        //"BL      sub_FF0C8980\n" //--
			"BL      sub_FF0C8980_my\n" // +------->
	        "MOV     R8, #0\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC854:\n"
	        "BL      sub_FF0C8B64\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC85C:\n"
	        "LDRH    R1, [R0,#4]\n"
	        "STRH    R1, [SP,#0x14]\n"
	        "LDRH    R1, [R4,#2]\n"
	        "STRH    R1, [SP,#0x16]\n"
	        "LDRH    R1, [R4,#4]\n"
	        "STRH    R1, [SP,#0x18]\n"
	        "LDRH    R1, [R4,#6]\n"
	        "STRH    R1, [SP,#0x1A]\n"
	        "LDRH    R1, [R0,#0xC]\n"
	        "STRH    R1, [SP,#0x1C]\n"
	        "LDRH    R1, [R4,#0xA]\n"
	        "STRH    R1, [SP,#0x1E]\n"
	        "BL      sub_FF0CD8F8\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC894:\n"
	        "LDRH    R1, [R0,#4]\n"
	        "STRH    R1, [SP,#0x14]\n"
	        "LDRH    R1, [R4,#2]\n"
	        "STRH    R1, [SP,#0x16]\n"
	        "LDRH    R1, [R4,#4]\n"
	        "STRH    R1, [SP,#0x18]\n"
	        "LDRH    R1, [R4,#6]\n"
	        "STRH    R1, [SP,#0x1A]\n"
	        "LDRH    R1, [R4,#8]\n"
	        "STRH    R1, [SP,#0x1C]\n"
	        "LDRH    R1, [R4,#0xA]\n"
	        "STRH    R1, [SP,#0x1E]\n"
	        "BL      sub_FF0CDA70\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC8CC:\n"
	        "LDRH    R1, [R4]\n"
	        "STRH    R1, [SP,#0x14]\n"
	        "LDRH    R1, [R0,#6]\n"
	        "STRH    R1, [SP,#0x16]\n"
	        "LDRH    R1, [R4,#4]\n"
	        "STRH    R1, [SP,#0x18]\n"
	        "LDRH    R1, [R4,#6]\n"
	        "STRH    R1, [SP,#0x1A]\n"
	        "LDRH    R1, [R4,#8]\n"
	        "STRH    R1, [SP,#0x1C]\n"
	        "LDRH    R1, [R4,#0xA]\n"
	        "STRH    R1, [SP,#0x1E]\n"
	        "BL      sub_FF0CDB24\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC904:\n"
	        "LDRH    R1, [R4]\n"
	        "STRH    R1, [SP,#0x14]\n"
	        "LDRH    R1, [R4,#2]\n"
	        "STRH    R1, [SP,#0x16]\n"
	        "LDRH    R1, [R4,#4]\n"
	        "STRH    R1, [SP,#0x18]\n"
	        "LDRH    R1, [R4,#6]\n"
	        "STRH    R1, [SP,#0x1A]\n"
	        "LDRH    R1, [R0,#0xC]\n"
	        "STRH    R1, [SP,#0x1C]\n"
	        "LDRH    R1, [R4,#0xA]\n"
	        "STRH    R1, [SP,#0x1E]\n"
	        "BL      sub_FF0CDBCC\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC93C:\n"
	        "BL      sub_FF0C914C\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC944:\n"
	        "BL      sub_FF0C99AC\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC94C:\n"
	        "BL      sub_FF0C9F04\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC954:\n"
	        "BL      sub_FF0CA128\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC95C:\n"
	        "BL      sub_FF0CA2E4\n"
	        "B       loc_FF0CC968\n"
	"loc_FF0CC964:\n"
	        "BL      sub_FF0CA454\n"
	"loc_FF0CC968:\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "LDR     R1, [R0,#0x7C]\n"
	        "LDR     R2, [R0,#0x90]\n"
	        "LDR     R3, [R0,#0x8C]\n"
	"loc_FF0CC978:\n"
	        "ADD     R0, R0, #4\n"
	        "BLX     R3\n"
	"loc_FF0CC980:\n"
	        "LDR     R1, [SP,#0x20]\n"
	        "LDR     R0, [R1]\n"
	        "CMP     R0, #0x10\n"
	        "BEQ     loc_FF0CC9B8\n"
	        "BGT     loc_FF0CC9A8\n"
	        "CMP     R0, #1\n"
	        "CMPNE   R0, #4\n"
	        "CMPNE   R0, #0xE\n"
	        "BNE     loc_FF0CC9C8\n"
	        "B       loc_FF0CC9B8\n"
	"loc_FF0CC9A8:\n"
	        "CMP     R0, #0x13\n"
	        "CMPNE   R0, #0x17\n"
	        "CMPNE   R0, #0x1A\n"
	        "BNE     loc_FF0CC9C8\n"
	"loc_FF0CC9B8:\n"
	        "LDRH    R0, [R4]\n"
	        "STRH    R0, [SP,#0x14]\n"
	        "LDRH    R0, [R4,#8]\n"
	        "STRH    R0, [SP,#0x1C]\n"
	"loc_FF0CC9C8:\n"
	        "CMP     R8, #1\n"
	        "BNE     loc_FF0CCA14\n"
	        "LDR     R0, [R1,#0x7C]\n"
	        "MOV     R2, #0xC\n"
	        "ADD     R0, R0, R0,LSL#1\n"
	        "ADD     R0, R1, R0,LSL#2\n"
	        "SUB     R8, R0, #8\n"
	        "LDR     R0, =0x5CDA0\n"
	        "ADD     R1, SP, #0x14\n"
	        "BL      sub_FF42FA94\n"
	        "LDR     R0, =0x5CDAC\n"
	        "MOV     R2, #0xC\n"
	        "ADD     R1, SP, #0x14\n"
	        "BL      sub_FF42FA94\n"
	        "LDR     R0, =0x5CDB8\n"
	        "MOV     R2, #0xC\n"
	        "MOV     R1, R8\n"
	        "BL      sub_FF42FA94\n"
	        "B       loc_FF0CCA8C\n"
	"loc_FF0CCA14:\n"
	        "LDR     R0, [R1]\n"
	        "MOV     R3, #1\n"
	        "CMP     R0, #0xB\n"
	        "BNE     loc_FF0CCA58\n"
	        "MOV     R2, #0\n"
	        "STRD    R2, [SP]\n"
	        "MOV     R2, R3\n"
	        "MOV     R1, R3\n"
	        "MOV     R0, #0\n"
	        "BL      sub_FF0C782C\n"
	        "MOV     R3, #1\n"
	        "MOV     R2, #0\n"
	        "STRD    R2, [SP]\n"
	        "MOV     R2, R3\n"
	        "MOV     R1, R3\n"
	        "MOV     R0, #0\n"
	        "B       loc_FF0CCA88\n"
	"loc_FF0CCA58:\n"
	        "MOV     R2, #1\n"
	        "STRD    R2, [SP]\n"
	        "MOV     R3, R2\n"
	        "MOV     R1, R2\n"
	        "MOV     R0, R2\n"
	        "BL      sub_FF0C782C\n"
	        "MOV     R3, #1\n"
	        "MOV     R2, R3\n"
	        "MOV     R1, R3\n"
	        "MOV     R0, R3\n"
	        "STR     R3, [SP]\n"
	        "STR     R3, [SP,#4]\n"
	"loc_FF0CCA88:\n"
	        "BL      sub_FF0C79A4\n"
	"loc_FF0CCA8C:\n"
	        "LDR     R0, [SP,#0x20]\n"
	        "BL      sub_FF0CD864\n"
	        "B       loc_FF0CC450\n"

	);
}

void __attribute__((naked,noinline)) sub_FF0C8980_my(){ 
	asm volatile(
	        "STMFD   SP!, {R4-R8,LR}\n"
	        "LDR     R7, =0x4BF0\n"
	        "MOV     R4, R0\n"
	        "LDR     R0, [R7,#0x1C]\n"
	        "MOV     R1, #0x3E\n"
	        "BL      sub_FF088BA8\n"
	        "MOV     R2, #0\n"
	        "LDRSH   R0, [R4,#4]\n"
	        "MOV     R1, R2\n"
	        "BL      sub_FF0C74F4\n"
	        "MOV     R5, R0\n"
	        "LDRSH   R0, [R4,#6]\n"
	        "BL      sub_FF0C7644\n"
	        "LDRSH   R0, [R4,#8]\n"
	        "BL      sub_FF0C769C\n"
	        "LDRSH   R0, [R4,#0xA]\n"
	        "BL      sub_FF0C76F4\n"
	        "LDRSH   R0, [R4,#0xC]\n"
	        "MOV     R1, #0\n"
	        "BL      sub_FF0C774C\n"
	        "MOV     R6, R0\n"
	        "LDRSH   R0, [R4,#0xE]\n"
	        "BL      sub_FF0CD894\n"
	        "LDR     R0, [R4]\n"
	        "LDR     R8, =0x5CDB8\n"
	        "CMP     R0, #0xB\n"
	        "MOVEQ   R5, #0\n"
	        "MOVEQ   R6, R5\n"
	        "BEQ     loc_FF0C8A1C\n"
	        "CMP     R5, #1\n"
	        "BNE     loc_FF0C8A1C\n"
	        "LDRSH   R0, [R4,#4]\n"
	        "LDR     R1, =0xFF0C7454\n"
	        "MOV     R2, #2\n"
	        "BL      sub_FF1BDB38\n"
	        "STRH    R0, [R4,#4]\n"
	        "MOV     R0, #0\n"
	        "STR     R0, [R7,#0x28]\n"
	        "B       loc_FF0C8A24\n"
	"loc_FF0C8A1C:\n"
	        "LDRH    R0, [R8]\n"
	        "STRH    R0, [R4,#4]\n"
	"loc_FF0C8A24:\n"
	        "CMP     R6, #1\n"
	        "LDRNEH  R0, [R8,#8]\n"
	        "BNE     loc_FF0C8A40\n"
	        "LDRSH   R0, [R4,#0xC]\n"
	        "LDR     R1, =0xFF0C74D8\n"
	        "MOV     R2, #0x20\n"
	        "BL      sub_FF0CD8B4\n"
	"loc_FF0C8A40:\n"
	        "STRH    R0, [R4,#0xC]\n"
	        "LDRSH   R0, [R4,#6]\n"
	        //"BL      sub_FF0B76AC\n" // ---
			"BL      sub_FF0B76AC_my\n" // +------->
	        "LDRSH   R0, [R4,#8]\n"
	        "MOV     R1, #1\n"
	        "BL      sub_FF0B7EEC\n"
	        "MOV     R1, #0\n"
	        "ADD     R0, R4, #8\n"
	        "BL      sub_FF0B7F74\n"
	        "LDRSH   R0, [R4,#0xE]\n"
	        "BL      sub_FF0C21E8\n"
	        "LDR     R4, =0xBB8\n"
	        "CMP     R5, #1\n"
	        "BNE     loc_FF0C8A98\n"
	        "LDR     R0, [R7,#0x1C]\n"
	        "MOV     R2, R4\n"
	        "MOV     R1, #2\n"
	        "BL      sub_FF088AB4\n"
	        "TST     R0, #1\n"
	        "LDRNE   R1, =0x73A\n"
	        "LDRNE   R0, =0xFF0C7C24\n"
	        "BLNE    sub_FF00EDC8\n"
	"loc_FF0C8A98:\n"
	        "CMP     R6, #1\n"
	        "LDMNEFD SP!, {R4-R8,PC}\n"
	        "LDR     R0, [R7,#0x1C]\n"
	        "MOV     R2, R4\n"
	        "MOV     R1, #0x20\n"
	        "BL      sub_FF088AB4\n"
	        "TST     R0, #1\n"
	        "LDMEQFD SP!, {R4-R8,PC}\n"
	        "LDMFD   SP!, {R4-R8,LR}\n"
	        "LDR     R1, =0x73F\n"
	        "LDR     R0, =0xFF0C7C24\n"
	        "B       sub_FF00EDC8\n"
	);
}

void __attribute__((naked,noinline)) sub_FF0B76AC_my(){ 
	asm volatile(
	        "STMFD   SP!, {R4-R6,LR}\n"
	        "LDR     R5, =0x4898\n"
	        "MOV     R4, R0\n"
	        "LDR     R0, [R5,#4]\n"
	        "CMP     R0, #1\n"
	        "LDRNE   R1, =0x14D\n"
	        "LDRNE   R0, =0xFF0B74E4\n"
	        "BLNE    sub_FF00EDC8\n"
	        "CMN     R4, #0xC00\n"
	        "LDREQSH R4, [R5,#2]\n"
	        "CMN     R4, #0xC00\n"
	        "LDREQ   R1, =0x153\n"
	        "LDREQ   R0, =0xFF0B74E4\n"
	        "STRH    R4, [R5,#2]\n"
	        "BLEQ    sub_FF00EDC8\n"
	        "MOV     R0, R4\n"
	        //"BL      sub_FF297C28\n"
			"BL      apex2us\n" // +++
	        "MOV     R4, R0\n"
	        "BL      sub_FF12CD1C\n"
	        "MOV     R0, R4\n"
	        "BL      sub_FF136820\n"
	        "TST     R0, #1\n"
	        "LDMEQFD SP!, {R4-R6,PC}\n"
	        "LDMFD   SP!, {R4-R6,LR}\n"
	        "MOV     R1, #0x158\n"
	        "LDR     R0, =0xFF0B74E4\n"
	        "B       sub_FF00EDC8\n"
	);
}
#endif

