include_directories(. ../lib/glad/include ../lib/glfw/include ../lib/imgui)
add_subdirectory(graphics)

# add app as last subdir
add_subdirectory(app)