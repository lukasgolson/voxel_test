#include <fstream>
#include <vector>
#include <iostream>

#include "../Helpers/OpenGlCommon.h"
#include <glm/gtc/type_ptr.hpp>
#include "ShaderProgram.h"
#include "../Camera/Camera.h"


ShaderProgram::ShaderProgram(const std::string &shaderDir, const std::string &shaderName, Camera *camera) {
    std::printf("Loading shader %s from %s\n", shaderName.c_str(), shaderDir.c_str());
    this->program = ShaderProgram::LoadShaders(shaderName);
    this->camera = camera;
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->program);
}


void ShaderProgram::Update() {
    // Set the shader program to use for rendering
    glUseProgram(this->program);

    // Set the uniforms for the shader program / camera matrices
    this->SetUniforms();
}


void ShaderProgram::SetUniforms() {


    this->SetUniform("m_projection", this->camera->GetProjectionMatrix());
    this->SetUniform("m_view", this->camera->GetViewMatrix());
    this->SetUniform("m_model", glm::mat4(1.0f));
}

void ShaderProgram::SetUniform(const std::string &name, const glm::mat4 &value) {
    auto location = this->GetUniformLocation(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::SetModelMatrix(const glm::mat4 &value) {
    this->SetUniform("m_model", value);
}

auto ShaderProgram::GetUniformLocation(const std::string &name) const -> GLint {
    return glGetUniformLocation(this->program, name.c_str());
}

/*std::string ShaderProgram::LoadShaderFile(const std::string &filePath) {
    std::string shaderCode;
    std::ifstream shaderFile(filePath);

    if (!shaderFile.is_open()) {
        throw std::runtime_error("Failed to open shader file: " + filePath);
    }

    std::string line;
    while (std::getline(shaderFile, line)) {
        shaderCode += line + "\n";
    }

    shaderFile.close();
    return shaderCode;
}*/

GLuint ShaderProgram::CompileShader(GLenum shaderType, const std::string &shaderCode) {
    GLuint shader = glCreateShader(shaderType);
    const char *shaderSource = shaderCode.c_str();
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> log(logLength);
        glGetShaderInfoLog(shader, logLength, nullptr, log.data());

        throw std::runtime_error(std::string(log.data()));
    }

    return shader;
}


GLuint ShaderProgram::LoadShaders(const std::string &shaderName) {



    auto vertexShaderCode = LoadShaderFile( shaderName, ShaderType::Vertex);
    auto fragmentShaderCode = LoadShaderFile( shaderName, ShaderType::Fragment);

    GLuint program = glCreateProgram();

    GLuint vertexShader;
    GLuint fragmentShader;

    try {
        std::printf("Compiling vertex shader...\n");
        vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderCode);
        glAttachShader(program, vertexShader);

    } catch (std::exception &e) {
        throw std::runtime_error("Failed to compile vertex shader: " + std::string(e.what()));
    }

    try {
        std::printf("Compiling fragment shader...\n");
        fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
        glAttachShader(program, fragmentShader);

    } catch (std::exception &e) {
        throw std::runtime_error("Failed to compile fragment shader: " + std::string(e.what()));
    }


    glLinkProgram(program);

    // Check for shader program linking errors
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> log(logLength);
        glGetProgramInfoLog(program, logLength, nullptr, log.data());

        throw std::runtime_error("Shader program linking failed: " + std::string(log.data()));
    } else {
        std::printf("Shader program linking successful for %s shader \n", shaderName.c_str());
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    return program;
}
