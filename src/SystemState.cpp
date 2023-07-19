#include "./include/SystemState.h"

/* This is the code for all the physics of the projectile.
 * The object can be initialise with the initial velocity,
 * the goal of the get Euler_ODE_Solver is not to caculate
 * the position of each vertex but the change in position for
 * each vertex. This change in position can then be set as
 * a translation view matrix which can shift each vertex
 * from the gpu side. That's why only initial velocity is required.
 */

SystemState::SystemState(QVector3D velocity) : m_position(0.0,0.0,0.0), m_InitialVelocity(velocity),
    m_velocity(m_InitialVelocity), m_acceleration(0.0f, -9.8f, 0.0f)
{
}

void SystemState::Euler_ODE_Solver(float dt)
{
    m_velocity += m_acceleration * dt;
    m_position += m_velocity * dt;
}



QVector3D SystemState::GetTranslation(float dt)
{
    Euler_ODE_Solver(dt);
    return m_position;
}

/* This function is responsible for finding the time the projectile hits
 * ground so the simulation stops when it reach the ground. It also simultaneously
 * caculate the Range and Maxheight. The time can be found when the height of the
 * projectile is 0. The maxheight can be found be comparing the each increment of
 * height ot the initial height. And the range is just the x component of the change
 * in position.
 */

QVector3D SystemState::CollisionDetection(float dt, QVector3D InitialPosition)
{
    float i = 0, Range = 0;
    float MaxHeight = InitialPosition[1];
    m_position = InitialPosition * 2;

    while(m_position[1] >= 0)
    {
        Euler_ODE_Solver(dt * i);

        i+=dt;

        if(m_position[1] > MaxHeight)
        {
            MaxHeight = m_position[1];
        }

    }
    Range = m_position[0] - InitialPosition[0];
    m_position = InitialPosition;
    m_velocity = m_InitialVelocity;
    return {i, MaxHeight, Range};

}


float SystemState::dot_product(QVector3D vec1, QVector3D vec2)
{
    float product = 0;
    for(int i = 0; i < 3; i++)
    {
        product += vec1[i] * vec2[i];
    }
    return product;
}
