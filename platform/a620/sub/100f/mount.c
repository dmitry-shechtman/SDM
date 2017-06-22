void __attribute__((naked,noinline)) init_file_modules_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"                          //FFD72B20
                "BL      _Unmount_FileSystem\n" // + 
                "BL      sub_FFEA0F64\n"
                "SUBS    R4, R0, #0\n"
                "MOV     R0, #0x5000\n"
                "MOV     R1, #0\n"
                "ADD     R0, R0, #6\n"
                "BEQ     loc_FFD72B40\n"
                "BL      sub_FFD45E4C\n"   //PostLogicalEventToUI
"loc_FFD72B40:\n"
                "BL      sub_FFEA0F8C_my\n"  //---------------->
                "MOV     R0, #0x5000\n"
                "CMP     R4, #0\n"
                "MOV     R1, R4\n"
                "ADD     R0, R0, #6\n"
                "LDMNEFD SP!, {R4,PC}\n"
                "LDMFD   SP!, {R4,LR}\n"
                "B       sub_FFD45E4C\n"   //PostLogicalEventToUI
 );
}

void __attribute__((naked,noinline)) sub_FFEA0F8C_my(){
 asm volatile(
                "STR     LR, [SP,#-4]!\n"
                "BL      Mount_FileSystem_my\n"   //-------------->
                "LDR     R3, =0xBD98\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "BNE     loc_FFEA0FC8\n"
                "BL      sub_FFD9502C\n"
                "AND     R0, R0, #0xFF\n"
                "BL      sub_FFC246B8\n"
                "BL      sub_FFD9502C\n"
                "AND     R0, R0, #0xFF\n"
                "BL      sub_FFC50DF8\n"
                "BL      sub_FFD9503C\n"
                "AND     R0, R0, #0xFF\n"
                "BL      sub_FFC24788\n"
"loc_FFEA0FC8:\n"
                "LDR     R2, =0xBD94\n"
                "MOV     R3, #1\n"
                "STR     R3, [R2]\n"
                "LDR     PC, [SP],#4\n"
 );
}

void __attribute__((naked,noinline)) Mount_FileSystem_my(){         //code from FFC5C140
 asm volatile(
                "STMFD   SP!, {R4-R6,LR}\n"
                "MOV     R5, #0\n"
                "LDR     R6, =0x2E2C8\n"
                "MOV     R0, R5\n"
                "BL      sub_FFC5BB78\n"
                "LDR     R0, [R6,#0x38]\n"
                "BL      sub_FFC5B268\n"
                "SUBS    R1, R0,#0\n"                               
                "MOV     R0, R5\n"
                "BNE     loc_FFC5C180\n"
                "LDR     R3, =0x2854\n"
                "LDR     R2, =0x284C\n"
                "STR     R1, [R3]\n"
                "LDR     R3, =0x2850\n"
                "STR     R1, [R2]\n"
                "STR     R1, [R3]\n"
"loc_FFC5C180:\n"
                "BL      sub_FFC5BBC8\n"
                "MOV     R0, R5\n"
                "BL      sub_FFC5BEF0_my\n"  //----------------->
                "MOV     R4, R0\n"
                "MOV     R0, R5\n"
                "BL      sub_FFC5BF78\n"
                "AND     R4, R4, R0\n"
                "MOV     R2, R4\n"
                "MOV     R0, R6\n"
                "LDR     R1, [R6,#0x3C]\n"
                "BL      sub_FFC5C0F0\n"
                "STR     R0, [R6,#0x40]\n"
                "LDMFD   SP!, {R4-R6,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FFC5BEF0_my(){
 asm volatile(
                "STMFD   SP!, {R4-R7,LR}\n"
                "LDR     R7, =0x2850\n"
                "LDR     R3, [R7]\n"
                "MOV     R4, R0\n"
                "CMP     R3, #0\n"
                "ADD     R3, R4, R4,LSL#1\n"
                "RSB     R3, R4, R3,LSL#3\n"
                "LDR     R6, =0x2E300\n"
                "MOV     R5, R3,LSL#2\n"
                "MOV     R1, R4\n"
                "BNE     loc_FFC5BF64\n"
                "LDR     R0, [R6,R5]\n"
                "BL      sub_FFC5BC80_my\n" //---------------->
                "SUBS    R3, R0, #0\n"
                "MOV     R1, R4\n"
                "BEQ     loc_FFC5BF3C\n"
                "LDR     R0, [R6,R5]\n"
                "BL      sub_FFC5BDD0\n"
                "MOV     R3, R0\n"
"loc_FFC5BF3C:\n"
                "CMP     R3, #0\n"
                "MOV     R0, R4\n"
                "BEQ     loc_FFC5BF50\n"
                "BL      sub_FFC5B340\n"
                "MOV     R3, R0\n"
"loc_FFC5BF50:\n"
                "CMP     R3, #0\n"
                "MOV     R0, R3\n"
                "MOVNE   R3, #1\n"
                "STRNE   R3, [R7]\n"
                "LDMFD   SP!, {R4-R7,PC}\n"
"loc_FFC5BF64:\n"
                "MOV     R0, #1\n"
                "LDMFD   SP!, {R4-R7,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FFC5BC80_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n"
                "MOV     R5, R1\n"
                "MOV     R8, R5,LSL#1\n"
                "ADD     R3, R8, R5\n"
                "LDR     R2, =0x2E304\n"
                "SUB     SP, SP, #8\n"
                "RSB     R3, R5, R3,LSL#3\n"
                "LDR     R1, [R2,R3,LSL#2]\n"
                "MOV     R6, #0\n"
                "STR     R6, [SP]\n"
                "MOV     R7, R0\n"
                "STR     R6, [SP,#4]\n"
                "CMP     R1, #5\n"
                "LDRLS   PC, [PC,R1,LSL#2]\n"
                "B       loc_FFC5BD7C\n"
                ".long loc_FFC5BD20\n"
                ".long loc_FFC5BCD4\n"
                ".long loc_FFC5BCD4\n"
                ".long loc_FFC5BCD4\n"
                ".long loc_FFC5BCD4\n"
                ".long loc_FFC5BD6C\n"
"loc_FFC5BCD4:\n"
                "MOV     R0, #3\n"
                "MOV     R1, #0x200\n"
                "MOV     R2, #0\n"
                "BL      sub_FFC02830\n" //AllocateExMem
                "SUBS    R6, R0, #0\n"
                "BEQ     loc_FFC5BDB4\n"
                "ADD     R12, R8, R5\n"
                "RSB     R12, R5, R12,LSL#3\n"
                "LDR     R4, =0x2E314\n"
                "MOV     R0, R7\n"
                "MOV     R1, #0\n"
                "MOV     R2, #1\n"
                "MOV     R3, R6\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R4,R12,LSL#2]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FFC5BD28\n"
                "MOV     R0, #3\n"
                "BL      sub_FFC0287C\n"  // FreeExMem
"loc_FFC5BD20:\n"
                "MOV     R0, #0\n"
                "B       loc_FFC5BDB4\n"
"loc_FFC5BD28:\n"
                "MOV     R0, R7\n"
                "BL      sub_FFC6BAB4\n"
                "MOV     R1, R0\n"
                "ADD     R2, SP, #4\n"
                "MOV     R3, SP\n"
                "MOV     R0, R6\n"

                "STMFD   SP!, {R4-R11,LR}\n" // +
                "BL      mbr_read\n"    //-----------> 
                "LDMFD   SP!, {R4-R11,LR}\n" // +

         //     "BL      sub_FFC5B444\n"      // original function
                "MOV     R4, R0\n"
                "MOV     R0, #3\n"
                "BL      sub_FFC0287C\n"  // FreeExMem
                "CMP     R4, #0\n"
                "BNE     loc_FFC5BD8C\n"
                "MOV     R0, R7\n"
                "STR     R4, [SP,#4]\n"
                "BL      sub_FFC6BAB4\n"
                "STR     R0, [SP]\n"
                "B       loc_FFC5BD8C\n"
"loc_FFC5BD6C:\n"
                "MOV     R3, #0\n"
                "MOV     R2, #0x40\n"
                "STMEA   SP, {R2,R3}\n"
                "B       loc_FFC5BD8C\n"
"loc_FFC5BD7C:\n"
                "MOV     R1, #0x284\n"
                "LDR     R0, =0xFFC5BA50\n"
                "ADD     R1, R1, #2\n"
                "BL      sub_FFC03AD0\n"   // DebugAssert
"loc_FFC5BD8C:\n"
                "LDR     R2, =0x2E2C8\n"
                "ADD     R3, R8, R5\n"
                "LDMFD   SP, {R0,R12}\n"
                "RSB     R3, R5, R3,LSL#3\n"
                "MOV     R3, R3,LSL#2\n"
                "ADD     R1, R2, #0x48\n"
                "ADD     R2, R2, #0x44\n"
                "STR     R0, [R1,R3]\n"
                "STR     R12, [R2,R3]\n"
                "MOV     R0, #1\n"
"loc_FFC5BDB4:\n"
                "ADD     SP, SP, #8\n"
                "LDMFD   SP!, {R4-R8,PC}\n"
 );
}
