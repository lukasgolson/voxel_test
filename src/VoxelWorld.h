//
// Created by lukas on 2023-11-20.
//


#pragma once

#include "Chunk.h"
#include "meshes/ChunkMesh.h"
#include "ShaderProgram.h"


class VoxelWorld {





public:
    VoxelWorld();

    Chunk chunks[WORLD_VOLUME];
    ChunkMesh chunkMeshes[WORLD_VOLUME];

    void Render(ShaderProgram *shaderProgram);

    void SetBlock(Coordinate coords, Voxel type);

    Coordinate GetChunkCoordinates(Coordinate worldCoords);
};
