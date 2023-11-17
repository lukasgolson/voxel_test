//
// Created by lukas on 2023-11-13.
//

#include "BaseMesh.h"

BaseMesh::BaseMesh() {

}

GLuint BaseMesh::GetVertexArrayObject() {
    auto vertexData = GetVertexData();

    // Generate Vertex Array Object (VAO)
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate Vertex Buffer Object (VBO) for vertex data
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_STATIC_DRAW);


    SetVertexAttributes();


    // Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return VAO;
}

void BaseMesh::Render() {



    // Bind the Vertex Array Object (VAO) for rendering
    GLuint VAO = GetVertexArrayObject();
    glBindVertexArray(VAO);

    // Issue OpenGL draw calls to render the mesh
    glDrawArrays(GL_TRIANGLES, 0, 3); // Assuming a triangle with 3 vertices

    // Unbind the VAO after rendering
    glBindVertexArray(0);
}
