
#pragma once

#include"../Macros/icCoreCommonMacros.h"
#include"../Types/icCoreCommonTypes.h"
#include"../Enums/icCoreCommonEnums.h"
#include"../Structs/icCoreCommonStructs.h"
#include"../../MicroPlatforms/Funcs/icCoreMicroPlatformsFuncs.h"

ic_info("icInterestCoreInfo")
    #define icInterestCoreInfo(clr, clrReset) \
        clr "* * * * * * * * * [I]nterest [C]ore * * * * * * * * *" clrReset "\r\n"\
        clr "* INTEREST CORE                                     *" clrReset "\r\n"\
        clr "*     Made by Xyino Snake(XYS).                     *" clrReset "\r\n"\
        clr "*     Use GPL-v3 as license.                        *" clrReset "\r\n"\
        clr "*     Copyleft[GPL-v3]. All lefts released.         *" clrReset "\r\n"\
        clr "* * * * * * * * * * * * * * * * * * * * * * * * * * *" clrReset "\r\n\r\n"

ic_info("icCoreName & icCoreDep")
    #define icCoreName()        "icCore"
    #define icCoreNameColored() icCmdFgClr(255, 96, 96) icCoreName() icCmdFgClrReset()
    #define icCoreDep()         icCoreName() "()"
    #define icCoreDepColored()  icCoreNameColored() icCmdFgClr(64, 255, 64) "()" icCmdFgClrReset()

ic_info("decs")
    #define                       icValInItv(value, left, right)        ((value) >= (left) && (value) < (right))
    #define                       icValInClosedItv(value, left, right)  ((value) >= (left) && (value) <= (right))
    #define                       icSetBits(v, mask)                    ((v) |= (mask))
    #define                       icClearBits(v, mask)                  ((v) &= ~(mask))
    #define                       icSetOrClearBits(b, v, mask)          ((v) = (b) ? ((v) | (mask)) : ((v) & ~(mask)))
    #define                       icGetBits(v, mask)                    ((v) & (mask))
    #define                       icGetBit                              icGetBits
    #define                       icArrayLen(Array)                     (sizeof(Array) / sizeof((Array)[0]))
    #define                       icConstructObjRange(pObjBg, pObjEd, btSzOfObj, fConstructor) icOperateObjRange(pObjBg, pObjEd, btSzOfObj, fConstructor)
    #define                       icDestructObjRange(pObjBg, pObjEd, btSzOfObj, fDestructor)   icOperateObjRange(pObjBg, pObjEd, btSzOfObj, fDestructor)
    ic_core_dcl void      ic_call icInfoBase(bool bColored) ic_noexc;
    ic_core_dcl void      ic_call icHelloBase(bool bColored, cch8_p name, cch8_p dep) ic_noexc;
    ic_core_dcl void      ic_call icCoreHello(ic_hello_flags_e flags ic_dfv(ic_hf_default_v)) ic_noexc;
    ic_core_dcl bool      ic_call icCoreEnable (ic_init_flags_e flags) ic_noexc;
    ic_core_dcl bool      ic_call icCoreDisable(ic_init_flags_e flags) ic_noexc;
    ic_core_dcl bool      ic_call icCoreInit(ic_init_flags_e flags ic_dfv(ic_itf_core_default_v)) ic_noexc;
    ic_core_dcl bool      ic_call icCoreUninit() ic_noexc;
    ic_core_dcl uint32_t* ic_call icGetInitFlagsPtr() ic_noexc;
    ic_core_dcl IC_VER    ic_call icGetVersion() ic_noexc;
    ic_core_dcl void      ic_call icYellHereIf(bool b, cch8_p Msg, cch8_p FuncName, cch8_p moduleName, cch8_p FileName, int LineNumber) ic_noexc;
    ic_core_dcl void      ic_call icAssert(bool b, cch8_p condStr, cch8_p msg, cch8_p funcName, cch8_p moduleName, cch8_p fileName, size_t lineNum, cch8_p timeStamp) ic_noexc;
    ic_core_dcl void      ic_call icOperateObjRange(void_p pObjBg, void_p pObjEd, size_t btSzOfObj, ic_operate_f fOperator) ic_noexc;
    ic_inl      uint32_t  ic_call icGetInitFlags() ic_noexc;
    ic_inl      ptrdiff_t ic_call icPtrDiff (cvoid_p bg, cvoid_p ed) ic_noexc;
    ic_inl      size_t    ic_call icPtrDiffU(cvoid_p bg, cvoid_p ed) ic_noexc;
    ic_inl      void_p    ic_call icAddPtr(cvoid_p bg, ptrdiff_t btsz) ic_noexc;
    ic_inl      void_p    ic_call icSubPtr(cvoid_p bg, ptrdiff_t btsz) ic_noexc;
    ic_inl      ptrdiff_t ic_call icObjPtrDiff (cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc;
    ic_inl      size_t    ic_call icObjPtrDiffU(cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc;
    ic_inl      void_p    ic_call icAddObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc;
    ic_inl      void_p    ic_call icSubObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc;
    ic_inl      flo32_t   ic_call icBinF32(uint32_t u) ic_noexc;
    ic_inl      flo64_t   ic_call icBinF64(uint64_t u) ic_noexc;
    ic_inl      ptrdiff_t ic_call icLockedInc(volatile ptrdiff_t* pI) ic_noexc;
    ic_inl      size_t    ic_call icLockedIncU(volatile size_t* pU) ic_noexc;
    ic_inl      ptrdiff_t ic_call icLockedDec(volatile ptrdiff_t* pI) ic_noexc;
    ic_inl      size_t    ic_call icLockedDecU(volatile size_t* pU) ic_noexc;

ic_info("inlines")
    ic_inl uint32_t ic_call icGetInitFlags() ic_noexc {
        return *icGetInitFlagsPtr();
    }

    ic_inl ptrdiff_t ic_call icPtrDiff(cvoid_p bg, cvoid_p ed) ic_noexc {
        return (ptrdiff_t)ed - (ptrdiff_t)bg;
    }

    ic_inl size_t ic_call icPtrDiffU(cvoid_p bg, cvoid_p ed) ic_noexc {
        return (size_t)ed - (size_t)bg;
    }

    ic_inl void_p ic_call icAddPtr(cvoid_p bg, ptrdiff_t btsz) ic_noexc {
        return (void_p)((ptrdiff_t)bg + btsz);
    }

    ic_inl void_p ic_call icSubPtr(cvoid_p bg, ptrdiff_t btsz) ic_noexc {
        return (void_p)((ptrdiff_t)bg - btsz);
    }

    ic_inl ptrdiff_t ic_call icObjPtrDiff(cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc {
        return icPtrDiff(bg, ed) / (ptrdiff_t)btSzOfObj;
    }

    ic_inl size_t ic_call icObjPtrDiffU(cvoid_p bg, cvoid_p ed, size_t btSzOfObj) ic_noexc {
        return icPtrDiffU(bg, ed) / btSzOfObj;
    }

    ic_inl void_p ic_call icAddObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc {
        return icAddPtr(bg, btSzOfObj * sz);
    }

    ic_inl void_p ic_call icSubObjPtr(cvoid_p bg, ptrdiff_t sz, size_t btSzOfObj) ic_noexc {
        return icSubPtr(bg, btSzOfObj * sz);
    }

    ic_inl flo32_t ic_call icBinF32(uint32_t u) ic_noexc {
        return *(flo32_t*)&u;
    }

    ic_inl flo64_t ic_call icBinF64(uint64_t u) ic_noexc {
        return *(flo64_t*)&u;
    }

    ic_inl ptrdiff_t ic_call icLockedInc(volatile ptrdiff_t* pI) ic_noexc {
        #if defined(IC_OS_WINDOWS)
            return icMicroWin32LockedInc(pI);
        #elif defined(IC_OS_UNIX_LIKE)
            return icMicroUnixLockedInc(pI);
        #else
            return 0;
        #endif
    }

    ic_inl size_t ic_call icLockedIncU(volatile size_t* pU) ic_noexc {
        return (size_t)icLockedInc((volatile ptrdiff_t*)pU);
    }

    ic_inl ptrdiff_t ic_call icLockedDec(volatile ptrdiff_t* pI) ic_noexc {
        #if defined(IC_OS_WINDOWS)
            return icMicroWin32LockedDec(pI);
        #elif defined(IC_OS_UNIX_LIKE)
            return icMicroUnixLockedDec(pI);
        #else
            return 0;
        #endif
    }

    ic_inl size_t ic_call icLockedDecU(volatile size_t* pU) ic_noexc {
        return (size_t)icLockedDec((volatile ptrdiff_t*)pU);
    }
