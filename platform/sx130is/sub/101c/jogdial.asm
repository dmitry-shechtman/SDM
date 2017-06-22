                "EXPORT _sub_FF85FD80__RotaryEncoder.c__13\n"
"_sub_FF85FD80__RotaryEncoder.c__13\n"
"var_40          = -0x40\n"
"var_3C          = -0x3C\n"
"var_38          = -0x38\n"
"var_34          = -0x34\n"
"var_30          = -0x30\n"
"var_2C          = -0x2C\n"
"var_28          = -0x28\n"
                "STMFD   SP!, {R4-R11,LR}\n"
                "SUB     SP, SP, #0x1C\n"
                "BL      _sub_FF860118__RotaryEncoder.c__496\n"
                "LDR     R1, =0x2480\n"
                "LDR     R6, =unk_FFB4F590\n"
                "MOV     R0, #0\n"
                "ADD     R3, SP, #0x40+var_30\n"
                "ADD     R12, SP, #0x40+var_2C\n"
                "ADD     R10, SP, #0x40+var_38\n"
                "MOV     R2, #0\n"
                "ADD     R9, SP, #0x40+var_34\n"
"loc_FF85FDAC:\n"
                "ADD     R12, SP, #0x40+var_2C\n"
                "ADD     LR, R12, R0,LSL#1\n"
                "MOV     R2, #0\n"
                "ADD     R3, SP, #0x40+var_30\n"
                "STRH    R2, [LR]\n"
                "ADD     LR, R3, R0,LSL#1\n"
                "STRH    R2, [LR]\n"
                "STR     R2, [R9,R0,LSL#2]\n"
                "STR     R2, [R10,R0,LSL#2]\n"
                "ADD     R0, R0, #1\n"
                "CMP     R0, #1\n"
                "BLT     loc_FF85FDAC\n"
"loc_FF85FDDC:\n"
                "LDR     R0, =0x2480\n"
                "MOV     R2, #0\n"
                "LDR     R0, [R0,#8]\n"
                "MOV     R1, SP\n"
                "BL      _sub_FF839B8C__KerQueue.c__0\n"
                "CMP     R0, #0\n"
                "LDRNE   R1, =0x262\n"
                "ADRNE   R0, aRotaryencoder_\n"
                "BLNE    DebugAssert\n"
                "LDR     R0, [SP,#0x40+var_40]\n"
                "AND     R4, R0, #0xFF\n"
                "AND     R0, R0, #0xFF00\n"
                "CMP     R0, #0x100\n"
                "BEQ     loc_FF85FE4C\n"
                "CMP     R0, #0x200\n"
                "BEQ     loc_FF85FE84\n"
                "CMP     R0, #0x300\n"
                "BEQ     loc_FF86007C\n"
                "CMP     R0, #0x400\n"
                "BNE     loc_FF85FDDC\n"
                "CMP     R4, #0\n"
                "LDRNE   R1, =0x2ED\n"
                "ADRNE   R0, aRotaryencoder_\n"
                "BLNE    DebugAssert\n"
                "RSB     R0, R4, R4,LSL#3\n"
                "LDR     R0, [R6,R0,LSL#2]\n"
"loc_FF85FE44:\n"
                "BL      sub_FF8600FC\n"
                "B       loc_FF85FDDC\n"
"loc_FF85FE4C:\n"
                "LDR     R7, =0x248C\n"
                "LDR     R0, [R7,R4,LSL#2]\n"
                "BL      sub_FF83AB24\n"
                "ADR     R2, unk_FF85FCCC\n"
                "MOV     R1, R2\n"
                "ORR     R3, R4, #0x200\n"
                "MOV     R0, #0x28\n"
                "BL      sub_FF83AA40\n"
                "TST     R0, #1\n"
                "CMPNE   R0, #0x15\n"
                "STR     R0, [R10,R4,LSL#2]\n"
                "BEQ     loc_FF85FDDC\n"
                "MOV     R1, #0x274\n"
                "B       loc_FF860028\n"
"loc_FF85FE84:\n"
                "RSB     R5, R4, R4,LSL#3\n"
                "LDR     R0, [R6,R5,LSL#2]\n"
                "LDR     R1, =0xC0240104\n"
                "LDR     R0, [R1,R0,LSL#8]\n"
                "MOV     R2, R0,ASR#16\n"
                "ADD     R0, SP, #0x40+var_2C\n"
                "ADD     R0, R0, R4,LSL#1\n"
                "STR     R0, [SP,#0x40+var_28]\n"
                "STRH    R2, [R0]\n"
                "ADD     R0, SP, #0x40+var_30\n"
                "ADD     R11, R0, R4,LSL#1\n"
                "LDRSH   R3, [R11]\n"
                "SUB     R0, R2, R3\n"
                "CMP     R0, #0\n"
                "BNE     loc_FF85FF04\n"
                "LDR     R0, [R9,R4,LSL#2]\n"
                "CMP     R0, #0\n"
                "BEQ     loc_FF85FFE4\n"
                "LDR     R7, =0x248C\n"
                "LDR     R0, [R7,R4,LSL#2]\n"
                "BL      sub_FF83AB24\n"
                "ADR     R2, _sub_FF85FCD8__RotaryEncoder.c__0\n"
                "MOV     R1, R2\n"
                "ORR     R3, R4, #0x300\n"
                "MOV     R0, #0x1F4\n"
                "BL      sub_FF83AA40\n"
                "TST     R0, #1\n"
                "CMPNE   R0, #0x15\n"
                "STR     R0, [R7,R4,LSL#2]\n"
                "BEQ     loc_FF85FFE4\n"
                "LDR     R1, =0x28D\n"
                "B       loc_FF85FFDC\n"
"loc_FF85FF04:\n"
                "MOV     R1, R0\n"
                "RSBLT   R0, R0, #0\n"
                "MOVLE   R7, #0\n"
                "MOVGT   R7, #1\n"
                "CMP     R0, #0xFF\n"
                "BLS     loc_FF85FF44\n"
                "CMP     R1, #0\n"
                "RSBLE   R0, R3, #0xFF\n"
                "ADDLE   R0, R0, #0x7F00\n"
                "ADDLE   R0, R0, R2\n"
                "RSBGT   R0, R2, #0xFF\n"
                "ADDGT   R0, R0, #0x7F00\n"
                "ADDGT   R0, R0, R3\n"
                "ADD     R0, R0, #0x8000\n"
                "ADD     R0, R0, #1\n"
                "EOR     R7, R7, #1\n"
"loc_FF85FF44:\n"
                "STR     R0, [SP,#0x40+var_3C]\n"
                "LDR     R0, [R9,R4,LSL#2]\n"
                "CMP     R0, #0\n"
                "ADDEQ   R0, R6, R5,LSL#2\n"
                "LDREQ   R0, [R0,#8]\n"
                "BEQ     loc_FF85FF7C\n"
                "ADD     R8, R6, R5,LSL#2\n"
                "ADD     R1, R8, R7,LSL#2\n"
                "LDR     R1, [R1,#0x10]\n"
                "CMP     R1, R0\n"
                "BEQ     loc_FF85FF80\n"
                "LDR     R0, [R8,#0xC]\n"
                "BL      sub_FF893C28\n"
                "LDR     R0, [R8,#8]\n"
"loc_FF85FF7C:\n"
                "BL      sub_FF893C28\n"
"loc_FF85FF80:\n"
                "ADD     R0, R6, R5,LSL#2\n"
                "ADD     R7, R0, R7,LSL#2\n"
                "LDR     R0, [R7,#0x10]\n"
                "LDR     R1, [SP,#0x40+var_3C]\n"
                "BL      sub_FF893B50\n"
                "LDR     R0, [R7,#0x10]\n"
                "LDR     R7, =0x248C\n"
                "STR     R0, [R9,R4,LSL#2]\n"
                "LDR     R0, [SP,#0x40+var_28]\n"
                "LDRH    R0, [R0]\n"
                "STRH    R0, [R11]\n"
                "LDR     R0, [R7,R4,LSL#2]\n"
                "BL      sub_FF83AB24\n"
                "ADR     R2, _sub_FF85FCD8__RotaryEncoder.c__0\n"
                "MOV     R1, R2\n"
                "ORR     R3, R4, #0x300\n"
                "MOV     R0, #0x1F4\n"
                "BL      sub_FF83AA40\n"
                "TST     R0, #1\n"
                "CMPNE   R0, #0x15\n"
                "STR     R0, [R7,R4,LSL#2]\n"
                "BEQ     loc_FF85FFE4\n"
                "LDR     R1, =0x2CF\n"
"loc_FF85FFDC:\n"
                "ADR     R0, aRotaryencoder_\n"
                "BL      DebugAssert\n"
"loc_FF85FFE4:\n"
                "ADD     R0, R6, R5,LSL#2\n"
                "LDR     R0, [R0,#0x18]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FF860074\n"
                "LDR     R0, =0x2480\n"
                "LDR     R0, [R0,#0x10]\n"
                "CMP     R0, #0\n"
"loc_FF860000:\n"
                "BEQ     loc_FF860074\n"
                "ADR     R2, unk_FF85FCCC\n"
                "MOV     R1, R2\n"
                "ORR     R3, R4, #0x400\n"
                "BL      sub_FF83AA40\n"
                "TST     R0, #1\n"
                "CMPNE   R0, #0x15\n"
                "STR     R0, [R10,R4,LSL#2]\n"
                "BEQ     loc_FF85FDDC\n"
                "LDR     R1, =0x2D6\n"
"loc_FF860028:\n"
                "ADR     R0, aRotaryencoder_\n"
                "BL      DebugAssert\n"
                "B       loc_FF85FDDC\n"
"dword_FF860034  DCD 0x2480\n"
"dword_FF860038  DCD 0x313\n"
"aRotaryencoder_ DCB "RotaryEncoder.c",0\n"
"dword_FF86004C  DCD 0x248C\n"
"dword_FF860050  DCD 0xC0240108\n"
"off_FF860054    DCD unk_FFB4F590\n"
"dword_FF860058  DCD 0x20E\n"
"dword_FF86005C  DCD 0x262\n"
"dword_FF860060  DCD 0x2ED\n"
"dword_FF860064  DCD 0xC0240104\n"
"dword_FF860068  DCD 0x28D\n"
"dword_FF86006C  DCD 0x2CF\n"
"dword_FF860070  DCD 0x2D6\n"
"loc_FF860074:\n"
                "LDR     R0, [R6,R5,LSL#2]\n"
                "B       loc_FF85FE44\n"
"loc_FF86007C:\n"
                "LDR     R0, [R9,R4,LSL#2]\n"
                "CMP     R0, #0\n"
                "MOVEQ   R1, #0x2E0\n"
                "ADREQ   R0, aRotaryencoder_\n"
                "BLEQ    DebugAssert\n"
                "RSB     R0, R4, R4,LSL#3\n"
                "ADD     R0, R6, R0,LSL#2\n"
                "LDR     R0, [R0,#0xC]\n"
                "BL      sub_FF893C28\n"
                "MOV     R2, #0\n"
                "STR     R2, [R9,R4,LSL#2]\n"
                "B       loc_FF85FDDC\n"