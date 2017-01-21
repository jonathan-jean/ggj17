//
// Created by jean_j on 21.01.17.
//

#include <sstream>
#include "Parser.hh"

Parser::Parser(const std::string &filename, PhysicsEngine &physics)
	: file(rapidxml::file<>(filename.c_str())), physicsEngine(physics){
	try
	{
		rapidxml::xml_document<> doc;
		doc.parse<0>(file.data());
		root_node = doc.first_node("map");
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error was: " << e.what() << std::endl;
	}
	catch (const rapidxml::parse_error& e)
	{
		std::cerr << "Parse error was: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error was: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unknown error occurred." << std::endl;
	}
}

Parser::~Parser() {
}

std::vector<Sprite *> Parser::parseSprites() {
	int                     width, height, i, j;
	rapidxml::xml_node<>    *tileset_node = root_node->first_node("tileset");
	rapidxml::xml_node<>    *image_node = tileset_node->first_node("image");
	sf::Texture             tileset;
	sf::Sprite              *newSprite;

	if (!tileset.loadFromFile(image_node->first_attribute("source")->value()))
		throw(std::runtime_error("Error: cannot load " + std::string(image_node->first_attribute("source")->value())));
	width = (atoi(image_node->first_attribute("width")->value()) / atoi(tileset_node->first_attribute("tilewidth")->value()));
	height = (atoi(image_node->first_attribute("height")->value()) / atoi(tileset_node->first_attribute("tileheight")->value()));
	i = 0;

	sprites.push_back(NULL);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			newSprite = new sf::Sprite();
			newSprite->setTexture(tileset);
			newSprite->setTextureRect(sf::IntRect(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT));
			sprites.push_back(new Sprite(newSprite));
			j++;
		}
		i++;
	}

	for(rapidxml::xml_node<> * tile_node = tileset_node->first_node("tile"); tile_node; tile_node = tile_node->next_sibling())
	{
		int id = atoi(tile_node->first_attribute("id")->value());
		id += 1;
		rapidxml::xml_node<> *obj = tile_node->first_node("objectgroup")->first_node("object");
		sprites[id]->addCollider(new CollideBox(
				Pos(atoi(obj->first_attribute("x")->value()), atoi(obj->first_attribute("y")->value())),
                atoi(obj->first_attribute("width")->value()),
                atoi(obj->first_attribute("height")->value()),
				obj->first_attribute("rotation") ? atoi(obj->first_attribute("rotation")->value()) : 0
		));
	}

	return (sprites);
}

std::vector<std::string> Parser::split(const std::string &s, char delim) {
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> tokens;
	while (std::getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

std::vector<std::vector<Tile *>>    Parser::parseMap()
{
	rapidxml::xml_node<>        *layer_node = root_node->first_node("layer");
	rapidxml::xml_node<>        *data_node = layer_node->first_node("data");
	int                         width = atoi(layer_node->first_attribute("width")->value());
	int                         height = atoi(layer_node->first_attribute("height")->value());
	std::vector<std::string>    data = split(std::string((data_node->value())), ',');
	int                         i = 0;
	int                         j;
	Sprite                      *tmpSprite;

	tiles.resize((unsigned long) height);

	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			int id = atoi(data[i * width + j].c_str());
			tmpSprite = sprites[id];
			tiles[i].push_back(new Tile(Pos(j * TILE_WIDTH, i * TILE_HEIGHT), tmpSprite));
			if (id)
			{
				for (std::vector<CollideBox *>::const_iterator it = tmpSprite->getColliders().begin();
				     it != tmpSprite->getColliders().end(); ++it)
					physicsEngine.createRectangle((*it)->getPos().x, (*it)->getPos().y, (*it)->getWidth(),
					                              (*it)->getHeight(), false);
			}
			j++;
		}
		i++;
	}
	return (tiles);
}