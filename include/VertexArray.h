#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <QOpenGLVertexArrayObject>

class VertexArray
{
private:
    QOpenGLVertexArrayObject m_vao;
public:
    VertexArray();
    ~VertexArray();

    void bind();
    void unbind();

};

#endif // VERTEXARRAY_H
