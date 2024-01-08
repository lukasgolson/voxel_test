//
// Created by olson.stu on 2024-01-05.
//

#ifndef VOXEL_TEST_RGBA_H
#define VOXEL_TEST_RGBA_H


#include "Rgb.h"

struct RGB;

struct RGBA {
    float red, green, blue, alpha;

    RGBA() : red(0), green(0), blue(0), alpha(0) {}

    RGBA(const float r, const float g, const float b, const float a) : red(r), green(g), blue(b), alpha(a) {


        bool error = false;

        if (red > 1) {
            red = 1;
            error = true;
        }

        if (green > 1) {
            green = 1;
            error = true;
        }

        if (blue > 1) {
            blue = 1;
            error = true;
        }

        if (alpha > 1) {
            alpha = 1;
            error = true;
        }

        if (error) {
            throw std::runtime_error("RGBA values must be between 0 and 1");
        }

    }

    RGBA(const RGB& rgb, const float alpha = 1.0);

    operator RGB() const;
};


#endif //VOXEL_TEST_RGBA_H
