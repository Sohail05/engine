#pragma once

#include "Actor.hpp"
#include <SFML/Graphics.hpp>

class DrawableActor : public Unit
{
public:

	DrawableActor() :
		m_rectangleSize(32.f)
	{
	}

	DrawableActor( float rectangleSize ) :
		m_rectangleSize( rectangleSize )
	{
		this->initialize();
	}

	inline void setSize( float rectangleSize ) { m_rectangleSize = rectangleSize; }

	void initialize()
	{
		m_rectangleShape.setSize(sf::Vector2f(m_rectangleSize,m_rectangleSize));
		m_rectangleShape.setPosition(this->m_position.x,this->m_position.y);
	}

	void render(sf::RenderWindow* renderWindow)
	{
		renderWindow->draw(m_rectangleShape);
	}

	void update()
	{
		m_rectangleShape.setPosition(this->m_position.x,this->m_position.y);	
	}

private:

	sf::RectangleShape m_rectangleShape;
	float m_rectangleSize;

};