#include "./include/Shader.h"

/* This is basically my abstraction of the OpenGL implementation
 * of handling shader. The uniformValue are value in the
 * shader. The uniform act as a bridget for the cpu to pass
 * value such as projection matrix or colour matrix into
 * the shader to be handled by the gpu.
 */


Shader::Shader(const QString& vertexShaderPath, const QString& fragmentShaderPath)
    : m_Program(QOpenGLShaderProgram())
{
    m_Program.create();
    m_Program.addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath);
    m_Program.addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath);
    m_Program.link();

}

Shader::~Shader()
{
    m_Program.destroyed();
}
unsigned int Shader::GetUniformLocation(const char* name) const
{
    return m_Program.uniformLocation(name);
}

void Shader::SetUniformValue(const char* name, const QMatrix4x4& matrix)
{
    m_Program.setUniformValue(GetUniformLocation(name), matrix);

}

void Shader::SetUniformValue(const char *name, const QVector4D &vector)
{
    m_Program.setUniformValue(GetUniformLocation(name), vector);

}

void Shader::AddBuffer(VertexBuffer* vbo, const VertexBufferLayout &layout)
{
    vbo->bind();

     unsigned int offset = 0;
    const auto& elements = layout.GetElement();

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];

        m_Program.setAttributeBuffer(i, element.type, offset, element.count, layout.GetStride());
        m_Program.enableAttributeArray(i);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);

    }
}

void Shader::bind()
{
    m_Program.bind();

}

void Shader::unbind()
{
    m_Program.release();

}
