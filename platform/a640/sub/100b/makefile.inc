#0x3139
PLATFORMID=12601
PLATFORMOS=vxworks
CAM_MULTIPART=1
MEMBASEADDR=0x1900
RESTARTSTART=0x50000
MEMISOSTART=0x94D10

ROMBASEADDR=0xffc00000

TARGET_PRIMARY=$(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/PRIMARY.BIN

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)