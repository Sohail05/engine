#include "Engine.h"

void Engine::Initialize()
{
	// State Manager to be created

	m_GameState = new GameState( m_WindowWidth, m_WindowHeight );
	m_MenuState = new MenuState( m_WindowWidth, m_WindowHeight );

	m_GameState->Initialize();
	m_MenuState->Initialize();

	m_StateManager = new StateManager();

	m_StateManager->AddState( "Game", *m_GameState );
	m_StateManager->AddState( "Menu", *m_MenuState );

	m_CurrentState = static_cast<GameState*> ( m_StateManager->GetState( "Game" ) );
}

int removeThisInt = 0;
bool removeThisBool = true;

void Engine::Update()
{
	if( removeThisInt < 500 )
		removeThisInt++;
	else
	{
		if( removeThisBool ) 
		{
			removeThisBool = false;
			m_CurrentState = static_cast<MenuState*> ( m_StateManager->GetState( "Menu" ) );
		}
		else
		{
			removeThisBool = true;
			m_CurrentState = static_cast<GameState*> ( m_StateManager->GetState( "Game" ) );
		}
		removeThisInt = 0;
	}

	m_CurrentState->Update();
}
void Engine::Render( sf::RenderWindow* _Window )
{
	m_CurrentState->Render( _Window );
}

void Engine::Release() {
	delete m_StateManager;
	delete m_GameState;
	delete m_MenuState;
	delete this;
}

Engine::Engine( std::string _Title, int _WindowWidth, int _WindowHeight, int _WindowPositionX, int _WindowPositionY ) :
	m_Title( _Title ), 
	m_WindowWidth(_WindowWidth),         m_WindowHeight(_WindowHeight), 
	m_WindowPositionX(_WindowPositionX), m_WindowPositionY(_WindowPositionY)
{

}

Engine::~Engine(void)
{
}
