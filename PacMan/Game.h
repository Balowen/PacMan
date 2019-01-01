#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public:
	Game();
	~Game();

	void run();

	void pressStart();

	void movePacman(sf::Vector2i direction);	//moving player x and y axis

private:
	sf::RenderWindow m_window;

};

