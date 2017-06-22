#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[9]={0x2000,0x38D,0x788,0x5800,0x9C5,0x14B8,0x10000,0x1C6A,0x3C45};
long def_table2[9]={0x1CCD,-0x2E1,-0x579,0x4F33,-0x7EB,-0xF0C,0xE666,-0x170A,-0x2BC6};

long table1[9], table2[9];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<9;i++) {table1[i]=(def_table1[i]*a)/b; table2[i]=(def_table2[i]*a)/b;}
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                 "STMFD   SP!, {R4,LR}\n"
                 "SUB     SP, SP, #4\n"
                 "MOV     R4, SP\n"
                 "B       loc_FF954564\n"
 "loc_FF9544C0:\n"
                 "LDR     R3, =0x6EC88\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #0\n"
                 "BNE     loc_FF954550\n"
                 "SUB     R3, R12, #2\n"
                 "CMP     R3, #9\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FF954550\n"
                 ".long loc_FF954510\n"
                 ".long loc_FF954528\n"
                 ".long loc_FF954530\n"
                 ".long loc_FF954538\n"
                 ".long loc_FF954518\n"
                 ".long loc_FF954540\n"
                 ".long loc_FF954520\n"
                 ".long loc_FF954550\n"
                 ".long loc_FF954548\n"
                 ".long loc_FF954508\n"
 "loc_FF954508:\n"
                 "BL      sub_FF9545FC\n"
                 "B       loc_FF95454C\n"
 "loc_FF954510:\n"
                 "BL      unlock_optical_zoom\n"
                 "BL      sub_FF9547B0\n"
                 "B       loc_FF95454C\n"
 "loc_FF954518:\n"
                 "BL      sub_FF954B84_my\n"  //------------------->
                 "B       loc_FF95454C\n"
 "loc_FF954520:\n"
                 "BL      sub_FF954FB8\n"
                 "B       loc_FF95454C\n"
 "loc_FF954528:\n"
                 "BL      sub_FF954E1C\n"
                 "B       loc_FF95454C\n"
 "loc_FF954530:\n"
                 "BL      sub_FF955128\n"
                 "B       loc_FF95454C\n"
 "loc_FF954538:\n"
                 "BL      sub_FF9552EC\n"
                 "B       loc_FF95454C\n"
 "loc_FF954540:\n"
                 "BL      sub_FF955040\n"
                 "B       loc_FF95454C\n"
 "loc_FF954548:\n"
                 "BL      sub_FF954E6C\n"
 "loc_FF95454C:\n"
                 "LDR     R1, [SP]\n"
 "loc_FF954550:\n"
                 "LDR     R3, =0x6EBBC\n"
                 "MOV     R2, #0\n"
                 "STR     R2, [R1]\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF82089C\n"
 "loc_FF954564:\n"
                 "LDR     R3, =0x6EBB8\n"
                 "MOV     R1, R4\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R2, #0\n"
                 "BL      sub_FF820484\n"
                 "LDR     R0, [SP]\n"
                 "LDR     R12, [R0]\n"
                 "CMP     R12, #0xC\n"
                 "MOV     R1, R0\n"
                 "BNE     loc_FF9544C0\n"
                 "LDR     R3, =0x6EBB4\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF821218\n"
                 "BL      sub_FF8219E0\n"
                 "ADD     SP, SP, #4\n"
                 "LDMFD   SP!, {R4,PC}\n"
 );
}


void __attribute__((naked,noinline)) sub_FF954B84_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R11,LR}\n"
                 "LDR     R5, =0x6ECA4\n"
                 "SUB     SP, SP, #0x34\n"
                 "LDR     R3, [R5]\n"
                 "CMP     R3, #3\n"
                 "MOV     R4, R0\n"
                 "MOVEQ   R3, #4\n"
                 "STREQ   R3, [R5]\n"
                 "LDR     R3, =0x6ED54\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3]\n"
                 "LDR     R2, [R5]\n"
                 "CMP     R2, #4\n"
                 "BNE     loc_FF954D48\n"
                 "ADD     R0, SP, #0x30\n"
                 "ADD     R1, SP, #0x2C\n"
                 "ADD     R2, SP, #0x28\n"
                 "ADD     R3, SP, #0x24\n"
                 "BL      sub_FF956258_my\n"  //------------------->
                 "CMP     R0, #0\n"
                 "BNE     loc_FF954C00\n"
                 "LDR     R3, =0x6EC90\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #1\n"
                 "BNE     loc_FF954C14\n"
                 "LDR     R2, =0x6ECE8\n"
                 "LDR     R1, =0x6ECBC\n"
                 "LDR     R12, [R2]\n"
                 "LDR     R3, [R1]\n"
                 "CMP     R12, R3\n"
                 "BCC     loc_FF954C14\n"
 "loc_FF954C00:\n"
                 "BL      sub_FF954D94\n"
                 "BL      sub_FF954F94\n"
                 "MOV     R3, #5\n"
                 "STR     R3, [R5]\n"
                 "B       loc_FF954D48\n"
 "loc_FF954C14:\n"
                 "LDR     R12, =0x6ECF0\n"
                 "LDR     R11, =0x6ECFC\n"
                 "LDMIB   R4, {R0-R2}\n"
                 "LDR     R10, [R12]\n"
                 "LDR     R7, [R11]\n"
                 "LDR     R4, [SP,#0x2C]\n"
                 "LDR     R5, [SP,#0x28]\n"
                 "LDR     R6, [SP,#0x24]\n"
                 "LDR     R8, =0x6EC94\n"
                 "LDR     R3, [SP,#0x30]\n"
                 "ADD     R12, SP, #0x20\n"
                 "ADD     LR, SP, #0x1C\n"
                 "MOV     R9, #1\n"
                 "STMEA   SP, {R4-R6,R12}\n"
                 "STR     R10, [SP,#0x10]\n"
                 "STR     R7, [SP,#0x14]\n"
                 "STR     LR, [SP,#0x18]\n"
                 "STR     R9, [R8]\n"
                 "BL      sub_FF89650C\n"
                 "LDR     R3, =0x6EBAC\n"
                 "MOV     R1, #0x3E8\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF821030\n"
                 "CMP     R0, #9\n"
                 "BNE     loc_FF954C88\n"
                 "BL      sub_FF956A68\n"
                 "LDR     R3, =0x6ECA4\n"
                 "LDR     R0, =0xFF954B6C\n"
                 "B       loc_FF954CA0\n"
 "loc_FF954C88:\n"
                 "LDR     R5, [SP,#0x1C]\n"
                 "CMP     R5, #0\n"
                 "BEQ     loc_FF954CAC\n"
                 "BL      sub_FF956A68\n"
                 "LDR     R3, =0x6ECA4\n"
                 "LDR     R0, =0xFF954B78\n"
 "loc_FF954CA0:\n"
                 "STR     R9, [R3]\n"
                 "BL      sub_FF969B80\n"
                 "B       loc_FF954D48\n"
 "loc_FF954CAC:\n"
                 "BL      sub_FF896678\n"
                 "LDR     R0, [SP,#0x30]\n"
                 "LDR     R1, [SP,#0x20]\n"
                 "BL      sub_FF95678C\n"
                 "LDR     R4, =0x6ECE8\n"
                 "LDR     R3, [R4]\n"
                 "ADD     R3, R3, #1\n"
                 "LDR     R0, [SP,#0x20]\n"
                 "MOV     R1, R11\n"
                 "STR     R3, [R4]\n"
                 "MOV     R2, R5\n"
                 "BL      sub_FF955648_my\n"  //--------------------->
                 "LDR     R3, =0x6ED08\n"
                 "LDR     R1, [R4]\n"
                 "LDR     R2, [R3]\n"
                 "LDR     R12, =0x6ED04\n"
                 "MUL     R0, R2, R1\n"
                 "LDR     R1, [R12]\n"
                 "BL      sub_FFB02D34\n"
                 "LDR     R7, =0x6ED00\n"
                 "LDR     R3, [R7]\n"
                 "MOV     R4, R0\n"
                 "CMP     R3, R4\n"
                 "BNE     loc_FF954D20\n"
                 "LDR     R6, =0x6EC98\n"
                 "LDR     R3, [R6]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FF954D3C\n"
                 "B       loc_FF954D24\n"
 "loc_FF954D20:\n"
                 "LDR     R6, =0x6EC98\n"
 "loc_FF954D24:\n"
                 "LDR     R3, =0x6ED38\n"
                 "MOV     R0, R4\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3]\n"
                 "STR     R5, [R6]\n"
                 "STR     R4, [R7]\n"
 "loc_FF954D3C:\n"
                 "LDR     R2, =0x6EC94\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
 "loc_FF954D48:\n"
                 "ADD     SP, SP, #0x34\n"
                 "LDMFD   SP!, {R4-R11,PC}\n"
 );
}


void __attribute__((naked,noinline)) sub_FF956258_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R11,LR}\n"
                 "LDR     R5, =0x6EFFC\n"
                 "SUB     SP, SP, #0x14\n"
                 "LDR     LR, [R5]\n"
                 "LDR     R12, =0x6F014\n"
                 "ADD     LR, LR, #1\n"
                 "LDR     R4, [R12]\n"
                 "STR     LR, [R5]\n"
                 "LDR     R12, =0x6F094\n"
                 "STR     R0, [SP,#0x10]\n"
                 "STR     R1, [SP,#0xC]\n"
                 "STR     R2, [SP,#8]\n"
                 "STR     R3, [SP,#4]\n"
                 "CMP     LR, R4\n"
                 "LDR     R11, [R12]\n"
                 "MOVHI   R0, #0x80000001\n"
                 "BHI     loc_FF956740\n"
                 "LDR     R3, =0x6F078\n"
                 "MOV     R0, LR\n"
                 "LDR     R1, [R3]\n"
                 "BL      sub_FFB033C4\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF956478\n"
                 "LDR     R0, =0x6F09C\n"
                 "LDR     R1, =0x6EFE8\n"
                 "LDR     R3, [R0]\n"
                 "LDR     R2, [R1]\n"
                 "CMP     R3, R2\n"
                 "LDREQ   R3, =0x6F098\n"
                 "LDREQ   R5, [R3]\n"
                 "MOVNE   R5, R2\n"
                 "LDR     R3, =0x6EFFC\n"
                 "LDR     R2, =0x6F078\n"
                 "LDR     R0, [R3]\n"
                 "LDR     R1, [R2]\n"
                 "BL      sub_FFB02D34\n"
                 "LDR     R3, =0x6EFF0\n"
                 "ADD     R0, R0, #1\n"
                 "AND     R0, R0, #1\n"
                 "STR     R5, [R3,R0,LSL#2]\n"
                 "LDR     R3, =0x6EFE4\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R5, R2\n"
                 "BHI     loc_FF956328\n"
                 "LDR     R4, =0x6F034\n"
                 "LDR     R3, [R4]\n"
                 "ADD     R3, R5, R3\n"
                 "ADD     R3, R3, #8\n"
                 "CMP     R2, R3\n"
                 "BCS     loc_FF95632C\n"
 "loc_FF956320:\n"
                 "MOV     R0, #0x80000003\n"
                 "B       loc_FF956740\n"
 "loc_FF956328:\n"
                 "LDR     R4, =0x6F034\n"
 "loc_FF95632C:\n"
                 "LDR     R3, [R4]\n"
                 "LDR     R2, =0x6F09C\n"
                 "ADD     R1, R5, R3\n"
                 "LDR     R3, [R2]\n"
                 "ADD     R2, R1, #8\n"
                 "CMP     R2, R3\n"
                 "BLS     loc_FF956378\n"
                 "LDR     R2, =0x6F098\n"
                 "LDR     R0, =0x6EFE4\n"
                 "RSB     R3, R3, R1\n"
                 "LDR     R1, [R2]\n"
                 "ADD     R3, R3, #8\n"
                 "LDR     R2, [R0]\n"
                 "ADD     R1, R1, R3\n"
                 "CMP     R2, R1\n"
                 "BCC     loc_FF956320\n"
                 "LDR     R3, =0x6EFE8\n"
                 "STR     R1, [R3]\n"
                 "B       loc_FF956380\n"
 "loc_FF956378:\n"
                 "LDR     R3, =0x6EFE8\n"
                 "STR     R2, [R3]\n"
 "loc_FF956380:\n"
                 "LDR     R3, [R4]\n"
                 "LDR     R12, =0x6F048\n"
                 "ADD     R3, R3, #0x18\n"
                 "LDR     R2, [R12,#4]\n"
                 "MOV     R0, R3\n"
                 "MOV     R1, #0\n"
                 "CMP     R1, R2\n"
                 "BHI     loc_FF9565C4\n"
                 "BNE     loc_FF9563B0\n"
                 "LDR     R3, [R12]\n"
                 "CMP     R0, R3\n"
                 "BHI     loc_FF9565C4\n"
 "loc_FF9563B0:\n"
                 "LDR     R4, [R4]\n"
                 "LDR     LR, =0x6F050\n"
                 "STR     R4, [SP]\n"
                 "LDR     R12, =0x6F048\n"
                 "LDR     R3, =0x6EFFC\n"
                 "LDMIA   LR, {R7,R8}\n"
                 "LDMIA   R12, {R5,R6}\n"
                 "LDR     R10, [R3]\n"
                 "LDR     R2, =0x6F078\n"
                 "MOV     R3, R4\n"
                 "MOV     R4, #0\n"
                 "ADDS    R7, R7, R3\n"
                 "ADC     R8, R8, R4\n"
                 "LDR     R9, [R2]\n"
                 "SUBS    R5, R5, R3\n"
                 "SBC     R6, R6, R4\n"
                 "MVN     R2, #0\n"
                 "MVN     R1, #0x17\n"
                 "ADDS    R5, R5, R1\n"
                 "MOV     R4, #0\n"
                 "MOV     R3, #0x18\n"
                 "ADC     R6, R6, R2\n"
                 "ADDS    R7, R7, R3\n"
                 "ADC     R8, R8, R4\n"
                 "STMIA   R12, {R5,R6}\n"
                 "SUB     R0, R10, #1\n"
                 "MOV     R1, R9\n"
                 "STMIA   LR, {R7,R8}\n"
                 "BL      sub_FFB02D34\n"
                 "CMP     R10, #1\n"
                 "MLA     R0, R9, R0, R0\n"
                 "BEQ     loc_FF956478\n"
                 "SUB     R3, R0, #1\n"
                 "MOV     R3, R3,LSL#4\n"
                 "ADD     R4, R11, #0x10\n"
                 "ADD     R5, R11, #0x14\n"
                 "LDR     R1, [R5,R3]\n"
                 "LDR     R2, [R4,R3]\n"
                 "LDR     LR, =0x62773130\n"
                 "ADD     R2, R2, R1\n"
                 "MOV     R3, R0,LSL#4\n"
                 "ADD     R2, R2, #8\n"
                 "MOV     R0, #0\n"
                 "ADD     R12, R11, #0xC\n"
                 "ADD     R1, R11, #8\n"
                 "STR     LR, [R1,R3]\n"
                 "STR     R0, [R12,R3]\n"
                 "STR     R2, [R4,R3]\n"
                 "LDR     R0, [SP]\n"
                 "STR     R0, [R5,R3]\n"
 "loc_FF956478:\n"
                 "LDR     R2, =0x6EFE8\n"
                 "LDR     R3, =0x6F09C\n"
                 "LDR     R1, [R2]\n"
                 "LDR     R0, [R3]\n"
                 "ADD     R3, R1, #9\n"
                 "CMP     R3, R0\n"
                 "BLS     loc_FF9564B4\n"
                 "LDR     R2, =0x6F098\n"
                 "LDR     R3, [R2]\n"
                 "ADD     R3, R3, R1\n"
                 "RSB     R3, R0, R3\n"
                 "LDR     R0, [SP,#0x10]\n"
                 "ADD     R3, R3, #8\n"
                 "STR     R3, [R0]\n"
                 "B       loc_FF9564C0\n"
 "loc_FF9564B4:\n"
                 "ADD     R3, R1, #8\n"
                 "LDR     R1, [SP,#0x10]\n"
                 "STR     R3, [R1]\n"
 "loc_FF9564C0:\n"
                 "LDR     R2, [SP,#0x10]\n"
                 "LDR     R1, =0x6F044\n"
                 "LDR     R3, =0x6F09C\n"
                 "LDR     R12, [R2]\n"
                 "LDR     R2, [R1]\n"
                 "LDR     R0, [R3]\n"
                 "ADD     R3, R12, R2\n"
                 "CMP     R3, R0\n"
                 "BLS     loc_FF956514\n"
                 "LDR     R2, [SP,#0xC]\n"
                 "RSB     R0, R12, R0\n"
                 "STR     R0, [R2]\n"
                 "LDR     R2, =0x6F098\n"
                 "LDR     R3, [R1]\n"
                 "LDR     R1, [R2]\n"
                 "RSB     R3, R0, R3\n"
                 "LDR     R0, [SP,#8]\n"
                 "STR     R1, [R0]\n"
                 "LDR     R1, [SP,#4]\n"
                 "STR     R3, [R1]\n"
                 "B       loc_FF956530\n"
 "loc_FF956514:\n"
                 "LDR     R0, [SP,#0xC]\n"
                 "STR     R2, [R0]\n"
                 "LDR     R1, [SP,#4]\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R1]\n"
                 "LDR     R2, [SP,#8]\n"
                 "STR     R3, [R2]\n"
 "loc_FF956530:\n"
                 "LDR     R0, =0x6EFE8\n"
                 "LDR     R1, =0x6EFE4\n"
                 "LDR     R3, [R0]\n"
                 "LDR     R2, [R1]\n"
                 "CMP     R3, R2\n"
                 "BHI     loc_FF95655C\n"
                 "LDR     R0, [SP,#0xC]\n"
                 "LDR     R3, [R0]\n"
                 "ADD     R3, R12, R3\n"
                 "CMP     R2, R3\n"
                 "BCC     loc_FF956320\n"
 "loc_FF95655C:\n"
                 "LDR     R1, [SP,#8]\n"
                 "LDR     R2, [R1]\n"
                 "CMP     R2, #0\n"
                 "BEQ     loc_FF956590\n"
                 "LDR     R3, =0x6EFE4\n"
                 "LDR     R1, [R3]\n"
                 "CMP     R2, R1\n"
                 "BHI     loc_FF956590\n"
                 "LDR     R0, [SP,#4]\n"
                 "LDR     R3, [R0]\n"
                 "ADD     R3, R2, R3\n"
                 "CMP     R1, R3\n"
                 "BCC     loc_FF956320\n"
 "loc_FF956590:\n"
                 "LDR     R3, =0x6F044\n"
                 "LDR     R0, =0x6F048\n"
                 "LDR     R2, [R3]\n"
                 "LDR     R3, [R0,#4]\n"
                 "ADD     R2, R2, #0x18\n"
                 "MOV     R1, R2\n"
                 "MOV     R2, #0\n"
                 "CMP     R2, R3\n"
                 "BHI     loc_FF9565C4\n"
                 "BNE     loc_FF9565CC\n"
                 "LDR     R3, [R0]\n"
                 "CMP     R1, R3\n"
                 "BLS     loc_FF9565CC\n"
 "loc_FF9565C4:\n"
                 "MOV     R0, #0x80000005\n"
                 "B       loc_FF956740\n"
 "loc_FF9565CC:\n"
                 "LDR     R1, =0x6F02C\n"
                 "LDR     R0, =0x6F078\n"
                 "LDR     R3, [R1]\n"
                 "LDR     R2, [R0]\n"
                 "ADD     R3, R3, R2,LSL#4\n"
                 "ADD     R3, R3, R3,LSL#2\n"
                 "LDR     R12, =0x6F048\n"
                 "MOV     R3, R3,LSL#1\n"
                 "ADD     R3, R3, #0xA0\n"
                 "LDR     R2, [R12,#4]\n"
                 "MOV     R0, R3\n"
                 "MOV     R1, #0\n"
                 "CMP     R1, R2\n"
                 "BHI     loc_FF956614\n"
                 "BNE     loc_FF956638\n"
                 "LDR     R3, [R12]\n"
                 "CMP     R0, R3\n"
                 "BLS     loc_FF956638\n"
 "loc_FF956614:\n"
                 "LDR     R4, =0x6F060\n"
                 "LDR     R1, [R4]\n"
                 "CMP     R1, #0\n"
                 "BNE     loc_FF956638\n"
                 "MOV     R0, #0x3140\n"
                 "ADD     R0, R0, #8\n"
                 "BL      sub_FF96E0B0\n"
                 "MOV     R3, #1\n"
                 "STR     R3, [R4]\n"
 "loc_FF956638:\n"
                 "LDR     R1, =0x6F02C\n"
                 "LDR     R0, =0x6F078\n"
                 "LDR     R2, [R1]\n"
                 "LDR     R3, [R0]\n"
                 "LDR     R0, =0x6F050\n"
                 "ADD     R2, R2, R3,LSL#4\n"
                 "MVN     R3, #0x9F\n"
                 "ADD     R2, R2, R2,LSL#2\n"
                 "ADD     R3, R3, #0x40000000\n"
                 "SUB     R3, R3, R2,LSL#1\n"
                 "LDR     R1, [R0,#4]\n"
                 "MOV     R4, R3\n"
                 "MOV     R5, #0\n"
                 "CMP     R1, R5\n"
                 "BHI     loc_FF956684\n"
                 "BNE     loc_FF9566A8\n"
                 "LDR     R3, [R0]\n"
                 "CMP     R3, R4\n"
                 "BLS     loc_FF9566A8\n"
 "loc_FF956684:\n"
                 "LDR     R4, =0x6F060\n"
                 "LDR     R1, [R4]\n"
                 "CMP     R1, #0\n"
                 "BNE     loc_FF9566A8\n"
                 "MOV     R0, #0x3140\n"
                 "ADD     R0, R0, #8\n"
                 "BL      sub_FF96E0B0\n"
                 "MOV     R3, #1\n"
                 "STR     R3, [R4]\n"
 "loc_FF9566A8:\n"
                 "LDR     R3, =0x6F078\n"
                 "LDR     R0, =0x6F014\n"
                 "LDR     R2, [R3]\n"
                 "LDR     R12, =0x6EFFC\n"
                 "LDR     R1, [R0]\n"
                 "ADD     R3, R2, R2,LSL#2\n"
                 "ADD     R2, R2, R3,LSL#1\n"
                 "LDR     R0, [R12]\n"
                 "RSB     R1, R2, R1\n"
                 "CMP     R0, R1\n"
                 "BLS     loc_FF9566F8\n"
                 "LDR     R4, =0x6F060\n"
                 "LDR     R1, [R4]\n"
                 "CMP     R1, #0\n"
                 "BNE     loc_FF9566F8\n"
                 "MOV     R0, #0x3140\n"
                 "ADD     R0, R0, #8\n"
                 "BL      sub_FF96E0B0\n"
                 "MOV     R3, #1\n"
                 "STR     R3, [R4]\n"
 "loc_FF9566F8:\n"
                 "LDR     R3, =0x6F050\n"
                 "LDR     R12, =0x6F044\n"
                 "LDMIA   R3, {R1,R2}\n"
                 "LDR     R0, [R12]\n"
                 "MOV     R4, #0\n"
                 "MOV     R3, #0x18\n"
                 "ADDS    R1, R1, R0\n"
                 "ADC     R2, R2, #0\n"
                 "ADDS    R1, R1, R3\n"
                 "ADC     R2, R2, R4\n"
                 "CMP     R2, #0\n"
                 "BHI     loc_FF956734\n"
                 "BNE     loc_FF95673C\n"
                 "CMP     R1, #0x40000000\n"
              // "BLS     loc_FF95673C\n"     // -

                 "B       loc_FF95673C\n"     // +

 "loc_FF956734:\n"
                 "MOV     R0, #0x80000007\n"
                 "B       loc_FF956740\n"
 "loc_FF95673C:\n"
                 "MOV     R0, #0\n"
 "loc_FF956740:\n"
                 "ADD     SP, SP, #0x14\n"
                 "LDMFD   SP!, {R4-R11,PC}\n"
 );
}



void __attribute__((naked,noinline)) sub_FF955648_my(){
 asm volatile(
                 "CMP     R2, #1\n"
                 "STMFD   SP!, {R4-R7,LR}\n"
                 "MOV     R7, R0\n"
                 "MOV     R6, R1\n"
                 "MOVEQ   R3, #0x79\n"
                 "STREQ   R3, [R6]\n"
                 "LDMEQFD SP!, {R4-R7,PC}\n"
                 "LDR     R12, =0x6ED60\n"
                 "LDR     R0, [R12]\n"
                 "LDR     R3, =0x6ED68\n"
                 "CMP     R0, #0\n"
                 "LDR     R1, [R3]\n"
                 "BEQ     loc_FF955690\n"
                 "LDR     R2, =0x6ED6C\n"
                 "LDR     R3, [R2]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FF9556A4\n"
                 "B       loc_FF955694\n"
 "loc_FF955690:\n"
                 "LDR     R2, =0x6ED6C\n"
 "loc_FF955694:\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
                 "STR     R7, [R12]\n"
                 "B       loc_FF95575C\n"
 "loc_FF9556A4:\n"
                 "LDR     R2, =0x6ED64\n"
                 "LDR     R3, [R2]\n"
                 "LDR     R5, =table1\n"        // + 0xFF9554B8
                 "ADD     R3, R3, R3,LSL#1\n"
                 "MOV     LR, R3,LSL#2\n"
                 "LDR     R2, [R5,LR]\n"
                 "LDR     R4, =table2\n"        // + 0xFF9554DC
                 "RSB     R12, R2, R0\n"
                 "LDR     R3, [R4,LR]\n"
                 "CMP     R12, #0\n"
                 "RSB     R0, R3, R0\n"
                 "BLE     loc_FF955708\n"
                 "ADD     R3, R5, #4\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #1\n"
                 "BGE     loc_FF9556FC\n"
                 "ADD     R3, R5, #8\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #2\n"
                 "ADDLT   R1, R1, #3\n"
 "loc_FF9556FC:\n"
            //   "CMP     R1, #0xE\n"     // -
            //   "MOVGE   R1, #0xE\n"     // -

                 "CMP     R1, #0x1A\n"    // +      
                 "MOVGE   R1, #0x1A\n"    // +      

                 "B       loc_FF955740\n"
 "loc_FF955708:\n"
                 "CMP     R0, #0\n"
                 "BGE     loc_FF955740\n"
                 "ADD     R3, R4, #4\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #1\n"
                 "BLE     loc_FF955738\n"
                 "ADD     R3, R4, #8\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #2\n"
                 "SUBGT   R1, R1, #3\n"
 "loc_FF955738:\n"
                 "CMP     R1, #0\n"
                 "MOVLT   R1, #0\n"
 "loc_FF955740:\n"
                 "LDR     R0, =0x6ED68\n"
                 "LDR     R3, [R0]\n"
                 "CMP     R1, R3\n"
                 "LDRNE   R2, =0x6ED6C\n"
                 "MOVNE   R3, #1\n"
                 "STRNE   R1, [R0]\n"
                 "STRNE   R3, [R2]\n"
 "loc_FF95575C:\n"
                 "LDR     R3, =0x6ED68\n"
             //  "LDR     R1, =0x6138\n"  // -
                 "LDR     R1, =video_mode\n"  //+       
                 "LDR     R0, [R3]\n"
                 "LDR     R2, =CompressionRateTable\n"  // + 0xFF95547C
                 "LDR     R12, [R1]\n"
                 "LDR     R12, [R12]\n"          //+
                 "LDR     LR, [R2,R0,LSL#2]\n"
                 "LDR     R3, =0x6ED60\n"
                 "CMP     R12, #1\n"
                 "STR     R7, [R3]\n"
                 "STR     LR, [R6]\n"
              // "MOVEQ   R3, #0xB\n"  // -

                 "LDREQ   R3, =video_quality\n"   // +
                 "LDREQ   R3, [R3]\n"             // +
                 "LDREQ   R3, [R3]\n"             // +

                 "STREQ   R3, [R6]\n"
                  "BL      video_frame_counter\n"
                 "LDMFD   SP!, {R4-R7,PC}\n"
 );
}

