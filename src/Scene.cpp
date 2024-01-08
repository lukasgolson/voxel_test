//
// Created by lukas on 2023-11-16.
//

#include <iostream>
#include "Scene.h"
#include "VoxelWorld.h"

Scene::Scene(ShaderProgram *shaderProgram, int worldSize, int chunkSize) {
    this->shaderProgram = shaderProgram;
    this->voxelWorld = new VoxelWorld(worldSize, chunkSize);
}

void Scene::Update() {
    this->Render();
}

void Scene::Render() {
    //  this->world->Render();
    //this->quadMesh->Render();

    this->voxelWorld->Render(this->shaderProgram);
}
