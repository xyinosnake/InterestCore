
#pragma once

#include"./icCoreMemoryFuncs.h"

/*
说明：
    再三思研，IC_MIXED_P3变成了现在的形式。
只要ptr[0] != ic_null，那么MixedP3就是动态分配的，与P3等效（ptr[0]是数据位置），而distance和buffer都是无效且禁止使用的。
如果ptr[0] == ic_null，那么MixedP3就是静态的。distance是数据长度，btStaticCap即数据容量，buffer是数据位置。
    这样做的好处是可以随意移动该结构体，也可以将结构体作为返回值返回。
*/

//definitions
//MixedSegBuf

ic_core_dcl void* ic_call icCreateMixedP3(IC_MIXED_P3* pMixedP3, size_t btStaticCap, size_t btSz, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc {
    void** pp       = pMixedP3->ptr;
    void*  p0       = pp[0];
    size_t btNewCap = btSz + btMinRes;
    if (btStaticCap >= btNewCap) { //静态容量充足
        if (p0) {
            pAlloc->dealloc(p0); //如果原MixedP3是动态分配的，就释放动态内存
            pp[0] = ic_null;        //转变为静态
        }
        pMixedP3->distance = btSz; //重置（设置）尺寸
        return pMixedP3->buffer; //返回静态数据位置
    } //静态容量不足
    if (p0) { //原MixedP3是动态分配的
        void*  p2       = pp[2];
        size_t btOldCap = icPtrDiffU(p0, p2); //计算btOldCap
        ic_if_do_and_return(btOldCap >= btNewCap, pp[1] = icAddPtr(p0, (ptrdiff_t)btSz), p0); //容量足够，仅重设尺寸
        pAlloc->dealloc(p0); //容量不足，释放动态内存
    } //并轨，原MixedP3是静态的
    void* new_p0 = pAlloc->alloc(btNewCap);
    if (!new_p0) {
        pp[0] = ic_null;
        pp[1] = ic_null;
        return ic_null;
    }
    pp[0] = new_p0;
    pp[1] = icAddPtr(new_p0, (ptrdiff_t)btSz);
    pp[2] = icAddPtr(new_p0, (ptrdiff_t)btNewCap);
    return new_p0;
}

ic_core_dcl void* ic_call icCreateMixedP3FromMem(IC_MIXED_P3* pMixedP3, size_t btStaticCap, const void* bg, const void* ed, size_t btMinRes, const IC_ALLOC* pAlloc) ic_noexc {
    size_t btSz  = icPtrDiffU(bg, ed);
    void*  pData = icCreateMixedP3(pMixedP3, btStaticCap, btSz, btMinRes, pAlloc);
    ic_if_goto(!pData, posEnd);
    icCopyMemSizeNoRet(pData, bg, btSz);
    ic_label_return(posEnd, pData);
}