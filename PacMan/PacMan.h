#pragma once
#include "Movable.h"

class PacMan : public Movable 
{
public:
	PacMan();
	~PacMan();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite m_sprite;
};

