//
// Created by lukas on 2023-11-20.
//


#pragma once

#include "Chunk.h"
#include "meshes/ChunkMesh.h"
#include "Rendering/ShaderProgram.h"


class VoxelWorld {





public:
    VoxelWorld(int worldSize, int chunkSize);

    Chunk* chunkArray;
    ChunkMesh* chunkMeshArray;

    void Render(ShaderProgram *shaderProgram);

    void SetVoxel(Coordinate worldPos, Voxel voxel);

    Coordinate GetChunkCoordinates(Coordinate worldCoords);

    Voxel GetVoxel(const Coordinate worldPos);

    int worldSize;
    int worldVolume;
    int chunkSize;
};
