#pragma once

#include "entity.h"
#include "player.h"

class Background
{
public:
	Background();
	~Background();

	bool checkCollisions(Player&);

	void draw();
private:
	sf::RectangleShape collisionSquare;
	sf::RectangleShape outerSquare;
	sf::RectangleShape middleSquare;
	sf::RectangleShape innerSquare;
	sf::RectangleShape bridge1;
	sf::RectangleShape bridge2;
	sf::RectangleShape bridge3;
	sf::RectangleShape bridge4;

	sf::RectangleShape outerTopCollision;
	sf::RectangleShape outerRightCollision;
	sf::RectangleShape outerBottomCollision;
	sf::RectangleShape outerLeftCollision;
	sf::RectangleShape innerTopLeftTopCollision;
	sf::RectangleShape innerTopLeftSideCollision;
	sf::RectangleShape innerTopRightTopCollision;
	sf::RectangleShape innerTopRightSideCollision;
	sf::RectangleShape innerBottomRightBottomCollision;
	sf::RectangleShape innerBottomRightSideCollision;
	sf::RectangleShape innerBottomLeftBottomCollision;
	sf::RectangleShape innerBottomLeftSideCollision;
};