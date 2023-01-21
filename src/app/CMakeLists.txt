cmake_minimum_required(VERSION 3.24)

add_library(app
        Application.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/backends/imgui_impl_opengl3.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_draw.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_tables.cpp
        ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_widgets.cpp)

target_include_directories(app PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/imgui)

target_link_libraries(app ${OpenCL_LIBRARY})