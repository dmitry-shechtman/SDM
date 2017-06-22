#include "stubs_asm.h"
#define NULL_SUB 0xffc00948

// Override stubs_entry.S

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xFFDEEA08)
NHSTUB(TurnOffMic,                  0xFFC35D28)
NHSTUB(TurnOnMic,                   0xFFC35CFC)
NHSTUB(RefreshUSBMode,              0xffc2b574)

NHSTUB(PTM_SetCurrentItem,          0xffd34878)

