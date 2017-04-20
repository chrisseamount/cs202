#pragma once

#include "entity.h"

class Background : public Entity
{
public:
	Background();
	~Background();
	void draw();
private:
	sf::CircleShape outerCircle;
	sf::CircleShape middleCircle;
	sf::CircleShape innerCircle;
	sf::RectangleShape bridge1;
	sf::RectangleShape bridge2;
	sf::RectangleShape bridge3;
	sf::RectangleShape bridge4;
};