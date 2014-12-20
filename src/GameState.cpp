#include "GameState.h"

const int DEFAULT_MAP_WIDTH  = 16;
const int DEFAULT_MAP_HEIGHT = 11;

void GameState::VInitialize() 
{
	m_Map = new Map( m_MapWidth, m_MapHeight );
	m_Map->Initialize();
}

void GameState::VUpdate() 
{
	m_Map->Update();
}

void GameState::VRender( sf::RenderWindow* window ) 
{
	m_Map->Render( window );
}

GameState::GameState( int ScreenWidth, int ScreenHeight ) :
	IState( ScreenWidth, ScreenHeight ),
	m_MapWidth( DEFAULT_MAP_WIDTH ), m_MapHeight( DEFAULT_MAP_HEIGHT )
{
}

GameState::~GameState(void)
{
}
