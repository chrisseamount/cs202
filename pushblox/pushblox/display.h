#pragma once

#include<SFML/Graphics.hpp>

/*
Display is just a display throughout the game. It uses one window so that the game can switch between states. 
Every object is drawn to the screen everytime something has been changed.
*/

namespace Display
{
	void init();
	void clear();
	void display();
	void draw(const sf::Drawable& drawable);

	bool isOpen();
	void checkWindowEvents();

	const int HEIGHT = 600;
	const int WIDTH = 800;
}