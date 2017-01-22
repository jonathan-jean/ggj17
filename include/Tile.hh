//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_OBJECT_HH
#define GGJ17_OBJECT_HH

#include "Sprite.hh"
#include "Pos.hh"

class           Tile
{
	sf::Vector2f     _pos;
	Sprite const    *_sprite;

  public:
	Tile(sf::Vector2f const pos, Sprite *sprite);
	Tile(Tile const &cpy);
	~Tile();
	Tile            &operator=(Tile const &t);

  public:
	sf::Vector2f     getPos() const;
	void            setPos(sf::Vector2f const pos);
	Sprite const    *getSprite() const;
	void            setSprite(Sprite *);
};

#endif //GGJ17_OBJECT_HH
