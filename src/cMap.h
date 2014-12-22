#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

const int MAP_DEFAULT_TILESIZE = 32;

class cMap
{
public:
	/** Intialize the default Map Data */
	void Initialize() 
	{
		int tileID = 0;

		m_MapData.resize( m_MapWidth * m_MapHeight );

		for( int y = 0; y < m_MapHeight; y++ ) 
		{
			for( int x = 0; x < m_MapWidth; x++ ) 
			{
				m_MapData[ y * m_MapWidth + x ] = tileID;

				if( tileID < 4 )
					tileID++;
				else
					tileID = 0;
			}
		}
	}

	void Render( sf::RenderWindow* Window )
	{

		std::unique_ptr<sf::CircleShape> Circle( new sf::CircleShape( (float)m_TileSize, 4 ) );
		
		for( int y = 0; y < m_MapHeight; y++ ) 
		{
			for( int x = 0; x < m_MapWidth; x++ ) 
			{
				switch( m_MapData[ y * m_MapWidth + x ] )
				{
					case 1:
						Circle->setFillColor( sf::Color::Red );
					break;
					case 2:
						Circle->setFillColor( sf::Color::Green );
					break;
					case 3:
						Circle->setFillColor( sf::Color::Blue );
					break;
					default:
						Circle->setFillColor( sf::Color::Cyan );
					break;
				}
			}

			Window->draw( *Circle );
		}	
	}

	/** Set the Size to Draw Tiles @param Size in Pixels */
	inline void SetTileSize( int TileSize ) { m_TileSize = TileSize; }


	cMap( int MapWidth, int MapHeight ) :
		m_TileSize( MAP_DEFAULT_TILESIZE ),
		m_MapWidth( MapWidth ), m_MapHeight( MapHeight )
	{
	
	}

	~cMap(void);

private:

	int m_MapWidth;
	int m_MapHeight;
	int m_TileSize;

	std::vector<int> m_MapData;

};

