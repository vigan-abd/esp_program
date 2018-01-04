####################################################################
# Makefile --> dedicated for the target environment                #
####################################################################

.SUFFIXES:				# ignore builtin rules
.PHONY: all debug release test-pc clean 

####################################################################
# Definitions                                                      #
####################################################################
LIBNAME  = libuart
LIBDIR   = ../libdir

OUT_NAME = output
OUT_DIR  = ./$(OUT_NAME)
OBJ_DIR  = $(OUT_DIR)/build
LST_DIR  = $(OUT_DIR)/lst
EXE_DIR  = $(OUT_DIR)/exe
TESTDIR  = $(shell pwd)/test

####################################################################
# Definitions of toolchain.                                        #
# You might need to do changes to match your system setup          #
####################################################################
include ../../Makefile.set

MAKE    = $(QUOTE)make$(QUOTE)
SPLINT  = $(QUOTE)splint$(QUOTE)
DOXYGEN = $(QUOTE)doxygen$(QUOTE)
RM  	= $(QUOTE)rm -rf$(QUOTE)

####################################################################
# Flags                                                            #
####################################################################

# -MMD : Don't generate dependencies on system header files.
# -MP  : Add phony targets, useful when a h-file is removed from a project.
# -MF  : Specify a file to write the dependencies to.
DEPFLAGS = -MMD -MP -MF $(@:.o=.d)

INCLUDEPATHS += \
-I./include -I../libsrv/include 

SPLINTFLAGS +=  +standard -mustfreeonly -likelybool -temptrans -mayaliasunique \
                -nullstate -mustdefine -compdef -mustfreefresh

####################################################################
# Files                                                            #
####################################################################

C_SRC +=  \
./src/uart.c  

S_SRC +=  

####################################################################
# Rules                                                            #
####################################################################

C_FILES = $(notdir $(C_SRC) )
S_FILES = $(notdir $(S_SRC) )
#make list of source paths, sort also removes duplicates
C_PATHS = $(sort $(dir $(C_SRC) ) )
S_PATHS = $(sort $(dir $(S_SRC) ) )

C_OBJS = $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.o))
S_OBJS = $(addprefix $(OBJ_DIR)/, $(S_FILES:.s=.o))
C_DEPS = $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.d))

vpath %.c $(C_PATHS)
vpath %.s $(S_PATHS)

# Default build is debug build
all:      debug
## all:      test-pc

test-pc: $(OBJ_DIR) $(LST_DIR) $(EXE_DIR) test-pc-do

debug:    CFLAGS += -DDEBUG -O0 -g3 -DBAUD0=9600 -DBAUD1=9600
debug:    $(OBJ_DIR) $(LST_DIR) $(EXE_DIR) $(EXE_DIR)/$(LIBNAME).a

release:  CFLAGS += -DNDEBUG -O3 
release:  $(OBJ_DIR) $(LST_DIR) $(EXE_DIR) $(EXE_DIR)/$(LIBNAME).a

# Create directories
$(OBJ_DIR):
	mkdir -p $(OUT_DIR)
	mkdir -p $(LIBDIR)
	mkdir $(OBJ_DIR)
	@echo "Created build directory."

$(EXE_DIR):
	mkdir $(EXE_DIR)
	@echo "Created executable directory."

$(LST_DIR):
	mkdir $(LST_DIR)
	@echo "Created list directory."

# Create objects from C SRC files
$(OBJ_DIR)/%.o: %.c
	@echo "Building file: $<"
	$(CC) $(CFLAGS) $(INCLUDEPATHS) -c -o $@ $<

# Assemble .s files
$(OBJ_DIR)/%.o: %.s
	@echo "Assembling $<"
	$(CC) $(ASMFLAGS) $(INCLUDEPATHS) -c -o $@ $<

# Link
$(EXE_DIR)/$(LIBNAME).a: $(C_OBJS) $(S_OBJS)
	@echo "Linking target: $@"
	$(AR) rs $(EXE_DIR)/$(LIBNAME).a $(C_OBJS) $(S_OBJS) $(LIBS)
	cp -p $(EXE_DIR)/$(LIBNAME).a $(LIBDIR)

splint:
	@echo "Making the test directory."
	for file in $(C_SRC); \
	do \
		echo "Static check (using splint utility) the $$file"; \
		$(SPLINT) $(SPLINTFLAGS) $(INCLUDEPATHS) $$file; \
	done

test-pc-do:
	@echo "Making <<test-pc>> in the test directory: $(TESTDIR)"
	$(MAKE) -C $(TESTDIR) clean all

utest:
	@echo "Making <<unit testc>> in the test directory: $(TESTDIR)"
	$(MAKE) -C $(TESTDIR) clean utest

dox: 
	@echo "Doxygen output will be stored in $(OUTPUT_DIR)"
	mkdir -p $(OUT_DIR)
	@echo "Created doxygen directory."
	$(DOXYGEN) ./dox/libgen_dx.cfg

clean:
	$(RM) $(OBJ_DIR) $(LST_DIR) $(EXE_DIR) $(OUT_DIR)/$(LIBNAME).a $(OUT_DIR) $(TESTDIR)/$(OUT_NAME)

# include auto-generated dependency files (explicit rules)
ifneq (clean,$(findstring clean, $(MAKECMDGOALS)))
-include $(C_DEPS)
endif
