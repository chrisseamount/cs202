#pragma once

#include "entity.h"

class Player : public Entity
{
public:
	Player();
	void updateSpritePosition();
	void keyboardInput();
	void drawToWindow();
	void loadTexture();
	sf::Texture playerTexture;

private:
	int _movementSpeed = 5;
	int _counterWalking = 0;
	int _spritePosition = 32;
};