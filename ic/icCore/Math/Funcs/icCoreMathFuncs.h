
#pragma once

#include"../../Common/icCoreHeaders.h"
#include"../Structs/icCoreMathStructs.h"

ic_info("Macros")
    #define ic_pi                              3.141592653589793
    #define icMin(a, b)                        (((a) < (b)) ? (a) : (b))
    #define icMax(a, b)                        (((a) > (b)) ? (a) : (b))
    #define icAbs(v)                           (v < 0 ? -v : v)                   
    #define icGetLCMByGCD(a, b, gcd)           ((a / gcd) * b) //LCM=最小公倍数，GCD=最大公约数
    #define icReduceFracByGCD(refA, refB, gcd) if (gcd != 1) { refA /= gcd; refB /= gcd; } //refA: num, refB: den

ic_info("decs")
    ic_core_dcl uint8_t  ic_call icGetGCDU8 (uint8_t  a, uint8_t  b) ic_noexc;
    ic_core_dcl uint16_t ic_call icGetGCDU16(uint16_t a, uint16_t b) ic_noexc;
    ic_core_dcl uint32_t ic_call icGetGCDU32(uint32_t a, uint32_t b) ic_noexc;
    ic_core_dcl uint64_t ic_call icGetGCDU64(uint64_t a, uint64_t b) ic_noexc;

    ic_core_dcl int8_t  ic_call icGetGCDI8 (int8_t  a, int8_t  b) ic_noexc;
    ic_core_dcl int16_t ic_call icGetGCDI16(int16_t a, int16_t b) ic_noexc;
    ic_core_dcl int32_t ic_call icGetGCDI32(int32_t a, int32_t b) ic_noexc;
    ic_core_dcl int64_t ic_call icGetGCDI64(int64_t a, int64_t b) ic_noexc;

ic_info("decs")
    ic_inl flo32_t ic_call icGetPiF32() ic_noexc;
    ic_inl flo64_t ic_call icGetPiF64() ic_noexc;
    ic_inl flo32_t ic_call icLogF32(flo32_t power, flo32_t base) ic_noexc;
    ic_inl flo64_t ic_call icLogF64(flo64_t power, flo64_t base) ic_noexc;
    ic_inl flo32_t ic_call icModF32(flo32_t a, flo32_t b) ic_noexc;
    ic_inl flo64_t ic_call icModF64(flo64_t a, flo64_t b) ic_noexc;
    ic_inl flo32_t ic_call icDivModF32(flo32_t a, flo32_t b, flo32_t* pRem) ic_noexc;
    ic_inl flo64_t ic_call icDivModF64(flo64_t a, flo64_t b, flo64_t* pRem) ic_noexc;
    ic_inl flo32_t ic_call icSqrtF32(flo32_t power) ic_noexc;
    ic_inl flo64_t ic_call icSqrtF64(flo64_t power) ic_noexc;
    ic_inl flo32_t ic_call icAngleToRadianF32(flo32_t angle) ic_noexc;
    ic_inl flo64_t ic_call icAngleToRadianF64(flo64_t angle) ic_noexc;
    #define                icAToRF32 icAngleToRadianF32
    #define                icAToRF64 icAngleToRadianF64
    ic_inl flo32_t ic_call icSinF32(flo32_t radian) ic_noexc;
    ic_inl flo64_t ic_call icSinF64(flo64_t radian) ic_noexc;
    ic_inl flo32_t ic_call icCosF32(flo32_t radian) ic_noexc;
    ic_inl flo64_t ic_call icCosF64(flo64_t radian) ic_noexc;
    ic_inl flo32_t ic_call icTanF32(flo32_t radian) ic_noexc;
    ic_inl flo64_t ic_call icTanF64(flo64_t radian) ic_noexc;
    #define                icSinAF32(angle) icSinF32(icAngleToRadianF32(angle))
    #define                icSinAF64(angle) icSinF64(icAngleToRadianF64(angle))
    #define                icCosAF32(angle) icCosF32(icAngleToRadianF32(angle))
    #define                icCosAF64(angle) icCosF64(icAngleToRadianF64(angle))
    #define                icTanAF32(angle) icTanF32(icAngleToRadianF32(angle))
    #define                icTanAF64(angle) icTanF64(icAngleToRadianF64(angle))
    ic_inl flo32_t ic_call icASinF32(flo32_t radian) ic_noexc;
    ic_inl flo64_t ic_call icASinF64(flo64_t radian) ic_noexc;
    ic_inl flo32_t ic_call icACosF32(flo32_t radian) ic_noexc;
    ic_inl flo64_t ic_call icACosF64(flo64_t radian) ic_noexc;
    ic_inl flo32_t ic_call icATanF32(flo32_t radian) ic_noexc;
    ic_inl flo64_t ic_call icATanF64(flo64_t radian) ic_noexc;
    #define                icASinAF32(angle) icASinF32(icAngleToRadianF32(angle))
    #define                icASinAF64(angle) icASinF64(icAngleToRadianF64(angle))
    #define                icACosAF32(angle) icACosF32(icAngleToRadianF32(angle))
    #define                icACosAF64(angle) icACosF64(icAngleToRadianF64(angle))
    #define                icATanAF32(angle) icATanF32(icAngleToRadianF32(angle))
    #define                icATanAF64(angle) icATanF64(icAngleToRadianF64(angle))
    ic_inl flo32_t ic_call icPowF32(flo32_t base, flo32_t index) ic_noexc;
    ic_inl flo64_t ic_call icPowF64(flo64_t base, flo64_t index) ic_noexc;
    ic_inl flo32_t ic_call icExtF32(flo32_t power, flo32_t index) ic_noexc; //Extract
    ic_inl flo64_t ic_call icExtF64(flo64_t power, flo64_t index) ic_noexc; //Extract

ic_info("defs: inlines")
    ic_inl flo32_t ic_call icGetPiF32() ic_noexc {
        return (flo32_t)ic_pi;
    }

    ic_inl flo64_t ic_call icGetPiF64() ic_noexc {
        return (flo64_t)ic_pi;
    }

    ic_inl flo32_t ic_call icLogF32(flo32_t power, flo32_t base) ic_noexc {
        return logf(power) / logf(base);
    }

    ic_inl flo64_t ic_call icLogF64(flo64_t power, flo64_t base) ic_noexc {
        return log(power) / log(base);
    }

    ic_inl flo32_t ic_call icModF32(flo32_t a, flo32_t b) ic_noexc {
    #define flo_xt flo32_t
    #define int_xt int32_t
        return a - b * (flo_xt)(int_xt)(a / b);
    #undef flo_xt
    #undef int_xt
    }

    ic_inl flo64_t ic_call icModF64(flo64_t a, flo64_t b) ic_noexc {
    #define flo_xt flo64_t
    #define int_xt int64_t
        return a - b * (flo_xt)(int_xt)(a / b);
    #undef flo_xt
    #undef int_xt
    }

    ic_inl flo32_t ic_call icDivModF32(flo32_t a, flo32_t b, flo32_t* pRem) ic_noexc {
    #define flo_xt flo32_t
    #define int_xt int32_t
        flo_xt qt = (flo_xt)(int_xt)(a / b); //quotient
        ic_if_do(pRem, *pRem = a - b * qt);  //remainder
        return qt;
    #undef flo_xt
    #undef int_xt
    }

    ic_inl flo64_t ic_call icDivModF64(flo64_t a, flo64_t b, flo64_t* pRem) ic_noexc {
    #define flo_xt flo64_t
    #define int_xt int64_t
        flo_xt qt = (flo_xt)(int_xt)(a / b); //quotient
        ic_if_do(pRem, *pRem = a - b * qt);  //remainder
        return qt;
    #undef flo_xt
    #undef int_xt
    }

    ic_inl flo32_t ic_call icSqrtF32(flo32_t power) ic_noexc {
        return sqrtf(power);
    }

    ic_inl flo64_t ic_call icSqrtF64(flo64_t power) ic_noexc {
        return sqrt(power);
    }

    ic_inl flo32_t ic_call icAngleToRadianF32(flo32_t angle) ic_noexc {
        return angle * ((flo32_t)ic_pi) / 180.0f;
    }

    ic_inl flo64_t ic_call icAngleToRadianF64(flo64_t angle) ic_noexc {
        return angle * ((flo64_t)ic_pi) / 180.0;
    }

    ic_inl flo32_t ic_call icSinF32(flo32_t radian) ic_noexc {
        return sinf(radian);
    }

    ic_inl flo64_t ic_call icSinF64(flo64_t radian) ic_noexc {
        return sin(radian);
    }

    ic_inl flo32_t ic_call icCosF32(flo32_t radian) ic_noexc {
        return cosf(radian);
    }

    ic_inl flo64_t ic_call icCosF64(flo64_t radian) ic_noexc {
        return cos(radian);
    }

    ic_inl flo32_t ic_call icTanF32(flo32_t radian) ic_noexc {
        return tanf(radian);
    }

    ic_inl flo64_t ic_call icTanF64(flo64_t radian) ic_noexc {
        return tan(radian);
    }

    ic_inl flo32_t ic_call icASinF32(flo32_t radian) ic_noexc {
        return asinf(radian);
    }

    ic_inl flo64_t ic_call icASinF64(flo64_t radian) ic_noexc {
        return asin(radian);
    }

    ic_inl flo32_t ic_call icACosF32(flo32_t radian) ic_noexc {
        return acosf(radian);
    }

    ic_inl flo64_t ic_call icACosF64(flo64_t radian) ic_noexc {
        return acos(radian);
    }

    ic_inl flo32_t ic_call icATanF32(flo32_t radian) ic_noexc {
        return atanf(radian);
    }

    ic_inl flo64_t ic_call icATanF64(flo64_t radian) ic_noexc {
        return atan(radian);
    }

    ic_inl flo32_t ic_call icPowF32(flo32_t base, flo32_t index) ic_noexc {
        return powf(base, index);
    }

    ic_inl flo64_t ic_call icPowF64(flo64_t base, flo64_t index) ic_noexc {
        return pow(base, index);
    }

    ic_inl flo32_t ic_call icExtF32(flo32_t power, flo32_t index) ic_noexc {
        return powf(power, 1.0f / index);
    }

    ic_inl flo64_t ic_call icExtF64(flo64_t power, flo64_t index) ic_noexc {
        return pow(power, 1.0 / index);
    }