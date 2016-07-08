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

#include "chunkrenderer.h"

VertexArray ChunkRenderer::va(262144, 2, 3, 1, 3);
bool ChunkRenderer::mergeFace;

void ChunkRenderer::buildVertexArray()
{
    if (mergeFace)
    {
        // Use struct Primitive
        // ...
    }
    else
    {
        // Iterate blocks and render
        // ...
    }
}

void ChunkRenderer::renderVertexArray()
{
    // glBindBufferARB(...)
    // glTexturePointerARB(...)
    // ...
    // glVertexPointerARB(...)
    // glDrawArrays(...)
}
