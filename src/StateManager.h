#pragma once

#include <iostream>
#include <string>
#include <map>

#include "State.h"

class StateManager
{

public:

	void AddState( std::string _Name, State &_State );

	State *GetState( std::string _Name );
	
	StateManager( );
	~StateManager( void );

private:

	std::map< std::string, State* > m_StateMap;

};

