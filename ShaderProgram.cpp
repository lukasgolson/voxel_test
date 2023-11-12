#include <fstream>
#include <vector>
#include <iostream>
#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(const std::string &shaderDir, const std::string &shaderName) {
    auto program = ShaderProgram::LoadShaders(shaderDir, shaderName);

}

ShaderProgram::~ShaderProgram() = default;


void ShaderProgram::Refresh() { SetUniforms(); }

void ShaderProgram::SetUniforms() {

}

void ShaderProgram::Update() {

}

std::string ShaderProgram::LoadShaderFile(const std::string &filePath) {
    std::string shaderCode;
    std::ifstream shaderFile(filePath);
    if (shaderFile.is_open()) {
        std::string line;
        while (std::getline(shaderFile, line)) {
            shaderCode += line + "\n";
        }
        shaderFile.close();
    }
    return shaderCode;
}

GLuint ShaderProgram::CompileShader(GLenum shaderType, const std::string &shaderCode) {
    GLuint shader = glCreateShader(shaderType);
    const char *shaderSource = shaderCode.c_str();
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    // Check for shader compilation errors (you can add error handling here)
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> log(logLength);
        glGetShaderInfoLog(shader, logLength, nullptr, log.data());



        // Print the error log to the console using std::cerr
        std::cerr << "Shader compilation failed:" << std::endl;
        std::cerr << log.data() << std::endl;

        return 0;
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
