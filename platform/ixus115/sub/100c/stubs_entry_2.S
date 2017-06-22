#include "stubs_asm.h"
#define NULL_SUB          0xFF907390 
NHSTUB(RefreshUSBMode, NULL_SUB) // Above ADR     R0, aForceQuitPtpMo ; "Force Quit PTP Mode\r\n"
NHSTUB(opendir,          		NULL_SUB)
NHSTUB(rename,          		NULL_SUB)
NHSTUB(Remove,				NULL_SUB)
NHSTUB(LockAndRefresh,		0xFF8B18F4)
NHSTUB(UnlockAndRefresh, 	0xFF8B1958)

//All pointed to nullsub_20 (NULL)
NHSTUB(Unmount_FileSystem 						,0xFF907390) //fake
NHSTUB(Mount_FileSystem 						,0xFF907390) //fake
NHSTUB(SetZoomActuatorSpeedPercent 				,0xFF907390) //fake
NHSTUB(rewinddir 								,0xFF907390) //fake
NHSTUB(kbd_pwr_on 								,0xFF907390) //fake

IGNORE(MakeAFScan)  // Custom version in lib.c, ignore firmware version
NHSTUB(PTM_SetCurrentItem,          0xff9adaf0)

