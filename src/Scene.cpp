//
// Created by lukas on 2023-11-16.
//

#include <iostream>
#include "Scene.h"
#include "meshes/QuadMesh.h"
#include "VoxelWorld.h"
#include "Helpers/ValueScaling.h"
#include "Helpers/Color.h"


Scene::Scene(ShaderProgram *shaderProgram) {
    this->shaderProgram = shaderProgram;
    this->vw = new VoxelWorld();
}

void Scene::Update() {
    this->Render();
}

void Scene::Render() {
    //  this->world->Render();
    //this->quadMesh->Render();

    this->vw->Render(this->shaderProgram);
}
