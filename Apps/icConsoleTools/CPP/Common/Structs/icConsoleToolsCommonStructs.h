
#pragma once

#include"../Types/icConsoleToolsCommonTypes.h"

ic_info("declarations")
    struct path_info_t;

ic_info("Structs")
    struct path_info_t {
        str_t drive;
        str_t dir;
        str_t fileName;
        str_t ext;
    };