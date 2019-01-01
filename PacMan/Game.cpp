#include "Game.h"
#include <iostream>


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

			// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))  it is better for const pressing button
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::S)
					pressStart();
				
				if (event.key.code == sf::Keyboard::Up)
					movePacman(sf::Vector2i(0, -1));
				if (event.key.code == sf::Keyboard::Down)
					movePacman(sf::Vector2i(0, 1));
				if (event.key.code == sf::Keyboard::Left)
					movePacman(sf::Vector2i(-1, 0));
				if (event.key.code == sf::Keyboard::Right)
					movePacman(sf::Vector2i(1, 0));

			}
		}

		m_window.clear();
		// draw  something here
		m_window.display();
	}
}

void Game::pressStart()
{
	std::cout << "Kliknales start" << std::endl;
}

void Game::movePacman(sf::Vector2i direction)
{
	std::cout << "Pacman sie rusza" << std::endl;
}

