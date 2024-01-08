#pragma once


#include "GLFW/glfw3.h"
#include <stdexcept>

class WindowManager {
public:
    WindowManager();
    ~WindowManager();

    GLFWwindow* createWindow(int width, int height, const char* title = "Voxel Test");
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    static void errorCallback(int error, const char* description);
    GLFWwindow* window;
};
