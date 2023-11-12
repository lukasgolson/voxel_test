#ifndef VOXEL_TEST_SHADERPROGRAM_H
#define VOXEL_TEST_SHADERPROGRAM_H


#include <string>
#include "glad/gl.h"


class ShaderProgram {
public:
    ShaderProgram(const std::string& shaderDir, const std::string& shaderName);
    ~ShaderProgram();


    void Refresh();

    void SetUniforms();

    void Update();

private:
    static GLuint LoadShaders(const std::string &shaderDir, const std::string &shaderName);

    static std::string LoadShaderFile(const std::string &filePath);

    static GLuint CompileShader(GLenum shaderType, const std::string &shaderCode);

    GLuint program;
};


#endif //VOXEL_TEST_SHADERPROGRAM_H
