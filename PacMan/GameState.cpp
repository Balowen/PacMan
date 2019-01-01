#include "GameState.h"



GameState::GameState(Game* game)
:m_game(game)
{
}


GameState::~GameState()
{
}

GetReadyState::GetReadyState(Game* game)
:GameState(game)
{
}

Game* GameState::getGame() const
{
	return m_game;
}

void GetReadyState::pressStart()
{// TO DO !!!!!!!!
}

void GetReadyState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void GetReadyState::update(sf::Time delta)
{// TO DO !!!!!!!!
}

void GetReadyState::draw(sf::RenderWindow & window)
{// TO DO !!!!!!!!
}
