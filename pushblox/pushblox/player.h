#pragma once

#include "entity.h"

class Player : public Entity
{
public:
	Player();
	void update();
	void input();
	void draw();
	void loadTexture();
private:
	int _movementSpeed = 1;
	int _counterWalking = 0;
	int _spritePosition = 32;
	sf::Texture playerOne;
};