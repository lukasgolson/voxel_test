#pragma once


#include <string>
#include "Camera.h"
#include "OpenGlCommon.h"
#include "meshes/BaseMesh.h"
#include "Enums/ShaderType.h"


class ShaderProgram {
public:
    ShaderProgram(const std::string& shaderDir, const std::string& shaderName, Camera *camera);
    ~ShaderProgram();
    void Update();

    void SetModelMatrix(const glm::mat4 &value);


private:
    void SetUniforms();

    static GLuint LoadShaders(const std::string &shaderName);

    static std::string LoadShaderFile(const std::string &shaderName, const ShaderType &shaderType);

    static GLuint CompileShader(GLenum shaderType, const std::string &shaderCode);

    GLuint program;
    Camera *camera;

    GLint GetUniformLocation(const std::string &name) const;

    void SetUniform(const std::string &name, const glm::mat4 &value);

};
