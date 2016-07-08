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

#include "../../../api/cpp/nwapi.h"

PluginData* TestPlugin;

// Export functions
extern "C"
{
    MWAPIEXPORT PluginData* MWAPICALL init();
}

// Main function
PluginData* MWAPICALL init()
{
    BlockType rock;
    rock.blockname = "Rock";
    rock.solid = 1;
    rock.translucent = 0;
    rock.opaque = 1;
    rock.explodePower = 0;
    rock.hardness = 2;
    registerBlock(&rock);
    TestPlugin = new PluginData();
    TestPlugin->pluginName = "Test Plugin";
    TestPlugin->authorName = "INFINIDEAS";
    TestPlugin->internalName = "infinideas.testplugin_cpp";
    return TestPlugin;
}
