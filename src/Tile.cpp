//
// Created by tonell_m on 21/01/17.
//

#include "Tile.hh"

Tile::Tile(Pos const pos, Sprite *sprite) : _pos(pos), _sprite(sprite)
{

}

Tile::Tile(Tile const &cpy) : _pos(cpy._pos), _sprite(cpy._sprite)
{

}

Tile::~Tile()
{

}

Tile&           Tile::operator=(Tile const &t)
{
	if (this != &t)
	{
		this->_pos = t._pos;
		this->_sprite = t._sprite;
	}
	return *this;
}



Pos             Tile::getPos() const
{
	return _pos;
}

void            Tile::setPos(Pos const pos)
{
	_pos = pos;
}

Sprite const    *Tile::getSprite() const
{
	return _sprite;
}

void            Tile::setSprite(Sprite *sprite)
{
	_sprite = sprite;
}