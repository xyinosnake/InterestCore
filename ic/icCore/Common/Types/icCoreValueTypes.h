
#pragma once

#include"../Macros/icCoreCommonMacros.h"

ic_info("headers")
    #ifdef __cplusplus
        #include<cstdint>
        #include<cstddef>
    #else
        #include<stddef.h>
        #include<stdint.h>
        #include<stdbool.h>
    #endif
    #include"./ic_def_t.h"

ic_info("cint cuint")
    ic_expand_t(int8_t,  cint8_t,  int8_p,  cint8_p);
    ic_expand_t(int16_t, cint16_t, int16_p, cint16_p);
    ic_expand_t(int32_t, cint32_t, int32_p, cint32_p);
    ic_expand_t(int64_t, cint64_t, int64_p, cint64_p);

    ic_expand_t(uint8_t,  cuint8_t,  uint8_p,  cuint8_p);
    ic_expand_t(uint16_t, cuint16_t, uint16_p, cuint16_p);
    ic_expand_t(uint32_t, cuint32_t, uint32_p, cuint32_p);
    ic_expand_t(uint64_t, cuint64_t, uint64_p, cuint64_p);

ic_info("sint (signed int, same to int)")
    ic_def_t(sint8_t,  csint8_t , sint8_p,  csint8_p , int8_t);
    ic_def_t(sint16_t, csint16_t, sint16_p, csint16_p, int16_t);
    ic_def_t(sint32_t, csint32_t, sint32_p, csint32_p, int32_t);
    ic_def_t(sint64_t, csint64_t, sint64_p, csint64_p, int64_t);

ic_info("GNU专有")
    #ifdef IC_CE_GNUC
        ic_def_t(sint128_t, csint128_t, sint128_p, csint128_p, __int128_t);
        ic_def_t(uint128_t, cuint128_t, uint128_p, cuint128_p, __uint128_t);
        ic_def_t(int128_t,  cint128_t,  int128_p,  cint128_p,  __int128_t);
    #endif

ic_info("等价2型")
    ic_def_t(sint32_2_t, csint32_2_t, sint32_2_p, csint32_2_p, signed   long);
    ic_def_t(uint32_2_t, cuint32_2_t, uint32_2_p, cuint32_2_p, unsigned long);
    ic_def_t(int32_2_t,  cint32_2_t,  int32_2_p,  cint32_2_p,  signed   long);

ic_info("csize cptrdiff")
    ic_expand_t(size_t,    csize_t,    size_p,    csize_p);
    ic_expand_t(ptrdiff_t, cptrdiff_t, ptrdiff_p, cptrdiff_p);

ic_info("flo")
    ic_def_t(flo32_t, cflo32_t, flo32_p, cflo32_p, float);
    ic_def_t(flo64_t, cflo64_t, flo64_p, cflo64_p, double);

ic_info("MINI TYPES")
#ifndef IC_NO_MINI_TYPES
    ic_def_t(i8_t,  ci8_t,  i8_p,  ci8_p,  int8_t);
    ic_def_t(i16_t, ci16_t, i16_p, ci16_p, int16_t);
    ic_def_t(i32_t, ci32_t, i32_p, ci32_p, int32_t);
    ic_def_t(i64_t, ci64_t, i64_p, ci64_p, int64_t);
    ic_def_t(u8_t,  cu8_t,  u8_p,  cu8_p,  uint8_t);
    ic_def_t(u16_t, cu16_t, u16_p, cu16_p, uint16_t);
    ic_def_t(u32_t, cu32_t, u32_p, cu32_p, uint32_t);
    ic_def_t(u64_t, cu64_t, u64_p, cu64_p, uint64_t);
    ic_def_t(f32_t, cf32_t, f32_p, cf32_p, flo32_t);
    ic_def_t(f64_t, cf64_t, f64_p, cf64_p, flo64_t);
#endif

ic_info("bool_t")
    ic_def_t(bool_t, cbool_t, bool_p, cbool_p, bool);

ic_info("void_t")
    ic_def_t(void_t, cvoid_t, void_p, cvoid_p, void);

ic_info("char types")
    #ifdef IC_OS_WINDOWS
        #include"./icCharTypes_Windows.h"
    #else
        #include"./icCharTypes_UnixLike.h"
    #endif

ic_info("Unicode Char Types.")
    #ifndef __cplusplus
    ic_info("C Mode")
        ic_def_t(utf8_t,  cutf8_t,  utf8_p,  cutf8_p,  ch8_t);
        ic_def_t(utf16_t, cutf16_t, utf16_p, cutf16_p, ch16_t);
        ic_def_t(utf32_t, cutf32_t, utf32_p, cutf32_p, ch32_t);
    #else
    ic_info("C++ Mode")
        ic_def_t(utf8_t,  cutf8_t,  utf8_p,  cutf8_p,  char8_t);
        ic_def_t(utf16_t, cutf16_t, utf16_p, cutf16_p, char16_t);
        ic_def_t(utf32_t, cutf32_t, utf32_p, cutf32_p, char32_t);
    #endif

ic_info("线程返回值类型")
    #if defined(IC_OS_WINDOWS)
        ic_alias(ic_thr_t, uint32_t); //Always uint32_t(Same to Windows DWORD).
    #elif defined(IC_OS_UNIX_LIKE)
        ic_alias(ic_thr_t, size_t); //uint32_t on 32, uint64_t on 64.
    #endif
    #ifndef IC_NO_THR_T
        ic_alias(thr_t, ic_thr_t);
    #endif
