#include "AnimationThread.h"

AnimationThread::AnimationThread(float dt, float duration, QMatrix4x4 proj, QMatrix4x4 view, QVector3D init_velocity)
    : m_dt(dt), m_duration(duration), m_proj(proj), m_view(view), m_ball(init_velocity)
{
}

void AnimationThread::run()
{
    for(int i = 0; i < m_duration; i+=m_dt)
    {
        m_view.translate(m_ball.GetTranslation(m_dt * i));
        mvp = m_proj * m_view;
    }
    emit updatePosition(mvp);
    msleep(16);

}


