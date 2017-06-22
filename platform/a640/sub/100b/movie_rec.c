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


void __attribute__((naked,noinline)) sub_FFD4B9DC_my(){
 asm volatile(
                "CMP     R2, #1\n"
                "STMFD   SP!, {R4-R7,LR}\n"
                "MOV     R7, R0\n"
                "MOV     R6, R1\n"
                "MOVEQ   R3, #0x79\n"
                "STREQ   R3, [R6]\n"
                "LDMEQFD SP!, {R4-R7,PC}\n"
                "LDR     R12, =0x66950\n"
                "LDR     R0, [R12]\n"
                "LDR     R3, =0x66958\n"
                "CMP     R0, #0\n"
                "LDR     R1, [R3]\n"
                "BEQ     loc_FFD4BA24\n"
                "LDR     R2, =0x6695C\n"
                "LDR     R3, [R2]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FFD4BA38\n"
                "B       loc_FFD4BA28\n"
"loc_FFD4BA24:\n"                           
                "LDR     R2, =0x6695C\n"
"loc_FFD4BA28:\n"                           
                "MOV     R3, #0\n"
                "STR     R3, [R2]\n"
                "STR     R7, [R12]\n"
                "B       loc_FFD4BAF0\n"
"loc_FFD4BA38:\n"                           
                "LDR     R2, =0x66954\n"
                "LDR     R3, [R2]\n"
                "LDR     R5, =table1\n"        //+ 0xFFD4B84C
                "ADD     R3, R3, R3,LSL#1\n"
                "MOV     LR, R3,LSL#2\n"
                "LDR     R2, [R5,LR]\n"
                "LDR     R4, =table2\n"        // + 0xFFD4B870
                "RSB     R12, R2, R0\n"
                "LDR     R3, [R4,LR]\n"
                "CMP     R12, #0\n"
                "RSB     R0, R3, R0\n"
                "BLE     loc_FFD4BA9C\n"
                "ADD     R3, R5, #4\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #1\n"
                "BGE     loc_FFD4BA90\n"
                "ADD     R3, R5, #8\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #2\n"
                "ADDLT   R1, R1, #3\n"
"loc_FFD4BA90:\n"                           
          //    "CMP     R1, #0xE\n"   // -
          //    "MOVGE   R1, #0xE\n"   // -
                "CMP     R1, #0x1A\n"   // +
                "MOVGE   R1, #0x1A\n"   // +

                "B       loc_FFD4BAD4\n"
"loc_FFD4BA9C:\n"                           
                "CMP     R0, #0\n"
                "BGE     loc_FFD4BAD4\n"
                "ADD     R3, R4, #4\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #1\n"
                "BLE     loc_FFD4BACC\n"
                "ADD     R3, R4, #8\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #2\n"
                "SUBGT   R1, R1, #3\n"
"loc_FFD4BACC:\n"                           
                "CMP     R1, #0\n"
                "MOVLT   R1, #0\n"
"loc_FFD4BAD4:\n"                           
                                        
                "LDR     R0, =0x66958\n"
                "LDR     R3, [R0]\n"
                "CMP     R1, R3\n"
                "LDRNE   R2, =0x6695C\n"
                "MOVNE   R3, #1\n"
                "STRNE   R1, [R0]\n"
                "STRNE   R3, [R2]\n"
"loc_FFD4BAF0:\n"                           
                "LDR     R3, =0x66958\n"
        //      "LDR     R1, =0x61D8\n"  // - 
                "LDR     R1, =video_mode\n"  //+
                "LDR     R0, [R3]\n"
                "LDR     R2, =CompressionRateTable\n"
                "LDR     R12, [R1]\n"
                "LDR     R12, [R12]\n"    //+
                "LDR     LR, [R2,R0,LSL#2]\n"
                "LDR     R3, =0x66950\n"
                "CMP     R12, #1\n"
                "STR     R7, [R3]\n"
                "STR     LR, [R6]\n"
         //     "MOVEQ   R3, #0xB\n"   // -

                "LDREQ   R3, =video_quality\n"      //  + 
                "LDREQ   R3, [R3]\n"          //  +
                "LDREQ   R3, [R3]\n"          //  +

                "STREQ   R3, [R6]\n"
                "BL      mute_on_zoom\n"     // +
                "LDMFD   SP!, {R4-R7,PC}\n"
 );
}


void __attribute__((naked,noinline)) sub_FFD4C5EC_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R5, =0x66BEC\n"
                "SUB     SP, SP, #0x14\n"
                "LDR     LR, [R5]\n"
                "LDR     R12, =0x66C04\n"
                "ADD     LR, LR, #1\n"
                "LDR     R4, [R12]\n"
                "STR     LR, [R5]\n"
                "LDR     R12, =0x66C84\n"
                "STR     R0, [SP,#0x10]\n"
                "STR     R1, [SP,#0xC]\n"
                "STR     R2, [SP,#8]\n"
                "STR     R3, [SP,#4]\n"
                "CMP     LR, R4\n"
                "LDR     R11, [R12]\n"
                "MOVHI   R0, #0x80000001\n"
                "BHI     loc_FFD4CAD4\n"
                "LDR     R3, =0x66C68\n"
                "MOV     R0, LR\n"
                "LDR     R1, [R3]\n"
                "BL      sub_FFEF1464\n"
                "CMP     R0, #1\n"
                "BNE     loc_FFD4C80C\n"
                "LDR     R0, =0x66C8C\n"
                "LDR     R1, =0x66BD8\n"
                "LDR     R3, [R0]\n"
                "LDR     R2, [R1]\n"
                "CMP     R3, R2\n"
                "LDREQ   R3, =0x66C88\n"
                "LDREQ   R5, [R3]\n"
                "MOVNE   R5, R2\n"
                "LDR     R3, =0x66BEC\n"
                "LDR     R2, =0x66C68\n"
                "LDR     R0, [R3]\n"
                "LDR     R1, [R2]\n"
                "BL      sub_FFEF0DD4\n"
                "LDR     R3, =0x66BE0\n"
                "ADD     R0, R0, #1\n"
                "AND     R0, R0, #1\n"
                "STR     R5, [R3,R0,LSL#2]\n"
                "LDR     R3, =0x66BD4\n"
                "LDR     R2, [R3]\n"
                "CMP     R5, R2\n"
                "BHI     loc_FFD4C6BC\n"
                "LDR     R4, =0x66C24\n"
                "LDR     R3, [R4]\n"
                "ADD     R3, R5, R3\n"
                "ADD     R3, R3, #8\n"
                "CMP     R2, R3\n"
                "BCS     loc_FFD4C6C0\n"
"loc_FFD4C6B4:\n"                           
                                        
                "MOV     R0, #0x80000003\n"
                "B       loc_FFD4CAD4\n"
"loc_FFD4C6BC:\n"                           
                "LDR     R4, =0x66C24\n"
"loc_FFD4C6C0:\n"                           
                "LDR     R3, [R4]\n"
                "LDR     R2, =0x66C8C\n"
                "ADD     R1, R5, R3\n"
                "LDR     R3, [R2]\n"
                "ADD     R2, R1, #8\n"
                "CMP     R2, R3\n"
                "BLS     loc_FFD4C70C\n"
                "LDR     R2, =0x66C88\n"
                "LDR     R0, =0x66BD4\n"
                "RSB     R3, R3, R1\n"
                "LDR     R1, [R2]\n"
                "ADD     R3, R3, #8\n"
                "LDR     R2, [R0]\n"
                "ADD     R1, R1, R3\n"
                "CMP     R2, R1\n"
                "BCC     loc_FFD4C6B4\n"
                "LDR     R3, =0x66BD8\n"
                "STR     R1, [R3]\n"
                "B       loc_FFD4C714\n"
"loc_FFD4C70C:\n"                           
                "LDR     R3, =0x66BD8\n"
                "STR     R2, [R3]\n"
"loc_FFD4C714:\n"                           
                "LDR     R3, [R4]\n"
                "LDR     R12, =0x66C38\n"
                "ADD     R3, R3, #0x18\n"
                "LDR     R2, [R12,#4]\n"
                "MOV     R0, R3\n"
                "MOV     R1, #0\n"
                "CMP     R1, R2\n"
                "BHI     loc_FFD4C958\n"
                "BNE     loc_FFD4C744\n"
                "LDR     R3, [R12]\n"
                "CMP     R0, R3\n"
                "BHI     loc_FFD4C958\n"
"loc_FFD4C744:\n"                           
                "LDR     R4, [R4]\n"
                "LDR     LR, =0x66C40\n"
                "STR     R4, [SP]\n"
                "LDR     R12, =0x66C38\n"
                "LDR     R3, =0x66BEC\n"
                "LDMIA   LR, {R7,R8}\n"
                "LDMIA   R12, {R5,R6}\n"
                "LDR     R10, [R3]\n"
                "LDR     R2, =0x66C68\n"
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
                "BL      sub_FFEF0DD4\n"
                "CMP     R10, #1\n"
                "MLA     R0, R9, R0, R0\n"
                "BEQ     loc_FFD4C80C\n"
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
"loc_FFD4C80C:\n"                           
                                        
                "LDR     R2, =0x66BD8\n"
                "LDR     R3, =0x66C8C\n"
                "LDR     R1, [R2]\n"
                "LDR     R0, [R3]\n"
                "ADD     R3, R1, #9\n"
                "CMP     R3, R0\n"
                "BLS     loc_FFD4C848\n"
                "LDR     R2, =0x66C88\n"
                "LDR     R3, [R2]\n"
                "ADD     R3, R3, R1\n"
                "RSB     R3, R0, R3\n"
                "LDR     R0, [SP,#0x10]\n"
                "ADD     R3, R3, #8\n"
                "STR     R3, [R0]\n"
                "B       loc_FFD4C854\n"
"loc_FFD4C848:\n"                           
                "ADD     R3, R1, #8\n"
                "LDR     R1, [SP,#0x10]\n"
                "STR     R3, [R1]\n"
"loc_FFD4C854:\n"                           
                "LDR     R2, [SP,#0x10]\n"
                "LDR     R1, =0x66C34\n"
                "LDR     R3, =0x66C8C\n"
                "LDR     R12, [R2]\n"
                "LDR     R2, [R1]\n"
                "LDR     R0, [R3]\n"
                "ADD     R3, R12, R2\n"
                "CMP     R3, R0\n"
                "BLS     loc_FFD4C8A8\n"
                "LDR     R2, [SP,#0xC]\n"
                "RSB     R0, R12, R0\n"
                "STR     R0, [R2]\n"
                "LDR     R2, =0x66C88\n"
                "LDR     R3, [R1]\n"
                "LDR     R1, [R2]\n"
                "RSB     R3, R0, R3\n"
                "LDR     R0, [SP,#8]\n"
                "STR     R1, [R0]\n"
                "LDR     R1, [SP,#4]\n"
                "STR     R3, [R1]\n"
                "B       loc_FFD4C8C4\n"
"loc_FFD4C8A8:\n"                           
                "LDR     R0, [SP,#0xC]\n"
                "STR     R2, [R0]\n"
                "LDR     R1, [SP,#4]\n"
                "MOV     R3, #0\n"
                "STR     R3, [R1]\n"
                "LDR     R2, [SP,#8]\n"
                "STR     R3, [R2]\n"
"loc_FFD4C8C4:\n"                           
                "LDR     R0, =0x66BD8\n"
                "LDR     R1, =0x66BD4\n"
                "LDR     R3, [R0]\n"
                "LDR     R2, [R1]\n"
                "CMP     R3, R2\n"
                "BHI     loc_FFD4C8F0\n"
                "LDR     R0, [SP,#0xC]\n"
                "LDR     R3, [R0]\n"
                "ADD     R3, R12, R3\n"
                "CMP     R2, R3\n"
                "BCC     loc_FFD4C6B4\n"
"loc_FFD4C8F0:\n"                           
                "LDR     R1, [SP,#8]\n"
                "LDR     R2, [R1]\n"
                "CMP     R2, #0\n"
                "BEQ     loc_FFD4C924\n"
                "LDR     R3, =0x66BD4\n"
                "LDR     R1, [R3]\n"
                "CMP     R2, R1\n"
                "BHI     loc_FFD4C924\n"
                "LDR     R0, [SP,#4]\n"
                "LDR     R3, [R0]\n"
                "ADD     R3, R2, R3\n"
                "CMP     R1, R3\n"
                "BCC     loc_FFD4C6B4\n"
"loc_FFD4C924:\n"                           
                                        
                "LDR     R3, =0x66C34\n"
                "LDR     R0, =0x66C38\n"
                "LDR     R2, [R3]\n"
                "LDR     R3, [R0,#4]\n"
                "ADD     R2, R2, #0x18\n"
                "MOV     R1, R2\n"
                "MOV     R2, #0\n"
                "CMP     R2, R3\n"
                "BHI     loc_FFD4C958\n"
                "BNE     loc_FFD4C960\n"
                "LDR     R3, [R0]\n"
                "CMP     R1, R3\n"
                "BLS     loc_FFD4C960\n"
"loc_FFD4C958:\n"                           
                                        
                "MOV     R0, #0x80000005\n"
                "B       loc_FFD4CAD4\n"
"loc_FFD4C960:\n"                           
                                        
                "LDR     R1, =0x66C1C\n"
                "LDR     R0, =0x66C68\n"
                "LDR     R3, [R1]\n"
                "LDR     R2, [R0]\n"
                "ADD     R3, R3, R2,LSL#4\n"
                "ADD     R3, R3, R3,LSL#2\n"
                "LDR     R12, =0x66C38\n"
                "MOV     R3, R3,LSL#1\n"
                "ADD     R3, R3, #0xA0\n"
                "LDR     R2, [R12,#4]\n"
                "MOV     R0, R3\n"
                "MOV     R1, #0\n"
                "CMP     R1, R2\n"
                "BHI     loc_FFD4C9A8\n"
                "BNE     loc_FFD4C9CC\n"
                "LDR     R3, [R12]\n"
                "CMP     R0, R3\n"
                "BLS     loc_FFD4C9CC\n"
"loc_FFD4C9A8:\n"                           
                "LDR     R4, =0x66C50\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FFD4C9CC\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FFD66990\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FFD4C9CC:\n"                           
                                        
                "LDR     R1, =0x66C1C\n"
                "LDR     R0, =0x66C68\n"
                "LDR     R2, [R1]\n"
                "LDR     R3, [R0]\n"
                "LDR     R0, =0x66C40\n"
                "ADD     R2, R2, R3,LSL#4\n"
                "MVN     R3, #0x9F\n"
                "ADD     R2, R2, R2,LSL#2\n"
                "ADD     R3, R3, #0x40000000\n"
                "SUB     R3, R3, R2,LSL#1\n"
                "LDR     R1, [R0,#4]\n"
                "MOV     R4, R3\n"
                "MOV     R5, #0\n"
                "CMP     R1, R5\n"
                "BHI     loc_FFD4CA18\n"
                "BNE     loc_FFD4CA3C\n"
                "LDR     R3, [R0]\n"
                "CMP     R3, R4\n"
                "BLS     loc_FFD4CA3C\n"
"loc_FFD4CA18:\n"                           
                "LDR     R4, =0x66C50\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FFD4CA3C\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FFD66990\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FFD4CA3C:\n"                           
                                        
                "LDR     R3, =0x66C68\n"
                "LDR     R0, =0x66C04\n"
                "LDR     R2, [R3]\n"
                "LDR     R12, =0x66BEC\n"
                "LDR     R1, [R0]\n"
                "ADD     R3, R2, R2,LSL#2\n"
                "ADD     R2, R2, R3,LSL#1\n"
                "LDR     R0, [R12]\n"
                "RSB     R1, R2, R1\n"
                "CMP     R0, R1\n"
                "BLS     loc_FFD4CA8C\n"
                "LDR     R4, =0x66C50\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FFD4CA8C\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FFD66990\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FFD4CA8C:\n"                           
                                        
                "LDR     R3, =0x66C40\n"
                "LDR     R12, =0x66C34\n"
                "LDMIA   R3, {R1,R2}\n"
                "LDR     R0, [R12]\n"
                "MOV     R4, #0\n"
                "MOV     R3, #0x18\n"
                "ADDS    R1, R1, R0\n"
                "ADC     R2, R2, #0\n"
                "ADDS    R1, R1, R3\n"
                "ADC     R2, R2, R4\n"
                "CMP     R2, #0\n"
                "BHI     loc_FFD4CAC8\n"
                "BNE     loc_FFD4CAD0\n"
                "CMP     R1, #0x40000000\n"
              //  "BLS     loc_FFD4CAD0\n"    // original
                "B       loc_FFD4CAD0\n"

"loc_FFD4CAC8:\n"                           
                "MOV     R0, #0x80000007\n"
                "B       loc_FFD4CAD4\n"
"loc_FFD4CAD0:\n"                           
                                        
                "MOV     R0, #0\n"
"loc_FFD4CAD4:\n"                           
                                        
                "ADD     SP, SP, #0x14\n"
                "LDMFD   SP!, {R4-R11,PC}\n"

 );
}


void __attribute__((naked,noinline)) sub_FFD4AF18_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R5, =0x66894\n"
                "SUB     SP, SP, #0x34\n"
                "LDR     R3, [R5]\n"
                "CMP     R3, #3\n"
                "MOV     R4, R0\n"
                "MOVEQ   R3, #4\n"
                "STREQ   R3, [R5]\n"
                "LDR     R3, =0x66944\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R3]\n"
                "LDR     R2, [R5]\n"
                "CMP     R2, #4\n"
                "BNE     loc_FFD4B0DC\n"
                "ADD     R0, SP, #0x30\n"
                "ADD     R1, SP, #0x2C\n"
                "ADD     R2, SP, #0x28\n"
                "ADD     R3, SP, #0x24\n"
                "BL      sub_FFD4C5EC_my\n"   //------------------>
                "CMP     R0, #0\n"
                "BNE     loc_FFD4AF94\n"
                "LDR     R3, =0x66880\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #1\n"
                "BNE     loc_FFD4AFA8\n"
                "LDR     R2, =0x668D8\n"
                "LDR     R1, =0x668AC\n"
                "LDR     R12, [R2]\n"
                "LDR     R3, [R1]\n"
                "CMP     R12, R3\n"
                "BCC     loc_FFD4AFA8\n"
"loc_FFD4AF94:\n"                           
                "BL      sub_FFD4B128\n"
                "BL      sub_FFD4B328\n"
                "MOV     R3, #5\n"
                "STR     R3, [R5]\n"
                "B       loc_FFD4B0DC\n"
"loc_FFD4AFA8:\n"                           
                                        
                "LDR     R12, =0x668E0\n"
                "LDR     R11, =0x668EC\n"
                "LDMIB   R4, {R0-R2}\n"
                "LDR     R10, [R12]\n"
                "LDR     R7, [R11]\n"
                "LDR     R4, [SP,#0x2C]\n"
                "LDR     R5, [SP,#0x28]\n"
                "LDR     R6, [SP,#0x24]\n"
                "LDR     R8, =0x66884\n"
                "LDR     R3, [SP,#0x30]\n"
                "ADD     R12, SP, #0x20\n"
                "ADD     LR, SP, #0x1C\n"
                "MOV     R9, #1\n"
                "STMEA   SP, {R4-R6,R12}\n"
                "STR     R10, [SP,#0x10]\n"
                "STR     R7, [SP,#0x14]\n"
                "STR     LR, [SP,#0x18]\n"
                "STR     R9, [R8]\n"
                "BL      sub_FFC89308\n"
                "LDR     R3, =0x6679C\n"
                "MOV     R1, #0x3E8\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC11B64\n"
                "CMP     R0, #9\n"
                "BNE     loc_FFD4B01C\n"
                "BL      sub_FFD4CDFC\n"
                "LDR     R3, =0x66894\n"
                "LDR     R0, =0xFFD4AF00\n"
                "B       loc_FFD4B034\n"
"loc_FFD4B01C:\n"                           
                "LDR     R5, [SP,#0x1C]\n"
                "CMP     R5, #0\n"
                "BEQ     loc_FFD4B040\n"
                "BL      sub_FFD4CDFC\n"
                "LDR     R3, =0x66894\n"
                "LDR     R0, =0xFFD4AF0C\n"
"loc_FFD4B034:\n"                           
                "STR     R9, [R3]\n"
                "BL      sub_FFD62110\n"
                "B       loc_FFD4B0DC\n"
"loc_FFD4B040:\n"                           
                "BL      sub_FFC89474\n"
                "LDR     R0, [SP,#0x30]\n"
                "LDR     R1, [SP,#0x20]\n"
                "BL      sub_FFD4CB20\n"
                "LDR     R4, =0x668D8\n"
                "LDR     R3, [R4]\n"
                "ADD     R3, R3, #1\n"
                "LDR     R0, [SP,#0x20]\n"
                "MOV     R1, R11\n"
                "STR     R3, [R4]\n"
                "MOV     R2, R5\n"
                "BL      sub_FFD4B9DC_my\n"  //------------------>
                "LDR     R3, =0x668F8\n"
                "LDR     R1, [R4]\n"
                "LDR     R2, [R3]\n"
                "LDR     R12, =0x668F4\n"
                "MUL     R0, R2, R1\n"
                "LDR     R1, [R12]\n"
                "BL      sub_FFEF0DD4\n"
                "LDR     R7, =0x668F0\n"
                "LDR     R3, [R7]\n"
                "MOV     R4, R0\n"
                "CMP     R3, R4\n"
                "BNE     loc_FFD4B0B4\n"
                "LDR     R6, =0x66888\n"
                "LDR     R3, [R6]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FFD4B0D0\n"
                "B       loc_FFD4B0B8\n"
"loc_FFD4B0B4:\n"                           
                "LDR     R6, =0x66888\n"
"loc_FFD4B0B8:\n"                           
                "LDR     R3, =0x66928\n"
                "MOV     R0, R4\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R3]\n"
                "STR     R5, [R6]\n"
                "STR     R4, [R7]\n"
"loc_FFD4B0D0:\n"                           
                "LDR     R2, =0x66884\n"
                "MOV     R3, #0\n"
                "STR     R3, [R2]\n"
"loc_FFD4B0DC:\n"                           
                                        
                "ADD     SP, SP, #0x34\n"
                "LDMFD   SP!, {R4-R11,PC}\n"
 );
}





void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R4, SP\n"
                "B       loc_FFD4A840\n"
"loc_FFD4A79C:\n"                           
                "LDR     R3, =0x66878\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "BNE     loc_FFD4A82C\n"
                "SUB     R3, R12, #2\n"
                "CMP     R3, #9\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FFD4A82C\n"
                ".long loc_FFD4A7EC\n"
                ".long loc_FFD4A804\n"
                ".long loc_FFD4A80C\n"
                ".long loc_FFD4A814\n"
                ".long loc_FFD4A7F4\n"
                ".long loc_FFD4A81C\n"
                ".long loc_FFD4A7FC\n"
                ".long loc_FFD4A82C\n"
                ".long loc_FFD4A824\n"
                ".long loc_FFD4A7E4\n"
"loc_FFD4A7E4:\n"                           
                                        
                "BL      sub_FFD4A8D8\n"
                "B       loc_FFD4A828\n"
"loc_FFD4A7EC:\n"                           

                "BL      unlock_optical_zoom\n"                        
                "BL      sub_FFD4AA8C\n" 
                "B       loc_FFD4A828\n"
"loc_FFD4A7F4:\n"                           
                                        
                "BL      sub_FFD4AF18_my\n" //--------------->
                "B       loc_FFD4A828\n"
"loc_FFD4A7FC:\n"                           
                                        
                "BL      sub_FFD4B34C\n"
                "B       loc_FFD4A828\n"
"loc_FFD4A804:\n"                           
                                        
                "BL      sub_FFD4B1B0\n"
                "B       loc_FFD4A828\n"
"loc_FFD4A80C:\n"                           
                                        
                "BL      sub_FFD4B4BC\n"
                "B       loc_FFD4A828\n"
"loc_FFD4A814:\n"                           
                                        
                "BL      sub_FFD4B680\n"
                "B       loc_FFD4A828\n"
"loc_FFD4A81C:\n"                           
                                        
                "BL      sub_FFD4B3D4\n"
                "B       loc_FFD4A828\n"
"loc_FFD4A824:\n"                           
                                        
                "BL      sub_FFD4B200\n"
"loc_FFD4A828:\n"                           
                                        
                "LDR     R1, [SP]\n"
"loc_FFD4A82C:\n"                           
                "LDR     R3, =0x667AC\n"
                "MOV     R2, #0\n"
                "STR     R2, [R1]\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC113D0\n"
"loc_FFD4A840:\n"                
                "LDR     R3, =0x667A8\n"
                "MOV     R1, R4\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, #0\n"
                "BL      sub_FFC10FB8\n"
                "LDR     R0, [SP]\n"
                "LDR     R12, [R0]\n"
                "CMP     R12, #0xC\n"
                "MOV     R1, R0\n"
                "BNE     loc_FFD4A79C\n"
                "LDR     R3, =0x667A4\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC11D4C\n"
                "BL      sub_FFC12514\n"
                "ADD     SP, SP, #4\n"
                "LDMFD   SP!, {R4,PC}\n"
 );
}

