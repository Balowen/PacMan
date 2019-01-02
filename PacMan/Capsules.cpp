#include "Capsules.h"

sf::CircleShape dot()
{
	sf::CircleShape dot;
	dot.setRadius(3);
	dot.setFillColor(sf::Color::White);
	dot.setOrigin(3, 3);

	return dot;
}

sf::CircleShape bigDot()
{
	sf::CircleShape bigDot;
	bigDot.setRadius(6);
	bigDot.setFillColor(sf::Color::White);
	bigDot.setOrigin(6, 6);

	return bigDot;
}
