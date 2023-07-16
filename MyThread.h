#ifndef MYTHREAD_H
#define MYTHREAD_H
#include "MyOpenGLWidget.h"
#include <QThread>


class MyThread : QThread
{
    Q_OBJECT

public:

   // MyThread(VertexArray vao, VertexBuffer* vbo, IndexBuffer* ibo, Shader* shader);
//    ~MyThread();


protected:
    void run() override;

};

#endif // MYTHREAD_H
