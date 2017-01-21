//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_SPRITE_HH
#define GGJ17_SPRITE_HH

#include <SDL2/SDL.h>
#include <vector>
#include <Box2D/Dynamics/b2Body.h>

class           Sprite
{
  private:
	SDL_Texture             *_tex;
	std::vector<b2Body>     _colliders;

  public:
	Sprite(SDL_Texture *tex, std::vector<b2Body> const &colliders);
	Sprite(Sprite const &cpy);
	~Sprite();
	Sprite                  &operator=(Sprite const &sp);

  public:
	SDL_Texture             *getTexture() const;
	const std::vector<b2Body> &getColliders() const;
};

#endif //GGJ17_SPRITE_HH
