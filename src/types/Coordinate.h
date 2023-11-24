//
// Created by lukas on 2023-11-20.
//

#pragma once


#include <stdexcept>

struct Coordinate {
    Coordinate(int x, int y, int z) : x(x), y(y), z(z) {}

    Coordinate(int index, int size) {
        if (size <= 0) {
            throw std::out_of_range("size must be greater than 0");
        }

        if (index < 0 || index >= size * size * size) {
            throw std::out_of_range("index must fit within the volume space of size");
        }

        int area = size * size;
        y = index / area;
        int remainder = index % area;
        z = remainder / size;
        x = remainder % size;
    }


    int x;
    int y;
    int z;

    [[nodiscard]] int GetFlatIndex(int size) {

        if (size <= 0) {
            throw std::out_of_range("size must be greater than 0");
        }

        if (x < 0 || x >= size || y < 0 || y >= size || z < 0 || z >= size) {
            throw std::out_of_range("coordinates must fit within the volume space of size");
        }

        int area = size * size;

        int index = x + size * z + area * y;

        return index;
    }
};




