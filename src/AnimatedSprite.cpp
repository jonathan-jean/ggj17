//
// Created by tonell_m on 22/01/17.
//

#include <Constants.hh>
#include "AnimatedSprite.hh"

AnimatedSprite::AnimatedSprite(sf::Texture *spriteSheet, int frames, std::vector<CollideBox *> colliders)
		: Sprite(new sf::Sprite(*spriteSheet, sf::IntRect(0, 0, CHARACTER_WIDTH, CHARACTER_HEIGHT))),
		  _frames(frames), _currentFrame(0)
{
	_colliders = colliders;
}

AnimatedSprite::~AnimatedSprite()
{
}

int AnimatedSprite::getFrames() const
{
	return _frames;
}

void AnimatedSprite::setFrames(int _frames)
{
	AnimatedSprite::_frames = _frames;
}

int AnimatedSprite::getCurrentFrame() const
{
	return _currentFrame;
}

void AnimatedSprite::setCurrentFrame(int _currentFrame)
{
	AnimatedSprite::_currentFrame = _currentFrame;
}

const sf::Texture &AnimatedSprite::getSpriteSheet() const
{
	return _spriteSheet;
}

void AnimatedSprite::setSpriteSheet(const sf::Texture &_spriteSheet)
{
	AnimatedSprite::_spriteSheet = _spriteSheet;
}


void AnimatedSprite::next()
{
	_currentFrame++;
	if (_currentFrame == _frames)
		_currentFrame = 0;
	if (_sprite)
		delete _sprite;
	_sprite = new sf::Sprite(_spriteSheet, sf::IntRect(_currentFrame * TILE_WIDTH, _currentFrame * TILE_HEIGHT, CHARACTER_WIDTH, CHARACTER_HEIGHT));
}