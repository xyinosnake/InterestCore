
#pragma once

#include"../Macros/icppCommonMacros.h"
#include"../icppCommonHeaders.h"

icpp_ns_x1(icpp)
    ic_info("concept")
        icpp_t1c(static_allocator_type, alloc_xt)(alloc_xt a) {
            alloc_xt::allocate((::size_t)1);
            alloc_xt::deallocate(nullptr);
        };

        icpp_t1c(static_allocator_type_2, alloc_xt)(alloc_xt a) {
            alloc_xt::allocate((::size_t)1);
            alloc_xt::deallocate(nullptr);
            alloc_xt::reallocate(nullptr, (::size_t)1);
        };

    ic_info("traits type")
        icpp_t1(type_xt) struct is_static_allocator_type:
            ::std::false_type{};
        
        icpp_c1(static_allocator_type type_xt) struct is_static_allocator_type<type_xt>:
            ::std::true_type{};
        
        icpp_t1(type_xt) struct is_static_allocator_type_2:
            ::std::false_type{};
        
        icpp_c1(static_allocator_type_2 type_xt) struct is_static_allocator_type_2<type_xt>:
            ::std::true_type{};
    
    ic_info("traits bool")
        icpp_t1(type_xt)
        icpp_bv is_static_allocator_type_v = is_static_allocator_type<type_xt>::value;

        icpp_t1(type_xt)
        icpp_bv is_static_allocator_type_2_v = is_static_allocator_type_2<type_xt>::value;

icpp_end_ns_x1