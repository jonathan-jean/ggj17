#include <SFML/Graphics.hpp>
#include "Constants.hh"
#include "World.hh"

int main() {
	// create the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_NAME);
	window.setFramerateLimit(60);

	sf::RenderTexture renderTexture;

	World world(MAP_PATH, renderTexture);

	sf::Texture bkgTexture;
	bkgTexture.loadFromFile(BACKGROUND_PATH);
	sf::Sprite bkg;
	bkg.setTexture(bkgTexture);

	sf::Sprite globalSprite;

	sf::Vector2f blitOffset(0, 0);
	sf::Vector2f bkgBlitPos(-50, -500);
	b2Body* player = world.engine.createRectangle(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2, 64, 64, 0);
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
			if (event.key.code == sf::Keyboard::Q)
			{
				b2Vec2 pos = player->GetPosition();
				pos.x -= CHAR_SPEED;
				player->SetTransform(pos, player->GetAngle());
				player->ApplyLinearImpulse(b2Vec2(-0.05, -0.1), player->GetPosition(), true);

				world.scroll(blitOffset, bkgBlitPos, FOREGROUND_SCROLLING);
			}
			if (event.key.code == sf::Keyboard::D)
			{
				b2Vec2 pos = player->GetPosition();
				pos.x += CHAR_SPEED;
				player->SetTransform(pos, player->GetAngle());
				player->ApplyLinearImpulse(b2Vec2(0.05, -0.1), player->GetPosition(), true);

				world.scroll(blitOffset, bkgBlitPos, -FOREGROUND_SCROLLING);
			}
		}

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
				Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y + TILE_HEIGHT);
				Sprite.setRotation(BodyIterator->GetAngle() * 180/b2_pi);
				window.draw(Sprite);
			}
		}
		world.engine.Step();
		// end the current frame
		window.display();
	}
}