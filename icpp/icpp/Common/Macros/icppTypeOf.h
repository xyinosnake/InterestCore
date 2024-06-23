
#pragma once

#include<type_traits>
#include<iterator>
#include"./icppTN.h"

ic_info("H...")
    icpp_t1(T) using H_icppTypeOf = typename ::std::remove_cv<
        typename::std::remove_reference<T>::type>::type;

    icpp_t1(iter_xt) using H_icppTargetOf = typename ::std::remove_cv<
        typename::std::iterator_traits<iter_xt>::value_type>::type;

ic_info("macros")
    #define icpp_typeof(v)       H_icppTypeOf<decltype(v)>
    #define icpp_targetof(it_xt) H_icppTargetOf<it_xt>
