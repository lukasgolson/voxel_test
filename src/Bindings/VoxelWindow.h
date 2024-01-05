//
// Created by olson.stu on 2024-01-05.
//

#pragma once


#include "GLFW/glfw3.h"
#include "../VoxelEngine.h"
#include "../types/Rgba.h"


class VoxelWindow {
    GLFWwindow *window;
    std::unique_ptr<VoxelEngine> voxelEngine;

    VoxelWindow(int resolutionX, int resolutionY, RGBA backgroundColor = RGBA(0.15, 0.10, 0.10, 1.0));

    ~VoxelWindow();

    void Refresh();

    bool ShouldClose();

    RGBA BackgroundColor;
};

