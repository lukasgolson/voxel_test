//
// Created by olson.stu on 2024-01-04.
//

#include <pybind11/pybind11.h>
#include "../src/WindowManager.h"
#include "GLFW/glfw3.h"
#include "../src/VoxelEngine.h"

namespace py = pybind11;



int launch() {

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



    return 0;
}

PYBIND11_MODULE(pythonModule, m) {
    m.doc() = "VoxelTest Python Binding"; // optional module docstring

    m.def("launch", &launch, "A function that launches the voxel engine"); // We should probably use a class instead of a function;
    // We can then use the class to store the voxel engine and call update on it; Maybe we can even use the class to store the window and the voxel engine;
    // We could probably add a update callback to the class that is called every frame; This would allow us to add custom logic to the voxel engine;
    // that class would then be the only thing that is exposed to python; We could then use the class to store the voxel engine and the window;
}
