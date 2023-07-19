#include "./include/Renderer.h"
#include "./include/VertexArray.h"
#include "./include/IndexBuffer.h"
#include "./include/Shader.h"

//Renderer::Renderer()
//{

//}

void Renderer::draw(VertexArray &vao, IndexBuffer* ibo, VertexBuffer* vbo, Shader* shader, VertexBufferLayout layout, QMatrix4x4 mvp) const
{
    vao.bind();
    ibo->bind();
    shader->bind();
    shader->AddBuffer(vbo, layout);
    shader->SetUniformValue("u_MVP", mvp);
    glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, 0);

}
