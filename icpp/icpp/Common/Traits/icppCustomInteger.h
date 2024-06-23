
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"../icppCommonHeaders.h"

/*
    1.custom_integer
    2.int_g
    3.sint_g
    4.uint_g
*/

ic_info("H...")
    icpp_v2(size_t Sz, bool isSigned) struct H_icpp_custom_integer;
        #define icpp_define_custom_sint(n, T) template<> struct H_icpp_custom_integer<n, true>  { icpp_alias(type, T); }
        #define icpp_define_custom_uint(n, T) template<> struct H_icpp_custom_integer<n, false> { icpp_alias(type, T); }
            ic_macro_x4_param_x2(icpp_define_custom_sint, 1, int8_t,  2, int16_t,  4, int32_t,  8, int64_t);
            ic_macro_x4_param_x2(icpp_define_custom_uint, 1, uint8_t, 2, uint16_t, 4, uint32_t, 8, uint64_t);
            #ifdef IC_CE_GNUC
                ic_macro_x1_param_x2(icpp_define_custom_sint, 16, int128_t);
                ic_macro_x1_param_x2(icpp_define_custom_uint, 16, uint128_t);
            #endif
        #undef icpp_define_custom_sint
        #undef icpp_define_custom_uint

icpp_ns_x1(icpp)
    icpp_v2(size_t Sz, bool isSigned = true) icpp_alias(custom_integer, typename H_icpp_custom_integer<Sz, isSigned>::type);
    icpp_v2(size_t Sz, bool isSigned = true) icpp_alias(int_g,          custom_integer<Sz, isSigned>);
    icpp_v1(size_t Sz) icpp_alias(sint_g, int_g<Sz, true>);
    icpp_v1(size_t Sz) icpp_alias(uint_g, int_g<Sz, false>);
icpp_end_ns_x1;