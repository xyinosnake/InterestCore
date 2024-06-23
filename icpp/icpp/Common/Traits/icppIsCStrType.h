
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"./icppIsAnyOfTypes.h"

icpp_ns_x1(icpp)
    ic_info("traits type")
        icpp_t1(str_xt) struct is_c_str_type:
            ::std::bool_constant<is_any_of_types_v<::std::remove_cvref_t<str_xt>,
                char*, wchar_t*, char8_t*, char16_t*, char32_t*,
                const char*, const wchar_t*, const char8_t*, const char16_t*, const char32_t*>> {};

        icpp_t1v1(char_xt, size_t CharSize) struct is_c_str_type<char_xt[CharSize]>:
            ::std::bool_constant<is_char_type<char_xt>::value> {};

        icpp_t1(char_xt) struct is_c_str_type<char_xt[]>:
            ::std::bool_constant<is_char_type<char_xt>::value> {};
    
    ic_info("traits bool")
        icpp_t1(str_xt)
        icpp_bv is_c_str_type_v = is_c_str_type<str_xt>::value;

    ic_info("concepts")
        icpp_t1(str_xt)
        concept c_str_type = is_c_str_type_v<str_xt>;

icpp_end_ns_x1;