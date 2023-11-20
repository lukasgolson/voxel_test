//
// Created by lukas on 2023-11-19.
//

#pragma once

#include "VoxelEngine.h"
#include "Voxel.h"
#include "meshes/ChunkMesh.h"
#include "Chunk.h"


constexpr int CHUNK_SIZE = 16;
constexpr int H_CHUNK_SIZE = CHUNK_SIZE / 2;
constexpr int CHUNK_AREA = CHUNK_SIZE * CHUNK_SIZE;
constexpr int CHUNK_VOLUME = CHUNK_AREA * CHUNK_SIZE;

class ChunkMesh;

class Chunk {

public:
    Chunk();
    ~Chunk();

    void BuildVoxels();


    [[nodiscard]] static int GetVoxelIndex(int x, int y, int z) {
        return x + CHUNK_SIZE * z + CHUNK_AREA * y;
    };

    Voxel voxels[CHUNK_VOLUME];
};
