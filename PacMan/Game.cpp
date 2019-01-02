#include "Game.h"
#include <iostream>

//here takes place the gameloop
//and drawwing/drawing

Game::Game()
:m_window(sf::VideoMode(640,480),"PacMan")
{
	m_gameStates[GameState::State::GetReady] = new GetReadyState(this);
	m_gameStates[GameState::State::Play] = new PlayState(this);
	m_gameStates[GameState::State::Victory] = new VictoryState(this);
	m_gameStates[GameState::State::Defeat] = new DefeatState(this);

	changeGameState(GameState::State::GetReady);	//initial state, when game launches
}


Game::~Game()
{
	//https://en.cppreference.com/w/cpp/language/range-for		range-based loop
	for (GameState* gamestate : m_gameStates)		//moge tak zrobic, ale musi byc ten sam typ
		delete gamestate;											//danych co w vector
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
					m_currentState->pressStart();			// every state has it's own methods
				
				if (event.key.code == sf::Keyboard::Up)
					m_currentState->movePacman(sf::Vector2i(0, -1));
				if (event.key.code == sf::Keyboard::Down)
					m_currentState->movePacman(sf::Vector2i(0, 1));
				if (event.key.code == sf::Keyboard::Left)
					m_currentState->movePacman(sf::Vector2i(-1, 0));
				if (event.key.code == sf::Keyboard::Right)
					m_currentState->movePacman(sf::Vector2i(1, 0));

			}
		}
		m_currentState->update(sf::seconds(1));			// seconds (1.0f) ?? sprawdz
		m_window.clear();
		// draw  something here
		m_currentState->draw(m_window);
		m_window.display();
	}
}

void Game::changeGameState(GameState::State next_gameState)
{
	m_currentState = m_gameStates[next_gameState];
}



