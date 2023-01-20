include_directories(. ../lib/glad/include ../lib/glfw/include)
add_subdirectory(graphics)

# add app as last subdir
add_subdirectory(app)