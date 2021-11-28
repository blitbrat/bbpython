#include <stdint.h>
#include <stddef.h>

// For now we'll enable just the basic features. We might increase this later
// since BlitBrat cartridges will probably have enough room to spend a little
// more on MicroPython VM features, but we'll see how things go.
#define MICROPY_CONFIG_ROM_LEVEL (MICROPY_CONFIG_ROM_LEVEL_BASIC_FEATURES)

// Python internal features.
#define MICROPY_ENABLE_GC       (1)
#define MICROPY_HELPER_REPL     (1)
#define MICROPY_ERROR_REPORTING (MICROPY_ERROR_REPORTING_TERSE)
#define MICROPY_FLOAT_IMPL      (MICROPY_FLOAT_IMPL_NONE)

typedef intptr_t mp_int_t;
typedef uintptr_t mp_uint_t;
typedef long mp_off_t;

// MicroPython depends on the alloca function, which isn't C standard but
// BlitBrat's newlib port has it.
#include <alloca.h>

// "BlitBrat" isn't really a board but we'll call it one to satisfy
// MicroPython's assumptions.
#define MICROPY_HW_BOARD_NAME   "BlitBrat"
#define MICROPY_HW_MCU_NAME     "ARMv6-M"
#define MICROPY_PY_SYS_PLATFORM "blitbrat"
#define MICROPY_PY_SYS_EXIT     (0)

#define MP_STATE_PORT MP_STATE_VM

#define MICROPY_PORT_ROOT_POINTERS \
    const char *readline_hist[8];
