//
// Created by lukas on 2023-11-12.
//

#pragma once



#include "Camera.h"
#include "VoxelEngine.h"

class FlyingCamera : public Camera {
    void update(double delta_time) override;

public:
    FlyingCamera(glm::vec3 position, float pitch, float yaw) : Camera(position, pitch, yaw) {}

    void keyboardInput(double deltaTime);

    void mouseInput(double deltaTime);

    double lastMouseX;
    double lastMouseY;
};
