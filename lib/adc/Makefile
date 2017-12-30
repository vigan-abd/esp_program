#   Project:     Makefile
#   
#   File:        $RCSfile: Makefile,v $ 
#   Description: common Makefile (GNU make)
#   Revision     $Revision: 1.5 $
#   Date:        $Date: 2003/11/18 13:00:04 $
#   Author:      Wolfgang Haidinger
#   Adapted by:  Alexander Koessler
#
#   TU Vienna, Real Time Group
#
#   GNU Make Documentation:
#                http://www.gnu.org/software/make/manual/make.html

# settings which should affect the compilation of this dir & the
# subdirs, are collected in Makefile.set. Don't forget to adjust
# this file to fit your needings.
# "include Makefile.set" includes the file Makefile.set
include Makefile.set


# Projectname
PRJNAME    = adc

# Select node number
TARGET     = 2

# Select programming Interface
INTERFACE  = /dev/ttyUSB2

# Define Debug Port
DEBUGPORT  = 6000



# listing the objects instead of the source fils are prefered
# to highlight the following problem:
# when having a directory containing a file TuWas.c and Tuwas.S
# TuWas.c compiles to TuWas.o & TuWas.S overwrites TuWas.o
# OBJ should contain all your object files in the current directory
# while SUBOBJS should contain all the objects which are not in
# the current directory but required for linking 
OBJS       = $(PRJNAME).o
SUBOBJS    = 


#============================================================
# usually there is no need to change anything below this line
# but be carefull: the trojans placed the horse in the city
# because of their lack of knowledge ...
#============================================================


# define variables containing the names of the hex & eep file
FLASH_FILE = $(PRJNAME).hex
EEP_FILE   = $(PRJNAME).eep
ELF_FILE   = $(PRJNAME).elf

# since just the objects are provided, make has to generate the
# source file names from the objects
EXISTC     = $(wildcard *.c) # a list of all .c files of current dir
EXISTS     = $(wildcard *.S) # a list of all .S files of current dir
POTC       = $(OBJS:.o=.c) # all potentially .c source files
POTS       = $(OBJS:.o=.S) # all potentially .S source files
CFILES     = $(filter $(EXISTC), $(POTC)) # intersection (existing .c files)
SFILES     = $(filter $(EXISTS), $(POTS)) # intersection (existing .S files)


# if there exist a .c and a .S file compiling to the same .o file stop!
BOTH       = $(filter $(CFILES:.c=), $(SFILES:.S=)) # xxx.c & xxx.S ?
ifneq "$(strip $(BOTH))" ""
  $(error Both $(addsuffix .c, $(BOTH)) and $(addsuffix .S,$(BOTH)) exist.)
endif


SUBDIRS    = $(dir $(SUBOBJS)) # just the dirs "Sub1/ Sub2/ ..."


# .d files are used to handle the #include dependencies
# (so a altered header file will cause a recompilation)
# DFILES contains a list of all (existing & required) *.d files
DEXIST     = $(wildcard *.d) # list of all existing .d files
DREQUIRED  = $(CFILES:.c=.d) $(SFILES:.S=.d) # list of all required .d files
DFILES     = $(filter $(DEXIST),$(DREQUIRED)) # intersection


# list of all non-file targets
.PHONY: all makesub lc lmc clean mostlyclean distclean install debug


# 1st the main target
all: $(DREQUIRED) makesub $(PRJNAME).hex $(PRJNAME).eep


# include just existing D-files
ifneq "$(strip $(DFILES))" ""
  include $(DFILES)
endif


# declare implicit rules
%.hex:	%.elf
	$(OBJCOPY) -O $(FORMAT) $< $@

%.eep:	%.elf
	$(OBJCOPY) $(EEPFLAGS) -O $(FORMAT) $< $@

%.elf:	$(OBJS) $(SUBOBJS)
	$(CC) -Wl,-Map=$*.m $(LDFLAGS) -o $@ $(OBJS) $(SUBOBJS) $(LIBOPT)
# the x bit is set by the compiler but since this is a cross compiler
# this programm should not be executeable on this machine
	@$(CHMOD) ugo-x $@

%.d:	%.c
# the compiler generates output of the following format:
# "Test.o: Test.c Header1.h Header2.h ..."
# sed is used to convert this into:
# "Test.o Test.d: Test.c Header1.h Header2.h ..."
# to declare the dependencies of Test.d too
	$(CC) $(DOPT) $(CFLAGS) $<|sed 's,\($*\).o[ :]*,\1.o $@: ,g' > $@

%.d:	%.S
# the compiler generates output of the following format:
# "Test.o: Test.S Header1.h Header2.h ..."
# sed is used to convert this into:
# "Test.o Test.d: Test.S Header1.h Header2.h ..."
# to declare the dependencies of Test.d too
	$(CC) $(DOPT) $(CFLAGS) $<|sed 's,\($*\).o[ :]*,\1.o $@: ,g' > $@

%.o:	%.c
	$(CC) $(CFLAGS) -Wall -c -o $@ $<

%.o:	%.S
	$(CC) $(CFLAGS) -Wall -c -o $@ $<

%.i:	%.c
	$(CC) $(CFLAGS) -E -o $@ $<

%.s:	%.c
	$(CC) $(CFLAGS) -S -o $@ $<

# intended:
# TMPCLEAN = cd $(dir); make clean\n
# due to the trailing newline character a define is
# required instead of "="
define TMPMAKE
@cd $(dir); make

endef
define TMPCLEAN
@cd $(dir); make clean

endef
define TMPMOSTLY
@cd $(dir); make mostlyclean

endef
define TMPDIST
@cd $(dir); make distclean

endef


# declare the PHONYs
makesub: # calls make in subdirs
	$(foreach dir,$(dir $(SUBOBJS)),$(TMPMAKE))

lc: # local clean
	$(RM) $(CFILES:.c=.i) $(SFILES:.S=.i) # generated preprocs
	$(RM) $(CFILES:.c=.s) $(SFILES:.S=.s) # generated asms
	$(RM) $(CFILES:.c=.o) $(SFILES:.S=.o) # generated objects
	$(RM) $(CFILES:.c=.l) $(SFILES:.S=.l) # generated lists
	$(RM) $(ELF_FILE) $(PRJNAME).m        # generated elf & map file
	$(RM) $(EEP_FILE) $(FLASH_FILE)       # generated eep & hex file

lmc: lc # local mostly clean
	$(RM) $(CFILES:.c=.d) $(SFILES:.S=.d) # generated dependecies

clean: lc
	$(foreach dir,$(dir $(SUBOBJS)),$(TMPCLEAN))

mostlyclean: lmc
	$(foreach dir,$(dir $(SUBOBJS)),$(TMPMOSTLY))

distclean: lmc
	$(RM) $(ELF_FILE) $(FLASH_FILE) $(EEP_FILE)       # generated elf,hex & eep
	$(RM) *~ *.bak *.BAK                  # all (sic!) backups
	$(foreach dir,$(dir $(SUBOBJS)),$(TMPDIST))

install: all #installs program to selected target
#install the evaluator
	$(MUXR) --port=0
	$(MUXR) --global-disable=0
	$(PROGR) --erase --program --file evaluator.elf --jtag $(INTERFACE) 
	$(MUXR) --reset16
	$(MUXR) --target-disable=1
	$(MUXR) --target-disable=0
#switch programming target
	$(MUXR) --port=$(TARGET)
#install muster-program on selected target
	$(PROGR) --erase --program --file $(ELF_FILE) --jtag $(INTERFACE) 
#resetting programmer and node
	$(MUXR) --reset16
	$(MUXR) --target-disable=1
	$(MUXR) --target-disable=0
#disable programmer
	$(MUXR) --global-disable=1

debug: install
#enable programmer
	$(MUXR) --verbose --global-disable=0
#open debug port
	$(PROGR) --jtag $(INTERFACE) :$(DEBUGPORT)

muster:
#install the evaluator
	$(MUXR) --port=0
	$(MUXR) --global-disable=0
	$(PROGR) --erase --program --file evaluator.elf --jtag $(INTERFACE) 
	$(MUXR) --reset16
	$(MUXR) --target-disable=1
	$(MUXR) --target-disable=0
#switch programming target
	$(MUXR) --port=$(TARGET)
#install muster-program on selected target
	$(PROGR) --erase --program --file muster.elf --jtag $(INTERFACE) 
#resetting programmer and node
	$(MUXR) --reset16
	$(MUXR) --target-disable=1
	$(MUXR) --target-disable=0
#disable programmer
	$(MUXR) --global-disable=1
