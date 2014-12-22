#include "Map.h"

void Map::initialize() 
{
	int tileID = 0;

	m_mapData.resize(m_mapWidth * m_mapHeight);

	for(int y = 0; y < m_mapHeight; y++) 
		for(int x = 0; x < m_mapWidth; x++) 
			m_mapData[y * m_mapWidth + x] = 0;

	for(int x = 0; x < m_mapWidth; x++) 
	{
		m_mapData[x] = 1;
		m_mapData[(m_mapHeight-1) * m_mapWidth + x] = 1;
	}

	for(int y = 0; y < m_mapHeight; y++) 
	{
		m_mapData[ y * m_mapWidth] = 1;
		m_mapData[(y * m_mapWidth) + m_mapWidth-1] = 1;
	}

	m_mapData[(((m_mapHeight / 2 ) * m_mapWidth) + m_mapWidth / 2)] = 2;
	m_mapData[(((m_mapHeight / 2 ) * m_mapWidth) + m_mapWidth / 2) - 1] = 2;
	m_mapData[(((m_mapHeight / 2 ) * m_mapWidth) + m_mapWidth / 2) - m_mapWidth] = 2;
	m_mapData[(((m_mapHeight / 2 ) * m_mapWidth) + m_mapWidth / 2) - m_mapWidth -1] = 2;
	
}

void Map::update()
{
	
}

void Map::render(sf::RenderWindow* renderWindow)
{	
	std::unique_ptr<sf::RectangleShape> rectangle(new sf::RectangleShape());
	rectangle->setSize(sf::Vector2f(m_tileSize, (float)m_tileSize));

	for(int y = 0; y < m_mapHeight; y++) 
	{
		for(int x = 0; x < m_mapWidth; x++) 
		{
			switch(m_mapData[y * m_mapWidth + x])
			{
				case 1:
					rectangle->setPosition((float)x * m_tileSize, y * m_tileSize);
					rectangle->setFillColor(sf::Color(0, 0, 100));
					renderWindow->draw(*rectangle);
				break;
				case 2:
					rectangle->setPosition((float)x * m_tileSize, y * m_tileSize);
					rectangle->setFillColor(sf::Color(150, 150, 0));
					renderWindow->draw(*rectangle);
				break;
				case 3:
					rectangle->setPosition((float)x * m_tileSize, y * m_tileSize);
					rectangle->setFillColor(sf::Color::Blue);
					renderWindow->draw(*rectangle);
				break;
				default:
					rectangle->setPosition((float)x * m_tileSize, y * m_tileSize);
					rectangle->setFillColor(sf::Color(0, 100, 0));
					renderWindow->draw(*rectangle);
				break;
			}
		}
	}
}

Map::Map(int mapWidth, int mapHeight) :
	m_tileSize(MAP_DEFAULT_TILESIZE),
	m_mapWidth(mapWidth), m_mapHeight(mapHeight)
{
	
}

Map::~Map(void)
{
}
