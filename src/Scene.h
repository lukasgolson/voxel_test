//
// Created by lukas on 2023-11-16.
//

#pragma once


#include "meshes/ChunkMesh.h"
#include "ShaderProgram.h"
#include "Chunk.h"





class Scene {
public:
    Scene();


    void Update();

    void Render();

    Chunk *chunk;
    ChunkMesh *chunkMesh;
};
