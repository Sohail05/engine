#include "MenuState.h"

void MenuState::VInitialize() 
{
	for( int i = 0; i < 4; i++ ) {
		m_RecShape[i].setSize( sf::Vector2f( 400, 100 ) );
		m_RecShape[i].setPosition( 100, (float) i * 120 );
		m_RecShape[i].setFillColor( sf::Color::Blue );
	}
}

void MenuState::VUpdate()
{

}

void MenuState::VRender( sf::RenderWindow *_window ) 
{
	for( int i = 0; i < 4; i++ ) 
		_window->draw( 	m_RecShape[i] );
}

MenuState::MenuState( int _ScreenWidth, int _ScreenHeight ) :
	IState( _ScreenWidth, _ScreenHeight )
{
}

MenuState::~MenuState(void)
{
}
