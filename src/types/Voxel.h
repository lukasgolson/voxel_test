//
// Created by lukas on 2023-11-19.
//

#pragma once


#include <cstdint>
#include "Rgb.h"
#include "Rgba.h"

struct Voxel {
    Voxel();
    Voxel(int red, int green, int blue);
    explicit Voxel(RGB rgb);
    Voxel(int red, int green, int blue, int alpha);
    explicit Voxel(RGBA rgba);
    explicit Voxel(uint32_t color);

    [[nodiscard]] uint32_t GetColor() const;

    int red = 0;
    int green = 0;
    int blue = 0;
    int alpha = 0;

    static const Voxel EMPTY;
};



