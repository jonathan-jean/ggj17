//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_CHARACTER_HH
#define GGJ17_CHARACTER_HH

#include <SFML/System.hpp>
#include "Spell.hh"

class           Character
{
  private:
	sf::Vector2f        _pos;

  public:
	Spell               *push;
	Spell               *pull;

  public:
	Character();
	~Character();

  public:
	const sf::Vector2f &get_pos() const;

	void set_pos(const sf::Vector2f &_pos);
};

#endif //GGJ17_CHARACTER_HH
