# 0x3236 Found @ 0xfff40040
PLATFORMID=12854

PLATFORMOS=dryos

# address where wif or diskboot code will be loaded by camera
MEMBASEADDR=0x1900

# size of memory region for CHDK
RESTARTSTART=0x50000

# points to the start of the memory pool used by the firmware
MEMISOSTART=0x195D34

# start of firmware
ROMBASEADDR=0xFF000000

MAXRAMADDR = 0x0fffffff

# Found @ 0xffff3b38
NEED_ENCODED_DISKBOOT=7

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)

#suppress FI2 since it doesn't work
override OPT_FI2=
# Found @ 0xffff3b28
KEYSYS=d4c

PLATFORMOSVER=49
