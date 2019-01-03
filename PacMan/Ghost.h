#pragma once
#include "Movable.h"

class Ghost : public Movable
{
public:
	Ghost(sf::Texture& texture);
	~Ghost();

	enum State
	{
		Chase,		
		Scared		//when scared, ghost is killable
	};

	void setScared(sf::Time scaredTime);
	bool isScared() const;

private:
	sf::Sprite m_sprite;
	bool m_isScared;
	sf::Time m_scaredTime;	//how long a ghost stay scared

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

