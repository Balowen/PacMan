#pragma once
#include "Movable.h"
#include "Animation.h"

class PacMan : public Movable 
{
public:
	PacMan(sf::Texture& texture);
	~PacMan();

	void die();
	bool isDead() const;
	bool isDying() const;
	

private:
	Animation m_aliveAnimation;
	Animation m_dieAnimation;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite m_sprite;
	bool m_isDead;
	bool m_isDying;
};

