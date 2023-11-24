
#pragma once

#include <iostream>
#include <cmath>
#include "../types/Coordinate.h"
#include "../Voxel.h"

struct RGB {
    double r, g, b;
};

struct HSV {
    double h, s, v = 0;
};

RGB hsvToRgb(HSV hsv) {
    RGB rgb;
    double C = hsv.v * hsv.s;
    double X = C * (1 - fabs(fmod(hsv.h / 60.0, 2) - 1));
    double m = hsv.v - C;

    if (hsv.h >= 0 && hsv.h < 60) {
        rgb.r = C, rgb.g = X, rgb.b = 0;
    } else if (hsv.h >= 60 && hsv.h < 120) {
        rgb.r = X, rgb.g = C, rgb.b = 0;
    } else if (hsv.h >= 120 && hsv.h < 180) {
        rgb.r = 0, rgb.g = C, rgb.b = X;
    } else if (hsv.h >= 180 && hsv.h < 240) {
        rgb.r = 0, rgb.g = X, rgb.b = C;
    } else if (hsv.h >= 240 && hsv.h < 300) {
        rgb.r = X, rgb.g = 0, rgb.b = C;
    } else {
        rgb.r = C, rgb.g = 0, rgb.b = X;
    }

    rgb.r += m;
    rgb.g += m;
    rgb.b += m;

    return rgb;
}

RGB convertCoordinateToColor(Coordinate pos, double maxCoordValue) {
    // Normalize coordinates
    auto x = pos.x / maxCoordValue;
    auto y = pos.y / maxCoordValue;
    auto z = pos.z / maxCoordValue;

    // Use x for hue, y and z could also be used
    HSV hsv;
    hsv.h = (x * 120) + (y * 120) + (z * 120); // Map x,y,z to [0, 360]

    hsv.s = 0.4 + (x * 0.2) + (y * 0.2) + (z * 0.2);       // Saturation
    hsv.v = 1.0;       // Value


    return hsvToRgb(hsv);
}


