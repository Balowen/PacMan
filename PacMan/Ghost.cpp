#include "Ghost.h"
#include "GameState.h"


Ghost::Ghost(sf::Texture& texture,PacMan* pacMan)
:m_sprite(texture)
,m_isScared(false)
,m_scaredTime(sf::Time::Zero)
,m_pacMan(pacMan)
{
	m_sprite.setOrigin(7, 7);
	m_sprite.setScale(2.5, 2.5);

	m_chaseAnimation.addFrame(sf::IntRect(4, 65, 14, 14));
	m_chaseAnimation.addFrame(sf::IntRect(20, 65, 14, 14));

	m_scaredAnimation.addFrame(sf::IntRect(132, 65, 14, 14));
	m_scaredAnimation.addFrame(sf::IntRect(148, 65, 14, 14));

	m_chaseAnimation.play(sf::seconds(0.25),true);
	m_scaredAnimation.play(sf::seconds(1), true);
	
}

Ghost::~Ghost()
{
}

void Ghost::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		
	target.draw(m_sprite, states);
}

void Ghost::update(sf::Time elapsedTime)
{
	if (m_isScared)
	{
		m_scaredTime -= elapsedTime;	//if ghost is scared, slowly decrease scaredTime
		if (m_scaredTime <= sf::Time::Zero)
		{
			m_isScared = false;
			m_chaseAnimation.play(sf::seconds(0.25), true);	//play chase animation
		}
	}
	
	if (!m_isScared)
	{
		m_chaseAnimation.update(elapsedTime);
		m_chaseAnimation.animate(m_sprite);
	}
	else
	{
		m_scaredAnimation.update(elapsedTime);
		m_scaredAnimation.animate(m_sprite);
	}
	Movable::update(elapsedTime);
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

void Ghost::updateDirection()
{
	static sf::Vector2i directions[4] = {
		sf::Vector2i(1,0),
		sf::Vector2i(-1,0),
		sf::Vector2i(0,1),
		sf::Vector2i(0,-1)
	};
	//http ://cpp0x.pl/kursy/Kurs-C++/Poziom-5/Kontenery-asocjacyjne-std-set-i-std-map/589
	std::map<float, sf::Vector2i> directionHierarchy;	//zapisuje roznice katow do pacmana i odpowiadajcy kierunek, map<> sam posortuje
	std::map<float, sf::Vector2i>::reverse_iterator rit;
	float angleToPac;

	sf::Vector2f distanceToPac = m_pacMan->getPosition() - getPosition();

	angleToPac = std::atan2(distanceToPac.x, distanceToPac.y) *(180/3.14); //atan2 zwraca kat w radianach

	for (auto direction : directions)
	{
		float angle_toDirection = std::atan2(direction.x, direction.y)*(180 / 3.14);

		//float difference = 180 - std::abs(std::abs(angle_toDirection - angleToPac) - 180);
		float difference = normalizeAngle(angle_toDirection - angleToPac);

		directionHierarchy[difference] = direction;		//difference(k¹t) to klucz wdg ktorego posortuje
													//best directions are first in map<>
	}
	
		setDirection(directionHierarchy.begin()->second);	//begin() zwraca iterator, ->first to klucz (tutaj kat),->second to direction

		//keep going with best possible direction

		auto it = directionHierarchy.begin();
		rit = directionHierarchy.rbegin();
		if (!this->isScared())
		{
			do
			{

				setDirection(it->second);
				it++;

			} while (!canMove());
		}
		else
		{

			do
			{

				setDirection(rit->second);
				rit++;

			} while (!canMove());
		}
	
}

float Ghost::normalizeAngle(float x)
{
	x = 180 - std::abs(std::abs(x)-180);
	return x;
}



