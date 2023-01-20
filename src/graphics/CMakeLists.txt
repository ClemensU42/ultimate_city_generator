cmake_minimum_required(VERSION 3.24)

add_library(graphics)

target_include_directories(graphics PUBLIC ${CMAKE_SOURCE_DIR}/lib/glfw/include)