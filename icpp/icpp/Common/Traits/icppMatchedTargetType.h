
#pragma once

#include"../icppCommonHeaders.h"


icpp_t4(type_xt, case0_xt, target0_xt, ...cases_xt)
    struct H_icpp_matched_target_type {
        icpp_alias(type, typename H_icpp_matched_target_type<type_xt, cases_xt...>::type);
    };

icpp_t3(type_xt, target0_xt, ...cases_xt)
    struct H_icpp_matched_target_type<type_xt, type_xt, target0_xt, cases_xt...> {
        icpp_alias(type, target0_xt);
    };

icpp_ns_x1(icpp)
    icpp_t4(type_xt, case0_xt, target0_xt, ...cases_xt)
        icpp_alias(matched_target_type, 
            typename H_icpp_matched_target_type<type_xt, case0_xt, target0_xt, cases_xt...>::type);
icpp_end_ns_x1