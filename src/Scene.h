//
// Created by lukas on 2023-11-16.
//

#pragma once

#include "Chunk.h"
#include "meshes/ChunkMesh.h"
#include "meshes/QuadMesh.h"
#include "VoxelWorld.h"
#include "Rendering/ShaderProgram.h"


class Scene {
public:
    Scene(ShaderProgram *shaderProgram, int worldSize, int chunkSize);


    void Update();

    void Render();

    ShaderProgram *shaderProgram;
    VoxelWorld *voxelWorld;

    Coordinate currentCoords = {0, 0, 0};
    Coordinate colorOffset = {0, 0, 0};
};
