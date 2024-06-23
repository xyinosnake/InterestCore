
#pragma once

#include"P_icRdRand_RdSeed.h"
#include"../../../Memory/Funcs/icMemoryFuncs.h"

ic_info("definitions")
    #define icRdXX8Func_m(rd_xf) \
        static ic_thread_own uint8_t buf; \
        static ic_thread_own bool    bHold = 0; \
        int r; \
        ic_if_do_x3(bHold, *pU8 = buf, bHold = false, r = 1) \
        else { \
            uint16_t v16; \
            int r = rd_xf(&v16); \
            ic_if_return(!r, r); \
            ic_do_x3(*pU8 = ((uint8_t*)&v16)[0], buf = ((uint8_t*)&v16)[1], bHold = true); \
        } \
        return r

    ic_dcl ic_tgt("rdrnd") int ic_call icRdRand8Func(uint8_t* pU8) ic_noexc {
        icRdXX8Func_m(_rdrand16_step);
    }

    ic_dcl ic_tgt("rdseed") int ic_call icRdSeed8Func(uint8_t* pU8) ic_noexc {
        icRdXX8Func_m(_rdseed16_step);
    }
    #undef icRdXX8Func_m

#if IC_WORD_SIZE != 64
    #define icRdXX64Func_m(rd_xf) \
        int r = rd_xf((uint32_t*)pU64); \
        ic_if_do(r, r = rd_xf((uint32_t*)pU64 + 1)) \
        return r

    ic_dcl ic_tgt("rdrnd") int ic_call icRdRand64Func(uint64_t* pU64) ic_noexc {
        icRdXX64Func_m(_rdrand32_step);
    }

    ic_dcl ic_tgt("rdseed") int ic_call icRdSeed64Func(uint64_t* pU64) ic_noexc {
        icRdXX64Func_m(_rdseed32_step);
    }
    #undef icRdXX64Func_m
#endif

#define icGenRdXXSize_m(type_xt, rd_xf) \
    size_t n = btSz / sizeof(type_xt); \
    type_xt* itXX = (type_xt*)bg; \
    type_xt* edXX = itXX + n; \
    ic_while_do(itXX != edXX, ic_if_return(!rd_xf(itXX++), false)); \
    type_xt bufXX; \
    ic_if_return(!rd_xf(&bufXX), false); \
    icCopyMemSizeNoRet(itXX, &bufXX, btSz % sizeof(type_xt)); \
    return true

    ic_dcl ic_tgt("rdrnd") bool ic_call icGenRdRandSize(void* bg, size_t btSz) ic_noexc {
    #if IC_WORD_SIZE == 64
        icGenRdXXSize_m(unsigned long long, _rdrand64_step);
    #else
        icGenRdXXSize_m(unsigned, _rdrand32_step);
    #endif
    }

    ic_dcl ic_tgt("rdseed") bool ic_call icGenRdSeedSize(void* bg, size_t btSz) ic_noexc {
    #if IC_WORD_SIZE == 64
        icGenRdXXSize_m(unsigned long long, _rdseed64_step);
    #else
        icGenRdXXSize_m(unsigned, _rdseed64_step);
    #endif
    }
#undef icGenRdXXSize_m