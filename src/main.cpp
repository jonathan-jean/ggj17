#include <SFML/Graphics.hpp>
#include "Constants.hh"
#include <iostream>
#include <World.hh>

int main() {
	PhysicsEngine physicsEngine(0, 9.8);
	Parser parser("resources/test_map.tmx", physicsEngine);

	parser.parseSprites();
	parser.parseMap();
	// create the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "My window");

	sf::RenderTexture renderTexture;
	renderTexture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

	World world = World("inputFile", renderTexture);
	sf::Sprite globalSprite;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		world.draw();
		globalSprite.setTexture(world.getRenderTexture().getTexture());
		window.draw(globalSprite);

		// end the current frame
		window.display();
	}
}