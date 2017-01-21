#include <SFML/Graphics.hpp>
#include "Constants.hh"
#include <iostream>

int main() {

	// create the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "My window");

	sf::Texture testTexture;
	if (!testTexture.loadFromFile("resources/bmp/square300.bmp"))
	{
		std::cerr << "Something fishy happened" << std::endl;
		return 1;
	}
	testTexture.setSmooth(true);
	sf::Sprite testSprite;
	testSprite.setTexture(testTexture);

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

		testSprite.rotate(6.28 / 60.f);

		// draw everything here...
		window.draw(testSprite);

		// end the current frame
		window.display();
	}
}