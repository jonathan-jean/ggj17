//
// Created by tonell_m on 21/01/17.
//

#include "Sprite.hh"

Sprite::Sprite(sf::Sprite *sprite) : _sprite(sprite) {}

Sprite::Sprite(Sprite const &cpy) : _sprite(cpy._sprite), _colliders(cpy._colliders) {}

Sprite::~Sprite()
{
	if (_sprite)
		delete _sprite;
}

Sprite&             Sprite::operator=(Sprite const &sp)
{
	if (this != &sp)
	{
		this->_sprite = sp._sprite;
		this->_colliders = sp._colliders;
	}
	return *this;
}


sf::Sprite          *Sprite::getSprite() const
{
	return _sprite;
}

const std::vector<CollideBox *> &Sprite::getColliders() const
{
	return _colliders;
}

void                Sprite::addCollider(CollideBox *collider)
{
	_colliders.push_back(collider);
}