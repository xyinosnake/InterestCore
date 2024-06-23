
#pragma once

#include"./icppCommonFuncs.h"

ic_info("in ns inl definitions") icpp_ns_x1(icpp)
    ic_inl void ic_call hello(ic_hello_flags_e flags) ic_noexc {
        icppHello(flags);
    }

    icpp_t1(value_xt) ic_inl bool ic_call valInItv(value_xt value, value_xt left, value_xt right) ic_noexc {
        return icValInItv(value, left, right);
    }

    icpp_t1(value_xt) ic_inl bool ic_call valInClosedItv(value_xt value, value_xt left, value_xt right) ic_noexc {
        return icValInClosedItv(value, left, right);
    }

    icpp_t1(value_xt) ic_inl value_xt& ic_call setBits(value_xt& v, value_xt mask) ic_noexc {
        return icSetBits(v, mask);
    }

    icpp_t1(value_xt) ic_inl value_xt& ic_call clearBits(value_xt& v, value_xt mask) ic_noexc {
        return icClearBits(v, mask);
    }

    icpp_t1(value_xt) ic_inl value_xt& ic_call setOrClearBits(bool b, value_xt& v, value_xt mask) ic_noexc {
        return icSetOrClearBits(b, v, mask);
    }

    icpp_t1(value_xt) ic_inl value_xt ic_call getBits(value_xt v, value_xt mask) ic_noexc {
        return icGetBits(v, mask);
    }

    icpp_t1(value_xt) ic_inl value_xt  ic_call getBit(value_xt v, value_xt mask) ic_noexc {
        return icGetBit(v, mask);
    }

    icpp_t2(func_xf, srcFunc_xf) ic_inl func_xf ic_call funcCast(srcFunc_xf f) ic_noexc {
    #if defined(IC_CE_GNUC)
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wall" //"-Wpmf-conversions"
            return (func_xf)f;
        #pragma GCC diagnostic pop
    #else
        return (func_xf)f;
    #endif
    }

    ic_inl ptrdiff_t ic_call ptrDiff (cvoid_p bg, cvoid_p ed) ic_noexc {
        return icPtrDiff(bg, ed);
    }

    ic_inl size_t ic_call ptrDiffU(cvoid_p bg, cvoid_p ed) ic_noexc {
        return icPtrDiffU(bg, ed);
    }

    icpp_t1(ptr_xt) ic_inl ptr_xt ic_call addPtr(ptr_xt bg, ptrdiff_t btSz) ic_noexc {
        return (ptr_xt)icAddPtr((cvoid_p)bg, btSz);
    }

    icpp_t1(ptr_xt) ic_inl ptr_xt ic_call subPtr(ptr_xt bg, ptrdiff_t btSz) ic_noexc {
        return (ptr_xt)icSubPtr((cvoid_p)bg, btSz);
    }

    ic_inl ptrdiff_t ic_call objPtrDiff(cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc {
        return icObjPtrDiff(bg, ed, btSzOfObj);
    }

    ic_inl size_t ic_call objPtrDiffU(cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc {
        return icObjPtrDiffU(bg, ed, btSzOfObj);
    }

    ic_inl void_p ic_call addObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc {
        return icAddObjPtr(bg, sz, btSzOfObj);
    }

    ic_inl void_p ic_call subObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc {
        return icSubObjPtr(bg, sz, btSzOfObj);
    }

    ic_inl flo32_t ic_call binF32(uint32_t u) ic_noexc {
        return icBinF32(u);
    }

    ic_inl flo64_t ic_call binF64(uint64_t u) ic_noexc {
        return icBinF64(u);
    }

    ic_inl ptrdiff_t ic_call lockedInc(volatile ptrdiff_t& refI) ic_noexc {
        return icLockedInc(&refI);
    }

    ic_inl size_t ic_call lockedIncU(volatile size_t& refU) ic_noexc {
        return icLockedIncU(&refU);
    }

    ic_inl ptrdiff_t ic_call lockedDec(volatile ptrdiff_t& refI) ic_noexc {
        return icLockedDec(&refI);
    }

    ic_inl size_t ic_call lockedDecU(volatile size_t& refU) ic_noexc {
        return icLockedDecU(&refU);
    }

    icpp_t2(Obj, ...Args) ic_inl void ic_call construct(Obj& obj, Args&&...args) ic_noexc {
        new (&obj) Obj(::std::forward<Args>(args)...);
    }

    icpp_t1(Obj) ic_inl void ic_call destruct(Obj& obj) ic_noexc {
        obj.~Obj();
    }

    icpp_t2(Target, Obj) ic_inl Target& as(Obj& obj) ic_noexc {
        return reinterpret_cast<Target&>(obj);
    }

    icpp_t2(Target, Obj) ic_inl const Target& as(const Obj& obj) ic_noexc {
        return reinterpret_cast<const Target&>(obj);
    }
icpp_end_ns_x1