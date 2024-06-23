
#pragma once

#include"./icppIsAnyOfTypes.h"
#include"./icppIsCharType.h"

ic_info("forward decs")
    icpp_t1(char_xt) class icppStrandG;
    icpp_t1(char_xt) class icppSSegG;

icpp_ns_x1(icpp)
    ic_info("traits type")
        icpp_t1(str_xt) struct is_string_type:
            ::std::bool_constant<is_any_of_types_v<::std::remove_cvref_t<str_xt>,
                char*, wchar_t*, char8_t*, char16_t*, char32_t*,
                const char*, const wchar_t*, const char8_t*, const char16_t*, const char32_t*>> {};

        icpp_t1v1(char_xt, size_t CharSize) struct is_string_type<char_xt[CharSize]>:
            ::std::bool_constant<is_char_type<char_xt>::value> {};
        
        icpp_t1(char_xt) struct is_string_type<char_xt[]>:
            ::std::bool_constant<is_char_type<char_xt>::value> {};

        ic_info("cpp")
            icpp_t3(char_xt, char_traits_xt, alloc_xt)
            struct is_string_type<::std::basic_string<char_xt, char_traits_xt, alloc_xt>>:
                ::std::true_type {};

        ic_info("icpp")
            icpp_t1(ch_xt) struct is_string_type<icppStrandG<ch_xt>>:
                ::std::true_type {};
            icpp_t1(ch_xt) struct is_string_type<icppSSegG<ch_xt>>:
                ::std::true_type {};
            /*
                尚未编写完适配icpp字符串对象的代码。
            */
    
    ic_info("traits bool")
        icpp_t1(str_xt)
        icpp_bv is_string_type_v = is_string_type<str_xt>::value;

    ic_info("concepts")
        icpp_t1(str_xt)
        concept string_type = is_string_type_v<str_xt>;

icpp_end_ns_x1;