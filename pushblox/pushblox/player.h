#pragma once

#include "entity.h"

class Player : public Entity
{
public:
	Player();
	void updateSpritePosition();
	void keyboardInput();
	void keyboardInput2();
	void drawToWindow();
	void loadTexture();
	sf::Texture playerTexture;

	int _direction = 0;

private:
	int _movementSpeed = 5;
	int _counterWalking = 0;
	int _spritePosition = 32;
};