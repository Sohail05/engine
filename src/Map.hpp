#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

const int MAP_DEFAULT_TILESIZE = 64;

class Map
{
public:
	Map(int mapWidth, int mapHeight);
	~Map(void);

	void initialize();                          ///< Intialize the Map Data
	void update();   	                        ///< Update the Map Data
	void render(sf::RenderWindow* renderWindow); ///< Render the Map Data @param Handle to the Render Window
	
	inline void setTileSize(int tileSize) { m_tileSize = tileSize; } ///< Set the Size to Draw Tiles @param Size in Pixels

private:
	int m_mapWidth;  ///< The Width of the Map in Pixels
	int m_mapHeight; ///< The Height of the Map in Pixels
	int m_tileSize;  ///< The Size of each tile in Pixels

	std::vector<int> m_mapData; ///< The indices that hold the value of the maps

};

