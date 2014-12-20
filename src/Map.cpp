#include "Map.h"

void Map::Initialize() 
{
	int tileID = 0;

	m_MapData.resize( m_MapWidth * m_MapHeight );

	for( int y = 0; y < m_MapHeight; y++ ) 
		for( int x = 0; x < m_MapWidth; x++ ) 
			m_MapData[ y * m_MapWidth + x ] = 0;

	for( int x = 0; x < m_MapWidth; x++ ) 
	{
		m_MapData[ x ] = 1;
		m_MapData[ (m_MapHeight-1) * m_MapWidth + x ] = 1;
	}

	for( int y = 0; y < m_MapHeight; y++ ) 
	{
		m_MapData[ y * m_MapWidth  ] = 1;
		m_MapData[ (y * m_MapWidth) + m_MapWidth-1 ] = 1;
	}

	m_MapData[ ((( m_MapHeight / 2 ) * m_MapWidth ) + m_MapWidth / 2 )     ] = 2;
	m_MapData[ ((( m_MapHeight / 2 ) * m_MapWidth ) + m_MapWidth / 2 ) - 1 ] = 2;
	m_MapData[ ((( m_MapHeight / 2 ) * m_MapWidth ) + m_MapWidth / 2 ) - m_MapWidth    ] = 2;
	m_MapData[ ((( m_MapHeight / 2 ) * m_MapWidth ) + m_MapWidth / 2 ) - m_MapWidth -1 ] = 2;
	
}

void Map::Update()
{
	
}

void Map::Render( sf::RenderWindow* Window )
{		
	std::unique_ptr<sf::RectangleShape> Rectangle( new sf::RectangleShape() );
	Rectangle->setSize( sf::Vector2f( m_TileSize, (float) m_TileSize ) );

	for( int y = 0; y < m_MapHeight; y++ ) 
	{
		for( int x = 0; x < m_MapWidth; x++ ) 
		{
			switch( m_MapData[ y * m_MapWidth + x ] )
			{
				case 1:
					Rectangle->setPosition( (float) x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color( 0, 0, 100 ));
					Window->draw( *Rectangle );
				break;
				case 2:
					Rectangle->setPosition( (float) x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color( 150, 150, 0 ) );
					Window->draw( *Rectangle );
				break;
				case 3:
					Rectangle->setPosition( (float) x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color::Blue );
					Window->draw( *Rectangle );
				break;
				default:
					Rectangle->setPosition( (float) x * m_TileSize, y * m_TileSize );
					Rectangle->setFillColor( sf::Color( 0, 100, 0 ) );
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
