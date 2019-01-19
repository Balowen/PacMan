#pragma once
#include "Movable.h"
#include "Animation.h"
#include "PacMan.h"


class Ghost : public Movable
{
public:
	Ghost(sf::Texture& texture, PacMan* pacMan);	//wskaznik zeby wiedziec gdzie 
	~Ghost();									// jest pacman

	enum State
	{
		Chase,		
		Scared		//when scared, ghost is killable
	};

	void setScared(sf::Time scaredTime);
	bool isScared() const;

	float normalizeAngle(float x);

	void update(sf::Time elapsedTime);

protected:
	void updateDirection();

private:
	sf::Sprite m_sprite;
	bool m_isScared;
	sf::Time m_scaredTime;	//how long a ghost stay scared
	PacMan* m_pacMan;	//przyda sie do kolizji


	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Animation m_scaredAnimation;
	Animation m_chaseAnimation;



};

