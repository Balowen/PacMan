#include "Ghost.h"



Ghost::Ghost(sf::Texture& texture,PacMan* pacMan)
:m_sprite(texture)
,m_isScared(false)
,m_scaredTime(sf::Time::Zero)
//,m_pacMan(m_pacMan)
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
		sf::Vector2i(1,0), sf::Vector2i(-1,0),
		sf::Vector2i(0,1), sf::Vector2i(0,-1)
	};
	//http://cpp0x.pl/kursy/Kurs-C++/Poziom-5/Kontenery-asocjacyjne-std-set-i-std-map/589
	std::map<float, sf::Vector2i> directionHierarchy;	//zapisuje roznice katow do pacmana i odpowiadajcy kierunek, map<> sam posortuje

	float angleToPac;

	sf::Vector2f distanceToPac = m_pacMan->getPosition() - this->getPosition();
	angleToPac = std::atan2(distanceToPac.x, distanceToPac.y) *(180/3.14); //atan2 zwraca kat w radianach

	for (auto direction : directions)
	{
		float angle_toDirection = std::atan2(direction.x, direction.y) *(180/3.14);

		float difference = normalizeAngle(angle_toDirection - angleToPac);

		directionHierarchy[difference] = direction;		//difference(k¹t) to klucz wdg ktorego posortuje
	}
	setDirection(directionHierarchy.begin()->second);	//begin() zwraca iterator, ->first to klucz (tutaj k¹t),->second to direction


}

float Ghost::normalizeAngle(float x)
{
	x = fmod(x + 180, 360);
	if (x < 0)
		x += 360;
	return x - 180;
}

