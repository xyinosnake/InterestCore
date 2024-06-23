
#ifndef ICCT_COMMON_FUNCS
#define ICCT_COMMON_FUNCS

#include"./icctCommonFuncs.h"

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
#endif