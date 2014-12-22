#pragma once

#include "State.hpp"

class MenuState : public State
{
public:

	void initialize();
	void update();
	void render(sf::RenderWindow* renderWindow);

	MenuState(int screenWidth, int screenHeight);
	~MenuState(void );

private:

	sf::RectangleShape m_recShape[4];
};

