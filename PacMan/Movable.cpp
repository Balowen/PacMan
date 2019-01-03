#include "Movable.h"



Movable::Movable()
	:m_velocity(2.f)		//how many pixel per second, check later
{
}


Movable::~Movable()
{
}

void Movable::setVelocity(float velocity)
{
	m_velocity = velocity;
}

float Movable::getVelocity() const
{
	return m_velocity;
}
