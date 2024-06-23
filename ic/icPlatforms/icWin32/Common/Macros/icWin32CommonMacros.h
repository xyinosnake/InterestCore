
#pragma once

#include"../../../../icCore/Common/Macros/icCoreCommonMacros.h"
#include"./icWin32Link.h"

ic_info("int")
	#define IC_WIN32_STR_FMT_ERR                -1
	#define IC_WIN32_CS_DEFAULT	  (CS_HREDRAW | CS_VREDRAW | CS_OWNDC)
	#define IC_WIN32_WS_DEFAULT	  WS_OVERLAPPEDWINDOW

ic_info("MsgFunc")
	#define icWin32RegMsgFunc(msg, fMsgFunc)      { msg, fMsgFunc }
	#define ic_win32_def_msg_map_infos(infosName) IC_WIN32_WND_MSG_MAP_INFO infosName[] =
	#define icWin32CountOfMsgMapInfos(infosName)  icArrayLen(infosName)

ic_info("WinMain")
	#define ic_win32_def_WinMain(hInstance, szCmdLine, iCmdShow)  int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR  szCmdLine, int iCmdShow)
	#define ic_win32_def_wWinMain(hInstance, szCmdLine, iCmdShow) int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR szCmdLine, int iCmdShow)

#ifdef IC_CE_MSC
	#pragma warning(disable: 28251) //禁用批注警告！
#endif