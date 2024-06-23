
#pragma once

#include"../declarations.h"

class icppNullRef {
public:
    icpp_t1(obj_xt) ic_inl                  obj_xt& ic_call cast() const ic_noexc { return *(obj_xt*)nullptr;    }
    icpp_t1(obj_xt) ic_inl ic_call operator obj_xt&             () const ic_noexc { return this->cast<obj_xt>(); }
    ic_inl void* ic_call operator&() const ic_noexc { return nullptr; }
    icpp_t1(obj_xt) icppNullRef ic_call operator=(const obj_xt&) ic_noexc = delete;
    ic_inl ic_call icppNullRef() ic_noexc {}
};

ic_info("declarations")
    ic_inl icppNullRef& ic_call H_icppGetNullref() ic_noexc;

ic_info("inlines")
    icpp_t1(obj_xt) ic_inl bool ic_call operator==(const icppNullRef& nref, const obj_xt&      oref) ic_noexc { return (bool)(&nref == (const void*)&oref); }
    icpp_t1(obj_xt) ic_inl bool ic_call operator==(const obj_xt&      oref, const icppNullRef& nref) ic_noexc { return (bool)(&oref == (const void*)&nref); }
    icpp_t1(obj_xt) ic_inl bool ic_call operator!=(const icppNullRef& nref, const obj_xt&      oref) ic_noexc { return (bool)(&nref != (const void*)&oref); }
    icpp_t1(obj_xt) ic_inl bool ic_call operator!=(const obj_xt&      oref, const icppNullRef& nref) ic_noexc { return (bool)(&oref != (const void*)&nref); }

    ic_inl icppNullRef& ic_call H_icppGetNullref() ic_noexc {
    #if defined(IC_CE_GNUC) || defined(IC_CE_CLANG)
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wnull-dereference"
            return *reinterpret_cast<icppNullRef*>(0);
        #pragma GCC diagnostic pop
    #else
        return *reinterpret_cast<icppNullRef*>(0);
    #endif
    }