#pragma once

#include<SFML/Graphics.hpp>

namespace Display
{
	void init();
	void clear(sf::Color color);
	void display();
	void draw(const sf::Drawable& drawable);

	bool isOpen();
	void checkWindowEvents();
	
	void setView(int centerX, int centerY, int sizeX, int sizeY);
	void changeView(float w, float h);

	void closeWindow();

	const int HEIGHT = 720;
	const int WIDTH = 1280;
}