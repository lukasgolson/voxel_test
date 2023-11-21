//
// Created by lukas on 2023-11-13.
//

#pragma once


#include <vector>
#include <glm/ext/matrix_float4x4.hpp>
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

    virtual glm::mat4 GetModelMatrix() { return glm::mat4(1.0f); };
};
