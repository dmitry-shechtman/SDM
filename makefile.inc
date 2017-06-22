 
BUILD_NUMBER=2.2

PLATFORM=s95
PLATFORMSUB=100k

MEMISOSIZE="(&_end-&_start)"
# override this on the command line or in buildconf to use PRIMARY.BIN from a different tree
# should be an absolute path
PRIMARY_ROOT=$(topdir)platform
include $(topdir)buildconf.inc
include $(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/makefile.inc

ifdef PLATFORM
  ifdef PLATFORMSUB
    MEMBASEADDR=0x1900
    include $(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/makefile.inc
    PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
    ifdef RESTARTSTART
      PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)
    endif
    ifeq ($(PLATFORMOSVER),)
      PLATFORMOSVER=0
    endif
  endif
endif


SILENT=SILENT

NOZERO100K=TRUE

ESED = sed -r

# keep sort order consistent
export LC_ALL=C

ifndef OSTYPE
  HOSTPLATFORM:=$(patsubst MINGW%,MINGW,$(shell uname -s))
  ifeq ($(HOSTPLATFORM),MINGW)
    OSTYPE = Windows
    EXE = .exe
    SH = sh
    DEVNULL = NUL
	OLDSEPARATOR = \\\\
	NEWSEPARATOR = /
	SORT := $(dir $(shell which uniq.exe | sed 's_$(OLDSEPARATOR)_$(NEWSEPARATOR)_g'))/sort.exe
  else
    ifeq ($(HOSTPLATFORM),Linux)
      OSTYPE = Linux
      EXE =
      SH =
      DEVNULL = /dev/null
      SORT = sort
    else
      ifeq ($(HOSTPLATFORM),Darwin)
        OSTYPE = Darwin
        EXE =
        SH =
        DEVNULL = /dev/null
        SORT = sort
        ESED = sed -E
      else
        OSTYPE = Other
        EXE =
        SH =
        DEVNULL = /dev/null
        SORT = sort
      endif
    endif
  endif
else
  EXE =
  SH =
  DEVNULL = /dev/null
  SORT = sort
endif

HOSTCC=gcc
HOSTCFLAGS=-g -O2 -Wall
HOSTAR=ar

PAKWIF=$(topdir)tools/pakwif$(EXE)
PAKFI2=$(topdir)tools/packfi2/fi2enc$(EXE)
ENCODE_DISKBOOT=$(topdir)tools/dancingbits$(EXE)

##########################################################################

CC=arm-elf-gcc
OBJCOPY=arm-elf-objcopy
OBJDUMP=arm-elf-objdump
STRIP=arm-elf-strip
NM=arm-elf-nm
AR=arm-elf-ar
RANLIB=arm-elf-ranlib
SIZE=arm-elf-size

GCC_VERSION=$(shell $(CC) -dumpversion)
GCC_VERSION_MAJOR=$(firstword $(subst ., ,$(GCC_VERSION)))

# -msoft-float is used per default but object files are marked as hard-float
CFLAGS=-fno-inline -Os -fno-strict-aliasing
# flags for gcc v4
#CFLAGS+=-mcpu=arm946e-s
# for gcc v3, we use to allow use of strd etc
ifeq ($(GCC_VERSION_MAJOR),3)
    CFLAGS+=-march=armv5te
else
    ifeq ($(GCC_VERSION_MAJOR),4)
        # TODO should be -mcpu, but breaks things ATM
        CFLAGS+=-mtune=arm946e-s
    endif
endif


CTHUMB=-mthumb
CFLAGS+=-mthumb-interwork
CFLAGS+=-I$(topdir)include $(PLFLAGS) $(CPPFLAGS)
CFLAGS+=-DPLATFORM=\"$(PLATFORM)\" -DPLATFORMSUB=\"$(PLATFORMSUB)\" -DPLATFORMID=$(PLATFORMID) -DBUILD_NUMBER=\"$(BUILD_NUMBER)\" -DCAMERA_$(PLATFORM)
CFLAGS+=-Wall -Wno-unused -Wno-format
LDFLAGS=-L$(topdir)lib/math -L$(topdir)lib/font
LDFLAGS+=-L$(topdir)lib/libc -L$(topdir)lib/ubasic
LDFLAGS+=-L$(topdir)platform/$(PLATFORM) -L$(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)

ifdef OPT_DEBUGGING
CFLAGS+=-DOPT_DEBUGGING
endif
ifdef MOVIE_SYNCH
CFLAGS+=-DMOVIE_SYNCH
endif
ifdef SDM_TESTS
CFLAGS+=-DSDM_TESTS
endif
ifdef OPT_PTP
CFLAGS+=-DOPT_PTP
endif
ifdef OPT_OMNI
CFLAGS+=-DOPT_OMNI
endif
ifdef DNG_SUPPORT
CFLAGS+=-DDNG_SUPPORT
endif

ifdef OPT_EXMEM_MALLOC
CFLAGS+=-DOPT_EXMEM_MALLOC
endif

ifdef OPT_EXMEM_TESTING
CFLAGS+=-DOPT_EXMEM_TESTING
endif

ifdef EXMEM_HEAP_SKIP
CFLAGS+=-DEXMEM_HEAP_SKIP=$(EXMEM_HEAP_SKIP)
endif

ifdef EXMEM_BUFFER_SIZE
CFLAGS+=-DEXMEM_BUFFER_SIZE=$(EXMEM_BUFFER_SIZE)
endif

ifdef OPT_CHDK_IN_EXMEM
CFLAGS+=-DOPT_CHDK_IN_EXMEM
endif

ifdef OPT_LOG
CFLAGS+=-DOPT_LOG
endif

ifdef OPT_XML
CFLAGS+=-DOPT_XML
endif

ifdef OPT_LIVE_VIEW
CFLAGS+=-DOPT_LIVE_VIEW
endif

ifdef OPT_ALARIK
CFLAGS+=-DOPT_ALARIK
endif

ifdef OPT_EXT_TV_RANGE
CFLAGS+=-DOPT_EXT_TV_RANGE
endif

ifdef OPT_NEW_OVERLAY
CFLAGS+=-DOPT_NEW_OVERLAY
endif

ifdef OPT_NEW_ZEBRA
CFLAGS+=-DOPT_NEW_ZEBRA
endif

ifdef OPT_NEW_INVERT
CFLAGS+=-DOPT_NEW_INVERT
endif

ifdef OPT_NEW_STEREO_PB
CFLAGS+=-DOPT_NEW_STEREO_PB
endif

ifdef OPT_MOVIE_GENLOCK
CFLAGS+=-DOPT_MOVIE_GENLOCK
endif

ifdef OPT_SUNSET
CFLAGS+=-DOPT_SUNSET
endif

ifdef OPT_SYNC_TEST
CFLAGS+=-DOPT_SYNC_TEST
endif

ifdef OPT_WARNINGS
     ifeq ($(GCC_VERSION_MAJOR),3)
           CFLAGS+=-Wwrite-strings -Wsign-compare -Wunused -Wno-unused-parameter
           HOSTCFLAGS+=-Wwrite-strings -Wsign-compare -Wunused -Wno-unused-parameter
     endif
     ifeq ($(GCC_VERSION_MAJOR),4)
           CFLAGS+=-Wextra -fdiagnostics-show-option -Wno-missing-field-initializers -Wunused -Wno-unused-parameter
           #HOSTCFLAGS+=-Wextra -fdiagnostics-show-option -Wno-missing-field-initializers -Wunused -Wno-unused-parameter
     endif
endif

##########################################################################

default: all

ifndef SKIPBUILDRULES

%.o: %.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -o $@ $<
%.o: %.S
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -o $@ $<
%.a:
	@echo $^ \-\> $@
	$(AR) rcs $@ $^

.dep/%.d: %.c .dep
	$(CC) $(CFLAGS) -M $< > $@.$$$$; \
	    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	    rm -f $@.$$$$

.dep/%.d: %.S .dep
	$(CC) $(CFLAGS) -M $< > $@.$$$$; \
	    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	    rm -f $@.$$$$

endif

all: all-recursive
clean: clean-recursive
distclean: distclean-recursive

.dep:
	mkdir .dep

clean-recursive:
	@for i in $(SUBDIRS); do \
	    echo \>\> Cleaning in $(FOLDER)$$i; \
	    $(MAKE) -C $$i FOLDER="$(FOLDER)$$i/" clean || exit 1; \
	done

distclean-recursive:
	@for i in $(SUBDIRS); do \
	    echo \>\> Distcleaning in $(FOLDER)$$i; \
	    $(MAKE) -C $$i FOLDER="$(FOLDER)$$i/" distclean || exit 1; \
	done

all-recursive:
	@for i in $(SUBDIRS); do \
	    echo \>\> Entering folder $(FOLDER)$$i; \
	    $(MAKE) -C $$i FOLDER="$(FOLDER)$$i/" || exit 1; \
	    echo \<\< Leaving folder $(FOLDER)$$i; \
	done

depend-recursive:
	@for i in $(SUBDIRS); do \
	    echo \>\> Entering folder $(FOLDER)$$i; \
	    $(MAKE) -C $$i FOLDER="$(FOLDER)$$i/" depend || exit 1; \
	    echo \<\< Leaving $(FOLDER)$$i; \
	done

ifdef SILENT
.SILENT:
endif
