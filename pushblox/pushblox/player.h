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
	sf::Texture playerTexture;
private:
	int _movementSpeed = 5;
	int _counterWalking = 0;
	int _spritePosition = 32;
};