#include "StateManager.h"

void StateManager::AddState( std::string _Name, IState &_State ) {
	m_StateMap[_Name] = &_State;
}

IState* StateManager::GetState( std::string _Name ) {
	return m_StateMap[_Name];
} 
	
StateManager::StateManager( void ) 
{
		
}
StateManager::~StateManager(void)
{
}

