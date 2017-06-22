#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"

static long *nrflag = (long*)(0x8748+0x00);  // Found @ ff9df4ac & ff9df50c
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

#define PAUSE_FOR_FILE_COUNTER 150           // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF86F0F0 

void __attribute__((naked,noinline)) capt_seq_task(  ) { 
asm volatile (
      "STMFD   SP!, {R3-R9,LR}\n"
      "LDR     R4, =0x36C6C\n"
      "LDR     R7, =0x2AEC\n"
      "MOV     R6, #0\n"
"loc_FF86F100:\n"
      "LDR     R0, [R7, #4]\n"
      "MOV     R2, #0\n"
      "MOV     R1, SP\n"
      "BL      sub_003F7218\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF86F12C\n"
      "LDR     R1, =0x493\n"
      "LDR     R0, =0xFF86EC5C\n" // "SsShootTask.c"
      "BL      _DebugAssert\n"
      "BL      _ExitTask\n"
      "LDMFD   SP!, {R3-R9,PC}\n"
"loc_FF86F12C:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x20\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF86F394\n"
      "B       loc_FF86F1C0\n"
      "B       loc_FF86F1D8\n"
      "B       loc_FF86F248\n"
      "B       loc_FF86F25C\n"
      "B       loc_FF86F254\n"
      "B       loc_FF86F268\n"
      "B       loc_FF86F270\n"
      "B       loc_FF86F278\n"
      "B       loc_FF86F294\n"
      "B       loc_FF86F2C0\n"
      "B       loc_FF86F2A0\n"
      "B       loc_FF86F2AC\n"
      "B       loc_FF86F2B4\n"
      "B       loc_FF86F2C8\n"
      "B       loc_FF86F2D0\n"
      "B       loc_FF86F2D8\n"
      "B       loc_FF86F2E0\n"
      "B       loc_FF86F2E8\n"
      "B       loc_FF86F2F4\n"
      "B       loc_FF86F2FC\n"
      "B       loc_FF86F304\n"
      "B       loc_FF86F30C\n"
      "B       loc_FF86F314\n"
      "B       loc_FF86F320\n"
      "B       loc_FF86F328\n"
      "B       loc_FF86F330\n"
      "B       loc_FF86F338\n"
      "B       loc_FF86F340\n"
      "B       loc_FF86F34C\n"
      "B       loc_FF86F354\n"
      "B       loc_FF86F360\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F1C0:\n"
//      "BL      shooting_expo_iso_override \n" // added
      "BL      sub_FF86F900\n"
      "BL      shooting_expo_param_override \n" // added
      "BL      sub_FF86CF58\n"
//      "LDR     R0, [R4, #0x28]\n"
//      "CMP     R0, #0\n"
//      "BLNE    sub_FF961044\n" // above 3 lines removed - redundant with added lines below
      "MOV     R0, #0\n"         // patch added
      "STR     R0, [R4,#0x28]\n" //fixes overrides behavior at short shutter press
      "B       loc_FF86F3A0\n"
"loc_FF86F1D8:\n"
"     BL    shooting_set_flash_override\n"
      "LDR     R5, [R0, #0x10]\n"
      "LDR     R0, [R4, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF86F220\n"
      "LDR     R0, [R4, #0x8C]\n"
      "TST     R0, #0x30\n"
      "BLNE    sub_FF870AA4\n"
      "BL      sub_FF870784\n"
      "MOV     R1, R5\n"
      "BL      sub_FF8707DC\n"
      "LDR     R0, =0x10F\n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x24\n"
      "BL      _SetPropertyCase\n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x28\n"
      "MOV     R0, #0x2C\n"
      "BL      _SetPropertyCase\n"
"loc_FF86F220:\n"
      "MOV     R0, R5\n"
//      "BL      sub_FF960FAC\n"  //original
      "BL      sub_FF960FAC_my\n" //patched
      "BL      capt_seq_hook_raw_here \n" // patch
      "MOV     R8, R0\n"
      "MOV     R2, R5\n"
      "MOV     R1, #1\n"
      "BL      sub_FF86D408\n"
      "TST     R8, #1\n"
      "MOVEQ   R0, R5\n"
      "BLEQ    sub_FF9609A0\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F248:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF86FBD0\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F254:\n"
      "BL      sub_FF86F568\n"
      "B       loc_FF86F260\n"
"loc_FF86F25C:\n"
      "BL      sub_FF86F8E0\n"
"loc_FF86F260:\n"
      "STR     R6, [R4, #0x28]\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F268:\n"
      "BL      sub_FF86F8E8\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F270:\n"
      "BL      sub_FF86FAB8\n"
      "B       loc_FF86F298\n"
"loc_FF86F278:\n"
      "LDR     R5, [R0, #0x10]\n"
      "MOV     R0, R5\n"
      "BL      sub_FF961180\n"
      "MOV     R2, R5\n"
      "MOV     R1, #9\n"
      "BL      sub_FF86D408\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F294:\n"
      "BL      sub_FF86FB38\n"
"loc_FF86F298:\n"
      "BL      sub_FF86CF58\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2A0:\n"
      "LDR     R0, [R4, #0x58]\n"
      "BL      sub_FF86FFA8\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2AC:\n"
      "BL      sub_FF870340\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2B4:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8703A4\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2C0:\n"
      "BL      sub_FF86F8E0\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2C8:\n"
      "BL      sub_FF95FD4C\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2D0:\n"
      "BL      sub_FF95FFAC\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2D8:\n"
      "BL      sub_FF960064\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2E0:\n"
      "BL      sub_FF960138\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2E8:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF960398\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2F4:\n"
      "BL      sub_FF960508\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F2FC:\n"
      "BL      sub_FF96059C\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F304:\n"
      "BL      sub_FF960658\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F30C:\n"
      "BL      sub_FF86FD44\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F314:\n"
      "BL      sub_FF86FDB0\n"
      "BL      sub_FF832410\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F320:\n"
      "BL      sub_FF960208\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F328:\n"
      "BL      sub_FF960248\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F330:\n"
      "BL      sub_FF871C80\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F338:\n"
      "BL      sub_FF871CF4\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F340:\n"
      "LDR     R0, [R0, #0xC]\n"
      "BL      sub_FF960780\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F34C:\n"
      "BL      sub_FF9607F0\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F354:\n"
      "BL      sub_FF871D5C\n"
      "BL      sub_FF871D14\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F360:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF96189C\n"
      "MOV     R0, #1\n"
      "BL      sub_FF9619C4\n"
      "LDRH    R0, [R4, #0x9C]\n"
      "CMP     R0, #4\n"
      "LDRNEH  R0, [R4]\n"
      "SUBNE   R1, R0, #0x8200\n"
      "SUBNES  R1, R1, #0x2E\n"
      "BNE     loc_FF86F3A0\n"
      "BL      sub_FF871CF4\n"
      "BL      sub_FF8721B8\n"
      "B       loc_FF86F3A0\n"
"loc_FF86F394:\n"
      "LDR     R1, =0x5F4\n"
      "LDR     R0, =0xFF86EC5C\n"
      "BL      _DebugAssert\n"
"loc_FF86F3A0:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0, #4]\n"
      "LDR     R0, [R7]\n"
      "BL      sub_003FAC6C\n"
      "LDR     R5, [SP]\n"
      "LDR     R0, [R5, #8]\n"
      "CMP     R0, #0\n"
      "LDREQ   R1, =0x117\n"
      "LDREQ   R0, =0xFF86EC5C\n" // "SsShootTask.c"
      "BLEQ    _DebugAssert\n"
      "STR     R6, [R5, #8]\n"
      "B       loc_FF86F100\n"
	);
}


//** sub_FF960FAC_my  @ 0xFF960FAC

void __attribute__((naked,noinline)) sub_FF960FAC_my(  ) {
asm volatile (
      "STMFD   SP!, {R3-R7,LR}\n"
      "LDR     R4, =0x36C6C\n"
      "MOV     R6, R0\n"
      "LDR     R0, [R4, #0x28]\n"
      "MOV     R5, #0\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF960FDC\n"
      "MOV     R0, #0xC\n"
      "BL      sub_FF87373C\n"
      "TST     R0, #1\n"
      "MOVNE   R0, #1\n"
      "BNE     loc_FF9610E4\n"
"loc_FF960FDC:\n"
      "BL      sub_FF86F8F0\n"
      "LDR     R0, [R4, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF9610D0\n"
      "MOV     R0, R6\n"
      "BL      sub_FF9608E0\n"
      "TST     R0, #1\n"
      "BNE     loc_FF9610E4\n"
      "LDR     R0, [R4, #0x8C]\n"
      "AND     R0, R0, #0x40\n"
      "CMP     R0, #0\n"
      "LDRNEH  R0, [R4, #0x9A]\n"
      "CMPNE   R0, #3\n"
      "LDRNE   R0, [R6, #8]\n"
      "CMPNE   R0, #1\n"
      "BLS     loc_FF961038\n"
      "BL      sub_FF961B84\n"
      "MOV     R3, #0xC0\n"
      "STR     R3, [SP]\n"
      "LDR     R2, =0x3A98\n"
      "LDR     R3, =0xFF961208\n" //SsCaptureSeq.c
      "MOV     R1, #0x8000\n"
      "BL      sub_FF8739A4\n"
"loc_FF961038:\n"
      "MOV     R0, R6\n"
      "BL      sub_FF960BEC\n"
      "BL      sub_FF96167C\n"

      "BL      wait_until_remote_button_is_released\n"  //before shoot XXX
      "BL      capt_seq_hook_set_nr\n"

      "LDR     R0, [R4, #0x8C]\n"
      "TST     R0, #0x40\n"
      "BEQ     loc_FF9610AC\n"
      "LDR     R0, =0x181\n"
      "MOV     R2, #4\n"
      "MOV     R1, SP\n"
      "BL      _GetPropertyCase\n"
      "TST     R0, #1\n"
      "MOVNE   R1, #0xD4\n"
      "LDRNE   R0, =0xFF961208\n"  // SsCaptureSeq.c
      "BLNE    _DebugAssert\n"
      "LDR     R0, [SP]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF96108C\n"
      "BL      sub_FF961B84\n"
      "MOV     R1, #0x8000\n"
      "BL      sub_003FAC6C\n"
      "B       loc_FF9610AC\n"
"loc_FF96108C:\n"
      "BL      sub_FF961B84\n"
      "MOV     R1, #0x8000\n"
      "BL      sub_003FACA0\n"
      "LDR     R2, =0xFF960F98\n"
      "LDR     R0, [SP]\n"
      "MOV     R3, #0x8000\n"
      "ADD     R1, R2, #0\n"
      "BL      sub_FF8346B0\n"
"loc_FF9610AC:\n"
      "LDR     R0, [R4, #0x8C]\n"
      "TST     R0, #0x10\n"
      "MOV     R0, R6\n"
      "BEQ     loc_FF9610C4\n"
      "BL      sub_FFA6F808\n"
      "B       loc_FF9610C8\n"
"loc_FF9610C4:\n"
      "BL      sub_FFA6F464\n"
"loc_FF9610C8:\n"
      "MOV     R5, R0\n"
      "B       loc_FF9610E0\n"
"loc_FF9610D0:\n"
      "LDR     R0, =0x6784\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0\n"
      "MOVNE   R5, #0x1D\n"
"loc_FF9610E0:\n"
      "MOV     R0, R5\n"
"loc_FF9610E4:\n"
      "LDMFD   SP!, {R3-R7,PC}\n"
	);
}

#if defined(OPT_EXT_TV_RANGE)
//** exp_drv_task  @ 0xFF8AEE90 

void __attribute__((naked,noinline)) exp_drv_task(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R9,LR}\n"
      "SUB     SP, SP, #0x2C\n"
      "LDR     R6, =0x3DA0\n"
      "LDR     R7, =0xBB8\n"
      "LDR     R4, =0x55E5C\n"
      "MOV     R0, #0\n"
      "ADD     R5, SP, #0x1C\n"
      "STR     R0, [SP, #0xC]\n"
"loc_FF8AEEB0:\n"
      "LDR     R0, [R6, #0x20]\n"
      "MOV     R2, #0\n"
      "ADD     R1, SP, #0x28\n"
      "BL      sub_003F7218\n"
      "LDR     R0, [SP, #0xC]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF8AEEFC\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x14\n"
      "CMPNE   R0, #0x15\n"
      "CMPNE   R0, #0x16\n"
      "CMPNE   R0, #0x17\n"
      "BEQ     loc_FF8AF05C\n"
      "CMP     R0, #0x2A\n"
      "BEQ     loc_FF8AEFE4\n"
      "ADD     R1, SP, #0xC\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8AEE40\n"
"loc_FF8AEEFC:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x30\n"
      "BNE     loc_FF8AEF28\n"
      "BL      sub_FF8B026C\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #1\n"
      "BL      sub_003FAC6C\n"
      "BL      _ExitTask\n"
      "ADD     SP, SP, #0x2C\n"
      "LDMFD   SP!, {R4-R9,PC}\n"
"loc_FF8AEF28:\n"
      "CMP     R1, #0x2F\n"
      "BNE     loc_FF8AEF44\n"
      "LDR     R2, [R0, #0x8C]!\n"
      "LDR     R1, [R0, #4]\n"
      "MOV     R0, R1\n"
      "BLX     R2\n"
      "B       loc_FF8AF518\n"
"loc_FF8AEF44:\n"
      "CMP     R1, #0x28\n"
      "BNE     loc_FF8AEF94\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x80\n"
      "BL      sub_003FACA0\n"
      "LDR     R0, =0xFF8AA7AC\n"
      "MOV     R1, #0x80\n"
      "BL      sub_FF954F74\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x80\n"
      "BL      sub_003FABAC\n"
      "TST     R0, #1\n"
      "LDRNE   R1, =0x1599\n"
      "BNE     loc_FF8AF050\n"
"loc_FF8AEF80:\n"
      "LDR     R1, [SP, #0x28]\n"
      "LDR     R0, [R1, #0x90]\n"
      "LDR     R1, [R1, #0x8C]\n"
      "BLX     R1\n"
      "B       loc_FF8AF518\n"
"loc_FF8AEF94:\n"
      "CMP     R1, #0x29\n"
      "BNE     loc_FF8AEFDC\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF8AEE40\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x100\n"
      "BL      sub_003FACA0\n"
      "LDR     R0, =0xFF8AA7BC\n"
      "MOV     R1, #0x100\n"
      "BL      sub_FF955114\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x100\n"
      "BL      sub_003FABAC\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF8AEF80\n"
      "LDR     R1, =0x15A3\n"
      "B       loc_FF8AF050\n"
"loc_FF8AEFDC:\n"
      "CMP     R1, #0x2A\n"
      "BNE     loc_FF8AEFF4\n"
"loc_FF8AEFE4:\n"
      "LDR     R0, [SP, #0x28]\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF8AEE40\n"
      "B       loc_FF8AEF80\n"
"loc_FF8AEFF4:\n"
      "CMP     R1, #0x2D\n"
      "BNE     loc_FF8AF00C\n"
      "BL      sub_FF89A9E4\n"
      "BL      sub_FF89B6CC\n"
      "BL      sub_FF89B234\n"
      "B       loc_FF8AEF80\n"
"loc_FF8AF00C:\n"
      "CMP     R1, #0x2E\n"
      "BNE     loc_FF8AF05C\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #4\n"
      "BL      sub_003FACA0\n"
      "LDR     R1, =0xFF8AA7DC\n"
      "LDR     R0, =0xFFFFF400\n"
      "MOV     R2, #4\n"
      "BL      sub_FF89A434\n"
      "BL      sub_FF89A6C4\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #4\n"
      "BL      sub_003FAAC8\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF8AEF80\n"
      "LDR     R1, =0x15CB\n"
"loc_FF8AF050:\n"
      "LDR     R0, =0xFF8AAED0\n"
      "BL      _DebugAssert\n"
      "B       loc_FF8AEF80\n"
"loc_FF8AF05C:\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R8, #1\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x12\n"
      "CMPNE   R1, #0x13\n"
      "BNE     loc_FF8AF0C4\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF8AD3E4\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8B0670\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x98]\n"
      "LDR     R3, [R0, #0x94]\n"
      "B       loc_FF8AF3DC\n"
"loc_FF8AF0C4:\n"
      "CMP     R1, #0x14\n"
      "CMPNE   R1, #0x15\n"
      "CMPNE   R1, #0x16\n"
      "CMPNE   R1, #0x17\n"
      "BNE     loc_FF8AF17C\n"
      "ADD     R3, SP, #0xC\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF8AD644\n"
      "CMP     R0, #1\n"
      "MOV     R9, R0\n"
      "CMPNE   R9, #5\n"
      "BNE     loc_FF8AF118\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, R9\n"
      "LDR     R1, [R0, #0x7C]!\n"
      "LDR     R12, [R0, #0x10]!\n"
      "LDR     R3, [R0, #4]\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "B       loc_FF8AF150\n"
"loc_FF8AF118:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R9, #2\n"
      "LDR     R3, [R0, #0x90]\n"
      "CMPNE   R9, #6\n"
      "BNE     loc_FF8AF164\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "MOV     R1, #1\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF8AEB2C\n"
"loc_FF8AF150:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R2, [SP, #0xC]\n"
      "MOV     R1, R9\n"
      "BL      sub_FF8AED7C\n"
      "B       loc_FF8AF3E4\n"
"loc_FF8AF164:\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "ADD     R0, R0, #4\n"
      "BLX     R12\n"
      "B       loc_FF8AF3E4\n"
"loc_FF8AF17C:\n"
      "CMP     R1, #0x24\n"
      "CMPNE   R1, #0x25\n"
      "BNE     loc_FF8AF1C8\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF8AC3D0\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8AC810\n"
      "B       loc_FF8AF3E4\n"
"loc_FF8AF1C8:\n"
      "ADD     R1, R0, #4\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x28\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF8AF3CC\n"
      "B       loc_FF8AF284\n" //(01)
      "B       loc_FF8AF284\n" //(02)
      "B       loc_FF8AF28C\n" //(03)
      "B       loc_FF8AF294\n" //(04)
      "B       loc_FF8AF294\n" //(05)
      "B       loc_FF8AF294\n" //(06)
      "B       loc_FF8AF284\n" //(07)
      "B       loc_FF8AF28C\n" //(08)
      "B       loc_FF8AF294\n" //(09)
      "B       loc_FF8AF294\n" //(10)
      "B       loc_FF8AF2AC\n" //(11)
      "B       loc_FF8AF2AC\n" //(12)
      "B       loc_FF8AF3B8\n" //(13)
      "B       loc_FF8AF3C0\n" //(14)
      "B       loc_FF8AF3C0\n" //(15)
      "B       loc_FF8AF3C0\n" //(16)
      "B       loc_FF8AF3C0\n" //(17)
      "B       loc_FF8AF3C8\n" //(18)
      "B       loc_FF8AF3CC\n" //(19)
      "B       loc_FF8AF3CC\n" //(20)
      "B       loc_FF8AF3CC\n" //(21)
      "B       loc_FF8AF3CC\n" //(22)
      "B       loc_FF8AF3CC\n" //(23)
      "B       loc_FF8AF3CC\n" //(24)
      "B       loc_FF8AF29C\n" //(25)
      "B       loc_FF8AF2A4\n" //(26)
      "B       loc_FF8AF2A4\n" //(27)
      "B       loc_FF8AF2A4\n" //(28)
      "B       loc_FF8AF2B8\n" //(29)
      "B       loc_FF8AF2B8\n" //(30)
      "B       loc_FF8AF2C0\n" //(31)
      "B       loc_FF8AF2F8\n" //(32)
      "B       loc_FF8AF330\n" //(33)
      "B       loc_FF8AF368\n" //(34)
      "B       loc_FF8AF3A0\n" //(35)
      "B       loc_FF8AF3A0\n" //(36)
      "B       loc_FF8AF3CC\n" //(37)
      "B       loc_FF8AF3CC\n" //(38)
      "B       loc_FF8AF3A8\n" //(39)
      "B       loc_FF8AF3B0\n" //(40)
"loc_FF8AF284:\n" // jump table entries 01-02,07
      "BL      sub_FF8AAD54\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF28C:\n"// jump table entry 03
      "BL      sub_FF8AAFF8\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF294:\n" // jump table entries 04-06,09-10
      "BL      sub_FF8AB220\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF29C:\n" // jump table entries 25
      "BL      sub_FF8AB544\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF2A4:\n" // jump table entries 26-27
      "BL      sub_FF8AB75C\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF2AC:\n" // jump table entries 11,12
//      "BL      sub_FF8ABB08\n"  //original
      "BL      sub_FF8ABB08_my\n" //patched
      "MOV     R8, #0\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF2B8:\n" // jump table entries 29,30
      "BL      sub_FF8ABC48\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF2C0:\n" // jump table entry 31
      "LDRH    R1, [R0, #4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R0, #0xC]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B0300\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF2F8:\n" // jump table entry 32
      "LDRH    R1, [R0, #4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R4, #8]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B0470\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF330:\n" // jump table entry 33
      "LDRH    R1, [R4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R0, #6]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R4, #8]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B0524\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF368:\n" // jump table entry 34
      "LDRH    R1, [R4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R0, #0xC]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B05CC\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF3A0:\n" // jump table entries 35-36
      "BL      sub_FF8AC184\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF3A8:\n" // jump table entry 39
      "BL      sub_FF8AC914\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF3B0:\n" // jump table entry 40
      "BL      sub_FF8ACBF8\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF3B8:\n" // jump table entry 13
      "BL      sub_FF8ACEB8\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF3C0:\n" // jump table entries 14-17
      "BL      sub_FF8AD074\n"
      "B       loc_FF8AF3CC\n"
"loc_FF8AF3C8:\n" // jump table entry 18
      "BL      sub_FF8AD1DC\n"
"loc_FF8AF3CC:\n" // jump table default entry
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "LDR     R3, [R0, #0x8C]\n"
"loc_FF8AF3DC:\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
"loc_FF8AF3E4:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x10\n"
      "BEQ     loc_FF8AF41C\n"
      "BGT     loc_FF8AF40C\n"
      "CMP     R0, #1\n"
      "CMPNE   R0, #4\n"
      "CMPNE   R0, #0xE\n"
      "BNE     loc_FF8AF450\n"
      "B       loc_FF8AF41C\n"
"loc_FF8AF40C:\n"
      "CMP     R0, #0x13\n"
      "CMPNE   R0, #0x17\n"
      "CMPNE   R0, #0x1A\n"
      "BNE     loc_FF8AF450\n"
"loc_FF8AF41C:\n"
      "LDRSH   R0, [R4]\n"
      "CMN     R0, #0xC00\n"
      "LDRNESH R1, [R4, #8]\n"
      "CMNNE   R1, #0xC00\n"
      "STRNEH  R0, [SP, #0x1C]\n"
      "STRNEH  R1, [SP, #0x24]\n"
      "BNE     loc_FF8AF450\n"
      "ADD     R0, SP, #0x10\n"
      "BL      sub_FF8B0880\n"
      "LDRH    R0, [SP, #0x10]\n"
      "STRH    R0, [SP, #0x1C]\n"
      "LDRH    R0, [SP, #0x18]\n"
      "STRH    R0, [SP, #0x24]\n"
"loc_FF8AF450:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R8, #1\n"
      "BNE     loc_FF8AF4A0\n"
      "LDR     R1, [R0, #0x7C]\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R0, R0, R1, LSL #2\n"
      "SUB     R8, R0, #8\n"
      "LDR     R0, =0x55E5C\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_003FC17C\n"
      "LDR     R0, =0x55E68\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_003FC17C\n"
      "LDR     R0, =0x55E74\n"
      "MOV     R2, #0xC\n"
      "MOV     R1, R8\n"
      "BL      sub_003FC17C\n"
      "B       loc_FF8AF518\n"
"loc_FF8AF4A0:\n"
      "LDR     R0, [R0]\n"
      "MOV     R3, #1\n"
      "CMP     R0, #0xB\n"
      "BNE     loc_FF8AF4E4\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8AAB34\n"
      "MOV     R3, #1\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "B       loc_FF8AF514\n"
"loc_FF8AF4E4:\n"
      "MOV     R2, #1\n"
      "STRD    R2, [SP]\n"
      "MOV     R3, R2\n"
      "MOV     R1, R2\n"
      "MOV     R0, R2\n"
      "BL      sub_FF8AAB34\n"
      "MOV     R3, #1\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, R3\n"
      "STR     R3, [SP]\n"
      "STR     R3, [SP, #4]\n"
"loc_FF8AF514:\n"
      "BL      sub_FF8AACA0\n"
"loc_FF8AF518:\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8B026C\n"
      "B       loc_FF8AEEB0\n"
	);
}


//** sub_FF8ABB08_my  @ 0xFF8ABB08

void __attribute__((naked,noinline)) sub_FF8ABB08_my(  ) {
asm volatile (
      "STMFD   SP!, {R4-R8,LR}\n"
      "LDR     R7, =0x3DA0\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R7, #0x1C]\n"
      "MOV     R1, #0x3E\n"
      "BL      sub_003FACA0\n"
      "MOV     R2, #0\n"
      "LDRSH   R0, [R4, #4]\n"
      "MOV     R1, R2\n"
      "BL      sub_FF8AA83C\n"
      "MOV     R6, R0\n"
      "LDRSH   R0, [R4, #6]\n"
      "BL      sub_FF8AA98C\n"
      "LDRSH   R0, [R4, #8]\n"
      "BL      sub_FF8AA9E4\n"
      "LDRSH   R0, [R4, #0xA]\n"
      "BL      sub_FF8AAA3C\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "MOV     R1, #0\n"
      "BL      sub_FF8AAA94\n"
      "MOV     R5, R0\n"
      "LDR     R0, [R4]\n"
      "LDR     R8, =0x55E74\n"
      "CMP     R0, #0xB\n"
      "MOVEQ   R6, #0\n"
      "MOVEQ   R5, R6\n"
      "BEQ     loc_FF8ABB9C\n"
      "CMP     R6, #1\n"
      "BNE     loc_FF8ABB9C\n"
      "LDRSH   R0, [R4, #4]\n"
      "LDR     R1, =0xFF8AA79C\n"
      "MOV     R2, #2\n"
      "BL      sub_FF954FF8\n"
      "STRH    R0, [R4, #4]\n"
      "MOV     R0, #0\n"
      "STR     R0, [R7, #0x28]\n"
      "B       loc_FF8ABBA4\n"
"loc_FF8ABB9C:\n"
      "LDRH    R0, [R8]\n"
      "STRH    R0, [R4, #4]\n"
"loc_FF8ABBA4:\n"
      "CMP     R5, #1\n"
      "LDRNEH  R0, [R8, #8]\n"
      "BNE     loc_FF8ABBC0\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "LDR     R1, =0xFF8AA820\n"
      "MOV     R2, #0x20\n"
      "BL      sub_FF8B02BC\n"
"loc_FF8ABBC0:\n"
      "STRH    R0, [R4, #0xC]\n"
      "LDRSH   R0, [R4, #6]\n"
//      "BL      sub_FF89A730\n" //original
      "BL      sub_FF89A730_my\n"//patched
      "B sub_FF8ABBCC \n" // continue in firmware
	);
}


//** sub_FF89A730_my  @ 0xFF89A730 

void __attribute__((naked,noinline)) sub_FF89A730_my(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R6,LR}\n"
      "LDR     R5, =0x39F0\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R5, #4]\n"
      "CMP     R0, #1\n"
      "LDRNE   R1, =0x14D\n"
      "LDRNE   R0, =0xFF89A568\n"//  ; "Shutter.c"
      "BLNE    _DebugAssert\n"
      "CMN     R4, #0xC00\n"
      "LDREQSH R4, [R5, #2]\n"
      "CMN     R4, #0xC00\n"
      "LDREQ   R1, =0x153\n"
      "LDREQ   R0, =0xFF89A568\n"//  ; "Shutter.c"
      "STRH    R4, [R5, #2]\n"
      "BLEQ    _DebugAssert\n"
      "MOV     R0, R4\n"
//      "BL      _apex2us\n"   //original _apex2us
      "BL      apex2us \n"   //patch
      "MOV     R4, R0\n"
      "BL      sub_FF8E9B4C\n"
      "MOV     R0, R4\n"
      "BL      sub_FF8F2354\n"
      "TST     R0, #1\n"
      "LDMEQFD SP!, {R4-R6,PC}\n"
      "LDMFD   SP!, {R4-R6,LR}\n"
      "MOV     R1, #0x158\n"
      "LDR     R0, =0xFF89A568\n" //  ; "Shutter.c"
      "B       _DebugAssert\n"
	);
}
#endif

