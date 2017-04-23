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

	void loadTexture(sf::RectangleShape&,sf::Texture&,char*);

	void draw();
private:
	sf::RectangleShape collisionSquare;
	sf::RectangleShape innerCollisionSquare;
	sf::RectangleShape outerSquare;
	sf::Texture outerSquareTex;
	sf::RectangleShape middleSquare;
	sf::RectangleShape innerSquare;
	sf::Texture innerSquareTex;
	sf::RectangleShape bridge1;
	sf::Texture bridge1Tex;
	sf::RectangleShape bridge2;
	sf::Texture bridge2Tex;
	sf::RectangleShape bridge3;
	sf::Texture bridge3Tex;
	sf::RectangleShape bridge4;
	sf::Texture bridge4Tex;
};