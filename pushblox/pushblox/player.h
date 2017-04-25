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

	int getDirection() const;
	int getIsRunning() const;

	int _direction = 1;
	int _counterWalking = 0;
	int _isRunning = 0;
	int _movementSpeed = 5;
	
	int _xDirection = 0;
	int _yDirection = 0;
	int _playerState = 0;


private:
	int _spritePosition = 32;
};