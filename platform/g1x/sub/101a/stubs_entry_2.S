#include "stubs_asm.h"
#define NULL_SUB 0xFF0574AC
     // Unconfirmed 
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(opendir,          		NULL_SUB)
NHSTUB(rename,          		NULL_SUB)
NHSTUB(Remove,				NULL_SUB)
# Missing
NHSTUB(SetZoomActuatorSpeedPercent,		NULL_SUB)
NHSTUB(PTM_SetCurrentItem,          0xff205aec)

