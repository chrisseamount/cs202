#include "display.h"

#include <memory>

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

namespace Display
{

	std::unique_ptr<sf::RenderWindow> window;

	void init()
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "PushBlox");
	}

	void clear()
	{
		window->clear();
	}

	void display()
	{
		window->display();
	}

	void checkWindowEvents()
	{
		sf::Event e;

		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
		}
	}

	bool isOpen()
	{
		return window->isOpen();
	}



}