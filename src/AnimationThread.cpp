#include "./include/AnimationThread.h"

AnimationThread::AnimationThread(SystemState ball)
    : m_ball(ball)
{
//    player = new QMediaPlayer(this);
//    player->setMedia(QUrl::fromLocalFile("path/to/your/audio/file.mp3"));
//    player->setVolume(50); // Set the volume (0 - 100)
//    player->play();

}

void AnimationThread::setParameters(float dt, float duration, float time, QMatrix4x4 proj, QMatrix4x4 view, QMatrix4x4 model)
{
    this->m_dt = dt;
    this->m_duration = duration;
    this->m_proj = proj;
    this->m_view = view;
    this->m_model = model;
    this->m_time = time;
}


void AnimationThread::run()
{
    for(float i = 0.0; i < m_duration; i+=m_dt)
    {
        m_view.setToIdentity();
        m_view.translate(m_ball.GetTranslation(m_dt * i));
        mvp = m_proj * m_view * m_model;
        emit updateBallPosition(mvp);
        msleep(m_time);
    }


}
