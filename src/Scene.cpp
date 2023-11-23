//
// Created by lukas on 2023-11-16.
//

#include "Scene.h"
#include "meshes/QuadMesh.h"
#include "VoxelWorld.h"


Scene::Scene(ShaderProgram *shaderProgram) {


    // this->world = new VoxelWorld();

    this->chunk = new Chunk();
    this->chunkMesh = new ChunkMesh();
    this->chunkMesh->AssociateChunk(this->chunk);

    this->chunk->BuildVoxels();

    this->shaderProgram = shaderProgram;


}

void Scene::Update() {
    this->Render();
}

void Scene::Render() {
    //  this->world->Render();
    //this->quadMesh->Render();

    this->shaderProgram->SetModelMatrix(this->chunkMesh->GetModelMatrix());

    this->chunkMesh->Render();
}
