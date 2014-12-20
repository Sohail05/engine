#pragma once
#include <SFML/Graphics.hpp>

class IState
{
public:
	IState( int ScreenWidth, int ScreenHeight );
	virtual ~IState( void );

	virtual void Initialize() = 0;
	virtual void Update()     = 0;
	virtual void Render( sf::RenderWindow* _window ) = 0;
protected:
	int m_ScreenWidth;
	int m_ScreenHeight;
};

