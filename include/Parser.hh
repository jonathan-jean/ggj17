//
// Created by jean_j on 21.01.17.
//

#ifndef GGJ17_PARSER_HH
#define GGJ17_PARSER_HH

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <rapidxml_utils.hpp>
#include <rapidxml.hpp>
#include "CollideBox.hh"
#include <SFML/Graphics.hpp>
#include "Sprite.hh"
#include "Constants.hh"
#include "Tile.hh"
#include "PhysicsEngine.hh"

class Parser {
	PhysicsEngine                       &physicsEngine;
	rapidxml::file<>                    file;
	rapidxml::xml_document<>            doc;
	std::vector<Sprite *>               sprites;
	std::vector<std::vector<Tile *>>    tiles;
	rapidxml::xml_node<>                *root_node;

public:
	Parser(const std::string &, PhysicsEngine &);

	std::vector<Sprite *> parseSprites();

	virtual ~Parser();

	std::vector<std::vector<Tile *>> parseMap();

	std::vector<std::string> split(const std::string &s, char delim);

	bool isDynamic(int id);
};


#endif //GGJ17_PARSER_HH
