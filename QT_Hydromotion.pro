QT       += core gui \
            opengl \
            multimedia



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 \
          debug


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/AnimationThread.cpp \
    src/HelpDialog.cpp \
    src/IndexBuffer.cpp \
    src/MainMenu.cpp \
    src/MyOpenGLWidget.cpp \
    src/OptionDialog.cpp \
    src/Renderer.cpp \
    src/Shader.cpp \
    src/SystemState.cpp \
    src/Texture.cpp \
    src/VerteBuffer.cpp \
    src/VertexArray.cpp \
    src/VertexBufferLayout.cpp \
    src/game.cpp \
    src/main.cpp

HEADERS += \
   include/AnimationThread.h \
   include/Debug.h \
   include/HelpDialog.h \
   include/IndexBuffer.h \
   include/MainMenu.h \
   include/MyOpenGLWidget.h \
   include/OptionDialog.h \
   include/Renderer.h \
   include/Shader.h \
   include/SystemState.h \
   include/Texture.h \
   include/VertexArray.h \
   include/VertexBuffer.h \
   include/VertexBufferLayout.h \
   include/game.h

FORMS += \
   ui/HelpDialog.ui \
   ui/MainMenu.ui \
   ui/OptionDialog.ui \
   ui/game.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
UI_HEADERS_DESTDIR = ui

DISTFILES += \
    src/shaders/fragmentShader.frag \
    src/shaders/vertexShader.vert
