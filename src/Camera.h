//
// Created by lukas on 2023-11-12.
//

#ifndef VOXEL_TEST_CAMERA_H
#define VOXEL_TEST_CAMERA_H

#include "GlCommon.h"
#include <glm/vec3.hpp>
#include <glm/ext/matrix_float4x4.hpp>


class Camera {

public:
    Camera(glm::vec3 position, float yaw, float pitch);

    void updatePitch(float delta_pitch);

    void updateYaw(float delta_yaw);

    virtual void update(double delta_time);

    void updateViewMatrix();

    void updateRelativeVectors();

    [[nodiscard]] glm::mat<4, 4, float> GetViewMatrix() const;

    [[nodiscard]] glm::mat<4, 4, float> GetProjectionMatrix() const;


    void updatePosition(glm::vec3 delta_position);

private:

    float yaw;
    float pitch;

    glm::mat4 viewMatrix{};
    glm::mat<4, 4, float> projectionMatrix{};

    glm::vec3 up = glm::vec3{0.0f, 1.0f, 0.0f};
    glm::vec3 right = glm::vec3{1.0f, 0.0f, 0.0f};
    glm::vec3 forward = glm::vec3{0.0f, 0.0f, -1.0f};


protected:
    GLFWwindow *window;
    glm::vec3 position{};
};


#endif //VOXEL_TEST_CAMERA_H
