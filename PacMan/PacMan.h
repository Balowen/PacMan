#pragma once
#include "Movable.h"

class PacMan : public Movable 
{
public:
	PacMan(sf::Texture& texture);
	~PacMan();

	void die();
	bool isDead() const;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite m_sprite;
	bool m_isDead;
};

