//
// Created by lukas on 2023-11-16.
//

#ifndef VOXEL_TEST_SCENE_H
#define VOXEL_TEST_SCENE_H


#include "meshes/QuadMesh.h"

class Scene {
public:
    Scene();
    void Update();
    void Render();

    QuadMesh *quad;
};


#endif //VOXEL_TEST_SCENE_H
