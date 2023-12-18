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

    [[nodiscard]] int GetFlatIndex(int dimension_size) {

        if (dimension_size <= 0) {
            throw std::out_of_range("dimension_size must be greater than 0");
        }

        if (x < 0 || x >= dimension_size || y < 0 || y >= dimension_size || z < 0 || z >= dimension_size) {
            throw std::out_of_range("coordinates must fit within the space of dimension_size * dimension_size * dimension_size");
        }

        int area = dimension_size * dimension_size;

        int index = x + dimension_size * z + area * y;

        return index;
    }
};




