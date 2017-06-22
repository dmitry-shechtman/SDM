#include "stubs_asm.h"
#define NULL_SUB 0xFF81093C

// Override stubs_entry.S
NHSTUB(ExitFromCompensationEVF,     0xFF825BAC)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist/aren't found in dryos
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(platformsub_kbd_fetch_data,  0xFF84D880)
NHSTUB(RefreshUSBMode, 0xFF83E7E0) // above "Force Quit PTP Mode\r\n"

NHSTUB(PTM_SetCurrentItem,          0xff98c904)

