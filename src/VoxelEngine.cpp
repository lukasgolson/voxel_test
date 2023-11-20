//
// Created by lukas on 2023-11-12.
//

#include <stdexcept>
#include "VoxelEngine.h"
#include "FlyingCamera.h"
#include "Scene.h"

class Scene;

VoxelEngine::VoxelEngine() {

    this->camera = new FlyingCamera(glm::vec3{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f);
    this->shaderProgram = new ShaderProgram("shaders", "chunk", camera);
    this->scene = new Scene();
}


void VoxelEngine::update() {

    double currentFrameTime = glfwGetTime();
    this->deltaTime = currentFrameTime - lastFrameTime;
    this->lastFrameTime = currentFrameTime;

    this->camera->update(this->deltaTime);

    this->shaderProgram->Update();
    this->scene->Update();


}
