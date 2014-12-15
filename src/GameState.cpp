#include "GameState.h"

void GameState::Render( sf::RenderWindow *_window ) {
		
	sf::CircleShape CS( 20.f, 60 );
	CS.setFillColor( sf::Color::Black );

	for( float y = 0; y < 20; y++ ) 
	{
		for( float x = 0; x < 20; x++ ) 
		{
			CS.setPosition( x * 50, y * 50 );
			_window->draw( CS );
		}
	}
}

GameState::GameState( int _ScreenWidth, int _ScreenHeight ) :
	State( _ScreenWidth, _ScreenHeight )
{
}


GameState::~GameState(void)
{
}
