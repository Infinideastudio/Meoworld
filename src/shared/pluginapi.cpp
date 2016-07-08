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

#include "pluginapi.h"

BlockManager* PiBlocks;

int MWAPICALL registerBlock(const PiBlockType* block)
{
    (PiBlocks->registerBlock)(convertBlockType(*block));
    return 0;
}

BlockType convertBlockType(const PiBlockType& src)
{
    return BlockType(src.blockname, src.solid, src.translucent, src.opaque, src.explodePower, src.hardness);
}

/*

extern "C"
{

    // ### Export variables/procedures to plugins ###

    MWAPIEXPORT PluginAPI::PiBlockData getBlock(const PluginAPI::PiVec3i* pos)
    {
        return PluginAPI::convertBlockData((world->getBlock)(*pos));
    }
    MWAPIEXPORT void setBlock(const PluginAPI::PiVec3i* pos, PluginAPI::PiBlockData block)
    {
        (world->setBlock)(*pos, PluginAPI::convertBlockData(block));
    }
    MWAPIEXPORT void registerBlock(const PluginAPI::PiBlockType* block)
    {
        (blocks->registerBlock)(PluginAPI::convertBlockType(*block));
    }

}

// Conversions between plugin structures and Meoworld structures
// This is used when structure definitions in Meoworld and in Plugin API are different
BlockData PluginAPI::convertBlockData(const PiBlockData& src)
{
    return BlockData(src.id, src.brightness, src.state);
}

PluginAPI::PiBlockData PluginAPI::convertBlockData(const BlockData& src)
{
    PiBlockData res;
    res.id = src.getID();
    res.brightness = src.getBrightness();
    res.state = src.getState();
    return res;
}

BlockType PluginAPI::convertBlockType(const PiBlockType& src)
{
    return BlockType(src.blockname, src.solid, src.translucent, src.opaque, src.explodePower, src.hardness);
}

*/
