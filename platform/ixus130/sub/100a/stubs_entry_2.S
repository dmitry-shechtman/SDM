#include "stubs_asm.h"

#define NULL_SUB 0xFF811800

NHSTUB(MakeAFScan,                  0xFF95D2C8) // "SsPrepareSeqBase.c"
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)   //
NHSTUB(kbd_pwr_on,                  NULL_SUB)   //
NHSTUB(kbd_pwr_off,                 NULL_SUB)   //
     // Unconfirmed 
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(opendir,          		NULL_SUB)
NHSTUB(rename,          		NULL_SUB)
NHSTUB(Remove,				NULL_SUB)

NHSTUB(PTM_SetCurrentItem,          0xff985710)

