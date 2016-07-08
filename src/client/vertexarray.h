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

#ifndef VERTEXARRAY_H_
#define VERTEXARRAY_H_

#include <cstring>
#include <boost/core/noncopyable.hpp>
#include "../shared/common.h"

class VertexArray
    :boost::noncopyable
{
public:
    VertexArray(int maxVertexes, int textureElementCount, int colorElementCount, int attributeElementCount, int coordinateElementCount)
        :m_maxVertexes(maxVertexes), m_vertexes(0),
         m_textureCount(textureElementCount), m_colorCount(colorElementCount), m_attributeCount(attributeElementCount), m_coordinateCount(coordinateElementCount),
         m_vertexAttributeCount(textureElementCount + colorElementCount + attributeElementCount + coordinateElementCount)
    {
        m_data = new float[m_maxVertexes*m_vertexAttributeCount]();
        m_vertexAttributes = new float[m_vertexAttributeCount]();
    }

    ~VertexArray()
    {
        delete[] m_data;
        delete[] m_vertexAttributes;
    }

    void clear()
    {
        memset(m_data, 0, m_maxVertexes*m_vertexAttributeCount*sizeof(float));
        memset(m_vertexAttributes, 0, m_vertexAttributeCount*sizeof(float));
        m_vertexes = 0;
    }

    // Set texture coordinates
    void setTexture(int size, const float* texture)
    {
        assert(size <= m_textureCount);
        memcpy(m_vertexAttributes, texture, size*sizeof(float));
    }

    // Set color value
    void setColor(int size, const float* color)
    {
        assert(size <= m_colorCount);
        memcpy(m_vertexAttributes + m_textureCount, color, size*sizeof(float));
    }

    // Set extra vertex attributes value
    void setAttribute(int size, const float* attribute)
    {
        assert(size <= m_attributeCount);
        memcpy(m_vertexAttributes + m_textureCount + m_colorCount, attribute, size*sizeof(float));
    }

    // Add vertex
    void addVertex(const float* coords)
    {
        memcpy(m_data + m_vertexes, m_vertexAttributes, m_vertexAttributeCount*sizeof(float));
        memcpy(m_data + m_vertexes + m_vertexAttributeCount, coords, m_coordinateCount*sizeof(float));
        m_vertexes++;
    }

    // Generate vertex buffer for rendering
    void flush();
    // Render vertex buffer
    static void render();

private:
    // Max vertex count
    const int m_maxVertexes;
    // Vertex count
    int m_vertexes;
    // Vertex Attribute Count
    const int m_textureCount, m_colorCount, m_attributeCount, m_coordinateCount;
    // Vertex attributes count (sum of all)
    const int m_vertexAttributeCount;
    // Vertex array
    float *m_data;
    // Current vertex attributes
    float *m_vertexAttributes;

};

#endif // !VERTEXARRAY_H_
