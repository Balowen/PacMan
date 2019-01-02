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
	
private:
	sf::RenderWindow m_window;
	GameState* m_currentState;
	// array of all gameStates
	std::array<GameState*, GameState::Counter> m_gameStates;	//moglbym dac ilosc stanow gry, ale lepiej size/counter
};

