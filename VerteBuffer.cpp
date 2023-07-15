#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    m_Buffer.create();
    m_Buffer.bind();
    m_Buffer.allocate(data, size);

}

VertexBuffer::~VertexBuffer()
{
    m_Buffer.destroy();
}

void VertexBuffer::bind()
{
    m_Buffer.bind();
}

void VertexBuffer::unbind()
{
    m_Buffer.release();
}
