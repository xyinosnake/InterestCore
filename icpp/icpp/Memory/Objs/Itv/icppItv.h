

#pragma once

#include"./declarations.h"
#include"../Seg/declarations.h"
#include"../../Funcs/icppMemoryFuncs.h"

ic_info("definitions")
    icpp_t1(elem_xt) ic_inl elem_xt* icppItvG<elem_xt>::begin() ic_noexc {
        return this->left;
    }

    icpp_t1(elem_xt) ic_inl elem_xt* icppItvG<elem_xt>::end() ic_noexc {
        return this->right;
    }

    icpp_t1(elem_xt) ic_inl const elem_xt* icppItvG<elem_xt>::begin() const ic_noexc {
        return this->left;
    }

    icpp_t1(elem_xt) ic_inl const elem_xt* icppItvG<elem_xt>::end() const ic_noexc {
        return this->right;
    }

    icpp_t1(elem_xt) ic_inl bool icppItvG<elem_xt>::empty() const ic_noexc {
        return this->left == this->right;
    }

    icpp_t1(elem_xt) ic_inl bool icppItvG<elem_xt>::isNull() const ic_noexc {
        return (this->left == nullptr) && (this->right == nullptr);
    }

    icpp_t1(elem_xt) ic_inl size_t icppItvG<elem_xt>::sizeOfBytes() const ic_noexc {
        return (size_t)icPtrDiff(this->left, this->right);
    }

    icpp_t1(elem_xt) ic_inl size_t icppItvG<elem_xt>::size() const ic_noexc {
        return this->sizeOfBytes() / sizeof(elem_xt);
    }

    icpp_t1(elem_xt) ic_inl icppItvG<elem_xt> icppItvG<elem_xt>::slice(size_t bg, size_t ed) ic_noexc {
        auto left = this->left;
        return icppItvG<elem_xt>(left + bg, left + ed);
    }

    icpp_t1(elem_xt) ic_inl void icppItvG<elem_xt>::set(const elem_xt* bg, const elem_xt* ed) ic_noexc {
        this->left  = (elem_xt*)bg;
        this->right = (elem_xt*)ed;
    }

    icpp_t1(elem_xt) ic_inl typename icppItvG<elem_xt>::elem_t& icppItvG<elem_xt>::operator[](size_t pos) ic_noexc {
        using elem_t = typename icppItvG<elem_xt>::elem_t;
        return ((elem_t*)(this->left))[pos];
    }

    icpp_t1(elem_xt) ic_inl typename icppItvG<elem_xt>::elem_t icppItvG<elem_xt>::operator[](size_t pos) const ic_noexc {
        using elem_t = typename icppItvG<elem_xt>::elem_t;
        return ((elem_t*)(this->left))[pos];
    }

    icpp_t1(elem_xt) ic_inl icppItvG<elem_xt>& icppItvG<elem_xt>::operator=(const icppItvG<elem_xt>& st) ic_noexc {
        this->set(st.left, st.right);
    }

    icpp_t1(elem_xt) ic_inl bool icppItvG<elem_xt>::operator==(const icppItvG<elem_xt>& st) ic_noexc {
        return icSameMem(this->left, this->right, st.left, st.right);
    }

    icpp_t1(elem_xt) ic_inl bool icppItvG<elem_xt>::operator!=(const icppItvG<elem_xt>& st) ic_noexc {
        return !(*this == st);
    }

    icpp_t1(elem_xt) ic_inl icppItvG<elem_xt>::operator icppSegG<elem_xt>() const ic_noexc {
        return icppSegG<elem_xt>(this->begin(), this->size());
    }

    icpp_t1(elem_xt) ic_inl icppSegG<elem_xt> icppItvG<elem_xt>::toSeg() const ic_noexc {
        return (icppSegG<elem_xt>)*this;
    }

    icpp_t1(elem_xt) ic_inl icppItvG<elem_xt>::icppItvG() ic_noexc {
        this->set(nullptr, nullptr);
    }

    icpp_t1(elem_xt) ic_inl icppItvG<elem_xt>::icppItvG(const icppItvG<elem_xt>& st) ic_noexc {
        this->set(st.left, st.right);
    }

    icpp_t1(elem_xt) ic_inl icppItvG<elem_xt>::icppItvG(const elem_xt* bg, const elem_xt* ed) ic_noexc {
        this->set(bg, ed);
    }