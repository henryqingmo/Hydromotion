// OPENGL
#include <QOpenGLContext>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//All My abstracted code
#include "./include/MyOpenGLWidget.h"
#include "./include/VertexBuffer.h"
#include "./include/VertexArray.h"
#include "./include/IndexBuffer.h"
#include "./include/Shader.h"
#include "./include/Renderer.h"
#include "./include/SystemState.h"

// QT FRAMEWORK
#include <QElapsedTimer>
#include <QThread>

/* This file basically uses all the abstracted classess to render all the things on
 * the openglwidget. All of the variables related to rendering are declared as class
 * attributes on the heap so don't get destroyed when goes out of scope, this allows
 * them to be share across the function.
 */



MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent), m_speed(0.0f), m_angle(0.0f), m_height(0.0f),
    m_InitialVelocity(0.0, 0.0, 0.0), m_InitialPosition(0.0, 0.0, 0.0)
{
    m_proj.ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

}

MyOpenGLWidget::~MyOpenGLWidget()
{
    delete shader_ball;
    delete shader_rectangle;
    delete ibo_ball;
    delete ibo_rectangle;
    delete vbo_ball;
    delete vbo_rectangle;

}

void MyOpenGLWidget::initializeRectangle()
{

    /* Here is the code responsible to setup a rectangle in opengl
     * The 4 glm::ve3 reprents the 4 vertices of the rectangle.
     * Each vertex stores the {x,y,z} position. The rectangle
     * Indices is responsible for setting up the indexBuffer, the number
     * 0, 1, 2, 3 represents the 4 vertices. And they are arrange into
     * 2 lines of 3 vertices, each line represent one triangle. The indexBuffer
     * is then able to determine the unique vertex from there.
     */


    std::vector<glm::vec3> rectangleVertices = {
        glm::vec3(-2.0f, -1.5f, 0.0f),
        glm::vec3(-1.9f, -1.5f, 0.0f),
        glm::vec3(-1.9f, -1.4f, 0.0f),
        glm::vec3(-2.0f, -1.4f, 0.0f)
    };


    std::vector<unsigned int> rectangleIndices = {
        0, 1, 2,
        2, 3, 0
    };
    shader_rectangle = new Shader(m_vertexShaderPath, m_fragmentShaderPath);
    shader_rectangle->bind();
//    texture = new Texture(m_texturePath);


    //the float value represent r, g, b, a respectively

    QVector4D color_rectangle(0.0f, 0.0f, 0.0f, 0.0f);


    vbo_rectangle = new VertexBuffer(rectangleVertices.data(), rectangleVertices.size() * sizeof(glm::vec3));

    ibo_rectangle = new IndexBuffer(rectangleIndices.data(), rectangleIndices.size());

    layout_rectangle.Push(GL_FLOAT, 3, GL_FALSE);

    shader_rectangle->SetUniformValue("u_Color", color_rectangle);

}

void MyOpenGLWidget::initializeBall()
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
        float x = radius * cos(angle * i) - 1.95;
        float y = radius * sin(angle * i) - 1.45;
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


    shader_ball = new Shader(m_vertexShaderPath, m_fragmentShaderPath);
    shader_ball->bind();
    QVector4D color_ball(1.0f, 0.0f, 0.0f, 1.0f);
    shader_ball->SetUniformValue("u_Color", color_ball);

    vbo_ball = new VertexBuffer(ball_position.data(), ball_position.size() * sizeof(glm::vec3));

    layout_ball.Push(GL_FLOAT, 3, GL_FALSE);

    ibo_ball = new IndexBuffer(indices.data(), indices.size());

}

/* This function is called when the animation starts
 * The funciton passess mvp matrix which is set to an
 * attribute to be passed to the paintGL function where
 * all the rendering takes place. The update function c
 * calls the paintGL function
 */

void MyOpenGLWidget::updateBallPosition(QMatrix4x4 mvp)
{
    m_ballMVP = mvp;
    update();
}

/* Transformation is called when the height slider change
 * It basically translate the shape upwards through
 * constructing a model matrix. The height is scalled
 * to times 2
 */

void MyOpenGLWidget::transformation()
{
    QMatrix4x4 model, view;

    model.translate(0.0f, m_height * 2, 0.0f);

    m_rectangleTranslation = view * model;

    update();


}

/* Rotation is called when the angle changed
 * The model.rotate{0.0, 0.0, 1.0} will rotate the shape around
 * the z axis, which appears to rotate from the x axis to the y axis
 * anticlockwise around the object's centre. Hence the object is first
 * moved to the origin i.e it's initial centre. Then, it is rotated
 * to the desire angle and lastly translated back.
 */

void MyOpenGLWidget::rotation()
{
    QMatrix4x4 model, view;
    float pivot_x = -1.95, pivot_y = -1.45;

    view.setToIdentity();

    model.translate(pivot_x, pivot_y, 0.0f);

    model.rotate(m_angle, QVector3D(0.0f, 0.0f, 1.0f)); // Rotate from x axis to y axis 2D

    model.translate(-pivot_x, -pivot_y, 0.0f);

    m_rectangleRotation = view * model;

    update();

}


/* All the code to initialize the drawing of
 * both shape is called here It also set the
 * color of the widget background to be
 * {0, 0.5, 0.7, 1} which is blue
 */
void MyOpenGLWidget::initializeGL()
{
    QOpenGLWidget::initializeGL();  // Call the base class initialization
    initializeOpenGLFunctions();


    QOpenGLContext* context = this->context();
    context->makeCurrent(this->context()->surface());

    glClearColor(0, 0.5, 0.7, 1);

    initializeBall();

    initializeRectangle();

}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}


/* The rendering of the objects are called here. The ball is only
 * drawn when the fire button is pressed, therefore it is only rendered
 * when the animationThread is active.
 * The rotation together with translation of the rectangle is caculated
 * through multiplying the projection matrix which sets the boundary of the
 * widget to the corresponding translation and rotation. The paintGL is
 * always called so the rectangle appears on the screen initially
 *
 */

void MyOpenGLWidget::paintGL()
{
    if(animationThread)
    {
        renderer.draw(vao_ball, ibo_ball, vbo_ball, shader_ball, layout_ball, m_ballMVP);

    }

    QMatrix4x4 RectangleMVP = m_proj * m_rectangleTranslation * m_rectangleRotation;
    renderer.draw(vao_rectangle, ibo_rectangle, vbo_rectangle, shader_rectangle, layout_rectangle, RectangleMVP);


}

/* This is a slot which is called when the fire button is pressed.
 * It first create a instance of Systemstate and setup the dt. The dt and
 * the inital position which contains the height is passed into
 * the collisionDetection, a method of Systemstate. Now the Systemstate
 * would have the initial velocity from the constructor and the height and
 * dt. This is sufficient to caculate when the ball hits the ground. The
 * {flight time, max Height, range} is then emitted here as a 3D vector.
 * The flight time is inaccurate therefore it's recaculated from the range
 * and initial velocity. This data is then emitted to the Game class
 * to display on the TextEdit
 */

void MyOpenGLWidget::on_pushButton_fire_clicked()
{
    SystemState ball(m_InitialVelocity);

    float dt = 0.001;


    QVector3D projectileData = ball.CollisionDetection(dt, m_InitialPosition);
    m_duration = projectileData[0];
    projectileData[0] = projectileData[2] / m_InitialVelocity[0];
    emit projectileDataUpdate(projectileData);


    QMatrix4x4 proj, view, model;

    proj.ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

    model.translate(m_InitialPosition);

    animationThread = new AnimationThread(ball);

    connect(animationThread, &AnimationThread::updateBallPosition, this, &MyOpenGLWidget::updateBallPosition);

    animationThread->setParameters(dt, m_duration, m_time, proj, view, model);

    animationThread->start();


}


/* Here is a switch statement that determine which slider value is emitted
 * The signal passess an int value and an enum which is defined in
 * MyOpenGLWidget.h. The initial velocity and position is also setup as
 * the v_x is speed * cos(angle) and v_y is speed * sin(angle)
 * the intialposition takes the value {0, height, 0}
 */

void MyOpenGLWidget::on_sliderValueChanged(int value, SliderType sliderName)
{

    switch (sliderName) {
    case Speed:
        m_speed = static_cast<float>(value) / 1.0f;
        break;
    case Angle:
        m_angle = static_cast<float>(value) / 1.0f;
        rotation();
        break;
           case Height:
        m_height = static_cast<float>(value) / 100.0f;
        transformation();
        break;
    case Time:
        m_time = static_cast<float>(value) / 10.0f;
    default:
        break;
    }

    m_InitialVelocity[0] = m_speed * cos(m_angle * M_PI / 180.0);
    m_InitialVelocity[1] = m_speed * sin(m_angle * M_PI / 180.0);
    m_InitialPosition[1] = m_height;

}




