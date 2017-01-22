//
// Created by tonell_m on 22/01/17.
//

#include <Constants.hh>
#include <PhysicsEngine.hh>
#include "Character.hh"

Character::Character(int x, int y, PhysicsEngine* engine) : _pos(sf::Vector2f(PLAYER_START_X, PLAYER_START_Y))
{
	//TODO: init sprites and colliders
	this->body = engine->createRectangle(x, y, CHARACTER_WIDTH, CHARACTER_HEIGHT, 0);
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

void            Character::move(Direction way) const
{
	if (way == LEFT)
	{
		b2Vec2 pos = this->body->GetPosition();
		pos.x -= CHAR_SPEED;
		this->body->SetTransform(pos, this->body->GetAngle());
		this->body->ApplyLinearImpulse(b2Vec2(-0.05, -0.1), this->body->GetPosition(), true);
	}
	else
	{
		b2Vec2 pos = this->body->GetPosition();
		pos.x += CHAR_SPEED;
		this->body->SetTransform(pos, this->body->GetAngle());
		this->body->ApplyLinearImpulse(b2Vec2(-0.05, -0.1), this->body->GetPosition(), true);
	}
}
