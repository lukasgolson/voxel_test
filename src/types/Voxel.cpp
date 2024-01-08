//
// Created by olson.stu on 2024-01-05.
//

#include "Voxel.h"



Voxel::Voxel() = default;

Voxel::Voxel(int red, int green, int blue) : red(red), green(green), blue(blue), alpha(255) {}

Voxel::Voxel(RGB rgb) : red(static_cast<int>(rgb.red * 255)), green(static_cast<int>(rgb.green * 255)), blue(static_cast<int>(rgb.blue * 255)), alpha(255) {}

Voxel::Voxel(int red, int green, int blue, int alpha) : red(red), green(green), blue(blue), alpha(alpha) {}

Voxel::Voxel(RGBA rgba) : red(static_cast<int>(rgba.red * 255)), green(static_cast<int>(rgba.green * 255)), blue(static_cast<int>(rgba.blue * 255)), alpha(static_cast<int>(rgba.alpha * 255)) {}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
Voxel::Voxel(uint32_t color) {
    red = color & 0xFF;
    green = (color >> 8) & 0xFF;
    blue = (color >> 16) & 0xFF;
    alpha = (color >> 24) & 0xFF;
}
#pragma clang diagnostic pop

uint32_t Voxel::GetColor() const {
    return static_cast<uint32_t>(red | (green << 8) | (blue << 16) | (alpha << 24));
}

const Voxel Voxel::EMPTY = Voxel(0, 0, 0, 0);