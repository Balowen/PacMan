#include "Map.h"
#include "Capsules.h"
#include <cassert>
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
			{
				pacManPosition = sf::Vector2i(x, y);
				m_mapData.push_back(Empty);	//pacman starting position
			}
			else if (singleCell == sf::Color::Red)
			{
				ghostsPositions.push_back(sf::Vector2i(x, y));
				m_mapData.push_back(Empty);	//ghost starting position
			}
			else
				m_mapData.push_back(Empty);
		}
	}

	m_texture.create(32 * m_mapSize.x, 32 * m_mapSize.y);	//single cell is 32x32 large
	m_texture.clear(sf::Color::Black);		//background of the level

	//drawing here

	m_texture.display();

	//---------------- RENDERING WALLS -----------------

	for (unsigned int i = 0; i < m_mapData.size(); i++)
	{
		sf::Vector2i position = indexToPosition(i);	//changing index to position for whole mapData

		if (m_mapData[i] == Wall)
		{
			sf::RectangleShape wall;
			wall.setSize(sf::Vector2f(32, 32));
			wall.setFillColor(sf::Color::Cyan);
			wall.setPosition(32 * position.x,32 * position.y);
			m_texture.draw(wall);		//drawing walls of a level on a black texture
		}
	}


}

sf::Vector2i Map::getSize() const
{
	return m_mapSize;
}

sf::Vector2i Map::getPacManPosition() const
{
	return pacManPosition;
}

std::vector<sf::Vector2i> Map::getGhostsPositions() const
{
	return ghostsPositions;
}

std::size_t Map::positionToIndex(sf::Vector2i position) const
{
	return position.y * m_mapSize.x + position.x;
}

sf::Vector2i Map::indexToPosition(std::size_t index) const
{
	sf::Vector2i position;

	position.x = index % m_mapSize.x;	//mam rozrysowane na kartce
	position.y = index / m_mapSize.x;

	return position;
}

sf::Vector2i Map::transform_pixelToCell(sf::Vector2f pixel) const
{
	sf::Vector2i cell;
	cell.x = std::floor(pixel.x / 32.f);
	cell.y = std::floor(pixel.y / 32.f);
	
	return cell;
}

sf::Vector2f Map::transform_cellToPixel(sf::Vector2i cell) const
{
	sf::Vector2f pixel;
	pixel.x = cell.x * 32 + 16;		//dodajemy 16 zeby pozycja byla w srodku komórki 32x32
	pixel.y = cell.y * 32 + 16;
	return pixel;
}

bool Map::isWall(sf::Vector2i position) const
{
	//------sprawdzenie czy pozycja miesci sie w granicach labiryntu
	if (position.x < 0 || position.y < 0 || position.x >= m_mapSize.x || position.y >= m_mapSize.y)
		return false;

	return m_mapData[positionToIndex(position)] == Wall;	//sprawdza czy dana pozycja jest scian¹
}

bool Map::isBigDot(sf::Vector2i position) const
{
	return m_mapData[positionToIndex(position)] == BigDot;
}

bool Map::isFruit(sf::Vector2i position) const
{
	return m_mapData[positionToIndex(position)] == Fruit;
}

void Map::collectObject(sf::Vector2i position)
{
	assert(!isWall(position));	//sprawdza czy zwraca 0, jesli tak wyrzuca blad 
	m_mapData[positionToIndex(position)] = Empty;
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sf::Sprite(m_texture.getTexture()), states);

	//-------------- CREATING DOTS (capsules.cpp)
	static sf::CircleShape dot = createDot();
	static sf::CircleShape bigDot = createBigDot();

	for (unsigned int i = 0; i < m_mapData.size(); i++)
	{
		sf::Vector2i position = indexToPosition(i);	//changing index to position for whole mapData

		if (m_mapData[i] == Dot)
		{
			dot.setPosition(32 * position.x + 16, 32 * position.y + 16);
			target.draw(dot, states);		//drawing walls of a level on a black texture
		}
		else if (m_mapData[i] == BigDot)
		{
			bigDot.setPosition(32 * position.x + 16, 32 * position.y + 16);
			target.draw(bigDot, states);
		}
	}
}
