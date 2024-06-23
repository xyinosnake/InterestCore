
#pragma once

#include"../../Common/icCoreCommon.h"

ic_info("inline decs: Copy Move Memory")
    #define               icClearStruct(refStruct) icClearMemSize(&refStruct, sizeof(refStruct))
    ic_inl void   ic_call icClearMem(void_p bg, void_p ed) ic_noexc;
    ic_inl void   ic_call icClearMemSize(void_p dst, size_t btSz) ic_noexc;
    ic_inl void   ic_call icCopyMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc;
    ic_inl void   ic_call icMoveMemNoRet(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc;
    ic_inl void   ic_call icCopyMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc;
    ic_inl void   ic_call icMoveMemSizeNoRet(void_p dst, cvoid_p bg, size_t btSz) ic_noexc;
    ic_inl void_p ic_call icCopyMem(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc;
    ic_inl void_p ic_call icMoveMem(void_p dst, cvoid_p bg, cvoid_p ed) ic_noexc;
    ic_inl void_p ic_call icCopyMemSize(void_p dst, cvoid_p bg, size_t btSz) ic_noexc;
    ic_inl void_p ic_call icMoveMemSize(void_p dst, cvoid_p bg, size_t btSz) ic_noexc;
    ic_inl bool   ic_call icEqualMem(cvoid_p bg1, cvoid_p bg2, size_t btSz) ic_noexc;
    ic_inl bool   ic_call icSameMem(cvoid_p bg1, cvoid_p ed1, cvoid_p bg2, cvoid_p ed2) ic_noexc;
    ic_inl bool   ic_call icSameMemSize(cvoid_p bg1, size_t btSz1, cvoid_p bg2, size_t btSz2) ic_noexc;
    ic_inl bool   ic_call icMemStartsWithSize(cvoid_p pMemBg, size_t memBtSz, cvoid_p pWithBg, size_t withBtSz) ic_noexc;
    ic_inl bool   ic_call icMemStartsWith(cvoid_p pMemBg, cvoid_p pMemEd, cvoid_p pWithBg, cvoid_p pWithEd) ic_noexc;
    ic_inl void_p ic_call icInsertMem(void_p pos, void_p edOfData, void_p edOfCap, cvoid_p bg, cvoid_p ed, void_p* pNewMemEd ic_dfv(ic_null)) ic_noexc;

ic_info("decs: Copy Move Memory")
    ic_core_dcl void_p ic_call icInsertMemSize(void_p pos, void_p edOfData, void_p edOfCap, cvoid_p bg, size_t btSz, void_p* pNewMemEd ic_dfv(ic_null)) ic_noexc;

ic_info("inline decs: Alloc")
    ic_inl void_p ic_call icPosixAllocInl(size_t btSz) ic_noexc;
    ic_inl void   ic_call icPosixDeallocInl(void_p pMem) ic_noexc;
    ic_inl void_p ic_call icPosixReallocInl(void_p pMem, size_t btSz) ic_noexc;

ic_info("decs: Alloc")
    ic_core_dcl volatile ptrdiff_t* ic_call icGetAllocCountPtr() ic_noexc;
    ic_core_dcl void_p    ic_call icPosixAlloc(size_t btSz) ic_noexc;
    ic_core_dcl void      ic_call icPosixDealloc(void_p pMem) ic_noexc;
    ic_core_dcl void_p    ic_call icPosixRealloc(void_p pMem, size_t btSz) ic_noexc;
    ic_core_dcl void_p    ic_call icCountedPosixAlloc(size_t btSz) ic_noexc;
    ic_core_dcl void      ic_call icCountedPosixDealloc(void_p pMem) ic_noexc;
    ic_core_dcl void_p    ic_call icCountedPosixRealloc(void_p pMem, size_t btSz) ic_noexc;
    ic_inl      ptrdiff_t ic_call icGetAllocCount() ic_noexc;

ic_info("inline decs: P3")
    ic_inl void   ic_call icInitP3(IC_P3* pP3) ic_noexc;
    ic_inl size_t ic_call icSizeOfBytesP3(IC_P3* pP3) ic_noexc;
    ic_inl size_t ic_call icCapOfBytesP3(IC_P3* pP3) ic_noexc;
    ic_inl size_t ic_call icResOfBytesP3(IC_P3* pP3) ic_noexc;
    ic_inl void_p ic_call icBeginP3(IC_P3* pP3) ic_noexc;
    ic_inl void_p ic_call icEndP3(IC_P3* pP3) ic_noexc;
    ic_inl void   ic_call icClearP3(IC_P3* pP3) ic_noexc;
    ic_inl void   ic_call icEraseP3(IC_P3* pP3, void_p bg, void_p ed) ic_noexc;
    ic_inl void_p ic_call icPopP3(IC_P3* pP3, size_t btSzOfElem) ic_noexc;
    ic_inl bool   ic_call icIsEmptyP3(IC_P3* pP3) ic_noexc;
    ic_inl bool   ic_call icIsNullP3(IC_P3* pP3) ic_noexc;
    ic_inl void_p ic_call icInsertMemToP3(IC_P3* pP3, void_p pos, cvoid_p bg, cvoid_p ed, const IC_ALLOC* pAlloc) ic_noexc;

ic_info("decs: P3")
    ic_core_dcl void   ic_call icTakeP3(IC_P3* pP3, IC_P3* pTargetP3, ic_dealloc_f dealloc) ic_noexc;
    ic_core_dcl void   ic_call icDestroyP3(IC_P3* pP3, ic_dealloc_f dealloc) ic_noexc;
    ic_core_dcl void_p ic_call icReserveP3(IC_P3* pP3, size_t btCap, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icReserveResP3(IC_P3* pP3, size_t btRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icResizeP3(IC_P3* pP3, size_t btSz, size_t btMinRes, bool bMem0, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icShrinkP3(IC_P3* pP3, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icCreateP3(IC_P3* pP3, size_t btSz, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icCreateP3FromMem(IC_P3* pP3, cvoid_p bg, cvoid_p ed, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icInsertPlaceToP3(IC_P3* pP3, void_p pos, size_t btInsert, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icInsertMemSizeToP3(IC_P3* pP3, void_p pos, cvoid_p memBg, size_t memBtSz, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icAppendPlaceToP3(IC_P3* pP3, size_t btAppend, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icAppendMemToP3(IC_P3* pP3, cvoid_p bg, cvoid_p ed, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc;

ic_info("inline decs: P3 Obj")
    ic_inl size_t ic_call icSizeOfP3(IC_P3* pP3, size_t btSzOfObj) ic_noexc;
    ic_inl size_t ic_call icCapOfP3(IC_P3* pP3, size_t btSzOfObj) ic_noexc;
    ic_inl size_t ic_call icResOfP3(IC_P3* pP3, size_t btSzOfObj) ic_noexc;

ic_info("decs: P3 Obj")
    ic_core_dcl void   ic_call icEraseObjP3(IC_P3* pP3, void_p bg, void_p ed, size_t btSzOfObj, ic_destruct_f fDestructor) ic_noexc;
    ic_core_dcl void   ic_call icClearObjP3(IC_P3* pP3, size_t btSzOfObj, ic_destruct_f fDestructor) ic_noexc;
    ic_core_dcl void   ic_call icDestroyObjP3(IC_P3* pP3, size_t btSzOfObj, ic_destruct_f fDestructor, ic_dealloc_f dealloc) ic_noexc;
    ic_core_dcl void_p ic_call icResizeObjP3(IC_P3* pP3, size_t btSz, size_t btMinRes, const IC_CONSTRUCT* pConstruct, const IC_ALLOC* pAlloc) ic_noexc;

ic_info("inline decs: P4")
    ic_inl void   ic_call icInitP4(IC_P4* pP4) ic_noexc;
    ic_inl size_t ic_call icSizeOfBytesP4(IC_P4* pP4) ic_noexc;
    ic_inl size_t ic_call icCapOfBytesP4(IC_P4* pP4) ic_noexc;
    ic_inl size_t ic_call icLResOfBytesP4(IC_P4* pP4) ic_noexc;
    ic_inl size_t ic_call icRResOfBytesP4(IC_P4* pP4) ic_noexc;
    ic_inl size_t ic_call icResOfBytesP4(IC_P4* pP4) ic_noexc;
    ic_inl void_p ic_call icBeginP4(IC_P4* pP4) ic_noexc;
    ic_inl void_p ic_call icEndP4(IC_P4* pP4) ic_noexc;
    ic_inl void   ic_call icClearP4(IC_P4* pP4) ic_noexc;
    ic_inl void   ic_call icEraseP4(IC_P4* pP4, void_p bg, void_p ed) ic_noexc;
    ic_inl void_p ic_call icLPopP4(IC_P4* pP4, size_t btSzOfElem) ic_noexc;
    ic_inl void_p ic_call icRPopP4(IC_P4* pP4, size_t btSzOfElem) ic_noexc;
    #define               icPopP4 icRPopP4
    ic_inl bool   ic_call icIsEmptyP4(IC_P4* pP4) ic_noexc;
    ic_inl bool   ic_call icIsNullP4(IC_P4* pP4) ic_noexc;
    ic_inl void_p ic_call icInsertMemToP4(IC_P4* pP4, void_p pos, cvoid_p bg, cvoid_p ed, const IC_ALLOC* pAlloc) ic_noexc;

ic_info("decs: P4")
    ic_core_dcl void   ic_call icTakeP4(IC_P4* pP4, IC_P4* pTargetP4, ic_dealloc_f dealloc) ic_noexc;
    ic_core_dcl void   ic_call icDestroyP4(IC_P4* pP4, ic_dealloc_f dealloc) ic_noexc;
    ic_core_dcl void_p ic_call icShrinkP4(IC_P4* pP4, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icLShrinkP4(IC_P4* pP4, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icRShrinkP4(IC_P4* pP4, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icCreateP4(IC_P4* pP4, size_t btSz, size_t btLMinRes, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icCreateP4FromMem(IC_P4* pP4, cvoid_p bg, cvoid_p ed, size_t btLMinRes, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icReserveP4(IC_P4* pP4, size_t btCap, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icReserveResP4(IC_P4* pP4, size_t btLRes, size_t btRRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icResizeP4(IC_P4* pP4, size_t btSz, size_t btLMinRes, size_t btRMinRes, bool bMem0, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icInsertPlaceToP4(IC_P4* pP4, void_p pos, size_t btInsert, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icInsertMemSizeToP4(IC_P4* pP4, void_p pos, cvoid_p memBg, size_t memBtSz, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icLAppendPlaceToP4(IC_P4* pP4, size_t btLAppend, size_t btLMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icRAppendPlaceToP4(IC_P4* pP4, size_t btRAppend, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    #define                    icAppendPlaceToP4 icRAppendPlaceToP4
    ic_core_dcl void_p ic_call icLAppendMemToP4(IC_P4* pP4, cvoid_p bg, cvoid_p ed, size_t btLMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icRAppendMemToP4(IC_P4* pP4, cvoid_p bg, cvoid_p ed, size_t btRMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    #define                    icAppendMemToP4 icRAppendMemToP4
    //Not Fine! Need definitions!

ic_info("inline decs: P4 Obj")
    ic_inl size_t ic_call icSizeOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc;
    ic_inl size_t ic_call icCapOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc;
    ic_inl size_t ic_call icLResOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc;
    ic_inl size_t ic_call icRResOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc;
    ic_inl size_t ic_call icResOfP4(IC_P4* pP4, size_t btSzOfObj) ic_noexc;

ic_info("decs: P4 Obj")
    //Not Fine!

ic_info("inline decs: MixedSegBuf")
    ic_inl void   ic_call icInitMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc;
    ic_inl size_t ic_call icSizeOfBytesMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc;
    ic_inl size_t ic_call icCapOfBytesMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap) ic_noexc;
    ic_inl size_t ic_call icResOfBytesMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap) ic_noexc;
    ic_inl void_p ic_call icBeginMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc;
    ic_inl void_p ic_call icEndMixedP3(IC_MIXED_P3* pMixedP3) ic_noexc;
    ic_inl void   ic_call icDestroyMixedP3(IC_MIXED_P3* pMixedP3, ic_dealloc_f dealloc) ic_noexc;

ic_info("decs: MixedSegBuf")
    ic_core_dcl void_p ic_call icCreateMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, size_t btSz, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc;
    ic_core_dcl void_p ic_call icCreateMixedP3FromMem(IC_MIXED_P3* pMixedP3, size_t btStaticCap, cvoid_p bg, cvoid_p ed, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc;

#include"./P_icMemInline.h"
#include"./P_icP3Inline.h"
#include"./P_icP4Inline.h"
#include"./P_icMixedP3Inline.h"
