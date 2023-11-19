//
// Created by lukas on 2023-11-16.
//

#include "Scene.h"
#include "meshes/QuadMesh.h"

Scene::Scene(ShaderProgram *shaderProgram) {
    this->quad = new QuadMesh();

}

void Scene::Update() {
    this->Render();
}

void Scene::Render() {
    this->quad->Render();
}
