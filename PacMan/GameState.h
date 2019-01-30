#pragma once
#include <SFML/Graphics.hpp>
#include "Ghost.h"
#include "PacMan.h"
#include "Map.h"

//https://stackoverflow.com/questions/15827921/include-in-header-file-vs-forward-declare-and-include-in-cpp
// forward declaration zamiast  include
// bo Game pojawia sie tylko jako wskaznik
class Game;

class GameState
{
public:
	GameState(Game* game);
	~GameState();

	enum State		// all possible game states
	{
		Menu,
		GetReady,
		Play,
		Victory,
		Defeat,
		Counter			//ile jest stanow
	};

	Game* getGame() const;							//https://stackoverflow.com/questions/2156634/why-is-a-pure-virtual-function-initialized-by-0

	virtual void pressStart()=0;		//virtual bo bedzie to podklasa (dziedziczenie)
	virtual void movePacman(sf::Vector2i direction)=0;		// =0 to czesc skladni, mowi ze to funkcja virtualna
	virtual void update(sf::Time delta)=0;
	virtual void draw(sf::RenderWindow& window)=0;

private:
	Game* m_game;			// kazdy gamestate zmienia stan gry (klasa Game)
							// dlatego wskaznik do klasy Game
};

// GAME STATES			every gamestate inherits from gamestate class
class MenuState : public GameState
{
public:
	MenuState(Game* game);

	void pressStart();
	void movePacman(sf::Vector2i direction);
	void update(sf::Time delta);
	void draw(sf::RenderWindow& window);

private:
	sf::Text m_text;
	sf::Text m_text2;
	sf::Sprite m_sprite;
};

class GetReadyState : public GameState
{
public:
	GetReadyState(Game* game);

	void pressStart();
	void movePacman(sf::Vector2i direction);
	void update(sf::Time delta);
	void draw(sf::RenderWindow& window);		// RenderWindow&  refererencja

private:
	sf::Text m_text;
};

class PlayState : public GameState
{
public:
	PlayState(Game* game);
	~PlayState();

	void pressStart();
	void movePacman(sf::Vector2i direction);
	void update(sf::Time delta);
	void draw(sf::RenderWindow& window);	
	void resetCharactersPosition();
private:
	PacMan* m_pacMan;
	std::vector<Ghost*> m_ghosts;	// tablica z wieloma duchami
	
	Map m_map;
};

class VictoryState : public GameState
{
public:
	VictoryState(Game* game);

	void pressStart();
	void movePacman(sf::Vector2i direction);
	void update(sf::Time delta);
	void draw(sf::RenderWindow& window);

private:
	sf::Text m_text;

};

class DefeatState : public GameState
{
public:
	DefeatState(Game* game);

	void pressStart();
	void movePacman(sf::Vector2i direction);
	void update(sf::Time delta);
	void draw(sf::RenderWindow& window);

private:
	sf::Text m_text;
	sf::Text m_text2;
};
