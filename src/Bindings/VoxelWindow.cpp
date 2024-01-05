//
// Created by olson.stu on 2024-01-05.
//

#include <memory>
#include "VoxelWindow.h"
#include "../WindowManager.h"



VoxelWindow::VoxelWindow(const int resolutionX, const int resolutionY, const RGBA backgroundColor) {

    windowManager = std::make_unique<WindowManager>();
    window = windowManager->createWindow(resolutionX, resolutionY);


    voxelEngine = std::make_unique<VoxelEngine>();

    BackgroundColor = backgroundColor;

}

VoxelWindow::~VoxelWindow() {
    glfwTerminate();
}

void VoxelWindow::Update() {

    if (glfwWindowShouldClose(window)) {
        // print some error message
        std::printf("Window closed\n");
        return;
    }

    // Clear the color buffer
    glClearColor(BackgroundColor.red, BackgroundColor.green, BackgroundColor.blue, BackgroundColor.alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    voxelEngine->update();

    // Swap front and back buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool VoxelWindow::ShouldClose() {
    return glfwWindowShouldClose(window);
}