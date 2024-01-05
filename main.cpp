#include "src/OpenGlCommon.h"
#include <iostream>
#include <memory>
#include "src/VoxelEngine.h"
#include "src/WindowManager.h"


int main() {
    const int resolutionX = 1200;
    const int resolutionY = 900;

    WindowManager windowManager;
    GLFWwindow* window = windowManager.createWindow(resolutionX, resolutionY);


    auto voxelEngine = std::make_unique<VoxelEngine>();


    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClearColor(0.15f, 0.10f, 0.10f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        voxelEngine->update();

        // Swap front and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

