#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H

#include "qvector3d.h"
#include <iostream>
#include <vector>


class SystemState
{

private:
    QVector3D m_position, m_velocity, m_acceleration;
    float m_mass;

    QVector3D scalar_product(QVector3D vector, float scalar);
    float dot_product(QVector3D vec1, QVector3D vec2);
    void Euler_ODE_Solver(float dt);


public:

    SystemState(float mass, QVector3D velocity);

    QVector3D GetTranslation(float dt);



};

#endif // SYSTEMSTATE_H
