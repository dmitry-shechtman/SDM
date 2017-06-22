#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;


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
        "STMFD   SP!, {R2-R8,LR}\n"
        "LDR     R7, =0x2710\n"
        "LDR     R4, =0x7AB0\n"
        "MOV     R6, #0\n"
        "MOV     R5, #1\n"
"loc_FF961950:\n"
        "LDR     R0, [R4,#0x18]\n"
        "MOV     R2, #0\n"
        "ADD     R1, SP, #4\n"
        "BL      sub_FF8382FC    \n"
        "LDR     R0, [R4,#0x20]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF961A20\n"
        "LDR     R0, [SP,#4]\n"
        "LDR     R1, [R0]\n"
        "SUB     R1, R1, #2\n"
        "CMP     R1, #9\n"
        "ADDLS   PC, PC, R1,LSL#2\n"
        "B       loc_FF961A20\n"
"loc_FF961984:\n"
        "B       loc_FF9619D4\n"
"loc_FF961988:\n"
        "B       loc_FF9619F4\n"
"loc_FF96198C:\n"
        "B       loc_FF961A04\n"
"loc_FF961990:\n"
        "B       loc_FF961A0C\n"
"loc_FF961994:\n"
        "B       loc_FF9619DC\n"
"loc_FF961998:\n"
        "B       loc_FF961A14\n"
"loc_FF96199C:\n"
        "B       loc_FF9619E4\n"
"loc_FF9619A0:\n"
        "B       loc_FF961A20\n"
"loc_FF9619A4:\n"
        "B       loc_FF961A1C\n"
"loc_FF9619A8:\n"
        "B       loc_FF9619AC\n"
"loc_FF9619AC:\n"
        "STR     R6, [R4,#0x34]\n"
        "LDR     R0, =0xFF961654\n"
        "LDR     R2, =0xFF960BDC\n"
        "LDR     R1, =0x8E094\n"
        "STR     R0, [R4,#0x9C]\n"
        "LDR     R0, =0xFF960CC0\n"
        "STR     R6, [R4,#0x24]\n"
        "BL      sub_FF84ED58\n"
        "STR     R5, [R4,#0x38]\n"
        "B       loc_FF961A20\n"
"loc_FF9619D4:\n"
		"BL      unlock_optical_zoom\n" //+-----> inserted to unlock the zoom
        "BL      sub_FF96175C\n"
        "B       loc_FF961A20\n"
"loc_FF9619DC:\n"
        //"BL      sub_FF9612D4\n"
		"BL      sub_FF9612D4_my\n" // ------------------------------>
        "B       loc_FF961A20\n"
"loc_FF9619E4:\n"
        "LDR     R1, [R0,#0x18]\n"
        "LDR     R0, [R0,#4]\n"
        "BL      sub_FFA97054    \n"
        "B       loc_FF961A20\n"
"loc_FF9619F4:\n"
        "LDR     R0, [R4,#0x38]\n"
        "CMP     R0, #5\n"
        "STRNE   R5, [R4,#0x28]\n"
        "B       loc_FF961A20\n"
"loc_FF961A04:\n"
        "BL      sub_FF961020\n"
        "B       loc_FF961A20\n"
"loc_FF961A0C:\n"
        "BL      sub_FF960D0C\n"
        "B       loc_FF961A20\n"
"loc_FF961A14:\n"
        "BL      sub_FF960B68\n"
        "B       loc_FF961A20\n"
"loc_FF961A1C:\n"
        "BL      sub_FF961B8C\n"
"loc_FF961A20:\n"
        "LDR     R1, [SP,#4]\n"
        "MOV     R3, #0x460\n"
        "STR     R6, [R1]\n"
        "STR     R3, [SP]\n"
        "LDR     R0, [R4,#0x1C]\n"
        "LDR     R3, =0xFF9609C8\n"
        "MOV     R2, R7\n"
        "BL      sub_FF838C50\n"
        "B       loc_FF961950\n"
 );
} 

void __attribute__((naked,noinline)) sub_FF9612D4_my(){ 
 asm volatile(
        "STMFD   SP!, {R4-R8,LR}\n"
        "SUB     SP, SP, #0x40\n"
        "MOV     R7, #0\n"
        "LDR     R6, =0x7AB0\n"
        "MOV     R4, R0\n"
        "STR     R7, [SP,#0x30]\n"
        "STR     R7, [SP,#0x28]\n"
        "LDR     R0, [R6,#0x38]\n"
        "MOV     R8, #4\n"
        "CMP     R0, #3\n"
        "STREQ   R8, [R6,#0x38]\n"
        "LDR     R0, [R6,#0x9C]\n"
        "BLX     R0\n"
        "LDR     R0, [R6,#0x38]\n"
        "CMP     R0, #4\n"
        "BNE     loc_FF961444\n"
        "ADD     R3, SP, #0x28\n"
        "ADD     R2, SP, #0x2C\n"
        "ADD     R1, SP, #0x30\n"
        "ADD     R0, SP, #0x34\n"
        "BL      sub_FFA970F0    \n"
        "CMP     R0, #0\n"
        "MOV     R5, #1\n"
        "BNE     loc_FF961350\n"
        "LDR     R1, [R6,#0x28]\n"
        "CMP     R1, #1\n"
        "BNE     loc_FF96144C\n"
        "LDR     R1, [R6,#0x4C]\n"
        "LDR     R2, [R6,#0x3C]\n"
        "CMP     R1, R2\n"
        "BCC     loc_FF96144C\n"
"loc_FF961350:\n"
        "CMP     R0, #0x80000001\n"
        "STREQ   R8, [R6,#0x50]\n"
        "BEQ     loc_FF961388\n"
        "CMP     R0, #0x80000003\n"
        "STREQ   R5, [R6,#0x50]\n"
        "BEQ     loc_FF961388\n"
        "CMP     R0, #0x80000005\n"
        "MOVEQ   R0, #2\n"
        "BEQ     loc_FF961384\n"
        "CMP     R0, #0x80000007\n"
        "STRNE   R7, [R6,#0x50]\n"
        "BNE     loc_FF961388\n"
        "MOV     R0, #3\n"
"loc_FF961384:\n"
        "STR     R0, [R6,#0x50]\n"
"loc_FF961388:\n"
        "LDR     R0, =0x8E0C8\n"
        "LDR     R0, [R0,#8]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF9613A0\n"
        "BL      sub_FF8601E0\n"
        "B       loc_FF9613A4\n"
"loc_FF9613A0:\n"
        "BL      sub_FF960B68    \n"
"loc_FF9613A4:\n"
        "LDR     R0, [R4,#0x1C]\n"
        "ADD     R4, SP, #0x18\n"
        "ADD     R3, SP, #0x38\n"
        "MVN     R2, #1\n"
        "MOV     R1, #0\n"
        "STMIA   R4, {R0-R3}\n"
        "LDR     R2, [R6,#0x64]\n"
        "LDR     R3, [R6,#0x68]\n"
        "ADD     R1, SP, #0x3C\n"
        "ADD     R4, SP, #8\n"
        "MOV     R0, #0\n"
        "STMIA   R4, {R0-R3}\n"
        "MOV     R3, #0\n"
        "MOV     R2, #0x40\n"
        "STRD    R2, [SP]\n"
        "LDR     R3, =0x8E0E0\n"
        "MOV     R2, #0\n"
        "MOV     R1, #0\n"
        "BL      sub_FFA581A4\n"
        "LDR     R0, [R6,#0x10]\n"
        "MOV     R1, #0x3E8\n"
        "BL      sub_FF838718    \n"
        "CMP     R0, #9\n"
        "BNE     loc_FF961414\n"
"loc_FF961404:\n"
        "BL      sub_FFA975C4\n"
        "MOV     R0, #1\n"
        "STR     R5, [R6,#0x38]\n"
        "B       loc_FF961574\n"
"loc_FF961414:\n"
        "LDR     R0, [SP,#0x38]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF961430\n"
"loc_FF961420:\n"
        "BL      sub_FFA975C4\n"
        "MOV     R0, #1\n"
        "STR     R5, [R6,#0x38]\n"
        "B       loc_FF9615A0\n"
"loc_FF961430:\n"
        "MOV     R0, #1\n"
        "BL      sub_FFA5824C\n"
        "BL      sub_FFA58288\n"
        "MOV     R0, #5\n"
        "STR     R0, [R6,#0x38]\n"
"loc_FF961444:\n"
        "ADD     SP, SP, #0x40\n"
        "LDMFD   SP!, {R4-R8,PC}\n"
"loc_FF96144C:\n"
        "LDR     R12, [SP,#0x30]\n"
        "CMP     R12, #0\n"
        "BEQ     loc_FF9615FC\n"
        "STR     R5, [R6,#0x2C]\n"
        "LDR     R0, [R6,#0x4C]\n"
        "LDR     R8, [R4,#0xC]\n"
        "CMP     R0, #0\n"
        "LDRNE   LR, [SP,#0x34]\n"
        "BNE     loc_FF9614F8\n"
        "LDR     R0, [R4,#0x1C]\n"
        "LDR     R1, [R4,#0x20]\n"
        "ADD     R3, SP, #0x38\n"
        "MVN     R2, #0\n"
        "ADD     LR, SP, #0x18\n"
        "STMIA   LR, {R0-R3}\n"
        "LDR     R0, [SP,#0x28]\n"
        "LDR     R2, [R6,#0x64]\n"
        "LDR     R3, [R6,#0x68]\n"
        "ADD     R1, SP, #0x3C\n"
        "ADD     LR, SP, #8\n"
        "STMIA   LR, {R0-R3}\n"
        "LDR     R3, [SP,#0x2C]\n"
        "STR     R12, [SP]\n"
        "STR     R3, [SP,#4]\n"
        "LDMIB   R4, {R0,R1}\n"
        "LDR     R3, [SP,#0x34]\n"
        "MOV     R2, R8\n"
        "BL      sub_FFA581A4\n"
        "LDR     R0, [R6,#0x10]\n"
        "MOV     R1, #0x3E8\n"
        "BL      sub_FF838718    \n"
        "CMP     R0, #9\n"
        "BEQ     loc_FF961404\n"
        "LDR     R0, [SP,#0x38]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF961420\n"
        "MOV     R0, #1\n"
        "BL      sub_FFA5824C\n"
        "LDR     R0, [SP,#0x3C]\n"
        "LDR     R1, [SP,#0x34]\n"
        "ADD     LR, R1, R0\n"
        "LDR     R1, [SP,#0x30]\n"
        "SUB     R12, R1, R0\n"
"loc_FF9614F8:\n"
        "LDR     R2, [R6,#0x48]\n"
        "LDR     R0, [R4,#0x1C]\n"
        "LDR     R1, [R4,#0x20]\n"
        "ADD     R3, SP, #0x38\n"
        "STR     R0, [SP,#0x18]\n"
        "STR     R1, [SP,#0x1C]\n"
        "STR     R3, [SP,#0x24]\n"
        "STR     R2, [SP,#0x20]\n"
        "LDR     R2, [R6,#0x64]\n"
        "LDR     R3, [R6,#0x68]\n"
        "LDR     R0, [SP,#0x28]\n"
        "STR     R3, [SP,#0x14]\n"
        "LDR     R3, [SP,#0x2C]\n"
        "ADD     R1, SP, #0x3C\n"
        "STR     R2, [SP,#0x10]\n"
        "STR     R3, [SP,#4]\n"
        "STR     R1, [SP,#0xC]\n"
        "STR     R12, [SP]\n"
        "STR     R0, [SP,#8]\n"
        "LDMIB   R4, {R0,R1}\n"
        "MOV     R3, LR\n"
        "MOV     R2, R8\n"
        "BL      sub_FFA581A4\n"
        "LDR     R0, [R6,#0x10]\n"
        "MOV     R1, #0x3E8\n"
        "BL      sub_FF838718    \n"
        "CMP     R0, #9\n"
        "BNE     loc_FF961588\n"
        "BL      sub_FFA975C4\n"
        "MOV     R0, #0\n"
        "STR     R5, [R6,#0x38]\n"
"loc_FF961574:\n"
        "BL      sub_FFA5824C\n"
        "MOV     R0, #0xC\n"
        "BL      sub_FF88754C    \n"
        "MOV     R0, #0x90000\n"
        "B       loc_FF9615B0\n"
"loc_FF961588:\n"
        "LDR     R0, [SP,#0x38]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF9615C4\n"
        "BL      sub_FFA975C4\n"
        "MOV     R0, #0\n"
        "STR     R5, [R6,#0x38]\n"
"loc_FF9615A0:\n"
        "BL      sub_FFA5824C\n"
        "MOV     R0, #0xC\n"
        "BL      sub_FF88754C    \n"
        "MOV     R0, #0xA0000\n"
"loc_FF9615B0:\n"
        "BL      sub_FF894994\n"
        "LDR     R1, [R6,#0x8C]!\n"
        "LDR     R0, [R6,#0xC]\n"
        "BLX     R1\n"
        "B       loc_FF961444\n"
"loc_FF9615C4:\n"
        "MOV     R0, #0\n"
        "BL      sub_FFA5824C\n"
        "LDR     R0, [SP,#0x34]\n"
        "LDR     R1, [SP,#0x3C]\n"
        "BL      sub_FFA9731C    \n"
        "LDR     R0, [R6,#0x48]\n"
        "LDR     R3, =0x7B18\n"       // ---> -
        "ADD     R1, R0, #1\n"        //       |
        "STR     R1, [R6,#0x48]\n"    //       |
        "STR     R3, [SP]\n"          //       |
        "LDR     R0, [SP,#0x3C]\n"    //       |
        "SUB     R3, R3, #4\n"        // ---> -
        "MOV     R2, #0xF\n"          //       |
        "BL      sub_FFA955F4\n"      //       |
                                      //       |
        "LDR     R0, =0x7B18-4\n"     // -<----     // +
        "BL      set_quality\n"                     // +
        "BL      synch_led \n"
"loc_FF9615FC:\n"
        "LDR     R0, [R6,#0x4C]\n"
        "ADD     R0, R0, #1\n"
        "STR     R0, [R6,#0x4C]\n"
        "LDR     R1, [R6,#0x74]\n"
        "MUL     R0, R1, R0\n"
        "LDR     R1, [R6,#0x70]\n"
        "BL      sub_FFB37448\n"
        "MOV     R4, R0\n"
        "BL      sub_FFA975FC\n"
        "LDR     R1, [R6,#0x6C]\n"
        "CMP     R1, R4\n"
        "BNE     loc_FF961638\n"
        "LDR     R0, [R6,#0x30]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF96164C\n"
"loc_FF961638:\n"
        "LDR     R1, [R6,#0x80]\n"
        "MOV     R0, R4\n"
        "BLX     R1\n"
        "STR     R4, [R6,#0x6C]\n"
        "STR     R7, [R6,#0x30]\n"
"loc_FF96164C:\n"
        "STR     R7, [R6,#0x2C]\n"
        "B       loc_FF961444\n"
	);
};

/* Values are extracted from G11 FW-Dump, but there are unused.
 
long def_table[24]={
  0x2000,   0x38D,   0x788,  0x5800,  0x9C5,  0x14B8, 0x10000,  0x1C6A,  0x3C45,  0x8000, 0xE35,
  0x1E23,   0x1CCD, -0x2E1, -0x579,  0x4f33, -0x7EB,  -0xF0C,   0xE666, -0x170A, -0x2BC6, 0x7333,
  -0xB85,  -0x15E3
};

long table[24];
long CompressionRateTable[]={0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 0x9, 0x7,
	                         0x6, 0x5, 4, 3, 2, 1};
 
*/ 
void change_video_tables(int a, int b){
#if 0
 int i;
 for (i=0;i<24;i++) table[i]=(def_table[i]*a)/b; 
#endif
} 


