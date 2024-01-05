//
// Created by lukas on 2023-11-18.
//

#include "QuadMesh.h"


QuadMesh::QuadMesh() {
    // Set up the mesh (VAO, VBO, etc.) using BaseMesh's setup functionality
    SetupMesh(6);
}

void QuadMesh::SetVertexAttributes() {
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

std::vector<float> QuadMesh::GetVertexData() {
    // Vertex data: position (x, y, z) followed by color (red, g, b)
    return {
            // Vertex 1: Position, Color
            -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
            // Vertex 2
            1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
            // Vertex 3
            1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
            // Vertex 4
            -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
            // Vertex 5
            1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
            // Vertex 6
            -1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f
    };
}
