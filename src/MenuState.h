#pragma once

#include "IState.h"

class MenuState : public IState
{
public:

	void VInitialize();
	void VUpdate();
	void VRender( sf::RenderWindow *_window );

	MenuState( int _ScreenWidth, int _ScreenHeight );
	~MenuState( void );

private:

	sf::RectangleShape m_RecShape[4];
};

