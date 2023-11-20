//
// Created by lukas on 2023-11-19.
//

#pragma once

#include "Voxel.h"
#include "Settings.h"




class Chunk {

public:
    Chunk();
    ~Chunk();

    void BuildVoxels();


    [[nodiscard]] static int GetVoxelIndex(int x, int y, int z) {
        return x + CHUNK_SIZE * z + CHUNK_AREA * y;
    };

    Voxel voxels[CHUNK_VOLUME]{};
};
