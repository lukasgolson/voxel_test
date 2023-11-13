//
// Created by lukas on 2023-11-12.
//

#ifndef VOXEL_TEST_CAMERA_H
#define VOXEL_TEST_CAMERA_H


#include <glm/detail/type_mat4x4.hpp>

class Camera {

public:
    Camera(glm::vec2 window_size, glm::vec3 position, float yaw, float pitch);

    void updatePitch(float delta_pitch);

    void updateYaw(float delta_yaw);

    virtual void update();

    void updateViewMatrix();

    void updateRelativeVectors();

    glm::mat<4, 4, float> GetViewMatrix() const;

    glm::mat<4, 4, float> GetProjectionMatrix() const;


    void updatePosition(glm::vec3 delta_position);

private:

    float yaw;
    float pitch;

    glm::mat4 view_matrix{};
    glm::mat<4, 4, float> projection_matrix{};
    glm::vec3 position{};

    glm::vec3 up = glm::vec3{0.0f, 1.0f, 0.0f};
    glm::vec3 right = glm::vec3{1.0f, 0.0f, 0.0f};
    glm::vec3 forward = glm::vec3{0.0f, 0.0f, -1.0f};


};


#endif //VOXEL_TEST_CAMERA_H
