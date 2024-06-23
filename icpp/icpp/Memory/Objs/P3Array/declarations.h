
#pragma once

#include"../declarations.h"
#include"../../../Common/Macros/icppCommonMacros.h"
#include"../../../Common/Types/icppCommonTypes.h"
#include"../../../Common/Structs/icppCommonStructs.h"
#include"../../../Common/Traits/icppCommonTraits.h"

ic_info("declarations")
    icpp_t2(elem_xt, staticAlloc_xt) class icppP3ArrayG: public ICPP_P3_G<elem_xt> {
        static_assert(::std::is_trivially_destructible_v<elem_xt>, "elem_xt must be trivially destructible");
        static const IC_ALLOC allocator;
    public:
        using base_t = ICPP_P3_G<elem_xt>;
        ic_inl const base_t& structBase() const ic_noexc { return *this; }
        ic_inl       base_t& structBase()       ic_noexc { return *this; }
        ic_inl const base_t& base() const ic_noexc { return this->structBase(); }
        ic_inl       base_t& base()       ic_noexc { return this->structBase(); }
        ic_inl elem_xt* begin() ic_noexc;
        ic_inl elem_xt* end() ic_noexc;
        ic_inl const elem_xt* begin() const ic_noexc;
        ic_inl const elem_xt* end() const ic_noexc;
        ic_inl size_t size() const ic_noexc;
        ic_inl size_t sizeOfBytes() const ic_noexc;
        ic_inl size_t capacity() const ic_noexc;
        ic_inl size_t capacityOfBytes() const ic_noexc;
        ic_inl size_t residue() const ic_noexc;
        ic_inl size_t residueOfBytes() const ic_noexc;
        ic_inl bool empty() const ic_noexc;
        ic_inl bool isNull() const ic_noexc;
        ic_inl elem_xt* reserve(size_t cap) ic_noexc;
        ic_inl elem_xt* resize(size_t sz, size_t minRes = 0, bool bMem0 = true) ic_noexc;
        ic_inl elem_xt* prepare(size_t sz, size_t minRes = 0) ic_noexc;
        ic_inl elem_xt* shrink() ic_noexc;
        ic_inl elem_xt* create(const elem_xt* bg, const elem_xt* ed, size_t minRes = 0) ic_noexc;
        ic_inl elem_xt* insert(elem_xt*, const elem_xt*, const elem_xt*) ic_noexc;
        ic_inl elem_xt* insert(elem_xt*, elem_xt) ic_noexc;
        ic_inl elem_xt* append(const elem_xt*, const elem_xt*, size_t minRes = 0) ic_noexc;
        ic_inl elem_xt* append(elem_xt) ic_noexc;
        ic_inl elem_xt  pop() ic_noexc;
        ic_inl void erase(elem_xt*, elem_xt*) ic_noexc;
        ic_inl void erase(elem_xt*) ic_noexc;
        ic_inl void clear() ic_noexc;
        ic_inl void destroy() ic_noexc;
        icpp_t1(SA2_xt)
            ic_inl icppP3ArrayG<elem_xt, SA2_xt> slice(size_t bg, size_t ed) const ic_noexc;
        ic_inl elem_xt& operator[](size_t) ic_noexc;
        ic_inl elem_xt  operator[](size_t) const ic_noexc;
        ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& operator=(const icppP3ArrayG<elem_xt, staticAlloc_xt>&)  ic_noexc;
        ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& operator=(      icppP3ArrayG<elem_xt, staticAlloc_xt>&&) ic_noexc;
        ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& operator=(const icppItvG<elem_xt>&) ic_noexc;
        ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& operator=(const icppSegG<elem_xt>&) ic_noexc;
        ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& operator+=(const icppItvG<elem_xt>&) ic_noexc;
        ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& operator+=(const icppSegG<elem_xt>&) ic_noexc;
        ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& operator+=(const icppP3ArrayG<elem_xt, staticAlloc_xt>&) ic_noexc;
        ic_inl icppSegG<elem_xt> toSeg() ic_noexc;
        ic_inl icppItvG<elem_xt> toItv() ic_noexc;
        ic_inl icppP3ArrayG() ic_noexc;
        ic_inl icppP3ArrayG(const icppIL<elem_xt>& il) ic_noexc;
        ic_inl icppP3ArrayG(icppP3ArrayG<elem_xt, staticAlloc_xt>&&) ic_noexc;
        ic_inl icppP3ArrayG(const elem_xt* bg, const elem_xt* ed, size_t minRes = 0) ic_noexc;
        ic_inl ~icppP3ArrayG() ic_noexc;
    };