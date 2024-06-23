
#pragma once

#include"./declarations.h"

ic_info("forward decs") icpp_ns_x1(icpp)
    icpp_t1(ch_xt) ic_inl size_t ic_call strLen(const ch_xt* cs) ic_noexc;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpaces(ch_xp bg, ch_xp ed) ic_noexc;
    icpp_t1(ch_xp) ic_inl ch_xp ic_call skipSpacesBackward(ch_xp bg, ch_xp ed) ic_noexc;
    icpp_t1(ch_xt) ic_inl ch_xt* ic_call strToLower(ch_xt* dst, const ch_xt* bg, const ch_xt* ed) ic_noexc;
    icpp_t1(ch_xt) ic_inl ch_xt* ic_call strToUpper(ch_xt* dst, const ch_xt* bg, const ch_xt* ed) ic_noexc;
icpp_end_ns_x1;

ic_info("definitions")
    icpp_t2(ch_xt, staticAlloc_xt) ic_inl const ch_xt* icppStringG<ch_xt, staticAlloc_xt>::c_str() ic_noexc {
        ic_if_return(!this->append((ch_xt)'\0'), nullptr);
        icPopP3((IC_P3*)this, sizeof(ch_xt));
        return (const ch_xt*)this->begin();
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator=(const ch_xt* cs) ic_noexc {
        this->create(cs, cs + ::icpp::strLen(cs), 1);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator=(const icppStrandG<ch_xt>& sd) ic_noexc {
        this->create(sd.left, sd.right, 1);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator=(const icppSSegG<ch_xt>& sg) ic_noexc {
        auto pos = sg.position;
        this->create(pos, pos + sg.distance);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator+=(const ch_xt* cs) ic_noexc {
        this->append(cs, cs + ::icpp::strLen(cs), 1);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator+=(const icppStrandG<ch_xt>& sd) ic_noexc {
        this->append(sd.left, sd.right, 1);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator+=(const icppSSegG<ch_xt>& sg) ic_noexc {
        auto pos = sg.position;
        this->append(pos, pos + sg.distance, 1);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl bool icppStringG<ch_xt, staticAlloc_xt>::operator==(const ch_xt* cs) ic_noexc {
        return this->toStrand() == icppStrandG<ch_xt>(cs);
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl bool icppStringG<ch_xt, staticAlloc_xt>::operator!=(const ch_xt* cs) ic_noexc {
        return this->toStrand() != icppStrandG<ch_xt>(cs);
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl bool icppStringG<ch_xt, staticAlloc_xt>::operator==(const icppStrandG<ch_xt>& sd) ic_noexc {
        return this->toStrand() == sd;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl bool icppStringG<ch_xt, staticAlloc_xt>::operator!=(const icppStrandG<ch_xt>& sd) ic_noexc {
        return this->toStrand() != sd;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl bool icppStringG<ch_xt, staticAlloc_xt>::operator==(const icppSSegG<ch_xt>& seg) ic_noexc {
        return this->toSSeg() == seg;
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl bool icppStringG<ch_xt, staticAlloc_xt>::operator!=(const icppSSegG<ch_xt>& seg) ic_noexc {
        return this->toSSeg() != seg;
    }

    icpp_t2(ch_xt, staticAlloc_xt) icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator=(icppP3ArrayG<ch_xt, staticAlloc_xt>&& rr) ic_noexc {
        icTakeP3((IC_P3*)this, (IC_P3*)&rr, this->allocator.dealloc);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) icpp_t1(staticAlloc2_xt) icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator=(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc {
        this->create(s.begin(), s.end(), 1);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) icpp_t1(staticAlloc2_xt) icppStringG<ch_xt, staticAlloc_xt>& icppStringG<ch_xt, staticAlloc_xt>::operator+=(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc {
        this->append(s.begin(), s.end(), 1);
        return *this;
    }

    icpp_t2(ch_xt, staticAlloc_xt) icpp_t1(staticAlloc2_xt) bool icppStringG<ch_xt, staticAlloc_xt>::operator==(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc {
        return *this == s.toItv();
    }

    icpp_t2(ch_xt, staticAlloc_xt) icpp_t1(staticAlloc2_xt) bool icppStringG<ch_xt, staticAlloc_xt>::operator!=(const icppP3ArrayG<ch_xt, staticAlloc2_xt>& s) ic_noexc {
        return *this != s.toItv();
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStrandG<ch_xt> icppStringG<ch_xt, staticAlloc_xt>::toStrand() const ic_noexc {
        return icppStrandG<ch_xt>(this->begin(), this->end());
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppSSegG<ch_xt> icppStringG<ch_xt, staticAlloc_xt>::toSSeg() const ic_noexc {
        return icppSSegG<ch_xt>(this->begin(), this->size());
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl void icppStringG<ch_xt, staticAlloc_xt>::toLower() ic_noexc {
        auto bg = this->begin();
        ::icpp::strToLower(bg, bg, this->end());
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl void icppStringG<ch_xt, staticAlloc_xt>::toUpper() ic_noexc {
        auto bg = this->begin();
        ::icpp::strToUpper(bg, bg, this->end());
    }

    icpp_t2(ch_xt, staticAlloc_xt) icpp_t1(SA2_xt)
    ic_inl icppStringG<ch_xt, SA2_xt> icppStringG<ch_xt, staticAlloc_xt>::slice(size_t bg, size_t ed) const ic_noexc {
        auto thisBg = this->begin();
        return icppStringG<ch_xt, SA2_xt>(thisBg + bg, thisBg + ed, 0);
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl void icppStringG<ch_xt, staticAlloc_xt>::strip(bool stripLeft, bool stripRight) ic_noexc {
        ic_stv_x3(auto, pp = this->ptr, p0 = pp[0], p1 = pp[1]);
        ic_if_do_x2(stripRight, p1 = ::icpp::skipSpacesBackward(p0, p1), pp[1] = p1);
        ic_if_do_x2(stripLeft, auto pos = ::icpp::skipSpaces(p0, p1), this->erase(p0, pos));
    }

    icpp_t2(ch_xt, staticAlloc_xt) ic_inl icppStringG<ch_xt, staticAlloc_xt>::icppStringG(const ch_xt* cs) ic_noexc {
        this->create(cs, cs + ::icpp::strLen(cs), 1);
    }

    icpp_t3(ch_xt, SA1_xt, SA2_xt) ic_inl bool ic_call operator==(const icppStringG<ch_xt, SA1_xt>& s1, const icppStringG<ch_xt, SA2_xt>& s2) ic_noexc {
        return s1.toStrand() == s2.toStrand();
    }

    icpp_t3(ch_xt, SA1_xt, SA2_xt) ic_inl bool ic_call operator!=(const icppStringG<ch_xt, SA1_xt>& s1, const icppStringG<ch_xt, SA2_xt>& s2) ic_noexc {
        return s1.toStrand() != s2.toStrand();
    }

    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call H_icppJoinToString(const ch_xt* bg1, const ch_xt* ed1, const ch_xt* bg2, const ch_xt* ed2) ic_noexc {
        icppStringG<ch_xt, SA_xt> rs(bg1, ed1, ed2 - bg2 + 1);
        rs.append(bg2, ed2, 1);
        return rs;
    }

    icpp_t3(ch_xt, SA1_xt, SA2_xt) ic_inl icppStringG<ch_xt, SA1_xt> ic_call operator+(const icppStringG<ch_xt, SA1_xt>& s1, const icppStringG<ch_xt, SA2_xt>& s2) ic_noexc {
        return H_icppJoinToString<ch_xt, SA1_xt>(s1.begin(). s1.end(), s2.begin(), s2.end());
    }

    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStringG<ch_xt, SA_xt>& s1, const icppStrandG<ch_xt>& sd) ic_noexc {
        return H_icppJoinToString<ch_xt, SA_xt>(s1.begin(). s1.end(), sd.begin(), sd.end());
    }

    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStrandG<ch_xt>& sd, const icppStringG<ch_xt, SA_xt>& s1) ic_noexc {
        return H_icppJoinToString<ch_xt, SA_xt>(sd.begin(). sd.end(), s1.begin(), s1.end());
    }

    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStringG<ch_xt, SA_xt>& s1, const icppSSegG<ch_xt>& sg) ic_noexc {
        return H_icppJoinToString<ch_xt, SA_xt>(s1.begin(). s1.end(), sg.begin(), sg.end());
    }

    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppSSegG<ch_xt>& sg, const icppStringG<ch_xt, SA_xt>& s1) ic_noexc {
        return H_icppJoinToString<ch_xt, SA_xt>(sg.begin(). sg.end(), s1.begin(), s1.end());
    }

    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const icppStringG<ch_xt, SA_xt>& s1, const ch_xt* cs) ic_noexc {
        return H_icppJoinToString<ch_xt, SA_xt>(s1.begin(). s1.end(), cs, cs + strLen(cs));
    }

    icpp_t2(ch_xt, SA_xt) ic_inl icppStringG<ch_xt, SA_xt> ic_call operator+(const ch_xt* cs, const icppStringG<ch_xt, SA_xt>& s1) ic_noexc {
        return H_icppJoinToString<ch_xt, SA_xt>(cs, cs + strLen(cs), s1.begin(). s1.end());
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppSSegG<ch_xt>& sg1, const icppSSegG<ch_xt>& sg2) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(sg1.begin(), sg1.end(), sg2.begin(), sg2.end());
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppStrandG<ch_xt>& sd1, const icppStrandG<ch_xt>& sd2) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(sd1.begin(), sd1.end(), sd2.begin(), sd2.end());
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppSSegG<ch_xt>& sg, const icppStrandG<ch_xt>& sd) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(sg.begin(), sg.end(), sd.begin(), sd.end());
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppStrandG<ch_xt>& sd, const icppSSegG<ch_xt>& sg) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(sd.begin(), sd.end(), sg.begin(), sg.end());
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppSSegG<ch_xt>& sg, const ch_xt* cs) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(sg.begin(), sg.end(), cs, cs + ::icpp::strLen(cs));
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const ch_xt* cs, const icppSSegG<ch_xt>& sg) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(cs, cs + ::icpp::strLen(cs), sg.begin(), sg.end());
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const icppStrandG<ch_xt>& sd, const ch_xt* cs) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(sd.begin(), sd.end(), cs, cs + ::icpp::strLen(cs));
    }

    icpp_t1(ch_xt) ic_inl icppStringG<ch_xt, icppStaticAllocator> ic_call operator+(const ch_xt* cs, const icppStrandG<ch_xt>& sd) ic_noexc {
        return H_icppJoinToString<ch_xt, icppStaticAllocator>(cs, cs + ::icpp::strLen(cs), sd.begin(), sd.end());
    }
