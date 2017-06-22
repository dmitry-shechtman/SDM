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
               "LDR     R4, =0x6D58\n"
               "MOV     R6, #0\n"
               "MOV     R5, #1\n"
			   
"loc_FF962B08:\n"
               "LDR     R0, [R4,#0x18]\n"
               "MOV     R2, #0\n"
               "ADD     R1, SP, #0x4\n"
               "BL      sub_FF83894C\n"
               "LDR     R0, [R4,#0x20]\n"
               "CMP     R0, #0\n"
               "BNE     loc_FF962BD8\n"
               "LDR     R0, [SP,#0x4]\n"
               "LDR     R1, [R0]\n"
               "SUB     R1, R1, #2\n"
               "CMP     R1, #9\n"
               "ADDLS   PC, PC, R1,LSL#2\n"
               "B       loc_FF962BD8\n"
"loc_FF962B3C:\n"
               "B       loc_FF962B8C\n"
"loc_FF962B40:\n"
               "B       loc_FF962BAC\n"
"loc_FF962B44:\n"
               "B       loc_FF962BBC\n"
"loc_FF962B48:\n"
               "B       loc_FF962BC4\n"
"loc_FF962B4C:\n"
               "B       loc_FF962B94\n"
"loc_FF962B50:\n"
               "B       loc_FF962BCC\n"
"loc_FF962B54:\n"
               "B       loc_FF962B9C\n"
"loc_FF962B58:\n"
               "B       loc_FF962BD8\n"
"loc_FF962B5C:\n"
               "B       loc_FF962BD4\n"
"loc_FF962B60:\n"
               "B       loc_FF962B64\n"
"loc_FF962B64:\n"
//; jumptable FF9"2B34 entry 9
               "LDR     R0, =0xFF96281C\n" //nullsub_305
               "STR     R6, [R4,#0x34]\n"
               "STR     R0, [R4,#0x9C]\n"
               "LDR     R2, =0xFF961DAC\n"
               "LDR     R1, =0x8D74C\n"
               "LDR     R0, =0xFF961E90\n"
               "STR     R6, [R4,#0x24]\n"
               "BL      sub_FF85049C\n"
               "STR     R5, [R4,#0x38]\n"
               "B       loc_FF962BD8\n"
"loc_FF962B8C:\n"
//; jumptable FF9"2B34 entry 0
               "BL      unlock_optical_zoom\n" //+-----> inserted to unlock the zoom
               "BL      sub_FF962914\n"
               "B       loc_FF962BD8\n"
"loc_FF962B94:\n"
//; jumptable FF9"2B34 entry 4
               //"BL      sub_FF96249C\n" // -
               "BL      sub_FF96249C_my\n" // + --------->
               "B       loc_FF962BD8\n"
"loc_FF962B9C:\n"
//; jumptable FF9"2B34 entry 6
               "LDR     R1, [R0,#0x18]\n"
               "LDR     R0, [R0,#4]\n"
               "BL      sub_FFA9C758\n"
               "B       loc_FF962BD8\n"
"loc_FF962BAC:\n"
//; jumptable FF9"2B34 entry 1
               "LDR     R0, [R4,#0x38]\n"
               "CMP     R0, #5\n"
               "STRNE   R5, [R4,#0x28]\n"
               "B       loc_FF962BD8\n"
"loc_FF962BBC:\n"
//; jumptable FF9"2B34 entry 2
               "BL      sub_FF9621EC\n"
               "B       loc_FF962BD8\n"
"loc_FF962BC4:\n"
//; jumptable FF9"2B34 entry 3
               "BL      sub_FF961EDC\n"
               "B       loc_FF962BD8\n"
"loc_FF962BCC:\n"
//; jumptable FF9"2B34 entry 5
               "BL      sub_FF961D38\n"
               "B       loc_FF962BD8\n"
"loc_FF962BD4:\n"
//; jumptable FF9"2B34 entry 8
               "BL      sub_FF962D44\n"
"loc_FF962BD8:\n"
//; jumptable FF9"2B34 default entry
//; jumptable FF9"2B34 entry 7
               "LDR     R1, [SP,#0x4]\n"
               "MOV     R3, #0x460\n"
               "STR     R6, [R1]\n"
               "STR     R3, [SP]\n"
               "LDR     R0, [R4,#0x1C]\n"
               "LDR     R3, =0xFF961B98\n" //aMovierecorder
               "MOV     R2, R7\n"
               "BL      sub_FF8392A0\n"
               "B       loc_FF962B08\n"
 );
} 

void __attribute__((naked,noinline)) sub_FF96249C_my(){ 
 asm volatile(
               "STMFD   SP!, {R4-R8,LR}\n"
               "SUB     SP, SP, #0x40\n"
               "MOV     R7, #0\n"
               "LDR     R6, =0x6D58\n"
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
               "BNE     loc_FF96260C\n"
               "ADD     R3, SP, #0x28\n"
               "ADD     R2, SP, #0x2C\n"
               "ADD     R1, SP, #0x30\n"
               "ADD     R0, SP, #0x34\n"
               "BL      sub_FFA9C7F4\n"
               "CMP     R0, #0\n"
               "MOV     R5, #1\n"
               "BNE     loc_FF962518\n"
               "LDR     R1, [R6,#0x28]\n"
               "CMP     R1, #1\n"
               "BNE     loc_FF962614\n"
               "LDR     R1, [R6,#0x4C]\n"
               "LDR     R2, [R6,#0x3C]\n"
               "CMP     R1, R2\n"
               "BCC     loc_FF962614\n"
"loc_FF962518:\n"
               "CMP     R0, #0x80000001\n"
               "STREQ   R8, [R6,#0x50]\n"
               "BEQ     loc_FF962550\n"
               "CMP     R0, #0x80000003\n"
               "STREQ   R5, [R6,#0x50]\n"
               "BEQ     loc_FF962550\n"
               "CMP     R0, #0x80000005\n"
               "MOVEQ   R0, #2\n"
               "BEQ     loc_FF96254C\n"
               "CMP     R0, #0x80000007\n"
               "STRNE   R7, [R6,#0x50]\n"
               "BNE     loc_FF962550\n"
               "MOV     R0, #3\n"
"loc_FF96254C:\n"
               "STR     R0, [R6,#0x50]\n"
"loc_FF962550:\n"
               "LDR     R0, =0x8D780\n"
               "LDR     R0, [R0,#8]\n"
               "CMP     R0, #0\n"
               "BEQ     loc_FF962568\n"
               "BL      sub_FF8621C8\n"
               "B       loc_FF96256C\n"
"loc_FF962568:\n"
               "BL      sub_FF961D38\n"
"loc_FF96256C:\n"
               "LDR     R0, [R4,#0x1C]\n"
               "ADD     R4, SP, #0x18\n"
               "ADD     R3, SP, #0x38\n"
//               "MOVL    R2, 0xFFFFFFFE\n"
               "LDR    R2, =0xFFFFFFFE\n"
               "MOV     R1, #0\n"
               "STMIA   R4, {R0-R3}\n"
               "LDR     R2, [R6,#0x64]\n"
               "LDR     R3, [R6,#0x68]\n"
               "ADD     R1, SP, #0x3C\n"
               "ADD     R4, SP, #0x8\n"
               "MOV     R0, #0\n"
               "STMIA   R4, {R0-R3}\n"
               "MOV     R3, #0\n"
               "MOV     R2, #0x40\n"
               "STRD    R2, [SP]\n"
               "LDR     R3, =0x8D798\n"
               "MOV     R2, #0\n"
               "MOV     R1, #0\n"
               "BL      sub_FFA5ED1C\n"
               "LDR     R0, [R6,#0x10]\n"
               "MOV     R1, #0x3E8\n"
               "BL      sub_FF838D68\n" //eventproc_export_TakeSemaphore
               "CMP     R0, #9\n"
               "BNE     loc_FF9625DC\n"
"loc_FF9625CC:\n"                   
               "BL      sub_FFA9CCC8\n"
               "MOV     R0, #1\n"
               "STR     R5, [R6,#0x38]\n"
               "B       loc_FF96273C\n"
"loc_FF9625DC:\n"
               "LDR     R0, [SP,#0x38]\n"
               "CMP     R0, #0\n"
               "BEQ     loc_FF9625F8\n"
"loc_FF9625E8:\n"
               "BL      sub_FFA9CCC8\n"
               "MOV     R0, #1\n"
               "STR     R5, [R6,#0x38]\n"
               "B       loc_FF962768\n"
"loc_FF9625F8:\n"
               "MOV     R0, #1\n"
               "BL      sub_FFA5EDC4\n"
               "BL      sub_FFA5EE00\n"
               "MOV     R0, #5\n"
               "STR     R0, [R6,#0x38]\n"
"loc_FF96260C:\n"
               "ADD     SP, SP, #0x40\n"
               "LDMFD   SP!, {R4-R8,PC}\n"
"loc_FF962614:\n"
               "LDR     R12, [SP,#0x30]\n"
               "CMP     R12, #0\n"
               "BEQ     loc_FF9627C4\n"
               "STR     R5, [R6,#0x2C]\n"
               "LDR     R0, [R6,#0x4C]\n"
               "LDR     R8, [R4,#0xC]\n"
               "CMP     R0, #0\n"
               "LDRNE   LR, [SP,#0x34]\n"
               "BNE     loc_FF9626C0\n"
               "LDR     R0, [R4,#0x1C]\n"
               "LDR     R1, [R4,#0x20]\n"
               "ADD     R3, SP, #0x38\n"
//               "MOVL    R2, 0xFFFFFFFF\n"
               "LDR    R2, =0xFFFFFFFF\n"
               "ADD     LR, SP, #0x18\n"
               "STMIA   LR, {R0-R3}\n"
               "LDR     R0, [SP,#0x28]\n"
               "LDR     R2, [R6,#0x64]\n"
               "LDR     R3, [R6,#0x68]\n"
               "ADD     R1, SP, #0x3c\n"
               "ADD     LR, SP, #0x8\n"
               "STMIA   LR, {R0-R3}\n"
               "LDR     R3, [SP,#0x2C]\n"
               "STR     R12, [SP]\n"
               "STR     R3, [SP,#4]\n"
               "LDMIB   R4, {R0,R1}\n"
               "LDR     R3, [SP,#0x34]\n"
               "MOV     R2, R8\n"
               "BL      sub_FFA5ED1C\n"
               "LDR     R0, [R6,#0x10]\n"
               "MOV     R1, #0x3E8\n"
               "BL      sub_FF838D68\n" //eventproc_export_TakeSemaphore
               "CMP     R0, #9\n"
               "BEQ     loc_FF9625CC\n"
               "LDR     R0, [SP,#0x38]\n"
               "CMP     R0, #0\n"
               "BNE     loc_FF9625E8\n"
               "MOV     R0, #1\n"
               "BL      sub_FFA5EDC4\n"
               "LDR     R0, [SP,#0x3C]\n"
               "LDR     R1, [SP,#0x34]\n"
               "ADD     LR, R1, R0\n"
               "LDR     R1, [SP,#0x30]\n"
               "SUB     R12, R1, R0\n"
"loc_FF9626C0:\n"
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
               "STR     R0, [SP,#0x8]\n"
               "LDMIB   R4, {R0,R1}\n"
               "MOV     R3, LR\n"
               "MOV     R2, R8\n"
               "BL      sub_FFA5ED1C\n"
               "LDR     R0, [R6,#0x10]\n"
               "MOV     R1, #0x3E8\n"
               "BL      sub_FF838D68\n" //eventproc_export_TakeSemaphore
               "CMP     R0, #9\n"
               "BNE     loc_FF962750\n"
               "BL      sub_FFA9CCC8\n"
               "MOV     R0, #0\n"
               "STR     R5, [R6,#0x38]\n"
"loc_FF96273C:\n" 
               "BL      sub_FFA5EDC4\n"
               "MOV     R0, #0xC\n"
               "BL      sub_FF8880D8\n" //__ExMemMan.c__0
               "MOV     R0, #0x90000\n"
               "B       loc_FF962778\n"
"loc_FF962750:\n"
               "LDR     R0, [SP,#0x38]\n"
               "CMP     R0, #0\n"
               "BEQ     loc_FF96278C\n"
               "BL      sub_FFA9CCC8\n"
               "MOV     R0, #0\n"
               "STR     R5, [R6,#0x38]\n"
"loc_FF962768:\n"
               "BL      sub_FFA5EDC4\n"
               "MOV     R0, #0xC\n"
               "BL      sub_FF8880D8\n" //__ExMemMan.c__0
               "MOV     R0, #0xA0000\n"
"loc_FF962778:\n"
               "BL      sub_FF8955E0\n" //eventproc_export_HardwareDefect
               "LDR     R1, [R6,#0x8C]!\n"
               "LDR     R0, [R6,#0xC]\n"
               "BLX     R1\n"
               "B       loc_FF96260C\n"

"loc_FF96278C:\n"
               "MOV     R0, #0\n"
               "BL      sub_FFA5EDC4\n"
               "LDR     R0, [SP,#0x34]\n"
               "LDR     R1, [SP,#0x3C]\n"
               "BL      sub_FFA9CA20\n"//__MovWriter.c__0
               "LDR     R0, [R6,#0x48]\n"
               "LDR     R3, =0x6DC0\n"       // ---> -
               "ADD     R1, R0, #1\n"        //       |
               "STR     R1, [R6,#0x48]\n"    //       |
               "STR     R3, [SP]\n"          //       |
               "LDR     R0, [SP,#0x3C]\n"    //       |
               "SUB     R3, R3, #4\n"        // ---> -
               "MOV     R2, #0xF\n"          //       |
               "BL      sub_FFA9ACF8\n"      //       |
                                             //       |
               "LDR     R0, =0x6DC0-4\n"     // -<----     // +
               "BL      set_quality\n"                     // +
"loc_FF9627C4:\n"
               "LDR     R0, [R6,#0x4C]\n"
               "ADD     R0, R0, #1\n"
               "STR     R0, [R6,#0x4C]\n"
               "LDR     R1, [R6,#0x74]\n"
               "MUL     R0, R1, R0\n"
               "LDR     R1, [R6,#0x70]\n"
               "BL      sub_FFB3E480\n"
               "MOV     R4, R0\n"
               "BL      sub_FFA9CD00\n"
               "LDR     R1, [R6,#0x6C]\n"
               "CMP     R1, R4\n"
               "BNE     loc_FF962800\n"
               "LDR     R0, [R6,#0x30]\n"
               "CMP     R0, #1\n"
               "BNE     loc_FF962814\n"
"loc_FF962800:\n"
               "LDR     R1, [R6,#0x80]\n"
               "MOV     R0, R4\n"
               "BLX     R1\n"
               "STR     R4, [R6,#0x6C]\n"
               "STR     R7, [R6,#0x30]\n"
"loc_FF962814:\n"
               "STR     R7, [R6,#0x2C]\n"
               "B       loc_FF96260C\n"
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


