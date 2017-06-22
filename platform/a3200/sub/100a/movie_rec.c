#include "conf.h"

void change_video_tables(int a, int b){
}

#include "../../../../include/platform.h"
extern volatile enum _VideoMode VideoMode;
extern unsigned char displayedMode;


void  set_quality(int *x) // -17 highest; +12 lowest
{
      gFramesRecorded++;
if((gFramesRecorded==30)&&conf.camera_position&&(displayedMode==6))play_sound(4);

if(VideoMode==VIDEO_BURST){if((gFrameCount--)<2)gStopVideoCapture=1;}  
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

//** movie_record_task  @ 0xFF969AE4 

void __attribute__((naked,noinline)) movie_record_task(  ) { 
asm volatile (
      "STMFD   SP!, {R2-R10,LR} \n"
      "LDR     R6, =0xFF969014 \n"
      "LDR     R7, =0xFF96950C \n" //This function was used to take values for set_quality -->
      "LDR     R4, =0x66E0 \n"
      "LDR     R9, =0x67F \n"
      "LDR     R10, =0x2710 \n"
      "MOV     R8, #1 \n"
      "MOV     R5, #0 \n"
"loc_FF969B04:\n"
      "LDR     R0, [R4, #0x24] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #4 \n"
      "BL      sub_FF839B84 \n"
      "LDR     R0, [R4, #0x2C] \n"
      "CMP     R0, #0 \n"
      "LDRNE   R0, [R4, #0xC] \n"
      "CMPNE   R0, #2 \n"
      "LDRNE   R0, [R4, #0x44] \n"
      "CMPNE   R0, #6 \n"
      "BNE     loc_FF969C28 \n"
      "LDR     R0, [SP, #4] \n"
      "LDR     R1, [R0] \n"
      "SUB     R1, R1, #2 \n"
      "CMP     R1, #0xB \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF969C28 \n"
      "B       loc_FF969BD8 \n" //(01)
      "B       loc_FF969BFC \n" //(02)
      "B       loc_FF969C0C \n" //(03)
      "B       loc_FF969C14 \n" //(04)
      "B       loc_FF969BE0 \n" //(05)
      "B       loc_FF969C1C \n" //(06)
      "B       loc_FF969BEC \n" //(07)
      "B       loc_FF969C28 \n" //(08)
      "B       loc_FF969C24 \n" //(09)
      "B       loc_FF969BA4 \n" //(10)
      "B       loc_FF969B74 \n" //(11)
"loc_FF969B74:\n" //Jump Table entry 11
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R5, [R4, #0x34] \n"
      "STRH    R5, [R4, #6] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xCC] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "MOV     R0, #6 \n"
      "STR     R0, [R4, #0x44] \n"
      "B       loc_FF969BC4 \n"
"loc_FF969BA4:\n" //Jump Table entry 10
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xCC] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "STR     R8, [R4, #0x44] \n"
"loc_FF969BC4:\n"
      "LDR     R2, =0xFF968830 \n"
      "LDR     R1, =0xACE28 \n"
      "LDR     R0, =0xFF968944 \n"
      "BL      sub_FF852C24 \n"
      "B       loc_FF969C28 \n"
"loc_FF969BD8:\n" //Jump Table entry 01
      "BL      unlock_optical_zoom \n" //added
      "BL      sub_FF96916C \n"
      "B       loc_FF969C28 \n"
"loc_FF969BE0:\n" //Jump Table entry 05
      "LDR     R1, [R4, #0xCC] \n"
      "BLX     R1 \n"
//begin patch
"    LDR    R0, =0x6764\n"  // added, 0x6768-0x4 taken from  "loc_FF96950C:" see commented function below.
"    BL     set_quality\n"  // added
//end patch
      "B       loc_FF969C28 \n"
"loc_FF969BEC:\n" //Jump Table entry 07
      "LDR     R1, [R0, #0x18] \n"
      "LDR     R0, [R0, #4] \n"
      "BL      sub_FFAAC964 \n"
      "B       loc_FF969C28 \n"
"loc_FF969BFC:\n" //Jump Table entry 02
      "LDR     R0, [R4, #0x44] \n"
      "CMP     R0, #5 \n"
      "STRNE   R8, [R4, #0x34] \n"
      "B       loc_FF969C28 \n"
"loc_FF969C0C:\n" //Jump Table entry 03
      "BL      sub_FF968CD4 \n"
      "B       loc_FF969C28 \n"
"loc_FF969C14:\n" //Jump Table entry 04
      "BL      sub_FF968990 \n"
      "B       loc_FF969C28 \n"
"loc_FF969C1C:\n" //Jump Table entry 06
      "BL      sub_FF9687BC \n"
      "B       loc_FF969C28 \n"
"loc_FF969C24:\n" //Jump Table entry 09
      "BL      sub_FF96A068 \n"
"loc_FF969C28:\n"
      "LDR     R1, [SP, #4] \n"
      "LDR     R3, =0xFF968604 \n"
      "STR     R5, [R1] \n"
      "STR     R9, [SP] \n"
      "LDR     R0, [R4, #0x28] \n"
      "MOV     R2, R10 \n"
      "BL      sub_FF83A4FC \n"
      "B       loc_FF969B04 \n"
	);
}

