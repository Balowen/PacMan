#pragma once
#include <SFML/Graphics.hpp>


class Fruit : public sf::Drawable, public sf::Transformable
{
public:
	enum bonusFruit
	{
		cherry,
		strawberry,
		peach,
		apple,
		melon
	};

	Fruit(sf::Texture& texture); //konstruktor z referencja na teksture (owocu)
	void setBonusFruit(bonusFruit fruit);

	

	//https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php
	//any class inheriting from Drawable, has to implement private draw method from it:
	//virtual void 	draw (RenderTarget &target, RenderStates states) const =0
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite m_sprite;

};

