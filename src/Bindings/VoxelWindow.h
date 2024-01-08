//
// Created by olson.stu on 2024-01-05.
//

#pragma once


#include "GLFW/glfw3.h"
#include "../VoxelEngine.h"
#include "../types/Rgba.h"
#include "../Window/WindowManager.h"


class VoxelWindow {
    std::unique_ptr<WindowManager> windowManager;


    GLFWwindow *window;
    std::unique_ptr<VoxelEngine> voxelEngine;


    public: VoxelWindow(int worldSize, int chunkSize, const int resolutionX, const int resolutionY, const RGBA backgroundColor = RGBA(0.15, 0.10, 0.10, 1.0));

    ~VoxelWindow();

    void Update();

    bool ShouldClose();

    RGBA BackgroundColor;



    void SetVoxel(const Coordinate coordinate, const RGBA color);

    RGBA GetVoxel(const Coordinate coordinate);
};

