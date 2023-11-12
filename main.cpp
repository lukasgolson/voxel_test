#define GLFW_INCLUDE_NONE

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderProgram.h"
#include "Camera.h"

void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}


static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}



int main() {
    GLFWwindow *window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640 * 2, 480 * 2, "Voxel Renderer", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL((GLADloadfunc) glfwGetProcAddress);


    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);


    auto *sp = new ShaderProgram("shaders", "test");
    auto *cam = new Camera();


    // Define vertices and colors
    GLfloat vertices[] = {
            // Triangle
            -0.5f, -0.5f, 0.0f,  // Vertex 1 (bottom-left)
            0.5f, -0.5f, 0.0f,   // Vertex 2 (bottom-right)
            0.0f, 0.5f, 0.0f     // Vertex 3 (top-center)
    };

    GLfloat colors[] = {
            // Vertex Colors
            1.0f, 0.0f, 0.0f,  // Red for the top vertex
            0.0f, 1.0f, 0.0f,  // Green for the bottom-left vertex
            0.0f, 0.0f, 1.0f   // Blue for the bottom-right vertex
    };

    // Create and bind VAO and VBO
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Combine vertex and color data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);  // Position attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)sizeof(vertices));
    glEnableVertexAttribArray(1);  // Color attribute

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClearColor(0.15f, 0.10f, 0.10f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program
        sp->Refresh();

        // Bind the VAO
        glBindVertexArray(VAO);

        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Unbind the VAO
        glBindVertexArray(0);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
