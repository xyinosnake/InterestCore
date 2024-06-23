
#pragma once

#include"../../Common/Types/icCommonTypes.h"

ic_info("...")
    ic_dcl_struct(IC_CPUID_REGISTERS);
    ic_dcl_struct(IC_XGETBV_REGISTERS);
    ic_dcl_struct(IC_CPU_FEATURES);

ic_info("...")
    struct IC_CPUID_REGISTERS {
        uint32_t EAX;
        uint32_t EBX;
        uint32_t ECX;
        uint32_t EDX;
    };

    struct IC_XGETBV_REGISTERS {
        uint32_t EAX, EDX;
    };

    struct IC_CPU_FEATURES {
        uint32_t max_EAX;
        ch8_t    vender_ID[13];

        ic_info("Vendor")
            bool vendor_Intel : 1;
            bool vendor_AMD : 1;

        ic_info("OSFeatures")
            bool OS_AVX : 1;     // 即使CPU支持AVX，   操作系统也可能不支持AVX。   必须通过_xgetbv明确操作系统是否支持该指令集。
            bool OS_AVX512 : 1;  // 即使CPU支持AVX512，操作系统也可能不支持AVX512。必须通过_xgetbv明确操作系统是否支持该指令集。

        ic_info("Misc.")
            bool x64 : 1;
            bool MMX_POPCNT : 1; // Same
            bool LZCNT_ABM : 1;  // Same
            bool RDRAND : 1;
            bool RDSEED : 1;
            bool BMI1 : 1;
            bool BMI2 : 1;
            bool ADX : 1;
            bool MPX : 1;
            bool PREFETCHW : 1;
            bool PREFETCHWT1 : 1;
            bool RDPID : 1;
            bool OSXSAVE : 1;
            bool SSE_STATE : 1;
            bool AVX_STATE : 1;
            bool F16C : 1;
            bool MOVBE : 1;

        ic_info("SIMD: 128-bit")
            bool SSE : 1;
            bool SSE2 : 1;
            bool SSE3 : 1;
            bool SSSE3 : 1;
            bool SSE4_1 : 1;
            bool SSE4_2 : 1;
            bool SSE4a : 1;
            bool AES : 1;
            bool SHA : 1;

        ic_info("SIMD: 256-bit")
            bool AVX : 1;
            bool XOP : 1;
            bool FMA_FMA3 : 1; // Same
            bool FMA4 : 1;
            bool AVX2 : 1;

        ic_info("SIMD: 512-bit")
            bool AVX512_F : 1;
            bool AVX512_CD : 1;

        ic_info("Knights Landing")
            bool AVX512_PF : 1;
            bool AVX512_ER : 1;

        ic_info("Skylake Purley")
            bool AVX512_VL : 1;
            bool AVX512_BW : 1;
            bool AVX512_DQ : 1;

        ic_info("Cannon Lake")
            bool AVX512_IFMA : 1;
            bool AVX512_VBMI : 1;

        ic_info("Knights Mill")
            bool AVX512_VPOPCNTDQ : 1;
            bool AVX512_4FMAPS : 1;
            bool AVX512_4VNNIW : 1;

        ic_info("Cascade Lake")
            bool AVX512_VNNI : 1;

        ic_info("Cooper Lake")
            bool AVX512_BF16 : 1;

        ic_info("Ice Lake")
            bool AVX512_VBMI2 : 1;
            bool GFNI : 1;
            bool VAES : 1;
            bool AVX512_VPCLMUL : 1;
            bool AVX512_BITALG : 1;
    };