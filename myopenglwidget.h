#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include "Renderer.h"
#include "SystemState.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLTexture>
#include <VertexArray.h>
#include <IndexBuffer.h>
#include <Shader.h>
#include <QImage>

enum SliderType {
    Mass,
    Speed,
    Angle,
    Height
};

class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
private:
    float m_mass, m_speed, m_angle, m_height;
    SystemState m_ball;
    QString m_vertexShaderPath = "/home/henry/Documents/Programming/Project/QT_Hydromotion/vertexShader.vert";
    QString m_fragmentShaderPath = "/home/henry/Documents/Programming/Project/QT_Hydromotion/fragmentShader.frag";
public:
      VertexArray vao_ball, vao_rectangle;
      Shader* shader_ball, *shader_rectangle;
      IndexBuffer* ibo_ball, *ibo_rectangle;
      VertexBuffer* vbo_ball, *vbo_rectangle;
      Renderer renderer;



    MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();
    void fire(float dt, float duration, QMatrix4x4 proj, QMatrix4x4 view);

public slots:
    void on_sliderValueChanged(int value, const SliderType sliderName);

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;


};

#endif // MYOPENGLWIDGET_H
