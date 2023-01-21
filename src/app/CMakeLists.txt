cmake_minimum_required(VERSION 3.24)

add_library(app
        Application.cpp
        )

target_include_directories(app PUBLIC
        )

target_link_libraries(app ${OpenCL_LIBRARY})