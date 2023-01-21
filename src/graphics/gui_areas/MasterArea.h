//
// Created by Clemens on 21/01/2023.
//

#ifndef ULTIMATE_CITY_GENERATOR_MASTERAREA_H
#define ULTIMATE_CITY_GENERATOR_MASTERAREA_H

#include "GLFW/glfw3.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "ViewportArea.h"

namespace GuiAreas {
    class MasterArea {

        bool firstTimeRender = true;
        ImGuiWindowFlags windowFlags;

        ViewportArea viewportArea;

    public:
        MasterArea();
        explicit MasterArea(GLFWwindow *glfwWindow);
        void Initialize();
        void Render();
        void End();
    };

} // GuiAreas

#endif //ULTIMATE_CITY_GENERATOR_MASTERAREA_H
