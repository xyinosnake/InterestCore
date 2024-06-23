
#ifndef IC_X64_FUNCS
#define IC_X64_FUNCS

#include"./icX64Funcs.h"

ic_info("Parts")
    #include"./P_icRdRand_RdSeed.c.h"

ic_info("...")
    ic_dcl bool ic_call icGetCPUID(int CPUInfo[4], int Function, int SubLeaf) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        __cpuidex(CPUInfo, Function, SubLeaf);
        return true;
    #elif defined(IC_OS_UNIX_LIKE)
        __asm__ volatile("cpuid"
            : "=a" (CPUInfo[0]), "=b" (CPUInfo[1]), "=c" (CPUInfo[2]), "=d" (CPUInfo[3])
            : "a" (Function), "c" (SubLeaf));
        return true;
    #else
        return false;
    #endif
    }

    ic_hide void ic_call H_icGetOSAVXFeatures(IC_CPU_FEATURES* cf, int cpuInfo_1_0[4], uint64_t _xgetbv_0) ic_noexc {
        bool avxSupported;
        bool osUsesXSAVE_XRSTORE = (cpuInfo_1_0[2] & (1 << 27)) != 0;
        bool cpuAVXSuport        = (cpuInfo_1_0[2] & (1 << 28)) != 0;
        if (osUsesXSAVE_XRSTORE && cpuAVXSuport) {
            uint64_t xcrFeatureMask = _xgetbv_0;
            avxSupported = (xcrFeatureMask & 0x6) == 0x6;
            cf->OS_AVX = avxSupported; // OS_AVX
            ic_if_do(avxSupported, cf->OS_AVX512 = (xcrFeatureMask & 0xE6) == 0xE6); // OS_AVX512
        }
    }

    ic_dcl ic_tgt("xsave") bool ic_call icGetCPUFeatures(IC_CPU_FEATURES* cf) ic_noexc {
        int32_t              info[4];
        int32_t              nIds;
        uint32_t             nExIds;
        uint64_t             _xgetbv_0 = 0;
        ch8_t*               pVenderID;
        bool                 mb;
        IC_CPUID_REGISTERS*  pRegs   = (IC_CPUID_REGISTERS*)info;
        IC_XGETBV_REGISTERS* pXgetbv = (IC_XGETBV_REGISTERS*)&_xgetbv_0;
        memset(cf, 0, sizeof(IC_CPU_FEATURES));
        icCPUID(info, 0, 0); // function: EAX, subLeaf: ECX
        nIds = info[0];
        cf->max_EAX = pRegs->EAX;
        pVenderID = cf->vender_ID;
        *(uint32_t*)(pVenderID + 0) = pRegs->EBX;
        *(uint32_t*)(pVenderID + 4) = pRegs->EDX;
        *(uint32_t*)(pVenderID + 8) = pRegs->ECX;
        pVenderID[12] = '\0';
            ic_if_do(memcmp(pVenderID, "GenuineIntel", 12) == 0, cf->vendor_Intel = 1)
        else ic_if_do(memcmp(pVenderID, "AuthenticAMD", 12) == 0, cf->vendor_AMD   = 1);
        icCPUID(info, 0x80000000, 0);
        nExIds = info[0];        
        if (nIds >= 0x00000001) { // Detect Features
            icCPUID(info, 0x00000001, 0);
            cf->MMX_POPCNT = (info[3] & (0x1 << 23)) != 0; // POPCNT
            cf->SSE        = (info[3] & (0x1 << 25)) != 0;
            cf->SSE2       = (info[3] & (0x1 << 26)) != 0;
            cf->SSE3       = (info[2] & (0x1 << 0 )) != 0;
            cf->SSSE3      = (info[2] & (0x1 << 9 )) != 0;
            cf->SSE4_1     = (info[2] & (0x1 << 19)) != 0;
            cf->SSE4_2     = (info[2] & (0x1 << 20)) != 0;
            cf->AES        = (info[2] & (0x1 << 25)) != 0;
            cf->AVX        = (info[2] & (0x1 << 28)) != 0;
            cf->FMA_FMA3   = (info[2] & (0x1 << 12)) != 0; // FMA
            cf->RDRAND     = (info[2] & (0x1 << 30)) != 0;
            cf->F16C       = (info[2] & (0x1 << 29)) != 0;
            cf->MOVBE      = (info[2] & (0x1 << 22)) != 0;
            
            cf->OSXSAVE = mb = (info[2] & (0x1 << 27)) != 0; // OSXSAVE
            ic_if_do(mb, _xgetbv_0 = _xgetbv(0)); // 必须检测OSXSAVE值，否则将诱发异常。
            cf->SSE_STATE = (pXgetbv->EAX & (0x1 << 1)) != 0; // Xgetbv
            cf->AVX_STATE = (pXgetbv->EAX & (0x1 << 2)) != 0;
            H_icGetOSAVXFeatures(cf, info, _xgetbv_0); // AVX
            if (nIds >= 0x00000007) {
                icCPUID(info, 0x00000007, 0);
                cf->AVX2             = (info[1] & (0x1 << 5 )) != 0;
                cf->BMI1             = (info[1] & (0x1 << 3 )) != 0;
                cf->BMI2             = (info[1] & (0x1 << 8 )) != 0;
                cf->ADX              = (info[1] & (0x1 << 19)) != 0;
                cf->MPX              = (info[1] & (0x1 << 14)) != 0;
                cf->SHA              = (info[1] & (0x1 << 29)) != 0;
                cf->RDSEED           = (info[1] & (0x1 << 18)) != 0;
                cf->PREFETCHWT1      = (info[2] & (0x1 << 0 )) != 0;
                cf->RDPID            = (info[2] & (0x1 << 22)) != 0;
                cf->AVX512_F         = (info[1] & (0x1 << 16)) != 0;
                cf->AVX512_CD        = (info[1] & (0x1 << 28)) != 0;
                cf->AVX512_PF        = (info[1] & (0x1 << 26)) != 0;
                cf->AVX512_ER        = (info[1] & (0x1 << 27)) != 0;
                cf->AVX512_VL        = (info[1] & (0x1 << 31)) != 0;
                cf->AVX512_BW        = (info[1] & (0x1 << 30)) != 0;
                cf->AVX512_DQ        = (info[1] & (0x1 << 17)) != 0;
                cf->AVX512_IFMA      = (info[1] & (0x1 << 21)) != 0;
                cf->AVX512_VBMI      = (info[2] & (0x1 << 1 )) != 0;
                cf->AVX512_VPOPCNTDQ = (info[2] & (0x1 << 14)) != 0;
                cf->AVX512_4FMAPS    = (info[3] & (0x1 << 2 )) != 0;
                cf->AVX512_4VNNIW    = (info[3] & (0x1 << 3 )) != 0;
                cf->AVX512_VNNI      = (info[2] & (0x1 << 11)) != 0;
                cf->AVX512_VBMI2     = (info[2] & (0x1 << 6 )) != 0;
                cf->GFNI             = (info[2] & (0x1 << 8 )) != 0;
                cf->VAES             = (info[2] & (0x1 << 9 )) != 0;
                cf->AVX512_VPCLMUL   = (info[2] & (0x1 << 10)) != 0;
                cf->AVX512_BITALG    = (info[2] & (0x1 << 12)) != 0;
                icCPUID(info, 0x00000007, 1);
                cf->AVX512_BF16 = (info[0] & (0x1 << 5)) != 0;
            }
        }
        if (nExIds >= 0x80000001) {
            icCPUID(info, 0x80000001, 0);
            cf->x64       = (info[3] & (0x1 << 29)) != 0;
            cf->LZCNT_ABM = (info[2] & (0x1 << 5 )) != 0; // ABM
            cf->SSE4a     = (info[2] & (0x1 << 6 )) != 0;
            cf->FMA4      = (info[2] & (0x1 << 16)) != 0;
            cf->XOP       = (info[2] & (0x1 << 11)) != 0;
            cf->PREFETCHW = (info[2] & (0x1 << 8 )) != 0;
        }
        return true;
    }

    ic_dcl size_t ic_call icCPUFeaturesToS8(ch8_t* dst, IC_CPU_FEATURES* pCf) ic_noexc {
        size_t nMax = dst ? 65536 : 0;
        ch8_t* it   = dst;
        it += snprintf(it, nMax, "[[CPUFeatures]]\r\n");
        it += snprintf(it, nMax, "max_EAX: %u\r\n",   pCf->max_EAX);
        it += snprintf(it, nMax, "vender_ID: %s\r\n", pCf->vender_ID);
    #define H_icNameBool(name) it += snprintf(it, nMax, "%s: %hhu\r\n", #name, pCf->name)
    #define H_icSPrintStr(s)   it += snprintf(it, nMax, "\r\n" s "\r\n");
        H_icSPrintStr("[Vendor]");
        ////////////////////////
        H_icNameBool(vendor_Intel);
        H_icNameBool(vendor_AMD);

        H_icSPrintStr("[OSFeatures]");
        ////////////////////////
        H_icNameBool(OS_AVX);
        H_icNameBool(OS_AVX512);

        H_icSPrintStr("[Misc]");
        ////////////////////////
        H_icNameBool(x64);
        H_icNameBool(MMX_POPCNT);
        H_icNameBool(LZCNT_ABM);
        H_icNameBool(RDRAND);
        H_icNameBool(RDSEED);
        H_icNameBool(BMI1);
        H_icNameBool(BMI2);
        H_icNameBool(ADX);
        H_icNameBool(MPX);
        H_icNameBool(PREFETCHW);
        H_icNameBool(PREFETCHWT1);
        H_icNameBool(RDPID);
        H_icNameBool(OSXSAVE);
        H_icNameBool(SSE_STATE);
        H_icNameBool(AVX_STATE);
        H_icNameBool(F16C);
        H_icNameBool(MOVBE);

        H_icSPrintStr("[SIMD 128-bit]");
        ////////////////////////
        H_icNameBool(SSE);
        H_icNameBool(SSE2);
        H_icNameBool(SSE3);
        H_icNameBool(SSSE3);
        H_icNameBool(SSE4_1);
        H_icNameBool(SSE4_2);
        H_icNameBool(SSE4a);
        H_icNameBool(AES);
        H_icNameBool(SHA);

        H_icSPrintStr("[SIMD 256-bit]");
        ////////////////////////
        H_icNameBool(AVX);
        H_icNameBool(XOP);
        H_icNameBool(FMA_FMA3); // Same
        H_icNameBool(FMA4);
        H_icNameBool(AVX2);

        H_icSPrintStr("[SIMD 512-bit]");
        ////////////////////////
        H_icNameBool(AVX512_F);
        H_icNameBool(AVX512_CD);

        H_icSPrintStr("[Knights Landing]");
        ////////////////////////
        H_icNameBool(AVX512_PF);
        H_icNameBool(AVX512_ER);

        H_icSPrintStr("[Skylake Purley]");
        ////////////////////////
        H_icNameBool(AVX512_VL);
        H_icNameBool(AVX512_BW);
        H_icNameBool(AVX512_DQ);

        H_icSPrintStr("[Cannon Lake]");
        ////////////////////////
        H_icNameBool(AVX512_IFMA);
        H_icNameBool(AVX512_VBMI);

        H_icSPrintStr("[Knights Mill]");
        ////////////////////////
        H_icNameBool(AVX512_VPOPCNTDQ);
        H_icNameBool(AVX512_4FMAPS);
        H_icNameBool(AVX512_4VNNIW);

        H_icSPrintStr("[Cascade Lake]");
        ////////////////////////
        H_icNameBool(AVX512_VNNI);

        H_icSPrintStr("[Cooper Lake]");
        ////////////////////////
        H_icNameBool(AVX512_BF16);

        H_icSPrintStr("[Ice Lake]");
        ////////////////////////
        H_icNameBool(AVX512_VBMI2);
        H_icNameBool(GFNI);
        H_icNameBool(VAES);
        H_icNameBool(AVX512_VPCLMUL);
        H_icNameBool(AVX512_BITALG);
        size_t uLength = it - dst;
        ic_if_do(!dst, ++uLength); // 将末尾的空字符也计算在内，保证输出完整。
        return uLength;
    #undef H_icNameBool
    #undef H_icSPrintStr
    }
#endif