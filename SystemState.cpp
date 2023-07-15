#include "SystemState.h"

SystemState::SystemState(float mass, QVector3D velocity) : m_velocity(velocity), m_mass(mass), m_position(QVector3D(0.0f, 0.0f, 0.0f)), m_acceleration(QVector3D(0.0f, -9.8f, 0.0f))
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
};


float SystemState::dot_product(QVector3D vec1, QVector3D vec2)
{
    float product = 0;
    for(int i = 0; i < 3; i++)
    {
        product += vec1[i] * vec2[i];
    }
    return product;
}