#include "Game.h"



Game::Game()
:m_window(sf::VideoMode(640,480),"PacMan")
{

}


Game::~Game()
{
}

void Game::run()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)	//if user clicks exit button
				m_window.close();
		}

		m_window.clear();
		// draw  something here
		m_window.display();
	}
}