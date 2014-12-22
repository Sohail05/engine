#include "InputSystem.hpp"
#include "Unit.hpp"

const float TEMP_MOVE_SPEED = 1.f;

Command* InputSystem::handleInput() {
	
	Unit *unit = new Unit(); // TODO: Pointer or list of current units.

	if( isPressed(m_buttonUp) )
	{
		ActorPosition actorPosition = unit->getPosition();
		float newY = actorPosition.y + TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, actorPosition.x,newY);
	}
	if( isPressed(m_buttonDown) )
	{
		ActorPosition actorPosition = unit->getPosition();
		float newY  = actorPosition.y - TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, actorPosition.x,newY);
	}
	if( isPressed(m_buttonLeft) )
	{
		ActorPosition actorPosition = unit->getPosition();
		float newX = actorPosition.x - TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, newX, actorPosition.y);	
	}
	if( isPressed(m_buttonRight) )
	{
		ActorPosition actorPosition = unit->getPosition();
		float newX = actorPosition.x + TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, newX, actorPosition.y);	
	}
}

// TODO
bool InputSystem::isPressed(Command* command) 
{
	return false;
}