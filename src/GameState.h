#pragma once

#include "State.h"
#include "Map.h"

class GameState : public State
{
public:

	GameState( int ScreenWidth, int ScreenHeight );
	~GameState( void );

	void Initialize();
	void Update();
	void Render( sf::RenderWindow* window );
	
private:
	Map* m_Map;
};

