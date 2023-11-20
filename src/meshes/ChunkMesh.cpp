//
// Created by lukas on 2023-11-19.
//

#include <iostream>
#include "ChunkMesh.h"
#include "../Chunk.h"


ChunkMesh::ChunkMesh(Chunk *chunk) : chunk(chunk), BaseMesh() {
    SetupMesh(8);
}

bool ChunkMesh::IsVoid(int x, int y, int z, int currentAlpha, Voxel voxels[CHUNK_VOLUME]) {
    if (x < 0 || x >= CHUNK_SIZE || y < 0 || y >= CHUNK_SIZE || z < 0 || z >= CHUNK_SIZE) return true;
    return voxels[Chunk::GetVoxelIndex(x, y, z)].alpha != currentAlpha;
}

void ChunkMesh::SetVertexAttributes() {
    // Position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);

    // Color
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));

    // Face ID
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (7 * sizeof(float)));
}

std::vector<float> ChunkMesh::GetVertexData() {

    std::cout << "Generating mesh for chunk" << std::endl;

    // create new vector to store vertex data; size = CHUNK_VOL * 18 (6 faces * 3 vertices * 3 floats) * 5 (5 floats per vertex)
    std::vector<float> vertexData;
    vertexData.reserve(CHUNK_VOLUME * 18 * 5);


    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int z = 0; z < CHUNK_SIZE; ++z) {
            for (int y = 0; y < CHUNK_SIZE; ++y) {
                auto voxel = chunk->voxels[Chunk::GetVoxelIndex(x, y, z)];
                if (voxel.alpha == 0) continue;

              //  std::cout << "Generating mesh for voxel at " << x << ", " << y << ", " << z << std::endl;

                // format: x, y, z, r,g,b,a, face_id
                // Face ID: 0 = top, 1 = bottom, 2 = right, 3 = left, 4 = back, 5 = front

                // top face


                if (this->IsVoid(x, y + 1, z, voxel.alpha, chunk->voxels)) {
                    auto v0 = VoxelVertex{x + 0, y + 1, z + 0, voxel, 0};
                    auto v1 = VoxelVertex{x + 1, y + 1, z + 0, voxel, 0};
                    auto v2 = VoxelVertex{x + 1, y + 1, z + 1, voxel, 0};
                    auto v3 = VoxelVertex{x, y + 1, z + 1, voxel, 0};

                    AddVerticesToData(vertexData, {v0, v3, v2, v0, v2, v1});

                }

                // bottom face
                if (this->IsVoid(x,y-1,z, voxel.alpha,chunk->voxels)){
                    auto v0 = VoxelVertex{x + 0, y + 0, z + 0, voxel, 1};
                    auto v1 = VoxelVertex{x + 1, y + 0, z + 0, voxel, 1};
                    auto v2 = VoxelVertex{x + 1, y + 0, z + 1, voxel, 1};
                    auto v3 = VoxelVertex{x + 0, y + 0, z + 1, voxel, 1};

                    AddVerticesToData(vertexData, {v0, v2, v3, v0, v1, v2});

                }

                // right face
                if (this->IsVoid(x+1,y,z, voxel.alpha,chunk->voxels)){
                    auto v0 = VoxelVertex{x + 1, y + 0, z + 0, voxel, 2};
                    auto v1 = VoxelVertex{x + 1, y + 1, z + 0, voxel, 2};
                    auto v2 = VoxelVertex{x + 1, y + 1, z + 1, voxel, 2};
                    auto v3 = VoxelVertex{x + 1, y + 0, z + 1, voxel, 2};

                    AddVerticesToData(vertexData, {v0, v1, v2, v0, v2, v3});

                }

                // left face
                if (this->IsVoid(x-1,y,z,voxel.alpha, chunk->voxels)){
                    auto v0 = VoxelVertex{x + 0, y + 0, z + 0, voxel, 3};
                    auto v1 = VoxelVertex{x + 0, y + 1, z + 0, voxel, 3};
                    auto v2 = VoxelVertex{x + 0, y + 1, z + 1, voxel, 3};
                    auto v3 = VoxelVertex{x + 0, y + 0, z + 1, voxel, 3};

                    AddVerticesToData(vertexData, {v0, v2, v1, v0, v3, v2});

                }

                // back face
                if (this->IsVoid(x,y,z-1,voxel.alpha, chunk->voxels)){
                    auto v0 = VoxelVertex{x + 0, y + 0, z + 0, voxel, 4};
                    auto v1 = VoxelVertex{x + 0, y + 1, z + 0, voxel, 4};
                    auto v2 = VoxelVertex{x + 1, y + 1, z + 0, voxel, 4};
                    auto v3 = VoxelVertex{x + 1, y + 0, z + 0, voxel, 4};

                    AddVerticesToData(vertexData, {v0, v1, v2, v0, v2, v3});

                }

                // front face
                if (this->IsVoid(x,y,z+1,voxel.alpha, chunk->voxels)){
                    auto v0 = VoxelVertex{x + 0, y + 0, z + 1, voxel, 5};
                    auto v1 = VoxelVertex{x + 0, y + 1, z + 1, voxel, 5};
                    auto v2 = VoxelVertex{x + 1, y + 1, z + 1, voxel, 5};
                    auto v3 = VoxelVertex{x + 1, y + 0, z + 1, voxel, 5};

                    AddVerticesToData(vertexData, {v0, v2, v1, v0, v3, v2});

                }
            }
        }
    }

    return vertexData;
}
