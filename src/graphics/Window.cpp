//
// Created by Clemens on 20/01/2023.
//

#include "Window.h"
#include "VulkanUtils.h"

//#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window(int width, int height, const char* title) : windowWidth(width), windowHeight(height){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    // TODO: add window resizing
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);

    this->instance = VulkanUtils::createInstance();
}

Window::Window() {}

void Window::kill() {
    glfwDestroyWindow(this->glfwWindow);
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(this->glfwWindow);
}
