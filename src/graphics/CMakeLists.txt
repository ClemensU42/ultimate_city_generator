cmake_minimum_required(VERSION 3.24)

add_library(graphics
        ${CMAKE_SOURCE_DIR}/lib/glad/src/glad.c
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/backends/imgui_impl_opengl3.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_draw.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_tables.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_widgets.cpp

        Window.cpp Mesh.cpp Shader.cpp Shader.h gui_areas/ViewportArea.cpp gui_areas/ViewportArea.h gui_areas/NodeArea.cpp gui_areas/NodeArea.h gui_areas/MasterArea.cpp gui_areas/MasterArea.h)

target_include_directories(graphics PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/glfw/include
        ${CMAKE_SOURCE_DIR}/lib/glad/include
        ${CMAKE_SOURCE_DIR}/lib/imgui
        )
target_link_libraries(graphics glfw)