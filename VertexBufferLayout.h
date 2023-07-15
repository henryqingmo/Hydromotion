#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <vector>
#include <QOpenGLFunctions_3_3_Core>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    bool normalized;

    static unsigned int GetSizeOfType(unsigned int type);

};


class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout();
    void Push(unsigned int type, unsigned int count, bool normalized);

    std::vector<VertexBufferElement> GetElement() const;
    unsigned int GetStride() const;


};

#endif // VERTEXBUFFERLAYOUT_H
