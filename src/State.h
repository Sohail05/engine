#pragma once
#include <SFML/Graphics.hpp>

class State
{

public:

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render( sf::RenderWindow* _window ) = 0;

	State( int _ScreenWidth, int _ScreenHeight );
	virtual ~State(void);

protected:

	int m_ScreenWidth;
	int m_ScreenHeight;

private:


};

