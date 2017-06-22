#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[56]={
0x10000,0xC000,0x5800, 0x2000, 0x1C6A, 0x1550,0x9C5,  0x38D,  0x3C45, 0x2D34, 0x14B8, 0x788,  0x5F60, 0x4788,
0x20C9, 0xBE1, 0x8661, 0x64C9, 0x2E31, 0x10CB,0xB21A, 0x8594, 0x3D39, 0x1642, 0xE249, 0xA9B8, 0x4DC9, 0x1C48,
0x117D2,0xD1DF,0x6030, 0x22F9, 0x153D5,0xFEE1,0x74D1, 0x2A79, 0x195F8,0x1307C,0x8B8D, 0x32AA, 0x1E01C,0x16817,
0xA509, 0x3C01,0x2328E,0x1A5ED,0xC160, 0x4637,0x28C99,0x1E975,0xE054, 0x5190, 0x2F08B,0x2346B,0x102AF,0x5E0E
};

long def_table2[12]={0xE666,0xACCD,0x4F33,0x1CCD,-0x170A,-0x1148,-0x7EB,-0x2E1,-0x2BC6,-0x20D5,-0xF0C,-0x579};

long table1[56], table2[12];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<56;i++) table1[i]=(def_table1[i]*a)/b;
 for (i=0;i<12;i++) table2[i]=(def_table2[i]*a)/b;
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                 "STMFD   SP!, {R4,LR}\n"
                 "SUB     SP, SP, #4\n"
                 "MOV     R4, SP\n"
                 "B       loc_FF943EB8\n"
"loc_FF943E08:\n"
                 "LDR     R3, =0x73850\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #0\n"
                 "BNE     loc_FF943EA4\n"                                       
                 "SUB     R3, R12, #1\n"
                 "CMP     R3, #0xA\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FF943EA4\n"                                   
				 ".long loc_FF943E54\n"
				 ".long loc_FF943E5C\n"
				 ".long loc_FF943E74\n"
				 ".long loc_FF943E7C\n"
				 ".long loc_FF943E84\n"
				 ".long loc_FF943E64\n"
				 ".long loc_FF943E8C\n"
				 ".long loc_FF943E6C\n"
				 ".long loc_FF943EA4\n"
				 ".long loc_FF943E9C\n"
				 ".long loc_FF943E94\n"

"loc_FF943E54:\n"                                       
                 "BL      sub_FF943F38\n"
                 "B       loc_FF943EA0\n"
 "loc_FF943E5C:\n"                                        
                 "BL	 unlock_optical_zoom\n"
                 "BL      sub_FF94416C\n"
                 "B       loc_FF943EA0\n"
 "loc_FF943E64:\n"                                         
                "BL      sub_FF9445FC_my\n"    //--------------------->
                 "B       loc_FF943EA0\n"
 "loc_FF943E6C:\n"                                       
                 "BL      sub_FF944A50\n"
                 "B       loc_FF943EA0\n"
 "loc_FF943E74:\n"                                         
                 "BL      sub_FF944874\n"
                 "B       loc_FF943EA0\n"
 "loc_FF943E7C:\n"                                         
                 "BL      sub_FF944C5C\n"
                 "B       loc_FF943EA0\n"
 "loc_FF943E84:\n"                                        
                 "BL      sub_FF944E20\n"
                 "B       loc_FF943EA0\n"
"loc_FF943E8C:\n"                                        
                 "BL      sub_FF944B10\n"
                 "B       loc_FF943EA0\n"
 "loc_FF943E94:\n"                                         
                 "BL      sub_FF944BF0\n"
                 "B       loc_FF943EA0\n"
 "loc_FF943E9C:\n"                                         
                 "BL      sub_FF9448C4\n"
"loc_FF943EA0:\n"                                       
                 "LDR     R1, [SP]\n"
"loc_FF943EA4:\n"                                       
                 "LDR     R3, =0x73780\n"                                        
                 "MOV     R2, #0\n"
                 "STR     R2, [R1]\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF8212BC\n" //PostMessageQueue\n"
"loc_FF943EB8:\n"
                 "LDR     R3, =0x7377C\n"
                 "MOV     R1, R4\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R2, #0\n"
                 "BL      sub_FF820EA4\n"//ReceiveMessageQueue\n"
                 "LDR     R0, [SP]\n"
                 "LDR     R12, [R0]\n"
                 "CMP     R12, #0xC\n"
                 "MOV     R1, R0\n"
                 "BNE     loc_FF943E08\n"
                 "LDR     R3, =0x73774\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF821C78\n" //GiveSemaphore
                 "BL      sub_FF822634\n" //ExitTask\n"
                 "ADD     SP, SP, #4\n"
                 "LDMFD   SP!, {R4,PC}\n"
 );
}


//void __attribute__((naked,noinline)) sub_FF944274_my(){
void __attribute__((naked,noinline)) sub_FF9445FC_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R11,LR}\n"
                 "LDR     R5, =0x7386C\n"
                 "SUB     SP, SP, #0x34\n"
                 "LDR     R3, [R5]\n"
                 "CMP     R3, #3\n"
                 "MOV     R4, R0\n"
                 "MOVEQ   R3, #4\n"
                 "STREQ   R3, [R5]\n"
                 "LDR     R3, =0x73914\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3]\n"
                 "LDR     R2, [R5]\n"
                 "CMP     R2, #4\n"
                 "BNE     loc_FF9447A8\n"
                 "ADD     R0, SP, #0x30\n"
                 "ADD     R1, SP, #0x2C\n"
                 "ADD     R2, SP, #0x28\n"
                 "ADD     R3, SP, #0x24\n"
                 "BL      sub_FF945DBC\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF944678\n"
                 "LDR     R3, =0x73858\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #1\n"
                 "BNE     loc_FF94468C\n"
                 "LDR     R2, =0x738A8\n"
                 "LDR     R1, =0x73880\n"
                 "LDR     R12, [R2]\n"
                 "LDR     R3, [R1]\n"
                 "CMP     R12, R3\n"
                 "BCC     loc_FF94468C\n"
"loc_FF944678:                            \n"
                 "BL      sub_FF9447EC\n"
                 "BL      sub_FF944A20\n"
                 "MOV     R3, #5\n"
                 "STR     R3, [R5]\n"
                 "B       loc_FF9447A8\n"
"loc_FF94468C:                            \n"                                        
                 "LDR     R12, =0x738B0\n"
                 "LDR     R11, =0x738BC\n"
                 "LDMIB   R4, {R0-R2}\n"
                 "LDR     R10, [R12]\n"
                 "LDR     R7, [R11]\n"
                 "LDR     R4, [SP,#0x2C]\n"
                 "LDR     R5, [SP,#0x28]\n"
                 "LDR     R6, [SP,#0x24]\n"
                 "LDR     R8, =0x7385C\n"
                 "LDR     R3, [SP,#0x30]\n"
                 "ADD     R12, SP, #0x20\n"
                 "ADD     LR, SP, #0x1C\n"
                 "MOV     R9, #1\n"
                 "STMEA   SP, {R4-R6,R12}\n"
                 "STR     R10, [SP,#0x10]\n"
                 "STR     R7, [SP,#0x14]\n"
                 "STR     LR, [SP,#0x18]\n"
                 "STR     R9, [R8]\n"
                 "BL      sub_FF8978D8\n"
                 "LDR     R3, =0x73774\n"
                 "MOV     R1, #0x3E8\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF821A90\n"	 //takesemaphore
                 "CMP     R0, #9\n"
                 "BNE     loc_FF944700\n"
                 "BL      sub_FF94657C\n"
                 "LDR     R3, =0x7386C\n"
                 "LDR     R0, =0xff9445E4\n" //aJpegtimeout_2\n"
                 "B       loc_FF944718\n"
"loc_FF944700:                            \n"
                 "LDR     R5, [SP,#0x1C]\n"
                 "CMP     R5, #0\n"
                 "BEQ     loc_FF944724\n"
                 "BL      sub_FF94657C\n"
                 "LDR     R3, =0x7386C\n"
                 "LDR     R0, =0xff9445F0\n"//aJpegicerror_3\n"
"loc_FF944718:                            \n"
                 "STR     R9, [R3]\n"
                 "BL      sub_FF958454\n"//eventproc_export_HardwareDefect\n"
                 "B       loc_FF9447A8\n"
"loc_FF944724:                            \n"
                 "BL      sub_FF897A4C\n"
                 "LDR     R0, [SP,#0x30]\n"
                 "LDR     R1, [SP,#0x20]\n"
                 "BL      sub_FF9462A0\n"
                 "LDR     R4, =0x738A8\n"
                 "LDR     R3, [R4]\n"
                 "ADD     R3, R3, #1\n"
                 "LDR     R0, [SP,#0x20]\n"
                 "MOV     R1, R11\n"
                 "STR     R3, [R4]\n"
                 "MOV     R2, R5\n"
                 "BL      sub_FF945184_my\n"
                 "LDR     R3, =0x73894\n"
                 "LDR     R4, [R4]\n"
                 "LDR     R1, [R3]\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFAC9710\n" //__umodsi3\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF944784\n"
                 "LDR     R6, =0x73860\n"
                 "LDR     R3, [R6]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FF94479C\n"
                 "B       loc_FF944788\n"
"loc_FF944784:                            \n"
                 "LDR     R6, =0x73860\n"
"loc_FF944788:                            \n"
                 "MOV     R0, R4\n"
                 "LDR     R3, =0x738F0\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3]\n"
                 "STR     R5, [R6]\n"
"loc_FF94479C:                            \n"
                 "LDR     R2, =0x7385C\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
"loc_FF9447A8:                            \n"                                         
                 "ADD     SP, SP, #0x34\n"
                 "LDMFD   SP!, {R4-R11,PC}\n"
 );
}


void __attribute__((naked,noinline)) sub_FF945184_my(){
//void __attribute__((naked,noinline)) sub_FF944DFC_my(){
 asm volatile(                 
				 "CMP     R2, #1\n"
                 "STMFD   SP!, {R4-R7,LR}\n"
                 "MOV     R7, R0\n"
                 "MOV     R6, R1\n"

//                 "MOVEQ   R3, #0x79\n"
//                 "STREQ   R3, [R6]\n"
                "LDREQ   R3, =CompressionRateTable\n" // +
                "LDREQ   R2, [R3,#0x18]\n"            // +
                "STREQ   R2, [R6]\n"				  // +

				"LDMEQFD SP!, {R4-R7,PC}\n"
                 "LDR     R12, =0x73920\n"
                 "LDR     R0, [R12]\n"
                 "LDR     R3, =0x73928\n"
                 "CMP     R0, #0\n"
                 "LDR     R1, [R3]\n"
                 "BEQ     loc_FF9451CC\n"
                 "LDR     R2, =0x7392C\n"
                 "LDR     R3, [R2]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FF9451E0\n"
                 "B       loc_FF9451D0\n"
 "loc_FF9451CC:                            \n"
                 "LDR     R2, =0x7392C\n"
"loc_FF9451D0:                            \n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
                 "STR     R7, [R12]\n"
                 "B       loc_FF945294\n"
"loc_FF9451E0:                            \n"
                 "LDR     R3, =0x73924\n"
                 "LDR     R2, [R3]\n"
                 "LDR     R5, =table1\n" //unk_FF944FEC\n"
                 "MOV     LR, R2,LSL#2\n"
                 "LDR     R3, [R5,LR]\n"
                 "LDR     R4, =table2\n" //unk_FF945028\n"
                 "RSB     R12, R3, R0\n"
                 "LDR     R2, [R4,LR]\n"
                 "CMP     R12, #0\n"
                 "RSB     R0, R2, R0\n"
                 "BLE     loc_FF945240\n"
                 "ADD     R3, R5, #0x14\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #1\n"
                 "BGE     loc_FF945234\n"
                 "ADD     R3, R5, #0x28\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #2\n"
                 "ADDLT   R1, R1, #3\n"
"loc_FF945234:                            \n"
			//     "CMP     R1, #0xE\n"    // -
           //     "MOVGE   R1, #0xE\n"    // -
				"CMP     R1, #0x1A\n"    // +
                "MOVGE   R1, #0x1A\n"    // +

				"B       loc_FF945270\n"
"loc_FF945240:                            \n"
                 "CMP     R0, #0\n"
                 "BGE     loc_FF945278\n"
                 "ADD     R3, R4, #0x14\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #1\n"
                 "BLE     loc_FF945270\n"
                 "ADD     R3, R4, #0x28\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #2\n"
                 "SUBGT   R1, R1, #3\n"
"loc_FF945270:                            \n"
                 "CMP     R1, #0\n"
                 "MOVLT   R1, #0\n"
"loc_FF945278:                            \n"                                     
                 "LDR     R0, =0x73928\n"
                 "LDR     R3, [R0]\n"
                 "CMP     R1, R3\n"
                 "LDRNE   R2, =0x7392C\n"
                 "MOVNE   R3, #1\n"
                 "STRNE   R1, [R0]\n"
                 "STRNE   R3, [R2]\n"
"loc_FF945294:                            \n"
                 "LDR     R3, =0x73928\n"
           //     "LDR     R1, =0x6CF8\n"  // -
		        "LDR     R1, =video_mode\n"  // +
                 "LDR     R0, [R3]\n"
                 "LDR     R2, =CompressionRateTable\n" //unk_FF944FB0\n"
                 "LDR     R12, [R1]\n"
                 "LDR     LR, [R2,R0,LSL#2]\n"
                 "LDR     R3, =0x73920\n"
                 "CMP     R12, #1\n"
                 "STR     R7, [R3]\n"
                 "STR     LR, [R6]\n"
            //    "MOVEQ   R3, #0xB\n"   // -

                "LDREQ   R3, =video_quality\n"          // +
                "LDREQ   R3, [R3]\n"                    // +
                "LDREQ   R3, [R3]\n"                    // +	
                 "STREQ   R3, [R6]\n"
                 "BL      video_frame_counter\n" 
                 "LDMFD   SP!, {R4-R7,PC}\n"
	 );
}

