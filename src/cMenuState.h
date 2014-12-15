#pragma once

#include "cState.h"

class cMenuState : cState
{
public:

	void Initialize() {}
	void Update() {}
	void Render( sf::RenderWindow *_window );

	cMenuState( int _ScreenWidth, int _ScreenHeight );
	~cMenuState(void);
};

