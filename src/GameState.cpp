#include "GameState.hpp"

const int DEFAULT_MAP_WIDTH  = 16;
const int DEFAULT_MAP_HEIGHT = 11;

void GameState::initialize() 
{
	m_drawableActor.setSize( 32 );
	m_drawableActor.setPosition( 0, 0 );
	m_drawableActor.initialize();

	m_map = new Map(m_mapWidth, m_mapHeight);
	m_map->initialize();
}

void GameState::update() 
{
	Command *command = m_inputSystem.handleInput(&m_drawableActor);
	
	if( command )
		command->execute();

	m_drawableActor.update();
	m_map->update();
}

void GameState::render(sf::RenderWindow* renderWindow) 
{
	m_map->render(renderWindow);
	m_drawableActor.render(renderWindow);
}

GameState::GameState(int screenWidth, int screenHeight) :
	State(screenWidth, screenHeight),
	m_mapWidth(DEFAULT_MAP_WIDTH), m_mapHeight(DEFAULT_MAP_HEIGHT)
{
}

GameState::~GameState(void)
{
}
