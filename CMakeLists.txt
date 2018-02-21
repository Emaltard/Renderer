cmake_minimum_required(VERSION 3.9.0)

project(Renderer VERSION 0.1 LANGUAGES CXX)

# compilation c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)

add_executable(renderer main.cpp imgui_impl_glfw_gl3.cpp imgui.cpp imgui_demo.cpp imgui_draw.cpp)
target_link_libraries(renderer ${OPENGL_gl_LIBRARY})
target_link_libraries(renderer glfw)
target_link_libraries(renderer GLEW)
