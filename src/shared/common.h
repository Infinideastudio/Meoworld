/*
* Meoworld: A 2D sandbox game which can create anything and travel around universe.
* Copyright (C) 2016 Meoworld Team
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef COMMON_H_
#define COMMON_H_

// Compiler flags
#ifdef _MSC_VER
    #define MEOWORLD_COMPILER_MSVC
#endif

// OS flags
#if defined _WIN32 || defined __CYGWIN__
    #define MEOWORLD_TARGET_WINDOWS
    #define MEOWORLD_USE_WINAPI // Windows native API
#else
    //#    define Meoworld_TARGET_LINUX
    //#    define Meoworld_TARGET_MACOSX
#endif

#ifdef _DEBUG
    #define MEOWORLD_DEBUG // Main debug flag
#endif

#ifdef MEOWORLD_DEBUG
    //    ...
#else
    #ifndef NDEBUG
        #define NDEBUG // NDEBUG flag for cassert
    #endif
#endif

#ifdef MEOWORLD_USE_WINAPI
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h> // Windows API
#else
    //#    include <pthread.h> // Or <thread> <mutex>
#endif

#include <cassert>

#if (-1)>>1 == -1
    #define MEOWORLD_COMPILER_RSHIFT_ARITH // Arithmetic shift right
#endif

// MWAPICALL
#ifdef MEOWORLD_COMPILER_MSVC
    #define MWAPICALL __cdecl
#else
    #define MWAPICALL __attribute__((__cdecl__))
#endif

// MWAPIEXPORT
#ifdef MEOWORLD_TARGET_WINDOWS
    #ifdef MEOWORLD_COMPILER_MSVC
        #define MWAPIEXPORT __declspec(dllexport)
    #else
        #define MWAPIEXPORT __attribute__((dllexport))
    #endif
#else
    #define MWAPIEXPORT __attribute__((visibility("default")))
#endif

constexpr unsigned int MeoworldVersion = 41u;
constexpr unsigned int ReleaseVersion = (MeoworldVersion << 16) + 2;
constexpr const char* CopyrightString = R"(
Meoworld  Copyright (C) 2016  Meoworld Team
This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it under certain conditions.
For details see "licenses/license_Meoworld.txt".
)";

#if defined(MEOWORLD_TARGET_WINDOWS)
    constexpr const char* DLLSuffix = "dll";
#elif defined(Meoworld_TARGET_MACOSX)
    constexpr const char* DLLSuffix = "dylib";
#else
    constexpr const char* DLLSuffix = "so";
#endif

#endif // !COMMON_H_
