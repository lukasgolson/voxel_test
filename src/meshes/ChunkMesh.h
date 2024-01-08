//
// Created by lukas on 2023-11-19.
//

#pragma once


#include <glm/ext/matrix_float4x4.hpp>
#include "BaseMesh.h"
#include "../types/Voxel.h"
#include "../VoxelVertex.h"
#include "../Settings.h"
#include "../Chunk.h"

class ChunkMesh : public BaseMesh {
    Chunk *chunk;

public:
    ChunkMesh();
    ~ChunkMesh() override = default;

    void Render() override;

    std::vector<float> GetVertexData() override;

    void SetVertexAttributes() override;

    bool IsVoid(int x, int y, int z, int currentAlpha, Voxel *voxels);

    void AssociateChunk(Chunk *chunk);

    bool IsInitialized();

    // Get model matrix
    glm::mat4 GetModelMatrix() override;
};
