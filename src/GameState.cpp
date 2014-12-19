#include "GameState.h"


void GameState::Initialize() 
{
	m_Map = new Map( 10, 8 );
	m_Map->Initialize();
}

void GameState::Update() 
{
	m_Map->Update();
}

void GameState::Render( sf::RenderWindow* window ) 
{
	m_Map->Render( window );
}

GameState::GameState( int ScreenWidth, int ScreenHeight ) :
	State( ScreenWidth, ScreenHeight )
{
}

GameState::~GameState(void)
{
}
