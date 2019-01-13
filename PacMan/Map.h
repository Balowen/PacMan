#pragma once
#include <SFML/Graphics.hpp>
#include <array>
class Map : public sf::Drawable
{
public:
	Map();
	~Map();

	void loadMap(std::string levelName);
	sf::Vector2i getPacManPosition() const;
	std::vector<sf::Vector2i> getGhostPosition() const;

	std::size_t positionToIndex(sf::Vector2i position) const;
	sf::Vector2i indexToPosition(std::size_t index) const;

private:
	enum singleCell
	{
		Wall,
		Empty,
		Dot,
		BigDot,
		Fruit
	};

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2i pacManPosition;
	std::vector<sf::Vector2i> ghostsPositions;

	sf::Vector2i m_mapSize;
	std::vector<singleCell> m_mapData;	//what is a wall, what is a ghost start point etc.

	sf::RenderTexture m_texture;	//to render the level
};

