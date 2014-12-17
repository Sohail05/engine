#pragma once

#include "State.h"

class GameState : public State
{
public:

	void Initialize() {}
	void Update() {}
	void Render( sf::RenderWindow *_window );

	GameState( int _ScreenWidth, int _ScreenHeight );
	~GameState( void );
};

