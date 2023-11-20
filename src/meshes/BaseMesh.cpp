//
// Created by lukas on 2023-11-13.
//

#include "BaseMesh.h"



BaseMesh::~BaseMesh() {
    // Clean up the VAO and VBO when the mesh is destroyed
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void BaseMesh::SetupMesh(int elementsPerVertex) {
    auto vertexData = GetVertexData();
    vertexCount = static_cast<GLsizei>(vertexData.size() / elementsPerVertex); // Update this based on your vertex structure

    // Generate and bind Vertex Array Object (VAO)
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind Vertex Buffer Object (VBO)
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_STATIC_DRAW);

    SetVertexAttributes();

    // Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void BaseMesh::Render() {
    // Bind the Vertex Array Object (VAO) for rendering
    glBindVertexArray(VAO);

    // Issue OpenGL draw calls to render the mesh
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    // Unbind the VAO after rendering
    glBindVertexArray(0);
}
