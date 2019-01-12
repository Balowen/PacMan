#include "Map.h"


Map::Map()
:m_mapSize(0,0)
{
}


Map::~Map()
{
}

void Map::loadMap(std::string levelName)
{
	sf::Image level_Image;
	if (!level_Image.loadFromFile("assets/" + levelName + ".png"))
		throw std::runtime_error("Nie udalo sie wczytac poziomu");

	m_mapSize = sf::Vector2i(level_Image.getSize());	//getSize() returns vector2u - unsigned int

	//loading the level pixel after pixel
	for (unsigned int y = 0; y < m_mapSize.y; y++)
	{
		for (unsigned int x = 0; x < m_mapSize.x; x++)
		{
			sf::Color singleCell = level_Image.getPixel(x, y);

			if (singleCell == sf::Color::Black)
				m_mapData.push_back(Wall);
			else if (singleCell == sf::Color::White)
				m_mapData.push_back(Dot);
			else if (singleCell == sf::Color::Green)
				m_mapData.push_back(BigDot);
			else if (singleCell == sf::Color::Blue)
				m_mapData.push_back(Empty);
		}
	}

}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}
