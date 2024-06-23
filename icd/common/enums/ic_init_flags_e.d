
//module:
    module icd.common.enums.ic_init_flags_e;

//import:
    import icd.common.macros;

mixin(ic_info("ic初始化枚举"));
    enum ic_init_flags_e {
        ic_itf_utf8_v          = 0x00000001,
        ic_itf_console_color_v = 0x00000002,
        ic_itf_default_v       = ic_itf_utf8_v | ic_itf_console_color_v,
    }
    alias ic_init_e = ic_init_flags_e;