
#pragma once

#include"../icppCommonHeaders.h"
#include"../Macros/icppCommonMacros.h"

template<size_t index, typename case0_xt, typename...cases_xt>
struct H_icpp_type_of_index {
    static_assert(index < sizeof...(cases_xt), "index out of range!");
    icpp_alias(type, typename H_icpp_type_of_index<index - 1, cases_xt...>::type);
};

icpp_t2(case0_xt, ...cases_xt) struct H_icpp_type_of_index<0, case0_xt, cases_xt...> {
    icpp_alias(type, case0_xt);
};


ic_info("in ns") icpp_ns_x1(icpp)
    template<size_t index, typename case0_xt, typename...cases_xt>
    icpp_alias(type_of_index, typename H_icpp_type_of_index<index, case0_xt, cases_xt...>::type);
icpp_end_ns_x1;