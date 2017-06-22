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
                "STMFD   SP!, {R4,R5,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R5, SP\n"
                "MOV     R4, #0\n"
"loc_FFB815B0:\n"
                "LDR     R3, =0xBB420\n"
                "MOV     R2, #0\n"
                "LDR     R0, [R3]\n"
                "MOV     R1, R5\n"
                "BL      sub_FFB1358C\n"
                "LDR     R3, =0xBB540\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "BNE     loc_FFB8165C\n"
                "LDR     R1, [SP]\n"
                "LDR     R3, [R1]\n"
                "SUB     R3, R3, #2\n"
                "MOV     R0, R1\n"
                "CMP     R3, #9\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FFB81660\n"
                ".long loc_FFB81620\n"
                ".long loc_FFB81638\n"
                ".long loc_FFB81640\n"
                ".long loc_FFB81648\n"
                ".long loc_FFB81628\n"
                ".long loc_FFB81650\n"
                ".long loc_FFB81630\n"
                ".long loc_FFB81660\n"
                ".long loc_FFB81658\n"
                ".long loc_FFB81618\n"
"loc_FFB81618:\n"
                "BL      sub_FFB816CC\n"
                "B       loc_FFB8165C\n"
"loc_FFB81620:\n"
                "BL      unlock_optical_zoom\n"
                "BL      sub_FFB818D4\n"
                "B       loc_FFB8165C\n"
"loc_FFB81628:\n"
                "BL      sub_FFB81CB4_my\n"  //----------->
                "B       loc_FFB8165C\n"
"loc_FFB81630:\n"
                "BL      sub_FFB82544\n"
                "B       loc_FFB8165C\n"
"loc_FFB81638:\n"
                "BL      sub_FFB81FF8\n"
                "B       loc_FFB8165C\n"
"loc_FFB81640:\n"
                "BL      sub_FFB826E0\n"
                "B       loc_FFB8165C\n"
"loc_FFB81648:\n"
                "BL      sub_FFB828C0\n"
                "B       loc_FFB8165C\n"
"loc_FFB81650:\n"
                "BL      sub_FFB825CC\n"
                "B       loc_FFB8165C\n"
"loc_FFB81658:\n"
                "BL      sub_FFB82048\n"
"loc_FFB8165C:\n"
                "LDR     R1, [SP]\n"
"loc_FFB81660:\n"
                "LDR     R3, =0xBB424\n"
                "STR     R4, [R1]\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, R4\n"
                "BL      sub_FFB139A4\n"
                "B       loc_FFB815B0\n"
 );
}

void __attribute__((naked,noinline)) sub_FFB81CB4_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R7, =0xBB558\n"
                "SUB     SP, SP, #0x3C\n"
                "LDR     R3, [R7]\n"
                "MOV     R5, #0\n"
                "CMP     R3, #3\n"
                "MOV     R4, R0\n"
                "STR     R5, [SP,#0x34]\n"
                "STR     R5, [SP,#0x2C]\n"
                "MOV     R6, #1\n"
                "MOVEQ   R3, #4\n"
                "STREQ   R3, [R7]\n"
                "LDR     R3, =0xBB604\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R3]\n"
                "LDR     R2, [R7]\n"
                "CMP     R2, #4\n"
                "BNE     loc_FFB81F10\n"
                "LDR     R3, =0xBB646\n"
                "LDRH    R2, [R3]\n"
                "CMP     R2, #1\n"
                "BNE     loc_FFB81D44\n"
                "LDR     R2, =0xBB568\n"
                "LDR     R1, =0xBB648\n"
                "LDR     R0, [R2]\n"
                "LDRH    R3, [R1]\n"
                "MUL     R12, R3, R0\n"
                "LDR     R2, =0x10624DD3\n"
                "UMULL   R3, R1, R2, R12\n"
                "LDR     R3, =0xBB584\n"
                "MOV     R1, R1,LSR#6\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FF914660\n"
                "CMP     R0, #0\n"
                "MOVNE   R6, #0\n"
                "MOVEQ   R6, #1\n"
"loc_FFB81D44:\n"
                "CMP     R6, #1\n"
                "BNE     loc_FFB81D64\n"
                "ADD     R0, SP, #0x38\n"
                "ADD     R1, SP, #0x34\n"
                "ADD     R2, SP, #0x30\n"
                "ADD     R3, SP, #0x2C\n"
                "BL      sub_FFB8347C\n"
                "MOV     R5, R0\n"
"loc_FFB81D64:\n"
                "CMP     R5, #0\n"
                "BNE     loc_FFB81D94\n"
                "LDR     R3, =0xBB548\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #1\n"
                "BNE     loc_FFB81DA8\n"
                "LDR     R2, =0xBB584\n"
                "LDR     R1, =0xBB55C\n"
                "LDR     R0, [R2]\n"
                "LDR     R3, [R1]\n"
                "CMP     R0, R3\n"
                "BCC     loc_FFB81DA8\n"
"loc_FFB81D94:\n"
                "MOV     R0, R5\n"
                "BL      sub_FFB81F70\n"
                "BL      sub_FFB82504\n"
                "MOV     R3, #5\n"
                "B       loc_FFB81F0C\n"
"loc_FFB81DA8:\n"
                "LDR     R9, [SP,#0x34]\n"
                "CMP     R9, #0\n"
                "BEQ     loc_FFB81E90\n"
                "LDR     R7, =0xBB5A0\n"
                "LDR     R12, =0xBB58C\n"
                "LDMIB   R4, {R0-R2}\n"
                "LDR     R10, [R4,#0x18]\n"
                "LDR     R6, [R7]\n"
                "LDR     R7, [R4,#0x14]\n"
                "LDR     R4, =0xBB54C\n"
                "LDR     R8, [R12]\n"
                "ADD     R5, SP, #0x2C\n"
                "LDMIA   R5, {R5,LR}\n"
                "MOV     R11, #1\n"
                "LDR     R3, [SP,#0x38]\n"
                "ADD     R12, SP, #0x28\n"
                "STR     R11, [R4]\n"
                "ADD     R4, SP, #0x24\n"
                "STMEA   SP, {R9,LR}\n"
                "STR     R5, [SP,#8]\n"
                "STR     R12, [SP,#0xC]\n"
                "STR     R8, [SP,#0x10]\n"
                "STR     R6, [SP,#0x14]\n"
                "STR     R7, [SP,#0x18]\n"
                "STR     R10, [SP,#0x1C]\n"
                "STR     R4, [SP,#0x20]\n"
                "BL      sub_FFB86528\n"
                "LDR     R3, =0xBB418\n"
                "MOV     R1, #0x3E8\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFB14154\n"
                "CMP     R0, #9\n"
                "BNE     loc_FFB81E3C\n"
                "BL      sub_FFB83D0C\n"
                "LDR     R3, =0xBB558\n"
                "LDR     R0, =0xFFB81C9C\n"
                "B       loc_FFB81E54\n"
"loc_FFB81E3C:\n"
                "LDR     R4, [SP,#0x24]\n"
                "CMP     R4, #0\n"
                "BEQ     loc_FFB81E60\n"
                "BL      sub_FFB83D0C\n"
                "LDR     R3, =0xBB558\n"
                "LDR     R0, =0xFFB81CA8\n"
"loc_FFB81E54:\n"
                "STR     R11, [R3]\n"
                "BL      sub_FFB36F08\n"
                "B       loc_FFB81F10\n"
"loc_FFB81E60:\n"
                "BL      sub_FFB866A4\n"
                "LDR     R0, [SP,#0x38]\n"
                "LDR     R1, [SP,#0x28]\n"
                "BL      sub_FFB83964\n"
                "LDR     R12, =0xBB580\n"
                "LDR     R3, [R12]\n"
                "ADD     R3, R3, #1\n"
                "LDR     R0, [SP,#0x28]\n"
                "LDR     R1, =0xBB5A0\n"
                "MOV     R2, R4\n"
                "STR     R3, [R12]\n"
                "BL      sub_FFAF2BC4_my\n"  //-------------->
"loc_FFB81E90:\n"
                "LDR     R4, =0xBB584\n"
                "LDR     R2, =0xBB5AC\n"
                "LDR     R3, [R4]\n"
                "LDR     R1, [R2]\n"
                "LDR     R12, =0xBB5A8\n"
                "ADD     R3, R3, #1\n"
                "MUL     R0, R1, R3\n"
                "LDR     R1, [R12]\n"
                "STR     R3, [R4]\n"
                "BL      sub_FF9145C8\n"
                "LDR     R6, =0xBB5A4\n"
                "MOV     R4, R0\n"
                "BL      sub_FFB83D48\n"
                "LDR     R3, [R6]\n"
                "CMP     R3, R4\n"
                "BNE     loc_FFB81EE4\n"
                "LDR     R5, =0xBB550\n"
                "LDR     R3, [R5]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FFB81F04\n"
                "B       loc_FFB81EE8\n"
"loc_FFB81EE4:\n"
                "LDR     R5, =0xBB550\n"
"loc_FFB81EE8:\n"
                "LDR     R2, =0xBB5E8\n"
                "MOV     R0, R4\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R2]\n"
                "MOV     R3, #0\n"
                "STR     R3, [R5]\n"
                "STR     R4, [R6]\n"
"loc_FFB81F04:\n"
                "LDR     R7, =0xBB54C\n"
                "MOV     R3, #0\n"
"loc_FFB81F0C:\n"
                "STR     R3, [R7]\n"
"loc_FFB81F10:\n"
                "ADD     SP, SP, #0x3C\n"
                "LDMFD   SP!, {R4-R11,PC}\n"

 );
}

void __attribute__((naked,noinline)) sub_FFAF2BC4_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n"
                "LDR     R12, =0x96ED4\n"
                "LDR     R4, [R12]\n"
                "LDR     R3, =0x96EDC\n"
                "CMP     R4, #0\n"
                "MOV     R8, R1\n"
                "MOV     R7, R0\n"
                "LDR     R1, [R3]\n"
                "BEQ     loc_FFAF2BFC\n"
                "LDR     R2, =0x96EE0\n"
                "LDR     R3, [R2]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FFAF2C10\n"
                "B       loc_FFAF2C00\n"
"loc_FFAF2BFC:\n"
                "LDR     R2, =0x96EE0\n"
"loc_FFAF2C00:\n"
                "MOV     R3, #0\n"
                "STR     R3, [R2]\n"
                "STR     R7, [R12]\n"
                "B       loc_FFAF2CC8\n"
"loc_FFAF2C10:\n"
                "LDR     R2, =0x96ED8\n"
                "LDR     R3, [R2]\n"
                "LDR     R6, =table1\n" // 0xFFAF2AC8
                "ADD     R3, R3, R3,LSL#1\n"
                "MOV     LR, R3,LSL#2\n"
                "LDR     R2, [R6,LR]\n"
                "LDR     R5, =table2\n" // 0xFFAF2AEC
                "RSB     R12, R2, R4\n"
                "LDR     R3, [R5,LR]\n"
                "CMP     R12, #0\n"
                "RSB     R0, R3, R4\n"
                "BLE     loc_FFAF2C74\n"
                "ADD     R3, R6, #4\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #1\n"
                "BGE     loc_FFAF2C68\n"
                "ADD     R3, R6, #8\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #2\n"
                "ADDLT   R1, R1, #3\n"
"loc_FFAF2C68:\n"
          //    "CMP     R1, #0x16\n"
          //    "MOVGE   R1, #0x16\n"
                "CMP     R1, #0x1A\n"     // + 
                "MOVGE   R1, #0x1A\n"     // + 

                "B       loc_FFAF2CAC\n"
"loc_FFAF2C74:\n"
                "CMP     R0, #0\n"
                "BGE     loc_FFAF2CAC\n"
                "ADD     R3, R5, #4\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #1\n"
                "BLE     loc_FFAF2CA4\n"
                "ADD     R3, R5, #8\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #2\n"
                "SUBGT   R1, R1, #3\n"
"loc_FFAF2CA4:\n"
                "CMP     R1, #0\n"
                "MOVLT   R1, #0\n"
"loc_FFAF2CAC:\n"
                "LDR     R0, =0x96EDC\n"
                "LDR     R3, [R0]\n"
                "CMP     R1, R3\n"
                "LDRNE   R2, =0x96EE0\n"
                "MOVNE   R3, #1\n"
                "STRNE   R1, [R0]\n"
                "STRNE   R3, [R2]\n"
"loc_FFAF2CC8:\n"
                "LDR     R3, =0x96EDC\n"
                "LDR     R2, =CompressionRateTable\n" 
                "LDR     R1, [R3]\n"
                "LDR     R0, =0x96ED4\n"
                "LDR     R3, [R2,R1,LSL#2]\n"

                "LDR     R1, =video_mode\n"      // +
                "LDR     R1, [R1]\n"             // +
                "LDR     R1, [R1]\n"             // +
                "CMP     R1, #1\n"               // +
                "LDREQ   R1, =video_quality\n"   // +     
                "LDREQ   R1, [R1]\n"             // +     
                "LDREQ   R3, [R1]\n"             // +     

                "STR     R7, [R0]\n"
                "STR     R3, [R8]\n"
                  "BL      video_frame_counter\n"
                "LDMFD   SP!, {R4-R8,PC}\n"
 );
}
