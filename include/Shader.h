#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <QMatrix4x4>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
#include <glm/glm.hpp>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

//struct ShaderProgramSource
//{
//    std::string VertexSource;
//    std::string FragmentSource;
//};


class Shader
{
private:
    QOpenGLShaderProgram m_Program;




public:
    Shader(const QString& vertexShaderPath, const QString& fragmentShaderPath);
    ~Shader();

    void bind();
    void unbind();

    void SetUniformValue(const char* name, const QMatrix4x4& matrix);
    void SetUniformValue(const char* name, const QVector4D& vector);

    void AddBuffer(VertexBuffer* vbo, const VertexBufferLayout& layout);

    unsigned int GetUniformLocation(const char* name) const;
};

#endif // SHADER_H
