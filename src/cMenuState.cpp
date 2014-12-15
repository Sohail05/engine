#include "cMenuState.h"

void cMenuState::Render( sf::RenderWindow *_window ) {
		
	sf::CircleShape CS( 20.f, 60 );
	CS.setFillColor( sf::Color::Green );

	for( int y = 0; y < 20; y++ ) 
	{
		for( int x = 0; x < 20; x++ ) 
		{
			CS.setPosition( 25+ (x * 50), 25+ (y * 50) );
			_window->draw( CS );
		}
	}
}

cMenuState::cMenuState( int _ScreenWidth, int _ScreenHeight ) :
	cState( _ScreenWidth, _ScreenHeight )
{
}


cMenuState::~cMenuState(void)
{
}
