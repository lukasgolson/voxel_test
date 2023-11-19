//
// Created by lukas on 2023-11-12.
//

#include <iostream>
#include "FlyingCamera.h"

void FlyingCamera::update(double delta_time) {
    keyboardInput(0.1 * delta_time);
    mouseInput();
    Camera::update(delta_time);

}

void FlyingCamera::keyboardInput(double velocity){

    if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS) {
        updatePosition({velocity, 0.0, 0.0});
    }

    if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS) {
        updatePosition({-velocity, 0.0, 0.0});
    }

    if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS) {
        updatePosition({0.0, 0.0, velocity});
    }

    if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS) {
        updatePosition({0.0, 0.0, -velocity});
    }

    if (glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        updatePosition({0.0, velocity, 0.0});
    }

    if (glfwGetKey(this->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        updatePosition({0.0, -velocity, 0.0});
    }

}



void FlyingCamera::mouseInput() {
    double xpos, ypos;
    glfwGetCursorPos(this->window, &xpos, &ypos);

    const float sensitivity = 0.1f; // Inline constant for sensitivity
    float xoffset = (xpos - this->lastMouseX) * sensitivity;
    float yoffset = (this->lastMouseY - ypos) * sensitivity;

    this->lastMouseX = xpos;
    this->lastMouseY = ypos;

    // Considering a minimal threshold for movement
    if (fabs(xoffset) > 0.001f) {
        this->updatePitch(xoffset);
    }

    if (fabs(yoffset) > 0.001f) {
        this->updateYaw(yoffset);
    }
}
