####################################################################
# Makefile --> dedicated for the target environment                #
####################################################################

.SUFFIXES:				# ignore builtin rules
.PHONY: all debug clean 

####################################################################
# Definitions                                                      #
####################################################################
EXENAME  = testsrv

OUT_NAME = output
OUT_DIR  = ./$(OUT_NAME)
OBJ_DIR  = $(OUT_DIR)/build
EXE_DIR  = $(OUT_DIR)/exe

####################################################################
# Definitions of toolchain.                                        #
# You might need to do changes to match your system setup          #
####################################################################

CC      = $(QUOTE)gcc$(QUOTE)
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
-I./include -I../include
CFLAGS      += -DDEBUG -O0 -g3
SPLINTFLAGS +=  +standard -mustfreeonly -likelybool -temptrans -mayaliasunique \
                -nullstate -mustdefine -compdef -mustfreefresh

####################################################################
# Files                                                            #
####################################################################

C_SRC +=  \
../src/bcd.c  \
../src/r_buffer.c  \
./src/test_bcd.c \
./src/test_r_buffer.c \
./src/main.c

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
all:      $(OBJ_DIR) $(EXE_DIR) $(EXE_DIR)/$(EXENAME).exe

# Create directories
$(OBJ_DIR):
	@echo "Creating build directory."
	mkdir -p $(OUT_DIR)
	mkdir $(OBJ_DIR)

$(EXE_DIR):
	@echo "Created executable directory."
	mkdir $(EXE_DIR)

# Create objects from C SRC files
$(OBJ_DIR)/%.o: %.c
	@echo "Building file: $<"
	$(CC) $(CFLAGS) $(INCLUDEPATHS) -c -o $@ $<

# Assemble .s files
$(OBJ_DIR)/%.o: %.s
	@echo "Assembling $<"
	$(CC) $(ASMFLAGS) $(INCLUDEPATHS) -c -o $@ $<

# Link
$(EXE_DIR)/$(EXENAME).exe: $(C_OBJS) $(S_OBJS)
	@echo "Linking target: $@"
	$(CC) $(LDFLAGS) $(C_OBJS) $(LIBS) -o $(EXE_DIR)/$(EXENAME).exe

clean:
	$(RM) $(OBJ_DIR) $(LST_DIR) $(EXE_DIR) $(OUT_DIR)/$(LIBNAME).a $(OUT_DIR) $(TESTDIR)/$(OUT_NAME)

# include auto-generated dependency files (explicit rules)
ifneq (clean,$(findstring clean, $(MAKECMDGOALS)))
-include $(C_DEPS)
endif
