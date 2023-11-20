//
// Created by lukas on 2023-11-19.
//

#pragma once


#include "BaseMesh.h"
#include "../Voxel.h"
#include "../VoxelVertex.h"
#include "../Settings.h"

class Chunk;

class ChunkMesh : public BaseMesh {
    Chunk *chunk;

public:
    ChunkMesh(Chunk *chunk);
    ~ChunkMesh() override = default;

    std::vector<float> GetVertexData() override;

    void SetVertexAttributes() override;

    bool IsVoid(int x, int y, int z, int currentAlpha, Voxel *voxels);
};
