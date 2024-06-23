
#pragma once

#include"./declarations.h"
#include"../Itv/declarations.h"
#include"../../Funcs/icppMemoryFuncs.h"

ic_info("definitions")
    icpp_t1(elem_xt) ic_inl elem_xt* icppSegG<elem_xt>::begin() ic_noexc {
        return this->position;
    }

    icpp_t1(elem_xt) ic_inl elem_xt* icppSegG<elem_xt>::end() ic_noexc {
        return ::icpp::addPtr(this->position, this->distance);
    }

    icpp_t1(elem_xt) ic_inl const elem_xt* icppSegG<elem_xt>::begin() const ic_noexc {
        return this->position;
    }

    icpp_t1(elem_xt) ic_inl const elem_xt* icppSegG<elem_xt>::end()   const ic_noexc {
        return ::icpp::addPtr(this->position, this->distance);
    }

    icpp_t1(elem_xt) ic_inl bool icppSegG<elem_xt>::empty() const ic_noexc {
        return this->distance == 0;
    }

    icpp_t1(elem_xt) ic_inl bool icppSegG<elem_xt>::isNull() const ic_noexc {
        return (this->position == nullptr) && (this->distance == 0);
    }

    icpp_t1(elem_xt) ic_inl size_t icppSegG<elem_xt>::sizeOfBytes() const ic_noexc {
        return this->distance;
    }

    icpp_t1(elem_xt) ic_inl size_t icppSegG<elem_xt>::size() const ic_noexc {
        return this->sizeOfBytes() / sizeof(elem_xt);
    }

    icpp_t1(elem_xt) ic_inl icppSegG<elem_xt> icppSegG<elem_xt>::slice(size_t bg, size_t ed) ic_noexc {
        auto pos = this->position;
        return icppSegG<elem_xt>(pos + bg, ed - bg);
    }

    icpp_t1(elem_xt) ic_inl void icppSegG<elem_xt>::set(const elem_xt* pos, size_t sz) ic_noexc {
        this->position = (elem_xt*)pos;
        this->distance = sizeof(elem_xt) * sz;
    }

    icpp_t1(elem_xt) ic_inl typename icppSegG<elem_xt>::elem_t& icppSegG<elem_xt>::operator[](size_t pos) ic_noexc {
        using elem_t = typename icppSegG<elem_xt>::elem_t;
        return ((elem_t*)(this->position))[pos];
    }

    icpp_t1(elem_xt) ic_inl typename icppSegG<elem_xt>::elem_t icppSegG<elem_xt>::operator[](size_t pos) const ic_noexc {
        using elem_t = typename icppSegG<elem_xt>::elem_t;
        return ((elem_t*)(this->position))[pos];
    }

    icpp_t1(elem_xt) ic_inl icppSegG<elem_xt>& icppSegG<elem_xt>::operator=(const icppSegG<elem_xt>& st) ic_noexc {
        this->position = st.position;
        this->distance = st.distance;
        return *this;
    }

    icpp_t1(elem_xt) ic_inl bool icppSegG<elem_xt>::operator==(const icppSegG<elem_xt>& st) ic_noexc {
        return icSameMemSize(this->position, this->distance, st.position, st.distance);
    }

    icpp_t1(elem_xt) ic_inl bool icppSegG<elem_xt>::operator!=(const icppSegG<elem_xt>& st) ic_noexc {
        return !(*this == st);
    }

    icpp_t1(elem_xt) ic_inl icppSegG<elem_xt>::operator icppItvG<elem_xt>() const ic_noexc {
        return icppItvG<elem_xt>(this->begin(), this->end());
    }

    icpp_t1(elem_xt) ic_inl icppItvG<elem_xt> icppSegG<elem_xt>::toItv() const ic_noexc {
        return (icppItvG<elem_xt>)*this;
    }

    icpp_t1(elem_xt) ic_inl icppSegG<elem_xt>::icppSegG() ic_noexc {
        this->set(nullptr, 0);
    }

    icpp_t1(elem_xt) ic_inl icppSegG<elem_xt>::icppSegG(const icppSegG<elem_xt>& st) ic_noexc {
        *this = st;
    }

    icpp_t1(elem_xt) ic_inl icppSegG<elem_xt>::icppSegG(const elem_xt* pos, size_t sz) ic_noexc {
        this->set(pos, sz);
    }