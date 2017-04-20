#include "display.h"

#include <memory>

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

namespace Display
{

	std::unique_ptr<sf::RenderWindow> window;

	std::unique_ptr<sf::View> view;

	void init()
	{
		sf::ContextSettings settings;
		settings.antialiasingLevel = 16;
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "PushBlox",sf::Style::Default, settings);
		view = std::make_unique<sf::View>(sf::FloatRect(0, 0, 1, 1));
	}

	void clear()
	{
		window->clear();
	}

	void display()
	{
		window->display();
	}

	void draw(const sf::Drawable& drawable)
	{
		window->setView(*view);
		window->draw(drawable);
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

	void setView()
	{
		view->setSize(3200, 2400);
		view->setCenter(432, 268);
	}

	void changeView(float w, float h)
	{
		view->move(w, h);
	}

}