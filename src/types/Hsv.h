//
// Created by olson.stu on 2024-01-05.
//

#ifndef VOXEL_TEST_HSV_H
#define VOXEL_TEST_HSV_H


#include "Rgb.h"

struct RGB;

struct HSV {
    float hue, saturation, value;

    HSV(float h = 0, float s = 0, float v = 0) : hue(h), saturation(s), value(v) {};

    explicit HSV(const RGB& rgb); // Explicit conversion from RGB

    explicit operator RGB() const; // Explicit conversion to RGB
};



#endif //VOXEL_TEST_HSV_H
