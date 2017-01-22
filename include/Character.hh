//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_CHARACTER_HH
#define GGJ17_CHARACTER_HH

#include <SFML/System.hpp>
#include "Spell.hh"
#include "AnimatedSprite.hh"

class           Character
{
  private:
	sf::Vector2f        _pos;
	std::map<SpriteType, AnimatedSprite> _sprites;

  public:
	Spell               *push;
	Spell               *pull;

  public:
	Character();
	~Character();

  public:
	const sf::Vector2f &getPos() const;
	void setPos(const sf::Vector2f &_pos);

  public:
	sf::Sprite *animate(SpriteType anim, bool update = false);
};

#endif //GGJ17_CHARACTER_HH
