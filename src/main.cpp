#include <SFML/Graphics.hpp>
#include "Constants.hh"
#include <iostream>
#include <Parser.hh>

int main() {
	PhysicsEngine physicsEngine(0, 9.8);
	Parser parser("resources/test_map.tmx", physicsEngine);

	parser.parseSprites();
}