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



const std::vector<std::vector<Tile>>& World::map() const
{
	return _map;
}

sf::RenderTexture const &World::getRenderTexture() const
{
	return _ren;
}

void                            World::draw()
{
	std::vector<std::vector<Tile> >::iterator iterator;
	for (iterator = _map.begin(); iterator != _map.end(); ++iterator)
	{
		std::vector<Tile>::iterator lineIterator;
		for (lineIterator = iterator->begin(); lineIterator != iterator->end(); ++lineIterator)
		{
			_ren.draw(*lineIterator->getSprite()->getSprite());
		}
	}
}