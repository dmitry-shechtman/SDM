#include "stubs_asm.h"
#define NULL_SUB 0xffc00b28

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                      NULL_SUB)   // endereço dummy com uma instrução bx lr (um ret, creio)
NHSTUB(mkdir,                           0xffc267fc) // 53% corrigido
NHSTUB(rand,                            NULL_SUB)   // Não encontrei manualmente
NHSTUB(srand,                           NULL_SUB)   // idem acima

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                      0xffd1b2e0) // verifiquei a rotina e as referências a ela e são bastante similares FFD0F2AC) // Ok
NHSTUB(TurnOffMic,                      0xffc444ec) // rotina em posição similar a de a495 -logo provavelmente doesn't work também -  FFC43C28) // Doesn't work
NHSTUB(TurnOnMic,                       0xffc44518) // idem acima FFC43C54) // Doesn't work
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"

NHSTUB(PTM_SetCurrentItem,          0xffd3a520)

