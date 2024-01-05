//
// Created by olson.stu on 2024-01-05.
//

#include "Rgba.h"

RGBA::RGBA(const RGB &rgb, const float a) {
    red = rgb.red;
    green = rgb.green;
    blue = rgb.blue;
    alpha = a;
}

RGBA::operator RGB() const {
    return {red, green, blue};
}
