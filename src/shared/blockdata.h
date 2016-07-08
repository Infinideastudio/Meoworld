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

#ifndef BLOCKDATA_H_
#define BLOCKDATA_H_

class BlockData
{
private:
    unsigned int id : 12; // Block ID
    unsigned int brightness : 4; // Brightness
    unsigned int state : 16; // Block state

public:
    BlockData() :id(0), brightness(0),state(0) {}
    BlockData(int id_, int brightness_, int state_) :id(id_), brightness(brightness_), state(state_) {}
    BlockData(const BlockData& rhs) :id(rhs.id), brightness(rhs.brightness), state(rhs.state) {}

    bool operator== (const BlockData& rhs) const
    {
        return id == rhs.id;
    }

    int getID() const
    {
        return id;
    }
    int getBrightness() const
    {
        return brightness;
    }
    int getState() const
    {
        return state;
    }
    void setID(int id_)
    {
        id = id_;
    }
    void setBrightness(int brightness_)
    {
        brightness = brightness_;
    }
    void setState(int state_)
    {
        state = state_;
    }

};

#endif // !BLOCKDATA_H_
