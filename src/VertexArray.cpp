#include "./include/VertexArray.h"
#include <glm/glm.hpp>

/* My Abstraction of the QT implementation of VertexArray
 */
VertexArray::VertexArray(){
    m_vao.create();
    bind();

}

VertexArray::~VertexArray()
{
    m_vao.destroy();
}

void VertexArray::bind()
{
    m_vao.bind();

}

void VertexArray::unbind()
{
    m_vao.release();
}
