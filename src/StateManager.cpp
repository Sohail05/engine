#include "StateManager.h"

void StateManager::AddState( std::string _Name, State &_State ) {
	m_StateMap[_Name] = &_State;
}

State* StateManager::GetState( std::string _Name ) {
	return m_StateMap[_Name];
} 
	
StateManager::StateManager( void ) 
{
		
}
StateManager::~StateManager(void)
{
}

