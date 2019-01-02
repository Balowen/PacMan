#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <array>

class Game
{
public:
	Game();
	~Game();

	void run();

	void changeGameState(GameState::State next_gameState);

	sf::Font& getFont();
	sf::Texture& getTexture();
	sf::Texture& getGameLogo();
	
private:
	sf::RenderWindow m_window;
	GameState* m_currentState;
	// array of all gameStates
	std::array<GameState*, GameState::Counter> m_gameStates;	//moglbym dac ilosc stanow gry, ale lepiej size/counter

	sf::Font m_font;
	sf::Texture m_texture;		//wszystkie tekstury w jednym
	sf::Texture m_gameLogo;
};

