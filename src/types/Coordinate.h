//
// Created by lukas on 2023-11-20.
//

#pragma once

#include <stdexcept>

struct Coordinate {
    Coordinate(int x, int y, int z);
    Coordinate(int index, int dimensionLength);

    int x;
    int y;
    int z;

    Coordinate operator+(const Coordinate& other) const;
    Coordinate operator-(const Coordinate& other) const;
    Coordinate operator*(const Coordinate& other) const;
    Coordinate operator/(const Coordinate& other) const;

    [[nodiscard]] int GetFlatIndex(int dimensionLength) const;
};
