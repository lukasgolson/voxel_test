//
// Created by lukas on 2023-11-12.
//

#ifndef VOXEL_TEST_FLYINGCAMERA_H
#define VOXEL_TEST_FLYINGCAMERA_H


#include "Camera.h"
#include "voxelEngine.h"

class FlyingCamera : public Camera {
    void update(double delta_time) override;

public:
    FlyingCamera(glm::vec3 position, float pitch, float yaw) : Camera(position, pitch, yaw) {}

    void keyboardInput(double deltaTime);

    void mouseInput(double deltaTime);

    double lastMouseX;
    double lastMouseY;
};


#endif //VOXEL_TEST_FLYINGCAMERA_H
