
#pragma once

#include"../declarations.h"
#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"
#include"../../../Common/Structs/icppCommonStructs.h"
#include"../../../Common/Traits/icppCommonTraits.h"

ic_info("declarations")
    icpp_t1(elem_xt) class icppSegG: public ICPP_SEG_G<elem_xt> {
    public:
        using elem_t = ::std::conditional_t<::std::is_void_v<elem_xt>, uint8_t, elem_xt>;
        using base_t = ICPP_SEG_G<elem_xt>;
        ic_inl const base_t& structBase() const ic_noexc { return *this; }
        ic_inl       base_t& structBase()       ic_noexc { return *this; }
        ic_inl const base_t& base() const ic_noexc { return this->structBase(); }
        ic_inl       base_t& base()       ic_noexc { return this->structBase(); }
        ic_inl       elem_xt* begin() ic_noexc;
        ic_inl       elem_xt* end()   ic_noexc;
        ic_inl const elem_xt* begin() const ic_noexc;
        ic_inl const elem_xt* end()   const ic_noexc;
        ic_inl bool empty() const ic_noexc;
        ic_inl bool isNull() const ic_noexc;
        ic_inl size_t sizeOfBytes() const ic_noexc;
        ic_inl size_t size() const ic_noexc;
        ic_inl icppSegG<elem_xt> slice(size_t bg, size_t ed) ic_noexc;
        ic_inl void set(const elem_xt*, size_t) ic_noexc;
        ic_inl elem_t& operator[](size_t) ic_noexc;
        ic_inl elem_t  operator[](size_t) const ic_noexc;
        ic_inl icppSegG<elem_xt>& operator=(const icppSegG<elem_xt>&) ic_noexc;
        ic_inl bool operator==(const icppSegG<elem_xt>&) ic_noexc;
        ic_inl bool operator!=(const icppSegG<elem_xt>&) ic_noexc;
        ic_inl operator icppItvG<elem_xt>() const ic_noexc;
        ic_inl icppItvG<elem_xt> toItv() const ic_noexc;
        ic_inl icppSegG() ic_noexc;
        ic_inl icppSegG(const icppSegG<elem_xt>&) ic_noexc;
        ic_inl icppSegG(const elem_xt*, size_t sz) ic_noexc;
    };