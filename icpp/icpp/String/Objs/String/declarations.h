
#pragma once

#include"../declarations.h"
#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"
#include"../../../Common/Structs/icppCommonStructs.h"
#include"../../../Common/Traits/icppCommonTraits.h"
#include"../../../Memory/Objs/Itv/declarations.h"
#include"../../../Memory/Objs/P3Array/declarations.h"

ic_info("declarations")
    icpp_t2(ch_xt, staticAlloc_xt) class icppStringG: public icppP3ArrayG<ch_xt, staticAlloc_xt> {
    public:
        icpp_alias(base_t, icppP3ArrayG<ch_xt, staticAlloc_xt>);
        ic_inl const base_t& base() const ic_noexc { return *this; }
        ic_inl       base_t& base()       ic_noexc { return *this; }
        ic_inl const ch_xt* c_str() ic_noexc;
        icpp_using_x1(base_t::, base_t);
        ic_inl icppStringG<ch_xt, staticAlloc_xt>& operator=(const ch_xt* cs) ic_noexc;
        ic_inl icppStringG<ch_xt, staticAlloc_xt>& operator=(const icppStrandG<ch_xt>& sd) ic_noexc;
        ic_inl icppStringG<ch_xt, staticAlloc_xt>& operator=(const icppSSegG<ch_xt>& sg) ic_noexc;
        ic_inl icppStringG<ch_xt, staticAlloc_xt>& operator+=(const ch_xt* cs) ic_noexc;
        ic_inl icppStringG<ch_xt, staticAlloc_xt>& operator+=(const icppStrandG<ch_xt>& sd) ic_noexc;
        ic_inl icppStringG<ch_xt, staticAlloc_xt>& operator+=(const icppSSegG<ch_xt>& sg) ic_noexc;
        ic_inl bool operator==(const ch_xt* cs) ic_noexc;
        ic_inl bool operator!=(const ch_xt* cs) ic_noexc;
        ic_inl bool operator==(const icppStrandG<ch_xt>& sd) ic_noexc;
        ic_inl bool operator!=(const icppStrandG<ch_xt>& sd) ic_noexc;
        ic_inl bool operator==(const icppSSegG<ch_xt>& sd) ic_noexc;
        ic_inl bool operator!=(const icppSSegG<ch_xt>& sd) ic_noexc;
        icppStringG<ch_xt, staticAlloc_xt>& operator=(icppP3ArrayG<ch_xt, staticAlloc_xt>&& rr) ic_noexc;
        icpp_t1(staticAlloc2_xt) icppStringG<ch_xt, staticAlloc_xt>& operator =(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc;
        icpp_t1(staticAlloc2_xt) icppStringG<ch_xt, staticAlloc_xt>& operator+=(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc;
        icpp_t1(staticAlloc2_xt) bool operator==(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc;
        icpp_t1(staticAlloc2_xt) bool operator!=(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc;
        ic_inl icppStrandG<ch_xt> toStrand() const ic_noexc;
        ic_inl icppSSegG<ch_xt>   toSSeg()   const ic_noexc;
        ic_inl void toLower() ic_noexc;
        ic_inl void toUpper() ic_noexc;
        icpp_t1(SA2_xt)
            ic_inl icppStringG<ch_xt, SA2_xt> slice(size_t bg, size_t ed) const ic_noexc;
        ic_inl void strip(bool stripLeft = true, bool stripRight = true) ic_noexc;
        ic_inl icppStringG(const ch_xt* cs) ic_noexc;
    };
    icpp_t3(ch_xt, SA1_xt, SA2_xt) ic_inl bool ic_call operator==(const icppStringG<ch_xt, SA1_xt>& s1, const icppStringG<ch_xt, SA2_xt>& s2) ic_noexc;
    icpp_t3(ch_xt, SA1_xt, SA2_xt) ic_inl bool ic_call operator!=(const icppStringG<ch_xt, SA1_xt>& s1, const icppStringG<ch_xt, SA2_xt>& s2) ic_noexc;
    icpp_t3(ch_xt, SA1_xt, SA2_xt) ic_inl icppStringG<ch_xt, SA1_xt> ic_call operator+(const icppStringG<ch_xt, SA1_xt>& s1, const icppStringG<ch_xt, SA2_xt>& s2) ic_noexc;
    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStringG<ch_xt, SA_xt>& s1, const icppStrandG<ch_xt>& sd) ic_noexc;
    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStrandG<ch_xt>& sd, const icppStringG<ch_xt, SA_xt>& s1) ic_noexc;
    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStringG<ch_xt, SA_xt>& s1, const icppSSegG<ch_xt>& sg) ic_noexc;
    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppSSegG<ch_xt>& sg, const icppStringG<ch_xt, SA_xt>& s1) ic_noexc;
    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStringG<ch_xt, SA_xt>& s1, const ch_xt* cs) ic_noexc;
    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const ch_xt* cs, const icppStringG<ch_xt, SA_xt>& s1) ic_noexc;

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppSSegG<ch_xt>&   sg1, const icppSSegG<ch_xt>&   sg2) ic_noexc;
    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppStrandG<ch_xt>& sd1, const icppStrandG<ch_xt>& sd2) ic_noexc;
    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppSSegG<ch_xt>&   sg, const icppStrandG<ch_xt>& sd) ic_noexc;
    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppStrandG<ch_xt>& sd, const icppSSegG<ch_xt>&   sg) ic_noexc;
    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppSSegG<ch_xt>& sg, const ch_xt* cs) ic_noexc;
    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const ch_xt* cs, const icppSSegG<ch_xt>& sg) ic_noexc;
    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppStrandG<ch_xt>& sd, const ch_xt* cs) ic_noexc;
    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const ch_xt* cs, const icppStrandG<ch_xt>& sd) ic_noexc;