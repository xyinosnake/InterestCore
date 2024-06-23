
#pragma once

#include"../declarations.h"
#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"
#include"../../../Common/Structs/icppCommonStructs.h"
#include"../../../Common/Traits/icppCommonTraits.h"
#include"../../../Memory/Objs/Seg/icppSeg.h"

ic_info("declarations")
    icpp_t1(char_xt) class icppSSegG: public icppSegG<char_xt> {
        static_assert(icpp::is_char_type_v<char_xt>, "char_xt must be char type.");
    public:
        icpp_alias(base_t, icppSegG<char_xt>);
        ic_inl const base_t& base() const ic_noexc { return *this; }
        ic_inl       base_t& base()       ic_noexc { return *this; }
        icpp_using_x1(base_t::, set);
        ic_inl void set(const char_xt*) ic_noexc;
        ic_inl icppSSegG<char_xt>& operator=(const icppSSegG<char_xt>&) ic_noexc;
        ic_inl icppSSegG<char_xt>& operator=(const char_xt*) ic_noexc;
        ic_inl bool operator==(const icppSSegG<char_xt>&) ic_noexc;
        ic_inl bool operator!=(const icppSSegG<char_xt>&) ic_noexc;
        ic_inl bool operator==(const char_xt*) ic_noexc;
        ic_inl bool operator!=(const char_xt*) ic_noexc;
        ic_inl operator icppStrandG<char_xt>() const ic_noexc;
        ic_inl icppStrandG<char_xt> toStrand() const ic_noexc;
        icpp_using_x1(base_t::, base_t);
        ic_inl icppSSegG(const char_xt*) ic_noexc;
    };

