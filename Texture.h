#ifndef TEXTURE_H
#define TEXTURE_H

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLTexture>


class Texture
{
private:
    QString m_FilePath;
    GLuint m_textureId;
    QOpenGLTexture* m_texture;
    int m_width, m_height, m_BPP;

    void CreateTexture(const QImage& image);

public:
    Texture(QString& path);
    ~Texture();


    void bind();
    void unbind();



};

#endif // TEXTURE_H
