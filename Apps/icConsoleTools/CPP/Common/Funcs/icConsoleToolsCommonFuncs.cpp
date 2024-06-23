
#pragma once

#include<map>
#include<set>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cstdint>

//Macros
#define MAIN(argv, argc)    int main(int argc, char* argv[]) noexcept

//Types
using str_t = ::std::string;
using map_t = ::std::map<str_t, str_t>;
using set_t = ::std::set<str_t>;
using vec_t = ::std::vector<str_t>;

//Structs
struct path_info_t {
    str_t drive;
    str_t dir;
    str_t fileName;
    str_t ext;
};

//Funcs Decs
bool   checkHelp(char** argv, int argc, const char* sHelp) noexcept;
bool   inSet(const str_t& s, const set_t& ss);
size_t getMachine(const char* dllName) noexcept;

//Funcs Defs
bool checkHelp(char** argv, int argc, const char* sHelp) noexcept {
    if (argc < 2) {
    Help:
        fputs(sHelp, stdout);
        return false;
    } else if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            goto Help;
        }
    }
    return true;
}

bool inSet(const str_t& s, const set_t& ss) {
    return ss.find(s) != ss.end();
}

errno_t splitPath(path_info_t& pi, const char* fullPath) {
    const int max_c = 1024;
    char drive[max_c];
    char dir[max_c];
    char fileName[max_c];
    char ext[max_c];
    auto e = _splitpath_s(fullPath, drive, max_c, dir, max_c, fileName, max_c, ext, max_c);
    if (!e) {
        pi = { drive, dir, fileName, ext };    
    }
    return e;
}

size_t getMachine(const char* dllName) noexcept {
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
    if(machine == 0x14C) { //332
        return 32;
    } else if(machine == 0x8664) { //34404
        return 64;
    }
    return 0;  
}
