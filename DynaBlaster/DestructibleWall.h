#pragma once

#include <SFML/Graphics.hpp>

void DestructibleWallGraphic()
{
	sf::RenderWindow window(sf::VideoMode(512, 256), "DestructibleWall");
	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile("DestructibleWall.jpg"))
		return;
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(100, 100, 100, 100));
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draw the map
		window.clear();
		window.draw(sprite);
		window.display();
	}
}