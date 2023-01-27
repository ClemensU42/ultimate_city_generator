//
// Created by Clemens on 20/01/2023.
//

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#ifndef ULTIMATE_CITY_GENERATOR_WINDOW_H
#define ULTIMATE_CITY_GENERATOR_WINDOW_H


class Window {
public:
    GLFWwindow* glfwWindow;
    int windowWidth;
    int windowHeight;

public:
    Window(int width, int height, const char* title);
    Window();
    void kill();

    bool shouldClose();
};


#endif //ULTIMATE_CITY_GENERATOR_WINDOW_H
