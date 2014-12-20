#pragma once

#include "IState.h"
#include "Map.h"

class GameState : public IState
{
public:

	GameState( int ScreenWidth, int ScreenHeight );
	~GameState( void );

	void VInitialize(); 
	void VUpdate();
	void VRender( sf::RenderWindow* window );
	
private:
	Map* m_Map;
	int m_MapWidth;
	int m_MapHeight;
};

