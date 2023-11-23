//
// Created by lukas on 2023-11-16.
//

#include "Scene.h"
#include "meshes/QuadMesh.h"
#include "VoxelWorld.h"


Scene::Scene(ShaderProgram *shaderProgram) {


    // this->world = new VoxelWorld();



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
