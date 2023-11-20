//
// Created by lukas on 2023-11-13.
//

#pragma once


#include <vector>
#include "glad/gl.h"

class BaseMesh {
protected:
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLsizei vertexCount = 0;

    virtual void SetVertexAttributes() = 0;

    virtual void SetupMesh(int elementsPerVertex);


public:

    virtual ~BaseMesh(); // Virtual destructor

    virtual void Render();

    virtual std::vector<float> GetVertexData() = 0; // Pure virtual function
};
