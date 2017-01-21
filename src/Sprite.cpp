//
// Created by tonell_m on 21/01/17.
//

#include "Sprite.hh"

Sprite::Sprite(SDL_Texture *tex, std::vector<b2Body> const &colliders)
		: _tex(tex), _colliders(colliders) {}

Sprite::Sprite(Sprite const &cpy)
		: _tex(cpy._tex), _colliders(cpy._colliders) {}

Sprite::~Sprite()
{
	if (_tex)
		delete _tex;
}

Sprite&             Sprite::operator=(Sprite const &sp)
{
	if (this != &sp)
	{
		this->_tex = sp._tex;
		this->_colliders = sp._colliders;
	}
	return *this;
}


SDL_Texture*        Sprite::getTexture() const
{
	return _tex;
}

const std::vector<b2Body>& Sprite::getColliders() const
{
	return _colliders;
}
