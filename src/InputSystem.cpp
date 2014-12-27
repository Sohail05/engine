#include "InputSystem.hpp"
#include "Unit.hpp"

const float TEMP_MOVE_SPEED = 1.f;

Command* InputSystem::handleInput(Unit *unit) 
{	
	if(isPressed(sf::Keyboard::Key::S))
	{
		ActorPosition actorPosition = unit->getPosition();
		float newY = actorPosition.y + TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, actorPosition.x,newY);
	}
	else if(isPressed(sf::Keyboard::Key::W))
	{
		ActorPosition actorPosition = unit->getPosition();
		float newY  = actorPosition.y - TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, actorPosition.x,newY);
	}
	else if(isPressed(sf::Keyboard::Key::A))
	{
		ActorPosition actorPosition = unit->getPosition();
		float newX = actorPosition.x - TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, newX, actorPosition.y);	
	}
	else if(isPressed(sf::Keyboard::Key::D))
	{
		ActorPosition actorPosition = unit->getPosition();
		float newX = actorPosition.x + TEMP_MOVE_SPEED;
		return new MoveUnitCommand(unit, newX, actorPosition.y);	
	}
	else
	{
		return nullptr;
	}
}

// TODO
bool InputSystem::isPressed(sf::Keyboard::Key key) 
{
	if( sf::Keyboard::isKeyPressed(key) )
		return true;
	else
		return false;
}