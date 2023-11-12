//
// Created by lukas on 2023-11-12.
//

#ifndef VOXEL_TEST_CAMERA_H
#define VOXEL_TEST_CAMERA_H


#include <glm/detail/type_mat4x4.hpp>

class Camera {

public:
    Camera();

    void update_pitch(float delta_pitch);
    void update_yaw(float delta_yaw);

    void refresh();

    void update();

    void update_view_matrix();

    void update_relative_vectors();

private:

    float yaw;
    float pitch;

    glm::mat4 view_matrix;
    glm::mat<4, 4, float> projection_matrix;
    glm::vec3 position;

    glm::vec3 up = glm::vec3{0.0f, 1.0f, 0.0f};
    glm::vec3 right = glm::vec3{1.0f, 0.0f, 0.0f};
    glm::vec3 forward = glm::vec3{0.0f, 0.0f, -1.0f};


};


#endif //VOXEL_TEST_CAMERA_H
