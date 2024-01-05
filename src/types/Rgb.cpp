//
// Created by olson.stu on 2024-01-05.
//

#include "Rgb.h"

RGB::operator RGBA() const {
    return {red, green, blue, 1.0};
}

RGB::RGB(const RGBA &rgba) {
    red = rgba.red;
    green = rgba.green;
    blue = rgba.blue;
}
