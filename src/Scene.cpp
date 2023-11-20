//
// Created by lukas on 2023-11-16.
//

#include "Scene.h"
#include "meshes/QuadMesh.h"


Scene::Scene() {
    this->quadMesh = new QuadMesh();

    this->chunk = new Chunk();
    this->chunkMesh = new ChunkMesh(this->chunk);
}

void Scene::Update() {
    this->Render();
}

void Scene::Render() {
    this->chunkMesh->Render();
    //this->quadMesh->Render();
}
