
#pragma once

#include"../../../Common/Macros/icCommonMacros.h"
#include"../../../Common/Types/icCommonTypes.h"
#include"../../../Common/Funcs/icCommonFuncs.h"
#include"../icX64Macros.h"

ic_info("Macros")
    #define icRdRand8  _icRdRand8Func
    #define icRdRand16 _rdrand16_step
    #define icRdRand32 _rdrand32_step
    #define icRdRand64 _icRdRand64Func

    #define icRdSeed8  _icRdSeed8Func
    #define icRdSeed16 _rdseed16_step
    #define icRdSeed32 _rdseed32_step
    #define icRdSeed64 _icRdSeed64Func

ic_info("declarations")
    ic_dcl int ic_call icRdRand8Func(uint8_t* pU8) ic_noexc;
    ic_dcl int ic_call icRdSeed8Func(uint8_t* pU8) ic_noexc;
    #if IC_WORD_SIZE == 64
        #define icRdRand64Func _rdrand64_step
        #define icRdSeed64Func _rdseed64_step
    #else
        ic_dcl int ic_call icRdRand64Func(uint64_t* pU64) ic_noexc;
        ic_dcl int ic_call icRdSeed64Func(uint64_t* pU64) ic_noexc;
    #endif
    ic_dcl bool ic_call icGenRdRandSize(void* bg, size_t btSz) ic_noexc;
    ic_dcl bool ic_call icGenRdSeedSize(void* bg, size_t btSz) ic_noexc;
    ic_inl bool ic_call icGenRdRand(void* bg, void* ed) ic_noexc;
    ic_inl bool ic_call icGenRdSeed(void* bg, void* ed) ic_noexc;

ic_info("inl definitions")
    ic_inl bool ic_call icGenRdRand(void* bg, void* ed) ic_noexc {
        return icGenRdRandSize(bg, icPtrDiff(bg, ed));
    }

    ic_inl bool ic_call icGenRdSeed(void* bg, void* ed) ic_noexc {
        return icGenRdSeedSize(bg, icPtrDiff(bg, ed));
    }