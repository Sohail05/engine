#pragma once

#include "cState.h"

class cGameState : cState
{
public:

	void Initialize() {}
	void Update() {}
	void Render( sf::RenderWindow *_window );

	cGameState( int _ScreenWidth, int _ScreenHeight );
	~cGameState(void);
};

