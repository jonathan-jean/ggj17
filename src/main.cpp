#include <SFML/Graphics.hpp>
#include "Constants.hh"
#include "World.hh"

int main() {
	// create the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_NAME);

	sf::RenderTexture renderTexture;
	renderTexture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

	World world(MAP_PATH, renderTexture);
	sf::Sprite globalSprite;
	// run the program as long as the window is open
	sf::Vector2f blitPos(0, 0);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Q)
				blitPos.x -= 5;
			if (event.key.code == sf::Keyboard::D)
				blitPos.x += 5;
			if (event.key.code == sf::Keyboard::Z)
				blitPos.y -= 5;
			if (event.key.code == sf::Keyboard::S)
				blitPos.y += 5;
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		world.draw();
		globalSprite.setTexture(world.getRenderTexture().getTexture());
		globalSprite.setPosition(blitPos);
		window.draw(globalSprite);

		// end the current frame
		window.display();
	}
}