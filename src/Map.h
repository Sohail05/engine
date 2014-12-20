#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

const int MAP_DEFAULT_TILESIZE = 64;

class Map
{
public:
	Map( int MapWidth, int MapHeight );
	~Map(void);

	void Initialize();                       ///< Intialize the Map Data
	void Update();   	                     ///< Update the Map Data
	void Render( sf::RenderWindow* Window ); ///< Render the Map Data @param Handle to the Render Window
	
	inline void SetTileSize( int TileSize ) { m_TileSize = TileSize; } ///< Set the Size to Draw Tiles @param Size in Pixels

private:
	int m_MapWidth;  ///< The Width of the Map in Pixels
	int m_MapHeight; ///< The Height of the Map in Pixels
	int m_TileSize;  ///< The Size of each tile in Pixels

	std::vector<int> m_MapData; ///< The indices that hold the value of the maps

};

