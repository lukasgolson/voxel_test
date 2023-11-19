#define GLFW_INCLUDE_NONE

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/ShaderProgram.h"
#include "src/Camera.h"
#include "src/Scene.h"

Camera *cam;

double resolutionX = 1200, resolutionY = 900;

double lastX = resolutionX / 2, lastY = resolutionY / 2;
bool firstMouse = true;


void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (key == GLFW_KEY_A) {
        cam->updatePosition(glm::vec3{-0.1f, 0.0f, 0.0f});
    }

    if (key == GLFW_KEY_D) {
        cam->updatePosition(glm::vec3{0.1f, 0.0f, 0.0f});
    }

    if (key == GLFW_KEY_W) {
        cam->updatePosition(glm::vec3{0.0f, 0.0f, 0.1f});
    }

    if (key == GLFW_KEY_S) {
        cam->updatePosition(glm::vec3{0.0f, 0.0f, -0.1f});
    }

    if (key == GLFW_KEY_SPACE) {
        cam->updatePosition(glm::vec3{0.0f, 0.1f, 0.0f});
    }

    if (key == GLFW_KEY_LEFT_SHIFT) {
        cam->updatePosition(glm::vec3{0.0f, -0.1f, 0.0f});
    }
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    double xoffset = xpos - lastX;
    double yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.05f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    cam->updateYaw(xoffset);
    cam->updatePitch(yoffset);
}


int main() {
    GLFWwindow *window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(resolutionX, resolutionY, "Voxel Renderer", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }




    glfwMakeContextCurrent(window);

    gladLoadGL((GLADloadfunc) glfwGetProcAddress);


    glViewport(0, 0, resolutionX, resolutionY);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);


    cam = new Camera(glm::vec2{resolutionX, resolutionY}, glm::vec3{0.0f, 0.0f, 3.0f}, 0.0f, 0.0f);
    auto *sp = new ShaderProgram("shaders", "quad", cam);
    auto *scene = new Scene(sp);



    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    //  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClearColor(0.15f, 0.10f, 0.10f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // update camera and shader program
        cam->update();
        sp->Update();

        scene->Render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

