//
// Created by Clemens on 21/01/2023.
//

#include "MasterArea.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui_internal.h"

namespace GuiAreas {
    MasterArea::MasterArea(GLFWwindow *glfwWindow){
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        (void)io;
        ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
        ImGui_ImplOpenGL3_Init("#version 130");
        this->windowFlags = ImGuiWindowFlags_MenuBar |ImGuiWindowFlags_NoDocking;
        this->windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        this->windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;


    }

    void MasterArea::Render() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGuiViewport* viewport = ImGui::GetWindowViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);

        ImGui::Begin("DockSpace", nullptr, this->windowFlags);
        ImGuiIO& io = ImGui::GetIO();
        if(io.ConfigFlags & ImGuiConfigFlags_DockingEnable){
            ImGuiID dockSpaceID = ImGui::GetID("DockSpace");
            ImGui::DockSpace(dockSpaceID, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

            if(firstTimeRender){
                firstTimeRender = false;

                ImGui::DockBuilderRemoveNode(dockSpaceID);
                ImGui::DockBuilderAddNode(dockSpaceID, ImGuiDockNodeFlags_PassthruCentralNode | ImGuiDockNodeFlags_DockSpace);
                ImGui::DockBuilderSetNodeSize(dockSpaceID, ImGui::GetWindowViewport()->Size);

                ImGuiID dockViewportID;
                auto DockSettingsID = ImGui::DockBuilderSplitNode(dockSpaceID, ImGuiDir_Right, 0.2f, nullptr, &dockSpaceID);
                auto dockNodesID = ImGui::DockBuilderSplitNode(dockSpaceID, ImGuiDir_Down, 0.35f, nullptr, &dockSpaceID);
                auto dockIDunnoID = ImGui::DockBuilderSplitNode(dockSpaceID, ImGuiDir_Left, 0.2f, nullptr, &dockViewportID);
                ImGui::DockBuilderDockWindow("Settings", DockSettingsID);
                ImGui::DockBuilderDockWindow("Nodes", dockNodesID);
                ImGui::DockBuilderDockWindow("IDunno", dockIDunnoID);
                ImGui::DockBuilderDockWindow("Viewport", dockViewportID);
                ImGui::DockBuilderFinish(dockSpaceID);
            }
        }
        ImGui::End();

        ImGui::Begin("IDunno");
        ImGui::Text("I have no idea what should go here!");
        ImGui::End();

        ImGui::Begin("Nodes");
        ImGui::Text("Nodes panel!");
        ImGui::End();

        ImGui::Begin("Settings");
        ImGui::Text("Settings panel!");
        ImGui::End();

        ImGui::Begin("Viewport");
        ImGui::Text("Viewport panel!");
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void MasterArea::End() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    MasterArea::MasterArea() {

    }

    void MasterArea::Initialize() {

    }
} // GuiAreas