//
// Created by olson.stu on 2024-01-05.
//

#include <memory>
#include "VoxelWindow.h"
#include "../WindowManager.h"



VoxelWindow::VoxelWindow(int resolutionX, int resolutionY, RGBA backgroundColor) {

    WindowManager windowManager;
    window = windowManager.createWindow(resolutionX, resolutionY);
    voxelEngine = std::make_unique<VoxelEngine>();

    BackgroundColor = backgroundColor;

}

VoxelWindow::~VoxelWindow() {
    glfwTerminate();
}

void VoxelWindow::Refresh() {
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