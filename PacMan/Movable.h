#pragma once
#include <SFML/Graphics.hpp>

class Movable : public sf::Drawable, public sf::Transformable
{
public:
	Movable();
	~Movable();

	void setVelocity(float velocity);
	float getVelocity() const;

private:
	float m_velocity;		
};

