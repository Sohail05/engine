#pragma once

#include "Unit.hpp"

Unit::Unit()
{

}

Unit::~Unit(void)
{

}

void Unit::moveTo( float x, float y )
{
	this->m_position.x = x;
	this->m_position.y = y;
}