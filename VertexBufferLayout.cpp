#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout()
    : m_Stride(0)
{
}

void VertexBufferLayout::Push(unsigned int type, unsigned int count, bool normalized)
{
    m_Elements.push_back({ type, count, normalized });
    m_Stride += VertexBufferElement::GetSizeOfType(type) * count;
}

std::vector<VertexBufferElement> VertexBufferLayout::GetElement() const
{
    return m_Elements;
}

unsigned int VertexBufferLayout::GetStride() const
{
    return m_Stride;
}

unsigned int VertexBufferElement::GetSizeOfType(unsigned int type)
{
    switch (type)
    {
    case GL_FLOAT:
        return sizeof(GLfloat);
    case GL_UNSIGNED_INT:
        return sizeof(GLuint);
    default:
        return 0;
    }
}
