
#ifndef IC_CORE_BASICS_FUNCS
#define IC_CORE_BASICS_FUNCS
    
#include"./icCoreCommonFuncs.h"
#include"../../MicroPlatforms/icCoreMicroPlatforms.h"

ic_info("ic_decs")
    ic_core_dcl void ic_call icYellHereIf(bool b, cch8_p Msg, cch8_p FuncName, cch8_p moduleName, cch8_p FileName, int LineNumber) ic_noexc {
        if (b) {
    #if defined(IC_OS_WINDOWS)
            icMicroWin32Yell(Msg, FuncName, FileName, moduleName, LineNumber);
    #elif defined(IC_OS_UNIX_LIKE)
            icMicroUnixYell(Msg, FuncName, FileName, moduleName, LineNumber);
    #endif
        }
    }

    ic_core_dcl void ic_call icInfoBase(bool bColored) ic_noexc {
        cch8_p icInfoStr = bColored ?
            icInterestCoreInfo(icCmdClr(255, 255, 0, 0, 64, 0), icCmdClrReset()):
            icInterestCoreInfo("", "");
        fprintf(stdout, "%s", icInfoStr);
    }

    ic_core_dcl void ic_call icHelloBase(bool bColored, cch8_p name, cch8_p dep) ic_noexc {
        // 红 \x1B[38;2;255;0;0m
        // 黄 \x1B[38;2;255;255;0m
        // 紫 \x1B[38;2;255;0;255m
        // 蓝 \x1B[38;2;0;0;255m
        // 绿 \x1B[38;2;0;255;0m
        // 默 \x1B[39m
        // Bg \x1B[49...
        cch8_p sFm = bColored ? 
            icCmdBgClr(0, 0, 128) icCmdFgClr(16, 255, 16) "[%s" icCmdFgClr(16, 255, 16) "]" icCmdClrReset() "\r\n    Hello, I'm %s!\r\n "
            icCmdBgClr(0, 0, 128) icCmdFgClr(8,  255,  8) "Dependences" icCmdClrReset() "\r\n    " icCmdFgClr(255, 64, 64) "-> %s\r\n\r\n":
            "[%s] Hello, I'm %s!\r\n Dependences\r\n    -> %s\r\n\r\n";
        fprintf(stdout, sFm, name, name, dep);
    }

    ic_core_dcl void ic_call icCoreHello(ic_hello_flags_e flags) ic_noexc {
        bool bColored = (icGetBit(icGetInitFlags(), ic_itf_console_color_v) != 0);
        ic_if_do(icGetBit(flags, ic_hf_ic_info_v), icInfoBase(bColored));
        if (icGetBit(flags, ic_hf_current_info_v)) {
            cch8_p name, dep;
            ic_if_else_do_x2(bColored,
                name = icCoreNameColored(), dep = icCoreDepColored(),
                name = icCoreName(),        dep = icCoreDep());
            icHelloBase(bColored, name, dep);
        }
        fflush(stdout);
    }

    ic_hide uint32_t g_icInitFlags = 0;
    ic_core_dcl bool ic_call icCoreEnable(ic_init_flags_e flags) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return icMicroWin32CoreEnable(flags) == TRUE;
    #elif defined(IC_OS_UNIX_LIKE)
        icSetBits(g_icInitFlags, icGetBits(flags, ic_itf_core_default_v));
        return true;
    #else
        return false;
    #endif
    }

    ic_core_dcl bool ic_call icCoreDisable(ic_init_flags_e flags) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        return icMicroWin32CoreDisable(flags) == TRUE;
    #elif defined(IC_OS_UNIX_LIKE)
        icClearBits(g_icInitFlags, icGetBits(flags, ic_itf_core_default_v));
        return true;
    #else
        return false;
    #endif
    }

    ic_core_dcl bool ic_call icCoreInit(ic_init_flags_e flags) ic_noexc {
        return icCoreEnable(flags);
    }

    ic_core_dcl bool ic_call icCoreUninit() ic_noexc {
        return icCoreDisable((ic_init_flags_e)g_icInitFlags);
    }

    ic_core_dcl uint32_t* ic_call icGetInitFlagsPtr() ic_noexc {
        return &g_icInitFlags;
    }

    ic_inl uint64_t ic_call H_icDivModVer(uint64_t* pNum, uint64_t dmVal) ic_noexc {
        uint64_t val = *pNum;
        *pNum = val / dmVal;
        return val % dmVal;
    }

    ic_core_dcl IC_VER ic_call icGetVersion() ic_noexc {
        IC_VER   ver;
        uint64_t vn = IC_VER_NUMBER;
        ver.build = (uint32_t)H_icDivModVer(&vn, 1000000);
        ver.patch = (uint8_t )H_icDivModVer(&vn, 100);
        ver.minor = (uint8_t )H_icDivModVer(&vn, 100);
        ver.major = (uint16_t)vn;
        return ver;
    }

    ic_core_dcl void ic_call icAssert(bool b, cch8_p condStr, cch8_p msg, cch8_p funcName, cch8_p moduleName, cch8_p fileName, size_t lineNum, cch8_p timeStamp) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        icMicroWin32Assert(b, condStr, msg, funcName, moduleName, fileName, lineNum, timeStamp);
    #elif defined(IC_OS_UNIX_LIKE)
        icMicroUnixAssert(b, condStr, msg, funcName, moduleName, fileName, lineNum, timeStamp);
    #else
        assert(b);
    #endif
    }

    ic_core_dcl void ic_call icOperateObjRange(void_p pObjBg, void_p pObjEd, size_t btSzOfObj, ic_operate_f fOperator) ic_noexc {
        while(pObjBg != pObjEd) {
            fOperator(pObjBg);
            pObjBg = icAddPtr(pObjBg, btSzOfObj);
        }
    }
#endif