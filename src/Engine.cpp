#include "Engine.h"



void Engine::Initialize()
{
	m_GameState->Initialize();
	m_MenuState->Initialize();
	
	/*
	m_StateManager = new StateManager();

	m_StateManager->AddState( "Game", *m_GameState );
	m_StateManager->AddState( "Menu", *m_MenuState );

	m_CurrentState = static_cast<GameState*> ( m_StateManager->GetState( "Game" ) );
	*/
}

int removeThisInt = 0;
bool removeThisBool = true;

void Engine::Update()
{
	m_GameState->Update();
	m_MenuState->Update();
}

int deleteThisInt = 0;
bool deleteThisBool = false;

void Engine::Render( sf::RenderWindow* _Window )
{
	if( deleteThisInt < 1000 )
	{
		deleteThisInt++;
	}
	else
	{
		if( deleteThisBool ) 
			deleteThisBool = false;
		else
			deleteThisBool = true;
		deleteThisInt = 0;
	}

	if( deleteThisBool )
		m_GameState->Render( _Window );
	else
		m_MenuState->Render( _Window );

}

void Engine::Release() {
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
