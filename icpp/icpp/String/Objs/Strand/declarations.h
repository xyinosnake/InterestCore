
#pragma once

#include"../declarations.h"
#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"
#include"../../../Common/Structs/icppCommonStructs.h"
#include"../../../Common/Traits/icppCommonTraits.h"
#include"../../../Memory/Objs/Itv/icppItv.h"

ic_info("declarations")
    icpp_t1(ch_xt) class icppStrandG: public icppItvG<ch_xt> {
        static_assert(icpp::is_char_type_v<ch_xt>, "ch_xt must be char type.");
    public:
        icpp_alias(base_t, icppItvG<ch_xt>);
        ic_inl const base_t& base() const ic_noexc { return *this; }
        ic_inl       base_t& base()       ic_noexc { return *this; }
        icpp_using_x1(base_t::, set);
        ic_inl void set(const ch_xt*) ic_noexc;
        ic_inl icppStrandG<ch_xt>& operator=(const icppStrandG<ch_xt>&) ic_noexc;
        ic_inl icppStrandG<ch_xt>& operator=(const ch_xt*) ic_noexc;
        ic_inl bool operator==(const icppStrandG<ch_xt>&) ic_noexc;
        ic_inl bool operator!=(const icppStrandG<ch_xt>&) ic_noexc;
        ic_inl bool operator==(const ch_xt*) ic_noexc;
        ic_inl bool operator!=(const ch_xt*) ic_noexc;
        ic_inl operator icppSSegG<ch_xt>() const ic_noexc;
        ic_inl icppSSegG<ch_xt> toSSeg() const ic_noexc;
        ic_inl void strip(bool stripLeft = true, bool stripRight = true) ic_noexc;
        icpp_using_x1(base_t::, base_t);
        ic_inl icppStrandG(const ch_xt*) ic_noexc;
    };