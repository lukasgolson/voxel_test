#include <fstream>
#include <vector>
#include <iostream>
#include "ShaderProgram.h"
#include "Camera.h"
#include <glm/gtc/type_ptr.hpp>

ShaderProgram::ShaderProgram(const std::string &shaderDir, const std::string &shaderName, Camera *camera) {
    std::printf("Loading shader %s from %s\n", shaderName.c_str(), shaderDir.c_str());
    this->program = ShaderProgram::LoadShaders(shaderDir, shaderName);
    this->camera = camera;
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->program);
}


void ShaderProgram::Refresh() {
    glUseProgram(this->program);
    this->SetUniforms();
}

void ShaderProgram::SetUniforms() {
    auto viewLocation = this->GetUniformLocation("view");
    auto viewMatrix = this->camera->GetViewMatrix();

    auto modelLocation = this->GetUniformLocation("model");
    auto modelMatrix = glm::mat4{1.0f};

    auto projectionLocation = this->GetUniformLocation("projection");
    auto projectionMatrix = this->camera->GetProjectionMatrix();

    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

}

void ShaderProgram::Update() {

}


auto ShaderProgram::GetUniformLocation(const std::string &name) const -> GLint {
    return glGetUniformLocation(this->program, name.c_str());
}

std::string ShaderProgram::LoadShaderFile(const std::string &filePath) {
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
}

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

        throw std::runtime_error("Shader compilation failed: " + std::string(log.data()));
    }

    return shader;
}


GLuint ShaderProgram::LoadShaders(const std::string &shaderDir, const std::string &shaderName) {
    std::string vertexShaderPath = shaderDir + "/" + shaderName + ".vert";
    std::string fragmentShaderPath = shaderDir + "/" + shaderName + ".frag";


    auto vertexShaderCode = LoadShaderFile(vertexShaderPath);
    auto fragmentShaderCode = LoadShaderFile(fragmentShaderPath);


    GLuint program = glCreateProgram();
    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderCode);
    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

