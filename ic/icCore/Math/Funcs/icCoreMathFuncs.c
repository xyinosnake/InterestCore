
#ifndef IC_CORE_MATH_FUNCS
#define IC_CORE_MATH_FUNCS

#include"./icCoreMathFuncs.h"

ic_info("defs")
    #define icGetGCDU_m(type_xt) \
        ic_if_swap(a < b, type_xt, a, b);\
        while (b != 0) {\
            type_xt c = a;\
            a = b;\
            b = c % b;\
        }\
        return a

    ic_core_dcl uint8_t ic_call icGetGCDU8(uint8_t a, uint8_t b) ic_noexc {
        icGetGCDU_m(uint8_t);
    }

    ic_core_dcl uint16_t ic_call icGetGCDU16(uint16_t a, uint16_t b) ic_noexc {
        icGetGCDU_m(uint16_t);
    }

    ic_core_dcl uint32_t ic_call icGetGCDU32(uint32_t a, uint32_t b) ic_noexc {
        icGetGCDU_m(uint32_t);
    }

    ic_core_dcl uint64_t ic_call icGetGCDU64(uint64_t a, uint64_t b) ic_noexc {
        icGetGCDU_m(uint64_t);
    }
    #undef icGetGCDU_m

    #define icGetGCDI_m(int_xt, uint_xt, GetGCDU_xf) \
        bool bNegA = a < 0;\
        bool bNegB = b < 0;\
        bool bNeg  = (bNegA && bNegB);\
        ic_if_do(bNegA, a = -a);\
        ic_if_do(bNegB, b = -b);\
        int_xt c = (int_xt)GetGCDU_xf((uint_xt)a, (uint_xt)b);\
        if (bNeg) {\
            ic_if_do(c > 0, c = -c);\
        } else {\
            ic_if_do(c < 0, c = -c);\
        }\
        return c

    ic_core_dcl int8_t ic_call icGetGCDI8(int8_t a, int8_t b) ic_noexc {
        icGetGCDI_m(int8_t, uint8_t, icGetGCDU8);
    }

    ic_core_dcl int16_t ic_call icGetGCDI16(int16_t a, int16_t b) ic_noexc {
        icGetGCDI_m(int16_t, uint16_t, icGetGCDU16);
    }

    ic_core_dcl int32_t ic_call icGetGCDI32(int32_t a, int32_t b) ic_noexc {
        icGetGCDI_m(int32_t, uint32_t, icGetGCDU32);
    }

    ic_core_dcl int64_t ic_call icGetGCDI64(int64_t a, int64_t b) ic_noexc {
        icGetGCDI_m(int64_t, uint64_t, icGetGCDU64);
    }
    #undef icGetGCDI_m
#endif