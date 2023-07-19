#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <QOpenGLBuffer>

class VertexBuffer
{
private:
      QOpenGLBuffer m_Buffer;

public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void bind();
    void unbind();
};

#endif // VERTEXBUFFER_H
