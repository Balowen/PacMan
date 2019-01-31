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
	m_text.setPosition(678 / 2.0f, 700 / 2.0f);
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
	m_text.setPosition(678 / 2.0f, 700 / 2.0f);
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
	m_screen.create(672, 672);

	m_pointsText.setFont(game->getFont());
	m_pointsText.setCharacterSize(20);
	m_pointsText.setPosition(10, 675);
	m_pointsText.setString("0 points");

	m_currentLevelText.setFont(game->getFont());	
	m_currentLevelText.setCharacterSize(20);	
	m_currentLevelText.setPosition(180, 675);
	m_currentLevelText.setString("1 level");

	for (auto& lives : m_livesSprite)
	{
		lives.setTexture(game->getTexture());
		lives.setScale(2, 2);
		lives.setTextureRect(sf::IntRect(19, 1, 14, 14));
	}
	m_livesSprite[0].setPosition(sf::Vector2f(580, 675));
	m_livesSprite[1].setPosition(sf::Vector2f(610, 675));
	m_livesSprite[2].setPosition(sf::Vector2f(640, 675));


}

void PlayState::resetCharactersPosition()
{
	m_pacMan->setPosition(m_map.transform_cellToPixel(m_map.getPacManPosition()));
	auto ghostPositions = m_map.getGhostsPositions();
	
	for (unsigned int i = 0; i < m_ghosts.size(); i++)
	{
		m_ghosts[i]->setPosition(m_map.transform_cellToPixel(ghostPositions[i]));
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
	//if (direction.x == -1)
	//	getGame()->changeGameState(GameState::Victory);	//just to check if it works
	//else if (direction.x == 1)
	//	getGame()->changeGameState(GameState::Defeat);
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

	sf::Vector2f pixelPos = m_pacMan->getPosition();
	sf::Vector2f offset(std::fmod(pixelPos.x, 32), std::fmod(pixelPos.y, 32));
	offset -= sf::Vector2f(16, 16);

	// collecting bonuses
	if (offset.x <= 2 && offset.x >= -2 && offset.y <= 2 && offset.y >=-2)
	{
		sf::Vector2i cellPos = m_map.transform_pixelToCell(pixelPos);

		if (m_map.isBigDot(cellPos))	
		{
			//duchy sie boja
			for (Ghost* ghost : m_ghosts)
			{
				ghost->setScared(sf::seconds(6));
			}
		 }

		m_map.collectObject(cellPos);
	}
	// collision with ghosts
	for (Ghost* ghost : m_ghosts)
	{
		if (ghost->getCollisionBox().intersects(m_pacMan->getCollisionBox()))
		{
			if (ghost->isScared())
			{
				//ghost dies -> delete him from the list of ghosts
				m_ghosts.erase(std::find(m_ghosts.begin(), m_ghosts.end(), ghost));
			}
			else
			{
				m_pacMan->die();//pacman dies
			}
		}
	}
	if (m_pacMan->isDead())
	{
		m_pacMan->reset();
		//getGame()->changeGameState(GameState::Defeat);
		resetCharactersPosition();
	}
}

void PlayState::draw(sf::RenderWindow & window)
{// TO DO !!!!!!!!
	m_screen.clear();
	m_screen.draw(m_map);
	m_screen.draw(*m_pacMan);
	
	for (Ghost* ghost : m_ghosts)
		m_screen.draw(*ghost);

	m_screen.display();
	window.draw(sf::Sprite(m_screen.getTexture()));

	window.draw(m_pointsText);
	window.draw(m_currentLevelText);
	
	for (unsigned int i = 0; i < 3; i++)
		window.draw(m_livesSprite[i]);
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