//
// Created by lukas on 2023-11-19.
//

#include "Chunk.h"

Chunk::Chunk() {
    this->BuildVoxels();
}

Chunk::~Chunk() {

}

void Chunk::BuildVoxels() {
    // loop through all voxels in chunk based on CHUNK_SIZE
    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int z = 0; z < CHUNK_SIZE; ++z) {
            for (int y = 0; y < CHUNK_SIZE; ++y) {
                voxels[GetVoxelIndex(x, y, z)] = {static_cast<uint8_t>((x % 126) * 2), static_cast<uint8_t>((y % 126) * 2), static_cast<uint8_t>((z % 126) * 2), static_cast<uint8_t>(((z % 51) * 4) + 51)};
            }
        }
    }


}
