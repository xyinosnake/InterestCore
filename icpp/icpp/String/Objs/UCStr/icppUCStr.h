
#pragma once

#include"./declarations.h"

ic_info("forward") icpp_ns_x1(icpp)
    icpp_t1(ch_xt) ic_inl size_t ic_call strLen(const ch_xt* cs) ic_noexc;
icpp_end_ns_x1

ic_info("definitions")
    icpp_t1(ch_xt) ic_inl const ch_xt* ic_call icppUCStr::cast() const ic_noexc {
        return (const ch_xt*)(*this);
    }

    icpp_t1(ch_xt) ic_inl const ch_xt* ic_call icppUCStr::begin() const ic_noexc {
        return this->cast<ch_xt>();
    }

    icpp_t1(ch_xt) ic_inl const ch_xt* ic_call icppUCStr::end() const ic_noexc {
        return this->begin<ch_xt>() + this->size<ch_xt>();
    }

    icpp_t1(ch_xt) ic_inl size_t ic_call icppUCStr::size() const ic_noexc {
        icpp_using_x1(::std::, is_same_v);
        icpp_static_if(is_same_v<ch_xt, nch_t>) { return this->csUtf8.distance  / sizeof(ch_xt); } else
    #ifdef IC_OS_WINDOWS
        icpp_static_if(is_same_v<ch_xt, wch_t>) { return this->csUtf16.distance / sizeof(ch_xt); } else
    #else
        icpp_static_if(is_same_v<ch_xt, wch_t>) { return this->csUtf32.distance / sizeof(ch_xt); } else
    #endif
        icpp_static_if(is_same_v<ch_xt, utf8_t >) { return this->csUtf8.distance  / sizeof(ch_xt); } else
        icpp_static_if(is_same_v<ch_xt, utf16_t>) { return this->csUtf16.distance / sizeof(ch_xt); } else
        icpp_static_if(is_same_v<ch_xt, utf32_t>) { return this->csUtf32.distance / sizeof(ch_xt); }
        ic_else_return(0);
    }

    icpp_t1(ch_xt) ic_inl const icppSSegG<ch_xt>& ic_call icppUCStr::toSSeg() const ic_noexc {
        icpp_using_x1(::std::, is_same_v);
        icpp_static_if(is_same_v<ch_xt, nch_t>) { return reinterpret_cast<const icppSSegG<nch_t>&>(this->csUtf8); } else
    #ifdef IC_OS_WINDOWS
        icpp_static_if(is_same_v<ch_xt, wch_t>) { return reinterpret_cast<const icppSSegG<wch_t>&>(this->csUtf16); } else
    #else
        icpp_static_if(is_same_v<ch_xt, wch_t>) { return reinterpret_cast<const icppSSegG<ch32_t>&>(this->csUtf32); } else
    #endif
        icpp_static_if(is_same_v<ch_xt, utf8_t >) { return this->csUtf8;  } else
        icpp_static_if(is_same_v<ch_xt, utf16_t>) { return this->csUtf16; } else
        icpp_static_if(is_same_v<ch_xt, utf32_t>) { return this->csUtf32; }
        ic_else_return(icpp_nullref);
    }

    ic_inl ic_call icppUCStr::operator const nch_t*() const ic_noexc { return (const nch_t*)(this->csUtf8.position); }
#ifdef IC_OS_WINDOWS
    ic_inl ic_call icppUCStr::operator const wch_t*() const ic_noexc { return (const wch_t*)(this->csUtf16.position); }
#else
    ic_inl ic_call icppUCStr::operator const wch_t*() const ic_noexc { return (const wch_t*)(this->csUtf32.position); }
#endif
    ic_inl ic_call icppUCStr::operator const utf8_t* () const ic_noexc { return (const utf8_t* )(this->csUtf8.position);  }
    ic_inl ic_call icppUCStr::operator const utf16_t*() const ic_noexc { return (const utf16_t*)(this->csUtf16.position); }
    ic_inl ic_call icppUCStr::operator const utf32_t*() const ic_noexc { return (const utf32_t*)(this->csUtf32.position); }

    ic_inl void ic_call icppUCStr::create(
        const icppSSegG<utf8_t>&  sUtf8,
        const icppSSegG<utf16_t>& sUtf16, 
        const icppSSegG<utf32_t>& sUtf32) ic_noexc {
        this->csUtf8  = sUtf8;
        this->csUtf16 = sUtf16;
        this->csUtf32 = sUtf32;
    }

ic_info("constructors")
    ic_inl ic_call icppUCStr::icppUCStr() ic_noexc {}
    ic_inl ic_call icppUCStr::icppUCStr(const icppUCStr& ucs) ic_noexc {
        *this = ucs;
    }

    ic_inl ic_call icppUCStr::icppUCStr(
        const icppSSegG<utf8_t>&  sUtf8,
        const icppSSegG<utf16_t>& sUtf16, 
        const icppSSegG<utf32_t>& sUtf32) ic_noexc:
        csUtf8(sUtf8),
        csUtf16(sUtf16),
        csUtf32(sUtf32) {}