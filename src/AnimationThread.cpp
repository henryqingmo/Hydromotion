#include "./include/AnimationThread.h"

/*The AnimationThread class is responsible for running the animation of the ball's movement.
 * The constructor takes in SystemState object, which contains the ball's initial velocity
 * The parameters are passed from game class through setParameters
 * The main animation loop, executed when the thread is started, iterates through the animation steps based on the time step.
 * It updates the view matrix with the ball's position at the current time step and calculates the Model-View-Projection (MVP) matrix.
 * After each update, it emits a signal to notify the main thread to update the ball's position in the OpenGL widget.
 * The msleep function introduces a delay between frames, controlling the animation speed.
*/


AnimationThread::AnimationThread(SystemState ball)
    : m_ball(ball)
{
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
