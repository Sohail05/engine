#pragma once

#include <iostream>
#include <string>
#include <map>

#include "IState.h"

class StateManager
{

public:

	void AddState( std::string _Name, IState &_State );

	IState *GetState( std::string _Name );
	
	StateManager( );
	~StateManager( void );

private:

	std::map< std::string, IState* > m_StateMap;

};

