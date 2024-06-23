
#[[
******************[I]nterest*[C]ore******************
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
    project(InterestCore LANGUAGES C CXX)
    string(TIMESTAMP IC_COMPILE_TIME   "%Y.%m.%d-%H.%M.%S") #IC_COMPILE_TIME
    string(TIMESTAMP IC_VER_NUMBER     "%Y%m%d%H%M%S")      #IC_VER_NUMBER(years, months, days, time)
    string(TIMESTAMP IC_VER_STRING     "%Y.%m.%d.%H%M%S")   #IC_VER_STRING(years, months, days, time)

#config:
    configure_file(./ic/ic-Config.h.in ic-Config.h)

#copy include files
    file(COPY "${PROJECT_SOURCE_DIR}/ic"        DESTINATION "${CMAKE_BINARY_DIR}/include/InterestCore")
    file(COPY "${CMAKE_BINARY_DIR}/ic-Config.h" DESTINATION "${CMAKE_BINARY_DIR}/include/InterestCore/ic/icCore/Common/Macros")
    file(COPY "${PROJECT_SOURCE_DIR}/icpp"      DESTINATION "${CMAKE_BINARY_DIR}/include/InterestCore")

#include path:
    include_directories(${PROJECT_BINARY_DIR})

#c/cpp standard:
    set(CMAKE_C_STANDARD   17)
    set(CMAKE_CXX_STANDARD 23)

#options
    option(icCore-Static "Generate icCore static lib." ON)
    option(icCore        "Generate icCore shared lib." ON)
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        option(icWin32-Static     "Generate icWin32 static lib."     ON)
        option(icWin32            "Generate icWin32 shared lib."     ON)
    elseif(UNIX)
        option(icUnix-Static      "Generate icUnix static lib."     ON)
        option(icUnix             "Generate icUnix shared lib."     ON)
    endif()
    option(ic-Static     "Generate ic static lib."     ON)
    option(ic            "Generate ic shared lib."     ON)

#icCore
    add_library(icCore-Static STATIC ./ic/icCore/icCore-Static.c)
    add_library(icCore        SHARED ./ic/icCore/icCore-Shared.c)
    #target_compile_definitions(icCore PRIVATE IC_CORE_STATIC_IMPORT) shared link static
    #target_link_libraries     (icCore PRIVATE icCore-Static)

#icWin32 | icUnix
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        add_library(icWin32-Static STATIC ./ic/icPlatforms/icWin32/icWin32-Static.c)
        add_library(icWin32        SHARED ./ic/icPlatforms/icWin32/icWin32-Shared.c)
        target_link_libraries(icWin32-Static PRIVATE icCore)
        target_link_libraries(icWin32        PRIVATE icCore)
    elseif(UNIX)
        add_library(icUnix-Static STATIC ./ic/icPlatforms/icUnix/icUnix-Static.c)
        add_library(icUnix        SHARED ./ic/icPlatforms/icUnix/icUnix-Shared.c)
        target_link_libraries(icUnix-Static PRIVATE icCore)
        target_link_libraries(icUnix        PRIVATE icCore)
    endif()

#ic
    add_library(ic-Static STATIC ./ic/ic/ic-Static.c)
    add_library(ic        SHARED ./ic/ic/ic-Shared.c)
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        target_link_libraries(ic-Static PRIVATE icCore icWin32)
        target_link_libraries(ic        PRIVATE icCore icWin32)
    elseif(UNIX)
        target_link_libraries(ic-Static PRIVATE icCore icUnix)
        target_link_libraries(ic        PRIVATE icCore icUnix)
    endif()

#icpp
    add_library(icpp-Static STATIC ./icpp/icpp/icpp-Static.cpp)
    add_library(icpp        SHARED ./icpp/icpp/icpp-Shared.cpp)
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        target_link_libraries(icpp-Static PRIVATE icCore icWin32 ic)
        target_link_libraries(icpp        PRIVATE icCore icWin32 ic)
    elseif(UNIX)
        target_link_libraries(icpp-Static PRIVATE icCore icUnix ic)
        target_link_libraries(icpp        PRIVATE icCore icUnix ic)
    endif()

#GNU VersionScript
    if(CMAKE_C_COMPILER_ID MATCHES "GNU")
        message(STATUS "InterestCore: GCC detected.")
        target_link_options(icCore PRIVATE -Wl,--version-script,./include/InterestCore/ic/ic-VersionScript.txt)
        target_link_options(ic     PRIVATE -Wl,--version-script,./include/InterestCore/ic/ic-VersionScript.txt)
        if(CMAKE_SYSTEM_NAME MATCHES "Windows")
            target_link_options(icWin32 PRIVATE -Wl,--version-script,./include/InterestCore/ic/ic-VersionScript.txt)
        elseif(UNIX)
            target_link_options(iUnix   PRIVATE -Wl,--version-script,./include/InterestCore/ic/ic-VersionScript.txt)
        endif()
    endif()

#std names
    set_target_properties(icCore        PROPERTIES OUTPUT_NAME "icCore")
    set_target_properties(icCore-Static PROPERTIES OUTPUT_NAME "icCore-Static")
    set_target_properties(ic            PROPERTIES OUTPUT_NAME "ic")
    set_target_properties(ic-Static     PROPERTIES OUTPUT_NAME "ic-Static")
    set_target_properties(icpp          PROPERTIES OUTPUT_NAME "icpp")
    set_target_properties(icpp-Static   PROPERTIES OUTPUT_NAME "icpp-Static")

#diff os
    set_target_properties(icCore PROPERTIES PREFIX "")
    set_target_properties(ic     PROPERTIES PREFIX "")
    set_target_properties(icpp   PROPERTIES PREFIX "")
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        set_target_properties(icWin32 PROPERTIES PREFIX "")
    elseif(UNIX)
        set_target_properties(icUnix PROPERTIES PREFIX "")
    endif()
    if(CMAKE_SYSTEM_NAME MATCHES "Windows" AND NOT CMAKE_C_COMPILER_ID MATCHES "GNU") #For .a hold lib*.a style.
        set_target_properties(icCore-Static PROPERTIES PREFIX "")
        set_target_properties(ic-Static     PROPERTIES PREFIX "")
        set_target_properties(icpp-Static   PROPERTIES PREFIX "")
    endif()

#install
    install(TARGETS icCore-Static ARCHIVE)
    install(TARGETS icCore        LIBRARY)
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        install(TARGETS icWin32-Static ARCHIVE)
        install(TARGETS icWin32        LIBRARY)
    elseif(UNIX)
        install(TARGETS icUnix-Static ARCHIVE)
        install(TARGETS icUnix        LIBRARY)
    endif()
    install(TARGETS ic-Static     ARCHIVE)
    install(TARGETS ic            LIBRARY)
    install(TARGETS icpp-Static   ARCHIVE)
    install(TARGETS icpp          LIBRARY)

    install(DIRECTORY "${CMAKE_BINARY_DIR}/include/InterestCore" DESTINATION "${CMAKE_INSTALL_PREFIX}/include")

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