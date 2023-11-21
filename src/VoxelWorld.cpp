//
// Created by lukas on 2023-11-20.
//

#include "VoxelWorld.h"


VoxelWorld::VoxelWorld() {
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int y = 0; y < WORLD_SIZE; y++) {
            for (int z = 0; z < WORLD_SIZE; z++) {
                auto chnk = this->chunks[Chunk::GetVoxelIndex(x, y, z)];
                chnk.position = {x, y, z};
                //  chnk.BuildVoxels();
                this->chunkMeshes[Chunk::GetVoxelIndex(x, y, z)].AssociateChunk(&chnk);
            }
        }
    }
}


void VoxelWorld::BuildChunkMesh() {

}

void VoxelWorld::Render() {
    for (ChunkMesh &mesh: this->chunkMeshes) {
        // mesh.Render();
    }
}
