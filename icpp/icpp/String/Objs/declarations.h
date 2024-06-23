
#pragma once

#include"../../Common/icppCommon.h"
#include"../../Memory/Objs/declarations.h"

ic_info("declarations")
                   class icppUCStr;
    icpp_t1(ch_xt) class icppStrandG;
        icpp_alias(icppStrand8,  icppStrandG<ch8_t>);
        icpp_alias(icppStrand16, icppStrandG<ch16_t>);
        icpp_alias(icppStrand32, icppStrandG<ch32_t>);
        icpp_alias(icppStrandN,  icppStrandG<nch_t>);
        icpp_alias(icppStrandW,  icppStrandG<wch_t>);
        icpp_alias(icppStrand,   icppStrandN);
    icpp_t1(ch_xt) class icppSSegG;
        icpp_alias(icppSSeg8,  icppSSegG<ch8_t>);
        icpp_alias(icppSSeg16, icppSSegG<ch16_t>);
        icpp_alias(icppSSeg32, icppSSegG<ch32_t>);
        icpp_alias(icppSSegN,  icppSSegG<nch_t>);
        icpp_alias(icppSSegW,  icppSSegG<wch_t>);
        icpp_alias(icppSSeg,   icppSSegN);
    icpp_t2(ch_xt, staticAlloc_xt = icppStaticAllocator)
        class icppStringG;
        icpp_alias(icppStr8,  icppStringG<ch8_t,  icppStaticAllocator>);
        icpp_alias(icppStr16, icppStringG<ch16_t, icppStaticAllocator>);
        icpp_alias(icppStr32, icppStringG<ch32_t, icppStaticAllocator>);
        icpp_alias(icppStrN,  icppStringG<nch_t,  icppStaticAllocator>);
        icpp_alias(icppStrW,  icppStringG<wch_t,  icppStaticAllocator>);

ic_info("in ns alias") icpp_ns_x1(icpp)
                   icpp_alias(UCStr, icppUCStr);
    icpp_t1(ch_xt) icpp_alias(StrandG, icppStrandG<ch_xt>);
        icpp_alias(Strand8,  icppStrand8);
        icpp_alias(Strand16, icppStrand16);
        icpp_alias(Strand32, icppStrand32);
        icpp_alias(StrandN,  icppStrandN);
        icpp_alias(StrandW,  icppStrandW);
        icpp_alias(Strand,   icppStrand);
    icpp_t1(ch_xt) icpp_alias(icppSSegG, icppSSegG<ch_xt>);
        icpp_alias(SSeg8,  icppSSeg8);
        icpp_alias(SSeg16, icppSSeg16);
        icpp_alias(SSeg32, icppSSeg32);
        icpp_alias(SSegN,  icppSSegN);
        icpp_alias(SSegW,  icppSSegW);
        icpp_alias(SSeg,   icppSSeg);
    icpp_t2(ch_xt, staticAlloc_xt = icppStaticAllocator)
        icpp_alias(StringG, icppStringG<ch_xt, staticAlloc_xt>);
        icpp_alias(Str8,  icppStr8);
        icpp_alias(Str16, icppStr16);
        icpp_alias(Str32, icppStr32);
        icpp_alias(StrN,  icppStrN);
        icpp_alias(StrW,  icppStrW);
icpp_end_ns_x1