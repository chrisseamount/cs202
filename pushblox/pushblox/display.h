#pragma once

#include<SFML/Graphics.hpp>

namespace Display
{
	void init();
	void clear();
	void display();
	void draw(const sf::Drawable& drawable);

	bool isOpen();
	void checkWindowEvents();

	const int WIDTH = 1920;
	const int HEIGHT = 1080;
}