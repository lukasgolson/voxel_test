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


    for (int i = 0; i < 8; ++i) {
        auto block_size = WORLD_SIZE * CHUNK_SIZE;

        auto coords = this->currentCoords;



        auto color = convertCoordinateToColor(coords, block_size);

        auto voxel = Voxel(color.r * 255, color.g * 255, color.b * 255);


        this->vw->SetBlock(this->currentCoords, voxel);



        this->currentCoords.x++;

        if (this->currentCoords.x >= block_size) {
            this->currentCoords.x = 0;
            this->currentCoords.z++;
            std::cout << "z: " << this->currentCoords.z << std::endl;
        }

        if (this->currentCoords.z >= block_size) {
            this->currentCoords.z = 0;
            this->currentCoords.y++;
            std::cout << "y: " << this->currentCoords.y << std::endl;
        }

        if (this->currentCoords.y >= block_size) {
            this->currentCoords.y = 0;
            this->currentCoords.x = 0;
            this->currentCoords.z = 0;

            std::cout << "z: " << this->currentCoords.z << std::endl;
        }
    }


}

void Scene::Render() {
    //  this->world->Render();
    //this->quadMesh->Render();

    this->vw->Render(this->shaderProgram);
}
