//
// Created by Clemens on 20/01/2023.
//

#include "Window.h"

//#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window(int width, int height, const char* title) : windowWidth(width), windowHeight(height){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    this->glfwWindow = glfwCreateWindow(1920, 1080, "Ultimate City Generator", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported!\n" << std::endl;
}

Window::Window() {}

void Window::kill() {
    glfwDestroyWindow(this->glfwWindow);
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(this->glfwWindow);
}
