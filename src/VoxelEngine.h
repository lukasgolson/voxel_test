#pragma once


#include "Camera.h"
#include "ShaderProgram.h"
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
};


