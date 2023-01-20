cmake_minimum_required(VERSION 3.24)

add_library(graphics
        ${CMAKE_SOURCE_DIR}/lib/glad/src/glad.c
        Window.cpp)

target_include_directories(graphics PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/glfw/include
        ${CMAKE_SOURCE_DIR}/lib/glad/include
        )
target_link_libraries(graphics glfw)