#include "Engine.h"

void Engine::initialize()
{
	m_gameState->initialize();
	//m_MenuState->Initialize();
	
}

void Engine::update()
{
	m_gameState->update();
	//m_MenuState->Update();
}

void Engine::render( sf::RenderWindow* renderWindow )
{
	m_gameState->render(renderWindow);
	//m_MenuState->Render(Window);
}

Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight, int windowPositionX, int windowPositionY) :
	m_windowTitle(windowTitle), 
	m_windowWidth(windowWidth), m_windowHeight(windowHeight), 
	m_windowPositionX(windowPositionX), m_windowPositionY(windowPositionY)
{

}

Engine::~Engine(void)
{
}
