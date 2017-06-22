#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "stdlib.h"


const char * const new_sa = &_end;


// Forward declarations
void CreateTask_PhySw();
void CreateTask_spytask();

void taskCreateHook(int *p) { 
p-=17;
if (p[0]==0xFF87A208)  p[0]=(int)capt_seq_task;
if (p[0]==0xFF96172C)  p[0]=(int)movie_record_task;
if (p[0]==0xFF8982E8)  p[0]=(int)init_file_modules_task;
}

void taskCreateHook2(int *p) { 
p-=17;
if (p[0]==0xFF8982E8)  p[0]=(int)init_file_modules_task;
}

void __attribute__((naked,noinline)) boot() {
    asm volatile (
                "LDR     R1, =0xC0410000\n"
                "MOV     R0, #0\n"
                "STR     R0, [R1]\n"
                "MOV     R1, #0x78\n"
                "MCR     p15, 0, R1,c1,c0\n"
                "MOV     R1, #0\n"
                "MCR     p15, 0, R1,c7,c10, 4\n"
                "MCR     p15, 0, R1,c7,c5\n"
                "MCR     p15, 0, R1,c7,c6\n"
                "MOV     R0, #0x3D\n"
                "MCR     p15, 0, R0,c6,c0\n"
                "MOV     R0, #0xC000002F\n"
                "MCR     p15, 0, R0,c6,c1\n"
                "MOV     R0, #0x33\n"
                "MCR     p15, 0, R0,c6,c2\n"
                "MOV     R0, #0x40000033\n"
                "MCR     p15, 0, R0,c6,c3\n"
                "MOV     R0, #0x80000017\n"
                "MCR     p15, 0, R0,c6,c4\n"
                "LDR     R0, =0xFF80002D\n"
                "MCR     p15, 0, R0,c6,c5\n"
                "MOV     R0, #0x34\n"
                "MCR     p15, 0, R0,c2,c0\n"
                "MOV     R0, #0x34\n"
                "MCR     p15, 0, R0,c2,c0, 1\n"
                "MOV     R0, #0x34\n"
                "MCR     p15, 0, R0,c3,c0\n"
                "LDR     R0, =0x3333330\n"
                "MCR     p15, 0, R0,c5,c0, 2\n"
                "LDR     R0, =0x3333330\n"
                "MCR     p15, 0, R0,c5,c0, 3\n"
                "MRC     p15, 0, R0,c1,c0\n"
                "ORR     R0, R0, #0x1000\n"
                "ORR     R0, R0, #4\n"
                "ORR     R0, R0, #1\n"
                "MCR     p15, 0, R0,c1,c0\n"
                "MOV     R1, #0x80000006\n"
                "MCR     p15, 0, R1,c9,c1\n"
                "MOV     R1, #6\n"
                "MCR     p15, 0, R1,c9,c1, 1\n"
                "MRC     p15, 0, R1,c1,c0\n"
                "ORR     R1, R1, #0x50000\n"
                "MCR     p15, 0, R1,c1,c0\n"
                "LDR     R2, =0xC0200000\n"
                "MOV     R1, #1\n"
                "STR     R1, [R2,#0x10C]\n"
                "MOV     R1, #0xFF\n"
                "STR     R1, [R2,#0xC]\n"
                "STR     R1, [R2,#0x1C]\n"
                "STR     R1, [R2,#0x2C]\n"
                "STR     R1, [R2,#0x3C]\n"
                "STR     R1, [R2,#0x4C]\n"
                "STR     R1, [R2,#0x5C]\n"
                "STR     R1, [R2,#0x6C]\n"
                "STR     R1, [R2,#0x7C]\n"
                "STR     R1, [R2,#0x8C]\n"
                "STR     R1, [R2,#0x9C]\n"
                "STR     R1, [R2,#0xAC]\n"
                "STR     R1, [R2,#0xBC]\n"
                "STR     R1, [R2,#0xCC]\n"
                "STR     R1, [R2,#0xDC]\n"
                "STR     R1, [R2,#0xEC]\n"
                "STR     R1, [R2,#0xFC]\n"
                "LDR     R1, =0xC0400008\n"
                "LDR     R2, =0x430005\n"
                "STR     R2, [R1]\n"
                "MOV     R1, #1\n"
                "LDR     R2, =0xC0243100\n"
                "STR     R2, [R1]\n"
                "LDR     R2, =0xC0242010\n"
                "LDR     R1, [R2]\n"
                "ORR     R1, R1, #1\n"
                "STR     R1, [R2]\n"
                "LDR     R0, =0xFFC14C88\n" //"dated already"
                "LDR     R1, =0x1900\n"	// MEMBASEADDR=0x1900
                "LDR     R3, =0xF470\n"

 "loc_FF81013C:\n"
                "CMP     R1, R3\n"
                "LDRCC   R2, [R0],#4\n"
                "STRCC   R2, [R1],#4\n"
                "BCC     loc_FF81013C\n"
                "LDR     R1, =0x141DBC\n"	// MEMISOSTART=0x141DBC
                "MOV     R2, #0\n"

"loc_FF810154:\n"
                "CMP     R3, R1\n"
                "STRCC   R2, [R3],#4\n"
                "BCC     loc_FF810154\n"
                // "B       loc_FF810354\n"
				"B       sub_FF810354_my\n" // ---------------->
    );
};

void __attribute__((naked,noinline)) sub_FF810354_my() {

    *(int*)0x1930=(int)taskCreateHook; 
    *(int*)0x1934=(int)taskCreateHook2; 
    *(int*)0x1938=(int)taskCreateHook; 		

    /* Power ON/OFF detection */
	*(int*)(0x254C)= (*(int*)0xC0220128)&1 ? 0x2000000 : 0x1000000; // replacement  for correct power-on.

		asm volatile (	
                "LDR     R0, =0xFF8103CC\n"
                "MOV     R1, #0\n"
                "LDR     R3, =0xFF810404\n"

"loc_FF810360:\n"
                "CMP     R0, R3\n"
                "LDRCC   R2, [R0],#4\n"
                "STRCC   R2, [R1],#4\n"
                "BCC     loc_FF810360\n"
                "LDR     R0, =0xFF810404\n"
                "MOV     R1, #0x4B0\n"
                "LDR     R3, =0xFF810618\n"

"loc_FF81037C:\n"
                "CMP     R0, R3\n"
                "LDRCC   R2, [R0],#4\n"
                "STRCC   R2, [R1],#4\n"
                "BCC     loc_FF81037C\n"
                "MOV     R0, #0xD2\n"
                "MSR     CPSR_cxsf, R0\n"
                "MOV     SP, #0x1000\n"
                "MOV     R0, #0xD3\n"
                "MSR     CPSR_cxsf, R0\n"
                "MOV     SP, #0x1000\n"
                "LDR     R0, =0x6C4\n"
                "LDR     R2, =0xEEEEEEEE\n"
                "MOV     R3, #0x1000\n"

"loc_FF8103B0:\n"
                "CMP     R0, R3\n"
                "STRCC   R2, [R0],#4\n"
                "BCC     loc_FF8103B0\n"
                //"BL      sub_FF811178\n"
				"BL      sub_FF811178_my\n" // ------------->

"loc_FF8103C0:\n"
                "ANDEQ   R0, R0, R4,ASR#13\n"

"loc_FF8103C4:\n"
                "ANDEQ   R0, R0, R0,ROR R6\n"

"loc_FF8103C8:\n"
                "ANDEQ   R0, R0, R4,ROR R6\n"
                "NOP\n"
                "LDR     PC, =0xFF810618\n"
  );				
};


void __attribute__((naked,noinline)) sub_FF811178_my() { 
        asm volatile ( 
        "STR     LR, [SP,#-4]!\n"
        "SUB     SP, SP, #0x74\n"
        "MOV     R0, SP\n"
        "MOV     R1, #0x74\n"
        "BL      sub_FFB34E24\n"
        "MOV     R0, #0x53000\n"
        "STR     R0, [SP,#4]\n"
        //"LDR     R0, =0x141DBC\n"
		 "LDR     R0, =new_sa\n"        // +
		 "LDR     R0, [R0]\n"           // +	
        "LDR     R2, =0x379C00\n"
        "LDR     R1, =0x3724A8\n"
        "STR     R0, [SP,#8]\n"
        "SUB     R0, R1, R0\n"
        "ADD     R3, SP, #0xC\n"
        "STR     R2, [SP]\n"
        "STMIA   R3, {R0-R2}\n"
        "MOV     R0, #0x22\n"
        "STR     R0, [SP,#0x18]\n"
        "MOV     R0, #0x68\n"
        "STR     R0, [SP,#0x1C]\n"
        "LDR     R0, =0x19B\n"
        //"LDR     R1, =sub_FF815E34\n"
		"LDR     R1, =sub_FF815E34_my\n"
        "STR     R0, [SP,#0x20]\n"
        "MOV     R0, #0x96\n"
        "STR     R0, [SP,#0x24]\n"
        "MOV     R0, #0x78\n"
        "STR     R0, [SP,#0x28]\n"
        "MOV     R0, #0x64\n"
        "STR     R0, [SP,#0x2C]\n"
        "MOV     R0, #0\n"
        "STR     R0, [SP,#0x30]\n"
        "STR     R0, [SP,#0x34]\n"
        "MOV     R0, #0x10\n"
        "STR     R0, [SP,#0x5C]\n"
        "MOV     R0, #0x800\n"
        "STR     R0, [SP,#0x60]\n"
        "MOV     R0, #0xA0\n"
        "STR     R0, [SP,#0x64]\n"
        "MOV     R0, #0x280\n"
        "STR     R0, [SP,#0x68]\n"
        "MOV     R0, SP\n"
        "MOV     R2, #0\n"
        "BL      sub_FF8133E4\n"
        "ADD     SP, SP, #0x74\n"
        "LDR     PC, [SP],#4\n"
        );
}; 

void __attribute__((naked,noinline)) sub_FF815E34_my() {
	asm volatile (
        "STMFD   SP!, {R4,LR}\n"
        "BL      sub_FF810B08\n"
        "BL      sub_FF81A148\n"
        "CMP     R0, #0\n"
        //"ADRLT   R0, 0xFF815F48\n"
		"LDRLT   R0, =0xFF815F48\n"
        "BLLT    sub_FF815F28\n"
        "BL      sub_FF815A70\n"
        "CMP     R0, #0\n"
        //"ADRLT   R0, 0xFF815F50\n"
		"LDRLT   R0, =0xFF815F50\n"
        "BLLT    sub_FF815F28\n"
        //"ADR     R0, 0xFF815F60\n"
		"LDR     R0, =0xFF815F60\n"
        "BL      sub_FF815B58\n"
        "CMP     R0, #0\n"
        //"ADRLT   R0, 0xFF815F68\n"
		"LDRLT   R0, =0xFF815F68\n"
        "BLLT    sub_FF815F28\n"
        //"ADR     R0, 0xFF815F60\n"
		"LDR     R0, =0xFF815F60\n"
        "BL      sub_FF813BE0\n"
        "CMP     R0, #0\n"
        //"ADRLT   R0, 0xFF815F7C\n"
		"LDRLT   R0, =0xFF815F7C\n"
        "BLLT    sub_FF815F28\n"
        "BL      sub_FF819B5C\n"
        "CMP     R0, #0\n"
        //"ADRLT   R0, 0xFF815F88\n"
		"LDRLT   R0, =0xFF815F88\n"
        "BLLT    sub_FF815F28\n"
        "BL      sub_FF81165C\n"
        "CMP     R0, #0\n"
        //"ADRLT   R0, 0xFF815F94\n"
		"LDRLT   R0, =0xFF815F94\n"
        "BLLT    sub_FF815F28\n"
        "LDMFD   SP!, {R4,LR}\n"
        //"B       sub_FF81F868\n"
		"B       taskcreate_Startup_my\n" //---------->
        );
}; 



void __attribute__((naked,noinline)) taskcreate_Startup_my() { 
	asm volatile (	
        "STMFD   SP!, {R3-R5,LR}\n"
        "BL      sub_FF833350\n"
        "BL      sub_FF83A614\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF81F8B0\n"
        "LDR     R4, =0xC0220000\n"
        "LDR     R0, [R4,#0x12C]\n"
        "TST     R0, #1\n"
        "MOVEQ   R0, #0x12C\n"
        "BLEQ    sub_FF838A50\n"
        "BL      sub_FF83334C\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF81F8B0\n"
        "BL      sub_FF8329F4\n"
        "MOV     R0, #0x44\n"
        "STR     R0, [R4,#0x1C]\n"
        "BL      sub_FF832BE8\n"
"loc_FF81F8AC:\n"
        "B       loc_FF81F8AC\n"
"loc_FF81F8B0:\n"
        //"BL      sub_FF833358\n" // removed, see boot() function
        "BL      sub_FF833354\n"
        "BL      sub_FF8388C8\n"
        "LDR     R1, =0x3CE000\n"
        "MOV     R0, #0\n"
        "BL      sub_FF838D10\n"
        "BL      sub_FF838ABC\n"
        "MOV     R3, #0\n"
        "STR     R3, [SP]\n"
		"LDR     R3, =task_Startup_my\n" //+ ----------->
        //"ADR     R3, sub_FF81F804\n"
        "MOV     R2, #0\n"
        "MOV     R1, #0x19\n"
        //"ADR     R0, 0xFF81F8F8\n"
		"LDR     R0, =0xFF81F8F8\n"
        "BL      sub_FF81E5B4\n"
        "MOV     R0, #0\n"
        "LDMFD   SP!, {R3-R5,PC}\n"

		//"LDMFD   SP!, {R12,PC}\n" ??????????????????????????????????????????????????
 );
}; 

void __attribute__((naked,noinline)) task_Startup_my() { 

       	asm volatile (
        "STMFD   SP!, {R4,LR}\n"
        "BL      sub_FF816490\n"
        "BL      sub_FF83444C\n"
        "BL      sub_FF832670\n"
        "BL      sub_FF83A654\n"
        "BL      sub_FF83A838\n"
        // "BL      sub_FF83A6E8\n" // Skip starting diskboot.bin again
        "BL      sub_FF83A9D8\n"
        "BL      sub_FF83136C\n"
        "BL      sub_FF83A868\n"
        "BL      sub_FF83806C\n"
        "BL      sub_FF83A9DC\n"
        //"BL      sub_FF83323C\n" ; taskcreate_PhySw
	);		 
	CreateTask_PhySw(); // +
	CreateTask_spytask();  // +
    asm volatile (		
		"BL      sub_FF836080\n"
		"BL      sub_FF83A9F4\n"
		"BL      sub_FF8306A4\n"
		"BL      sub_FF831FC8\n"
		"BL      sub_FF83A3F0\n"
		"BL      sub_FF832624\n"
		"BL      sub_FF831ED4\n"
		"BL      sub_FF8313A0\n"
		"BL      sub_FF83B564\n"
		"BL      sub_FF831EAC\n"
		"LDMFD   SP!, {R4,LR}\n"
		"B       sub_FF8165B0\n"
	);
}; 

void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    core_spytask();
}

void beeper(long ua, long ub, long uc, long ud, long ue, long uf)
{
 bgndBeeper();
}

void CreateTask_spytask() { 
_CreateTask("Beeper", 0x1, 0x200, beeper, 0);
        _CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
};

void __attribute__((naked,noinline)) CreateTask_PhySw() {
       	asm volatile ( 

        "STMFD   SP!, {R3-R5,LR}\n"
        "LDR     R4, =0x1C38\n"
        "LDR     R0, [R4,#0x10]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF833270\n"
        "MOV     R3, #0\n"
        "STR     R3, [SP]\n"
        //"ADR     R3, sub_FF833208\n"
        //"MOV     R2, #0x800\n"
			   "LDR     R3, =mykbd_task\n"  // task_phySw
			   "MOV     R2, #0x2000\n"		// greater Stacksize
        "MOV     R1, #0x17\n"
        //"ADR     R0, 0xFF833444\n"
		"LDR     R0, =0xFF833444\n"
        "BL      sub_FF838B10\n"
        "STR     R0, [R4,#0x10]\n"
"loc_FF833270:\n"
        "BL      sub_FF85E8B0\n"
        "BL      sub_FF88AF00\n"
        "BL      sub_FF861E20\n"
        "CMP     R0, #0\n"
        "LDREQ   R1, =0x330E4\n"
        "LDMEQFD SP!, {R3-R5,LR}\n"
        "BEQ     sub_FF88AE88\n"
        "LDMFD   SP!, {R3-R5,PC}\n"
	    "NOP\n"
	);
};

void __attribute__((naked,noinline)) init_file_modules_task() { 
  asm volatile (
        "STMFD   SP!, {R4-R6,LR}\n"
        "BL      sub_FF88D304\n"
        "LDR     R5, =0x5006\n"
        "MOVS    R4, R0\n"
        "MOVNE   R1, #0\n"
        "MOVNE   R0, R5\n"
        "BLNE    sub_FF8924F4\n"
        //"BL      sub_FF88D330\n"
		"BL      sub_FF88D330_my\n"
		"BL      core_spytask_can_start\n"      // +
        "CMP     R4, #0\n"
        "MOVEQ   R0, R5\n"
        "LDMEQFD SP!, {R4-R6,LR}\n"
        "MOVEQ   R1, #0\n"
        "BEQ     sub_FF8924F4\n"
        "LDMFD   SP!, {R4-R6,PC}\n"
 );
}; 

void __attribute__((naked,noinline)) sub_FF88D330_my() { 
 asm volatile (
        "STMFD   SP!, {R4,LR}\n"
        "MOV     R0, #3\n"
        //"BL      sub_FF86DFAC\n"
		"BL      sub_FF86DFAC_my\n" // ----------->
        "BL      sub_FF9475FC\n"
        "LDR     R4, =0x302C\n"
        "LDR     R0, [R4,#4]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF88D368\n"
        "BL      sub_FF86D2B8\n"
        "BL      sub_FF93B638\n"
        "BL      sub_FF86D2B8\n"
        "BL      sub_FF8695B4\n"
        "BL      sub_FF86D1B8\n"
        "BL      sub_FF93B700\n"
"loc_FF88D368:\n"
        "MOV     R0, #1\n"
        "STR     R0, [R4]\n"
        "LDMFD   SP!, {R4,PC}\n"
 );
}; 


void __attribute__((naked,noinline)) sub_FF86DFAC_my() {
 asm volatile (
        "STMFD   SP!, {R4-R8,LR}\n"
        "MOV     R8, R0\n"
        "BL      sub_FF86DF2C\n"
        "LDR     R1, =0x37EA0\n"
        "MOV     R6, R0\n"
        "ADD     R4, R1, R0,LSL#7\n"
        "LDR     R0, [R4,#0x6C]\n"
        "CMP     R0, #4\n"
        "LDREQ   R1, =0x804\n"
        //"ADREQ   R0, 0xFF86DA78\n"
		"LDREQ   R0, =0xFF86DA78\n"
        "BLEQ    sub_FF81E88C\n"
        "MOV     R1, R8\n"
        "MOV     R0, R6\n"
        "BL      sub_FF86D7CC\n"
        "LDR     R0, [R4,#0x38]\n"
        "BL      sub_FF86E5C8\n"
        "CMP     R0, #0\n"
        "STREQ   R0, [R4,#0x6C]\n"
        "MOV     R0, R6\n"
        "BL      sub_FF86D85C\n"
        "MOV     R0, R6\n"
        //"BL      sub_FF86DBE0\n"
		"BL      sub_FF86DBE0_my\n" //------------->
        "MOV     R5, R0\n"
        "MOV     R0, R6\n"
        "BL      sub_FF86DE08\n"
        "LDR     R6, [R4,#0x3C]\n"
        "AND     R7, R5, R0\n"
        "CMP     R6, #0\n"
        "LDR     R1, [R4,#0x38]\n"
        "MOVEQ   R0, #0x80000001\n"
        "MOV     R5, #0\n"
        "BEQ     loc_FF86E05C\n"
        "MOV     R0, R1\n"
        "BL      sub_FF86D420\n"
        "CMP     R0, #0\n"
        "MOVNE   R5, #4\n"
        "CMP     R6, #5\n"
        "ORRNE   R0, R5, #1\n"
        "BICEQ   R0, R5, #1\n"
        "CMP     R7, #0\n"
        "BICEQ   R0, R0, #2\n"
        "ORREQ   R0, R0, #0x80000000\n"
        "BICNE   R0, R0, #0x80000000\n"
        "ORRNE   R0, R0, #2\n"
"loc_FF86E05C:\n"
        "CMP     R8, #7\n"
        "STR     R0, [R4,#0x40]\n"
        "LDMNEFD SP!, {R4-R8,PC}\n"
        "MOV     R0, R8\n"
        "BL      sub_FF86DF7C\n"
        "CMP     R0, #0\n"
        "LDMEQFD SP!, {R4-R8,LR}\n"
        //"ADREQ   R0, 0xFF86E0A8\n"
		"LDREQ   R0, =0xFF86E0A8\n"
        "BEQ     sub_FF81175C\n"
        "LDMFD   SP!, {R4-R8,PC}\n"
 );
}; 

void __attribute__((naked,noinline)) sub_FF86DBE0_my() {

 asm volatile (
        "STMFD   SP!, {R4-R6,LR}\n"
        "MOV     R5, R0\n"
        "LDR     R0, =0x37EA0\n"
        "ADD     R4, R0, R5,LSL#7\n"
        "LDR     R0, [R4,#0x6C]\n"
        "TST     R0, #2\n"
        "MOVNE   R0, #1\n"
        "LDMNEFD SP!, {R4-R6,PC}\n"
        "LDR     R0, [R4,#0x38]\n"
        "MOV     R1, R5\n"
        //"BL      sub_FF86D8DC\n"
		"BL      sub_FF86D8DC_my\n" // ------------------>
        "CMP     R0, #0\n"
        "LDRNE   R0, [R4,#0x38]\n"
        "MOVNE   R1, R5\n"
        "BLNE    sub_FF86DA9C\n"
        "LDR     R2, =0x37F20\n"
        "ADD     R1, R5, R5,LSL#4\n"
        "LDR     R1, [R2,R1,LSL#2]\n"
        "CMP     R1, #4\n"
        "BEQ     loc_FF86DC40\n"
        "CMP     R0, #0\n"
        "LDMEQFD SP!, {R4-R6,PC}\n"
        "MOV     R0, R5\n"
        "BL      sub_FF86D4B0\n"
"loc_FF86DC40:\n"
        "CMP     R0, #0\n"
        "LDRNE   R1, [R4,#0x6C]\n"
        "ORRNE   R1, R1, #2\n"
        "STRNE   R1, [R4,#0x6C]\n"
        "LDMFD   SP!, {R4-R6,PC}\n"
 );
};


void __attribute__((naked,noinline)) sub_FF86D8DC_my() {
 asm volatile (	

"sub_FF86D8DC:\n"
        "STMFD   SP!, {R4-R10,LR}\n"
        "MOV     R9, R0\n"
        "LDR     R0, =0x37EA0\n"
        "MOV     R8, #0\n"
        "ADD     R5, R0, R1,LSL#7\n"
        "LDR     R0, [R5,#0x3C]\n"
        "MOV     R7, #0\n"
        "CMP     R0, #7\n"
        "MOV     R6, #0\n"
        "ADDLS   PC, PC, R0,LSL#2\n"
        "B       loc_FF86DA34\n"
"loc_FF86D908:\n"
        "B       loc_FF86D940\n"
"loc_FF86D90C:\n"
        "B       loc_FF86D928\n"
"loc_FF86D910:\n"
        "B       loc_FF86D928\n"
"loc_FF86D914:\n"
        "B       loc_FF86D928\n"
"loc_FF86D918:\n"
        "B       loc_FF86D928\n"
"loc_FF86D91C:\n"
        "B       loc_FF86DA2C\n"
"loc_FF86D920:\n"
        "B       loc_FF86D928\n"
"loc_FF86D924:\n"
        "B       loc_FF86D928\n"
"loc_FF86D928:\n"
        "MOV     R2, #0\n"
        "MOV     R1, #0x200\n"
        "MOV     R0, #2\n"
        "BL      sub_FF887384\n"
        "MOVS    R4, R0\n"
        "BNE     loc_FF86D948\n"
"loc_FF86D940:\n"
        "MOV     R0, #0\n"
        "LDMFD   SP!, {R4-R10,PC}\n"
"loc_FF86D948:\n"
        "LDR     R12, [R5,#0x50]\n"
        "MOV     R3, R4\n"
        "MOV     R2, #1\n"
        "MOV     R1, #0\n"
        "MOV     R0, R9\n"
        "BLX     R12\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF86D974\n"
        "MOV     R0, #2\n"
        "BL      sub_FF8874D0\n"
        "B       loc_FF86D940\n"
"loc_FF86D974:\n"
        "LDR     R1, [R5,#0x64]\n"
        "MOV     R0, R9\n"
        "BLX     R1\n"


               "MOV   R1, R4\n"           //  pointer to MBR in R1
				"BL    mbr_read_dryos\n"   //  total sectors count in R0 before and after call

                // Start of DataGhost's FAT32 autodetection code
                // Policy: If there is a partition which has type W95 FAT32, use the first one of those for image storage
                // According to the code below, we can use R1, R2, R3 and R12.
                // LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
                // that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
                "MOV     R12, R4\n"                    // Copy the MBR start address so we have something to work with
                "MOV     LR, R4\n"                     // Save old offset for MBR signature
                "MOV     R1, #1\n"                     // Note the current partition number
                "B       dg_sd_fat32_enter\n"          // We actually need to check the first partition as well, no increments yet!
           "dg_sd_fat32:\n"
                "CMP     R1, #4\n"                     // Did we already see the 4th partition?
                "BEQ     dg_sd_fat32_end\n"            // Yes, break. We didn't find anything, so don't change anything.
                "ADD     R12, R12, #0x10\n"            // Second partition
                "ADD     R1, R1, #1\n"                 // Second partition for the loop
           "dg_sd_fat32_enter:\n"
                "LDRB    R2, [R12, #0x1BE]\n"          // Partition status
                "LDRB    R3, [R12, #0x1C2]\n"          // Partition type (FAT32 = 0xB)
                "CMP     R3, #0xB\n"                   // Is this a FAT32 partition?
                "CMPNE   R3, #0xC\n"                   // Not 0xB, is it 0xC (FAT32 LBA) then?
                "BNE     dg_sd_fat32\n"                // No, it isn't.
                "CMP     R2, #0x00\n"                  // It is, check the validity of the partition type
                "CMPNE   R2, #0x80\n"
                "BNE     dg_sd_fat32\n"                // Invalid, go to next partition
                                                       // This partition is valid, it's the first one, bingo!
                "MOV     R4, R12\n"                    // Move the new MBR offset for the partition detection.
                
           "dg_sd_fat32_end:\n"
                // End of DataGhost's FAT32 autodetection code                		 

        "LDRB    R1, [R4,#0x1C9]\n"
        "LDRB    R3, [R4,#0x1C8]\n"
        "LDRB    R12, [R4,#0x1CC]\n"
        "MOV     R1, R1,LSL#24\n"
        "ORR     R1, R1, R3,LSL#16\n"
        "LDRB    R3, [R4,#0x1C7]\n"
        "LDRB    R2, [R4,#0x1BE]\n"
        //"LDRB    LR, [R4,#0x1FF]\n" // replaced, see below
        "ORR     R1, R1, R3,LSL#8\n"
        "LDRB    R3, [R4,#0x1C6]\n"
        "CMP     R2, #0\n"
        "CMPNE   R2, #0x80\n"
        "ORR     R1, R1, R3\n"
        "LDRB    R3, [R4,#0x1CD]\n"
        "MOV     R3, R3,LSL#24\n"
        "ORR     R3, R3, R12,LSL#16\n"
        "LDRB    R12, [R4,#0x1CB]\n"
        "ORR     R3, R3, R12,LSL#8\n"
        "LDRB    R12, [R4,#0x1CA]\n"
        "ORR     R3, R3, R12\n"
        //"LDRB    R12, [R4,#0x1FE]\n" // replaced, see below
        "LDRB    R12, [LR,#0x1FE]\n"        // New! First MBR signature byte (0x55)
        "LDRB    LR, [LR,#0x1FF]\n"         //      Last MBR signature byte (0xAA)	
        "BNE     loc_FF86DA00\n"
        "CMP     R0, R1\n"
        "BCC     loc_FF86DA00\n"
        "ADD     R2, R1, R3\n"
        "CMP     R2, R0\n"
        "CMPLS   R12, #0x55\n"
        "CMPEQ   LR, #0xAA\n"
        "MOVEQ   R7, R1\n"
        "MOVEQ   R6, R3\n"
        "MOVEQ   R4, #1\n"
        "BEQ     loc_FF86DA04\n"
"loc_FF86DA00:\n"
        "MOV     R4, R8\n"
"loc_FF86DA04:\n"
        "MOV     R0, #2\n"
        "BL      sub_FF8874D0\n"
        "CMP     R4, #0\n"
        "BNE     loc_FF86DA40\n"
        "LDR     R1, [R5,#0x64]\n"
        "MOV     R7, #0\n"
        "MOV     R0, R9\n"
        "BLX     R1\n"
        "MOV     R6, R0\n"
        "B       loc_FF86DA40\n"
"loc_FF86DA2C:\n"
        "MOV     R6, #0x40\n"
        "B       loc_FF86DA40\n"
"loc_FF86DA34:\n"
        "LDR     R1, =0x568\n"
        //"ADR     R0, 0xFF86DA78\n"
		"LDR     R0, =0xFF86DA78\n"
        "BL      sub_FF81E88C\n"
"loc_FF86DA40:\n"
        "STR     R7, [R5,#0x44]!\n"
        "STMIB   R5, {R6,R8}\n"
        "MOV     R0, #1\n"
        "LDMFD   SP!, {R4-R10,PC}\n"
 );
}; 

