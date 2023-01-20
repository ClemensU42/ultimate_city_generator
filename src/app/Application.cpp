//
// Created by Clemens on 19/01/2023.
//
#include "Application.h"

#include "graphics/Window.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <iostream>

void Application::setup() {
    std::cout << "hello world!" << std::endl;
    this->window = Window(1920, 1080, "Ultimate City Generator");

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(this->window.glfwWindow, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

void Application::update() {
    glfwPollEvents();
}

void Application::render() {

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("first window");

    ImGui::Text("Hello, world %d", 123);

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(this->window.glfwWindow);
}

void Application::end(){
    this->window.kill();
}