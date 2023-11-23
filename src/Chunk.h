//
// Created by lukas on 2023-11-19.
//

#pragma once

#include "Voxel.h"
#include "Settings.h"
#include "types/Coordinates.h"


class Chunk {




public:
    Chunk();

    Chunk(Coordinates position);
    ~Chunk();

    void BuildVoxels();



    bool Dirty = false;


    [[nodiscard]] static int GetVoxelIndex(int x, int y, int z) {
        return x + CHUNK_SIZE * z + CHUNK_AREA * y;
    };

    [[nodiscard]] static int GetVoxelIndex(Coordinates coords) {
        return coords.x + CHUNK_SIZE * coords.z + CHUNK_AREA * coords.y;
    };

    Voxel voxels[CHUNK_VOLUME]{};

    Coordinates position = {0, 0, 0};
};
