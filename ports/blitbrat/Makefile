# Include the core environment definitions; this will set $(TOP).
include ../../py/mkenv.mk

# Include py core make definitions.
include $(TOP)/py/py.mk

# Set CFLAGS and libraries.
CROSS_COMPILE ?= arm-blitbrat-
CFLAGS = -I. -I$(BUILD) -I$(TOP) -Os -g -static -fPIE
LIBS = 
LDFLAGS = -static -pie

# Define the required source files.
SRC_C = \
	main.c \
	mphalport.c \
	libbbglue.c \
	shared/readline/readline.c \
	shared/runtime/gchelper_generic.c \
	shared/runtime/pyexec.c \
	shared/runtime/stdout_helpers.c \

# Define the required object files.
OBJ = $(PY_CORE_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o))

# Define the top-level target, the main firmware.
all: $(BUILD)/bbpython.elf

# Define how to build the firmware.
$(BUILD)/bbpython.elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(Q)$(SIZE) $@

# Include remaining core make rules.
include $(TOP)/py/mkrules.mk
