#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "cMenuState.h"
#include "cGameState.h"

class cEngine
{

public:

	void Initialize();
	void Update();
	void Render( sf::RenderWindow* Window );

	std::string GetWindowTitle() { return m_Title; }
	
	int GetWindowWidth() { return m_WindowWidth; }
	int GetWindowHeight() { return m_WindowHeight; }
	int GetWindowPositionX() { return m_WindowPositionX; }
	int GetWindowPositionY() { return m_WindowPositionY; }

	cEngine( std::string _Title, int _WindowWidth, int _WindowHeight, int _WindowPositionX, int _WindowPositionY );
	~cEngine(void);

private:

	cGameState* m_GameState;
	cMenuState* m_MenuState;

	std::string m_Title;	
	int m_WindowWidth, m_WindowHeight;
	int m_WindowPositionX, m_WindowPositionY;
};

