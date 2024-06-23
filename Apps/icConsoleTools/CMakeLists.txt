#[[
********************
* IC Console Tools *
********************
]]#

#required:
    cmake_minimum_required(VERSION 3.23.0) #topmost

#default value (must set before project)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel None.")
    set(CMAKE_INSTALL_PREFIX "C:/InterestCore/Apps/icConsoleTools" CACHE PATH "Install path prefix.")

#project & version:
    # cmake_policy(SET CMP0048 NEW) # enable project version
    project(icConsoleTools LANGUAGES C CXX)

#include path:
    include_directories(${PROJECT_BINARY_DIR})

#c/cpp standard:
    set(CMAKE_C_STANDARD   17)
    set(CMAKE_CXX_STANDARD 23)
	
#exe
	add_executable(ddep ./ddep.c)
	add_executable(dexp ./dexp.c)
	if(CMAKE_C_COMPILER_ID MATCHES "GNU | Clang")
		target_link_options(ddep PRIVATE -static)
		target_link_options(dexp PRIVATE -static)
	endif()
