//
// Created by lukas on 2023-11-12.
//

#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void Camera::refresh() {
    auto vertical_fov = glm::radians(45.0f);
    auto aspect_ratio = 4.0f / 3.0f;

    auto near_plane = 0.1f;
    auto far_plane = 1000.0f;

    this->projection_matrix = glm::perspective(vertical_fov, aspect_ratio, near_plane, far_plane);
    this->view_matrix = glm::mat4{0.0f};

    this->position = glm::vec3(position);
    this->yaw = glm::radians(yaw);
    this->pitch = glm::radians(pitch);

}

void Camera::update() {
    this->update_relative_vectors();
    this->update_view_matrix();
}

void Camera::update_view_matrix() {
    this->view_matrix = glm::lookAt(this->position, this->position + this->forward, this->up);
}

void Camera::update_relative_vectors() {
    this->forward.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->forward.y = sin(glm::radians(this->pitch));
    this->forward.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

    this->forward = glm::normalize(this->forward);
    this->right = glm::normalize(glm::cross(this->forward, glm::vec3{0.0f, 1.0f, 0.0f}));
    this->up = glm::normalize(glm::cross(this->right, this->forward));
}

void Camera::update_pitch(float delta_pitch) {
    this->pitch += delta_pitch;
    this->pitch = glm::clamp(this->pitch, -89.0f, 89.0f);
}

void Camera::update_yaw(float delta_yaw) {
    this->yaw += delta_yaw;
}


