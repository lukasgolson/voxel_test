#define GLFW_INCLUDE_NONE

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/ShaderProgram.h"
#include "src/Camera.h"
#include "src/Scene.h"

Camera *cam;

void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (key == GLFW_KEY_A) {
        std::cout << "A pressed" << std::endl;
        cam->updatePosition(glm::vec3{-0.1f, 0.0f, 0.0f});
    }

    if (key == GLFW_KEY_D) {
        std::cout << "D pressed" << std::endl;
        cam->updatePosition(glm::vec3{0.1f, 0.0f, 0.0f});
    }

    if (key == GLFW_KEY_W) {
        std::cout << "W pressed" << std::endl;
        cam->updatePosition(glm::vec3{0.0f, 0.0f, 0.1f});
    }

    if (key == GLFW_KEY_S) {
        std::cout << "S pressed" << std::endl;
        cam->updatePosition(glm::vec3{0.0f, 0.0f, -0.1f});
    }
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


    auto *scene = new Scene();
    cam = new Camera(glm::vec2{640 * 2, 480 * 2}, glm::vec3{0.0f, 0.0f, -1.0f}, -90.0f, 0.0f);
    auto *sp = new ShaderProgram("shaders", "test", cam);


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClearColor(0.15f, 0.10f, 0.10f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // update camera
        cam->update();

        // Use the shader program
        sp->Refresh();

        // Render the scene
        scene->Render();



        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

