#include "Map.h"

void Map::Initialize() 
{
	int tileID = 0;

	m_MapData.resize( m_MapWidth * m_MapHeight );

	for( int y = 0; y < m_MapHeight; y++ ) 
	{
		for( int x = 0; x < m_MapWidth; x++ ) 
		{
			m_MapData[ y * m_MapWidth + x ] = tileID;

			if( tileID < 3 )
				tileID++;
			else
				tileID = 0;
		}
	}
}

void Map::Update()
{
	
}

void Map::Render( sf::RenderWindow* Window )
{		
	std::unique_ptr<sf::RectangleShape> Rectangle( new sf::RectangleShape() );
	Rectangle->setSize( sf::Vector2f( m_TileSize, m_TileSize ) );

	for( int y = 0; y < m_MapHeight; y++ ) 
	{
		for( int x = 0; x < m_MapWidth; x++ ) 
		{
			switch( m_MapData[ y * m_MapWidth + x ] )
			{
				case 1:
					Rectangle->setPosition( x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color::Red );
					Window->draw( *Rectangle );
				break;
				case 2:
					Rectangle->setPosition( x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color::Green );
					Window->draw( *Rectangle );
				break;
				case 3:
					Rectangle->setPosition( x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color::Blue );
					Window->draw( *Rectangle );
				break;
				default:
					Rectangle->setPosition( x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color::Cyan );
					Window->draw( *Rectangle );
				break;
			}
		}
	}
}

Map::Map( int MapWidth, int MapHeight ) :
	m_TileSize( MAP_DEFAULT_TILESIZE ),
	m_MapWidth( MapWidth ), m_MapHeight( MapHeight )
{
	
}

Map::~Map(void)
{
}
