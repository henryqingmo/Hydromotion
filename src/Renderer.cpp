#include "./include/Renderer.h"
#include "./include/VertexArray.h"
#include "./include/IndexBuffer.h"
#include "./include/Shader.h"

/* This is basically a renderer that first bind everything, ensuring the correct
 * shape is binded. Then it passess a mvp matrix to the vertex shader so that
 * each vertex is mutiplied by the mvp matrix on the gpu side.
 * Then it issue a draw call for the object to be rendered on
 * the screen.
 */

void Renderer::draw(VertexArray &vao, IndexBuffer* ibo, VertexBuffer* vbo, Shader* shader, VertexBufferLayout layout, QMatrix4x4 mvp) const
{
    vao.bind();
    ibo->bind();
    shader->bind();
    shader->AddBuffer(vbo, layout);
    shader->SetUniformValue("u_MVP", mvp);
    glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, 0);

}
