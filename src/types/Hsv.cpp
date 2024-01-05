//
// Created by olson.stu on 2024-01-05.
//

#include <cmath>
#include "Hsv.h"

HSV::HSV(const RGB &rgb) {

    float red = rgb.red / 255.0;
    float green = rgb.green / 255.0;
    float blue = rgb.blue / 255.0;


    float maxVal = std::max(red, std::max(green, blue));
    float minVal = std::min(red, std::min(green, blue));
    float delta = maxVal - minVal;

    // Value (V)
    value = maxVal;

    // Saturation (S)
    if (maxVal != 0) {
        saturation = delta / maxVal;
    } else {
        saturation = 0;
        hue = -1; // Undefined hue for black
    }

    // Hue (H)
    if (red == maxVal) {
        hue = (green - blue) / delta; // Between yellow & magenta
    } else if (green == maxVal) {
        hue = 2 + (blue - red) / delta; // Between cyan & yellow
    } else {
        hue = 4 + (red - green) / delta; // Between magenta & cyan
    }

    hue *= 60; // Convert to degrees
    if (hue < 0) {
        hue += 360;
    }
}

HSV::operator RGB() const {

    RGB rgb;
    float chroma = value * saturation;
    float X = chroma * (1 - fabs(fmod(hue / 60.0, 2) - 1));
    float match = value - chroma;

    if (hue >= 0 && hue < 60) {
        rgb.red = chroma, rgb.green = X, rgb.blue = 0;
    } else if (hue >= 60 && hue < 120) {
        rgb.red = X, rgb.green = chroma, rgb.blue = 0;
    } else if (hue >= 120 && hue < 180) {
        rgb.red = 0, rgb.green = chroma, rgb.blue = X;
    } else if (hue >= 180 && hue < 240) {
        rgb.red = 0, rgb.green = X, rgb.blue = chroma;
    } else if (hue >= 240 && hue < 300) {
        rgb.red = X, rgb.green = 0, rgb.blue = chroma;
    } else {
        rgb.red = chroma, rgb.green = 0, rgb.blue = X;
    }

    rgb.red += match;
    rgb.green += match;
    rgb.blue += match;

    return rgb;
}
