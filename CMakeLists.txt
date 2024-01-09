cmake_minimum_required(VERSION 3.21)
project(voxel_test)

set(CMAKE_CXX_STANDARD 17)


include("${CMAKE_CURRENT_SOURCE_DIR}/generate_shader_loader.cmake")


if (MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT> #---------|
            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
            $<$<CONFIG:Release>:/MT> #--|
    )

    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")

endif ()


if (MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
endif ()

# Set optimizations
if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
else ()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif ()

# import flags
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Threads)


# Python bindings
find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG REQUIRED)


# Add subdirectories for dependencies (GLFW, GLAD, etc)
add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glfw)


add_definitions(-DGLFW_INCLUDE_NONE)

add_executable(main main.cpp
        src/Rendering/ShaderProgram.cpp
        src/Rendering/ShaderProgram.h
        src/Camera/Camera.cpp
        src/Camera/Camera.h
        src/VoxelEngine.cpp
        src/VoxelEngine.h
        src/Camera/FlyingCamera.cpp
        src/Camera/FlyingCamera.h
        src/meshes/BaseMesh.cpp
        src/meshes/BaseMesh.h
        src/meshes/QuadMesh.cpp
        src/meshes/QuadMesh.h
        src/Scene.cpp
        src/Scene.h
        src/meshes/QuadMesh.cpp
        src/meshes/QuadMesh.h
        src/Helpers/OpenGlCommon.h
        src/meshes/ChunkMesh.cpp
        src/meshes/ChunkMesh.h
        src/Chunk.cpp
        src/Chunk.h
        src/types/Voxel.h
        src/VoxelVertex.h
        src/Settings.h
        src/VoxelWorld.cpp
        src/VoxelWorld.h
        src/types/Coordinate.h
        src/Helpers/ValueScaling.h
        src/Window/WindowManager.h
        src/Window/WindowManager.cpp
        src/Window/WindowManager.h
        src/Enums/ShaderType.h
        src/Bindings/VoxelWindow.cpp
        src/Bindings/VoxelWindow.h
        src/types/Rgb.cpp
        src/types/Rgb.h
        src/types/Rgba.cpp
        src/types/Rgba.h
        src/types/Hsv.cpp
        src/types/Hsv.h
        src/types/Coordinate.cpp
        src/types/Voxel.cpp
)

# Add a custom target to regenerate the shader loader
add_custom_target(
        RegenerateShaderLoader ALL
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/generate_shader_loader.cmake
        COMMENT "Regenerating Shader Loader"
)

add_dependencies(main RegenerateShaderLoader)
target_sources(main PRIVATE ${OUTPUT_FILE})

set_target_properties(main PROPERTIES OUTPUT_NAME "voxel_engine")


pybind11_add_module(voxelTest python/binding_VoxelEngine.cpp)

target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE glm::glm)
target_link_libraries(main PRIVATE glad)

target_link_libraries(voxelTest PRIVATE Threads::Threads)

target_link_libraries(voxelTest PRIVATE glfw)
target_link_libraries(voxelTest PRIVATE glm::glm)
target_link_libraries(voxelTest PRIVATE glad)


if (WIN32)
    # Set the main target to be a Windows GUI application
    set_target_properties(main PROPERTIES WIN32_EXECUTABLE FALSE)


    if (MINGW)
        # Define variables for resource file paths
        set(RESOURCE_FILE ${CMAKE_SOURCE_DIR}/main.rc)
        set(RESOURCE_OBJECT ${CMAKE_BINARY_DIR}/main_rc.o)

        # Find the windres program used for compiling resource files
        find_program(WINDRES_EXECUTABLE NAMES windres)
        if (NOT WINDRES_EXECUTABLE)
            message(WARNING "windres not found")

        else ()
            message(STATUS "windres found: ${WINDRES_EXECUTABLE}")

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
        endif ()
    endif ()


endif ()




# Retrieve source files from main
get_target_property(MAIN_SOURCES main SOURCES)

# Add the source files to the python module
target_sources(voxelTest PRIVATE ${MAIN_SOURCES})

