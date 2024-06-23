
#pragma once

#include"../icppCommonHeaders.h"
#include"./icppIsAnyOfTypes.h"

ic_info("declarations") icpp_ns_x1(icpp)
    icpp_t3(type_xt, case0_xt, ...cases_xt)
    inline constexpr size_t matched_type_index() noexcept;
icpp_end_namespace_x1;

ic_info("definitions") icpp_namespace_x1(icpp)
    icpp_t3(type_xt, case0_xt, ...cases_xt)
    inline constexpr size_t matched_type_index() noexcept {
        static_assert(icpp::is_any_of_types_v<type_xt, case0_xt, cases_xt...>, "No type case matched!");
        icpp_static_if(::std::is_same_v<type_xt, case0_xt>) {
            return 0;
        } else {
            return 1 + matched_type_index<type_xt, cases_xt...>();
        }
    }
icpp_end_ns_x1;