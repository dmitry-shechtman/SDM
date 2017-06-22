# build time optional components for 'special builds'.
 
#OPT_PTP = 1
OPT_OMNI = 1
#OPT_ALARIK=1
# experimental - allocate memory from alternate heap. Default 2MB from EXMEM_RAMDISK
# See exmem_malloc_init in generic/wrappers.c
#OPT_EXMEM_MALLOC=1
# Set OPT_CHDK_IN_EXMEM to build and load CHDK into EXMEM memory 
# Need to define MEMISOSTART and EXMEM values in PLATFORM/PLATFORMSUB/makefile.inc (see G12 or SX30 for example)
# (if setting this must also set OPT_EXMEM_MALLOC !)
#OPT_CHDK_IN_EXMEM=1
# set this to enable exmem corruption testing (see wrappers.c). (Don't set OPT_CHDK_IN_EXMEM with this !)
#OPT_EXMEM_TESTING=1
# debug logging
#OPT_LOG = 1
# set this for PTP LiveView support
#OPT_LIVE_VIEW = 1
# extended Tv range used by SDM for very short exposures rather than long
#OPT_EXT_TV_RANGE = 1
# experimental sunset option
#OPT_SUNSET = 1 
# counts to interrupt
#OPT_SYNC_TEST = 1


