//
// Created by tonell_m on 22/01/17.
//

#include <Constants.hh>
#include "Character.hh"

Character::Character() : _pos(sf::Vector2f(PLAYER_START_X, PLAYER_START_Y))
{

}

Character::~Character()
{

}



const sf::Vector2f &Character::get_pos() const
{
	return _pos;
}

void Character::set_pos(const sf::Vector2f &_pos)
{
	this->_pos = _pos;
}



