#include "conf.h"

void change_video_tables(int a, int b){}


#include "../../../../include/platform.h"
extern volatile enum _VideoMode VideoMode;
extern unsigned char displayedMode;


void  set_quality(int *x){ // -17 highest; +12 lowest
          gFramesRecorded++;
if((gFramesRecorded==30)&&conf.camera_position&&(displayedMode==6))play_sound(4);

if(VideoMode==VIDEO_BURST){if((gFrameCount--)<2)gStopVideoCapture=1;}
 if (conf.video_mode) 
        *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

//** movie_record_task  @ 0xFF95B59C 

void __attribute__((naked,noinline)) movie_record_task(  ) { 
asm volatile (
      "STMFD   SP!, {R2-R10,LR} \n"
      "LDR     R6, =0xFF95AA34 \n"
      "LDR     R7, =0xFF95AF60 \n" //This function was used to take values for set_quality -->
      "LDR     R4, =0x62F8 \n"
      "LDR     R9, =0x69B \n"
      "LDR     R10, =0x2710 \n"
      "MOV     R8, #1 \n"
      "MOV     R5, #0 \n"
"loc_FF95B5BC:\n"
      "LDR     R0, [R4, #0x24] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #4 \n"
      "BL      sub_003F7218 \n" //RAM
      "LDR     R0, [R4, #0x2C] \n"
      "CMP     R0, #0 \n"
      "LDRNE   R0, [R4, #0xC] \n"
      "CMPNE   R0, #2 \n"
      "LDRNE   R0, [R4, #0x44] \n"
      "CMPNE   R0, #6 \n"
      "BNE     loc_FF95B6E0 \n"
      "LDR     R0, [SP, #4] \n"
      "LDR     R1, [R0] \n"
      "SUB     R1, R1, #2 \n"
      "CMP     R1, #0xB \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF95B6E0 \n"
      "B       loc_FF95B690 \n" //(01)
      "B       loc_FF95B6B4 \n" //(02)
      "B       loc_FF95B6C4 \n" //(03)
      "B       loc_FF95B6CC \n" //(04)
      "B       loc_FF95B698 \n" //(05)
      "B       loc_FF95B6D4 \n" //(06)
      "B       loc_FF95B6A4 \n" //(07)
      "B       loc_FF95B6E0 \n" //(08)
      "B       loc_FF95B6DC \n" //(09)
      "B       loc_FF95B65C \n" //(10)
      "B       loc_FF95B62C \n" //(11)
"loc_FF95B62C:\n" //Jump Table entry 11
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
      "B       loc_FF95B67C \n"
"loc_FF95B65C:\n" //Jump Table entry 10
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xD0] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "STR     R8, [R4, #0x44] \n"
"loc_FF95B67C:\n"
      "LDR     R2, =0xFF95A194 \n"
      "LDR     R1, =0xAD018 \n"
      "LDR     R0, =0xFF95A2A8 \n"
      "BL      sub_FF84A34C \n"
      "B       loc_FF95B6E0 \n"
"loc_FF95B690:\n" //Jump Table entry 01
      "BL      unlock_optical_zoom \n" //added
      "BL      sub_FF95AB94 \n"
      "B       loc_FF95B6E0 \n"
"loc_FF95B698:\n"  //Jump Table entry 05
      "LDR     R1, [R4, #0xD0] \n"
      "BLX     R1 \n"
//begin patch
      "LDR	   R0, =0x637C \n"		// added, 0x6380-0x4 taken from  "loc_FF95B484:" see commented function below.
      "BL      set_quality \n"		// added
//end patch      
      "B       loc_FF95B6E0 \n"
"loc_FF95B6A4:\n"  //Jump Table entry 07
      "LDR     R1, [R0, #0x18] \n"
      "LDR     R0, [R0, #4] \n"
      "BL      sub_FFA6B224 \n"
      "B       loc_FF95B6E0 \n"
"loc_FF95B6B4:\n"  //Jump Table entry 02
      "LDR     R0, [R4, #0x44] \n"
      "CMP     R0, #5 \n"
      "STRNE   R8, [R4, #0x34] \n"
      "B       loc_FF95B6E0 \n"
"loc_FF95B6C4:\n"  //Jump Table entry 03
      "BL      sub_FF95A694 \n"
      "B       loc_FF95B6E0 \n"
"loc_FF95B6CC:\n"  //Jump Table entry 04
      "BL      sub_FF95A2F4 \n"
      "B       loc_FF95B6E0 \n"
"loc_FF95B6D4:\n"  //Jump Table entry 06
      "BL      sub_FF95A120 \n"
      "B       loc_FF95B6E0 \n"
"loc_FF95B6DC:\n"  //Jump Table entry 09
      "BL      sub_FF95BBB8 \n"
"loc_FF95B6E0:\n"
      "LDR     R1, [SP, #4] \n"
      "LDR     R3, =0xFF959E80 \n"
      "STR     R5, [R1] \n"
      "STR     R9, [SP] \n"
      "LDR     R0, [R4, #0x28] \n"
      "MOV     R2, R10 \n"
      "BL      sub_003F7B90 \n" //RAM
      "B       loc_FF95B5BC \n"
	);
}

