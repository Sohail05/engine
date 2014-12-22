#include "MenuState.h"

void MenuState::initialize() 
{
	for( int i = 0; i < 4; i++ ) {
		m_recShape[i].setSize(sf::Vector2f( 400, 100 ));
		m_recShape[i].setPosition(100, (float) i * 120);
		m_recShape[i].setFillColor(sf::Color::Blue);
	}
}

void MenuState::update()
{

}

void MenuState::render(sf::RenderWindow* renderWindow) 
{
	for(int i = 0; i < 4; i++) 
		renderWindow->draw(m_recShape[i]);
}

MenuState::MenuState( int screenWidth, int screenHeight ) :
	State( screenWidth, screenHeight )
{
}

MenuState::~MenuState(void)
{
}
