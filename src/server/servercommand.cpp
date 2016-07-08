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

#include "servercommand.h"
#include <logger.h>
#include <consolecolor.h>
#include <thread>
#include <chrono>
#include <command.h>
#include "server.h"
#include <utils.h>
#include "settings.h"
#include <type.h>

bool inputThreadRunning = true;

CommandMap commandMap;
#define CommandDefine(commandName, commandAuthor, commandHelp) commandMap.insert({commandName, std::pair<CommandInfo,CommandHandleFunction>({commandAuthor, commandHelp},[](Command cmd)->CommandExecuteStat
#define EndCommandDefine )})

void stopInputThreadRunning()
{
    inputThreadRunning = false;
}

void initCommands()
{
    CommandDefine("help", "Internel", "Help")
    {
        std::string helpString = "\nAvailable commands:\n";
        for (const auto& command : commandMap)
        {
            helpString += command.first + " - " + command.second.first.author + " : " + command.second.first.help + "\n";
        }
        return{ true, helpString };
    }
    EndCommandDefine;

    CommandDefine("test.hello", "Internal", "Say hello")
    {
        return{ true, "Hello!" };
    }
    EndCommandDefine;

    CommandDefine("test.fatal", "Internal", "test fatal log.")
    {
        fatalstream << "execute test.fatal!";
        return { true , "" };
    }
    EndCommandDefine;

    CommandDefine("test.error", "Internal", "test error log.")
    {
        errorstream << "execute test.error!";
        return{ true , "" };
    }
    EndCommandDefine;

    CommandDefine("test.warning", "Internal", "do NOT use it :-)")
    {
        warningstream << "Your computer will explode in three seconds!!!";
        return{ true , "" };
    }
    EndCommandDefine;

    CommandDefine("test.rainbow", "Internal", "test colors.")
    {
        infostream << "Grayscales:";
        infostream << LColor::black << "2333333333 [0%]";
        infostream << LColor::lblack << "2333333333 [50%]";
        infostream << LColor::white << "2333333333 [75%]";
        infostream << LColor::lwhite << "2333333333 [100%]";
        infostream << "Dark colors:";
        infostream << LColor::red << "2333333333 [dark red]";
        infostream << LColor::yellow << "2333333333 [dark yellow]";
        infostream << LColor::green << "2333333333 [dark green]";
        infostream << LColor::cyan << "2333333333 [dark cyan]";
        infostream << LColor::blue << "2333333333 [dark blue]";
        infostream << LColor::magenta << "2333333333 [dark magenta]";
        infostream << "Bright colors:";
        infostream << LColor::lred << "2333333333 [red]";
        infostream << LColor::lyellow << "2333333333 [yellow]";
        infostream << LColor::lgreen << "2333333333 [green]";
        infostream << LColor::lcyan << "2333333333 [cyan]";
        infostream << LColor::lblue << "2333333333 [blue]";
        infostream << LColor::lmagenta << "2333333333 [magenta]";
        return{ true , "" };
    }
    EndCommandDefine;

    CommandDefine("server.stop", "Internal", "Stop the server")
    {
        ioService.stop();
        stopInputThreadRunning();
        return{ true, "" };
    }
    EndCommandDefine;

    CommandDefine("conf.set", "Internal", "Set one configuration item. Usage: conf.set <confname> <value>")
    {
        if (cmd.args.size() == 2)
        {
            settings.set(cmd.args[0], string2type(cmd.args[1]));
            return{ true, "Set" };
        }
        else
        {
            return{ false, "Usage: conf.set <confname> <value>" };
        }
    }
    EndCommandDefine;

    CommandDefine("conf.get", "Internal", "Get one configuration item. Usage: conf.get <confname>")
    {
        if (cmd.args.size() == 1)
        {
            if(settings.have(cmd.args[0]))
                return{ true, cmd.args[0] + " = " + type2string(settings.get(cmd.args[0])) };
            else
                return{ false, "The configuration item does not exist." };
        }
        else
        {
            return{ false, "Usage: conf.get <confname>" };
        }
    }
    EndCommandDefine;

    CommandDefine("conf.show", "Internal", "Show the configuration.")
    {
        std::string conf;
        for (const auto& p : settings.getMap())
        {
            conf += '\n' + p.first + " = " + type2string(p.second);
        }
        return{ true,conf };
    }
    EndCommandDefine;

    CommandDefine("conf.save", "Internal", "Save the configuration.")
    {
        settings.save();
        return{ true,"Done!" };
    }
    EndCommandDefine;
}

CommandExecuteStat handleCommand(Command cmd)
{
    strtolower(cmd.name);
    auto result = commandMap.find(cmd.name);
    if (result != commandMap.end())
        return (*result).second.second(cmd);
    else
        return{ false,"Failed to execute the command: The command does not exist, type help for available commands." };
}

void inputThreadFunc()
{
    initCommands();
    while (inputThreadRunning)
    {
        std::string input;
        std::cout << LColorFunc::white << "$> ";
        std::getline(std::cin, input);
        auto result = handleCommand(Command(input));
        if (result.info != "")
            infostream << result.info;
    }
}
