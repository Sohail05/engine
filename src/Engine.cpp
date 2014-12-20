#include "Engine.h"

void Engine::Initialize()
{
	m_GameState->VInitialize();
	//m_MenuState->Initialize();
	
}

void Engine::Update()
{
	m_GameState->VUpdate();
	//m_MenuState->Update();
}

void Engine::Render( sf::RenderWindow* Window )
{
	m_GameState->VRender( Window );
	//m_MenuState->Render( _Window );
}

void Engine::Release() 
{
	//delete m_StateManager;
	//delete m_GameState;
	//delete m_MenuState;
}

Engine::Engine( std::string Title, int WindowWidth, int WindowHeight, int WindowPositionX, int WindowPositionY ) :
	m_Title( Title ), 
	m_WindowWidth(WindowWidth),         m_WindowHeight(WindowHeight), 
	m_WindowPositionX(WindowPositionX), m_WindowPositionY(WindowPositionY)
{

}

Engine::~Engine(void)
{
}
