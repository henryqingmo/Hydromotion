#ifndef RENDERER_H
#define RENDERER_H

#include <VertexArray.h>
#include <IndexBuffer.h>
#include <Shader.h>


class Renderer
{
public:
    void draw(VertexArray& vao, IndexBuffer* ibo, Shader* shader) const;
};

#endif // RENDERER_H
