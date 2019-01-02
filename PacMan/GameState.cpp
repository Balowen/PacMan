#include "GameState.h"
#include "Game.h"
#include <iostream>



GameState::GameState(Game* game)
:m_game(game)
{
}


GameState::~GameState()
{
}

MenuState::MenuState(Game* game)
:GameState(game)
{
	m_sprite.setTexture(game->getGameLogo());
	m_sprite.setPosition(60, 50);
	/*sf::Vector2f scale = m_sprite.getScale();			// will do for now, center it later
	std::cout << scale.x << scale.y << std::endl;*/
	m_sprite.setScale(0.7,0.7);

	m_text.setFont(game->getFont());
	m_text.setString("START GAME");
	m_text.setPosition(160, 240);
	m_text.setCharacterSize(45);

	m_instruction.setFont(game->getFont());
	m_instruction.setString("Press space to play");
	m_instruction.setPosition(30, 430);

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

Game* GameState::getGame() const		//dziêki tej metodzie zmieniam stany gry
{
	return m_game;
}

void MenuState::pressStart()
{
	getGame()->changeGameState(GameState::GetReady);
}

void MenuState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void MenuState::update(sf::Time delta)
{// TO DO !!!!!!!!
}

void MenuState::draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
	window.draw(m_text);
	window.draw(m_instruction);
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