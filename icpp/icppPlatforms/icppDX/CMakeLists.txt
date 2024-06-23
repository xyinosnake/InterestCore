
#[[
******************icpp [D]irect[X]*******************
*   This file is made by Xyino Snake.               *
*   All under GPL v3 licence. See "GNU-GPL-v3.txt". *
*   Copyleft, all lefts released.                   *
*****************************************************
]]#

#required:
    cmake_minimum_required(VERSION 3.23.0) #topmost

#default value (must set before project)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel None.")
    set(CMAKE_INSTALL_PREFIX "C:/InterestCore" CACHE PATH "Install path prefix.")

#project & version:
    # cmake_policy(SET CMP0048 NEW) # enable project version
    project(icppDX LANGUAGES CXX)

#assertion:
	if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		message(FATAL_ERROR "This project must be compiled with MSVC!")
	endif()

#include path:
    include_directories(${PROJECT_BINARY_DIR})

#c/cpp standard:
    set(CMAKE_CXX_STANDARD 20)
	
#compile_options:
	if(CMAKE_BUILD_TYPE STREQUAL "Release")
		add_compile_options("/MT")
	endif()

#options
    option(icppDXC     "Generate icppDXC shared lib." ON)
    option(icppWIC     "Generate icppWIC shared lib." ON)
	option(icppDWrite  "Generate icppDWrite shared lib." ON)
	option(icppD2D     "Generate icppD2D shared lib." ON)
    #option(icppDInput  "Generate icppDInput shared lib." ON)
    #option(icppXAudio2 "Generate icppXAudio2 shared lib." ON)

#icppDX
    add_library(icppDXC SHARED ./icppDXC/icppDXC-Shared.cpp)
	target_link_libraries(icppDXC PRIVATE icCore icWin32 ic icpp DXGI)
	
	add_library(icppWIC SHARED ./icppWIC/icppWIC-Shared.cpp)
	target_link_libraries(icppWIC PRIVATE icCore icWin32 ic icpp icppDXC DXGI Windowscodecs)

	add_library(icppDWrite SHARED ./icppDWrite/icppDWrite-Shared.cpp)
	target_link_libraries(icppDWrite PRIVATE icCore icWin32 ic icpp icppDXC DXGI DWrite)
	
	add_library(icppD2D SHARED ./icppD2D/icppD2D-Shared.cpp)
	target_link_libraries(icppD2D PRIVATE icCore icWin32 ic icpp icppDXC icppWIC icppDWrite DXGI Windowscodecs DWrite D2D1)
	
	add_library(icppDInput SHARED ./icppDInput/icppDInput-Shared.cpp)
	target_link_libraries(icppDInput PRIVATE icCore icWin32 ic icpp dinput8 dxguid uuid)
	
	add_library(icppXAudio2 SHARED ./icppXAudio2/icppXAudio2-Shared.cpp)
	target_link_libraries(icppXAudio2 PRIVATE icCore icWin32 ic icpp xaudio2_9redist xapobaseredist)

#std names
    #set_target_properties(icppDXC PROPERTIES OUTPUT_NAME "icppDXC")

#install
    install(TARGETS icppDXC     LIBRARY)
	install(TARGETS icppWIC     LIBRARY)
	install(TARGETS icppDWrite  LIBRARY)
	install(TARGETS icppD2D     LIBRARY)
	install(TARGETS icppDInput  LIBRARY)
	install(TARGETS icppXAudio2 LIBRARY)
	#install(TARGETS XX-Static ARCHIVE)

#[[
Diff CE Comp:
    CMAKE_CXX_COMPILER_ID (STREQUAL || MATCHES)
        "MSVC" "Clang" "GNU" "GNU | Clang"

Install:
    install(TARGETS my_executable DESTINATION bin)
    install(TARGETS my_executable RUNTIME DESTINATION bin)

    目标没有指定类型（如 LIBRARY 或 ARCHIVE），CMake 会假定目标是可执行文件。
        RUNTIME：.exe       可执行文件。
        LIBRARY：.dll | .so 库文件（动态库与对应的关联静态库）。
        ARCHIVE：.lib | .a  静态库。
]]#