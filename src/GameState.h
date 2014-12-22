#pragma once

#include "State.h"
#include "Map.h"

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
	int  m_mapWidth;
	int  m_mapHeight;
};

