#ifndef RENDERER_H
#define RENDERER_H

#include <VertexArray.h>
#include <IndexBuffer.h>
#include <Shader.h>


class Renderer
{
public:
    void draw(VertexArray& vao, IndexBuffer* ibo, VertexBuffer* vbo, Shader* shader, VertexBufferLayout layout, QMatrix4x4 mvp) const;
};

#endif // RENDERER_H
