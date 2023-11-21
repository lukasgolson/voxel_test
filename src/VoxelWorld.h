//
// Created by lukas on 2023-11-20.
//


#pragma once

#include "Chunk.h"
#include "meshes/ChunkMesh.h"


class VoxelWorld {





public:
    VoxelWorld();
    void Build_Chunks();

    void BuildChunkMesh();


    void Render();


    Chunk chunks[WORLD_VOLUME];
    ChunkMesh chunkMeshes[WORLD_VOLUME];
};
