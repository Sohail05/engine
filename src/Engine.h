#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "StateManager.h"
#include "MenuState.h"
#include "GameState.h"

/* The Engine class is used to store information about the window, main loop, input etc */
class Engine
{
public:

	Engine( std::string _Title, int _WindowWidth, int _WindowHeight, int _WindowPositionX, int _WindowPositionY );
	~Engine( void );

	/**
	* Main Initialize Loop 
	*/
	void Initialize();
	
	/**
	* Main Update Loop 
	*/
	void Update();
	
	/**
	* Main Render Loop 
	* @param Handle to a Render Window
	*/
	void Render( sf::RenderWindow* Window );
	
	/**
	* Release any memory obtained
	*/
	void Release();
	/**
	* Sets the GameState variable
	* @param unique_pointer to a GameState
	*/
	inline void SetGameState( std::unique_ptr<GameState> GameState ) { m_GameState = std::move( GameState ); }
	/**
	* Sets the MenuState variable
	* @param unique_pointer to a MenuState
	*/

	inline void SetMenuState( std::unique_ptr<MenuState> MenuState ) { m_MenuState = std::move( MenuState ); }
	
	/**
	* @returns the Title for the Window
	*/
	inline std::string Engine::GetWindowTitle()     { return m_Title;           }	
	/**
	* @returns the Width of the Window in pixels
	*/
	inline int		   Engine::GetWindowWidth()     { return m_WindowWidth;     }
	/**
	* @returns the Height of the Window in pixels
	*/
	inline int         Engine::GetWindowHeight()    { return m_WindowHeight;    }  
	/**
	* @returns the Position of the Window along the xAxis
	*/
	inline int         Engine::GetWindowPositionX() { return m_WindowPositionX; }
	/**
	* @returns the Position of the Window along the yAxis
	*/
	inline int         Engine::GetWindowPositionY() { return m_WindowPositionY; }

private:

	std::string m_Title;	
	int m_WindowWidth, m_WindowHeight;
	int m_WindowPositionX, m_WindowPositionY;

	std::unique_ptr<GameState> m_GameState;
	std::unique_ptr<MenuState> m_MenuState;	
};

