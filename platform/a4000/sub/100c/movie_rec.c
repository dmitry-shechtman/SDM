#include "conf.h"
#include "../../../../include/platform.h"
extern volatile enum _VideoMode VideoMode;
extern unsigned char displayedMode;



void change_video_tables(int a, int b){}

void  set_quality(int *x){ // -17 highest; +12 lowest
          gFramesRecorded++;
if((gFramesRecorded==30)&&conf.camera_position&&(displayedMode==6))play_sound(4);

if(VideoMode==VIDEO_BURST){if((gFrameCount--)<2)gStopVideoCapture=1;}
    if (conf.video_mode) 
        *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

//** movie_record_task  @ 0xFF95ED68 

void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
      "STMFD   SP!, {R2-R10,LR} \n"
      "LDR     R6, =0xFF95E200 \n"
      "LDR     R7, =0xFF95E72C \n" //This function was used to take values for set_quality -->
      "LDR     R4, =0x63E0 \n"
      "LDR     R9, =0x69B \n"
      "LDR     R10, =0x2710 \n"
      "MOV     R8, #1 \n"
      "MOV     R5, #0 \n"
"loc_FF95ED88:\n"
      "LDR     R0, [R4, #0x24] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #4 \n"
      "BL      sub_003F7218 \n"
      "LDR     R0, [R4, #0x2C] \n"
      "CMP     R0, #0 \n"
      "LDRNE   R0, [R4, #0xC] \n"
      "CMPNE   R0, #2 \n"
      "LDRNE   R0, [R4, #0x44] \n"
      "CMPNE   R0, #6 \n"
      "BNE     loc_FF95EEAC \n"
      "LDR     R0, [SP, #4] \n"
      "LDR     R1, [R0] \n"
      "SUB     R1, R1, #2 \n"
      "CMP     R1, #0xB \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF95EEAC \n"
      "B       loc_FF95EE5C \n" //(01)
      "B       loc_FF95EE80 \n" //(02)
      "B       loc_FF95EE90 \n" //(03)
      "B       loc_FF95EE98 \n" //(04)
      "B       loc_FF95EE64 \n" //(05)
      "B       loc_FF95EEA0 \n" //(06)
      "B       loc_FF95EE70 \n" //(07)
      "B       loc_FF95EEAC \n" //(08)
      "B       loc_FF95EEA8 \n" //(09)
      "B       loc_FF95EE28 \n" //(10)
      "B       loc_FF95EDF8 \n" //(11)
"loc_FF95EDF8:\n" //Jump Table entry 11
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R5, [R4, #0x34] \n"
      "STRH    R5, [R4, #6] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xD0] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "MOV     R0, #6 \n"
      "STR     R0, [R4, #0x44] \n"
      "B       loc_FF95EE48 \n"
"loc_FF95EE28:\n" //Jump Table entry 10
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xD0] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "STR     R8, [R4, #0x44] \n"
"loc_FF95EE48:\n"
      "LDR     R2, =0xFF95D960 \n"
      "LDR     R1, =0xAAE5C \n"
      "LDR     R0, =0xFF95DA74 \n"
      "BL      sub_FF84AECC \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE5C:\n" //Jump Table entry 01
      "BL      unlock_optical_zoom \n" //added
      "BL      sub_FF95E360 \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE64:\n" //Jump Table entry 05
      "LDR     R1, [R4, #0xD0] \n"
      "BLX     R1 \n"
//begin patch
      "LDR	   R0, =0x6464 \n"		// added, 0x6468-0x4 taken from  ""loc_FF95EC50:" see commented function below.
      "BL      set_quality \n"		// added
      "BL      mute_on_zoom\n"      // added
//end patch
      "B       loc_FF95EEAC \n"
"loc_FF95EE70:\n"  //Jump Table entry 07
      "LDR     R1, [R0, #0x18] \n"
      "LDR     R0, [R0, #4] \n"
      "BL      sub_FFA6CD2C \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE80:\n"  //Jump Table entry 02
      "LDR     R0, [R4, #0x44] \n"
      "CMP     R0, #5 \n"
      "STRNE   R8, [R4, #0x34] \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE90:\n"  //Jump Table entry 03
      "BL      sub_FF95DE60 \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EE98:\n"  //Jump Table entry 04
      "BL      sub_FF95DAC0 \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EEA0:\n"  //Jump Table entry 06
      "BL      sub_FF95D8EC \n"
      "B       loc_FF95EEAC \n"
"loc_FF95EEA8:\n"  //Jump Table entry 09
      "BL      sub_FF95F384 \n"
"loc_FF95EEAC:\n"
      "LDR     R1, [SP, #4] \n"
      "LDR     R3, =0xFF95D64C \n"
      "STR     R5, [R1] \n"
      "STR     R9, [SP] \n"
      "LDR     R0, [R4, #0x28] \n"
      "MOV     R2, R10 \n"
      "BL      sub_003F7B90 \n"
      "B       loc_FF95ED88 \n"
	);
}


