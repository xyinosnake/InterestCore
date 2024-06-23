
#pragma once

#include"./declarations.h"
#include"../../Funcs/icppMemoryFuncs.h"

icpp_t2(elem_xt, staticAlloc_xt)
const IC_ALLOC icppP3ArrayG<elem_xt, staticAlloc_xt>::allocator = { staticAlloc_xt::allocate, staticAlloc_xt::deallocate };

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::begin() ic_noexc {
    return (elem_xt*)icBeginP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::end() ic_noexc {
    return (elem_xt*)icEndP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl const elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::begin() const ic_noexc {
    return (const elem_xt*)icBeginP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl const elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::end() const ic_noexc {
    return (const elem_xt*)icEndP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl size_t icppP3ArrayG<elem_xt, staticAlloc_xt>::size() const ic_noexc {
    return icSizeOfP3((IC_P3*)this, sizeof(elem_xt));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl size_t icppP3ArrayG<elem_xt, staticAlloc_xt>::sizeOfBytes() const ic_noexc {
    return icSizeOfBytesP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl size_t icppP3ArrayG<elem_xt, staticAlloc_xt>::capacity() const ic_noexc {
    return icCapOfP3((IC_P3*)this, sizeof(elem_xt));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl size_t icppP3ArrayG<elem_xt, staticAlloc_xt>::capacityOfBytes() const ic_noexc {
    return icCapOfBytesP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl size_t icppP3ArrayG<elem_xt, staticAlloc_xt>::residue() const ic_noexc {
    return icResOfP3((IC_P3*)this, sizeof(elem_xt));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl size_t icppP3ArrayG<elem_xt, staticAlloc_xt>::residueOfBytes() const ic_noexc {
    return icResOfBytesP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl bool icppP3ArrayG<elem_xt, staticAlloc_xt>::empty() const ic_noexc {
    return icIsEmptyP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl bool icppP3ArrayG<elem_xt, staticAlloc_xt>::isNull() const ic_noexc {
    return icIsNullP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::reserve(size_t cap) ic_noexc {
    return (elem_xt*)icReserveP3((IC_P3*)this, sizeof(elem_xt) * cap, &(this->allocator));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::resize(size_t sz, size_t minRes, bool bMem0) ic_noexc {
    return (elem_xt*)icResizeP3((IC_P3*)this, sizeof(elem_xt) * sz, sizeof(elem_xt) * minRes, bMem0, &(this->allocator));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::prepare(size_t sz, size_t minRes) ic_noexc {
    return (elem_xt*)icCreateP3((IC_P3*)this, sizeof(elem_xt) * sz, sizeof(elem_xt) * minRes, &(this->allocator));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::shrink() ic_noexc {
    return (elem_xt*)icShrinkP3((IC_P3*)this, &(this->allocator));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::create(const elem_xt* bg, const elem_xt* ed, size_t minRes) ic_noexc {
    return (elem_xt*)icCreateP3FromMem((IC_P3*)this, bg, ed, sizeof(elem_xt) * minRes, &(this->allocator));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::insert(elem_xt* pos, const elem_xt* bg, const elem_xt* ed) ic_noexc {
    return (elem_xt*)icInsertMemToP3((IC_P3*)this, pos, bg, ed, &(this->allocator));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::insert(elem_xt* pos, elem_xt e) ic_noexc {
    auto ptr = (elem_xt*)icInsertPlaceToP3((IC_P3*)this, pos, sizeof(elem_xt), &(this->allocator));
    ic_if_return(!ptr, ptr);
    ic_do_and_return(*ptr = e, ++ptr);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::append(const elem_xt* bg, const elem_xt* ed, size_t minRes) ic_noexc {
    return (elem_xt*)icAppendMemToP3((IC_P3*)this, bg, ed, sizeof(elem_xt) * minRes, &(this->allocator));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt* icppP3ArrayG<elem_xt, staticAlloc_xt>::append(elem_xt e) ic_noexc {
    auto ptr = (elem_xt*)icAppendPlaceToP3((IC_P3*)this, sizeof(elem_xt), 0, &(this->allocator));
    ic_if_return(!ptr, ptr);
    ic_do_and_return(*ptr = e, ++ptr);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt icppP3ArrayG<elem_xt, staticAlloc_xt>::pop() ic_noexc {
    return *(elem_xt*)icPopP3((IC_P3*)this, sizeof(elem_xt));
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl void icppP3ArrayG<elem_xt, staticAlloc_xt>::erase(elem_xt* bg, elem_xt* ed) ic_noexc {
    icEraseP3((IC_P3*)this, bg, ed);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl void icppP3ArrayG<elem_xt, staticAlloc_xt>::erase(elem_xt* pos) ic_noexc {
    this->erase(pos, pos + 1);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl void icppP3ArrayG<elem_xt, staticAlloc_xt>::clear() ic_noexc {
    icClearP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl void icppP3ArrayG<elem_xt, staticAlloc_xt>::destroy() ic_noexc {
    icDestroyP3((IC_P3*)this, this->allocator.dealloc);
}

icpp_t2(elem_xt, staticAlloc_xt) template<typename SA2_xt> ic_inl icppP3ArrayG<elem_xt, SA2_xt> icppP3ArrayG<elem_xt, staticAlloc_xt>::slice(size_t bg, size_t ed) const ic_noexc {
    auto thisBg = this->begin();
    return icppP3ArrayG<elem_xt, SA2_xt>(thisBg + bg, thisBg + ed, 0);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator[](size_t pos) ic_noexc {
    return this->begin()[pos];
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl elem_xt icppP3ArrayG<elem_xt, staticAlloc_xt>::operator[](size_t pos) const ic_noexc {
    return this->begin()[pos];
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator=(const icppP3ArrayG<elem_xt, staticAlloc_xt>& r) ic_noexc {
    this->create(r.begin(), r.end(), 0);
    return *this;
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator=(icppP3ArrayG<elem_xt, staticAlloc_xt>&& rr) ic_noexc {
    icTakeP3((IC_P3*)this, (IC_P3*)&rr, this->allocator.dealloc);
    return *this;
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator=(const icppItvG<elem_xt>& itv) ic_noexc {
    this->create(itv.begin(), itv.end(), 0);
    return *this;
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator=(const icppSegG<elem_xt>& seg) ic_noexc {
    this->create(seg.begin(), seg.end(), 0);
    return *this;
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator+=(const icppItvG<elem_xt>& itv) ic_noexc {
    this->append(itv.begin(), itv.end());
    return *this;
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator+=(const icppSegG<elem_xt>& seg) ic_noexc {
    this->append(seg.begin(), seg.end());
    return *this;
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>& icppP3ArrayG<elem_xt, staticAlloc_xt>::operator+=(const icppP3ArrayG<elem_xt, staticAlloc_xt>& r) ic_noexc {
    this->append(r.begin(), r.end());
    return *this;
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppSegG<elem_xt> icppP3ArrayG<elem_xt, staticAlloc_xt>::toSeg() ic_noexc {
    return icppSegG<elem_xt>(this->begin(), this->size());
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppItvG<elem_xt> icppP3ArrayG<elem_xt, staticAlloc_xt>::toItv() ic_noexc {
    return icppItvG<elem_xt>(this->begin(), this->end());
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>::icppP3ArrayG() ic_noexc {
    icInitP3((IC_P3*)this);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>::icppP3ArrayG(const icppIL<elem_xt>& il) ic_noexc {
    icInitP3((IC_P3*)this);
    this->create(il.begin(), il.end(), 0);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>::icppP3ArrayG(icppP3ArrayG<elem_xt, staticAlloc_xt>&& rr) ic_noexc {
    icInitP3((IC_P3*)this);
    icTakeP3((IC_P3*)this, (IC_P3*)&rr, this->allocator.dealloc);
}

icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>::icppP3ArrayG(const elem_xt* bg, const elem_xt* ed, size_t minRes) ic_noexc {
    icInitP3((IC_P3*)this);
    this->create(bg, ed, minRes);
}
icpp_t2(elem_xt, staticAlloc_xt) ic_inl icppP3ArrayG<elem_xt, staticAlloc_xt>::~icppP3ArrayG() ic_noexc {
    this->destroy();
}
