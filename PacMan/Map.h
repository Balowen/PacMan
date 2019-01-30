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
	std::vector<sf::Vector2i> getGhostsPositions() const;


	std::size_t positionToIndex(sf::Vector2i position) const;
	sf::Vector2i indexToPosition(std::size_t index) const;

	sf::Vector2i transform_pixelToCell(sf::Vector2f pixel) const;
	sf::Vector2f transform_cellToPixel(sf::Vector2i cell) const;

	bool isWall(sf::Vector2i position) const;	// zwraca czy dana pozycja jest sciana
	sf::Vector2i getSize() const;

	bool isBigDot(sf::Vector2i position) const;
	bool isFruit(sf::Vector2i position) const;
	void collectObject(sf::Vector2i position);


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

