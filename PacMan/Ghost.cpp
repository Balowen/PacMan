#include "Ghost.h"



Ghost::Ghost(sf::Texture& texture)
:m_sprite(texture)
,m_isScared(false)
,m_scaredTime(sf::Time::Zero)	
{
	m_sprite.setOrigin(7, 7);
}

Ghost::~Ghost()
{
}

void Ghost::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		
	target.draw(m_sprite, states);
}

void Ghost::setScared(sf::Time scaredTime)
{
	m_isScared = true;
	m_scaredTime = scaredTime;
}

bool Ghost::isScared() const
{
	return m_isScared;
}
