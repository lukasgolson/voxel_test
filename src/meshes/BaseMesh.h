//
// Created by lukas on 2023-11-13.
//

#ifndef VOXEL_TEST_BASEMESH_H
#define VOXEL_TEST_BASEMESH_H


#include <vector>
#include "../ShaderProgram.h"

class BaseMesh {
protected:
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLsizei vertexCount = 0;

    virtual void SetVertexAttributes() = 0;

    virtual void SetupMesh(int elementsPerVertex);


public:
    BaseMesh();

    virtual ~BaseMesh(); // Virtual destructor

    virtual void Render();

    virtual std::vector<float> GetVertexData() = 0; // Pure virtual function
};

#endif //VOXEL_TEST_BASEMESH_H
