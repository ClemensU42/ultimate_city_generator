cmake_minimum_required(VERSION 3.24)
project(ultimate_city_generator)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCL REQUIRED)
find_package(Vulkan REQUIRED)

link_directories(${OpenCL_LIBRARY} ${Vulkan_LIB_LIST})
include_directories(${OpenCL_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS})

add_subdirectory(lib/glfw)
add_subdirectory(src)

add_executable(ultimate_city_generator main.cpp)

target_link_libraries(ultimate_city_generator ${OpenCL_LIBRARY} ${Vulkan_LIBS_LIST} app graphics)
target_include_directories(ultimate_city_generator PUBLIC src)