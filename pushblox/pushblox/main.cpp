#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		bool clr = false;
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
					{
						clr = !clr;
						//shape.setFillColor(sf::Color::Blue);
					}
					break;

				case sf::Event::Closed:
					window.close();
			}

			if (clr)
			{
				shape.setFillColor(sf::Color::Red);
			}
			else {
				shape.setFillColor(sf::Color::Blue);
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}