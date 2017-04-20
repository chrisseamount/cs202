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

	
	void setView();
	void changeView(float w, float h);

	const int HEIGHT = 600;
	const int WIDTH = 800;
}