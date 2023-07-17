#include "AnimationThread.h"

AnimationThread::AnimationThread(QVector3D InitialVelocity)
    : m_ball(InitialVelocity)
{
}

void AnimationThread::setParameters(float dt, float duration, QMatrix4x4 proj, QMatrix4x4 view)
{
    this->m_dt = dt;
    this->m_duration = duration;
//    this->m_proj = proj;
    this->m_view = view;
    m_proj.ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
}


void AnimationThread::run()
{
    for(float i = 0.0; i < m_duration; i+=m_dt)
    {
        m_view.setToIdentity();
        m_view.translate(m_ball.GetTranslation(m_dt * i));
        mvp = m_proj * m_view;
        emit updateBallPosition(mvp);
        msleep(16);
    }


}
