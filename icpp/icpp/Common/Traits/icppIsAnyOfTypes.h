
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"../icppCommonHeaders.h"

icpp_ns_x1(icpp)
    ic_info("traits bool")
        icpp_t2(type_xt, ...types_xt)
        icpp_bv is_any_of_types_v = ::std::disjunction_v<::std::is_same<type_xt, types_xt>...>;

    ic_info("traits type")
        icpp_t2(type_xt, ...types_xt)
        struct is_any_of_types:
            ::std::bool_constant<is_any_of_types_v<type_xt, types_xt...>> {};

    ic_info("concepts")
        icpp_t2(type_xt, ...types_xt)
        concept any_of_types = is_any_of_types_v<type_xt, types_xt...>;

icpp_end_ns_x1;