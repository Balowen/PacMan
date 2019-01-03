#include "PacMan.h"



PacMan::PacMan(sf::Texture& texture)
:m_sprite(texture)
,m_isDying(false)
,m_isDead(false)
{
	m_sprite.setOrigin(7, 7);		// Pacman sprite is 14,14

}


PacMan::~PacMan()
{
}

void PacMan::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//display sprite only if pacman isn't dead
	states.transform *= getTransform();
	if (!m_isDead)
	{
		target.draw(m_sprite, states);
	}
}

void PacMan::die()
{
	m_isDead = true;
}

bool PacMan::isDead() const
{
	return m_isDead;
}

bool PacMan::isDying() const
{
	return m_isDying;
}
