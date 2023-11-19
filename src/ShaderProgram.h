#ifndef VOXEL_TEST_SHADERPROGRAM_H
#define VOXEL_TEST_SHADERPROGRAM_H


#include <string>
#include "glad/gl.h"
#include "Camera.h"


class ShaderProgram {
public:
    ShaderProgram(const std::string& shaderDir, const std::string& shaderName, Camera *camera);
    ~ShaderProgram();




    void Update();

private:
    void SetUniforms();

    static GLuint LoadShaders(const std::string &shaderDir, const std::string &shaderName);

    static std::string LoadShaderFile(const std::string &filePath);

    static GLuint CompileShader(GLenum shaderType, const std::string &shaderCode);

    GLuint program;
    Camera *camera;

    GLint GetUniformLocation(const std::string &name) const;

};


#endif //VOXEL_TEST_SHADERPROGRAM_H
