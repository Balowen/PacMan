#pragma once
#include <SFML/Graphics.hpp>

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
		GetReady,
		Playing,
		Win,
		Lost
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
class GetReadyState : public GameState
{
public:
	GetReadyState(Game* game);

	void pressStart();
	void movePacman(sf::Vector2i direction);
	void update(sf::Time delta);
	void draw(sf::RenderWindow& window);		// RenderWindow&  refere
};
