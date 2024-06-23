
#pragma once

#include"./declarations.h"
#include"../../Funcs/icppFileFuncs.h"

ic_info("definitions")
    ic_inl bool ic_call icppFile::destroy() ic_noexc {
        return icDestroyFile((ic_file_h)this);
    }

    ic_inl bool ic_call icppFile::write(const void* pData, size_t btSz) ic_noexc {
        return icWriteFile((ic_file_h)this, pData, btSz);
    }

    ic_inl bool ic_call icppFile::read(void* pData, size_t btSz) ic_noexc {
        return icReadFile((ic_file_h)this, pData, btSz);
    }

    ic_inl uint64_t ic_call icppFile::size() ic_noexc {
        return icSizeOfFile((ic_file_h)this);
    }

    ic_inl uint64_t ic_call icppFile::getPos() ic_noexc {
        return icGetFilePos((ic_file_h)this);
    }

    ic_inl bool ic_call icppFile::setPos(uint64_t uBtPos) ic_noexc {
        return icSetFilePos((ic_file_h)this, uBtPos);
    }

    ic_inl bool ic_call icppFile::flush() ic_noexc {
        return icFlushFile((ic_file_h)this);
    }
