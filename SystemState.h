#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H

#include "qvector3d.h"
#include <iostream>
#include <vector>


class SystemState
{

private:
    QVector3D m_position, m_velocity, m_acceleration;

    float dot_product(QVector3D vec1, QVector3D vec2);
    void Euler_ODE_Solver(float dt);



public:

    SystemState(QVector3D velocity);
    QVector3D GetTranslation(float dt);
    float CollisionDetection(float dt, QVector3D m_velocity);


};

#endif // SYSTEMSTATE_H
