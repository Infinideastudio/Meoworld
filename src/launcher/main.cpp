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

#include <iostream>
#include <string>
#include <boost/dll/shared_library.hpp>
#include <common.h> // For MWAPICALL

const std::string Path = "./Bin/";
typedef void MWAPICALL MainFunction(int, char**);

int main(int argc, char** argv)
{
    std::cout << "Welcome to Meoworld Minimal Launcher!" << std::endl;
    std::cout << "Enter 'client' to run client" << std::endl;
    std::cout << "Enter 'server' to run server" << std::endl;
    std::string in;
    std::cin >> in;
    if (in == "server")
        boost::dll::shared_library
        (
            Path + "MeoworldServer",
            boost::dll::load_mode::append_decorations
        )
        .get<MainFunction>("main")(argc, argv);
    else boost::dll::shared_library
        (
            Path + "Meoworld",
            boost::dll::load_mode::append_decorations
        )
        .get<MainFunction>("main")(argc, argv);
    return 0;
}
