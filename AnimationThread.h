#ifndef ANIMATIONTHREAD_H
#define ANIMATIONTHREAD_H
#include "SystemState.h"
#include <QMatrix4x4>
#include <QThread>

class AnimationThread : public QThread
{
    Q_OBJECT

private:
    float m_dt, m_duration;
    QMatrix4x4 m_proj, m_view;
    SystemState m_ball;

public:
    QMatrix4x4 mvp;
    AnimationThread(float dt, float duration, QMatrix4x4 proj, QMatrix4x4 view, QVector3D init_velocity);

signals:
    QMatrix4x4 updatePosition(QMatrix4x4 mvp);

protected:
    void run() override;

};

#endif // ANIMATIONTHREAD_H
