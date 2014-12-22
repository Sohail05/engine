
#include "MoveUnitCommand.hpp"

MoveUnitCommand::MoveUnitCommand( Unit* unit, float x, float y ) : 
		m_unit(unit)
{
	m_position.x = x;
	m_position.y = y;
} 

MoveUnitCommand::~MoveUnitCommand(void)
{

}

void MoveUnitCommand::execute() 
{
	m_unit->moveTo( m_position.x, m_position.y );
}
