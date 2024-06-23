
#pragma once

#include"../icppCommonHeaders.h"
#include"../Macros/icppCommonMacros.h"
#include"../../../../ic/ic/Common/Types/icCommonTypes.h"

ic_info("icpp Ex")
    struct icppNoConstruct {};
    struct icppFlusher {};
    icpp_t1(value_xt) using icppIL = ::std::initializer_list<value_xt>;

ic_info("using") icpp_ns_x1(icpp)
    ic_info("cint cuint")
        icpp_using_x4(::, int8_t,  cint8_t,  int8_p,  cint8_p);
        icpp_using_x4(::, int16_t, cint16_t, int16_p, cint16_p);
        icpp_using_x4(::, int32_t, cint32_t, int32_p, cint32_p);
        icpp_using_x4(::, int64_t, cint64_t, int64_p, cint64_p);

        icpp_using_x4(::, uint8_t,  cuint8_t,  uint8_p,  cuint8_p);
        icpp_using_x4(::, uint16_t, cuint16_t, uint16_p, cuint16_p);
        icpp_using_x4(::, uint32_t, cuint32_t, uint32_p, cuint32_p);
        icpp_using_x4(::, uint64_t, cuint64_t, uint64_p, cuint64_p);
    
    ic_info("sint (signed int, same to int)")
        icpp_using_x4(::, sint8_t,  csint8_t , sint8_p,  csint8_p);
        icpp_using_x4(::, sint16_t, csint16_t, sint16_p, csint16_p);
        icpp_using_x4(::, sint32_t, csint32_t, sint32_p, csint32_p);
        icpp_using_x4(::, sint64_t, csint64_t, sint64_p, csint64_p);
    
    ic_info("GNU专有")
        #ifdef IC_CE_GNUC
            icpp_using_x4(::, sint128_t, csint128_t, sint128_p, csint128_p);
            icpp_using_x4(::, uint128_t, cuint128_t, uint128_p, cuint128_p);
            icpp_using_x4(::, int128_t,  cint128_t,  int128_p,  cint128_p);
        #endif

    ic_info("等价2型")
        icpp_using_x4(::, sint32_2_t, csint32_2_t, sint32_2_p, csint32_2_p);
        icpp_using_x4(::, uint32_2_t, cuint32_2_t, uint32_2_p, cuint32_2_p);
        icpp_using_x4(::, int32_2_t,  cint32_2_t,  int32_2_p,  cint32_2_p);

    ic_info("csize cptrdiff")
        icpp_using_x4(::, size_t,    csize_t,    size_p,    csize_p);
        icpp_using_x4(::, ptrdiff_t, cptrdiff_t, ptrdiff_p, cptrdiff_p);
    
    ic_info("flo")
        icpp_using_x4(::, flo32_t, cflo32_t, flo32_p, cflo32_p);
        icpp_using_x4(::, flo64_t, cflo64_t, flo64_p, cflo64_p);

    ic_info("MINI TYPES")
        #ifndef IC_NO_MINI_TYPES
            icpp_using_x4(::, i8_t,  ci8_t,  i8_p,  ci8_p);
            icpp_using_x4(::, i16_t, ci16_t, i16_p, ci16_p);
            icpp_using_x4(::, i32_t, ci32_t, i32_p, ci32_p);
            icpp_using_x4(::, i64_t, ci64_t, i64_p, ci64_p);
            icpp_using_x4(::, u8_t,  cu8_t,  u8_p,  cu8_p);
            icpp_using_x4(::, u16_t, cu16_t, u16_p, cu16_p);
            icpp_using_x4(::, u32_t, cu32_t, u32_p, cu32_p);
            icpp_using_x4(::, u64_t, cu64_t, u64_p, cu64_p);
            icpp_using_x4(::, f32_t, cf32_t, f32_p, cf32_p);
            icpp_using_x4(::, f64_t, cf64_t, f64_p, cf64_p);
        #endif

    ic_info("bool_t")
        icpp_using_x4(::, bool_t, cbool_t, bool_p, cbool_p);

    ic_info("void_t")
        icpp_using_x4(::, void_t, cvoid_t, void_p, cvoid_p);

    ic_info("ch_t")
        icpp_using_x4(::, ch8_t,  cch8_t,  ch8_p,  cch8_p);
        icpp_using_x4(::, ch16_t, cch16_t, ch16_p, cch16_p);
        icpp_using_x4(::, ch32_t, cch32_t, ch32_p, cch32_p);
        icpp_using_x4(::, nch_t, cnch_t, nch_p, cnch_p);
        icpp_using_x4(::, wch_t, cwch_t, wch_p, cwch_p);
        #ifdef IC_OS_WINDOWS
            icpp_using_x4(::, ach_t, cach_t, ach_p, cach_p); //Windows专有
        #endif
    
    ic_info("Unicode Char Types.")
        icpp_using_x4(::, utf8_t,  cutf8_t,  utf8_p,  cutf8_p);
        icpp_using_x4(::, utf16_t, cutf16_t, utf16_p, cutf16_p);
        icpp_using_x4(::, utf32_t, cutf32_t, utf32_p, cutf32_p);
    
    ic_info("线程返回值类型 thr_t")
        icpp_alias(thr_t, ic_thr_t);

    ic_info("icpp Ex")
        icpp_alias(NoConstruct, icppNoConstruct);
        icpp_alias(Flusher,     icppFlusher);
        icpp_t1(value_xt) icpp_alias(IL, icppIL<value_xt>);
icpp_end_ns_x1