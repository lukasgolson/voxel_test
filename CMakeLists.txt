cmake_minimum_required(VERSION 3.21)
project(voxel_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp
        ShaderProgram.cpp
        ShaderProgram.h)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm::glm)

add_subdirectory(dependencies/glad)
target_link_libraries(main PRIVATE glad)
