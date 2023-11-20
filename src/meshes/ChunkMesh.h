//
// Created by lukas on 2023-11-19.
//

#pragma once


#include "BaseMesh.h"
#include "../VoxelEngine.h"
#include "../Chunk.h"
#include "../Voxel.h"

class Chunk;

class ChunkMesh : public BaseMesh {
    Chunk *chunk;

public:
    ChunkMesh(Chunk *chunk);
    ~ChunkMesh() override = default;

    std::vector<float> GetVertexData() override;

    void SetVertexAttributes() override;

    bool IsVoid(int x, int y, int z, Voxel *voxels);
};
