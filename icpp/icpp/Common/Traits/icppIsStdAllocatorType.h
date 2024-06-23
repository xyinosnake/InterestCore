
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"../icppCommonHeaders.h"

icpp_ns_x1(icpp)
    ic_info("concept")
        icpp_t1(alloc_t) concept std_allocator_type = requires(alloc_t a) {
            a.allocate((::std::size_t)1);
            a.deallocate(nullptr, (::std::size_t)1);
        };

    ic_info("traits type")
        icpp_t1(type_xt) struct is_std_allocator_type:
            ::std::false_type{};
    
    template<std_allocator_type type_xt>
    struct is_std_allocator_type<type_xt>:
        ::std::true_type{};
    
    ic_info("traits bool")
        icpp_t1(type_xt) icpp_bv is_std_allocator_type_v = is_std_allocator_type<type_xt>::value;

icpp_end_ns_x1