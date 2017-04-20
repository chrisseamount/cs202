#include"background.h"
#include"display.h"

Background::Background()
{
	outerCircle.setFillColor(sf::Color::Red);
	outerCircle.setPosition(0, 0);
	outerCircle.setRadius(1500);
	innerCircle.setFillColor(sf::Color::White);
	innerCircle.setPosition(500, 500);
	innerCircle.setRadius(1000);
	middleCircle.setFillColor(sf::Color::Green);
	middleCircle.setPosition(1000, 1000);
	middleCircle.setRadius(500);
	bridge1.setFillColor(sf::Color::Red);
	bridge1.setPosition(400, 200);
	bridge2.setFillColor(sf::Color::Red);
	bridge2.setPosition(400, 200);
	bridge3.setFillColor(sf::Color::Red);
	bridge3.setPosition(400, 200);
	bridge4.setFillColor(sf::Color::Red);
	bridge4.setPosition(400, 200);
}

Background::~Background()
{

}


void Background::draw()
{
	Display::draw(outerCircle);
	Display::draw(innerCircle);
	Display::draw(middleCircle);
	
	Display::draw(bridge1);
	Display::draw(bridge2);
	Display::draw(bridge3);
	Display::draw(bridge4);
}