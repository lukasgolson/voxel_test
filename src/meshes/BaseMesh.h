//
// Created by lukas on 2023-11-13.
//

#ifndef VOXEL_TEST_BASEMESH_H
#define VOXEL_TEST_BASEMESH_H


#include <vector>
#include "../ShaderProgram.h"

class BaseMesh {

    ShaderProgram *shaderProgram;



public:
    BaseMesh();
    virtual std::vector<float> GetVertexData() = 0;

    virtual GLuint GetVertexArrayObject();

    virtual void Render();
};


#endif //VOXEL_TEST_BASEMESH_H
