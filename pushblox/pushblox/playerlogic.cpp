#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>

#include "playerlogic.h"
#include "game.h"
//#include <Transformable.hpp>
//#include <SFML/CircleShape.hpp>


void logic()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape triangle(20,3);
	triangle.setFillColor(sf::Color::Red);
	triangle.setPosition(100, 100);
	double xpos = 100;
	double ypos = 100;
	triangle.setRotation(90);

	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);

	/*class Player
	{
	public:
		void move(int x, int y)
		{
			
		}
	private:
		float _xpos;
		float _ypos;
	};*/

	double relmousex;
	double relmousey;

	while (window.isOpen())
	{
		bool clr = false;
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Left)
					{
						triangle.move(-10,0);
						xpos += 10;
					}
					if (event.key.code == sf::Keyboard::Right)
					{
						triangle.move(10, 0);
						xpos -= 10;
					}
					if (event.key.code == sf::Keyboard::Up)
					{
						triangle.move(0, -10);
						ypos += 10;
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						triangle.move(0, 10);
					}
					if (event.key.code == sf::Keyboard::Escape)
					{
						window.close();
						return;
					}
					/*if (event.key.code == (sf::Keyboard::Left)) {
						triangle.move(150 * 0.1 * -1, 0);
					}
					else if (event.key.code == (sf::Keyboard::Right)) {
						triangle.move(150 * 0.1, 0);
					}*/


					break;

				case sf::Event::Closed:
				{
					window.close();
					return;
				}
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}
				
		}

		window.clear();
		window.draw(triangle);
		window.display();
	}

}