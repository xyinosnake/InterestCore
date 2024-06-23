
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"./icppIsAnyOfTypes.h"

icpp_ns_x1(icpp)
    ic_info("traits type")
        icpp_t1(char_xt) struct is_char_type:
            ::std::bool_constant<is_any_of_types_v<::std::remove_cvref_t<char_xt>,
                char, wchar_t, char8_t, char16_t, char32_t>> {};

    ic_info("traits bool")
        icpp_t1(char_xt)
        icpp_bv is_char_type_v = is_char_type<char_xt>::value;

    ic_info("concepts")
        icpp_t1(char_xt)
        concept char_type = is_char_type_v<char_xt>;

icpp_end_ns_x1;