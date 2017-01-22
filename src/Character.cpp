//
// Created by tonell_m on 22/01/17.
//

#include <Constants.hh>
#include "Character.hh"

Character::Character() : _pos(sf::Vector2f(PLAYER_START_X, PLAYER_START_Y))
{
	//TODO: init sprites and colliders
}

Character::~Character()
{

}



const sf::Vector2f &Character::getPos() const
{
	return _pos;
}

void Character::setPos(const sf::Vector2f &_pos)
{
	this->_pos = _pos;
}

sf::Sprite *Character::animate(SpriteType anim, bool update)
{
	if (update)
	{
		_sprites.at(anim).next();
	}
	return _sprites.at(anim).getSprite();
}


