
#pragma once

#include"../../../../icpp/icpp/icpp.h"
#include"../Macros/icConsoleToolsCommonMacros.h"
#include"../Types/icConsoleToolsCommonTypes.h"
#include"../Structs/icConsoleToolsCommonStructs.h"

ic_info("declarations")
    bool   ic_call icctCheckHelp(char** argv, int argc, const char* sHelp) ic_noexc;
    bool   ic_call icctInSet(const str_t& s, const set_t& ss);
    size_t ic_call icctGetMachine(const char* dllName) ic_noexc;
    bool   ic_call icctSplitPath(path_info_t& pi, const char* fullPath);

ic_info("definitions")
    bool ic_call icctCheckHelp(char** argv, int argc, const char* sHelp) ic_noexc {
        if (argc < 2) {
        Help:
            ic_do_and_return(fputs(sHelp, stdout), false);
        } else if (argc == 2) {
            ic_if_goto(strcmp(argv[1], "--help") == 0, Help)
        }
        return true;
    }

    bool ic_call icctInSet(const str_t& s, const set_t& ss) {
        return ss.find(s) != ss.end();
    }

    bool ic_call icctSplitPath(path_info_t& pi, const char* fullPath) {
    #if defined(IC_OS_WINDOWS)
        #define max_c 1024
            char drive   [max_c];
            char dir     [max_c];
            char fileName[max_c];
            char ext     [max_c];
            bool b = (_splitpath_s(fullPath, drive, max_c, dir, max_c, fileName, max_c, ext, max_c) == 0);
            ic_if_do(b, ic_sg(pi = { drive, dir, fileName, ext }));
            return b;
        #undef max_c
    #else
        return -1;
    #endif
    }

    size_t ic_call icctGetMachine(const char* dllName) ic_noexc {
    #if defined(IC_OS_WINDOWS)
        uint8_t buf[4];  
        FILE *fp = fopen(dllName, "rb");  
        fseek(fp, 0x40-4, 0);  
        fread(buf, sizeof(char), 4, fp);  
        int a = int(buf[0]);  
        int b = int(buf[1]) * 256;  
        int c = int(buf[2]) * 256 * 256;  
        int d = int(buf[3]) * 256 * 256 * 256;
        int sum = a + b + c + d;
        fseek(fp, sum + 4, 0);
        uint8_t bufMachine[2];
        fread(bufMachine, sizeof(char), 2, fp);
        int machine = (int)bufMachine[0] + (int)(bufMachine[1]) * 256;
        ic_if_return(machine == 0x14C,  32) //332   -> 32
        ic_if_return(machine == 0x8664, 64) //34404 -> 64
        return 0;
    #else
        return 0;
    #endif
    }
