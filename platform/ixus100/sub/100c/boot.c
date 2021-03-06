#include "lolevel.h"
#include "platform.h"
#include "core.h"

const char * const new_sa = &_end;

/* Our stuff */
extern long wrs_kernel_bss_start;
extern long wrs_kernel_bss_end;

// Forward declarations
void CreateTask_spytask();
void boot();

void taskCreateHook(int *p) 
{
 p-=17;
 if (p[0]==0xFF91A6AC) p[0]=(int)movie_record_task;
 if (p[0]==0xFF877DD0) p[0]=(int)init_file_modules_task;
}

// ??? from sx10
void taskCreateHook2(int *p) {
 p-=17;
 //VERIFY_SD780 - Does this need to be here at all anymore?
//Uncomment if (p[0]==0xFF881534)  p[0]=(int)init_file_modules_task;
if (p[0]==0xFF877DD0) p[0]=(int)init_file_modules_task;
}

void boot() { //#fs
    long *canon_data_src = (void*)0xFFB513B0;  	//From end of first function
    long *canon_data_dst = (void*)0x1900;		//From end of first function
    long canon_data_len = 0xCDAC - 0x1900; 		// data_end - data_start
    long *canon_bss_start = (void*)0xCDAC; 		// just after data
    long canon_bss_len = 0x146B8C - 0xCDAC;		//In loop at end of first function

    long i;


    // enable caches and write buffer... this is a carryover from old dryos ports, may not be useful
    // SD780 still has this in first function VERIFY_SD780
    asm volatile (
	"MRC     p15, 0, R0,c1,c0\n"
	"ORR     R0, R0, #0x1000\n"
	"ORR     R0, R0, #4\n"
	"ORR     R0, R0, #1\n"
	"MCR     p15, 0, R0,c1,c0\n"
    :::"r0");

    for(i=0;i<canon_data_len/4;i++)
	canon_data_dst[i]=canon_data_src[i];

    for(i=0;i<canon_bss_len/4;i++)
	canon_bss_start[i]=0;

// see http://chdk.setepontos.com/index.php/topic,2972.msg30712.html#msg30712

    *(int*)0x1934=(int)taskCreateHook;
    *(int*)0x1938=(int)taskCreateHook2; //VERIFY_SD780

	// Search on 0x12345678 finds function that is called from function with this code (SD780 0xFF842A90)
    *(int*)(0x227C)= (*(int*)0xC02200C0)&1 ? 0x400000 : 0x200000; //VERIFY_SD780 replacement of sub_FF842A90/sub_FF821B7C for correct power-on.

    // jump to init-sequence that follows the data-copy-routine
    asm volatile ("B      sub_FF8101A0_my\n");
}

//SD780 - ASM matches but comments are unknown if correct....
void __attribute__((naked,noinline)) sub_FF8101A0_my() {
        asm volatile (
"                LDR     R0, =0xFF810218\n" // exception handler code
"                MOV     R1, #0\n"
"                LDR     R3, =0xFF810250\n"
"loc_FF8101AC:\n"
"                CMP     R0, R3\n"          // load exception vector
"                LDRCC   R2, [R0],#4\n"
"                STRCC   R2, [R1],#4\n"
"                BCC     loc_FF8101AC\n"
"                LDR     R0, =0xFF810250\n"
"                MOV     R1, #0x4B0\n"
"                LDR     R3, =0xFF810464\n"
"loc_FF8101C8:\n"
"                CMP     R0, R3\n"          // copy IRQ handler to ITCM starting at 0x4b0, 532 bytes up to 0x6C4
"                LDRCC   R2, [R0],#4\n"
"                STRCC   R2, [R1],#4\n"
"                BCC     loc_FF8101C8\n"
"                MOV     R0, #0xD2\n"
"                MSR     CPSR_cxsf, R0\n"   // set CPSR mode = IRQ, ints disabled
"                MOV     SP, #0x1000\n"     // irq mode SP
"                MOV     R0, #0xD3\n"
"                MSR     CPSR_cxsf, R0\n"   // set CPSR mode = Super, ints disabled
"                MOV     SP, #0x1000\n"     // super mode SP
"                LDR     R0, =0x6C4\n"
"                LDR     R2, =0xEEEEEEEE\n"
"                MOV     R3, #0x1000\n"
"loc_FF8101FC:\n"
"                CMP     R0, R3\n"          // clear ITCM 0x6C4-end with EEEEEEEE
"                STRCC   R2, [R0],#4\n"
"                BCC     loc_FF8101FC\n"
"                BL      sub_FF810FC4_my\n" //->my
        );
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF810FC4_my() {
	asm volatile (
"                 STR     LR, [SP,#-4]!\n"
"                 SUB     SP, SP, #0x74\n"
"                 MOV     R0, SP\n"
"                 MOV     R1, #0x74\n"
"                 BL      sub_FFAC7EFC\n"
"                 MOV     R0, #0x53000\n"
"                 STR     R0, [SP,#4]\n"

"                 LDR     R0, =new_sa\n"	//Replaces original start location 0x146B8C
"                 LDR     R0, [R0]\n"		//

"                 LDR     R2, =0x2F9C00\n"
"                 LDR     R1, =0x2F24A8\n"
"                 STR     R0, [SP,#8]\n"
"                 SUB     R0, R1, R0\n"
"                 ADD     R3, SP, #0xC\n"
"                 STR     R2, [SP]\n"
"                 STMIA   R3, {R0-R2}\n"
"                 MOV     R0, #0x22\n"
"                 STR     R0, [SP,#0x18]\n"
"                 MOV     R0, #0x68\n"
"                 STR     R0, [SP,#0x1C]\n"
"                 LDR     R0, =0x19B\n"
"                 LDR     R1, =sub_FF814D38_my\n"
"                 STR     R0, [SP,#0x20]\n"
"                 MOV     R0, #0x96\n"
"                 STR     R0, [SP,#0x24]\n"
"                 MOV     R0, #0x78\n"
"                 STR     R0, [SP,#0x28]\n"
"                 MOV     R0, #0x64\n"
"                 STR     R0, [SP,#0x2C]\n"
"                 MOV     R0, #0\n"
"                 STR     R0, [SP,#0x30]\n"
"                 STR     R0, [SP,#0x34]\n"
"                 MOV     R0, #0x10\n"
"                 STR     R0, [SP,#0x5C]\n"
"                 MOV     R0, #0x800\n"
"                 STR     R0, [SP,#0x60]\n"
"                 MOV     R0, #0xA0\n"
"                 STR     R0, [SP,#0x64]\n"
"                 MOV     R0, #0x280\n"
"                 STR     R0, [SP,#0x68]\n"
"                 MOV     R0, SP\n"
"                 MOV     R2, #0\n"
"                 BL      sub_FF812D68\n"
"                 ADD     SP, SP, #0x74\n"
"                 LDR     PC, [SP],#4\n"
	);
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF814D38_my() {
	asm volatile (
"                 STMFD   SP!, {R4,LR}\n"
"                 BL      sub_FF810954\n"
"                 BL      sub_FF8190B4\n" // dmSetup
"                 CMP     R0, #0\n"
"                 LDRLT   R0, =0xFF814E4C\n" // "dmSetup"
"                 BLLT    sub_FF814E2C\n" // err_init_task
"                 BL      sub_FF814974\n"
"                 CMP     R0, #0\n"
"                 LDRLT   R0, =0xFF814E54\n" // "termDriverInit"
"                 BLLT    sub_FF814E2C\n" // err_init_task
"                 LDR     R0, =0xFF814E64\n" // "/_term"
"                 BL      sub_FF814A5C\n" // termDeviceCreate
"                 CMP     R0, #0\n"
"                 LDRLT   R0, =0xFF814E6C\n" // "termDeviceCreate"
"                 BLLT    sub_FF814E2C\n" // err_init_task
"                 LDR     R0, =0xFF814E64\n" // "/_term"
"                 BL      sub_FF813578\n" // stdioSetup  //VERIFY_SD780 testing
"                 CMP     R0, #0\n"
"                 LDRLT   R0, =0xFF814E80\n" // "stdioSetup"
"                 BLLT    sub_FF814E2C\n" // err_init_task
"                 BL      sub_FF818BCC\n" // stdlibSetup
"                 CMP     R0, #0\n"
"                 LDRLT   R0, =0xFF814E8C\n" // "stdlibSetup"
"                 BLLT    sub_FF814E2C\n" // err_init_task
"                 BL      sub_FF8114A8\n"
"                 CMP     R0, #0\n"
"                 LDRLT   R0, =0xFF814E98\n" // "armlib_setup"
"                 BLLT    sub_FF814E2C\n" // err_init_task
"                 LDMFD   SP!, {R4,LR}\n"
"                 B       taskcreate_Startup_my\n"
	);
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) taskcreate_Startup_my() {  //0xFF81C260
	asm volatile (
"                STMFD   SP!, {R3,LR}\n"
"                BL      sub_FF821B74\n" //nullsub
"                BL      sub_FF828C8C\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF81C298\n"
"                BL      sub_FF821B70\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF81C298\n"
"                BL      sub_FF82123C\n"
"                LDR     R1, =0xC0220000\n"
"                MOV     R0, #0x44\n"
"                STR     R0, [R1,#0x1C]\n"
"                BL      sub_FF821428\n"
"loc_FF81C294:\n"
"                B       loc_FF81C294\n"
"loc_FF81C298:\n"
//"                BL      sub_FF821B7C\n" // VERIFY_SD780 is this true? - removed for correct power-on on 'on/off' button.  Hmm seems fine...
"                BL      sub_FF821B78\n"   //nullsub
"                BL      sub_FF826F44\n"
"                LDR     R1, =0x34E000\n"
"                MOV     R0, #0\n"
"                BL      sub_FF82738C\n"
"                BL      sub_FF827138\n" // LOCATION: KerSys.c:548
"                MOV     R3, #0\n"
"                STR     R3, [SP]\n"
"                LDR     R3, =task_Startup_my\n" // ->
"                MOV     R2, #0\n"
"                MOV     R1, #0x19\n"
"                LDR     R0, =0xFF81C2E0\n"  // "Startup"
"                BL      sub_FF81AFAC\n" // eventproc_export_CreateTask ; LOCATION: KerTask.c:163\n"
"                MOV     R0, #0\n"
"                LDMFD   SP!, {R12,PC}\n"
	);
}


//SD780 - ASM matches - Original location 0xFF81C1FC
void __attribute__((naked,noinline)) task_Startup_my() {
	asm volatile (
"                 STMFD   SP!, {R4,LR}\n"
"                 BL      sub_FF815394\n" // taskcreate_ClockSave
"                 BL      sub_FF822C58\n"
"                 BL      sub_FF820F04\n"
"                 BL      sub_FF828CCC\n" // j_nullsub
"                 BL      sub_FF828EB0\n"
//"                 BL      sub_FF828D60\n"  //diskboot loop - VERIFY_SD780
        );

       CreateTask_spytask();

        asm volatile (
"                 BL      sub_FF829054\n"
"                 BL      sub_FF81FB90\n"
"                 BL      sub_FF828EE0\n"
"                 BL      sub_FF826544\n"
"                 BL      sub_FF829058\n"
"                 BL      sub_FF821A70_my\n" // taskcreate_PhySw
"                 BL      sub_FF824A98_my\n" // taskcreate_SsTask -> for shoot seq stuff
"                 BL      sub_FF829070\n"
"                 BL      sub_FF81EFB0\n" // nullsub
"                 BL      sub_FF820808\n"
"                 BL      sub_FF828A68\n" // taskcreate_Bye
"                 BL      sub_FF820EB4\n"
"                 BL      sub_FF820714\n" // taskcreate_TempCheck
"                 BL      sub_FF81FBC4\n"
"                 BL      sub_FF829AEC\n"
"                 BL      sub_FF8206EC\n"
"                 LDMFD   SP!, {R4,LR}\n"
"                 B       sub_FF8154B4\n" // _sub_FF8154B4__MLHClock_c__0 ; LOCATION: MLHClock.c:0
	);
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF824A98_my() {
asm volatile (
"                 STMFD   SP!, {R4,LR}\n"
"                 MOV     R0, #0\n"
"                 MOV     R1, #0\n"
"                 BL      sub_FF8271E4\n" // KernelMisc.c:43
"                 LDR     R4, =0x1C48\n"
"                 STR     R0, [R4,#4]\n"
"                 BL      sub_FF862108\n"
"                 BL      sub_FF863818\n" // -> taskcreate_SsTask
"                 BL      sub_FF861238\n"
"                 BL      sub_FF85C228_my\n"
"                 BL      sub_FF8623EC\n"
"                 LDR     R0, [R4,#4]\n"
"                 LDMFD   SP!, {R4,LR}\n"
"                 MOV     R1, #0x1000\n"
"                 B       sub_FF866178\n"
	);
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF85C228_my() {
	asm volatile (
"                STMFD   SP!, {R4,LR}\n"
"                LDR     R4, =0x28E4\n"
"                LDR     R0, [R4,#0xC]\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF85C294\n"
"                BL      sub_FF85FA38\n" // nullsub
"                MOV     R1, #1\n"
"                MOV     R0, #0\n"
"                BL      sub_FF827208\n" // KernelMisc.c:55
"                STR     R0, [R4,#4]\n"
"                MOV     R0, #0\n"
"                MOV     R1, #8\n"
"                BL      sub_FF8271E4\n" // KernelMisc.c:43
"                STR     R0, [R4,#0x8]\n"
"                BL      sub_FF85C590\n"
"                BL      sub_FF85CD18\n"
"                MOV     R0, #0\n"
"                STR     R0, [R4]\n"
"                ADD     R0, R4, #0x10\n"
"                MOV     R1, #0\n"
"                STR     R1, [R0],#4\n"
"                STR     R1, [R0]\n"
"                BL      sub_FF85CF20\n"
"                BL      sub_FF8625F4\n"
"                BL      sub_FF85FD7C\n"
"                BL      sub_FF85DA4C_my\n" // ->taskcreate_CaptSeqTask
"                BL      sub_FF85EA10\n"

"loc_FF85C294:\n"
"                MOV     R0, #1\n"
"                STR     R0, [R4,#0xC]\n"
"                LDMFD   SP!, {R4,PC}\n"
	);
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF85DA4C_my() {
	asm volatile (
"                STMFD   SP!, {R3-R5,LR}\n"
"                LDR     R2, =0x1446C\n"
"                MOV     R0, #0\n"
"                MOV     R1, #0\n"

"loc_FF85DA5C:\n"
"                ADD     R3, R2, R0,LSL#4\n"
"                ADD     R0, R0, #1\n"
"                CMP     R0, #5\n"
"                STR     R1, [R3,#8]\n"
"                BCC     loc_FF85DA5C\n"
"                BL      sub_FF85E55C\n"
"                BL      sub_FF9202C4\n"
"                MOV     R1, #5\n"
"                MOV     R0, #0\n"
"                BL      sub_FF8271C0\n" // KernelMisc.c:31
"                LDR     R4, =0x291C\n"
"                LDR     R1, =0x101DFF\n"
"                STR     R0, [R4,#0x4]\n"
"                MOV     R0, #0\n"
"                BL      sub_FF8271E4\n" // KernelMisc.c:43
"                STR     R0, [R4]\n"
"                MOV     R0, #0\n"
"                MOV     R1, #1\n"
"                BL      sub_FF827208\n" // KernelMisc.c:55
"                STR     R0, [R4,#0x8]\n"
"                MOV     R3, #0\n"
"                STR     R3, [SP]\n"
"                LDR     R3, =task_CaptSeqTask_my\n"
"                LDR     R0, =0xFF85DC98\n" // "CaptSeqTask"
"                MOV     R2, #0x1000\n"
"                MOV     R1, #0x17\n"
"                BL      sub_FF82718C\n"// KernelCreateTask ; LOCATION: KernelMisc.c:19
"                LDMFD   SP!, {R3-R5,PC}\n"
	);
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF821A70_my() {
	asm volatile (
"                STMFD   SP!, {R3-R5,LR}\n"
"                LDR     R4, =0x1C28\n"
"                LDR     R0, [R4,#0x10]\n"
"                CMP     R0, #0\n"
"                BNE     loc_FF821AA4\n"
"                MOV     R3, #0\n"
"                STR     R3, [SP]\n"
"                LDR     R3, =mykbd_task\n" // task_PhySw
"                MOV     R2, #0x2000\n" 	// Increate stack size from 0x800 to 0x2000 for new task_PhySw so we don't have to do stack switch
"                MOV     R1, #0x17\n"
"                LDR     R0, =0xFF821C78\n" // "PhySw"
"                BL      sub_FF82718C\n" // KernelCreateTask
"                STR     R0, [R4,#0x10]\n"

"loc_FF821AA4:\n"
"                BL      sub_FF86C714\n"
"                BL      sub_FF846654\n" // IsFactoryMode
"                CMP     R0, #0\n"
"                LDREQ   R1, =0xE244\n"
"                LDMEQFD SP!, {R3-R5,LR}\n"
"                BEQ     sub_FF86C69C\n" // eventproc_export_OpLog_Start
"                LDMFD   SP!, {R3-R5,PC}\n"
	);
}

void beeper(long ua, long ub, long uc, long ud, long ue, long uf)
{
 bgndBeeper();
}

//VERIFY_SD780 - What does this do for us?
void CreateTask_spytask() {
_CreateTask("Beeper", 0x1, 0x200, beeper, 0);
        _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}


//SD780 - ASM Matches - Original location 0xFF877DD0
void __attribute__((naked,noinline)) init_file_modules_task() {
  asm volatile (
"                 STMFD   SP!, {R4-R6,LR}\n"
"                 BL      sub_FF86EB24\n"
"                 LDR     R5, =0x5006\n"
"                 MOVS    R4, R0\n"
"                 MOVNE   R1, #0\n"
"                 MOVNE   R0, R5\n"
"                 BLNE    sub_FF873978\n"			// PostLogicalEventToUI
"                 BL      sub_FF86EB50_my\n" // ->
"                 BL      core_spytask_can_start\n" // + safe to start spytask
"                 CMP     R4, #0\n"
"                 MOVEQ   R0, R5\n"
"                 LDMEQFD SP!, {R4-R6,LR}\n"
"                 MOVEQ   R1, #0\n"
"                 BEQ     sub_FF873978\n" // PostLogicalEventToUI
"                 LDMFD   SP!, {R4-R6,PC}\n"
	);
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF86EB50_my() {
  asm volatile (
"                 STMFD   SP!, {R4,LR}\n"
"                 MOV	  R0, #3\n"
"                 BL      sub_FF852020_my\n" // ->  //Mounter.c
//"                 BL      nullsub_95\n"
"                 LDR     R4, =0x2C94\n"
"                 LDR     R0, [R4,#4]\n"
"                 CMP     R0, #0\n"
"                 BNE     loc_FF86EB88\n"
"                 BL      sub_FF8513E4\n"
"                 BL      sub_FF8ED998\n"
"                 BL      sub_FF8513E4\n"
"                 BL      sub_FF84D438\n"
"                 BL      sub_FF8512E4\n"
"                 BL      sub_FF8EDA64\n"
"loc_FF86EB88:\n"
"                 MOV     R0, #1\n"
"                 STR     R0, [R4]\n"
"                 LDMFD   SP!, {R4,PC}\n"
 );
}

//SD780 - ASM matches
void __attribute__((naked,noinline)) sub_FF852020_my() {
  asm volatile (

"                 STMFD   SP!, {R4-R8,LR}\n"
"                 MOV     R6, R0\n"
"                 BL      sub_FF851F88\n"
"                 LDR     R1, =0x10938\n"
"                 MOV     R5, R0\n"
"                 ADD     R4, R1, R0, LSL#7\n"
"                 LDR     R0, [R4,#0x70]\n"
"                 CMP     R0, #4\n"
"                 LDREQ   R1, =0x6D8\n"
"                 LDREQ   R0, =0xFF851AAC\n"
"                 BLEQ    sub_FF81B284\n"
"                 MOV     R1, R6\n"
"                 MOV     R0, R5\n"
"                 BL      sub_FF8519F4\n" // LOCATION: Mounter.c:824// Original
"                 LDR     R0, [R4,#0x38]\n"
"                 BL      sub_FF85254C\n"
"				  CMP	  R0, #0\n"
"				  STREQ	  R0, [R4,#0x70]\n"
"				  MOV	  R0, R5\n"
"				  BL	  sub_FF851ACC\n"
"				  MOV	  R0, R5\n"
"				  BL	  sub_FF851DC0_my\n"
"                 MOV     R7, R0\n"
"                 MOV     R0, R5\n"
"                 BL      sub_FF851E24\n" // LOCATION: Mounter.c:8// Original
"                 LDR     R1, [R4,#0x3C]\n"
"                 AND     R2, R7, R0\n"
"                 CMP     R1, #0\n"
"                 MOV     R0, #0\n"
"                 MOVEQ   R0, #0x80000001\n"
"                 BEQ     loc_FF8520C8\n"
"                 LDR     R3, [R4,#0x2C]\n"
"                 CMP     R3, #2\n"
"                 MOVEQ   R0, #4\n"
"                 CMP     R1, #5\n"
"                 ORRNE   R0, R0, #1\n"
"                 BICEQ   R0, R0, #1\n"
"                 CMP     R2, #0\n"
"                 BICEQ   R0, R0, #2\n"
"                 ORREQ   R0, R0, #0x80000000\n"
"                 BICNE   R0, R0, #0x80000000\n"
"                 ORRNE   R0, R0, #2\n"
"loc_FF8520C8:\n"
"				  CMP	  R6, #7\n"
"                 STR     R0, [R4,#0x40]\n"
"				  LDMNEFD SP!, {R4-R8,PC}\n"
"				  MOV	  R0, R6\n"
"				  BL	  sub_FF851FD8\n"
"				  CMP	  R0, #0\n"
"				  LDMEQFD SP!, {R4-R8,LR}\n"
"				  LDREQ   R0,=0xFF8522C4\n"
"				  BEQ 	  sub_FF8115A8\n"
"                 LDMFD   SP!, {R4-R6,PC}\n"
 );
}

//SD780 - ASM matches - Note support of FAT32 is OFF
void __attribute__((naked,noinline)) sub_FF851DC0_my() {
  asm volatile (
"                 STMFD   SP!, {R4-R6,LR}\n"
"                 MOV     R5, R0\n"
"                 LDR     R0, =0x10938\n"
"				  ADD 	  R4, R0, R5,LSL#7\n"
"                 LDR     R0, [R4,#0x70]\n"
"                 TST     R0, #2\n"
"                 MOVNE   R0, #1\n"
"                 LDMNEFD SP!, {R4-R6,PC}\n"
"				  LDR 	  R0, [R4,#0x38]\n"
"                 MOV     R1, R5\n"
"                 BL      sub_FF851B50_my\n"  // -> FAT32 Support  //VERIFY_SD780
//                BL      sub_FF851B50\n" 		// -> is Mounter.c
"                 CMP     R0, #0\n"
"                 LDMEQFD SP!, {R4-R6,PC}\n"
"                 LDR     R0, [R4,#0x38]\n"
"                 MOV     R1, R5\n"
"                 BL      sub_FF851CBC\n" // LOCATION: Mounter.c:0
"                 CMP     R0, #0\n"
"                 LDMEQFD SP!, {R4-R6,PC}\n"
"                 MOV     R0, R5\n"
"                 BL      sub_FF8515DC\n"
"                 CMP     R0, #0\n"
"				  LDRNE	  R1, [R4,#0x70]\n"
"				  ORRNE	  R1, R1, #2\n"
"                 STRNE   R1, [R4,#0x70]\n"
"                 LDMFD   SP!, {R4-R6,PC}\n"
  );
}


//VERIFY_SD780 - FAT32 is OFF
void __attribute__((naked,noinline)) sub_FF851B50_my() {  //Need to fix
  asm volatile (
"                 STMFD   SP!, {R4-R8,LR}\n"
"                 MOV     R8, R0\n"
//"                 MOV     R0, #0x17\n"
//"                 MUL     R1, R0, R1\n"
"                 LDR     R0, =0x10938\n"
"                 MOV     R7, #0\n"
"                 ADD     R5, R0, R1,LSL#7\n"
"                 LDR     R0, [R5,#0x3C]\n"
"                 MOV     R6, #0\n"
"                 CMP     R0, #7\n"
"                 ADDLS   PC, PC, R0,LSL#2\n"

"                 B       loc_FF851CA0\n"
"                 B       loc_FF851BB0\n"
"                 B       loc_FF851B98\n"
"                 B       loc_FF851B98\n"
"                 B       loc_FF851B98\n"
"                 B       loc_FF851B98\n"
"                 B       loc_FF851C98\n"
"                 B       loc_FF851B98\n"
"                 B       loc_FF851B98\n"
"loc_FF851B98:\n"
// jumptable FF851B70 entries 1-4,6,7
"                 MOV     R2, #0\n"
"                 MOV     R1, #0x200\n"
"                 MOV     R0, #2\n"
"                 BL      sub_FF868C1C\n"
"                 MOVS    R4, R0\n"
"                 BNE     loc_FF851BB8\n"
"loc_FF851BB0:\n"
// jumptable FF851B70 entry 0
"                 MOV     R0, #0\n"
"                 LDMFD   SP!, {R4-R8,PC}\n"
"loc_FF851BB8:\n"
"                 LDR     R12, [R5,#0x4C]\n"
"                 MOV     R3, R4\n"
"                 MOV     R2, #1\n"
"                 MOV     R1, #0\n"
"                 MOV     R0, R8\n"
//"               BLX 	  R12\n"			//-
"                 MOV 	  LR, PC\n"			//+
"                 MOV 	  PC, R12\n"		//+
"                 CMP     R0, #1\n"
"                 BNE     loc_FF851BE4\n"
"                 MOV     R0, #2\n"
"                 BL      sub_FF868D68\n" // LOCATION: ExMemMan.c:0
"                 B       loc_FF851BB0\n"
"loc_FF851BE4:\n"
"                 LDR     R1, [R5,#0x68]\n"
"                 MOV     R0, R8\n"
//"               BLX     R1\n"  //FF851BEC //-
"                 MOV     LR, PC\n" //+
"                 MOV     PC, R1\n" //+


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
        "BNE     dg_sd_fat32\n"                // No, it isn't. Loop again.
        "CMP     R2, #0x00\n"                  // It is, check the validity of the partition type
        "CMPNE   R2, #0x80\n"
        "BNE     dg_sd_fat32\n"                // Invalid, go to next partition
                                               // This partition is valid, it's the first one, bingo!
        "MOV     R4, R12\n"                    // Move the new MBR offset for the partition detection.

   "dg_sd_fat32_end:\n"
        // End of DataGhost's FAT32 autodetection code
		  //FF851BF0
"                 LDRB    R1, [R4,#0x1C9]\n"
"                 LDRB    R3, [R4,#0x1C8]\n"
"                 LDRB    R12, [R4,#0x1CC]\n"
"                 MOV     R1, R1,LSL#24\n"
"                 ORR     R1, R1, R3,LSL#16\n"
"                 LDRB    R3, [R4,#0x1C7]\n"
"                 LDRB    R2, [R4,#0x1BE]\n"
//"                 LDRB    LR, [R4,#0x1FF]\n" // -
"                 ORR     R1, R1, R3,LSL#8\n"
"                 LDRB    R3, [R4,#0x1C6]\n"
"                 CMP     R2, #0\n"
"                 CMPNE   R2, #0x80\n"
"                 ORR     R1, R1, R3\n"
"                 LDRB    R3, [R4,#0x1CD]\n"
"                 MOV     R3, R3,LSL#24\n"
"                 ORR     R3, R3, R12,LSL#16\n"
"                 LDRB    R12, [R4,#0x1CB]\n"
"                 ORR     R3, R3, R12,LSL#8\n"
"                 LDRB    R12, [R4,#0x1CA]\n"
"                 ORR     R3, R3, R12\n"

		  //fix below
//"                 LDRB    R12, [R4,#0x1FE]\n" // -
"                 LDRB    R12, [LR,#0x1FE]\n" // +
"                 LDRB    LR, [LR,#0x1FF]\n" // +
//At ff851c44
		  "                 MOV     R4, #0\n"
"                 BNE     loc_FF851C70\n"
"                 CMP     R0, R1\n"
"                 BCC     loc_FF851C70\n"
"                 ADD     R2, R1, R3\n"
"                 CMP     R2, R0\n"
"                 CMPLS   R12, #0x55\n"
"                 CMPEQ   LR, #0xAA\n"
"                 MOVEQ   R7, R1\n"
"                 MOVEQ   R6, R3\n"
"                 MOVEQ   R4, #1\n"
"loc_FF851C70:\n"
"                 MOV     R0, #2\n"
"                 BL      sub_FF868D68\n" // LOCATION: ExMemMan.c:0
"                 CMP     R4, #0\n"
"                 BNE     loc_FF851CAC\n"
"     		LDR R1, [R5,#0x68]\n"
"                 MOV     R7, #0\n"
"                 MOV     R0, R8\n"
//"               BL      sub_FF9214E8\n"
//"		      BLX     R1"
"                 MOV     LR, PC\n" //+
"                 MOV     PC, R1\n" //+
"                 MOV     R6, R0\n"
"                 B       loc_FF851CAC\n"
"loc_FF851C98:\n"
// jumptable FF851B70 entry 5
"                 MOV     R6, #0x40\n"
"                 B       loc_FF851CAC\n"
"loc_FF851CA0:\n"
// jumptable FF851B70 default entry
"                 LDR     R1, =0x5C9\n"
"                 LDR     R0, =0xFF851AAC\n" // "Mounter.c"
"                 BL      sub_FF81B284\n" // DebugAssert
" loc_FF851CAC:\n"
"                 STR     R7, [R5,#0x44]!\n"
"                 MOV     R0, #1\n"
"                 STR     R6, [R5,#4]\n"
"                 LDMFD   SP!, {R4-R8,PC}\n"
  );
}

