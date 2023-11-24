//
// Created by lukas on 2023-11-19.
//

#include <cmath>
#include <tuple>
#include <iostream>
#include "Chunk.h"

Chunk::Chunk() {
    position = {0, 0, 0};
}


Chunk::Chunk(Coordinate position) : position(position) {

}

Chunk::~Chunk() {

}

float clamp(float x, float lower, float upper) {
    return std::max(lower, std::min(x, upper));
}

std::tuple<int, int, int> HueToRGB(float hue) {
    float r = fabs(hue * 6 - 3) - 1;
    float g = 2 - fabs(hue * 6 - 2);
    float b = 2 - fabs(hue * 6 - 4);
    return std::make_tuple(
            static_cast<int>(clamp(r, 0, 1) * 255),
            static_cast<int>(clamp(g, 0, 1) * 255),
            static_cast<int>(clamp(b, 0, 1) * 255)
    );
}

void Chunk::BuildVoxels() {

    int radius = CHUNK_SIZE / 2;
    int centerX = radius;
    int centerY = radius;
    int centerZ = radius;


    // loop through all voxels in chunk based on CHUNK_SIZE
    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int z = 0; z < CHUNK_SIZE; ++z) {
            for (int y = 0; y < CHUNK_SIZE; ++y) {

                // Calculate squared distance from the center
                int dx = x - centerX;
                int dy = y - centerY;
                int dz = z - centerZ;
                int distanceSquared = dx * dx + dy * dy + dz * dz;

                // Check if within sphere
                if (distanceSquared <= radius * radius) {

                    // Create a rainbow effect based on position
                    float hue = static_cast<float>((x + y + z) % CHUNK_SIZE) / CHUNK_SIZE;
                    auto [r, g, b] = HueToRGB(hue);

                    voxels[Coordinate(x, y, z).GetFlatIndex(CHUNK_SIZE)] = {
                            r, g, b, 255
                    };
                }

                // voxels[GetVoxelIndex(x, y, z)] = {static_cast<uint8_t>((x % 126) * 2), static_cast<uint8_t>((y % 126) * 2), static_cast<uint8_t>((z % 126) * 2), static_cast<uint8_t>(((z % 51) * 4) + 51)};
            }
        }
    }

    this->Dirty = true;
}


void Chunk::SetVoxel(Coordinate chunkPos, Voxel type) {
    //print chunkPos
    std::cout << "ChunkPos: " << chunkPos.x << ", " << chunkPos.y << ", " << chunkPos.z << std::endl;
    voxels[chunkPos.GetFlatIndex(CHUNK_AREA)] = type;
    this->Dirty = true;
}