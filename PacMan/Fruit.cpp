#include "Fruit.h"



Fruit::Fruit(sf::Texture& texture)
:m_sprite(texture)
{
	m_sprite.setOrigin(7, 7);	//every sprite is 14x14 large
	setBonusFruit(cherry);	//first, cherry appears :D !
}
 
Fruit::~Fruit()
{
}

void Fruit::setBonusFruit(bonusFruit fruit)
{
	if (fruit == cherry)
		m_sprite.setTextureRect(sf::IntRect(36, 49, 14, 14));
	else if (fruit == strawberry)
		m_sprite.setTextureRect(sf::IntRect(36 + 16, 49, 14, 14));		//zmierzone w gimpie
	else if (fruit == peach)
		m_sprite.setTextureRect(sf::IntRect(36 + 32, 49, 14, 14));
	//TO DO:
	// ADD MORE FRUITS
}

void Fruit::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		//taka sama implementacja jak w dokumentacji
	target.draw(m_sprite, states);	//https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Transformable.php
}




