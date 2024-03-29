#ifndef ANIMATIONTHREAD_H
#define ANIMATIONTHREAD_H
#include "SystemState.h"
#include <QMatrix4x4>
#include <QVector3D>
#include <cmath>
#include <QThread>
#include <QtMultimedia/QMediaPlayer>

class AnimationThread : public QThread
{
    Q_OBJECT

private:
    float m_mass, m_speed, m_angle, m_height, m_time, m_dt,  m_duration;
    QMatrix4x4 m_proj, m_view, m_model;
    QVector3D m_InitialVelocity, m_InitialPosition;
    SystemState m_ball;

public:
    QMatrix4x4 mvp;
    AnimationThread(SystemState ball);
    void setParameters(float dt, float duration, float time, QMatrix4x4 proj, QMatrix4x4 view, QMatrix4x4 modal);

signals:
    QMatrix4x4 updateBallPosition(QMatrix4x4 mvp);

protected:
    void run() override;
    QMediaPlayer *player;


};

#endif // ANIMATIONTHREAD_H
