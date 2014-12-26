#pragma once

#include "State.hpp"
#include "Map.hpp"
#include "InputSystem.hpp"
#include "DrawableActor.hpp"

class GameState : public State
{
public:
	GameState(int screenWidth, int screenHeight);
	~GameState(void);

	void initialize(); 
	void update();
	void render(sf::RenderWindow* renderWindow);
	
private:
	Map* m_map;
	InputSystem   m_inputSystem;
	DrawableActor m_drawableActor;
	int  m_mapWidth;
	int  m_mapHeight;
};

