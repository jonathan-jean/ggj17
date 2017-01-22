//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_CHARACTER_HH
#define GGJ17_CHARACTER_HH

#include <SFML/System.hpp>
#include "Spell.hh"
#include "AnimatedSprite.hh"
#include "PhysicsEngine.hh"
#include <Box2D/Box2D.h>

typedef enum {
	LEFT,
	RIGHT,
	UP
} Direction;

class           Character
{
  private:
	sf::Vector2f        _pos;
	std::map<SpriteType, AnimatedSprite> _sprites;

public:
	b2Body              *body;

  public:
	Spell               *push;
	Spell               *pull;

  public:
	Character(int, int, PhysicsEngine*);
	~Character();

  public:
	const sf::Vector2f &getPos() const;
	void setPos(const sf::Vector2f &_pos);

  public:
	sf::Sprite *animate(SpriteType anim, bool update = false);
	void            move(Direction) const;
};

#endif //GGJ17_CHARACTER_HH
