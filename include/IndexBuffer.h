#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include <QOpenGLBuffer>
#include <QOpenGLFunctions_3_3_Core>


class IndexBuffer
{
private:
    QOpenGLBuffer m_Buffer;
    unsigned int m_Count;

public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void bind();
    void unbind();
    unsigned int getCount() const;


};

#endif // INDEXBUFFER_H
