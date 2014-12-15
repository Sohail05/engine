#pragma once
#include <SFML/Graphics.hpp>

class cState
{

public:

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render( sf::RenderWindow* _window ) = 0;

	cState( int _ScreenWidth, int _ScreenHeight );
	~cState(void);

protected:

	int m_ScreenWidth;
	int m_ScreenHeight;

private:


};

