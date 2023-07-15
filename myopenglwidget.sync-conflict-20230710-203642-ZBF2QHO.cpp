#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QOpenGLContext>

#include "myopenglwidget.h"
//All my abstracted classess.
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Renderer.h"
#include <SystemState.h>
#include <game.h>

#include <QDebug>
#include <QElapsedTimer>
#include <Texture.h>

//#include "glm/glm.hpp"
///#include "glm/gtc/type_ptr.hpp"
//#include "glm/gtc/matrix_transform.hpp"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent), m_velocity(0.0f)
{
}

void MyOpenGLWidget::initializeGL()
{

    QOpenGLWidget::initializeGL();  // Call the base class initialization
    initializeOpenGLFunctions();


    QOpenGLContext* context = this->context();
    context->makeCurrent(this->context()->surface());

    glClearColor(0, 0.5, 0.7, 1);




}


void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}


void MyOpenGLWidget::paintGL()
{

    /* Opengl can only draw basic shapes like triangles, a circle can be approximated
     * through drawing various triangles that forms a n-sided polygon.
     * The angle between two adjacent vertices can be caculated by 2π / n
     * The polar coordinate of each vertex is (r, θ), which can be converted to contersian form (rcosθ, rsinθ)
     * The number of non-overlapping triangles is when all triangles shares a same vertex, therefore that vertex
     * connectects to n-1 verticies, and a triangle form between those two adjacent verticies, hence the number of triangle is n-2
     * The triangles can be then be drawn by setting a shared vertex and choosing 2 adjacent verticies along clockwise/anticlockwise
     * direction in the polar coordinates.
     */

    std::vector<glm::vec3> ball_position;
    int vertexCount = 100;
    int triangleCount = vertexCount - 2;
    std::vector<unsigned int> indices;
    float radius = 0.05f, angle = 2 * M_PI * M_PI / vertexCount; // for some reason, 2 pi only display a section of the circle
    for (int i = 0; i < vertexCount; i++)  // convert polar coordinate to cartesian form
    {
        float x = radius * cos(angle * i) - 1.85;
        float y = radius * sin(angle * i) - 0.95;
        float z = 0.0f;
        ball_position.push_back(glm::vec3(x, y, z));
    }

    //indexes for each triangle vertex use to create vertex buffer which avoid repetition of vertex buffer.

    for (int i = 0; i < triangleCount; i++) // assign verteces to each triangle
    {
        indices.push_back(0);
        indices.push_back(i+1);
        indices.push_back(i+2);
    }

//    std::vector<glm::vec2> ball_texCoords;
//    for (int i = 0; i < vertexCount; i++)
//    {
//        float u = static_cast<float>(i) / (vertexCount - 1);
//        float v = 0.0f; // Assuming the texture is vertically flipped
//        ball_texCoords.push_back(glm::vec2(u, v));
//    }

    QString vertexShaderPath = "/home/henry/Documents/Programming/Project/QT_Hydromotion/vertexShader.vert";
    QString fragmentShaderPath = "/home/henry/Documents/Programming/Project/QT_Hydromotion/fragmentShader.frag";
    Shader shader_ball(vertexShaderPath, fragmentShaderPath);
    shader_ball.bind();
    QVector4D color_ball(1.0f, 0.0f, 0.0f, 1.0f);
    shader_ball.SetUniformValue("u_Color", color_ball);

    Renderer renderer;
    VertexBuffer vbo_ball(ball_position.data(), ball_position.size() * sizeof(glm::vec3));
    VertexArray vao_ball;
    VertexBufferLayout ball_layout;
    ball_layout.Push(GL_FLOAT, 3, GL_FALSE);
    vao_ball.AddBuffer(vbo_ball, ball_layout);
   IndexBuffer ibo_ball(indices.data(), indices.size());

    float mass = 50.0f;
    float dt = 0.01f;
    float duration = 2.0f;
//    QVector3D init_velocity{2.0f, 5.0f, 0.0f};

    //m_velocity += 1;

    QVector3D init_velocity{2.0f, m_velocity, 0.0f};

    SystemState ball(mass, init_velocity);

    QMatrix4x4 proj, view;

    proj.ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

    QElapsedTimer timer;
    timer.start();
    float elapsed = 0.0f;

//    while (elapsed < duration) {
//        float t = timer.restart() / 1000.0f;
//        elapsed += t;
//        view.setToIdentity();
//        view.translate(ball.GetTranslation(dt * t));
//        QMatrix4x4 mvp = proj * view;
//        shader.SetUniformValue("u_MVP", mvp);
//        renderer.draw(vao_ball, ibo_ball, shader);

//    }



    for(float i = 0.0f; i < duration; i+=dt)
    {
        //view.translate(1.0f, 1.0f, 0.0f);
        view.setToIdentity();
        view.translate(ball.GetTranslation(dt * i));

        QMatrix4x4 mvp = proj * view;
        shader_ball.SetUniformValue("u_MVP", mvp);
        renderer.draw(vao_ball, ibo_ball, shader_ball);

    }


//    QString filePath = "/home/henry/Documents/Programming/Project/QT_Hydromotion/res/golf_ball.jpg";
//    Texture texture(filePath);
//    shader.SetUniformValue("u_Texture", 0);




//    VertexBuffer vbo_ball_texCoords(ball_texCoords.data(), ball_texCoords.size() * sizeof(glm::vec2));
//    VertexBufferLayout ball_texCoords_layout;
//    ball_texCoords_layout.Push(GL_FLOAT, 2, GL_FALSE);
//    vao_ball.AddBuffer(vbo_ball_texCoords, ball_texCoords_layout);



    std::vector<glm::vec3> squareVertices = {
        glm::vec3(-1.9f, -1.5f, 0.0f),
        glm::vec3(-1.8f, -1.5f, 0.0f),
        glm::vec3(-1.8f, -1.0f, 0.0f),
        glm::vec3(-1.9f, -1.0f, 0.0f)
    };


    std::vector<unsigned int> squareIndices = {
        0, 1, 2,
        2, 3, 0
    };

    shader_ball.unbind();

    Shader shader_rectangle(vertexShaderPath, fragmentShaderPath);
    shader_rectangle.bind();
    shader_rectangle.SetUniformValue("u_MVP", proj);


//   // QMatrix4x4 modelMatrix;
// //   modelMatrix.rotate(45.0f, 1.0f, 0.0f, 0.0f);

//    //QMatrix4x4 mvpMatrix = proj * modelMatrix;
//    //shader.SetUniformValue("u_MVP", mvpMatrix);

//    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));

    QVector4D color_rectangle(0.0f, 0.0f, 0.0f, 0.003f);

    VertexBuffer vbo_rectangle(squareVertices.data(), squareVertices.size() * sizeof(glm::vec3));

    // Create a new IndexBuffer for the square
    IndexBuffer ibo_rectangle(squareIndices.data(), squareIndices.size());

    // Create a new VertexArray for the square
    VertexArray vao_rectangle;
    VertexBufferLayout squareLayout;
    squareLayout.Push(GL_FLOAT, 3, GL_FALSE);
    vao_rectangle.AddBuffer(vbo_rectangle, squareLayout);
    shader_rectangle.SetUniformValue("u_Color", color_rectangle);

    renderer.draw(vao_rectangle, ibo_rectangle, shader_rectangle);




 //  glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
    //    QMatrix4x4 qProj(
//        proj[0][0], proj[1][0], proj[2][0], proj[3][0],
//        proj[0][1], proj[1][1], proj[2][1], proj[3][1],
//        proj[0][2], proj[1][2], proj[2][2], proj[3][2],
//        proj[0][3], proj[1][3], proj[2][3], proj[3][3]
//        );
//QMatrix4x4 qMatrix(reinterpret_cast<float*>(glm::value_ptr(proj)));

//    std::string vertexSource = ParseShader("/home/henry/Documents/Programming/Project/QT_Hydromotion/vertexShader.vert");
//    const char* vertexShaderSource = vertexSource.c_str();
//    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
//    glCompileShader(vertexShader);

////    Create and compile the fragment shader
//    std::string fragmentSource = ParseShader("/home/henry/Documents/Programming/Project/QT_Hydromotion/fragmentShader.frag");
//    const char* fragmentShaderSource = fragmentSource.c_str();
//    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
//    glCompileShader(fragmentShader);

////    Create the shader program
//    GLuint shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);

//    // Use the shader program
//    glUseProgram(shaderProgram);

//    GLuint projLocation = glGetUniformLocation(shaderProgram, "u_MVP");
//    glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(proj));



//    // Clean up the shader objects
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);




    //testing

//    int result;
//    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &result);
//    if(result == GL_FALSE)
//    {
//        int length;
//        glGetShaderiv(shaderProgram,  GL_INFO_LOG_LENGTH, &length);
//        char* message = (char*)alloca(length * sizeof(char));
//        std::cout << message << std::endl;

//    }



    //glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);



//    QOpenGLBuffer indexBuffer(QOpenGLBuffer::IndexBuffer);
//    indexBuffer.create();
//    indexBuffer.bind();
//    indexBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
//    indexBuffer.allocate(indices.data(), sizeof(unsigned int) * indices.size());

//    // Bind the index buffer object
//    indexBuffer.bind();

//    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

//    GLuint indexBuffer;
//    glGenBuffers(1, &indexBuffer);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

//    // Step 2: Allocate and initialize the index buffer's data
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

//    // Step 3: Unbind the index buffer
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

//    // Step 4: Draw using the index buffer
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
//    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

    // Step 5: Cleanup


   // glDrawArrays(GL_TRIANGLE_FAN, 0, triangleCount);
   // indexBuffer.release();
    //indexBuffer.destroy();


   // ibo.unbind();

//    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

//     GLuint vao;

//    glGenVertexArrays(1, &vao);
//    glBindVertexArray(vao);

//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

    //glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

    // draw circle


//    glGenBuffers(1, &vbo);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, triangleVertex.size() * sizeof(glm::vec3), triangleVertex.data(), GL_STATIC_DRAW);

}

void MyOpenGLWidget::fire()
{

}

void MyOpenGLWidget::on_horizontalSlider_mass_valueChanged(int value)
{
    m_velocity = static_cast<float>(value);
}

//     float position[6] = {
//        -0.5f, -0.5f,
//         0.5f, -0.5f,
//         0.0f,  0.5f
//     };


//     //load texture
//     QImage image;
//     image.load("/home/henry/Documents/Programming/Project/QT_Hydromotion/res/res/golf_ball.jpg");
//     QOpenGLTexture *texture = new QOpenGLTexture(image.mirrored());
//     texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
//     texture->setMagnificationFilter(QOpenGLTexture::Linear);
//     texture->bind();



//     unsigned int buffer;
//      glGenBuffers(1, &buffer);
//      glBindBuffer(GL_ARRAY_BUFFER, buffer);
     //glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), position, GL_STATIC_DRAW);

//      glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW); // asd
//      glDrawArrays(GL_TRIANGLES, 0, 3);
//      glEnableVertexAttribArray(0);
//      glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);






      //deprecated

//     unsigned int buffer;
//     glGenBuffers(1, &buffer);
//     glBindBuffer(GL_ARRAY_BUFFER, buffer);
//     glBufferData(buffer, 6 * sizeof(float), position, GL_STATIC_DRAW);

//     glDrawArrays(GL_TRIANGLES, 0, 3);
//     glEnableVertexAttribArray(0);
//     // assigend number to element, number of data in each vertex, type, GL_FALSE, size of the entire vertex, size of the element/offset
//     glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


//    glColor3ub(255,255,0);  // yellow
//    glBegin(GL_TRIANGLES);
//    glVertex2f( -0.5, -0.5 );
//    glVertex2f( 0.5, -0.5 );
//    glVertex2f( 0, 0.5 );
//    glEnd();



