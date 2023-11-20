//
// Created by lukas on 2023-11-12.
//

#include <cmath>
#include <iostream>
#include "FlyingCamera.h"

bool firstMouse = true;

void FlyingCamera::update(double delta_time) {
    keyboardInput(delta_time);
    mouseInput(delta_time);
    Camera::update(delta_time);

}

void FlyingCamera::keyboardInput(double deltaTime) {

    const float speed = 10.0f;

    if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS) {
        updatePosition({-speed * deltaTime, 0.0, 0.0});
    }

    if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS) {
        updatePosition({speed * deltaTime, 0.0, 0.0});
    }

    if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS) {
        updatePosition({0.0, 0.0, speed * deltaTime});
    }

    if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS) {
        updatePosition({0.0, 0.0, -speed * deltaTime});
    }

    if (glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        updatePosition({0.0, speed * deltaTime, 0.0});
    }

    if (glfwGetKey(this->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        updatePosition({0.0, -speed * deltaTime, 0.0});
    }

}




void FlyingCamera::mouseInput(double delta_time) {
    double xpos, ypos;
    glfwGetCursorPos(this->window, &xpos, &ypos);

    if (firstMouse) {
        this->lastMouseX = xpos;
        this->lastMouseY = ypos;
        firstMouse = false;
        return; // Skip this frame to avoid jump in camera orientation
    }

    const float sensitivity = 10.0f; // Inline constant for sensitivity
    float xoffset = (xpos - this->lastMouseX) * sensitivity * delta_time;
    float yoffset = (this->lastMouseY - ypos) * sensitivity * delta_time;




    if (std::fabs(xoffset) > 0.001f) {
        this->lastMouseX = xpos;
        this->updateYaw(xoffset);
    }

    if (std::fabs(yoffset) > 0.001f) {
        this->lastMouseY = ypos;
        this->updatePitch(yoffset);
    }
}


