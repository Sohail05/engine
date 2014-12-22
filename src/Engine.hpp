#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "MenuState.hpp"
#include "GameState.hpp"

////////////////////////////////////////////////////////////
/// \brief The Engine class is used to store information about the window, main loop, input etc
///
////////////////////////////////////////////////////////////

class Engine
{
public:
	Engine(std::string windowTitle, int windowWidth, int windowHeight, int windowPositionX, int windowPositionY);
	~Engine(void);

	////////////////////////////////////////////////////////////
	/// \brief Initialize the Engine
	///
	/// This function will initialize the Engine, and all of its subsystems.
	///
	////////////////////////////////////////////////////////////
	void initialize();	                         

	////////////////////////////////////////////////////////////
	/// \brief Update the Engine
	///
	/// This function will Update the Engine, and all of its subsystems.
	///
	////////////////////////////////////////////////////////////
	void update();	                             
	
	////////////////////////////////////////////////////////////
	/// \brief Render the Engine
	///
	/// This function will Render the Engine, and all of its subsystems.
	///
	/// \param sf::RenderWindow
	///
	////////////////////////////////////////////////////////////
	void render(sf::RenderWindow* renderWindow); 
	
	////////////////////////////////////////////////////////////
	/// \brief This function is used to set the Engines GameState
	///
	/// This function takes a GameState and asigns it to the Engine
	///
	/// \param GameState
	///
	////////////////////////////////////////////////////////////
	inline void setGameState(std::unique_ptr<GameState> gameState) { m_gameState = std::move(gameState); } 	

	////////////////////////////////////////////////////////////
	/// \brief This function is used to set the Engines MenuState
	///
	/// This function takes a MenuState and asigns it to the Engine
	///
	/// \param MenuState
	///
	////////////////////////////////////////////////////////////
	inline void setMenuState(std::unique_ptr<MenuState> menuState) { m_menuState = std::move(menuState); } 	

	inline std::string getWindowTitle()     { return m_windowTitle;     } ///< @returns the Title for the Window 
	inline int		   getWindowWidth()     { return m_windowWidth;     } ///< @returns the Width of the Window in pixels 
	inline int         getWindowHeight()    { return m_windowHeight;    } ///< @returns the Height of the Window in pixels 
	inline int         getWindowPositionX() { return m_windowPositionX; } ///< @returns the Position of the Window along the xAxis 
	inline int         getWindowPositionY() { return m_windowPositionY; } ///< @returns the Position of the Window along the yAxis 

private:

	std::string m_windowTitle;	
	int m_windowWidth, m_windowHeight;
	int m_windowPositionX, m_windowPositionY;

	std::unique_ptr<GameState> m_gameState;
	std::unique_ptr<MenuState> m_menuState;	
};

////////////////////////////////////////////////////////////
/// \class Engine
/// \ingroup Main
///
/// This class will hold information needed by the Game, and ways to edit / update / display this information
/// This information will consist of such things as the size and position of the window.
/// This class will also control the Main Rendering / Update Loop and user input.
/// more to come..
///
////////////////////////////////////////////////////////////