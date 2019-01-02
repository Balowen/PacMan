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

PlayState::PlayState(Game* game)
:GameState(game)
{
}

VictoryState::VictoryState(Game* game)
:GameState(game)
{
}

DefeatState::DefeatState(Game* game)
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

void PlayState::pressStart()
{// TO DO !!!!!!!!
}

void PlayState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void PlayState::update(sf::Time delta)
{// TO DO !!!!!!!!
}

void PlayState::draw(sf::RenderWindow & window)
{// TO DO !!!!!!!!
}

void VictoryState::pressStart()
{// TO DO !!!!!!!!
}

void VictoryState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void VictoryState::update(sf::Time delta)
{// TO DO !!!!!!!!
}

void VictoryState::draw(sf::RenderWindow & window)
{// TO DO !!!!!!!!
}

void DefeatState::pressStart()
{// TO DO !!!!!!!!
}

void DefeatState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void DefeatState::update(sf::Time delta)
{// TO DO !!!!!!!!
}

void DefeatState::draw(sf::RenderWindow & window)
{// TO DO !!!!!!!!
}