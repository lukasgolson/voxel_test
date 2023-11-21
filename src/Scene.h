//
// Created by lukas on 2023-11-16.
//

#pragma once

#include "Chunk.h"
#include "meshes/ChunkMesh.h"
#include "meshes/QuadMesh.h"
#include "VoxelWorld.h"


class Scene {
public:
    Scene();


    void Update();

    void Render();

    //VoxelWorld *world;
    Chunk *chunk;
    ChunkMesh *chunkMesh;
};
