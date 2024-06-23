
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"../icppCommonHeaders.h"
#include"../Types/icppCommonTypes.h"

/*
说明：
    凡继承自::icpp::iof_types::iof_types_base的对象，
都算是iof_types。C++的traits看来没有办法以对象的名称空间为判定依据，
否则这个iof_types_base对象就完全是多余的。
*/


icpp_ns_x1(icpp)
    ic_info("is_iof_types & is_iof_types_v")
        icpp_t1(value_xt) struct is_iof_types:
            ::std::conditional_t<::std::is_base_of_v<iof_types::iof_types_base, value_xt>,
            ::std::true_type,
            ::std::false_type> {};
        icpp_t1(value_xt)
            icpp_bv is_iof_types_v = is_iof_types<value_xt>::value;

    ic_info("is_hex & is_hex_v")
        icpp_t1(value_xt)
            struct is_hex: ::std::false_type {};
        icpp_t1(value_xt)
            struct is_hex<iof_types::hex<value_xt>>: ::std::true_type {};
        icpp_t1(value_xt)
            constexpr bool is_hex_v = is_hex<value_xt>::value;

    ic_info("is_HEX & is_HEX_v")
        icpp_t1(value_xt)
            struct is_HEX: ::std::false_type {};
        icpp_t1(value_xt)
            struct is_HEX<iof_types::HEX<value_xt>>: ::std::true_type {};
        icpp_t1(value_xt)
            icpp_bv is_HEX_v = is_HEX<value_xt>::value;

    ic_info("is_bin & is_bin_v")
        icpp_t1(value_xt)
            struct is_bin: ::std::false_type {};
        icpp_t1(value_xt)
            struct is_bin<iof_types::bin<value_xt>>: ::std::true_type {};
        icpp_t1(value_xt)
            icpp_bv is_bin_v = is_bin<value_xt>::value;

icpp_end_ns_x1