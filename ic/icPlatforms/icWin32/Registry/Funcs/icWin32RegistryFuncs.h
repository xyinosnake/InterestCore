
#pragma once

#include"../../Common/Macros/icWin32CommonMacros.h"
#include"../../icWin32Headers.h"

ic_info("declarations")
    ic_win32_dcl BOOL ic_call icWin32RegOpenCmdW(
        LPWSTR lpszExtName,       //Eg: .txt
        LPWSTR lpszFileTypeName,  //Eg: txtfile
        LPWSTR lpszCommandString, //Eg: "D:\Program Files\CodeEditor\CodeEditor.exe" "%1"
        LPWSTR lpszIconString     ic_dfv(NULL)
        //Eg1: C:\Windows\System\xxx.dll,1/*/
        //Eg2: C:\Icons\xxx.ico/*/
    ) ic_noexc;

    ic_win32_dcl BOOL ic_call icWin32RegOpenCmdA(
        LPSTR lpszExtName,       //Eg: .txt
        LPSTR lpszFileTypeName,  //Eg: txtfile
        LPSTR lpszCommandString, //Eg: "D:\Program Files\CodeEditor\CodeEditor.exe" "%1"
        LPSTR lpszIconString     ic_dfv(NULL)
        //Eg1: C:\Windows\System\xxx.dll,1/*/
        //Eg2: C:\Icons\xxx.ico/*/
    ) ic_noexc;