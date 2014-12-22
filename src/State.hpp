#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	State(int screenWidth, int screenHeight);
	virtual ~State(void);

	virtual void initialize() = 0;
	virtual void update()     = 0;
	virtual void render(sf::RenderWindow* renderWindow) = 0;
protected:
	int m_screenWidth;
	int m_screenHeight;
};

