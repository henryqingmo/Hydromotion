QT       += core gui \
            opengl


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 \
          debug


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AnimationThread.cpp \
    HelpDialog.cpp \
    IndexBuffer.cpp \
    MainMenu.cpp \
    MyOpenGLWidget.cpp \
    OptionDialog.cpp \
    Renderer.cpp \
    Shader.cpp \
    SystemState.cpp \
    Texture.cpp \
    VerteBuffer.cpp \
    VertexArray.cpp \
    VertexBufferLayout.cpp \
    game.cpp \
    main.cpp

HEADERS += \
    AnimationThread.h \
    Debug.h \
    HelpDialog.h \
    IndexBuffer.h \
    MainMenu.h \
    MyOpenGLWidget.h \
    OptionDialog.h \
    Renderer.h \
    Shader.h \
    SystemState.h \
    Texture.h \
    VertexArray.h \
    VertexBuffer.h \
    VertexBufferLayout.h \
    game.h

FORMS += \
    HelpDialog.ui \
    MainMenu.ui \
    OptionDialog.ui \
    game.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fragmentShader.frag \
    vertexShader.vert
