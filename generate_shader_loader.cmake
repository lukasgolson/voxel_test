# Custom target to regenerate the shader loader every build


set(SHADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/shaders")
set(OUTPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/generated/GeneratedShaderLoader.cpp")

file(REMOVE ${OUTPUT_FILE})




# Start writing the generated file
file(WRITE ${OUTPUT_FILE} "#include <string>\n\n")
file(WRITE ${OUTPUT_FILE} "#include <stdexcept>\n\n")
file(APPEND ${OUTPUT_FILE} "#include \"../src/ShaderProgram.h\"\n\n")



# Function to process each shader file
function(process_shader SHADER_PATH)
    get_filename_component(SHADER_NAME ${SHADER_PATH} NAME_WE)
    get_filename_component(SHADER_EXT ${SHADER_PATH} LAST_EXT)

    # Determine shader type based on file extension
    if(SHADER_EXT STREQUAL ".frag")
        set(SHADER_TYPE "Fragment")
    elseif(SHADER_EXT STREQUAL ".vert")
        set(SHADER_TYPE "Vertex")
    else()
        message(FATAL_ERROR "Unknown shader file extension: ${SHADER_EXT}")
    endif()

    file(READ ${SHADER_PATH} SHADER_CODE)

    # Prepare the shader code as a C++ string literal
    set(SHADER_CODE "R\"(${SHADER_CODE})\"")

    file(APPEND ${OUTPUT_FILE} "const std::string ${SHADER_NAME}${SHADER_TYPE}Shader = ${SHADER_CODE};\n\n")
endfunction()

# Generate LoadShaderFile function
file(APPEND ${OUTPUT_FILE} "std::string ShaderProgram::LoadShaderFile(const std::string &shaderName, const std::string &shaderType) {\n")

file(GLOB SHADER_FILES "${SHADER_DIR}/*.frag" "${SHADER_DIR}/*.vert")
foreach(SHADER_FILE ${SHADER_FILES})
    process_shader(${SHADER_FILE})
    get_filename_component(SHADER_NAME ${SHADER_FILE} NAME_WE)
    get_filename_component(SHADER_EXT ${SHADER_FILE} LAST_EXT)

    if(SHADER_EXT STREQUAL ".frag")
        set(SHADER_TYPE "Fragment")
    elseif(SHADER_EXT STREQUAL ".vert")
        set(SHADER_TYPE "Vertex")
    endif()

    file(APPEND ${OUTPUT_FILE} "    if (shaderName == \"${SHADER_NAME}\" && shaderType == \"${SHADER_TYPE}\") return ${SHADER_NAME}${SHADER_TYPE}Shader;\n")
endforeach()

file(APPEND ${OUTPUT_FILE} "    throw std::runtime_error(\"Shader not found: \" + shaderName + \" - \" + shaderType);\n")
file(APPEND ${OUTPUT_FILE} "}\n")
