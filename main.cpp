#include "src/GlCommon.h"
#include <iostream>
#include "src/voxelEngine.h"

double resolutionX = 1200, resolutionY = 900;


void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow *CreateWindow(glm::vec<2, int> window_size) {
    GLFWwindow *new_window;

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    new_window = glfwCreateWindow(window_size[0], window_size[1], "Voxel Renderer", NULL, NULL);
    if (!new_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }


    glfwMakeContextCurrent(new_window);
    gladLoadGL((GLADloadfunc) glfwGetProcAddress);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);

    glfwSetInputMode(new_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    return new_window;
}


int main() {
    GLFWwindow *window = CreateWindow({resolutionX, resolutionY});


    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);


    auto VoxelEngine = new voxelEngine({resolutionX, resolutionY});


    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClearColor(0.15f, 0.10f, 0.10f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        VoxelEngine->update();

        // Swap front and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

