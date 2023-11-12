cmake_minimum_required(VERSION 3.21)
project(voxel_test)

set(CMAKE_CXX_STANDARD 14)


add_executable(main main.cpp
        ShaderProgram.cpp
        ShaderProgram.h
        Camera.cpp
        Camera.h
        voxelEngine.cpp
        voxelEngine.h)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm::glm)

add_subdirectory(dependencies/glad)
target_link_libraries(main PRIVATE glad)


# Specify the shaders directory
set(SHADERS_DIR ${CMAKE_SOURCE_DIR}/shaders)
set(SHADERS_DEST_DIR ${CMAKE_BINARY_DIR}/shaders)

# Copy the shaders directory to the build directory initially
file(COPY ${SHADERS_DIR} DESTINATION ${SHADERS_DEST_DIR})

# Create a custom target to copy shaders when they change
add_custom_target(CopyShaders
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${SHADERS_DIR} ${SHADERS_DEST_DIR}
        DEPENDS ${SHADERS_DIR}
)

# Make MyApp depend on CopyShaders, so it's copied before building MyApp
add_dependencies(main CopyShaders)
