#include"background.h"
#include"display.h"

Background::Background()
{
	collisionSquare.setFillColor(sf::Color::Green);
	collisionSquare.setPosition(-64, -64);
	collisionSquare.setSize(sf::Vector2f(3128, 3128));
	outerSquare.setFillColor(sf::Color::White);
	outerSquare.setPosition(0, 0);
	outerSquare.setSize(sf::Vector2f(3000,3000));
	innerSquare.setFillColor(sf::Color::Black);
	innerSquare.setPosition(500, 500);
	innerSquare.setSize(sf::Vector2f(2000,2000));
	middleSquare.setFillColor(sf::Color::White);
	middleSquare.setPosition(1000, 1000);
	middleSquare.setSize(sf::Vector2f(1000,1000));
	bridge1.setFillColor(sf::Color::Red);
	bridge1.setPosition(450, 1350);
	bridge1.setSize(sf::Vector2f(600,300));
	bridge2.setFillColor(sf::Color::Red);
	bridge2.setPosition(1350, 450);
	bridge2.setSize(sf::Vector2f(300, 600));
	bridge3.setFillColor(sf::Color::Red);
	bridge3.setPosition(1950, 1350);
	bridge3.setSize(sf::Vector2f(600, 300));
	bridge4.setFillColor(sf::Color::Red);
	bridge4.setPosition(1350, 1950); 
	bridge4.setSize(sf::Vector2f(300, 600));

	outerTopCollision.setFillColor(sf::Color::Green);
	outerRightCollision.setFillColor(sf::Color::Green);
	outerBottomCollision.setFillColor(sf::Color::Green);
	outerLeftCollision.setFillColor(sf::Color::Green);
	innerTopLeftTopCollision.setFillColor(sf::Color::Green);
	innerTopLeftSideCollision.setFillColor(sf::Color::Green);
	innerTopRightTopCollision.setFillColor(sf::Color::Green);
	innerTopRightSideCollision.setFillColor(sf::Color::Green);
	innerBottomRightBottomCollision.setFillColor(sf::Color::Green);
	innerBottomRightSideCollision.setFillColor(sf::Color::Green);
	innerBottomLeftBottomCollision.setFillColor(sf::Color::Green);
	innerBottomLeftSideCollision.setFillColor(sf::Color::Green);
}

Background::~Background()
{

}

bool Background::checkCollisions(Player& playerOne)
{
	if (playerOne.rect.getGlobalBounds().intersects(collisionSquare.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

void Background::draw()
{
	Display::draw(collisionSquare);

	Display::draw(outerSquare);
	Display::draw(innerSquare);
	Display::draw(middleSquare);
	
	Display::draw(bridge1);
	Display::draw(bridge2);
	Display::draw(bridge3);
	Display::draw(bridge4);
}