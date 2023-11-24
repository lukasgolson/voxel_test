//
// Created by lukas on 2023-11-19.
//

#pragma once


#include <cstdint>

struct Voxel {

    Voxel() = default;

    Voxel(int red, int green, int blue) : red(red), green(green), blue(blue), alpha(255) {}

    Voxel(int red, int green, int blue, int alpha) : red(red), green(green), blue(blue), alpha(alpha) {}

    explicit Voxel(uint32_t color) {
        red = color & 0xFF;
        green = (color >> 8) & 0xFF;
        blue = (color >> 16) & 0xFF;
        alpha = (color >> 24) & 0xFF;
    }


    [[nodiscard]] uint32_t GetColor() const {
        return unsigned(red | (green << 8) | (blue << 16) | (alpha << 24));
    }

    int red = 0;
    int green = 0;
    int blue = 0;
    int alpha = 0;


};



