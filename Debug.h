#ifndef DEBUG_H
#define DEBUG_H
#include <QDebug>
#include <QOpenGLFunctions>



void GetError()
{
    //GLenum error = glGetError();
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        // Handle the error or print it
        switch (error) {
        case GL_INVALID_ENUM:
        qDebug() << "OpenGL Error: GL_INVALID_ENUM";
        break;
        case GL_INVALID_VALUE:
        qDebug() << "OpenGL Error: GL_INVALID_VALUE";
        break;
        case GL_INVALID_OPERATION:
        qDebug() << "OpenGL Error: GL_INVALID_OPERATION";
        break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
        qDebug() << "OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION";
        break;
        case GL_OUT_OF_MEMORY:
        qDebug() << "OpenGL Error: GL_OUT_OF_MEMORY";
        break;
        default:
        qDebug() << "OpenGL Error: Unknown error";
        break;
        }
    }
}

#endif // DEBUG_H
