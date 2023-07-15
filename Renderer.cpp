#include "Renderer.h"
#include "VertexArray.h"
#include <IndexBuffer.h>
#include <Shader.h>

//Renderer::Renderer()
//{

//}

void Renderer::draw(VertexArray &vao, IndexBuffer* ibo, Shader* shader) const
{
    vao.bind();
    ibo->bind();
    shader->bind();
    glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, 0);

}
