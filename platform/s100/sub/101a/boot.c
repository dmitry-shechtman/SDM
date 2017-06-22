#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
void CreateTask_PhySw();
void CreateTask_spytask();

/*
static void __attribute__((naked,noinline)) blink(int cnt)
{
	volatile long *p=(void*)0xC022C30C;
	int i;

	for(;cnt>0;cnt--){
		*p = (*p & 0xFFFFFFCF) | 0x20; // Turn on LED

		for(i=0;i<0x200000;i++){
			asm ("nop\n");
		}
		*p = (*p & 0xFFFFFFCF);		 // Turn off LED
		for(i=0;i<0x200000;i++){
			asm ("nop\n");
		}
	}
}
*/

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();

void taskHook(context_t **context)
{ 
	task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

	// Replace firmware task addresses with ours
	if(tcb->entry == (void*)task_CaptSeq)			tcb->entry = (void*)capt_seq_task; 
	if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
	if(tcb->entry == (void*)task_MovieRecord)		tcb->entry = (void*)movie_record_task;
}

/*---------------------------------------------------------------------
  Memory Map:
	0001900     MEMBASEADDR             start of data - used for initialized vars
	0195D34     MEMISOSTART             start of our data / bss

	0400000                             raw buffers
	8000000                             end of raw buffers

	C0xxxxxx                            I/O

	FF000000    ROMBASEADDR             start of rom
	FFFFFFFF                            end of rom
----------------------------------------------------------------------*/

/*----------------------------------------------------------------------
	boot()

	Main entry point for the CHDK code
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) boot() {
asm volatile (
"    LDR     R1, =0xC0410000 \n" 
"    MOV     R0, #0 \n" 
"    STR     R0, [R1] \n" 
"    MOV     R1, #0x78 \n" 
"    MCR     p15, 0, R1, c1, c0 \n" 
"    MOV     R1, #0 \n" 
"    MCR     p15, 0, R1, c7, c10, 4 \n" 
"    MCR     p15, 0, R1, c7, c5 \n" 
"    MCR     p15, 0, R1, c7, c6 \n" 
"    MOV     R0, #0x3D \n" 
"    MCR     p15, 0, R0, c6, c0 \n" 
"    MOV     R0, #0xC000002F \n" 
"    MCR     p15, 0, R0, c6, c1 \n" 
"    MOV     R0, #0x37 \n" 
"    MCR     p15, 0, R0, c6, c2 \n" 
"    MOV     R0, #0x40000037 \n" 
"    MCR     p15, 0, R0, c6, c3 \n" 
"    MOV     R0, #0x80000017 \n" 
"    MCR     p15, 0, R0, c6, c4 \n" 
"    LDR     R0, =0xFF00002F \n" 
"    MCR     p15, 0, R0, c6, c5 \n" 
"    LDR     R0, =0xD000002B \n" 
"    MCR     p15, 0, R0, c6, c7 \n" 
"    MOV     R0, #0x34 \n" 
"    MCR     p15, 0, R0, c2, c0 \n" 
"    MOV     R0, #0x34 \n" 
"    MCR     p15, 0, R0, c2, c0, 1 \n" 
"    MOV     R0, #0x34 \n" 
"    MCR     p15, 0, R0, c3, c0 \n" 
"    LDR     R0, =0x33333330 \n" 
"    MCR     p15, 0, R0, c5, c0, 2 \n" 
"    LDR     R0, =0x33333330 \n" 
"    MCR     p15, 0, R0, c5, c0, 3 \n" 
"    MRC     p15, 0, R0, c1, c0 \n" 
"    ORR     R0, R0, #0x1000 \n" 
"    ORR     R0, R0, #4 \n" 
"    ORR     R0, R0, #1 \n" 
"    MCR     p15, 0, R0, c1, c0 \n" 
"    MOV     R1, #0x80000006 \n" 
"    MCR     p15, 0, R1, c9, c1 \n" 
"    MOV     R1, #6 \n" 
"    MCR     p15, 0, R1, c9, c1, 1 \n" 
"    MRC     p15, 0, R1, c1, c0 \n" 
"    ORR     R1, R1, #0x50000 \n" 
"    MCR     p15, 0, R1, c1, c0 \n" 
"    LDR     R2, =0xC0200000 \n" 
"    MOV     R1, #1 \n" 
"    STR     R1, [R2, #0x10C] \n" 
"    MOV     R1, #0xFF \n" 
"    STR     R1, [R2, #0xC] \n" 
"    STR     R1, [R2, #0x1C] \n" 
"    STR     R1, [R2, #0x2C] \n" 
"    STR     R1, [R2, #0x3C] \n" 
"    STR     R1, [R2, #0x4C] \n" 
"    STR     R1, [R2, #0x5C] \n" 
"    STR     R1, [R2, #0x6C] \n" 
"    STR     R1, [R2, #0x7C] \n" 
"    STR     R1, [R2, #0x8C] \n" 
"    STR     R1, [R2, #0x9C] \n" 
"    STR     R1, [R2, #0xAC] \n" 
"    STR     R1, [R2, #0xBC] \n" 
"    STR     R1, [R2, #0xCC] \n" 
"    STR     R1, [R2, #0xDC] \n" 
"    STR     R1, [R2, #0xEC] \n" 
"    STR     R1, [R2, #0xFC] \n" 
"    LDR     R1, =0xC0400008 \n" 
"    LDR     R2, =0x430005 \n" 
"    STR     R2, [R1] \n" 
"    MOV     R1, #1 \n" 
"    LDR     R2, =0xC0243100 \n" 
"    STR     R2, [R1] \n" 
"    LDR     R2, =0xC0242010 \n" 
"    LDR     R1, [R2] \n" 
"    ORR     R1, R1, #1 \n" 
"    STR     R1, [R2] \n" 
"    LDR     R0, =0xFF64BE6C \n" 
"    LDR     R1, =0x1900 \n" 
"    LDR     R3, =0x148A8 \n" 
"loc_FF000144:\n"
"    CMP     R1, R3 \n" 
"    LDRCC   R2, [R0], #4 \n" 
"    STRCC   R2, [R1], #4 \n" 
"    BCC     loc_FF000144 \n" 
"    LDR     R1, =0x195D34 \n" 
"    MOV     R2, #0 \n" 
"loc_FF00015C:\n"
"    CMP     R3, R1 \n" 
"    STRCC   R2, [R3], #4 \n" 
"    BCC     loc_FF00015C \n" 
"    B       sub_FF000364_my \n"
    );
}


void __attribute__((naked,noinline)) sub_FF000364_my() {

	//http://chdk.setepontos.com/index.php/topic,4194.0.html
	*(int*)0x1938=(int)taskHook;
	*(int*)0x193C=(int)taskHook; // need this for startup in Playback mode (otherwise init_file_modules_task doesn't hook properly)

	*(int*)(0x26E0+0x4) = (*(int*)0xC022F48C)&4 ? 0x200000 : 0x100000;

asm volatile (
"    LDR     R0, =0xFF0003DC \n" 
"    MOV     R1, #0 \n" 
"    LDR     R3, =0xFF000414 \n" 
"loc_FF000370:\n"
"    CMP     R0, R3 \n" 
"    LDRCC   R2, [R0], #4 \n" 
"    STRCC   R2, [R1], #4 \n" 
"    BCC     loc_FF000370 \n" 
"    LDR     R0, =0xFF000414 \n" 
"    MOV     R1, #0x4B0 \n" 
"    LDR     R3, =0xFF000628 \n" 
"loc_FF00038C:\n"
"    CMP     R0, R3 \n" 
"    LDRCC   R2, [R0], #4 \n" 
"    STRCC   R2, [R1], #4 \n" 
"    BCC     loc_FF00038C \n" 
"    MOV     R0, #0xD2 \n" 
"    MSR     CPSR_cxsf, R0 \n" 
"    MOV     SP, #0x1000 \n" 
"    MOV     R0, #0xD3 \n" 
"    MSR     CPSR_cxsf, R0 \n" 
"    MOV     SP, #0x1000 \n" 
"    LDR     R0, =0x6C4 \n" 
"    LDR     R2, =0xEEEEEEEE \n" 
"    MOV     R3, #0x1000 \n" 
"loc_FF0003C0:\n"
"    CMP     R0, R3 \n" 
"    STRCC   R2, [R0], #4 \n" 
"    BCC     loc_FF0003C0 \n" 
"    BL      sub_FF0011BC_my \n"  //--> 
    );
}

void __attribute__((naked,noinline)) sub_FF0011BC_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n" 
"    SUB     SP, SP, #0x74 \n" 
"    MOV     R1, #0x74 \n" 
"    MOV     R0, SP \n" 
"    BL      sub_FF44E0F0 \n" 
"    MOV     R0, #0x67000 \n" 
"    STR     R0, [SP, #4] \n" 
#if defined(OPT_CHDK_IN_EXMEM)
"    LDR     R0, =0x195D34 \n"  // use original heap offset since CHDK is loaded in high memory
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      // 
#endif
"    LDR     R2, =0x55D788 \n" 
"    STR     R0, [SP, #8] \n" 
"    SUB     R0, R2, R0 \n" 
"    STR     R0, [SP, #0xC] \n" 
"    MOV     R0, #0x22 \n" 
"    STR     R0, [SP, #0x18] \n" 
"    MOV     R0, #0x72 \n" 
"    STR     R0, [SP, #0x1C] \n" 
"    LDR     R1, =0x565C00 \n" 
"    LDR     R0, =0x1CD \n" 
"    STR     R1, [SP] \n" 
"    STR     R0, [SP, #0x20] \n" 
"    MOV     R0, #0x96 \n" 
"    STR     R2, [SP, #0x10] \n" 
"    STR     R1, [SP, #0x14] \n" 
"    STR     R0, [SP, #0x24] \n" 
"    STR     R0, [SP, #0x28] \n" 
"    MOV     R0, #0x64 \n" 
"    STR     R0, [SP, #0x2C] \n" 
"    MOV     R0, #0 \n" 
"    STR     R0, [SP, #0x30] \n" 
"    STR     R0, [SP, #0x34] \n" 
"    MOV     R0, #0x10 \n" 
"    STR     R0, [SP, #0x5C] \n" 
"    MOV     R0, #0x800 \n" 
"    STR     R0, [SP, #0x60] \n" 
"    MOV     R0, #0xA0 \n" 
"    STR     R0, [SP, #0x64] \n" 
"    MOV     R0, #0x280 \n" 
"    STR     R0, [SP, #0x68] \n" 
"    LDR     R1, =sub_FF005F38_my \n" // -->
"    MOV     R2, #0 \n" 
"    MOV     R0, SP \n" 
"    BL      sub_FF0034D0 \n" 
"    ADD     SP, SP, #0x74 \n" 
"    LDR     PC, [SP], #4 \n" 
    );
}


void __attribute__((naked,noinline)) sub_FF005F38_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n" 
"    BL      sub_FF000B34 \n" 
"    BL      sub_FF00A390 \n" 
"    CMP     R0, #0 \n" 
"    LDRLT   R0, =0xFF00604C \n" 
"    BLLT    sub_FF00602C \n" 
"    BL      sub_FF005B70 \n" 
"    CMP     R0, #0 \n" 
"    LDRLT   R0, =0xFF006054 \n" 
"    BLLT    sub_FF00602C \n" 
"    LDR     R0, =0xFF006064 \n" 
"    BL      sub_FF005C58 \n" 
"    CMP     R0, #0 \n" 
"    LDRLT   R0, =0xFF00606C \n" 
"    BLLT    sub_FF00602C \n" 
"    LDR     R0, =0xFF006064 \n" 
"    BL      sub_FF003CB4 \n" 
"    CMP     R0, #0 \n" 
"    LDRLT   R0, =0xFF006080 \n" 
"    BLLT    sub_FF00602C \n" 
"    BL      sub_FF009CF8 \n" 
"    CMP     R0, #0 \n" 
"    LDRLT   R0, =0xFF00608C \n" 
"    BLLT    sub_FF00602C \n" 
"    BL      sub_FF00169C \n" 
"    CMP     R0, #0 \n" 
"    LDRLT   R0, =0xFF006098 \n" 
"    BLLT    sub_FF00602C \n" 
"    LDMFD   SP!, {R4,LR} \n" 
//"    B       sub_FF00FDAC \n" 
"    B       taskcreate_Startup_my \n" // patched
	);
}
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n" 
"    BL      sub_FF02B598 \n" 
"    BL      sub_FF02B7B0 \n" 
"    MOV     R3, #0 \n" 
"    STR     R3, [SP] \n" 
"    LDR     R3, =sub_FF00FD84_my \n" //-->
"    MOV     R2, #0x200 \n" 
"    MOV     R1, #0x19 \n" 
"    LDR     R0, =0xFF00FEBC \n" 
"    BL      sub_FF00EAF0 \n" 
"    MOV     R0, #0 \n" 
"    LDMFD   SP!, {R3,PC} \n" 
    );
}

void __attribute__((naked,noinline)) sub_FF00FD84_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n" 
"    BL      sub_FF024AEC \n" 
"    BL      sub_FF025C00 \n" 
"    BL      sub_FF023768 \n" 
"    BL      sub_FF02D9CC \n" 
"    BL      sub_FF023EDC \n" 
"    BL      sub_FF022C24 \n" 
"    BL      sub_FF022BB0 \n" 
"    LDMFD   SP!, {R4,LR} \n" 
"    B       sub_FF00FDDC_my \n" //-->
	);
}

void __attribute__((naked,noinline)) sub_FF00FDDC_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n" 
"    MOV     R6, #0 \n" 
"    BL      sub_FF02D73C \n" 
"    MOVS    R7, R0 \n" 
"    BNE     loc_FF00FE48 \n" 
"    BL      sub_FF0264BC \n" 
"    CMP     R0, #0 \n" 
"    BEQ     loc_FF00FE48 \n" 
"    MOV     R0, #0x37 \n" 
"    BL      sub_FF02BC18 \n" 
"    RSBS    R5, R0, #1 \n" 
"    MOVCC   R5, #0 \n" 
"    MOV     R0, #0x36 \n" 
"    BL      sub_FF02BC18 \n" 
"    RSBS    R4, R0, #1 \n" 
"    MOVCC   R4, #0 \n" 
"    BL      sub_FF022BD8 \n" 
"    CMP     R0, #1 \n" 
"    MOVEQ   R6, #1 \n" 
"    ORR     R0, R4, R5 \n" 
"    ORRS    R0, R0, R6 \n" 
"    BNE     loc_FF00FE68 \n" 
"    BL      sub_FF0238F0 \n" 
"    LDR     R1, =0x83DC00 \n" 
"    MOV     R0, #0x54 \n" 
"    BL      sub_FF02BC08 \n" 
"loc_FF00FE44:\n"
"    B       loc_FF00FE44 \n" 
"loc_FF00FE48:\n"
"    MOV     R0, #0x36 \n" 
"    BL      sub_FF02BC18 \n" 
"    RSBS    R4, R0, #1 \n" 
"    MOVCC   R4, #0 \n" 
"    MOV     R0, #0x37 \n" 
"    BL      sub_FF02BC18 \n" 
"    RSBS    R5, R0, #1 \n" 
"    MOVCC   R5, #0 \n" 
"loc_FF00FE68:\n"
"    MOV     R3, R6 \n" 
"    MOV     R2, R7 \n" 
"    MOV     R1, R5 \n" 
"    MOV     R0, R4 \n" 
//"    BL      sub_FF024AF4 \n" // power button & startup, see sub_FF000364_my
"    BL      sub_FF024AF0 \n" 
"    BL      sub_FF02B598 \n" 
"    LDR     R1, =0x5CE000 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF02BA08 \n" 
"    BL      sub_FF02B7B0 \n" 
"    MOV     R3, #0 \n" 
"    STR     R3, [SP] \n" 
//"    LDR     R3, =0xFF00FD34 \n" 
"    LDR     R3, =task_Startup_my \n" // -->
"    MOV     R2, #0 \n" 
"    MOV     R1, #0x19 \n" 
"    LDR     R0, =0xFF00FED0 \n" 
"    BL      sub_FF00EAF0 \n" 
"    MOV     R0, #0 \n" 
"    LDMFD   SP!, {R3-R7,PC} \n" 
	);
}

void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n" 
"    BL      sub_FF0065E8 \n" 
//"    BL      sub_FF02D7E0 \n" // NULLSUB
//"    BL      sub_FF02D874 \n" // don't start DISKBOOT.BIN again
"    BL      sub_FF02DB88 \n" 
"    BL      sub_FF02D9FC \n" 
"    BL      sub_FF02AD3C \n" 
"    BL      sub_FF02DB8C \n" 
//"    BL      sub_FF02496C \n" // PhySw
"    BL      CreateTask_spytask \n" // added
"    BL      taskcreatePhySw_my \n"  // we do this here rather than hook so we don't waste the original stack
"    BL      sub_FF028504 \n" 
"    BL      sub_FF02DBA4 \n" 
"    BL      sub_FF0217BC \n" 
"    BL      sub_FF02250C \n" 
"    BL      sub_FF02D40C \n" 
"    BL      sub_FF022B64 \n" 
"    BL      sub_FF0224A8 \n" 
"    BL      sub_FF02E830 \n" 
"    BL      sub_FF02246C \n" 
"    LDMFD   SP!, {R4,LR} \n" 
"    B       sub_FF006708 \n" 
     );
}

void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n" 
"    LDR     R4, =0x1C3C \n" 
"    LDR     R0, [R4, #4] \n" 
"    CMP     R0, #0 \n" 
"    BNE     loc_FF0249A0 \n" 
"    MOV     R3, #0 \n" 
"    STR     R3, [SP] \n" 
//"    LDR     R3, =0xFF024938 \n" 
//"    MOV     R2, #0x800 \n" 
"    LDR     R3, =mykbd_task \n" // task_PhySw
"    MOV     R2, #0x2000 \n" // stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n" 
"    LDR     R0, =0xFF024BEC \n" 
"    BL      sub_FF02B808 \n" 
"    STR     R0, [R4, #4] \n" 
"loc_FF0249A0:\n"
"    BL      sub_FF0595A4 \n" 
"    BL      sub_FF08FBB8 \n" 
"    BL      sub_FF02640C \n" 
"    CMP     R0, #0 \n" 
"    BNE     loc_FF0249C0 \n" 
"    LDR     R1, =0x386C8 \n" 
"    MOV     R0, #0 \n" 
"    BL      sub_FF08FB28 \n" 
"loc_FF0249C0:\n"
"    LDMFD   SP!, {R3-R5,PC} \n" 
	);
}

/*----------------------------------------------------------------------
	spytask
-----------------------------------------------------------------------*/
void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    core_spytask();
}

/*----------------------------------------------------------------------
	CreateTask_spytask
-----------------------------------------------------------------------*/
void beeper(long ua, long ub, long uc, long ud, long ue, long uf)
{
 bgndBeeper();
}

void CreateTask_spytask() {
  _CreateTask("Beeper", 0x1, 0x200, beeper, 0);
//  _CreateTask("SpyTask", 0x19, 0x2000,spytask, 0);
_CreateTask("SpyTask", 0x19, 0x2000,core_spytask, 0);// for Jenda
};

/*----------------------------------------------------------------------
	init_file_modules_task
-----------------------------------------------------------------------*/
void __attribute__((naked,noinline)) init_file_modules_task() {
    asm volatile(
"    STMFD   SP!, {R4-R6,LR} \n" 
"    BL      sub_FF092164 \n" 
"    LDR     R5, =0x5006 \n" 
"    MOVS    R4, R0 \n" 
"    MOVNE   R1, #0 \n" 
"    MOVNE   R0, R5 \n" 
"    BLNE    sub_FF096768 \n" 
"    BL      sub_FF092190 \n" 
"    BL      core_spytask_can_start\n"      // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n" 
"    LDMNEFD SP!, {R4-R6,PC} \n" 
"    MOV     R0, R5 \n" 
"    LDMFD   SP!, {R4-R6,LR} \n" 
"    MOV     R1, #0 \n" 
"    B       sub_FF096768 \n" 
    );
}

