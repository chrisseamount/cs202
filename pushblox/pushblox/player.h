#pragma once

#include "entity.h"

class Player : public Entity
{
public:
	Player();
	//Player(int);
	void updateSpritePosition();
	void keyboardInput();
	void keyboardInput2();
	void drawToWindow();
	void loadTexture();
	sf::Texture playerTexture;
	int _movementSpeed = 5;
	int _direction = 0; //1 - UP, 2 - Down, 3 - Left, 4 - Right
private:
	int _counterWalking = 0;
	int _spritePosition = 32;
};