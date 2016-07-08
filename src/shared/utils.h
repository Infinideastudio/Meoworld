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

#ifndef UTILS_H_
#define UTILS_H_

#include <vector>
#include <string>
#define FUNCTION_ALIAS(A,B) template <typename... Args> auto B(Args&&... args) -> decltype(A(std::forward<Args>(args)...)){return A(std::forward<Args>(args)...);}

std::vector<std::string> split(const std::string& src, std::string separate_character);
void trim(std::string& s);
void strtolower(std::string& s);

#endif // !UTILS_H_
