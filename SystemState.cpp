#include "SystemState.h"

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
