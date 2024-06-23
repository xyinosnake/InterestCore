
#pragma once

#include"../icppCommonHeaders.h"
#include"../Macros/icppCommonMacros.h"
#include"../../../../ic/ic/Common/Types/icCommonTypes.h"

ic_info("using")
    icpp_t1(elem_xt)    icpp_alias(icppStdAllocatorG, ::std::allocator<elem_xt>);
    icpp_t2(a_xt, b_xt) icpp_alias(icppStdPairG,      ::std::pair<a_xt, b_xt>);
    icpp_t2(elem_xt, std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(icppStdVecG, ::std::vector<elem_xt, std_alloc_xt>);

    icpp_t3(key_xt, pr_xt = ::std::less<key_xt>, std_alloc_xt = icppStdAllocatorG<key_xt>)
        icpp_alias(icppStdSetG, ::std::set<key_xt, pr_xt, std_alloc_xt>);

    icpp_t4(key_xt, value_xt, pr_xt = ::std::less<key_xt>, 
            std_alloc_xt = ic_sg(icppStdAllocatorG<icppStdPairG<const key_xt, value_xt>>))
        icpp_alias(icppStdMapG, ::std::map<key_xt, value_xt, pr_xt, std_alloc_xt>);

    icpp_t2(elem_xt, std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(icppStdListG, ::std::list<elem_xt, std_alloc_xt>);

    icpp_t2(elem_xt, std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(icppStdDequeG, ::std::deque<elem_xt, std_alloc_xt>);

    icpp_t3(elem_xt, char_traits_xt = ::std::char_traits<elem_xt>,
            std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(icppStdStrG, ::std::basic_string<elem_xt, char_traits_xt, std_alloc_xt>);
        icpp_alias(icppStdStrN, ::std::string);
        icpp_alias(icppStdStrW, ::std::wstring);
        icpp_alias(icppStdStr,  icppStdStrN);

ic_info("using") icpp_ns_x2(icpp, std)
	icpp_t1(elem_xt)    icpp_alias(AllocatorG, icppStdAllocatorG<elem_xt>);
    icpp_t2(a_xt, b_xt) icpp_alias(PairG, icppStdPairG<a_xt, b_xt>);

    icpp_t2(elem_xt, std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(VecG, icppStdVecG<elem_xt, std_alloc_xt>);

    icpp_t3(key_xt, pr_xt = ::std::less<key_xt>, std_alloc_xt = icppStdAllocatorG<key_xt>)
        icpp_alias(SetG, icppStdSetG<key_xt, pr_xt, std_alloc_xt>);

    icpp_t4(key_xt, value_xt, pr_xt = ::std::less<key_xt>, 
            std_alloc_xt = ic_sg(icppStdAllocatorG<icppStdPairG<const key_xt, value_xt>>))
        icpp_alias(MapG, icppStdMapG<key_xt, value_xt, pr_xt, std_alloc_xt>);

    icpp_t2(elem_xt, std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(ListG, icppStdListG<elem_xt, std_alloc_xt>);

    icpp_t2(elem_xt, std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(DequeG, icppStdDequeG<elem_xt, std_alloc_xt>);

    icpp_t3(elem_xt, char_traits_xt = ::std::char_traits<elem_xt>,
            std_alloc_xt = icppStdAllocatorG<elem_xt>)
        icpp_alias(StrG, icppStdStrG<elem_xt, char_traits_xt, std_alloc_xt>);
        icpp_alias(StrN, icppStdStrN);
        icpp_alias(StrW, icppStdStrW);
        icpp_alias(Str, icppStdStr);
icpp_end_ns_x2