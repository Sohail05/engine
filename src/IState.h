#pragma once
#include <SFML/Graphics.hpp>

class IState
{
public:
	IState( int ScreenWidth, int ScreenHeight );
	virtual ~IState( void );

	virtual void VInitialize() = 0;
	virtual void VUpdate()     = 0;
	virtual void VRender( sf::RenderWindow* _window ) = 0;
protected:
	int m_ScreenWidth;
	int m_ScreenHeight;
};

