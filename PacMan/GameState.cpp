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
	m_text.setPosition(678 / 2.0f, 678 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);

	m_text2.setFont(game->getFont());
	m_text2.setString("Press space to play");
	m_text2.setPosition(30, 630);

}

GetReadyState::GetReadyState(Game* game)
:GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("PRESS SPACE IF YOU ARE READY");
	m_text.setPosition(678 / 2.0f, 678 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
}

PlayState::PlayState(Game* game)
:GameState(game)
//m_pacMan(game->getTexture())
//,m_ghost(game->getTexture())
,m_pacMan(nullptr)
{
	//m_pacMan.move(100, 100);
	//m_ghost.move(300, 300);
	m_map.loadMap("level");

	m_pacMan = new PacMan(game->getTexture());
	m_pacMan->accessMap(&m_map);
	m_pacMan->setPosition(m_map.transform_cellToPixel(m_map.getPacManPosition()));	//setting pacman initial position

	for (auto ghostPosition : m_map.getGhostsPositions())
	{
		Ghost* ghost = new Ghost(game->getTexture(),m_pacMan);
		ghost->accessMap(&m_map);
		ghost->setPosition(m_map.transform_cellToPixel(ghostPosition));

		m_ghosts.push_back(ghost);
	}
}

PlayState::~PlayState()
{
	delete m_pacMan;

	for (Ghost* ghost : m_ghosts)
		delete ghost;
}

VictoryState::VictoryState(Game* game)
:GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("VICTORY");
	m_text.setCharacterSize(43);
	m_text.setPosition(640 / 2.0f, 480 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
	
}

DefeatState::DefeatState(Game* game)
:GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("You lost");
	m_text.setCharacterSize(43);
	m_text.setPosition(640 / 2.0f, 480 / 2.0f);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
	

	m_text2.setFont(game->getFont());
	m_text2.setString("Press space to exit to menu");
	m_text2.setPosition(20, 430);
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
	window.draw(m_text2);
}

void GetReadyState::pressStart()
{
	getGame()->changeGameState(GameState::Play);
}

void GetReadyState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
	if (direction.x == -1)
		getGame()->changeGameState(GameState::Victory);	//just to check if it works
	else if (direction.x == 1)
		getGame()->changeGameState(GameState::Defeat);
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
	//m_pacMan.die();
	//m_ghost.setScared(sf::seconds(4));	//just to test
}

void PlayState::movePacman(sf::Vector2i direction)
{
	//if (direction.x == -1)
	//	getGame()->changeGameState(GameState::Victory);	//just to check if it works
	//else if (direction.x == 1)
	//	getGame()->changeGameState(GameState::Defeat);
	m_pacMan->setDirection(direction);
}

void PlayState::update(sf::Time delta)
{// TO DO !!!!!!!!
	m_pacMan->update(delta);
	for (Ghost* ghost : m_ghosts)
	{
		ghost->update(delta);
	}
}

void PlayState::draw(sf::RenderWindow & window)
{// TO DO !!!!!!!!
	window.draw(m_map);
	window.draw(*m_pacMan);
	
	for (Ghost* ghost : m_ghosts)
		window.draw(*ghost);
}

void VictoryState::pressStart()
{// TO DO !!!!!!!!
}

void VictoryState::movePacman(sf::Vector2i direction)
{// TO DO !!!!!!!!
}

void VictoryState::update(sf::Time delta)
{
	static sf::Time buff = sf::Time::Zero;
	buff = buff + delta;
	if (buff.asSeconds() > 5)
		getGame()->changeGameState(GameState::GetReady);
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