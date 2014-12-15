#include "cGameState.h"

void cGameState::Render( sf::RenderWindow *_window ) {
		
	sf::CircleShape CS( 20.f, 60 );
	CS.setFillColor( sf::Color::Black );

	for( int y = 0; y < 20; y++ ) 
	{
		for( int x = 0; x < 20; x++ ) 
		{
			CS.setPosition( x * 50, y * 50 );
			_window->draw( CS );
		}
	}
}

cGameState::cGameState( int _ScreenWidth, int _ScreenHeight ) :
	cState( _ScreenWidth, _ScreenHeight )
{
}


cGameState::~cGameState(void)
{
}
