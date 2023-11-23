//
// Created by lukas on 2023-11-16.
//

#pragma once

#include "Chunk.h"
#include "meshes/ChunkMesh.h"
#include "meshes/QuadMesh.h"
#include "VoxelWorld.h"
#include "ShaderProgram.h"


class Scene {
public:
    Scene(ShaderProgram *shaderProgram);


    void Update();

    void Render();

    //VoxelWorld *world;
    Chunk *chunk;
    ChunkMesh *chunkMesh;
    ShaderProgram *shaderProgram;
};
