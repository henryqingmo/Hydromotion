#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    :m_Buffer(QOpenGLBuffer::IndexBuffer), m_Count(count)
{
    m_Buffer.create();
    m_Buffer.bind();
    m_Buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_Buffer.allocate(data, count * sizeof(unsigned int));
}

IndexBuffer::~IndexBuffer()
{
    m_Buffer.destroy();

}

void IndexBuffer::bind()
{
    m_Buffer.bind();

}

void IndexBuffer::unbind()
{
    m_Buffer.release();
}

unsigned int IndexBuffer::getCount() const
{
    return m_Count;
}

