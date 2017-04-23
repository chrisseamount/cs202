#include"background.h"
#include"display.h"

Background::Background()
{
	collisionSquare.setFillColor(sf::Color::Green);
	collisionSquare.setPosition(-16, -16);
	collisionSquare.setSize(sf::Vector2f(3032, 3032));
	innerCollisionSquare.setFillColor(sf::Color::Green);
	innerCollisionSquare.setPosition(564,564);
	innerCollisionSquare.setSize(sf::Vector2f(1872,1872));

	outerSquare.setFillColor(sf::Color::White);
	outerSquare.setPosition(0, 0);
	outerSquare.setSize(sf::Vector2f(3000,3000));
	middleSquare.setFillColor(sf::Color::Black);
	middleSquare.setPosition(500, 500);
	middleSquare.setSize(sf::Vector2f(2000,2000));
	innerSquare.setFillColor(sf::Color::White);
	innerSquare.setPosition(1000, 1000);
	innerSquare.setSize(sf::Vector2f(1000,1000));
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
}

Background::~Background()
{

}

bool Background::checkCollisions(Player& playerOne)
{
	if (playerOne.rect.getGlobalBounds().intersects(collisionSquare.getGlobalBounds()))
	{
		if (playerOne.rect.getGlobalBounds().intersects(innerCollisionSquare.getGlobalBounds()) && !isSafe(playerOne))
		{
			return false;
		}
		return true;
	}
	return false;
}

bool Background::isSafe(Player& playerOne)
{
	if (playerOne.rect.getGlobalBounds().intersects(innerSquare.getGlobalBounds())
		|| playerOne.rect.getGlobalBounds().intersects(bridge1.getGlobalBounds())
		|| playerOne.rect.getGlobalBounds().intersects(bridge2.getGlobalBounds())
		|| playerOne.rect.getGlobalBounds().intersects(bridge3.getGlobalBounds())
		|| playerOne.rect.getGlobalBounds().intersects(bridge4.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

void Background::draw()
{
	

	Display::draw(outerSquare);
	Display::draw(middleSquare);
	
	Display::draw(innerSquare);
	
	Display::draw(bridge1);
	Display::draw(bridge2);
	Display::draw(bridge3);
	Display::draw(bridge4);
}