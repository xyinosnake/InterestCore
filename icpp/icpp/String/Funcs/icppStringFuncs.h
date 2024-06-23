
#pragma once

#include"../../Common/icppCommon.h"

ic_info("declarations") icpp_ns_x1(icpp)
    icpp_t1(ch_xt) ic_inl ch_xt ic_call toLower(ch_xt c) ic_noexc;
    icpp_t1(ch_xt) ic_inl ch_xt ic_call toUpper(ch_xt c) ic_noexc;
    icpp_t1(ch_xt) ic_inl bool ic_call isLower(ch_xt c) ic_noexc;
    icpp_t1(ch_xt) ic_inl bool ic_call isUpper(ch_xt c) ic_noexc;
    icpp_t1(ch_xt) ic_inl ch_xt* ic_call strToLower(ch_xt* dst, const ch_xt* bg, const ch_xt* ed) ic_noexc;
    icpp_t1(ch_xt) ic_inl ch_xt* ic_call strToUpper(ch_xt* dst, const ch_xt* bg, const ch_xt* ed) ic_noexc;
    icpp_t1(ch_xt) ic_inl size_t ic_call strLen(const ch_xt* cs) ic_noexc;
    icpp_t1(ch_xp) ic_inl ch_xp  ic_call strEnd(ch_xp cs) ic_noexc;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpaces(ch_xp bg, ch_xp ed) ic_noexcept;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpacesBackward(ch_xp bg, ch_xp ed) ic_noexcept;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipGraphs(ch_xp bg, ch_xp ed) ic_noexcept;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipGraphsBackward(ch_xp bg, ch_xp ed) ic_noexcept;
icpp_end_ns_x1

#include"./P_icppStringFuncsInl.h"