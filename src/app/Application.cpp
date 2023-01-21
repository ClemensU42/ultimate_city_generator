//
// Created by Clemens on 19/01/2023.
//
#include "Application.h"

#include "graphics/Window.h"
#include "graphics/gui_areas/MasterArea.h"

#include <CL/cl.hpp>

#include <iostream>

GuiAreas::MasterArea masterArea;

void Application::setup() {
    std::cout << "hello world!" << std::endl;
    this->window = Window(1920, 1080, "Ultimate City Generator");



    cl_int err;
    cl_uint numPlatforms;

    err = clGetPlatformIDs(0, nullptr, &numPlatforms);
    if(CL_SUCCESS == err){
        std::cout << "\nDetected OpenCL platforms: " << numPlatforms << std::endl;
    } else {
        std::cout << "\nError calling clGetPlatformIDs. Error Code: " << err << std::endl;
    }

    masterArea = GuiAreas::MasterArea(this->window.glfwWindow);
    masterArea.Initialize();
}

void Application::update() {
    glfwPollEvents();
}

void Application::render() {

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    masterArea.Render();
/*
    ImGui::DockSpaceOverViewport(ImGui::GetWindowViewport());
    ImGui::Begin("first window");

    ImGui::Text("Hello, world %d", 123);

    ImGui::End();

*/

    glfwSwapBuffers(this->window.glfwWindow);
}

void Application::end(){
    masterArea.End();
    this->window.kill();
}