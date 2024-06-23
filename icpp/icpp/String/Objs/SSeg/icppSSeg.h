
#pragma once

#include"./declarations.h"

ic_info("forward decs") icpp_ns_x1(icpp)
    icpp_t1(ch_xt) ic_inl size_t ic_call strLen(const ch_xt* cs) ic_noexc;
icpp_end_ns_x1

ic_info("definitions")
    icpp_t1(ch_xt) ic_inl void icppSSegG<ch_xt>::set(const ch_xt* cs) ic_noexc {
        return this->set(cs, ::icpp::strLen(cs));
    }

    icpp_t1(ch_xt) ic_inl icppSSegG<ch_xt>& icppSSegG<ch_xt>::operator=(const icppSSegG<ch_xt>& seg) ic_noexc {
        this->position = seg.position;
        this->distance = seg.distance;
        return *this;
    }

    icpp_t1(ch_xt) ic_inl icppSSegG<ch_xt>& icppSSegG<ch_xt>::operator=(const ch_xt* cs) ic_noexc {
        this->set(cs);
        return *this;
    }

    icpp_t1(ch_xt) ic_inl bool icppSSegG<ch_xt>::operator==(const icppSSegG<ch_xt>& seg) ic_noexc {
        return this->base() == seg.base();
    }

    icpp_t1(ch_xt) ic_inl bool icppSSegG<ch_xt>::operator!=(const icppSSegG<ch_xt>& seg) ic_noexc {
        return this->base() != seg.base();
    }

    icpp_t1(ch_xt) ic_inl bool icppSSegG<ch_xt>::operator==(const ch_xt* cs) ic_noexc {
        return *this == icppSSegG<ch_xt>(cs);
    }

    icpp_t1(ch_xt) ic_inl bool icppSSegG<ch_xt>::operator!=(const ch_xt* cs) ic_noexc {
        return *this != icppSSegG<ch_xt>(cs);
    }

    icpp_t1(ch_xt) ic_inl icppSSegG<ch_xt>::operator icppStrandG<ch_xt>() const ic_noexc {
        return icppStrandG<ch_xt>(this->begin(), this->end());
    }

    icpp_t1(ch_xt) ic_inl icppStrandG<ch_xt> icppSSegG<ch_xt>::toStrand() const ic_noexc {
        return (icppStrandG<ch_xt>)*this;
    }

    icpp_t1(ch_xt) ic_inl icppSSegG<ch_xt>::icppSSegG(const ch_xt* cs) ic_noexc {
        this->set(cs);
    }