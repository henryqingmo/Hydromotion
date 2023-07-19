#include "./include/Texture.h"
#include <QImage>

/* My Abstration of OpenGL implementation of converting image into Texture
 */

Texture::Texture(QString& path)
    :m_FilePath(path), m_textureId(0), m_texture(nullptr), m_width(0), m_height(0), m_BPP(0)
{
    QImage image(path);
    CreateTexture(image);
}


void Texture::CreateTexture(const QImage &image)
{
    m_texture = new QOpenGLTexture(image);
    m_width = image.width();
    m_height = image.height();

    m_texture->setMinificationFilter(QOpenGLTexture::Linear);
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear);
    m_texture->setWrapMode(QOpenGLTexture::ClampToEdge);

    m_texture->setSize(m_width, m_height);
    m_texture->allocateStorage(QOpenGLTexture::RGBA, QOpenGLTexture::UInt8);

    m_texture->bind();
}



Texture::~Texture()
{
    delete m_texture;
}

void Texture::bind()
{
    m_texture->bind();
}

void Texture::unbind()
{
    m_texture->release();

}


//     glFunctions = new QOpenGLFunctions(QOpenGLContext::currentContext());
//   glFunctions->glGenTextures(1, &m_textureId);
//    glFunctions->glBindTexture(GL_TEXTURE_2D, m_textureId);

//    glFunctions->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glFunctions->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glFunctions->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//    glFunctions->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);


