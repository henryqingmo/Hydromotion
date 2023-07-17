#include "VertexArray.h"
#include <QOpenGLExtraFunctions>
#include <glm/glm.hpp>

VertexArray::VertexArray() : m_glFunctions(0)
{
    m_vao.create();
    bind();

}

VertexArray::~VertexArray()
{
    m_vao.destroy();
}

void VertexArray::AddBuffer(VertexBuffer &vbo, const VertexBufferLayout& layout)
{
    bind();
    vbo.bind();
    const auto& elements = layout.GetElement();
    unsigned int offset = 0;

    m_glFunctions = QOpenGLContext::currentContext()->functions();


    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];

        m_glFunctions->glEnableVertexAttribArray(i);
        m_glFunctions->glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), reinterpret_cast<void*>(offset));
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);

       // m_glFunctions->glDisableVertexAttribArray(i);

    }

}

void VertexArray::bind()
{
    m_vao.bind();

}

void VertexArray::unbind()
{
    m_vao.release();
}
