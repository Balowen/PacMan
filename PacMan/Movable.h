#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Movable : public sf::Drawable, public sf::Transformable
{
public:
	Movable();
	~Movable();

	void setVelocity(float velocity);
	float getVelocity() const;
	virtual void update(sf::Time delta);

	void changeDirection(sf::Vector2i direction);
	sf::Vector2i getDirection() const;

	void accessMap(Map* map);

private:
	Map* m_map;
	float m_velocity;		

	sf::Vector2i m_currentDirection;
	sf::Vector2i m_nextDirection;
};

