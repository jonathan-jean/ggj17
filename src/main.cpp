#include <SFML/Graphics.hpp>
#include "Constants.hh"
#include "World.hh"

int main() {
	// create the window
	sf::RenderWindow window(sf::VideoMode(20 * TILE_WIDTH, 10 * TILE_HEIGHT), WINDOW_NAME);
	window.setFramerateLimit(60);

	sf::RenderTexture renderTexture;

	World world(MAP_PATH, renderTexture);
	std::cout << renderTexture.getSize().x << " / " << renderTexture.getSize().y << std::endl;

	sf::Texture bkgTexture;
	bkgTexture.loadFromFile(BACKGROUND_PATH);
	sf::Sprite bkg;
	bkg.setTexture(bkgTexture);

	sf::Sprite globalSprite;

	sf::Vector2f blitOffset(0, 0);
	sf::Vector2f bkgBlitPos(-50, -500);

	int scroll;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		scroll = 0;

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Q)
			{
				scroll = 5;
				bkgBlitPos.x += BACKGROUND_SCROLLING;
			}
			if (event.key.code == sf::Keyboard::D)
			{
				scroll = -5;
				bkgBlitPos.x -= BACKGROUND_SCROLLING;
			}
		}

		world.scroll(blitOffset, scroll);
		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		world.draw();
		globalSprite.setTexture(world.getRenderTexture().getTexture());
		globalSprite.setPosition(blitOffset);
		bkg.setPosition(bkgBlitPos);
		window.draw(bkg);
		window.draw(globalSprite);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int MouseX = sf::Mouse::getPosition(window).x;
			int MouseY = sf::Mouse::getPosition(window).y;
			world.engine.createRectangle(MouseX, MouseY, 64, 64, 0);
		}

		Tile * tile = new Tile(sf::Vector2f(0, 0), world.getSprites()[7]);
		for (b2Body* BodyIterator = world.engine.world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_dynamicBody)
			{
				sf::Sprite Sprite = *(tile->getSprite()->getSprite());
				//Sprite.setOrigin(16.f, 16.f);
				Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y + TILE_HEIGHT);
				Sprite.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
				//Sprite.setOrigin(TILE_WIDTH / 2, TILE_HEIGHT / 2);
				window.draw(Sprite);
			}
		}
		world.engine.Step();
		// end the current frame
		window.display();
	}
}