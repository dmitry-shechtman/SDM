topdir=../

include $(topdir)makefile_tools.inc

SUBDIRS=gen_meta

EXES=

ifeq ($(OPT_CAPSTONE_TOOLS),1)
EXES+=finsig_thumb2$(EXE)
endif

all: $(EXES)

# not needed by batch builds, not built by default
EXTRA_EXES=
ifeq ($(OPT_CAPSTONE_TOOLS),1)
EXTRA_EXES+=capdis$(EXE)
endif

extras: $(EXTRA_EXES)

clean:
	rm -f *.o $(EXES) $(EXTRA_EXES)

distclean: clean
include $(topdir)bottom.inc
