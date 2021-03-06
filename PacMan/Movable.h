#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <array>


class Movable : public sf::Drawable, public sf::Transformable
{
public:
	Movable();
	~Movable();

	void setVelocity(float velocity);
	float getVelocity() const;
	virtual void update(sf::Time delta);

	void setDirection(sf::Vector2i direction);
	sf::Vector2i getDirection() const;

	void accessMap(Map* map);

	bool canMove() const;	//can a ghost move in this direction

	sf::FloatRect getCollisionBox() const;
protected:
	virtual void updateDirection() {};

private:
	Map* m_map;
	float m_velocity;		

	sf::Vector2i m_currentDirection;
	sf::Vector2i m_nextDirection;

	sf::Vector2i m_lastIntersection;	// cell position of the last intersection (road + )
	std::array<bool, 4> m_possibleDirections;


	
};

