cmake_minimum_required(VERSION 3.9.0)

project(Renderer VERSION 0.1 LANGUAGES CXX)

# compilation c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(renderer main.cpp)
target_link_libraries(renderer ${OPENGL_gl_LIBRARY})
target_link_libraries(renderer glfw)
