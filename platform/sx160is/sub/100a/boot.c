/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
	#if defined(OPT_EXT_TV_RANGE)
	extern void task_ExpDrv();
	#endif


void beeper(long ua, long ub, long uc, long ud, long ue, long uf)
{
 bgndBeeper();
}

void CreateTask_spytask()
{
  _CreateTask("Beeper", 0x1, 0x200, beeper, 0);
  _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}
  

//** boot @ 0xFF81000C - 0xFF81017C, length=93
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
"    MOV     R0, #0x33 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000033 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF80002D \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x3333330 \n"
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
"    LDR     R0, =0xFFCD8B18 \n"
"    LDR     R1, =0x431000 \n"
"    LDR     R3, =0x44059C \n"

"loc_FF81013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81013C \n"
"    LDR     R0, =0xFFCCAAEC \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0xF92C \n"

"loc_FF810158:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF810158 \n"
"    LDR     R1, =0x1639D4 \n"
"    MOV     R2, #0 \n"

"loc_FF810170:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF810170 \n"
/* Install task hooks via 0x193x is not possible with this new dryos version
   So the below code patches the CreateTask function in RAM to install our
   hook -- ERR99
*/
// Install CreateTask patch
"    LDR     R0, =patch_CreateTask\n"   // Patch data
"    LDM     R0, {R1,R2}\n"             // Get two patch instructions
"    LDR     R0, =hook_CreateTask\n"    // Address to patch
"    STM     R0, {R1,R2}\n"             // Store patch instructions

"    B       sub_FF810380_my \n"  // --> Patched. Old value = 0xFF810380.

"patch_CreateTask:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my\n"
);
}

/*************************************************************/
//** CreateTask_my @ 0x004368B0 - 0x004368B4, length=2
void __attribute__((naked,noinline)) CreateTask_my() {
asm volatile (
"    STMFD   SP!, {R0}\n"
//R3 = Pointer to task function to create

/*** INSTALL capt_seq_task() hook ***/
"    LDR     R0, =task_CaptSeq\n"       // DryOS original code function ptr.
"    CMP     R0, R3\n"                  // is the given taskptr equal to our searched function?
"    LDREQ   R3, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    BEQ     exitHook\n"                // below compares not necessary if this check has found something.

#if defined(OPT_EXT_TV_RANGE)
/*** INSTALL exp_drv_task() hook ***/
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =exp_drv_task\n"
"    BEQ     exitHook\n"
#endif

/*** INSTALL movie_record_task() hook ***/
"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"

/*** INSTALL init_file_modules_task() hook ***/
"    LDR     R0, =task_InitFileModules\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =init_file_modules_task\n"

"exitHook:\n" 
// restore overwritten registers
"    LDMFD   SP!, {R0}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    STMFD   SP!, {R1-R9,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     PC, =0x004368B8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF810380_my @ 0xFF810380 - 0xFF8103E8, length=27
void __attribute__((naked,noinline)) sub_FF810380_my() {

    //Replacement of sub_FF865694 for correct power-on.
    //(short press = playback mode, long press = record mode)
    if ((*(int*) 0xC0220114) & 1)       // look at power-on switch sub_ff828ec8
        *(int*)(0x2AF4+0x4) = 0x200000; // Playmode
    else
        *(int*)(0x2AF4+0x4) = 0x100000; // Shootingmode

asm volatile (
"    LDR     R0, =0xFF8103F8 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF810430 \n"

"loc_FF81038C:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81038C \n"
"    LDR     R0, =0xFF810430 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF810618 \n"

"loc_FF8103A8:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8103A8 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x698 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF8103DC:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF8103DC \n"
"    BL      sub_FF811160_my \n"  // --> Patched. Old value = 0xFF811160.
);
}

/*************************************************************/
//** sub_FF811160_my @ 0xFF811160 - 0xFF81120C, length=44
void __attribute__((naked,noinline)) sub_FF811160_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_0043C3A0 \n"
"    MOV     R0, #0x57000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(OPT_CHDK_IN_EXMEM) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x1639D4 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x32D440 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x7C \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x335C00 \n"
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
"    LDR     R1, =sub_FF814210_my \n"  // --> Patched. Old value = 0xFF814210.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_004327E8 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF814210_my @ 0xFF814210 - 0xFF814284, length=30
void __attribute__((naked,noinline)) sub_FF814210_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF810ADC \n"
"    BL      sub_FF8150FC \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814324 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF813E48 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF81432C \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF81433C \n"
"    BL      sub_FF813F30 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814344 \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF81433C \n"
"    BL      sub_FF812950 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814358 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF814A98 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814364 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF811650 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814370 \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF81A21C_my \n"  // --> Patched. Old value = 0xFF81A21C.
);
}

/*************************************************************/
//** sub_FF81A21C_my @ 0xFF81A21C - 0xFF81A298, length=32
void __attribute__((naked,noinline)) sub_FF81A21C_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF830550 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81A23C \n"
"    BL      sub_FF82AA28 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF81A240 \n"

"loc_FF81A23C:\n"
"    MOV     R0, #0 \n"

"loc_FF81A240:\n"
"    BL      sub_FF828EC8_my \n"  // --> Patched. Old value = 0xFF828EC8.
"    CMP     R0, #0 \n"
"    BNE     loc_FF81A264 \n"
"    BL      sub_FF828540 \n"
"    LDR     R1, =0xC0220000 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R1, #0x12C] \n"
"    BL      sub_FF828684 \n"

"loc_FF81A260:\n"
"    B       loc_FF81A260 \n"

"loc_FF81A264:\n"
"    BL      sub_0043786C \n"
"    LDR     R1, =0x38E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF82EB8C \n"
"    BL      sub_00437A84 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF81A1B4.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF81A2A8 \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF828EC8_my @ 0xFF828EC8 - 0xFF828F20, length=23
void __attribute__((naked,noinline)) sub_FF828EC8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R6, R0 \n"
//"  BL      _sub_FF86568C \n"  // --> Nullsub call removed.
"    LDR     R0, =0xC0220114 \n"
"    BL      sub_FF865ED8 \n"
"    MOV     R4, #1 \n"
"    BIC     R5, R4, R0 \n"
"    LDR     R0, =0xC022010C \n"
"    BL      sub_FF865ED8 \n"
"    CMP     R6, #0 \n"
"    BIC     R4, R4, R0 \n"
"    BEQ     loc_FF828F00 \n"
"    ORRS    R0, R5, R4 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF828F00:\n"
"    BL      sub_FF830550 \n"
"    MOV     R2, R0 \n"
"    MOV     R3, #0 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
//"  BL      _sub_FF865694 \n"  // Disable StartUpChecks
//"  BL      _sub_FF865690 \n"  // --> Nullsub call removed.
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF81A1B4 - 0xFF81A218, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF814850 \n"
"    BL      sub_FF82A04C \n"
"    BL      sub_FF8281EC \n"
//"  BL      _sub_FF865EEC \n"  // --> Nullsub call removed.
"    BL      sub_FF830784 \n"
//"  BL      _sub_FF83062C \n"  // load DISKBOOT.BIN
"    BL      sub_FF83090C \n"
"    BL      sub_FF830AD8 \n"
"    BL      sub_FF8308D0 \n"
"    BL      sub_FF8307B4 \n"
"    BL      sub_FF82EAC0 \n"
"    BL      sub_FF830AE0 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF828D68.
"    BL      sub_FF82C830 \n"
"    BL      sub_FF8A774C \n"
"    BL      sub_FF826214 \n"
"    BL      sub_FF827C0C \n"
"    BL      sub_FF83030C \n"
"    BL      sub_FF8281A0 \n"
"    BL      sub_FF827BAC \n"
"    BL      sub_FF853E74 \n"
"    BL      sub_FF826EA4 \n"
"    BL      sub_FF827B70 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF814970 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF828D68 - 0xFF828DBC, length=22
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1D30 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF828D9C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF828D34.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF829018 \n"
"    BL      sub_00437ADC /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF828D9C:\n"
"    BL      sub_FF866348 \n"
"    BL      sub_FF8934C8 \n"
"    BL      sub_FF82A978 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF828DBC \n"
"    LDR     R1, =0x33964 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF893434 /*_OpLog.Start_FW*/ \n"

"loc_FF828DBC:\n"
"    LDMFD   SP!, {R3-R5,PC} \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF856B18 - 0xFF856B4C, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF895A08 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF895A34 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0 \n"
"    B       _PostLogicalEventToUI \n"
);
}


