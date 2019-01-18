#include "Movable.h"



Movable::Movable()
	:m_velocity(50.f)		//how many pixel per second, check later
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

	float pixelTraveled = getVelocity() * delta.asSeconds();	//how many pixels traveled at one frame

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
	// ----------Changing direction after colliding 
	if (!m_map->isWall(cellPos + m_nextDirection) && m_currentDirection != m_nextDirection)
	{
		if ((!m_currentDirection.y && (offset.x > -2 && offset.x < 2)) ||
			(!m_currentDirection.x && (offset.y > -2 && offset.y < 2)))	//jesli idzie na bok, to offset w osi y ma byc bliski zeru
		{
			setPosition(m_map->transform_cellToPixel(cellPos));		//reseting character position on current cell
			m_currentDirection = m_nextDirection;

			if (m_currentDirection == sf::Vector2i(1, 0))
			{
				setRotation(0);
				setScale(1, 1);	//flipping the sprite
			}
			else if (m_currentDirection == sf::Vector2i(0, 1))
			{
				setRotation(90);
				setScale(1, 1);
			}
			else if (m_currentDirection == sf::Vector2i(-1, 0))
			{
				setRotation(0);
				setScale(-1, 1);
			}
			else if (m_currentDirection == sf::Vector2i(0, -1))
			{
				setRotation(90);
				setScale(-1, 1);
			}

		}
	}

	//MAKING ARRAY OF POSSiBLE DIRECTIONS AT GIVEN INTERSECTION

	static sf::Vector2i directions[4] = { 
		sf::Vector2i(1,0), sf::Vector2i(-1,0),
		sf::Vector2i(0,1), sf::Vector2i(0,-1)
	};

	if (cellPos != m_lastIntersection)
	{
		if ((!m_currentDirection.y && (offset.x > -2 && offset.x < 2)) ||
			(!m_currentDirection.x && (offset.y > -2 && offset.y < 2)))
		{
			std::array<bool, 4> possibleDirections;

			int i = 0;
			for (auto direction : directions)			//checking if there is a wall in this direction
			{
				possibleDirections[i] = m_map->isWall(cellPos + direction);
				i++;
			}

			if (m_possibleDirections != possibleDirections)
			{
				m_lastIntersection = cellPos;
				m_possibleDirections = possibleDirections;

				updateDirection();
			}
		}
	}
}

void Movable::setDirection(sf::Vector2i direction)
{
	m_nextDirection = direction;
}

sf::Vector2i Movable::getDirection() const
{
	return m_currentDirection;
}
