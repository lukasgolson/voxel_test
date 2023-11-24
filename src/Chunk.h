//
// Created by lukas on 2023-11-19.
//

#pragma once

#include "Voxel.h"
#include "Settings.h"
#include "types/Coordinate.h"


class Chunk {


public:
    Chunk();

    Chunk(Coordinate position);

    ~Chunk();

    void BuildVoxels();


    bool Dirty = false;


    [[nodiscard]] static int GetVoxelIndex(int x, int y, int z) {
        return x + CHUNK_SIZE * z + CHUNK_AREA * y;
    };



    Voxel voxels[CHUNK_VOLUME]{};

    Coordinate position = {0, 0, 0};

    void SetVoxel(Coordinate coords, Voxel type);
};
