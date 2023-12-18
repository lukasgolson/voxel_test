//
// Created by lukas on 2023-11-20.
//

#pragma once


#include <stdexcept>

struct Coordinate {
    Coordinate(int x, int y, int z) : x(x), y(y), z(z) {}

    Coordinate(int index, int dimensionLength) {
        if (dimensionLength <= 0) {
            throw std::out_of_range("dimensionLength must be greater than 0");
        }

        if (index < 0 || index >= dimensionLength * dimensionLength * dimensionLength) {
            throw std::out_of_range("index must fit within the volume space of dimensionLength");
        }

        int area = dimensionLength * dimensionLength;
        y = index / area;
        int remainder = index % area;
        z = remainder / dimensionLength;
        x = remainder % dimensionLength;
    }


    int x;
    int y;
    int z;

    // Overload the + operator
    Coordinate operator+(const Coordinate& other) const {
        return Coordinate(x + other.x, y + other.y, z + other.z);
    }

    // Overload the - operator
    Coordinate operator-(const Coordinate& other) const {
        return Coordinate(x - other.x, y - other.y, z - other.z);
    }

    // Overload the * operator for element-wise multiplication
    Coordinate operator*(const Coordinate& other) const {
        return Coordinate(x * other.x, y * other.y, z * other.z);
    }

    // Overload the / operator for element-wise division
    Coordinate operator/(const Coordinate& other) const {
        if (other.x == 0 || other.y == 0 || other.z == 0) {
            throw std::invalid_argument("Division by zero in one or more components");
        }
        return Coordinate(x / other.x, y / other.y, z / other.z);
    }

    [[nodiscard]] int GetFlatIndex(int dimensionLength) {

        if (dimensionLength <= 0) {
            throw std::out_of_range("dimensionLength must be greater than 0");
        }

        if (x < 0 || x >= dimensionLength || y < 0 || y >= dimensionLength || z < 0 || z >= dimensionLength) {
            throw std::out_of_range("coordinates must fit within the space of dimensionLength * dimensionLength * dimensionLength");
        }

        int area = dimensionLength * dimensionLength;

        int index = x + dimensionLength * z + area * y;

        return index;
    }
};




