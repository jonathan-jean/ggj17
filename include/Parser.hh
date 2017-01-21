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
#include <SFML/Graphics.hpp>
#include "Sprite.hh"
#include "Constants.hh"
#include "Tile.hh"
#include "PhysicsEngine.hh"

class Parser {
	PhysicsEngine               &physicsEngine;
	rapidxml::file<>            file;
	rapidxml::xml_document<>    doc;
	rapidxml::xml_node<>        *root_node;

public:
	Parser(const std::string &, PhysicsEngine &);

	std::vector<Sprite *> parseSprites();

	virtual ~Parser();

	std::vector<std::vector<Tile *>> parseMap();
};


#endif //GGJ17_PARSER_HH
