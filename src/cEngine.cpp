#include "cEngine.h"

void cEngine::Initialize()
{
	// State Manager to be created

	m_GameState = new cGameState( m_WindowWidth, m_WindowHeight );
	m_MenuState = new cMenuState( m_WindowWidth, m_WindowHeight );

	m_GameState->Initialize();
	m_MenuState->Initialize();
}
void cEngine::Update()
{
	m_GameState->Update();
	m_MenuState->Update();
}
void cEngine::Render( sf::RenderWindow* _Window )
{
	m_GameState->Render( _Window );
	m_MenuState->Render( _Window );
}

cEngine::cEngine( std::string _Title, int _WindowWidth, int _WindowHeight, int _WindowPositionX, int _WindowPositionY ) :
	m_Title( _Title ), 
	m_WindowWidth(_WindowWidth),         m_WindowHeight(_WindowHeight), 
	m_WindowPositionX(_WindowPositionX), m_WindowPositionY(_WindowPositionY)
{

}


cEngine::~cEngine(void)
{
}
