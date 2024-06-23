
module icd.common.types.func_types;

mixin(ic_info("import"));
    import icd.common.macros;
    import icd.common.types.value_types;

mixin(ic_info("declarations")); extern(C) {
    mixin(icd_dcl_f("ic_operate_f",  "void",     "(void_p pMem)", "nothrow"));
    mixin(icd_dcl_f("ic_alloc_f",    "void_p",   "(size_t btSz)", "nothrow"));
    mixin(icd_dcl_f("ic_realloc_f",  "void_p",   "(void_p pMem, size_t btSz)", "nothrow"));
    mixin(ic_alias("ic_dealloc_f",   "ic_operate_f"));
    mixin(ic_alias("ic_construct_f", "ic_operate_f"));
    mixin(ic_alias("ic_destruct_f",  "ic_operate_f"));
    mixin(icd_dcl_f("ic_compare_f",  "bool",     "(cvoid_p pObjA, cvoid_p pObjB)", "nothrow"));
    mixin(icd_dcl_f("ic_assign_f",   "void",     "(void_p pDstObj, cvoid_p pSrcObj)", "nothrow"));
}

version(Windows) {
    extern(Windows) {
        mixin(icd_dcl_f("ic_thread_f", "thr_t", "(void_p pParams)", "nothrow"));
    }
} else {
    extern(C) {
        mixin(icd_dcl_f("ic_thread_f", "thr_t", "(void_p pParams)", "nothrow"));
    }
}