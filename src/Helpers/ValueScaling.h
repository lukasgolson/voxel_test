//
// Created by olson.stu on 2023-11-24.
//

#pragma once

#include <cstdint>
#include <iostream>
#include <type_traits>

template <typename T, typename U>
uint32_t mapToUint32Range(T value, U size) {
    static_assert(std::is_arithmetic<T>::value, "Value must be a numeric type.");
    static_assert(std::is_arithmetic<U>::value, "Size must be a numeric type.");

    if (size == 0) {
        std::cerr << "Size cannot be zero." << std::endl;
        return 0;
    }

    // Scale factor calculation: target range / original range
    double scaleFactor = static_cast<double>(UINT32_MAX) / size;

    // Map the value
    return static_cast<uint32_t>(value * scaleFactor);
}