//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_SPRITE_HH
#define GGJ17_SPRITE_HH

#include <SFML/Graphics.hpp>
#include <vector>
#include <Box2D/Dynamics/b2Body.h>

class           Sprite
{
  private:
	sf::Sprite              *_sprite;
	std::vector<b2Body>     _colliders;

  public:
	Sprite(sf::Sprite *sprite);
	Sprite(Sprite const &cpy);
	~Sprite();
	Sprite                  &operator=(Sprite const &sp);

  public:
	sf::Sprite                  *getSprite() const;
	const std::vector<b2Body>   &getColliders() const;
	void                        setColliders(std::vector<b2Body> &colliders);
	void                        addCollider(b2Body collider);
};

#endif //GGJ17_SPRITE_HH
