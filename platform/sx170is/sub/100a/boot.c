/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;
 
void beeper(long ua, long ub, long uc, long ud, long ue, long uf)
{
 bgndBeeper();
}

void CreateTask_spytask()
{
  _CreateTask("Beeper", 0x1, 0x200, beeper, 0);
  _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
short *jog_position;

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
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
"    LDR     R0, =0xFFCD5E6C \n"
"    LDR     R1, =0x3F1000 \n"
"    LDR     R3, =0x400670 \n"

"loc_FF81013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81013C \n"
"    LDR     R0, =0xFFCC68D4 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x10E98 \n"

"loc_FF810158:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF810158 \n"
"    LDR     R1, =0x16FB10 \n"
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

"    B       sub_FF8103C4_my \n"  // --> Patched. Old value = 0xFF8103C4.

"patch_CreateTask:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my\n"
);
}

/*************************************************************/
//** CreateTask_my @ 0x003F5778 - 0x003F577C, length=2
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
// "    LDR     R0, =task_MovieRecord\n"
// "    CMP     R0, R3\n"
// "    LDREQ   R3, =movie_record_task\n"
// "    BEQ     exitHook\n"

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
"    LDR     PC, =0x003F5780 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8103C4_my @ 0xFF8103C4 - 0xFF81042C, length=27
void __attribute__((naked,noinline)) sub_FF8103C4_my() {

    //Replacement of sub_ for correct power-on.
    //(short press = playback mode, long press = record mode)

    // look at power-on switch sub_FF81BB18
    // value and pointer from sub_FF858620
    *(int*)(0x2b20+0x4) = (*(int*)0xC0220114)&1 ? 0x200000 : 0x100000;

asm volatile (
"    LDR     R0, =0xFF81043C \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF810474 \n"

"loc_FF8103D0:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8103D0 \n"
"    LDR     R0, =0xFF810474 \n"
"    MOV     R1, #0x1B0 \n"
"    LDR     R3, =0xFF81065C \n"

"loc_FF8103EC:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8103EC \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x398 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF810420:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF810420 \n"
"    B       sub_FF8128DC_my \n"  // --> Patched. Old value = 0xFF8128DC.
);
}

/*************************************************************/
//** sub_FF8128DC_my @ 0xFF8128DC - 0xFF812A54, length=95
void __attribute__((naked,noinline)) sub_FF8128DC_my() {
asm volatile (
"    LDR     R0, =0x1A54 \n"
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x80000 \n"
"    STR     R1, [R0] \n"
"    LDR     R0, =0x4090E980 \n"
"    LDR     R1, =0x1A58 \n"
"    STR     R0, [R1] \n"
"    LDR     R1, =0x1A5C \n"
"    ADD     R0, R0, #0x2000 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_003FC330 \n"
"    MOV     R0, #0x57000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x16FB10 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x2EE7B0 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x7C \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x2F7000 \n"
"    LDR     R0, =0x1D3 \n"
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
"    STR     R0, [SP, #0x38] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x5C] \n"
"    MOV     R0, #0x1000 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0x100 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x2000 \n"
"    STR     R0, [SP, #0x68] \n"
"    LDR     R1, =sub_FF8149AC_my \n"  // --> Patched. Old value = 0xFF8149AC.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_003F1C50 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF8149AC_my @ 0xFF8149AC - 0xFF814A44, length=39
void __attribute__((naked,noinline)) sub_FF8149AC_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R4, =0xFF814A68 /*'/_term'*/ \n"
"    BL      sub_FF810858 \n"
"    LDR     R1, =0x1A54 \n"
"    LDR     R0, =0x19F0 \n"
"    LDR     R1, [R1] \n"
"    LDR     R0, [R0] \n"
"    ADD     R1, R1, #0x10 \n"
"    CMP     R0, R1 \n"
"    LDRCC   R0, =0xFF814A78 /*'USER_MEM size checking'*/ \n"
"    BLCC    _err_init_task \n"
"    BL      sub_FF813774 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814A90 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8124E8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814A98 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF8125D0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814AA8 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF812100 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814ABC /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF815014 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814AC8 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8110A8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814AD4 /*'extlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF817CEC_my \n"  // --> Patched. Old value = 0xFF817CEC.
);
}

/*************************************************************/
//** sub_FF817CEC_my @ 0xFF817CEC - 0xFF817D5C, length=29
void __attribute__((naked,noinline)) sub_FF817CEC_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FF823044 \n"  // --> Nullsub call removed.
"    BL      sub_FF826CC8 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF817D10 \n"
"    BL      sub_FF81C958 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF817D14 \n"

"loc_FF817D10:\n"
"    MOV     R0, #0 \n"

"loc_FF817D14:\n"
"    BL      sub_FF81BB18_my \n"  // --> Patched. Old value = 0xFF81BB18.
"    CMP     R0, #0 \n"
"    BNE     loc_FF817D28 \n"
"    BL      sub_FF81B404 \n"

"loc_FF817D24:\n"
"    B       loc_FF817D24 \n"

"loc_FF817D28:\n"
"    BL      sub_003F8A34 \n"
"    LDR     R1, =0x34E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF827210 \n"
"    BL      sub_003F8D78 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF817C84.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF817D68 /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF81BB18_my @ 0xFF81BB18 - 0xFF81BB7C, length=26
void __attribute__((naked,noinline)) sub_FF81BB18_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R8, R0 \n"
"    MOV     R7, R6 \n"
//"  BL      _sub_FF858618 \n"  // --> Nullsub call removed.
"    LDR     R0, =0xC0220114 \n"
"    BL      sub_FF8569F4 \n"
"    MOV     R4, #1 \n"
"    BIC     R5, R4, R0 \n"
"    LDR     R0, =0xC022010C \n"
"    BL      sub_FF8569F4 \n"
"    CMP     R8, #0 \n"
"    BIC     R4, R4, R0 \n"
"    BEQ     loc_FF81BB58 \n"
"    ORRS    R0, R5, R4 \n"
"    BEQ     loc_FF81BB7C \n"

"loc_FF81BB58:\n"
"    BL      sub_FF826CC8 \n"
"    MOV     R2, R0 \n"
"    MOV     R3, #0 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    STRD    R6, [SP] \n"
//"  BL      _sub_FF858620 \n"  // Disable StartUpChecks
//"  BL      _sub_FF85861C \n"  // --> Nullsub call removed.
"    MOV     R0, #1 \n"

"loc_FF81BB7C:\n"
"    LDMFD   SP!, {R2-R8,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF817C84 - 0xFF817CE8, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF812EB8 \n"
"    BL      sub_FF81BF74 \n"
"    BL      sub_FF81B3B0 \n"
//"  BL      _sub_FF858E4C \n"  // --> Nullsub call removed.
"    BL      sub_FF826F28 \n"
//"  BL      _sub_FF826DC4 \n"  // load DISKBOOT.BIN
"    BL      sub_FF8270AC \n"
"    BL      sub_FF8272E4 \n"
"    BL      sub_FF827070 \n"
"    BL      sub_FF826F60 \n"
"    BL      sub_FF822F7C \n"
"    BL      sub_FF8272EC \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF81B9C0.
"    BL      sub_FF820D44 \n"
"    BL      sub_FF89FAE4 \n"
"    BL      sub_FF8190C4 \n"
"    BL      sub_FF81AD1C \n"
"    BL      sub_FF826AF8 \n"
"    BL      sub_FF81B364 \n"
"    BL      sub_FF81ACB8 \n"
"    BL      sub_FF8470B0 \n"
"    BL      sub_FF819DC8 \n"
"    BL      sub_FF81AC7C \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF812FE0 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF81B9C0 - 0xFF81BA08, length=19
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    BL      sub_FF825D50 \n"
"    BL      sub_FF81C8A8 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BLEQ    sub_FF825CB8 /*_OpLog.Start_FW*/ \n"
"    LDR     R4, =0x1CF4 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81BA04 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF81B98C.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF81BC74 /*'PhySw'*/ \n"
"    BL      sub_003F7C6C /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF81BA04:\n"
"    LDMFD   SP!, {R3-R5,LR} \n"
"    B       sub_FF8592D4 \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF849E18 - 0xFF849E4C, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF88B780 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF88B7B4 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0 \n"
"    B       _PostLogicalEventToUI \n"
);
}

 
 
