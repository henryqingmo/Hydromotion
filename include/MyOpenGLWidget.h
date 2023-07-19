#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLTexture>

#include "Renderer.h"
#include "SystemState.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "AnimationThread.h"

#include <QImage>
#include <QCoreApplication>
#include <QDir>

enum SliderType {
    Speed,
    Angle,
    Height,
    Time
};


class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

private:
    float m_speed, m_angle, m_height, m_time, m_duration;
    QVector3D m_InitialVelocity, m_InitialPosition;
    QMatrix4x4 m_proj, m_ballMVP, m_rectangleRotation, m_rectangleTranslation;
    QString currentDir = QDir::currentPath();
    QString m_vertexShaderPath = currentDir + "/src/shaders/vertexShader.vert";
    QString m_fragmentShaderPath = currentDir + "/src/shaders/fragmentShader.frag";



public:
      VertexArray vao_ball, vao_rectangle;
      Shader* shader_ball, *shader_rectangle;
      IndexBuffer* ibo_ball, *ibo_rectangle;
      VertexBuffer* vbo_ball, *vbo_rectangle;
      VertexBufferLayout layout_ball, layout_rectangle;
      Renderer renderer;
      AnimationThread* animationThread;



    MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();
    void initializeRectangle();
    void initializeBall();


    void fire(float dt, float duration, QMatrix4x4 proj, QMatrix4x4 view);
    void transformation();
    void rotation();

signals:
    void projectileDataUpdate(QVector3D projectileData);

public slots:
    void on_sliderValueChanged(int value, const SliderType sliderName);
    void on_pushButton_fire_clicked();
    void updateBallPosition(QMatrix4x4 mvp);


protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;


};

#endif // MYOPENGLWIDGET_H
