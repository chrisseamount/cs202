#pragma once

#include "entity.h"
#include "player.h"

class Background
{
public:
	Background();
	~Background();

	bool checkCollisions(Player&);
	bool isSafe(Player&);

	void draw();
private:
	sf::RectangleShape collisionSquare;
	sf::RectangleShape innerCollisionSquare;
	sf::RectangleShape outerSquare;
	sf::RectangleShape middleSquare;
	sf::RectangleShape innerSquare;
	sf::RectangleShape bridge1;
	sf::RectangleShape bridge2;
	sf::RectangleShape bridge3;
	sf::RectangleShape bridge4;
};