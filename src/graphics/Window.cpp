//
// Created by Clemens on 20/01/2023.
//

#include "Window.h"
#include "VulkanUtils.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

Window::Window(int width, int height, const char* title) : windowWidth(width), windowHeight(height){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    // TODO: add window resizing
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);

#ifndef NDEBUG
    if(!VulkanUtils::checkValidationLayerSupport(validationLayers)){
        throw std::runtime_error("validation layers requested, but not available!");
    }
#endif

    this->instance = VulkanUtils::createInstance(validationLayers);

    if(glfwCreateWindowSurface(this->instance, this->glfwWindow, nullptr, &this->surface) != VK_SUCCESS){
        throw std::runtime_error("failed to create window surface!");
    }

    this->physicalDevice = VulkanUtils::pickPhysicalDevice(this->instance, this->surface);
    this->device = VulkanUtils::createLogicalDevice(this->physicalDevice, validationLayers, &this->graphicsQueue, this->surface);
}

Window::Window() {}

void Window::kill() {
    vkDestroyDevice(this->device, nullptr);

    // destroy the surface before destroying the instance!
    vkDestroySurfaceKHR(this->instance, this->surface, nullptr);

    vkDestroyInstance(this->instance, nullptr);

    glfwDestroyWindow(this->glfwWindow);
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(this->glfwWindow);
}
