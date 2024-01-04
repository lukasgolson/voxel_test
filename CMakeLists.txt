cmake_minimum_required(VERSION 3.21)
project(voxel_test)

set(CMAKE_CXX_STANDARD 17)



find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Python bindings
find_package(Python 3.6 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

add_subdirectory(dependencies/glad)


set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -lpthread -static-libgcc -static-libstdc++")

add_definitions(-DGLFW_INCLUDE_NONE)

add_executable(main main.cpp
        src/ShaderProgram.cpp
        src/ShaderProgram.h
        src/Camera.cpp
        src/Camera.h
        src/VoxelEngine.cpp
        src/VoxelEngine.h
        src/FlyingCamera.cpp
        src/FlyingCamera.h
        src/meshes/BaseMesh.cpp
        src/meshes/BaseMesh.h
        src/meshes/QuadMesh.cpp
        src/meshes/QuadMesh.h
        src/Scene.cpp
        src/Scene.h
        src/meshes/QuadMesh.cpp
        src/meshes/QuadMesh.h
        src/OpenGlCommon.h
        src/meshes/ChunkMesh.cpp
        src/meshes/ChunkMesh.h
        src/Chunk.cpp
        src/Chunk.h
        src/Voxel.h
        src/VoxelVertex.h
        src/Settings.cpp
        src/Settings.h
        src/VoxelWorld.cpp
        src/VoxelWorld.h
        src/types/Coordinate.h
        src/Helpers/ValueScaling.h
        src/Helpers/Color.h
)




pybind11_add_module(pythonModule python/Example.cpp)


# Only proceed if building on Windows
if(WIN32)
    # Set the main target to be a Windows GUI application
    set_target_properties(main PROPERTIES WIN32_EXECUTABLE TRUE)

    # Define variables for resource file paths
    set(RESOURCE_FILE ${CMAKE_SOURCE_DIR}/main.rc)
    set(RESOURCE_OBJECT ${CMAKE_BINARY_DIR}/main_rc.o)

    # Find the windres program used for compiling resource files
    find_program(WINDRES_EXECUTABLE NAMES windres)
    if(NOT WINDRES_EXECUTABLE)
        message(FATAL_ERROR "windres not found")
    endif()

    # Custom command to compile the resource file
    add_custom_command(
            OUTPUT ${RESOURCE_OBJECT}
            COMMAND ${WINDRES_EXECUTABLE} -i ${RESOURCE_FILE} -o ${RESOURCE_OBJECT}
            DEPENDS ${RESOURCE_FILE}
            COMMENT "Compiling resource file ${RESOURCE_FILE}"
    )



    # Custom target to manage the resource file compilation
    add_custom_target(
            GenerateMainRC
            DEPENDS ${RESOURCE_OBJECT}
            COMMENT "Generating resource object file"
    )

    # Ensure the main target depends on the custom target
    add_dependencies(main GenerateMainRC)

    # Link the compiled resource object file with the main target
    target_link_libraries(main PRIVATE ${RESOURCE_OBJECT})
endif()


set_target_properties(main PROPERTIES OUTPUT_NAME "voxel_engine")


target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE glm::glm)
target_link_libraries(main PRIVATE glad)

target_link_libraries(pythonModule PRIVATE glfw)
target_link_libraries(pythonModule PRIVATE glm::glm)
target_link_libraries(pythonModule PRIVATE glad)

# Set optimizations
if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()



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
