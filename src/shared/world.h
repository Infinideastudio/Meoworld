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

#ifndef WORLD_H_
#define WORLD_H_

#include <algorithm>
#include <string>
#include <cstdlib> // malloc, realloc, free
#include <boost/core/noncopyable.hpp>
#include "chunk.h"

using std::abs;
using std::string;

class PluginManager;

class World :boost::noncopyable
{
private:
    // World name
    string m_name;
    // Loaded plugins
    PluginManager& m_plugins;
    // Loaded chunk count
    size_t m_chunkCount;
    // Size of chunk array
    size_t m_chunkArraySize;
    // All chunks (chunk array)
    Chunk** m_chunks;

    // Expand chunk array
    void expandChunkArray(size_t expandCount);
    // Reduce chunk array
    void reduceChunkArray(size_t reduceCount)
    {
        assert(m_chunkCount >= reduceCount);
        m_chunkCount -= reduceCount;
    }
    // New pointer at m_chunks[index]
    void newChunkPtr(size_t index)
    {
        expandChunkArray(1);
        for (size_t i = m_chunkCount - 1; i > index; i--)
            m_chunks[i] = m_chunks[i - 1];
        m_chunks[index] = nullptr;
    }
    // Erase pointer at m_chunks[index]
    void eraseChunkPtr(size_t index)
    {
        for (size_t i = index; i < m_chunkCount - 1; i++)
            m_chunks[i] = m_chunks[i + 1];
        reduceChunkArray(1);
    }
    // Search chunk index, or the index the chunk should insert into
    size_t getChunkIndex(const Vec3i& chunkPos) const;

public:
    World(const string& name, PluginManager& plugins) :m_name(name), m_plugins(plugins), m_chunkCount(0), m_chunkArraySize(1024)
    {
        //m_chunks = new Chunk*[m_chunkArraySize];
        m_chunks = (Chunk**)malloc(m_chunkArraySize * sizeof(Chunk*));
    }
    World(World&& rhs) :m_name(std::move(rhs.m_name)), m_plugins(rhs.m_plugins), m_chunkCount(rhs.m_chunkCount), m_chunkArraySize(rhs.m_chunkArraySize), m_chunks(rhs.m_chunks)
    {}

    ~World()
    {
        if (m_chunks)
        {
            // TODO: Save and destroy chunks
            free(m_chunks);
        }
    }

    // Get world name
    const string& getWorldName()
    {
        return m_name;
    }

    // Get chunk count
    size_t getChunkCount() const
    {
        return m_chunkCount;
    }

    // Get chunk pointer by index
    Chunk* getChunkPtr(size_t index) const
    {
        assert(index < m_chunkCount);
        return m_chunks[index];
    }

    // Get chunk pointer by chunk coordinates
    Chunk* getChunkPtr(const Vec3i& chunkPos) const
    {
        // TODO: Try chunk pointer cache
        // TODO: Try chunk pointer array
        Chunk* res = m_chunks[getChunkIndex(chunkPos)];
        // TODO: Update chunk pointer array
        // TODO: Update chunk pointer cache
        return res;
    }

    // Add chunk
    Chunk* addChunk(const Vec3i& chunkPos);
    // Delete chunk
    int deleteChunk(const Vec3i& chunkPos);

#ifdef MEOWORLD_COMPILER_RSHIFT_ARITH
    // Convert world position to chunk coordinate (one axis)
    static int getChunkPos(int pos)
    {
        return pos >> ChunkSizeLog2;
    }
#else
    // Convert world position to chunk coordinate (one axis)
    static int getChunkPos(int pos)
    {
        if (pos >= 0) return pos / ChunkSize;
        return (pos - ChunkSize + 1) / ChunkSize;
    }
#endif

    // Convert world position to chunk coordinate (all axes)
    static Vec3i getChunkPos(const Vec3i& pos)
    {
        return Vec3i(getChunkPos(pos.x), getChunkPos(pos.y), getChunkPos(pos.z));
    }

    // Convert world position to block coordinate in chunk (one axis)
    static int getBlockPos(int pos)
    {
        return pos & (ChunkSize - 1);
    }

    // Convert world position to block coordinate in chunk (all axes)
    static Vec3i getBlockPos(const Vec3i& pos)
    {
        return Vec3i(getBlockPos(pos.x), getBlockPos(pos.y), getBlockPos(pos.z));
    }

    // Get block data
    BlockData getBlock(const Vec3i& pos) const
    {
        Chunk* chunk = getChunkPtr(getChunkPos(pos));
        assert(chunk != nullptr);
        return chunk->getBlock(getBlockPos(pos));
    }

    // Get block reference
    BlockData& getBlock(const Vec3i& pos)
    {
        Chunk* chunk = getChunkPtr(getChunkPos(pos));
        assert(chunk != nullptr);
        return chunk->getBlock(getBlockPos(pos));
    }

    // Set block data
    void setBlock(const Vec3i& pos, BlockData block)
    {
        Chunk* chunk = getChunkPtr(getChunkPos(pos));
        assert(chunk != nullptr);
        chunk->setBlock(getBlockPos(pos), block);
    }

    // Main update
    void update();

};

#endif // !WORLD_H_
