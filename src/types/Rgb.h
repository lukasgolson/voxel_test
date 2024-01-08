//
// Created by olson.stu on 2024-01-05.
//

#ifndef VOXEL_TEST_RGB_H
#define VOXEL_TEST_RGB_H


#include <stdexcept>

struct RGBA;

struct RGB {
    float red, green, blue;

    RGB() : red(0), green(0), blue(0) {};

    RGB(const double r, const double g, const double b) : red(r), green(g), blue(b) {

        // add error checking to ensure values are between 0 and 1

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

        if (error) {
            throw std::runtime_error("RGB values must be between 0 and 1");
        }

    };

    operator RGBA() const; // Implicit conversion to RGBA


    explicit RGB(const RGBA& rgba);
};


#endif //VOXEL_TEST_RGB_H
