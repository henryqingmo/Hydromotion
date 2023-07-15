#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <QOpenGLVertexArrayObject>

class VertexArray
{
private:
    QOpenGLVertexArrayObject m_vao;
    QOpenGLFunctions* m_glFunctions;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(VertexBuffer& vbo, const VertexBufferLayout& Layout);
    void bind();
    void unbind();

};

#endif // VERTEXARRAY_H
