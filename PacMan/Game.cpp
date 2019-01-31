#include "Game.h"
#include <iostream>

//here takes place the gameloop
//and drawwing/drawing

Game::Game()
:m_window(sf::VideoMode(672, 705), "PacMan", sf::Style::Close)
{
	if (!m_font.loadFromFile("assets/font.ttf"))
		throw std::runtime_error("Blad wczytywania czcionki");

	if (!m_gameLogo.loadFromFile("assets/logo.png"))
		throw std::runtime_error("Blad wczytywania logo gry");

	if (!m_texture.loadFromFile("assets/texture.png"))
		throw std::runtime_error("Blad wczytywania tekstur");
	 
	m_gameStates[GameState::State::Menu] = new MenuState(this);
	m_gameStates[GameState::State::GetReady] = new GetReadyState(this);
	m_gameStates[GameState::State::Play] = new PlayState(this);
	m_gameStates[GameState::State::Victory] = new VictoryState(this, m_gameStates[GameState::Play]);
	m_gameStates[GameState::State::Defeat] = new DefeatState(this, m_gameStates[GameState::Play]);

	changeGameState(GameState::State::Menu);	//initial state, when game launches
}


Game::~Game()
{
	//https://en.cppreference.com/w/cpp/language/range-for		range-based loop
	for (GameState* gamestate : m_gameStates)		//moge tak zrobic, ale musi byc ten sam typ
		delete gamestate;											//danych co w vector
}

void Game::run()
{
	sf::Clock clock;

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
				if (event.key.code == sf::Keyboard::Space)
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
		m_currentState->update(clock.restart());			// seconds (1.0f) ?? sprawdz
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

sf::Font & Game::getFont()
{
	return m_font;
}

sf::Texture & Game::getTexture()
{
	return m_texture;
}

sf::Texture & Game::getGameLogo()
{
	return m_gameLogo;
}



