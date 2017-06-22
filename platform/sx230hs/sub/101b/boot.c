#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

void CreateTask_spytask();

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();

void taskHook(context_t **context) {

    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

    // Replace firmware task addresses with ours
    if(tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
    if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
    if(tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
}

void __attribute__((naked,noinline)) boot() {
    asm volatile (

"loc_FF00000C:\n"
"   LDR R1, =0xC0410000 \n"
"   MOV R0, #0 \n"
"   STR R0, [R1] \n"
"   MOV R1, #0x78 \n"
"   MCR p15, 0, R1, c1, c0 \n"
"   MOV R1, #0 \n"
"   MCR p15, 0, R1, c7, c10, 4 \n"
"   MCR p15, 0, R1, c7, c5 \n"
"   MCR p15, 0, R1, c7, c6 \n"
"   MOV R0, #0x3D \n"
"   MCR p15, 0, R0, c6, c0 \n"
"   MOV R0, #0xC000002F \n"
"   MCR p15, 0, R0, c6, c1 \n"
"   MOV R0, #0x35 \n"
"   MCR p15, 0, R0, c6, c2 \n"
"   MOV R0, #0x40000035 \n"
"   MCR p15, 0, R0, c6, c3 \n"
"   MOV R0, #0x80000017 \n"
"   MCR p15, 0, R0, c6, c4 \n"
"   LDR R0, =0xFF00002F \n"
"   MCR p15, 0, R0, c6, c5 \n"
"   MOV R0, #0x34 \n"
"   MCR p15, 0, R0, c2, c0 \n"
"   MOV R0, #0x34 \n"
"   MCR p15, 0, R0, c2, c0, 1 \n"
"   MOV R0, #0x34 \n"
"   MCR p15, 0, R0, c3, c0 \n"
"   LDR R0, =0x3333330 \n"
"   MCR p15, 0, R0, c5, c0, 2 \n"
"   LDR R0, =0x3333330 \n"
"   MCR p15, 0, R0, c5, c0, 3 \n"
"   MRC p15, 0, R0, c1, c0 \n"
"   ORR R0, R0, #0x1000 \n"
"   ORR R0, R0, #4 \n"
"   ORR R0, R0, #1 \n"
"   MCR p15, 0, R0, c1, c0 \n"
"   MOV R1, #0x80000006 \n"
"   MCR p15, 0, R1, c9, c1 \n"
"   MOV R1, #6 \n"
"   MCR p15, 0, R1, c9, c1, 1 \n"
"   MRC p15, 0, R1, c1, c0 \n"
"   ORR R1, R1, #0x50000 \n"
"   MCR p15, 0, R1, c1, c0 \n"
"   LDR R2, =0xC0200000 \n"
"   MOV R1, #1 \n"
"   STR R1, [R2, #0x10C] \n"
"   MOV R1, #0xFF \n"
"   STR R1, [R2, #0xC] \n"
"   STR R1, [R2, #0x1C] \n"
"   STR R1, [R2, #0x2C] \n"
"   STR R1, [R2, #0x3C] \n"
"   STR R1, [R2, #0x4C] \n"
"   STR R1, [R2, #0x5C] \n"
"   STR R1, [R2, #0x6C] \n"
"   STR R1, [R2, #0x7C] \n"
"   STR R1, [R2, #0x8C] \n"
"   STR R1, [R2, #0x9C] \n"
"   STR R1, [R2, #0xAC] \n"
"   STR R1, [R2, #0xBC] \n"
"   STR R1, [R2, #0xCC] \n"
"   STR R1, [R2, #0xDC] \n"
"   STR R1, [R2, #0xEC] \n"
"   STR R1, [R2, #0xFC] \n"
"   LDR R1, =0xC0400008 \n"
"   LDR R2, =0x430005 \n"
"   STR R2, [R1] \n"
"   MOV R1, #1 \n"
"   LDR R2, =0xC0243100 \n"
"   STR R2, [R1] \n"
"   LDR R2, =0xC0242010 \n"
"   LDR R1, [R2] \n"
"   ORR R1, R1, #1 \n"
"   STR R1, [R2] \n"
"   LDR R0, =0xFF4B506C \n"
"   LDR R1, =0x1900 \n"
"   LDR R3, =0x11C18 \n"
"loc_FF00013C:\n"
"   CMP R1, R3 \n"
"   LDRCC   R2, [R0], #4 \n"
"   STRCC   R2, [R1], #4 \n"
"   BCC loc_FF00013C \n"
"   LDR R1, =0x18A7FC \n"
"   MOV R2, #0 \n"
"loc_FF000154:\n"
"   CMP R3, R1 \n"
"   STRCC   R2, [R3], #4 \n"
"   BCC loc_FF000154 \n"
//PATCH
                // "B       sub_FF000358\n"
                "B       sub_FF000358_my\n"
//PATCH END

                 );
}

//SX230:101a @ FF000358
void __attribute__((naked,noinline)) sub_FF000358_my() {

   *(int*)0x1938=(int)taskHook;
   *(int*)0x193C=(int)taskHook;

//Power-on FF00FCCC+FF056DB4

if ((*(int*) 0xC022012C) & 1)                   // look at play switch
        *(int*)(0x25E4) = 0x200000;                 // not pressed - start in rec mode
    else
        *(int*)(0x25E4) = 0x100000;                 // power pressed - start in play mode

   asm volatile (
"   LDR R0, =0xFF0003D0 \n"
"   MOV R1, #0 \n"
"   LDR R3, =0xFF000408 \n"
"loc_FF000364:\n"
"   CMP R0, R3 \n"
"   LDRCC   R2, [R0], #4 \n"
"   STRCC   R2, [R1], #4 \n"
"   BCC loc_FF000364 \n"
"   LDR R0, =0xFF000408 \n"
"   MOV R1, #0x4B0 \n"
"   LDR R3, =0xFF00061C \n"
"loc_FF000380:\n"
"   CMP R0, R3 \n"
"   LDRCC   R2, [R0], #4 \n"
"   STRCC   R2, [R1], #4 \n"
"   BCC loc_FF000380 \n"
"   MOV R0, #0xD2 \n"
"   MSR CPSR_cxsf, R0 \n"
"   MOV SP, #0x1000 \n"
"   MOV R0, #0xD3 \n"
"   MSR CPSR_cxsf, R0 \n"
"   MOV SP, #0x1000 \n"
"   LDR R0, =0x6C4 \n"
"   LDR R2, =0xEEEEEEEE \n"
"   MOV R3, #0x1000 \n"
"loc_FF0003B4:\n"
"   CMP R0, R3 \n"
"   STRCC   R2, [R0], #4 \n"
"   BCC loc_FF0003B4 \n"
//PATCH BEGIN
            //  "BL      sub_FF0011B0\n"
                "BL      sub_FF0011B0_my\n"
//PATCH END
"loc_FF0003C4:\n"
                 "ANDEQ   R0, R0, R4,ASR#13\n"
"loc_FF0003C8:\n"
                 "ANDEQ   R0, R0, R0,ROR R6\n"
"loc_FF0003CC:\n"
                 "ANDEQ   R0, R0, R4,ROR R6\n"
"loc_FF8103D0:\n"
                 "NOP\n"
                 "LDR     PC, =0xFF00061C\n"
                );
}

//SX230 @ FF0011B0
void __attribute__((naked,noinline)) sub_FF0011B0_my() {

    asm volatile (
             "  STR LR, [SP, #-4]! \n"
"   SUB SP, SP, #0x74 \n"
"   MOV R1, #0x74 \n"
"   MOV R0, SP \n"
"   BL  sub_FF3B60B4 \n"
"   MOV R0, #0x53000 \n"
"   STR R0, [SP, #4] \n"
//PATCH BEGIN
#if defined(OPT_CHDK_IN_EXMEM)
        "   LDR R0, =0x18A7FC \n"
#else
              //"   LDR R0, =0x18A7FC \n"
                "LDR     R0, =new_sa\n"
                "LDR     R0, [R0]\n"
#endif
//PATCH END
                "   LDR R2, =0x371F80 \n"
"   STR R0, [SP, #8] \n"
"   SUB R0, R2, R0 \n"
"   STR R0, [SP, #0xC] \n"
"   MOV R0, #0x22 \n"
"   STR R0, [SP, #0x18] \n"
"   MOV R0, #0x68 \n"
"   STR R0, [SP, #0x1C] \n"
"   LDR R1, =0x379C00 \n"
"   LDR R0, =0x19B \n"
"   STR R1, [SP] \n"
"   STR R0, [SP, #0x20] \n"
"   MOV R0, #0x96 \n"
"   STR R2, [SP, #0x10] \n"
"   STR R1, [SP, #0x14] \n"
"   STR R0, [SP, #0x24] \n"
"   STR R0, [SP, #0x28] \n"
"   MOV R0, #0x64 \n"
"   STR R0, [SP, #0x2C] \n"
"   MOV R0, #0 \n"
"   STR R0, [SP, #0x30] \n"
"   STR R0, [SP, #0x34] \n"
"   MOV R0, #0x10 \n"
"   STR R0, [SP, #0x5C] \n"
"   MOV R0, #0x800 \n"
"   STR R0, [SP, #0x60] \n"
"   MOV R0, #0xA0 \n"
"   STR R0, [SP, #0x64] \n"
"   MOV R0, #0x280 \n"
"   STR R0, [SP, #0x68] \n"
//PATCH BEGIN
//              "LDR     R1, =sub_FF005EE0\n"
                "LDR     R1, =sub_FF005EE0_my\n"
//PATCH END
"   MOV R2, #0 \n"
"   MOV R0, SP \n"
"   BL  sub_FF0034C4 \n"
"   ADD SP, SP, #0x74 \n"
"   LDR PC, [SP], #4 \n"

                 );
}

//SX230:101a @ FF005EE0
void __attribute__((naked,noinline)) sub_FF005EE0_my() {

     asm volatile (
"   STMFD   SP!, {R4,LR} \n"
"   BL  sub_FF000B28 \n"
"   BL  sub_FF00A374 \n"
"   CMP R0, #0 \n"
"   LDRLT   R0, =0xFF005FF4 \n"
"   BLLT    sub_FF005FD4 \n"
"   BL  sub_FF005B18 \n"
"   CMP R0, #0 \n"
"   LDRLT   R0, =0xFF005FFC \n"
"   BLLT    sub_FF005FD4 \n"
"   LDR R0, =0xFF00600C \n"
"   BL  sub_FF005C00 \n"
"   CMP R0, #0 \n"
"   LDRLT   R0, =0xFF006014 \n"
"   BLLT    sub_FF005FD4 \n"
"   LDR R0, =0xFF00600C \n"
"   BL  sub_FF003CA8 \n"
"   CMP R0, #0 \n"
"   LDRLT   R0, =0xFF006028 \n"
"   BLLT    sub_FF005FD4 \n"
"   BL  sub_FF009D00 \n"
"   CMP R0, #0 \n"
"   LDRLT   R0, =0xFF006034 \n"
"   BLLT    sub_FF005FD4 \n"
"   BL  sub_FF001690 \n"
"   CMP R0, #0 \n"
"   LDRLT   R0, =0xFF006040 \n"
"   BLLT    sub_FF005FD4 \n"
"   LDMFD   SP!, {R4,LR} \n"
//PATCH BEGIN
//              "   B   sub_FF00FD54 \n"
                "B       sub_FF00FD54_my\n" // inserted sx230
//PATCH END
        );
};

//SX230 @ FF00FD54
void __attribute__((naked,noinline)) sub_FF00FD54_my(){
asm volatile (
"   STMFD   SP!, {R3,LR} \n"
"   BL  sub_FF02B74C \n"
"   BL  sub_FF02B964 \n"
"   MOV R3, #0 \n"
"   STR R3, [SP] \n"
//PATCH BEGIN
    //  "LDR     R3, =0xFF00FC6C\n"
        "LDR     R3, =taskcreate_Startup_my\n"
//PATCH END
"   MOV R2, #0x200 \n"
"   MOV R1, #0x19 \n"
"   LDR R0, =0xFF00FDA0 \n"
"   BL  sub_FF00E9B0 \n"
"   MOV R0, #0 \n"
"   LDMFD   SP!, {R3,PC} \n"
    );
}


//Added dSX230  from FF00FC6C
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
    asm volatile (
"   STMFD   SP!, {R3-R9,LR} \n"
"   MOV R5, #0 \n"
"   BL  sub_FF024A40 \n"
"   BL  sub_FF025C30 \n"
"   BL  sub_FF023C70 \n"
"   BL  sub_FF02D904 \n"
"   BL  sub_FF024E90 \n"
"   BL  sub_FF02389C \n"
"   BL  sub_FF023C0C \n"
"   BL  sub_FF02D674 \n"
"   LDR R7, =0xC0220000 \n"
"   MOVS    R9, R0 \n"
"   MOV R8, #1 \n"
"   BNE loc_FF00FD00 \n"
"   BL  sub_FF0263C0 \n"
"   CMP R0, #0 \n"
"   BEQ loc_FF00FD00 \n"
"   LDR R0, [R7, #0xD4] \n"
"   BICS    R4, R8, R0 \n"
"   BEQ loc_FF00FCCC \n"
"   MOV R0, #0x12C \n"
"   BL  sub_FF02B91C \n"
"   LDR R0, [R7, #0xD4] \n"
"   BIC R4, R8, R0 \n"
"loc_FF00FCCC:\n"
"   LDR R0, [R7, #0x12C] \n"
"   BIC R6, R8, R0 \n"
"   BL  sub_FF023C34 \n"
"   CMP R0, #1 \n"
"   MOVEQ   R5, #1 \n"
"   ORR R0, R6, R4 \n"
"   ORRS    R0, R0, R5 \n"
"   BNE loc_FF00FD10 \n"
"   BL  sub_FF024064 \n"
"   MOV R0, #0x44 \n"
"   STR R0, [R7, #0x1C] \n"
"   BL  sub_FF024258 \n"
"loc_FF00FCFC:\n"
"   B   loc_FF00FCFC \n"
"loc_FF00FD00:\n"
"   LDR R0, [R7, #0x12C] \n"
"   BIC R6, R8, R0 \n"
"   LDR R0, [R7, #0xD4] \n"
"   BIC R4, R8, R0 \n"
"loc_FF00FD10:\n"
"   MOV R3, R5 \n"
"   MOV R2, R9 \n"
"   MOV R1, R4 \n"
"   MOV R0, R6 \n"
//PATCH START //TODO    //comment next line
//        "BL      sub_FF024A48\n"   //we must remove this for power-on mode handling to work
//PATCH END
"   BL  sub_FF024A44 \n"
"   LDR R1, =0x3CE000 \n"
"   MOV R0, #0 \n"
"   BL  sub_FF02BBBC \n"
"   MOV R3, #0 \n"
"   STR R3, [SP] \n"
//BEGIN PATCH
//      "LDR    R3, =0xFF00FBF4\n"
        "LDR     R3, =task_Startup_my\n"
//END PATCH
"   MOV R2, #0 \n"
"   MOV R1, #0x19 \n"
"   LDR R0, =0xFF00FD94 \n"
"   BL  sub_FF00E9B0 \n"
"   LDMFD   SP!, {R3-R9,PC} \n"

        "loc_FF0263C0:\n"
                 "LDR     R0, =0xFFF40100\n"
                 "LDRB    R0, [R0]\n"
                 "CMP     R0, #0\n"
                 "MOVEQ   R0, #1\n"
                 "MOVNE   R0, #0\n"
                 "BX      LR\n"
    );
}

// SX230 @FF00FBF4
void __attribute__((naked,noinline)) task_Startup_my() {

   asm volatile (

"   STMFD   SP!, {R4,LR} \n"
"   BL  sub_FF006588 \n"
"   BL  sub_FF02D718 \n"
//PATCH BEGIN
//      "BL      sub_FF02D7AC\n"            //start diskboot.bin
//PATCH END
"   BL  sub_FF02DAB4 \n"
"   LDR R1, =0x30101 \n"
"   MOV R0, #2 \n"
"   BL  sub_FF02AC78 \n"
"   LDR R1, =0xC0220000 \n"
"   MOV R0, #8 \n"
"   STR R0, [R1, #0x9C] \n"
"   MOV R0, #2 \n"
"   BL  sub_FF02A9A8 \n"
"   BL  sub_FF02227C \n"
"   BL  sub_FF02D934 \n"
"   BL  sub_FF02AEF0 \n"
"   BL  sub_FF02DAB8 \n"
//PATCH START
        "BL      CreateTask_spytask\n"
//      "BL      sub_FF0248DC\n"
        "BL      taskcreatePhySw_my\n"
//PATCH END
"   BL  sub_FF02837C \n"
"   BL  sub_FF02DAD0 \n"
"   BL  sub_FF021674 \n"
"   BL  sub_FF02320C \n"
"   BL  sub_FF02D344 \n"
"   BL  sub_FF023850 \n"
"   BL  sub_FF0231A8 \n"
"   BL  sub_FF0222B0 \n"
"   BL  sub_FF02E6A0 \n"
"   BL  sub_FF02316C \n"
"   LDMFD   SP!, {R4,LR} \n"
"   B   sub_FF0066A8 \n"
        );
}

void __attribute__((naked,noinline)) taskcreatePhySw_my() {

    //sub_FF0248DC
    asm volatile (

                 "STMFD   SP!, {R3-R5,LR}\n"
                 "LDR     R4, =0x1C44\n"
                 "LDR     R0, [R4,#4]\n"
                 "CMP     R0, #0\n"
                 "BNE     sub_FF024910\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [SP]\n"
                 "LDR     R3, =mykbd_task\n"
//PATCH BEGIN
//               "MOV     R2, #0x800\n"
                 "MOV     R2, #0x2000\n"        // stack size for new task_PhySw so we don't have to do stack switch
//PATCH END
                 "B         sub_FF024900"
                );


}

void spytask(long ua, long ub, long uc, long ud, long ue, long uf) {

    core_spytask();
}

void beeper(long ua, long ub, long uc, long ud, long ue, long uf)
{
 bgndBeeper();
}

void CreateTask_spytask() {
  _CreateTask("Beeper", 0x1, 0x200, beeper, 0);
  _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
};

//sx230 @ 0xFF096FCC
void __attribute__((naked,noinline)) init_file_modules_task() {

     asm volatile(
//FF096FCC
            "STMFD   SP!, {R4-R6,LR}\n"
            "BL      sub_FF08C78C\n"
            "LDR     R5, =0x5006\n"
            "MOVS    R4, R0\n"
            "MOVNE   R1, #0\n"
            "MOVNE   R0, R5\n"
            "BLNE    sub_FF090CD4\n"
//PATCH BEGIN //TODO
            "BL      sub_FF08C7B8\n"
//          "BL      sub_FF08C7B8_my\n"
            "BL      core_spytask_can_start\n"
//PATCH END

//TODO REMOVE REST OF FUNCTION
            "CMP     R4, #0\n"
            "LDMNEFD SP!, {R4-R6,PC}\n"
            "MOV     R0, R5\n"
            "LDMFD   SP!, {R4-R6,LR}\n"
            "MOV     R1, #0\n"
            "B       sub_FF090CD4\n"
        );
}

