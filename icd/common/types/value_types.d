
module icd.common.types.value_types;

mixin(ic_info("import"));
    import icd.common.macros;
    import icd.common.types.ic_def_t;

mixin(ic_info("int"));
    mixin(ic_def_t("int8_t",  "cint8_t",  "int8_p",  "cint8_p",  "byte"));
    mixin(ic_def_t("int16_t", "cint16_t", "int16_p", "cint16_p", "short"));
    mixin(ic_def_t("int32_t", "cint32_t", "int32_p", "cint32_p", "int"));
    mixin(ic_def_t("int64_t", "cint64_t", "int64_p", "cint64_p", "long"));

mixin(ic_info("uint"));
    mixin(ic_def_t("uint8_t",  "cuint8_t",  "uint8_p",  "cuint8_p",  "ubyte"));
    mixin(ic_def_t("uint16_t", "cuint16_t", "uint16_p", "cuint16_p", "ushort"));
    mixin(ic_def_t("uint32_t", "cuint32_t", "uint32_p", "cuint32_p", "uint"));
    mixin(ic_def_t("uint64_t", "cuint64_t", "uint64_p", "cuint64_p", "ulong"));

mixin(ic_info("default int & uint"));
    mixin(ic_def_t("int_t",  "cint_t",  "int_p",  "cint_p",  "int"));
    mixin(ic_def_t("uint_t", "cuint_t", "uint_p", "cuint_p", "uint"));

mixin(ic_info("sint"));
    mixin(ic_def_t("sint8_t",  "csint8_t",  "sint8_p",  "csint8_p",  "int8_t"));
    mixin(ic_def_t("sint16_t", "csint16_t", "sint16_p", "csint16_p", "int16_t"));
    mixin(ic_def_t("sint32_t", "csint32_t", "sint32_p", "csint32_p", "int32_t"));
    mixin(ic_def_t("sint64_t", "csint64_t", "sint64_p", "csint64_p", "int64_t"));

mixin(ic_info("flo"));
    mixin(ic_def_t("flo32_t", "cflo32_t", "flo32_p", "cflo32_p", "float"));
    mixin(ic_def_t("flo64_t", "cflo64_t", "flo64_p", "cflo64_p", "double"));

mixin(ic_info("char types"));
    mixin(ic_def_t("ch8_t",  "cch8_t",  "ch8_p",  "cch8_p",  "char"));
    mixin(ic_def_t("ch16_t", "cch16_t", "ch16_p", "cch16_p", "wchar"));
    mixin(ic_def_t("ch32_t", "cch32_t", "ch32_p", "cch32_p", "dchar"));

    mixin(ic_def_t("nch_t", "cnch_t", "nch_p", "cnch_p", "ch8_t"));
    version(Windows) {
        mixin(ic_def_t("ach_t", "cach_t", "ach_p", "cach_p", "ch8_t"));
        mixin(ic_def_t("wch_t", "cwch_t", "wch_p", "cwch_p", "ch16_t"));
    } else {
        mixin(ic_def_t("wch_t", "cwch_t", "wch_p", "cwch_p", "ch32_t"));
    }

mixin(ic_info("utf char types"));
    mixin(ic_def_t("utf8_t",  "cutf8_t",  "utf8_p",  "cutf8_p",  "ch8_t"));
    mixin(ic_def_t("utf16_t", "cutf16_t", "utf16_p", "cutf16_p", "ch16_t"));
    mixin(ic_def_t("utf32_t", "cutf32_t", "utf32_p", "cutf32_p", "ch32_t"));

mixin(ic_info("bool_t"));
    mixin(ic_def_t("bool_t", "cbool_t", "bool_p", "cbool_p", "bool"));

mixin(ic_info("void_t"));
    mixin(ic_def_t("void_t", "cvoid_t", "void_p", "cvoid_p", "void"));

mixin(ic_info("MINI TYPES"));
    mixin(ic_def_t("i8_t",  "ci8_t",  "i8_p",  "ci8_p",  "int8_t"));
    mixin(ic_def_t("i16_t", "ci16_t", "i16_p", "ci16_p", "int16_t"));
    mixin(ic_def_t("i32_t", "ci32_t", "i32_p", "ci32_p", "int32_t"));
    mixin(ic_def_t("i64_t", "ci64_t", "i64_p", "ci64_p", "int64_t"));
    mixin(ic_def_t("u8_t",  "cu8_t",  "u8_p",  "cu8_p",  "uint8_t"));
    mixin(ic_def_t("u16_t", "cu16_t", "u16_p", "cu16_p", "uint16_t"));
    mixin(ic_def_t("u32_t", "cu32_t", "u32_p", "cu32_p", "uint32_t"));
    mixin(ic_def_t("u64_t", "cu64_t", "u64_p", "cu64_p", "uint64_t"));
    mixin(ic_def_t("f32_t", "cf32_t", "f32_p", "cf32_p", "flo32_t"));
    mixin(ic_def_t("f64_t", "cf64_t", "f64_p", "cf64_p", "flo64_t"));

mixin(ic_info("thr_t")); //thr_t = ic_thr_t
    version(Windows) {
        alias thr_t = uint32_t; //Always uint32_t(Same to Windows DWORD).
    } else { //UNIX_LIKE
        alias thr_t = size_t; //uint32_t on 32, uint64_t on 64.
    }