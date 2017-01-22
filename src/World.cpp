//
// Created by tonell_m on 21/01/17.
//

#include <PhysicsEngine.hh>
#include <Parser.hh>
#include "World.hh"

World::World(const std::string &file, sf::RenderTexture &ren) : _ren(ren), _parser(file, _engine), _engine(0, 0.1)
{
	try
	{
		_sprites = _parser.parseSprites();
		_map = _parser.parseMap();

		ren.create(_map.at(0).size() * TILE_WIDTH, _map.size() * TILE_HEIGHT);
	}
	catch (...)
	{
		std::cerr << "Error while parsing !" << std::endl;
	}
}

World::~World()
{

}



const std::vector<std::vector<Tile *>>& World::map() const
{
	return _map;
}

sf::RenderTexture const &World::getRenderTexture() const
{
	return _ren;
}

void                            World::draw()
{
	std::vector<std::vector<Tile *> >::iterator iterator;
	for (iterator = _map.begin(); iterator != _map.end(); ++iterator)
	{
		std::vector<Tile *>::iterator lineIterator;
		for (lineIterator = iterator->begin(); lineIterator != iterator->end(); ++lineIterator)
		{
			if ((*lineIterator)->getSprite())
			{
				sf::Sprite sprite = *(*lineIterator)->getSprite()->getSprite();
				sprite.setPosition((*lineIterator)->getPos());
				_ren.draw(sprite);
			}
		}
	}
}

const std::vector<Sprite *> &World::getSprites() const {
	return _sprites;
}
