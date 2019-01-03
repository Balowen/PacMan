#pragma once
#include "Movable.h"

class Ghost : public Movable
{
public:
	Ghost();
	~Ghost();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

