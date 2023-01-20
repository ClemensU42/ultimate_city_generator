//
// Created by Clemens on 19/01/2023.
//
#include "Application.h"

#include "graphics/Window.h"

#include <iostream>

void Application::setup() {
    std::cout << "hello world!" << std::endl;
    this->window = Window(1920, 1080, "Ultimate City Generator");
}

void Application::update() {
    glfwPollEvents();
}

void Application::render() {
    glfwSwapBuffers(this->window.glfwWindow);
}

void Application::end(){
    this->window.kill();
}