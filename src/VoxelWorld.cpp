//
// Created by lukas on 2023-11-20.
//

#include <iostream>
#include "VoxelWorld.h"
#include "ShaderProgram.h"





VoxelWorld::VoxelWorld() {

    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int y = 0; y < WORLD_SIZE; y++) {
            for (int z = 0; z < WORLD_SIZE; z++) {

                auto index = Coordinate(x, y, z).GetFlatIndex(WORLD_SIZE);

                chunkMeshes[index].AssociateChunk(&chunks[index]);
                chunks[index].position = {x, y, z};
               // chunks[index].BuildVoxels();

            }
        }
    }
}

Coordinate VoxelWorld::GetChunkCoordinates(Coordinate worldCoords) {


    int chunkX = worldCoords.x / CHUNK_SIZE;
    int chunkY = worldCoords.y / CHUNK_SIZE;
    int chunkZ = worldCoords.z / CHUNK_SIZE;


    auto chunkCoords = Coordinate(chunkX, chunkY, chunkZ);

    return chunkCoords;
}

void VoxelWorld::SetVoxel(Coordinate worldPos, Voxel type) {


    auto chunkCoords = GetChunkCoordinates(worldPos);
    auto chunkIndex = chunkCoords.GetFlatIndex(WORLD_SIZE);


    auto localCoords = Coordinate(worldPos.x - chunkCoords.x * CHUNK_SIZE, worldPos.y - chunkCoords.y * CHUNK_SIZE, worldPos.z - chunkCoords.z * CHUNK_SIZE);


    chunks[chunkIndex].SetVoxel(localCoords, type);

}


void VoxelWorld::Render(ShaderProgram *shaderProgram) {
    for (int i = 0; i < WORLD_VOLUME; i++) {
        shaderProgram->SetModelMatrix(chunkMeshes[i].GetModelMatrix());
        chunkMeshes[i].Render();
    }
}
