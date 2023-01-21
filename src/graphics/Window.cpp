//
// Created by Clemens on 20/01/2023.
//

#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title) : windowWidth(width), windowHeight(height){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if(this->glfwWindow == nullptr){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(this->glfwWindow);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(this->glfwWindow, framebufferSizeCallback);
}

Window::Window() {}

void Window::kill() {
    glfwDestroyWindow(this->glfwWindow);
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(this->glfwWindow);
}
