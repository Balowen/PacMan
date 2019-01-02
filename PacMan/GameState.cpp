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
	m_text.setPosition(640 / 2.0f, 480 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);

	m_text2.setFont(game->getFont());
	m_text2.setString("Press space to play");
	m_text2.setPosition(30, 430);

}

GetReadyState::GetReadyState(Game* game)
:GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("PRESS SPACE IF YOU ARE READY");
	m_text.setPosition(640 / 2.0f, 480 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
}

PlayState::PlayState(Game* game)
:GameState(game)
{
}

VictoryState::VictoryState(Game* game)
:GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("VICTORY");
	m_text.setPosition(640 / 2.0f, 480 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
}

DefeatState::DefeatState(Game* game)
:GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("You lost");
	m_text.setPosition(640 / 2.0f, 480 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);

	m_text2.setFont(game->getFont());
	m_text2.setString("Press space to exit to menu");
	m_text2.setPosition(20, 430);
}

Game* GameState::getGame() const		//dzi�ki tej metodzie zmieniam stany gry
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
	window.draw(m_text2);
}

void GetReadyState::pressStart()
{
	getGame()->changeGameState(GameState::Play);
}

void GetReadyState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void GetReadyState::update(sf::Time delta)
{// TO DO !!!!!!!!
}

void GetReadyState::draw(sf::RenderWindow & window)
{
	window.draw(m_text);
}

void PlayState::pressStart()
{// TO DO !!!!!!!!
}

void PlayState::movePacman(sf::Vector2i direction)
{
	if (direction.x == -1)
		getGame()->changeGameState(GameState::Victory);	//just to check if it works
	else if (direction.x == 1)
		getGame()->changeGameState(GameState::Defeat);
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
{
	window.draw(m_text);
}

void DefeatState::pressStart()
{
	getGame()->changeGameState(GameState::Menu);
}

void DefeatState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void DefeatState::update(sf::Time delta)
{// TO DO !!!!!!!!
}

void DefeatState::draw(sf::RenderWindow & window)
{
	window.draw(m_text);
	window.draw(m_text2);
}