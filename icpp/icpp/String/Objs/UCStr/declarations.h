
#pragma once

#include"../declarations.h"
#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"
#include"../../../Common/Structs/icppCommonStructs.h"
#include"../../../Common/Traits/icppCommonTraits.h"

#include"../SSeg/icppSSeg.h"

ic_info("declarations")
    class icppUCStr {
        icppSSegG<utf8_t>  csUtf8;
        icppSSegG<utf16_t> csUtf16;
        icppSSegG<utf32_t> csUtf32;
    public:
        icpp_t1(ch_xt) ic_inl const ch_xt* ic_call cast() const ic_noexc;
        icpp_t1(ch_xt) ic_inl const ch_xt* ic_call begin() const ic_noexc;
        icpp_t1(ch_xt) ic_inl const ch_xt* ic_call end() const ic_noexc;
        icpp_t1(ch_xt) ic_inl size_t ic_call size() const ic_noexc;
        icpp_t1(ch_xt) ic_inl const icppSSegG<ch_xt>& ic_call toSSeg() const ic_noexc;
    ic_info("nch_t & wch_t")
        ic_inl ic_call operator const nch_t*() const ic_noexc;
        ic_inl ic_call operator const wch_t*() const ic_noexc;
    ic_info("utf_t")
        ic_inl ic_call operator const utf8_t* () const ic_noexc;
        ic_inl ic_call operator const utf16_t*() const ic_noexc;
        ic_inl ic_call operator const utf32_t*() const ic_noexc;
        ic_inl void ic_call create(
            const icppSSegG<utf8_t>&  sUtf8, 
            const icppSSegG<utf16_t>& sUtf16, 
            const icppSSegG<utf32_t>& sUtf32) ic_noexc;
    ic_info("constructors")
        ic_inl ic_call icppUCStr() ic_noexc;
        ic_inl ic_call icppUCStr(const icppUCStr& ucs) ic_noexc;
        ic_inl ic_call icppUCStr(
            const icppSSegG<utf8_t>&  sUtf8, 
            const icppSSegG<utf16_t>& sUtf16, 
            const icppSSegG<utf32_t>& sUtf32) ic_noexc;
    };