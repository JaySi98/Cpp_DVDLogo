#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Logo.h"

void routine(Logo &logo, sf::RenderWindow &window);

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1280, 800), "DVD screensaver");
	sf::Vector2u window_size = window.getSize();
	sf::Texture texture;
	texture.loadFromFile("DVD.png");
	Logo logo(&texture, window_size, rand()%(window_size.x - texture.getSize().x), rand()%(window_size.y - texture.getSize().y));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		routine(logo, window);
		
		window.clear();
		logo.draw(window);
		window.display();
	}

	return 0;
}

//basically this function is responsible for controlling the logo
void routine(Logo &logo, sf::RenderWindow &window)
{
	//logo is touching horizontal sides of the window
	if (logo.CheckColisionX(window.getSize().x))
	{
		logo.changeColor(rand() % 7);
		//changes the x-axis of the direction so logo can "bounce off" the side
		logo.SetDirection(-logo.getDirection().x, logo.getDirection().y);

	} //logo is touching vertical sides of the window
	if (logo.CheckColisionY(window.getSize().y))
	{
		logo.changeColor(rand() % 7);
		//changes the y-axis of the direction so logo can "bounce off" the side
		logo.SetDirection(logo.getDirection().x , -logo.getDirection().y);
	}
	//move logo by vector direction
	logo.update();
}

