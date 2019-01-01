#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Game
{
public:
	Game();
	

	void run();

	void changeGameState(GameState::State next_gameState);
	
private:
	sf::RenderWindow m_window;
	GameState* m_currentState;		

};

