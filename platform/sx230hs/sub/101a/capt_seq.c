#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"
static long *nrflag = (long*)(0x8A64 + 0x8 );  // 0x8A64 (  @FF195C0C ) + 8 (@FF195C48)
#define NR_AUTO (0)                         // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 100          // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//SX230 @FF078BF0
void __attribute__((naked,noinline)) capt_seq_task() {
 asm volatile (
//"sub_FF078BF0\n"

        "STMFD  SP!, {R3-R9,LR}\n"
        "LDR    R5, =0x3EFA4\n"
        "LDR    R7, =0x3EF4\n"
        "MOV    R6, #0\n"
"loc_FF078C00:\n"
        "LDR    R0, [R7,#4]\n"
        "MOV    R2, #0\n"
        "MOV    R1, SP\n"
        "BL     sub_FF02B184\n"
        "TST    R0, #1\n"
        "BEQ    loc_FF078C2C\n"
        "LDR    R1, =0x47A\n"
        "LDR    R0, =0xFF07861C\n"      //"SsShootTask.c"
        "BL     sub_FF00EC88\n"         //assert
        "BL     sub_FF00EC40\n"         //ExitTask
        "LDMFD  SP!, {R3-R9,PC}\n"
"loc_FF078C2C:\n"
        "LDR    R0, [SP]\n"
        "LDR    R1, [R0]\n"
        "CMP    R1, #0x27\n"
        "ADDCC  PC, PC, R1,LSL#2\n"
        "B  loc_FF078EAC\n"

//"loc_FF078C40:\n"
        "B  loc_FF078CDC\n"
//"loc_FF078C44:\n"
        "B  loc_FF078CF4\n"
//"loc_FF078C48:\n"
        "B  loc_FF078D2C\n"
//"loc_FF078C4C:\n"
        "B  loc_FF078D40\n"
//"loc_FF078C50:\n"
        "B  loc_FF078D38\n"
//"loc_FF078C54:\n"
        "B  loc_FF078D4C\n"
//"loc_FF078C58:\n"
        "B  loc_FF078D54\n"
//"loc_FF078C5C:\n"
        "B  loc_FF078D5C\n"
//"loc_FF078C60:\n"
        "B  loc_FF078D78\n"
//"loc_FF078C64:\n"
        "B  loc_FF078DB8\n"
//"loc_FF078C68:\n"
        "B  loc_FF078D84\n"
//"loc_FF078C6C:\n"
        "B  loc_FF078D90\n"
//"loc_FF078C70:\n"
        "B  loc_FF078D98\n"
//"loc_FF078C74:\n"
        "B  loc_FF078DA0\n"
//"loc_FF078C78:\n"
        "B  loc_FF078DA8\n"
//"loc_FF078C7C:\n"
        "B  loc_FF078DB0\n"
//"loc_FF078C80:\n"
        "B  loc_FF078DC0\n"
//"loc_FF078C84:\n"
        "B  loc_FF078DC8\n"
//"loc_FF078C88:\n"
        "B  loc_FF078DD0\n"
//"loc_FF078C8C:\n"
        "B  loc_FF078DD8\n"
//"loc_FF078C90:\n"
        "B  loc_FF078DE0\n"
//"loc_FF078C94:\n"
        "B  loc_FF078DE8\n"
//"loc_FF078C98:\n"
        "B  loc_FF078DF0\n"
//"loc_FF078C9C:\n"
        "B  loc_FF078DF8\n"
//"loc_FF078CA0:\n"
        "B  loc_FF078E00\n"
//"loc_FF078CA4:\n"
        "B  loc_FF078E08\n"
//"loc_FF078CA8:\n"
        "B  loc_FF078E14\n"
//"loc_FF078CAC:\n"
        "B  loc_FF078E1C\n"
//"loc_FF078CB0:\n"
        "B  loc_FF078E28\n"
//"loc_FF078CB4:\n"
        "B  loc_FF078E30\n"
//"loc_FF078CB8:\n"
        "B  loc_FF078E38\n"
//"loc_FF078CBC:\n"
        "B  loc_FF078E40\n"
//"loc_FF078CC0:\n"
        "B  loc_FF078E48\n"
//"loc_FF078CC4:\n"
        "B  loc_FF078E50\n"
//"loc_FF078CC8:\n"
        "B  loc_FF078E58\n"
//"loc_FF078CCC:\n"
        "B  loc_FF078E60\n"
//"loc_FF078CD0:\n"
        "B  loc_FF078E68\n"
//"loc_FF078CD4:\n"
        "B  loc_FF078E74\n"
//"loc_FF078CD8:\n"
        "B  loc_FF078EB8\n"

"loc_FF078CDC:\n"
//PATCH BEGIN
        "BL      shooting_expo_iso_override\n"
//PATCH END
            "BL      sub_FF0794CC\n"
//PATCH BEGIN
        "BL      shooting_expo_param_override\n"
//PATCH END
                 "BL    sub_FF07618C\n"
//PATCH BEGIN
//      "LDR    R0, [R5,#0x28]\n"
//      "CMP    R0, #0\n"
//      "BLNE   sub_FF19309C\n"
        "MOV     R0, #0\n"
        "STR     R0, [R5,#0x28]\n"  // fixes overrides  behavior at short shutter press
//PATCH END
        "B  loc_FF078EB8\n"

"loc_FF078CF4:\n"
        "LDR    R8, [R0,#0xC]\n"
        "MOV    R0, R8\n"
//PATCH BEGIN
//      "BL     sub_FF192E78\n"
        "BL     sub_FF192E78_my\n"
        "BL     capt_seq_hook_raw_here\n"
//PATCH END
        "MOV    R4, R0\n"
        "MOV    R2, R8\n"
        "MOV    R1, #1\n"
        "BL     sub_FF076C14\n"
        "TST    R4, #1\n"
        "BNE    loc_FF078D24\n"
        "MOV    R0, R8\n"
        "BL     sub_FF192864\n"
        "B      loc_FF078EB8\n"
"loc_FF078D24:\n"
        "BL sub_FF192834\n"
        "B  loc_FF078EB8\n"
"loc_FF078D2C:\n"
        "MOV    R0, #1\n"
        "BL sub_FF0797AC\n"
        "B  loc_FF078EB8\n"
"loc_FF078D38:\n"
        "BL sub_FF079108\n"
        "B  loc_FF078D44\n"
"loc_FF078D40:\n"
        "BL sub_FF0794AC\n"
"loc_FF078D44:\n"
        "STR    R6, [R5,#0x28]\n"
        "B  loc_FF078EB8\n"
// last call after shot, also called switching from play->shoot
"loc_FF078D4C:\n"
        "BL sub_FF0794B4\n"
        "B  loc_FF078EB8\n"
"loc_FF078D54:\n"
        "BL sub_FF0796A0\n"
        "B  loc_FF078D7C\n"
"loc_FF078D5C:\n"
        "LDR    R4, [R0,#0xC]\n"
        "MOV    R0, R4\n"
        "BL     sub_FF1930F0\n"
        "MOV    R2, R4\n"
        "MOV    R1, #9\n"
        "BL     sub_FF076C14\n"
        "B      loc_FF078EB8\n"
"loc_FF078D78:\n"
        "BL sub_FF079714\n"
"loc_FF078D7C:\n"
        "BL sub_FF07618C\n"
        "B  loc_FF078EB8\n"
"loc_FF078D84:\n"
        "LDR    R0, [R5,#0x58]\n"
        "BL sub_FF07A034\n"
        "B  loc_FF078EB8\n"
"loc_FF078D90:\n"
        "BL sub_FF07A304\n"
        "B  loc_FF078EB8\n"
"loc_FF078D98:\n"
        "BL sub_FF07A368\n"
        "B  loc_FF078EB8\n"
"loc_FF078DA0:\n"
        "BL sub_FF07A55C\n"
        "B  loc_FF078EB8\n"
"loc_FF078DA8:\n"
        "BL sub_FF07A9AC\n"
        "B  loc_FF078EB8\n"
"loc_FF078DB0:\n"
        "BL sub_FF07AA5C\n"
        "B  loc_FF078EB8\n"
"loc_FF078DB8:\n"
        "BL sub_FF0794AC\n"
        "B  loc_FF078EB8\n"
"loc_FF078DC0:\n"
        "BL sub_FF191970\n"
        "B  loc_FF078EB8\n"
"loc_FF078DC8:\n"
        "BL sub_FF191B84\n"
        "B  loc_FF078EB8\n"
"loc_FF078DD0:\n"
        "BL sub_FF191C1C\n"
        "B  loc_FF078EB8\n"
"loc_FF078DD8:\n"
        "BL sub_FF191D08\n"
        "B  loc_FF078EB8\n"
"loc_FF078DE0:\n"
        "BL sub_FF191DD8\n"
        "B  loc_FF078EB8\n"
"loc_FF078DE8:\n"
        "MOV    R0, #0\n"
        "B  loc_FF078E0C\n"
"loc_FF078DF0:\n"
        "BL sub_FF192260\n"
        "B  loc_FF078EB8\n"
"loc_FF078DF8:\n"
        "BL sub_FF1922F8\n"
        "B  loc_FF078EB8\n"
"loc_FF078E00:\n"
        "BL sub_FF1923D8\n"
        "B  loc_FF078EB8\n"
"loc_FF078E08:\n"
        "MOV    R0, #1\n"
"loc_FF078E0C:\n"
        "BL sub_FF1920F8\n"
        "B  loc_FF078EB8\n"
"loc_FF078E14:\n"
        "BL sub_FF0799D8\n"
        "B  loc_FF078EB8\n"
"loc_FF078E1C:\n"
        "BL sub_FF079A18\n"
        "BL sub_FF193DA4\n"
        "B  loc_FF078EB8\n"
"loc_FF078E28:\n"
        "BL sub_FF191F5C\n"
        "B  loc_FF078EB8\n"
"loc_FF078E30:\n"
        "BL sub_FF192028\n"
        "B  loc_FF078EB8\n"
"loc_FF078E38:\n"
        "BL sub_FF193E70\n"
        "B  loc_FF078EB8\n"
"loc_FF078E40:\n"
        "BL sub_FF0282DC\n"
        "B  loc_FF078EB8\n"
"loc_FF078E48:\n"
        "BL sub_FF07CEA4\n"
        "B  loc_FF078EB8\n"
"loc_FF078E50:\n"
        "BL sub_FF07CF28\n"
        "B  loc_FF078EB8\n"
"loc_FF078E58:\n"
        "BL sub_FF192510\n"
        "B  loc_FF078EB8\n"
"loc_FF078E60:\n"
        "BL sub_FF192574\n"
        "B  loc_FF078EB8\n"
"loc_FF078E68:\n"
        "BL sub_FF07CF84\n"
        "BL sub_FF07CF44\n"
        "B  loc_FF078EB8\n"
"loc_FF078E74:\n"
        "MOV    R0, #1\n"
        "BL     sub_FF1938E4\n"
        "MOV    R0, #1\n"
        "BL     sub_FF193A18\n"
        "LDRH   R0, [R5,#0xA0]\n"
        "CMP    R0, #4\n"
        "LDRNEH R0, [R5]\n"
        "SUBNE  R1, R0, #0x4200\n"
        "SUBNES R1, R1, #0x2A\n"
        "BNE    loc_FF078EB8\n"
        "BL     sub_FF07CF28\n"
        "BL     sub_FF07D56C\n"
        "BL     sub_FF07D3A8\n"
        "B      loc_FF078EB8\n"
"loc_FF078EAC:\n"
        "LDR    R1, =0x5DB\n"
        "LDR    R0, =0xFF07861C\n"  //"SsShootTask.c"
        "BL     sub_FF00EC88\n"     //Assert
"loc_FF078EB8:\n"
        "LDR    R0, [SP]\n"
        "LDR    R1, [R0,#4]\n"
        "LDR    R0, [R7]\n"
        "BL     sub_FF083C90\n"
        "LDR    R4, [SP]\n"
        "LDR    R0, [R4,#8]\n"
        "CMP    R0, #0\n"
        "LDREQ  R0, =0xFF07861C\n"  //"SsShootTask.c"
        "MOVEQ  R1, #0x118\n"
        "BLEQ   sub_FF00EC88\n"     //Assert
        "STR    R6, [R4,#8]\n"
        "B      loc_FF078C00\n"
 //  End of function sub_FF078BF0
    );
}

//SX230 @FF192E78
void __attribute__((naked,noinline)) sub_FF192E78_my(){
    asm volatile(
    //"//sub_FF192E78               \n"
        "STMFD  SP!, {R3-R7,LR}\n"
        "LDR    R5, =0x3EFA4\n"
        "MOV    R4, R0\n"
        "LDR    R0, [R5,#0x28]\n"
        "LDR    R6, =0x420C\n"
        "CMP    R0, #0\n"
        "MOV    R7, #0\n"
        "BNE    loc_FF192F08\n"
        "LDR    R0, [R5,#0xC4]\n"
        "CMP    R0, #1\n"
        "BNE    loc_FF192EF0\n"
        "LDRH   R0, [R5]\n"
        "CMP    R0, R6\n"
        "LDRNEH R0, [R5,#0x9E]\n"
        "CMPNE  R0, #3\n"
        "LDRNE  R0, [R4,#8]\n"
        "CMPNE  R0, #1\n"
        "BLS    loc_FF192ED4\n"
        "BL sub_FF022D98\n"
        "TST    R0, #1\n"
        "BEQ    loc_FF192F08\n"
        "BL sub_FF07ECD8\n"
        "B  loc_FF192F00\n"
"loc_FF192ED4:\n"
        "MOV    R0, #0xC\n"
        "BL sub_FF07EC78\n"
        "TST    R0, #1\n"
        "BEQ    loc_FF192F08\n"
        "BL sub_FF193760\n"
        "BL sub_FF0768E4\n"
        "B  loc_FF192F00\n"
"loc_FF192EF0:          \n"
        "MOV    R0, #0xC\n"
        "BL sub_FF07EC78\n"
        "TST    R0, #1\n"
        "BEQ    loc_FF192F08\n"
"loc_FF192F00:\n"
        "MOV    R0, #1\n"
        "LDMFD  SP!, {R3-R7,PC}\n"
"loc_FF192F08:\n"
        "LDRH   R0, [R5]\n"
        "CMP    R0, R6\n"
        "LDRNEH R0, [R5,#0x9E]\n"
        "CMPNE  R0, #3\n"
        "LDRNE  R0, [R4,#8]\n"
        "CMPNE  R0, #1\n"
        "BLS    loc_FF192F38\n"
        "LDRH   R0, [R5,#0x9C]\n"
        "CMP    R0, #0\n"
        "LDREQH R0, [R5,#0x98]\n"
        "CMPEQ  R0, #2\n"
        "BLEQ   sub_FF079AE4\n"
"loc_FF192F38:\n"
        "LDRH   R1, [R5]\n"
        "LDRH   R0, [R5,#0x9E]\n"
        "CMP    R1, R6\n"
        "BEQ    loc_FF192F78\n"
        "CMP    R0, #3\n"
        "BEQ    loc_FF192FB8\n"
        "LDR    R0, [R4,#8]\n"
        "CMP    R0, #1\n"
        "BLS    loc_FF192F80\n"
        "LDRH   R0, [R5,#0x9C]\n"
        "CMP    R0, #0\n"
        "BNE    loc_FF192FB8\n"
        "LDRH   R0, [R5,#0x98]\n"
        "CMP    R0, #2\n"
        "BEQ    loc_FF192FB4\n"
        "B  loc_FF192F8C\n"
"loc_FF192F78:\n"
        "CMP    R0, #3\n"
        "BEQ    loc_FF192FB8\n"
"loc_FF192F80:\n"
        "LDRH   R0, [R5,#0x9C]\n"
        "CMP    R0, #0\n"
        "BNE    loc_FF192FB8\n"
"loc_FF192F8C:\n"
        "LDRH   R0, [R5,#0x98]\n"
        "CMP    R0, #1\n"
        "BNE    loc_FF192FB8\n"
        "CMP    R1, R6\n"
        "LDRNE  R0, [R4,#8]\n"
        "CMPNE  R0, #1\n"
        "BLS    loc_FF192FB8\n"
        "LDR    R0, [R4,#0xC]\n"
        "CMP    R0, #1\n"
        "BNE    loc_FF192FB8\n"
"loc_FF192FB4:\n"
        "BL sub_FF193EA8\n"
"loc_FF192FB8:\n"
        "BL sub_FF193E70\n"
        "BL sub_FF0794BC\n"
        "LDR    R0, [R5,#0x28]\n"
        "CMP    R0, #0\n"
        "BNE    loc_FF193084\n"
        "BL    shooting_set_flash_override\n"
        "MOV    R0, R4\n"
        "BL sub_FF1926EC\n"
        "TST    R0, #1\n"
        "LDMNEFD    SP!, {R3-R7,PC}\n"
        "MOV    R0, R4\n"
        "BL     sub_FF192B50\n"
        "BL     sub_FF1936A4\n"
        "LDR    R0, [R5,#0xC4]\n"
        "CMP    R0, #1\n"
        "BNE    loc_FF193010\n"
        "LDRH   R0, [R5]\n"
        "CMP    R0, R6\n"
        "LDRNEH R0, [R5,#0x9E]\n"
        "CMPNE  R0, #3\n"
        "LDRNE  R0, [R4,#8]\n"
        "CMPNE  R0, #1\n"
        "BHI    loc_FF193018\n"
"loc_FF193010:              \n"
        "MOV    R0, #2\n"
        "BL     sub_FF0805B4\n"
//PATCH BEGIN
        "BL      wait_until_remote_button_is_released\n"
        "BL      capt_seq_hook_set_nr\n"
//PATCH END
"loc_FF193018:              \n"
        "LDRH   R0, [R5]\n"
        "SUB    R1, R0, #0x4200\n"
        "SUBS   R1, R1, #0x2D\n"
        "BNE    loc_FF193074\n"
        "MOV    R5, #1\n"
        "MOV    R2, #2\n"
        "MOV    R1, SP\n"
        "ADD    R0, R2, #0x15C\n"
        "STR    R5, [SP]\n"
        "BL     sub_FF08BF50\n"
        "TST    R0, #1\n"
        "MOVNE  R1, #0xBC\n"
        "LDRNE  R0, =0xFF1931A0\n"
        "BLNE   sub_FF00EC88\n"
        "LDRH   R0, [SP]\n"
        "CMP    R0, #1\n"
        "BLS    loc_FF19306C\n"
        "MOV    R0, R4\n"
        "STR    R5, [R4,#0xE4]\n"
        "BL     sub_FF3100F4\n"
        "B      loc_FF19307C\n"
"loc_FF19306C:\n"
        "MOV    R0, #0\n"
        "STR    R0, [R4,#0xE4]\n"
"loc_FF193074:\n"
        "MOV    R0, R4\n"
        "BL     sub_FF30FD34\n"
"loc_FF19307C:\n"
        "MOV    R7, R0\n"
        "B  loc_FF193094\n"
"loc_FF193084:\n"
        "LDR    R0, =0x8A08\n"
        "LDR    R0, [R0]\n"
        "CMP    R0, #0\n"
        "MOVNE  R7, #0x1D\n"
"loc_FF193094:              \n"
        "MOV    R0, R7\n"
        "LDMFD  SP!, {R3-R7,PC}\n"
// "End of function sub_FF192E78\n"
    );
}

