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

#ifndef NWAPI_H_
#define NWAPI_H_

#include <stdint.h>

#if defined _WIN32 || defined __CYGWIN__
    #ifdef _MSC_VER
        #define NWAPIENTRY __declspec(dllimport)
        #define MWAPIEXPORT __declspec(dllexport)
    #else
        #define NWAPIENTRY __attribute__((dllimport))
        #define MWAPIEXPORT __attribute__((dllexport))
    #endif
#else
    #define NWAPIENTRY __attribute__((visibility("default")))
    #define MWAPIEXPORT __attribute__((visibility("default")))
#endif

#ifdef _MSC_VER
    #define MWAPICALL __cdecl
#else
    #define MWAPICALL __attribute__((__cdecl__))
#endif

struct PluginData
{
    char* pluginName = nullptr;
    char* authorName = nullptr;
    char* internalName = nullptr;
};

struct BlockType
{
    char* blockname = nullptr;
    bool solid;
    bool translucent;
    bool opaque;
    int32_t explodePower;
    int32_t hardness;
};

extern "C"
{
    NWAPIENTRY int32_t MWAPICALL registerBlock(BlockType*);
}

#endif // !NWAPI_H_
