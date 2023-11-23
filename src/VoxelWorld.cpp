//
// Created by lukas on 2023-11-20.
//

#include "VoxelWorld.h"
#include "ShaderProgram.h"


VoxelWorld::VoxelWorld() {


    for (int i = 0; i < WORLD_VOLUME; i++) {
        chunkMeshes[i].AssociateChunk(&chunks[i]);
        chunks[i].position = {i % WORLD_SIZE, (i / WORLD_SIZE) % WORLD_SIZE, i / (WORLD_SIZE * WORLD_SIZE)};
        chunks[i].BuildVoxels();

    }

}


void VoxelWorld::BuildChunkMesh() {

}

void VoxelWorld::Render(ShaderProgram *shaderProgram) {
    for (int i = 0; i < WORLD_VOLUME; i++) {
        shaderProgram->SetModelMatrix(chunkMeshes[i].GetModelMatrix());
        chunkMeshes[i].Render();
    }
}
