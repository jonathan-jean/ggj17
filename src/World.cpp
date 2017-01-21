//
// Created by tonell_m on 21/01/17.
//

#include "World.hh"

World::World(const std::string &file, sf::RenderTexture &ren) : _ren(ren)
{
	// TODO : Load textures from file with jj's parser.
}

World::~World()
{

}



std::vector<std::vector<Tile>>& World::map()
{
	return _map;
}
