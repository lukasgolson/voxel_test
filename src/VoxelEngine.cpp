//
// Created by lukas on 2023-11-12.
//

#include <stdexcept>
#include "VoxelEngine.h"
#include "Camera/FlyingCamera.h"
#include "Scene.h"

VoxelEngine::VoxelEngine(int worldSize, int chunkSize) {

    this->camera = new FlyingCamera(glm::vec3{10.0f, 6.f, -4.0f}, -1312.93f, 8568.09f);
    this->shaderProgram = new ShaderProgram("shaders", "chunk", camera);
    this->scene = new Scene(this->shaderProgram, worldSize, chunkSize);
}


void VoxelEngine::update() {

    double currentFrameTime = glfwGetTime();
    this->deltaTime = currentFrameTime - lastFrameTime;
    this->lastFrameTime = currentFrameTime;

    this->camera->update(this->deltaTime);

    this->shaderProgram->Update();
    this->scene->Update();


    // create a cube in the middle of the world
/*
    for (int i = 1; i < 11; i++) {
        this->SetVoxel(Coordinate(i, 1, 1), Voxel(1, 1, 1, 1));
    }*/


}

void VoxelEngine::SetVoxel(const Coordinate coordinate, const Voxel voxel) {

    this->scene->voxelWorld->SetVoxel(coordinate, voxel);

}

Voxel VoxelEngine::GetVoxel(const Coordinate coordinate) {
    return this->scene->voxelWorld->GetVoxel(coordinate);
}
