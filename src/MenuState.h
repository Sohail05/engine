#pragma once

#include "State.h"

class MenuState : public State
{
public:

	void Initialize() {}
	void Update() {}
	void Render( sf::RenderWindow *_window );

	MenuState( int _ScreenWidth, int _ScreenHeight );
	~MenuState(void);
};

