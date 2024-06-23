
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"../icppCommonHeaders.h"

icpp_ns_x1(icpp)
    ic_info("concepts")
        icpp_t1c(range_type, range_xt)(const range_xt& r) {
            *r.begin();
            *r.end();
        };

    ic_info("traits type")
        icpp_t1(type_xt) struct is_range_type:
            ::std::false_type{};
        icpp_c1(range_type type_xt) struct is_range_type<type_xt>:
            ::std::true_type{};
    
    ic_info("traits bool")
        icpp_t1(type_xt)
        icpp_bv is_range_type_v = is_range_type<type_xt>::value;

icpp_end_ns_x1;