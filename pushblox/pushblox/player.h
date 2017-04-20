#pragma once

#include "entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	void update();
	void input(sf::Time& dt);
	void draw();
	void loadTexture();
private:
	float _movementSpeed = 1;
	int _counterWalking = 0;
	int _spritePosition = 32;
	sf::Texture playerOne;
};