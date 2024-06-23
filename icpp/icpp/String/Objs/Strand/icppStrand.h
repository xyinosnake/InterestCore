
#pragma once

#include"./declarations.h"

ic_info("forward decs") icpp_ns_x1(icpp)
    icpp_t1(ch_xt) ic_inl size_t ic_call strLen(const ch_xt* cs) ic_noexc;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpaces(ch_xp bg, ch_xp ed) ic_noexcept;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpacesBackward(ch_xp bg, ch_xp ed) ic_noexcept;
icpp_end_ns_x1

ic_info("definitions")
    icpp_t1(ch_xt) ic_inl void icppStrandG<ch_xt>::set(const ch_xt* cs) ic_noexc {
        return this->set(cs, cs + ::icpp::strLen(cs));
    }

    icpp_t1(ch_xt) ic_inl icppStrandG<ch_xt>& icppStrandG<ch_xt>::operator=(const icppStrandG<ch_xt>& sd) ic_noexc {
        this->set(sd.left, sd.right);
        return *this;
    }

    icpp_t1(ch_xt) ic_inl icppStrandG<ch_xt>& icppStrandG<ch_xt>::operator=(const ch_xt* cs) ic_noexc {
        this->set(cs);
        return *this;
    }

    icpp_t1(ch_xt) ic_inl bool icppStrandG<ch_xt>::operator==(const icppStrandG<ch_xt>& sd) ic_noexc {
        return this->base() == sd.base();
    }

    icpp_t1(ch_xt) ic_inl bool icppStrandG<ch_xt>::operator!=(const icppStrandG<ch_xt>& sd) ic_noexc {
        return this->base() != sd.base();
    }

    icpp_t1(ch_xt) ic_inl bool icppStrandG<ch_xt>::operator==(const ch_xt* cs) ic_noexc {
        return *this == icppStrandG<ch_xt>(cs);
    }

    icpp_t1(ch_xt) ic_inl bool icppStrandG<ch_xt>::operator!=(const ch_xt* cs) ic_noexc {
        return *this != icppStrandG<ch_xt>(cs);
    }

    icpp_t1(ch_xt) ic_inl icppStrandG<ch_xt>::operator icppSSegG<ch_xt>() const ic_noexc {
        return icppSSegG<ch_xt>(this->begin(), this->size());
    }

    icpp_t1(ch_xt) ic_inl icppSSegG<ch_xt> icppStrandG<ch_xt>::toSSeg() const ic_noexc {
        return (icppSSegG<ch_xt>)*this;
    }

    icpp_t1(ch_xt) ic_inl void icppStrandG<ch_xt>::strip(bool stripLeft, bool stripRight) ic_noexc {
        icppStrandG<ch_xt> sd = *this;
        ic_if_do(stripLeft,  sd.left  = ::icpp::skipSpaces(sd.left, sd.right));
        ic_if_do(stripRight, sd.right = ::icpp::skipSpacesBackward(sd.left, sd.right));
        *this = sd;
    }

    icpp_t1(ch_xt) ic_inl icppStrandG<ch_xt>::icppStrandG(const ch_xt* cs) ic_noexc {
        this->set(cs);
    }