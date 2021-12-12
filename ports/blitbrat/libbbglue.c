#include "py/runtime.h"

STATIC const mp_rom_map_elem_t bb_module_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_bb) },
};
STATIC MP_DEFINE_CONST_DICT(bb_module_globals, bb_module_globals_table);

const mp_obj_module_t mp_module_bb = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&bb_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_bb, mp_module_bb, 1);
