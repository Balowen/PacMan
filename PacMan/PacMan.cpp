#include "PacMan.h"



PacMan::PacMan(sf::Texture& texture)
:m_sprite(texture)
,m_isDying(false)
,m_isDead(false)
{
	m_sprite.setOrigin(7, 7);		// Pacman sprite is 14 x 14

	m_aliveAnimation.addFrame(sf::IntRect(1, 1, 14, 14));
	m_aliveAnimation.addFrame(sf::IntRect(1 + 18, 1, 14, 14));

	m_dieAnimation.addFrame(sf::IntRect(36, 1, 14, 14));
	m_dieAnimation.addFrame(sf::IntRect(36+16, 1, 14, 14));
	m_dieAnimation.addFrame(sf::IntRect(36 + 31, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 31, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 47, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 63, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 79, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 95, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 111, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 127, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 143, 1, 15, 15));
	m_dieAnimation.addFrame(sf::IntRect(36 + 159, 1, 15, 15));

	m_aliveAnimation.play(sf::milliseconds(25), true);	//0.25 per frame and loop animation

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
	if (!m_isDying)
	{
		m_dieAnimation.play(sf::seconds(1),false);
		m_isDying = true;
	}
}

bool PacMan::isDead() const
{
	return m_isDead;
}

bool PacMan::isDying() const
{
	return m_isDying;
}
