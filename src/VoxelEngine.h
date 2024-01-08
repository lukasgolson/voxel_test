#pragma once


#include "Camera/Camera.h"
#include "Rendering/ShaderProgram.h"
#include "Scene.h"

class VoxelEngine {
    Camera *camera;
    ShaderProgram *shaderProgram;
    Scene *scene;

public:
    VoxelEngine();
    ~VoxelEngine() = default;
    void update();

    double deltaTime;
    double lastFrameTime;

    void SetVoxel(const Coordinate coordinate, const Voxel voxel);
    Voxel GetVoxel(const Coordinate coordinate);
};


