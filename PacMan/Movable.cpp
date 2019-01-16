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
	sf::Vector2f pixelPos = getPosition();

	float pixelTraveled = getVelocity() * delta.asSeconds();	//velocity is [pixels/seconds]

	sf::Vector2f nextPixelPos = pixelPos + sf::Vector2f(m_currentDirection) * pixelTraveled;
	setPosition(nextPixelPos);

	sf::Vector2i cellPos = m_map->transform_pixelToCell(pixelPos);

	sf::Vector2f offset;	//https://pl.cppreference.com/w/cpp/numeric/math/fmod
	offset.x = std::fmod(pixelPos.x, 32) - 16;	//-16 bo zwroci nam [0;32], ale chcemy [-16; 16]
	offset.y = std::fmod(pixelPos.y, 32) - 16;

	//-----------------COLLISION WITH WALL ---------------
	if (m_map->isWall(cellPos + m_currentDirection))
	{
		if ((m_currentDirection.x == 1 && offset.x > 0) ||	//pacman(any movable) going right (into the wall)
			(m_currentDirection.x == -1 && offset.x < 0) ||
			(m_currentDirection.y == 1 && offset.y > 0) ||
			(m_currentDirection.y == -1 && offset.y < 0))
		{
			setPosition(m_map->transform_cellToPixel(cellPos));	//zatrzyma w miejscu
		}
	}


	//m_currentDirection = m_nextDirection;

}

void Movable::changeDirection(sf::Vector2i direction)
{
	m_nextDirection = direction;
}

sf::Vector2i Movable::getDirection() const
{
	return m_currentDirection;
}
