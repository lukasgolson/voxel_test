#include "Coordinate.h"

Coordinate::Coordinate(int x, int y, int z) : x(x), y(y), z(z) {}

Coordinate::Coordinate(int index, int dimensionLength) {
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

Coordinate Coordinate::operator+(const Coordinate& other) const {
    return Coordinate(x + other.x, y + other.y, z + other.z);
}

Coordinate Coordinate::operator-(const Coordinate& other) const {
    return Coordinate(x - other.x, y - other.y, z - other.z);
}

Coordinate Coordinate::operator*(const Coordinate& other) const {
    return Coordinate(x * other.x, y * other.y, z * other.z);
}

Coordinate Coordinate::operator/(const Coordinate& other) const {
    if (other.x == 0 || other.y == 0 || other.z == 0) {
        throw std::invalid_argument("Division by zero in one or more components");
    }
    return Coordinate(x / other.x, y / other.y, z / other.z);
}

int Coordinate::GetFlatIndex(int dimensionLength) const {
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
