//
// Created by olson.stu on 2024-01-05.
//

#ifndef VOXEL_TEST_RGB_H
#define VOXEL_TEST_RGB_H


#include "Rgba.h"

struct RGBA;

struct RGB {
    float red, green, blue;

    RGB() : red(0), green(0), blue(0) {};

    RGB(const double r, const double g, const double b) : red(r), green(g), blue(b) {};

    operator RGBA() const; // Implicit conversion to RGBA


    explicit RGB(const RGBA& rgba);
};


#endif //VOXEL_TEST_RGB_H
