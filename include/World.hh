//
// Created by tonell_m on 21/01/17.
//

#ifndef GGJ17_WORLD_HH
#define GGJ17_WORLD_HH

#include <vector>
#include "Tile.hh"
#include "PhysicsEngine.hh"
#include "Parser.hh"

class           World
{
	sf::RenderTexture                   &_ren;
	std::vector<std::vector<Tile *>>    _map;
	std::vector<Sprite *>               _sprites;
	Parser                              _parser;
	int                                 height;
	int                                 width;

  public:
	PhysicsEngine                       engine;
	World(const std::string &file, sf::RenderTexture &ren);
	~World();

  public:
	const std::vector<std::vector<Tile *>> &map() const;
	const sf::RenderTexture                &getRenderTexture() const;
	const std::vector<Sprite *> &getSprites() const;

  public:
	void draw();
	void scroll(sf::Vector2f &, sf::Vector2f &, int);

};

#endif //GGJ17_WORLD_HH
