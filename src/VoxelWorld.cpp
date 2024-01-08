//
// Created by lukas on 2023-11-20.
//

#include <iostream>
#include "VoxelWorld.h"
#include "Rendering/ShaderProgram.h"





VoxelWorld::VoxelWorld(int worldSize, int chunkSize) {

    this->worldSize = worldSize;
    this->worldVolume = worldSize * worldSize * worldSize;
    this->chunkSize = chunkSize;

    this->chunkArray = new Chunk[worldVolume];
    this->chunkMeshArray = new ChunkMesh[worldVolume];

    for (int x = 0; x < worldSize; x++) {
        for (int y = 0; y < worldSize; y++) {
            for (int z = 0; z < worldSize; z++) {

                auto index = Coordinate(x, y, z).GetFlatIndex(worldSize);

                chunkMeshArray[index].AssociateChunk(&chunkArray[index]);
                chunkArray[index].position = {x, y, z};
               // chunkArray[index].BuildVoxels();

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

void VoxelWorld::SetVoxel(Coordinate worldPos, Voxel voxel) {


    auto chunkCoords = GetChunkCoordinates(worldPos);
    auto chunkIndex = chunkCoords.GetFlatIndex(this->worldSize);


    auto localCoords = Coordinate(worldPos.x - chunkCoords.x * CHUNK_SIZE, worldPos.y - chunkCoords.y * CHUNK_SIZE, worldPos.z - chunkCoords.z * CHUNK_SIZE);


    chunkArray[chunkIndex].SetVoxel(localCoords, voxel);

}


Voxel VoxelWorld::GetVoxel(const Coordinate worldPos) {

    auto chunkCoords = GetChunkCoordinates(worldPos);
    auto chunkIndex = chunkCoords.GetFlatIndex(this->worldSize);


    auto localCoords = Coordinate(worldPos.x - chunkCoords.x * CHUNK_SIZE, worldPos.y - chunkCoords.y * CHUNK_SIZE, worldPos.z - chunkCoords.z * CHUNK_SIZE);


    chunkArray[chunkIndex].GetVoxel(localCoords);

    return Voxel();
}



void VoxelWorld::Render(ShaderProgram *shaderProgram) {
    for (int i = 0; i < this->worldVolume; i++) {
        shaderProgram->SetModelMatrix(chunkMeshArray[i].GetModelMatrix());
        chunkMeshArray[i].Render();
    }
}

