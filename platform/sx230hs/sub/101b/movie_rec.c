#include "conf.h"

void change_video_tables(int a, int b){
}



#include "../../../../include/platform.h"
extern volatile enum _VideoMode VideoMode;
extern unsigned char displayedMode;


void  set_quality(int *x){ // -17 highest; +12 lowest

       gFramesRecorded++;
if((gFramesRecorded==30)&&conf.camera_position&&(displayedMode==6))play_sound(4);

if(VideoMode==VIDEO_BURST){if((gFrameCount--)<2)gStopVideoCapture=1;}
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

void __attribute__((naked,noinline)) movie_record_task(){
    asm volatile(
//"sub_FF18D9CC"
                "STMFD  SP!, {R2-R10,LR}\n"
                "LDR    R6, =0xFF18C73C\n"
//PATCH BEGIN
//      "LDR    R7, =sub_FF18D424\n"
        "LDR    R7, =sub_FF18D424_my\n"
//PATCH END
                "LDR    R4, =0x85E0\n"
                "LDR    R9, =0x67F\n"
                "LDR    R10, =0x2710\n"
                "MOV    R8, #1\n"
                "MOV    R5, #0\n"
"loc_FF18D9EC:\n"
                "LDR    R0, [R4, #0x24]\n"
                "MOV    R2, #0\n"
                "ADD    R1, SP, #4\n"
                "BL sub_FF02B184\n"
                "LDR    R0, [R4, #0x2C]\n"
                "CMP    R0, #0\n"
                "LDRNE  R0, [R4, #0xC]\n"
                "CMPNE  R0, #2\n"
                "LDRNE  R0, [R4, #0x44]\n"
                "CMPNE  R0, #6\n"
                "BNE    loc_FF18DB28\n"
                "LDR    R0, [SP, #4]\n"
                "LDR    R1, [R0]\n"
                "SUB    R1, R1, #2\n"
                "CMP    R1, #0xD\n"
                "ADDCC  PC, PC, R1, LSL #2\n"
                "B  loc_FF18DB28\n"
                "B  loc_FF18DAC8\n"
                "B  loc_FF18DAEC\n"
                "B  loc_FF18DAFC\n"
                "B  loc_FF18DB04\n"
                "B  loc_FF18DB0C\n"
                "B  loc_FF18DB14\n"
                "B  loc_FF18DAD0\n"
                "B  loc_FF18DB1C\n"
                "B  loc_FF18DADC\n"
                "B  loc_FF18DB28\n"
                "B  loc_FF18DB24\n"
                "B  loc_FF18DA94\n"
                "B  loc_FF18DA64\n"
"loc_FF18DA64:\n"
                "STR    R5, [R4, #0x40]\n"
                "STR    R5, [R4, #0x30]\n"
                "STR    R5, [R4, #0x34]\n"
                "STRH   R5, [R4, #6]\n"
                "STR    R6, [R4, #0xD8]\n"
                "STR    R7, [R4, #0xF0]\n"
                "LDR    R0, [R4, #0xC]\n"
                "ADD    R0, R0, #1\n"
                "STR    R0, [R4, #0xC]\n"
                "MOV    R0, #6\n"
                "STR    R0, [R4, #0x44]\n"
                "B  loc_FF18DAB4\n"
"loc_FF18DA94:\n"
                "STR    R5, [R4, #0x40]\n"
                "STR    R5, [R4, #0x30]\n"
                "STR    R6, [R4, #0xD8]\n"
                "STR    R7, [R4, #0xF0]\n"
                "LDR    R0, [R4, #0xC]\n"
                "ADD    R0, R0, #1\n"
                "STR    R0, [R4, #0xC]\n"
                "STR    R8, [R4, #0x44]\n"
"loc_FF18DAB4:\n"
                "LDR    R2, =0xFF18BD78\n"
                "LDR    R1, =0xC6A08\n"
                "LDR    R0, =0xFF18BE8C\n"
                "BL sub_FF0453E0\n"
                "B  loc_FF18DB28\n"
"loc_FF18DAC8:\n"
//              "BL sub_FF18D008_my\n"
                "BL     movie_time\n"
"label_A:\n"
                "B  loc_FF18DB28\n"
"loc_FF18DAD0:\n"
                "LDR    R1, [R4, #0xF0]\n"
                "BLX    R1\n"
                "B  loc_FF18DB28\n"
"loc_FF18DADC:\n"
                "LDR    R1, [R0, #0x18]\n"
                "LDR    R0, [R0, #4]\n"
                "BL sub_FF306D88\n"
                "B  loc_FF18DB28\n"
"loc_FF18DAEC:\n"
                "LDR    R0, [R4, #0x44]\n"
                "CMP    R0, #5\n"
                "STRNE  R8, [R4, #0x34]\n"
                "B  loc_FF18DB28\n"
"loc_FF18DAFC:\n"
                "BL sub_FF18C418\n"
                "B  loc_FF18DB28\n"
"loc_FF18DB04:\n"
                "BL sub_FF18C12C\n"
                "B  loc_FF18DB28\n"
"loc_FF18DB0C:\n"
                "BL sub_FF18BEE4\n"
                "B  loc_FF18DB28\n"
"loc_FF18DB14:\n"
                "BL sub_FF18BB0C\n"
                "B  loc_FF18DB28\n"
"loc_FF18DB1C:\n"
                "BL sub_FF18BA8C\n"
                "B  loc_FF18DB28\n"
"loc_FF18DB24:\n"
                "BL sub_FF18E078\n"
"loc_FF18DB28:\n"
                "LDR    R1, [SP, #4]\n"
                "LDR    R3, =0xFF18B7F0\n"
                "STR    R5, [R1]\n"
                "STR    R9, [SP]\n"
                "LDR    R0, [R4, #0x28]\n"
                "MOV    R2, R10\n"
                "BL sub_FF02BAFC\n"
                "B  loc_FF18D9EC\n"

// "End of function sub_FF18D9CC\n"
        );
}

void __attribute__((naked,noinline)) movie_time()
{
/*
 if( (int)conf.ext_video_time == 1 )
{
asm volatile (
                "BL     sub_FF18D008_my\n"
                "B      label_A\n"
             );
}
else
{
*/
asm volatile (
                "BL     sub_FF18D008\n"
                "B      label_A\n"
             );
//}

}

void __attribute__((naked,noinline)) sub_FF18D008_my(  ) {
asm volatile (
                "STMFD  SP!, {R0-R8,LR}\n"
                "LDR    R6, =0x85E0\n"
                "MOV    R0, #0\n"
                "STR    R0, [R6, #0x34]\n"
                "STR    R0, [R6, #0x38]\n"
                "ADD    R0, R6, #0\n"
                "LDR    R0, [R0, #0x5C]\n"
                "LDRH   R1, [R6, #6]\n"
                "MOV    R3, #0x3E8\n"
                "MUL    R0, R3, R0\n"
                "CMP    R1, #0\n"
                "MOV    R2, #1\n"
                "BNE    loc_FF18D04C\n"
                "LDR    R1, [R6, #0x90]\n"
                "CMP    R1, #0\n"
                "BNE    loc_FF18D05C\n"
                "B  loc_FF18D054\n"
"loc_FF18D04C:\n"
                "CMP    R1, #3\n"
                "BNE    loc_FF18D05C\n"
"loc_FF18D054:\n"
                "STR    R2, [R6, #0x48]\n"
                "B  loc_FF18D068\n"
"loc_FF18D05C:\n"
                "MOV    R1, #0x3E8\n"
                "BL sub_FF3B62EC\n"
                "STR    R0, [R6, #0x48]\n"
"loc_FF18D068:\n"
                "LDR    R4, =0xC6A3C\n"
                "MOV    R7, #2\n"
                "LDR    R0, [R4, #8]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18D0D0\n"
                "LDR    R0, [R6, #0x58]\n"
                "MOV    R1, #4\n"
                "CMP    R0, #0x18\n"
                "BEQ    loc_FF18D264\n"
                "BGT    loc_FF18D0AC\n"
                "CMP    R0, #0xA\n"
                "CMPNE  R0, #0xF\n"
                "STREQ  R7, [R4, #0x14]\n"
                "BEQ    loc_FF18D0D0\n"
                "CMP    R0, #0x14\n"
                "BNE    loc_FF18D0C4\n"
                "B  loc_FF18D264\n"
"loc_FF18D0AC:\n"
                "CMP    R0, #0x1E\n"
                "BEQ    loc_FF18D264\n"
                "CMP    R0, #0x3C\n"
                "MOVEQ  R0, #8\n"
                "STREQ  R0, [R4, #0x14]\n"
                "BEQ    loc_FF18D0D0\n"
"loc_FF18D0C4:\n"
                "LDR    R1, =0x777\n"
                "LDR    R0, =0xFF18B7F0\n"
                "BL sub_FF00EC88\n"
"loc_FF18D0D0:\n"
                "LDR    R2, =0x85E2\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #2\n"
                "MOV    R1, #0xAA\n"
                "BL sub_FF08C388\n"
                "LDR    R2, =0x85E4\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #2\n"
                "MOV    R1, #0xA9\n"
                "BL sub_FF08C388\n"
                "LDR    R2, =0x8630\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #4\n"
                "MOV    R1, #0xA2\n"
                "BL sub_FF08C388\n"
                "LDR    R2, =0x8634\n"
                "LDR    R0, [R6, #0xB8]\n"
                "MOV    R3, #4\n"
                "MOV    R1, #0xA3\n"
                "BL sub_FF08C388\n"
                "LDR    R0, [R6, #0x90]\n"
                "CMP    R0, #0\n"
                "LDRNE  R2, =0x86E0\n"
                "MOVNE  R1, #0\n"
                "MOVNE  R0, #0xD\n"
                "BLNE   sub_FF086854\n"
                "LDR    R0, [R6, #0x4C]\n"
                "LDR    R5, =0x86E0\n"
                "LDR    R8, =0xC6A24\n"
                "CMP    R0, #2\n"
                "CMPNE  R0, #3\n"
                "BNE    loc_FF18D1CC\n"
                "LDR    R0, [R6, #0x90]\n"
                "CMP    R0, #0\n"
                "LDRNE  R0, =0x443FC000\n"
                "STRNE  R0, [R5]\n"
                "BNE    loc_FF18D1CC\n"
                "LDR    R0, =0x460B8600\n"
                "LDR    R1, =0x10959E0\n"
                "STR    R0, [R5]\n"
                "STR    R1, [R5, #4]\n"
                "LDMIA  R8, {R1,R2}\n"
                "STR    R0, [R6, #0xA0]\n"
                "MUL    R1, R2, R1\n"
                "MOV    R2, #0\n"
                "MOV    R3, R1, LSL #1\n"
                "ADD    R1, R0, R3\n"
                "STR    R3, [R6, #0x9C]\n"
                "STR    R1, [R6, #0xA4]\n"
                "STMEA  SP, {R1-R3}\n"
                "MOV    R3, R2\n"
                "MOV    R2, #9\n"
                "MOV    R1, #5\n"
                "MOV    R0, #0x10\n"
                "BL sub_FF2B0A24\n"
                "LDR    R1, [R5]\n"
                "LDR    R0, [R6, #0x9C]\n"
                "ADD    R1, R1, R0, LSL #1\n"
                "STR    R1, [R5]\n"
                "LDR    R1, [R5, #4]\n"
                "RSB    R0, R0, #0\n"
                "ADD    R0, R1, R0, LSL #1\n"
                "STR    R0, [R5, #4]\n"
"loc_FF18D1CC:\n"
                "LDR    R3, =0xFF18CFD4\n"
                "LDMIA  R5, {R0,R1}\n"
                "STR    R3, [SP]\n"
                "LDR    R3, =0xC6A3C\n"
                "SUB    R2, R3, #0x18\n"
                "BL sub_FF3056D8_my\n"
                "LDR    R3, [R6, #0xB8]\n"
                "STR    R3, [SP]\n"
                "LDR    R0, [R6, #0x90]\n"
                "STRD   R2, [R6, #0xF8]\n"
                "BL sub_FF305AE8\n"
                "LDR    R0, [R6, #0x64]\n"
                "LDR    R3, =0x8668\n"
                "AND    R1, R0, #0xFF\n"
                "LDR    R0, [R8]\n"
                "SUB    R2, R3, #4\n"
                "BL sub_FF303404\n"
                "LDRH   R0, [R6, #6]\n"
                "CMP    R0, #2\n"
                "LDREQ  R0, =0xFF18CCA8\n"
                "STREQ  R0, [R6, #0xF0]\n"
                "LDR    R0, [R6, #0x90]\n"
                "CMP    R0, #0\n"
                "LDREQ  R1, =0xFF18C8EC\n"
                "STREQ  R1, [R6, #0xF0]\n"
                "LDR    R2, [R6, #0xC]\n"
                "LDR    R1, =0xFF414814\n"
                "CMP    R2, #2\n"
                "BNE    loc_FF18D26C\n"
                "LDR    R0, [R6, #0x4C]\n"
                "ADD    R0, R1, R0, LSL #3\n"
                "LDR    R1, [R8, #0xC]\n"
                "LDR    R0, [R0, R1, LSL #2]\n"
                "BL sub_FF2B6AC0\n"
                "LDR    R0, =0xFF18C818\n"
                "MOV    R1, #0\n"
                "BL sub_FF2B6FD4\n"
                "B  loc_FF18D2A8\n"
"loc_FF18D264:\n"
                "STR    R1, [R4, #0x14]\n"
                "B  loc_FF18D0D0\n"
"loc_FF18D26C:\n"
                "CMP    R0, #0\n"
                "BNE    loc_FF18D288\n"
                "LDR    R1, [R6, #0x98]\n"
                "MOV    R0, #5\n"
                "BL sub_FF2B6FE8\n"
                "BL sub_FF2B7078\n"
                "B  loc_FF18D2A8\n"
"loc_FF18D288:\n"
                "LDR    R0, [R6, #0x4C]\n"
                "ADD    R0, R1, R0, LSL #3\n"
                "LDR    R1, [R8, #0xC]\n"
                "LDR    R0, [R0, R1, LSL #2]\n"
                "BL sub_FF2B5250\n"
                "LDR    R0, =0xFF18C818\n"
                "MOV    R1, #0\n"
                "BL sub_FF2B599C\n"
"loc_FF18D2A8:\n"
                "LDR    R0, [R4, #8]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18D2DC\n"
                "ADD    R0, SP, #0xC\n"
                "BL sub_FF306C04\n"
                "LDR    R1, [R4, #0xC]\n"
                "LDR    R0, [SP, #0xC]\n"
                "BL sub_FF05D07C\n"
                "ADD    R0, SP, #0xC\n"
                "BL sub_FF306C04\n"
                "LDR    R1, [R4, #0xC]\n"
                "LDR    R0, [SP, #0xC]\n"
                "BL sub_FF05D07C\n"
"loc_FF18D2DC:\n"
                "LDR    R0, =0xFF18C7D0\n"
                "STR    R7, [R6, #0x44]!\n"
                "STR    R0, [R6, #0x94]\n"
                "LDMFD  SP!, {R0-R8,PC}\n"
    );
}

void __attribute__((naked,noinline)) sub_FF3056D8_my(  ) {
asm volatile (

                "STMFD  SP!, {R0-R12,LR}\n"
                "MOV    R9, R0\n"
                "LDR    R0, [R2, #0x10]\n"
                "LDR    R8, [SP, #0x38]\n"
                "CMP    R0, #0\n"
                "LDREQ  R1, =0x32A\n"
                "LDREQ  R0, =0xFF3042EC\n"
                "MOV    R5, #0\n"
                "MOV    R4, R2\n"
                "MOV    R10, R3\n"
                "MOV    R7, R5\n"
                "BLEQ   sub_FF00EC88\n"
                "LDR    R6, =0xDE88\n"
                "LDR    R0, [R4]\n"
                "MOV    R11, #0x1E\n"
                "STR    R0, [R6, #0xD0]\n"
                "LDR    R0, [R4, #4]\n"
                "STR    R0, [R6, #0xD4]\n"
                "LDR    R0, [R4, #0x10]\n"
                "STR    R0, [R6, #0xE0]\n"
                "LDR    R1, [R4, #8]\n"
                "LDR    R0, =0x7530\n"
                "CMP    R1, #0xB\n"
                "ADDCC  PC, PC, R1, LSL #2\n"
                "B  loc_FF3057C4\n"
                "B  loc_FF305778\n"
                "B  loc_FF305768\n"
                "B  loc_FF3057A0\n"
                "B  loc_FF3057B4\n"
                "B  loc_FF3057C4\n"
                "B  loc_FF3057C4\n"
                "B  loc_FF3057C4\n"
                "B  loc_FF3057C4\n"
                "B  loc_FF305798\n"
                "B  loc_FF305790\n"
                "B  loc_FF305780\n"
"loc_FF305768:\n"
                "LDR    R7, =0x5DC0\n"
                "MOV    R0, #0x18\n"
                "STR    R7, [R6, #0x12C]\n"
                "B  loc_FF3057AC\n"
"loc_FF305778:\n"
                "MOV    R7, R0\n"
                "B  loc_FF305784\n"
"loc_FF305780:\n"
                "LDR    R7, =0x5DC\n"
"loc_FF305784:\n"
                "STR    R0, [R6, #0x12C]\n"
                "STR    R11, [R6, #0xD8]\n"
                "B  loc_FF3057D0\n"
"loc_FF305790:\n"
                "LDR    R7, =0xBB8\n"
                "B  loc_FF305784\n"
"loc_FF305798:\n"
                "LDR    R7, =0x1770\n"
                "B  loc_FF305784\n"
"loc_FF3057A0:\n"
//              "LDR    R7, =0x3A980\n"
                "LDR    R6, =0xFFFFFFFE\n"           //240fps video time limit
                "STR    R0, [R6, #0x12C]\n"
                "MOV    R0, #0xF0\n"
"loc_FF3057AC:\n"
                "STR    R0, [R6, #0xD8]\n"
                "B  loc_FF3057D0\n"
"loc_FF3057B4:\n"
                "STR    R0, [R6, #0x12C]\n"
//              "LDR    R7, =0x1D4C0\n"
                "LDR    R6, =0xFFFFFFFE\n"           //120fps video time limit
                "MOV    R0, #0x78\n"
                "B  loc_FF3057AC\n"
"loc_FF3057C4:\n"
                "LDR    R1, =0x35B\n"
                "LDR    R0, =0xFF3042EC\n"
                "BL sub_FF00EC88\n"
"loc_FF3057D0:\n"
                "LDR    R0, [R6, #0xD8]\n"
//              "LDR    R1, =0xE0F\n"
                "LDR    R1, =0xFD20\n"               //240p, 480p video time limit 0xFD20(~18hr)
                "MOV    R0, R0, LSR #1\n"
                "STR    R0, [R6, #0xDC]\n"
                "LDR    R0, [R10]\n"
                "STR    R0, [R6, #0xE4]\n"
                "LDRH   R0, [R10, #0x10]\n"
                "STR    R0, [R6, #0xE8]\n"
                "LDR    R0, [R10, #4]\n"
                "STRH   R0, [R6, #2]\n"
                "LDR    R0, [R10, #8]\n"
                "STRH   R0, [R6, #4]\n"
                "LDR    R0, [R10, #0x14]\n"
                "STR    R0, [R6, #0xEC]\n"
                "STR    R8, [R6, #0x128]\n"
                "LDR    R0, [R6, #0xD0]\n"
                "CMP    R0, #0x140\n"
                "MOVEQ  R0, #0x20000\n"
                "MOVEQ  R5, #1\n"
                "STREQ  R0, [R6, #0xAC]\n"
                "BEQ    loc_FF305864\n"
                "CMP    R0, #0x280\n"
                "LDREQ  R0, =0x7A760\n"
                "MOVEQ  R5, #2\n"
                "STREQ  R0, [R6, #0xAC]\n"
                "BEQ    loc_FF305864\n"
                "CMP    R0, #0x500\n"
                "LDREQ  R0, =0x11DA50\n"
//              "LDR    R1, =0x707\n"
                "LDR    R1, =0xFFE\n"                   //720p, 1080p video time limit 0xFFE(~68min)
                "MOVEQ  R5, #4\n"
                "STREQ  R0, [R6, #0xAC]\n"
                "BEQ    loc_FF305864\n"
                "CMP    R0, #0x780\n"
                "BNE    loc_FF30586C\n"
                "MOV    R0, #0x200000\n"
                "MOV    R5, #5\n"
                "STR    R0, [R6, #0xAC]\n"
"loc_FF305864:\n"
                "STR    R1, [R6, #0x4C]\n"
                "B  loc_FF305878\n"
"loc_FF30586C:\n"
                "LDR    R1, =0x383\n"
                "LDR    R0, =0xFF3042EC\n"
                "BL sub_FF00EC88\n"
"loc_FF305878:\n"
                "LDR    R0, [R6, #0x4C]\n"
                "LDR    R1, =0x138D\n"
                "MUL    R0, R7, R0\n"
                "BL sub_FF3B62EC\n"
                "ADD    R0, R0, #1\n"
                "ADD    R0, R0, R0, LSL #2\n"
                "STR    R0, [R6, #0x48]\n"
                "LDR    R8, [R4, #8]\n"
                "CMP    R8, #2\n"
                "CMPNE  R8, #3\n"
                "BNE    loc_FF3058D0\n"
                "RSB    R0, R7, R7, LSL #4\n"
                "LDR    R1, =0x3E9\n"
                "MOV    R0, R0, LSL #1\n"
                "STR    R11, [R6, #0x4C]\n"
                "BL sub_FF3B62EC\n"
                "LDR    R1, [R6, #0xE0]\n"
                "MOV    R7, R1\n"
                "BL sub_FF3B62EC\n"
                "ADD    R0, R0, #1\n"
                "MUL    R0, R7, R0\n"
                "STR    R0, [R6, #0x48]\n"
"loc_FF3058D0:\n"
                "LDR    R0, [R4, #0xC]\n"
                "LDR    R7, [R10, #0xC]\n"
                "ADDS   R1, R0, #0\n"
                "MOV    R0, R7, LSR #1\n"
                "STR    R7, [R6, #0x94]\n"
                "STR    R0, [R6, #0x98]\n"
                "ADD    R0, R9, #3\n"
                "BIC    R0, R0, #3\n"
                "STR    R0, [R6, #0xF4]\n"
                "LDR    R2, [R6, #0x48]\n"
                "MOVNE  R1, #1\n"
                "MOV    R2, R2, LSL #2\n"
                "ADD    R3, R0, R2\n"
                "STR    R3, [R6, #0xF8]\n"
                "LDRH   R12, [R6, #4]\n"
                "LDR    R0, [SP, #4]\n"
                "ADD    R2, R2, R3\n"
                "CMP    R12, #0\n"
                "ADD    R0, R0, R9\n"
                "BEQ    loc_FF305A48\n"
                "STR    R2, [R6, #0xFC]\n"
                "LDR    R3, [R6, #0x4C]\n"
                "LDR    R9, =0x11D628\n"
                "ADD    R2, R2, R3, LSL #3\n"
                "ADD    R2, R2, #0x1F\n"
                "BIC    R2, R2, #0x1F\n"
                "STR    R2, [R6, #0x100]\n"
                "LDR    R3, [R6, #0xAC]\n"
                "LDR    R11, =0xE008\n"
                "ADD    R2, R2, R3\n"
                "ADD    R3, R2, #0x100000\n"
                "STR    R2, [R6, #0x78]\n"
                "SUB    R0, R0, R3\n"
                "RSB    R2, R7, #0\n"
                "ADD    R0, R0, R2, LSL #1\n"
                "MOV    R0, R0, LSR #0xF\n"
                "MOV    R0, R0, LSL #0xF\n"
                "STR    R3, [R6, #0x104]\n"
                "ADD    R8, R3, R0\n"
                "STR    R0, [R6, #0x110]\n"
                "STR    R8, [R6, #0x108]\n"
                "MOV    R2, #0\n"
                "ADD    R10, R9, #0x10\n"
                "STR    R8, [R6, #0x10C]\n"
"loc_FF305980:\n"
                "MLA    R0, R2, R7, R8\n"
                "ADD    R12, R9, R2, LSL #3\n"
                "ADD    R0, R0, #3\n"
                "BIC    R0, R0, #3\n"
                "STR    R0, [R11, R2, LSL #2]\n"
                "MOV    R0, #0\n"
                "ADD    R6, R10, R2, LSL #3\n"
"loc_FF30599C:\n"
                "STR    R3, [R12, R0, LSL #2]\n"
                "STR    R3, [R6, R0, LSL #2]\n"
                "ADD    R0, R0, #1\n"
                "CMP    R0, #2\n"
                "BLT    loc_FF30599C\n"
                "ADD    R2, R2, #1\n"
                "CMP    R2, #2\n"
                "BLT    loc_FF305980\n"
                "LDRH   R3, [R4, #0x14]\n"
                "LDR    R2, [R4, #8]\n"
                "MOV    R0, R5\n"
                "BL sub_FF0DA840\n"
                "LDR    R1, =0xDE88\n"
                "LDR    R2, [R1, #0x94]\n"
                "ADD    R0, R0, R2\n"
                "STR    R0, [R1, #0x8C]\n"
                "LDMFD  SP!, {R0-R12,PC}\n"
//                "STRVSBT  R7, [R8], #-0x66D\n"
//                "ANDEQ    LR, R0, R0, LSR #0x20\n"
"loc_FF305A48:\n"
                "ADD    R2, R2, #0x1F\n"
                "BIC    R2, R2, #0x1F\n"
                "STR    R2, [R6, #0x100]\n"
                "LDR    R3, [R6, #0xAC]\n"
                "ADD    R2, R2, R3\n"
                "SUB    R0, R0, R2\n"
                "MOV    R0, R0, LSR #0xF\n"
                "MOV    R0, R0, LSL #0xF\n"
                "STR    R2, [R6, #0x104]\n"
                "STR    R0, [R6, #0x110]\n"
                "ADD    R0, R0, R2\n"
                "STR    R0, [R6, #0x108]\n"
                "LDRH   R3, [R4, #0x14]\n"
                "MOV    R2, R8\n"
                "MOV    R0, R5\n"
                "BL sub_FF0DA840\n"
                "STR    R0, [R6, #0x8C]\n"
                "LDMFD  SP!, {R0-R12,PC}\n"
    );
}

void __attribute__((naked,noinline)) sub_FF18D424_my(){
    asm volatile(
//"sub_FF18D424             \n"
                "STMFD  SP!, {R4-R11,LR}\n"
                "SUB    SP, SP, #0x64\n"
                "MOV    R9, #0\n"
                "LDR    R8, =0x85E0\n"
                "STR    R9, [SP, #0x54]\n"
                "STR    R9, [SP, #0x4C]\n"
                "STR    R9, [R8, #0xDC]\n"
                "STR    R9, [R8, #0xE0]\n"
                "STR    R9, [R8, #0xE4]\n"
                "MOV    R4, R0\n"
                "STR    R9, [R8, #0xE8]\n"
                "LDR    R0, [R8, #0x44]\n"
                "MOV    R7, R9\n"
                "CMP    R0, #3\n"
                "MOVEQ  R0, #4\n"
                "STREQ  R0, [R8, #0x44]\n"
                "LDR    R0, [R8, #0xD8]\n"
                "MOV    R5, #1\n"
                "MOV    R6, R9\n"
                "BLX    R0\n"
                "LDR    R0, [R8, #0x44]\n"
                "CMP    R0, #6\n"
                "BEQ    loc_FF18D494\n"
                "LDR    R1, [R8, #0xC]\n"
                "CMP    R1, #2\n"
                "BNE    loc_FF18D4BC\n"
                "CMP    R0, #5\n"
                "BEQ    loc_FF18D4CC\n"
"loc_FF18D494:\n"
                "LDR    R2, =0xFF18D2F8\n"
                "LDR    R1, =0xFF18D35C\n"
                "LDR    R0, =0xFF18D3C0\n"
                "MOV    R6, #1\n"
                "ADD    R3, SP, #0x34\n"
                "BL sub_FF0463EC\n"
                "LDR    R0, [R8, #0x44]\n"
                "CMP    R0, #4\n"
                "MOVNE  R5, #0\n"
                "B  loc_FF18D4DC\n"
"loc_FF18D4BC:\n"
                "CMP    R0, #4\n"
                "BEQ    loc_FF18D4DC\n"
                "CMP    R1, #2\n"
                "BNE    loc_FF18D4D4\n"
"loc_FF18D4CC:\n"
                "MOV    R0, #0\n"
                "BL sub_FF0463F8\n"
"loc_FF18D4D4:\n"
                "ADD    SP, SP, #0x64\n"
                "LDMFD  SP!, {R4-R11,PC}\n"
"loc_FF18D4DC:\n"
                "LDRH   R0, [R8, #6]\n"
                "CMP    R0, #3\n"
                "BNE    loc_FF18D4FC\n"
                "LDR    R0, [R8, #0x6C]\n"
                "LDR    R1, [R8, #0xEC]\n"
                "BL sub_FF3B62EC\n"
                "CMP    R1, #0\n"
                "MOVNE  R5, #0\n"
"loc_FF18D4FC:\n"
                "LDR    R0, [R8, #0x44]\n"
                "CMP    R0, #6\n"
                "CMPNE  R0, #1\n"
                "CMPNE  R0, #3\n"
                "BNE    loc_FF18D540\n"
                "CMP    R6, #1\n"
                "CMPEQ  R5, #0\n"
                "BNE    loc_FF18D540\n"
                "BL sub_FF0463F0\n"
                "LDR    R0, [R8, #0x18]\n"
                "MOV    R1, #0x3E8\n"
                "BL sub_FF02B5A0\n"
                "CMP    R0, #9\n"
                "BNE    loc_FF18D948\n"
                "MOV    R0, #0x90000\n"
                "BL sub_FF093424\n"
                "B  loc_FF18D4D4\n"
"loc_FF18D540:\n"
                "CMP    R5, #1\n"
                "MOV    R10, #1\n"
                "BNE    loc_FF18D568\n"
                "ADD    R3, SP, #0x4C\n"
                "ADD    R2, SP, #0x50\n"
                "ADD    R1, SP, #0x54\n"
                "ADD    R0, SP, #0x58\n"
                "BL sub_FF306EB0\n"
                "MOVS   R9, R0\n"
                "BNE    loc_FF18D584\n"
"loc_FF18D568:\n"
                "LDR    R0, [R8, #0x34]\n"
                "CMP    R0, #1\n"
                "BNE    loc_FF18D6C4\n"
                "LDR    R0, [R8, #0x6C]\n"
                "LDR    R1, [R8, #0x48]\n"
                "CMP    R0, R1\n"
                "BCC    loc_FF18D6C4\n"
"loc_FF18D584:\n"
                "MOV    R0, R9\n"
                "BL sub_FF18C8B0\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "BNE    loc_FF18D5F4\n"
                "LDR    R0, =0xFF18D2EC\n"
                "MOV    R1, #0\n"
                "BL sub_FF2B6FD4\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "STRD   R2, [SP, #0x28]\n"
                "MOV    R2, #0x18\n"
                "ADD    R1, SP, #0x34\n"
                "ADD    R0, SP, #0x10\n"
                "BL sub_FF3B5FD0\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "MVN    R3, #1\n"
                "ADD    R0, SP, #0x60\n"
                "STMEA  SP, {R0-R3}\n"
                "MOV    R3, #0\n"
                "LDR    R0, =0xC6A54\n"
                "MOV    R2, R3\n"
                "MOV    R1, #0x40\n"
                "BL sub_FF2B6F20\n"
                "B  loc_FF18D64C\n"
"loc_FF18D5EC:\n"
                "MOV    R1, #1\n"
                "B  loc_FF18D8D8\n"
"loc_FF18D5F4:\n"
                "BL sub_FF18E150\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "MVN    R1, #1\n"
                "MOV    R0, #0\n"
                "ADD    R5, SP, #0x1C\n"
                "STMIA  R5, {R0-R3}\n"
                "LDR    R3, [R4, #0x1C]\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "ADD    R0, SP, #0x60\n"
                "ADD    R4, SP, #0xC\n"
                "STMIA  R4, {R0-R3}\n"
                "MOV    R3, #0\n"
                "MOV    R1, #0x40\n"
                "STMEA  SP, {R1,R3}\n"
                "MOV    R2, #0\n"
                "STR    R3, [SP, #8]\n"
                "LDR    R3, =0xC6A54\n"
                "MOV    R1, R2\n"
                "MOV    R0, R2\n"
                "BL sub_FF2B587C\n"
"loc_FF18D64C:\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL sub_FF02B5A0\n"
                "CMP    R0, #9\n"
                "BEQ    loc_FF18D5EC\n"
                "LDR    R0, [SP, #0x5C]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18D674\n"
"loc_FF18D66C:\n"
                "MOV    R1, #1\n"
                "B  loc_FF18D8F0\n"
"loc_FF18D674:\n"
                "LDR    R0, [R8, #0xC]\n"
                "MOV    R4, #5\n"
                "CMP    R0, #2\n"
                "MOV    R0, #1\n"
                "BNE    loc_FF18D6B0\n"
                "BL sub_FF2B6F94\n"
                "BL sub_FF2B6FBC\n"
                "MOV    R0, #0\n"
                "BL sub_FF0463F8\n"
                "BL sub_FF046408\n"
                "STR    R4, [R8, #0x44]\n"
                "BL sub_FF18E150\n"
                "BL sub_FF046464\n"
                "STR    R10, [R8, #0x44]\n"
                "B  loc_FF18D6BC\n"
"loc_FF18D6B0:\n"
                "BL sub_FF2B592C\n"
                "BL sub_FF2B5978\n"
                "STR    R4, [R8, #0x44]\n"
"loc_FF18D6BC:\n"
                "STR    R7, [R8, #0x34]\n"
                "B  loc_FF18D4D4\n"
"loc_FF18D6C4:\n"
                "CMP    R5, #1\n"
                "BNE    loc_FF18D940\n"
                "STR    R10, [R8, #0x38]\n"
                "LDR    R0, [R8, #0x6C]\n"
                "LDR    R11, [R4, #0xC]\n"
                "CMP    R0, #0\n"
                "LDRNE  R9, [SP, #0x58]\n"
                "LDRNE  R10, [SP, #0x54]\n"
                "BNE    loc_FF18D810\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "BNE    loc_FF18D768\n"
                "LDR    R0, =0xFF18D2EC\n"
                "MOV    R1, #0\n"
                "BL sub_FF2B6FD4\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "STRD   R2, [SP, #0x28]\n"
                "MOV    R2, #0x18\n"
                "ADD    R1, SP, #0x34\n"
                "ADD    R0, SP, #0x10\n"
                "BL sub_FF3B5FD0\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "MVN    R3, #0\n"
                "ADD    R0, SP, #0x60\n"
                "STMEA  SP, {R0-R3}\n"
                "LDR    R0, [SP, #0x58]\n"
                "LDR    R1, [SP, #0x54]\n"
                "LDR    R2, [SP, #0x50]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "BL sub_FF2B6F20\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL sub_FF02B5A0\n"
                "CMP    R0, #9\n"
                "BEQ    loc_FF18D5EC\n"
                "LDR    R0, =0xFF18C818\n"
                "MOV    R1, #0\n"
                "BL sub_FF2B6FD4\n"
                "B  loc_FF18D7D0\n"
"loc_FF18D768:\n"
                "LDR    R0, [R4, #0x20]\n"
                "LDR    R2, [R8, #0x64]\n"
                "ADD    R3, SP, #0x5C\n"
                "MVN    R1, #0\n"
                "ADD    R9, SP, #0x1C\n"
                "STMIA  R9, {R0-R3}\n"
                "LDR    R3, [R4, #0x1C]\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "ADD    R0, SP, #0x60\n"
                "ADD    R9, SP, #0xC\n"
                "STMIA  R9, {R0-R3}\n"
                "LDR    R1, [SP, #0x50]\n"
                "LDR    R2, [SP, #0x54]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "STMFA  SP, {R1,R3}\n"
                "STR    R2, [SP]\n"
                "LDMIB  R4, {R0,R1}\n"
                "LDR    R3, [SP, #0x58]\n"
                "MOV    R2, R11\n"
                "BL sub_FF2B587C\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL sub_FF02B5A0\n"
                "CMP    R0, #9\n"
                "BEQ    loc_FF18D5EC\n"
"loc_FF18D7D0:\n"
                "LDR    R0, [SP, #0x5C]\n"
                "CMP    R0, #0\n"
                "BNE    loc_FF18D66C\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "MOV    R0, #1\n"
                "BNE    loc_FF18D7F4\n"
                "BL sub_FF2B6F94\n"
                "B  loc_FF18D7F8\n"
"loc_FF18D7F4:\n"
                "BL sub_FF2B592C\n"
"loc_FF18D7F8:\n"
                "STR    R7, [R8, #0xE8]\n"
                "LDR    R0, [SP, #0x60]\n"
                "LDR    R1, [SP, #0x58]\n"
                "ADD    R9, R1, R0\n"
                "LDR    R1, [SP, #0x54]\n"
                "SUB    R10, R1, R0\n"
"loc_FF18D810:\n"
                "LDR    R0, [R8, #0xC]\n"
                "LDR    R2, [R8, #0x64]\n"
                "CMP    R0, #2\n"
                "ADD    R3, SP, #0x5C\n"
                "BNE    loc_FF18D868\n"
                "STRD   R2, [SP, #0x28]\n"
                "MOV    R2, #0x18\n"
                "ADD    R1, SP, #0x34\n"
                "ADD    R0, SP, #0x10\n"
                "BL sub_FF3B5FD0\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "LDR    R3, [R8, #0x68]\n"
                "ADD    R0, SP, #0x60\n"
                "STMEA  SP, {R0-R3}\n"
                "LDR    R2, [SP, #0x50]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "MOV    R1, R10\n"
                "MOV    R0, R9\n"
                "BL sub_FF2B6F20\n"
                "BL sub_FF0463F0\n"
                "B  loc_FF18D8C0\n"
"loc_FF18D868:\n"
                "LDR    R1, [R8, #0x68]\n"
                "LDR    R0, [R4, #0x20]\n"
                "STR    R1, [SP, #0x20]\n"
                "STR    R0, [SP, #0x1C]\n"
                "STR    R2, [SP, #0x24]\n"
                "STR    R3, [SP, #0x28]\n"
                "LDR    R3, [R4, #0x1C]\n"
                "LDR    R1, [R8, #0x84]\n"
                "LDR    R2, [R8, #0x88]\n"
                "ADD    R0, SP, #0x60\n"
                "STR    R2, [SP, #0x14]\n"
                "LDR    R2, [SP, #0x50]\n"
                "STR    R1, [SP, #0x10]\n"
                "STR    R3, [SP, #0x18]\n"
                "LDR    R3, [SP, #0x4C]\n"
                "STR    R0, [SP, #0xC]\n"
                "STMFA  SP, {R2,R3}\n"
                "STR    R10, [SP]\n"
                "LDMIB  R4, {R0,R1}\n"
                "MOV    R3, R9\n"
                "MOV    R2, R11\n"
                "BL sub_FF2B587C\n"
"loc_FF18D8C0:\n"
                "LDR    R0, [R8, #0x18]\n"
                "LDR    R1, [R8, #0x60]\n"
                "BL sub_FF02B5A0\n"
                "CMP    R0, #9\n"
                "BNE    loc_FF18D8E0\n"
                "MOV    R1, #0\n"
"loc_FF18D8D8:\n"
                "MOV    R0, #0x90000\n"
                "B  loc_FF18D8F4\n"
"loc_FF18D8E0:\n"
                "LDR    R0, [SP, #0x5C]\n"
                "CMP    R0, #0\n"
                "BEQ    loc_FF18D8FC\n"
                "MOV    R1, #0\n"
"loc_FF18D8F0:\n"
                "MOV    R0, #0xA0000\n"
"loc_FF18D8F4:\n"
                "BL sub_FF18CC2C\n"
                "B  loc_FF18D4D4\n"
"loc_FF18D8FC:\n"
                "LDR    R0, [R8, #0xC]\n"
                "CMP    R0, #2\n"
                "MOV    R0, #0\n"
                "BNE    loc_FF18D914\n"
                "BL sub_FF2B6F94\n"
                "B  loc_FF18D918\n"
"loc_FF18D914:\n"
                "BL sub_FF2B592C\n"
"loc_FF18D918:\n"
                "LDR    R0, [SP, #0x58]\n"
                "LDR    R1, [SP, #0x60]\n"
                "BL sub_FF307144\n"
                "LDR    R0, [R8, #0x68]\n"
                "LDR    R3, =0x8668\n"
                "ADD    R1, R0, #1\n"
                "STR    R1, [R8, #0x68]\n"
                "LDR    R0, [SP, #0x60]\n"
                "SUB    R2, R3, #4\n"
                "BL sub_FF303550\n"
//PATCH BEGIN
        "LDR    R0, =0x8664\n"
        "BL     set_quality\n"
//PATCH END
"loc_FF18D940:\n"
                "CMP    R6, #1\n"
                "BNE    loc_FF18D954\n"
"loc_FF18D948:\n"
                "BL sub_FF0463F4\n"
                "MOV    R0, #1\n"
                "BL sub_FF0463F8\n"
"loc_FF18D954:\n"
                "CMP    R5, #1\n"
                "LDRNEH R0, [R8, #6]\n"
                "CMPNE  R0, #3\n"
                "BNE    loc_FF18D4D4\n"
                "LDR    R0, [R8, #0x6C]\n"
                "ADD    R0, R0, #1\n"
                "STR    R0, [R8, #0x6C]\n"
                "LDRH   R1, [R8, #6]\n"
                "CMP    R1, #3\n"
                "LDRNE  R1, [R8, #0x54]\n"
                "LDREQ  R1, =0x3E9\n"
                "MUL    R0, R1, R0\n"
                "LDRNE  R1, [R8, #0x50]\n"
                "LDREQ  R1, =0x1770\n"
                "BL sub_FF3B62EC\n"
                "MOV    R4, R0\n"
                "BL sub_FF3077D8\n"
                "LDR    R0, [R8, #0x8C]\n"
                "CMP    R0, R4\n"
                "BNE    loc_FF18D9B0\n"
                "LDR    R0, [R8, #0x3C]\n"
                "CMP    R0, #1\n"
                "BNE    loc_FF18D9C4\n"
"loc_FF18D9B0:\n"
                "LDR    R1, [R8, #0xBC]\n"
                "MOV    R0, R4\n"
                "BLX    R1\n"
                "STR    R4, [R8, #0x8C]\n"
                "STR    R7, [R8, #0x3C]\n"
"loc_FF18D9C4:\n"
                "STR    R7, [R8, #0x38]\n"
                "B  loc_FF18D4D4\n"

// "End of function sub_FF18D424\n"
    );
}
