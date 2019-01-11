#pragma once
#include "Movable.h"
#include "Animation.h"
#include "PacMan.h"


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

	void update(sf::Time elapsedTime);
private:
	sf::Sprite m_sprite;
	bool m_isScared;
	sf::Time m_scaredTime;	//how long a ghost stay scared
	PacMan* m_pacMan;	//przyda sie do kolizji

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Animation m_scaredAnimation;
	Animation m_chaseAnimation;
};

