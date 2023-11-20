//
// Created by lukas on 2023-11-16.
//

#pragma once

#include "Chunk.h"
#include "meshes/ChunkMesh.h"
#include "meshes/QuadMesh.h"


class Scene {
public:
    Scene();


    void Update();

    void Render();

    Chunk *chunk;
    ChunkMesh *chunkMesh;
    QuadMesh *quadMesh;
};
