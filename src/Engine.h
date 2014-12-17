#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "StateManager.h"
#include "MenuState.h"
#include "GameState.h"

class Engine
{

public:

	void Initialize();
	void Update();
	void Render( sf::RenderWindow* Window );
	void Release();

	inline std::string GetWindowTitle() { return m_Title; }
	inline int GetWindowWidth() { return m_WindowWidth; }
	inline int GetWindowHeight() { return m_WindowHeight; }
	inline int GetWindowPositionX() { return m_WindowPositionX; }
	inline int GetWindowPositionY() { return m_WindowPositionY; }

	Engine( std::string _Title, int _WindowWidth, int _WindowHeight, int _WindowPositionX, int _WindowPositionY );
	~Engine( void );

private:

	StateManager *m_StateManager;
	State    *m_CurrentState, *m_GameState, *m_MenuState;

	std::string m_Title;	
	int m_WindowWidth, m_WindowHeight;
	int m_WindowPositionX, m_WindowPositionY;
};

