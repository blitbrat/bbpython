# Include the core environment definitions; this will set $(TOP).
include ../../py/mkenv.mk

# Include py core make definitions.
include $(TOP)/py/py.mk

# Set CFLAGS and libraries.
CROSS_COMPILE ?= arm-none-eabi-
CFLAGS = -I. -I$(BUILD) -I$(TOP) -march=armv7-m -Os -g -msingle-pic-base -mpic-register=r9 -mno-pic-data-is-text-relative -static -fPIE
LIBS = -lc -lm -lcstartup -lbb -lgcc
LIBGCC_DIR = $(shell dirname $$(arm-none-eabi-gcc -print-libgcc-file-name))
LDFLAGS = -T ldscripts/bbc.ld "-L$(LIBGCC_DIR)" -z text -static -pie --gc-sections --no-dynamic-linker

# Define the required source files.
SRC_C = \
	main.c \
	mphalport.c \
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
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(Q)$(SIZE) $@

# Include remaining core make rules.
include $(TOP)/py/mkrules.mk
