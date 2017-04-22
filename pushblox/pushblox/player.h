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
	int _xdirection = 0; //0 - Neutral, 1 - Left, (-1) - Right
	int _ydirection = 0; //0 - Neutral, 1 - Up, (-1) - Down
	int _playerstate = 0;//0 - Neutral, 1 - Speedy, 2- knockback
	//1-up, 2-down, 3-left, 4-right
private:
	int _counterWalking = 0;
	int _spritePosition = 32;
};