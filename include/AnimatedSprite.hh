//
// Created by tonell_m on 22/01/17.
//

#ifndef GGJ17_ANIMATEDSPRITE_HH
#define GGJ17_ANIMATEDSPRITE_HH

#include "Sprite.hh"

const int nbAnimations = 6;

typedef enum    e_SpriteType
{
	IDDLE_LEFT,
	IDDLE_RIGHT,
	WALK_LEFT,
	WALK_RIGHT,
	SPELL_LEFT,
	SPELL_RIGHT
}               SpriteType;

class           AnimatedSprite : public Sprite
{
  public:
	AnimatedSprite(sf::Texture *texture, int frames, std::vector<CollideBox *> colliders);
	~AnimatedSprite();

  public:
	int getFrames() const;
	void setFrames(int _frames);
	int getCurrentFrame() const;
	void setCurrentFrame(int _currentFrame);
	const sf::Texture &getSpriteSheet() const;
	void setSpriteSheet(const sf::Texture &_spriteSheet);

  public:
	void next();

  private:
	int         _frames;
	int         _currentFrame;
	sf::Texture _spriteSheet;
};

#endif //GGJ17_ANIMATEDSPRITE_HH
