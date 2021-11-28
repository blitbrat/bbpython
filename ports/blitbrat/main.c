#include "py/compile.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "py/stackctrl.h"
#include "shared/runtime/gchelper.h"
#include "shared/runtime/pyexec.h"

// Static memory block for the MicroPython heap.
// TODO: Can we make this grow as needed using blitbrat system calls, rather
// than statically allocating it?
static char heap[4096];

int main(int argc, char **argv) {
    // Initialise the MicroPython runtime.
    mp_stack_ctrl_init();
    gc_init(heap, heap + sizeof(heap));
    mp_init();
    mp_obj_list_init(MP_OBJ_TO_PTR(mp_sys_path), 0);
    mp_obj_list_init(MP_OBJ_TO_PTR(mp_sys_argv), 0);

    // Start a normal REPL; will exit when ctrl-D is entered on a blank line.
    // TODO: Run the embedded game bytecode instead.
    pyexec_friendly_repl();

    // Deinitialise the runtime.
    gc_sweep_all();
    mp_deinit();
    return 0;
}

// Handle uncaught exceptions (should not get here)
void nlr_jump_fail(void *val) {
    for (;;) {
    }
}

// Do a garbage collection cycle.
void gc_collect(void) {
    gc_collect_start();
    gc_helper_collect_regs_and_stack();
    gc_collect_end();
}

mp_import_stat_t mp_import_stat(const char *path) {
    return MP_IMPORT_STAT_NO_EXIST;
}

mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
    // We have no filesystem, so no files exist.
    mp_raise_OSError(MP_ENOENT);
}

#if !MICROPY_VFS
mp_obj_t mp_builtin_open(size_t n_args, const mp_obj_t *args, mp_map_t *kwargs) {
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(mp_builtin_open_obj, 1, mp_builtin_open);
#endif
