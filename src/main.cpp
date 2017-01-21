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
	world._engine.createRectangle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 64, 64, 0);
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int MouseX = sf::Mouse::getPosition(window).x;
			int MouseY = sf::Mouse::getPosition(window).y;
			world._engine.createRectangle(MouseX, MouseY, 64, 64, 0);
		}

		Tile * tile = new Tile(sf::Vector2f(0, 0), world.getSprites()[7]);
		for (b2Body* BodyIterator = world._engine.world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_dynamicBody)
			{
				sf::Sprite Sprite = *(tile->getSprite()->getSprite());
				Sprite.setOrigin(16.f, 16.f);
				Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				Sprite.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
				Sprite.setOrigin(TILE_WIDTH / 2, TILE_HEIGHT / 2);
				window.draw(Sprite);
			}
			else
			{
				sf::RectangleShape rectangle(sf::Vector2f(64, 64));
				rectangle.setPosition(BodyIterator->GetPosition().x, BodyIterator->GetPosition().y);
				rectangle.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
				window.draw(rectangle);
			}
		}
		world._engine.Step();
		// end the current frame
		window.display();
	}
}