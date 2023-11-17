//
// Created by lukas on 2023-11-13.
//

#include "QuadMesh.h"


std::vector<float> QuadMesh::GetVertexData() {

    std::vector<float> positions = {
            // positions
            -0.5f, -0.5f, 0.0f, // bottom left
            0.5f, -0.5f, 0.0f, // bottom right
            0.5f, 0.5f, 0.0f, // top right
            -0.5f, 0.5f, 0.0f, // top left
    };

    std::vector<float> color = {
            // colors
            1.0f, 0.0f, 0.0f, // bottom left
            0.0f, 1.0f, 0.0f, // bottom right
            0.0f, 0.0f, 1.0f, // top right
            1.0f, 1.0f, 0.0f, // top left
    };


    std::vector<float> vertexData;
    vertexData.reserve(positions.size() + color.size());

    // Interleave position and color data
    for (size_t i = 0; i < positions.size(); i += 3) {
        vertexData.insert(vertexData.end(), positions.begin() + i, positions.begin() + i + 3);
        vertexData.insert(vertexData.end(), color.begin() + i, color.begin() + i + 3);
    }

    return vertexData;

}

GLuint QuadMesh::GetVertexArrayObject() {
    return BaseMesh::GetVertexArrayObject();
}

void QuadMesh::SetVertexAttributes() {
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}


void QuadMesh::Render() {
    BaseMesh::Render();
}
