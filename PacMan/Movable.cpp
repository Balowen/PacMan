#include "Movable.h"



Movable::Movable()
	:m_velocity(2.f)		//how many pixel per second, check later
	,m_currentDirection(1,0)
	,m_nextDirection(0,0)
	,m_map(nullptr)
{
}


Movable::~Movable()
{
}

void Movable::accessMap(Map* map)		//przyda sie dostep do mapy
{
	m_map = map;
}

void Movable::setVelocity(float velocity)
{
	m_velocity = velocity;
}

float Movable::getVelocity() const
{
	return m_velocity;
}

void Movable::update(sf::Time delta)
{
	m_currentDirection = m_nextDirection;
}

void Movable::changeDirection(sf::Vector2i direction)
{
	m_nextDirection = direction;
}

sf::Vector2i Movable::getDirection() const
{
	return m_currentDirection;
}
