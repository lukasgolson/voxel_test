//
// Created by lukas on 2023-11-12.
//

#include "Camera.h"
#include <iostream>
#include <glm/trigonometric.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>


Camera::Camera(glm::vec3 position, float yaw, float pitch) {

    int windowX, windowY = 0;

    auto vertical_fov = glm::radians(45.0f);


    this->window = glfwGetCurrentContext();
    glfwGetWindowSize(window, &windowX, &windowY);

    float aspect_ratio = (float) windowX / (float) windowY;

    auto near_plane = 0.1f;
    auto far_plane = 2000.0f;

    this->projectionMatrix = glm::perspective(vertical_fov, aspect_ratio, near_plane, far_plane);
    this->viewMatrix = glm::mat4{1.0f};

    this->position = position;
    this->yaw = glm::radians(yaw);
    this->pitch = glm::radians(pitch);
}


void Camera::update(double delta_time) {
    this->updateRelativeVectors();
    this->updateViewMatrix();
}

void Camera::updateViewMatrix() {
    this->viewMatrix = glm::lookAt(this->position, this->position + this->forward, this->up);
}

void Camera::updateRelativeVectors() {
    this->forward.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->forward.y = sin(glm::radians(this->pitch));
    this->forward.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

    this->forward = glm::normalize(this->forward);
    this->right = glm::normalize(glm::cross(this->forward, glm::vec3{0.0f, 1.0f, 0.0f}));
    this->up = glm::normalize(glm::cross(this->right, this->forward));
}

void Camera::updatePitch(float delta_pitch) {
    this->pitch += delta_pitch;
    this->pitch = glm::clamp(this->pitch, -89.0f, 89.0f);

    std::cout << "Camera pitch: " << this->pitch << std::endl;
}

void Camera::updateYaw(float delta_yaw) {
    this->yaw += delta_yaw;

    if (yaw > 180.0f) {
        yaw -= 360.0f;
    } else if (yaw < -180.0f) {
        yaw += 360.0f;
    }

    std::cout << "Camera yaw: " << this->yaw << std::endl;
}

void Camera::updatePosition(glm::vec3 delta_position) {
    // Apply position delta to camera position, adjusted for camera orientation
    this->position += (delta_position.x * this->right);
    this->position += (delta_position.y * this->up);
    this->position += (delta_position.z * this->forward);

    std::cout << "Camera position: " << this->position.x << ", " << this->position.y << ", " << this->position.z << std::endl;
}

glm::mat<4, 4, float> Camera::GetViewMatrix() const {
    return this->viewMatrix;
}

glm::mat<4, 4, float> Camera::GetProjectionMatrix() const {
    return this->projectionMatrix;
}




