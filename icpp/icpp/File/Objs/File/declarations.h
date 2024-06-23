
#pragma once

#include"../declarations.h"

ic_info("declarations")
    class icppFile {
    public:
        ic_inl bool     ic_call destroy() ic_noexc;
        ic_inl bool     ic_call write(const void* pData, size_t btSz) ic_noexc;
        ic_inl bool     ic_call read(void* pData, size_t btSz) ic_noexc;
        ic_inl uint64_t ic_call size() ic_noexc;
        ic_inl uint64_t ic_call getPos() ic_noexc;
        ic_inl bool     ic_call setPos(uint64_t uBtPos) ic_noexc;
        ic_inl bool     ic_call flush() ic_noexc;
    private:
        icppFile() = delete;
        ~icppFile() = delete;
    };