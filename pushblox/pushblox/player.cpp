#include "player.h"
#include "display.h"
#include <iostream>

Player::Player()
{
	rect.setSize(sf::Vector2f(60, 65));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Black);
	
	sprite.setTextureRect(sf::IntRect(32*3, 0, 32, 32));
	sprite.scale(2.0f, 2.0f);
}

//This sets the position of the sprite relative to the rectangle
void Player::updateSpritePosition()
{
	sprite.setPosition(rect.getPosition());
}

void Player::keyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -_movementSpeed);
		sprite.setTextureRect(sf::IntRect((_counterWalking * 32)+(32*3), 32 * 3, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, _movementSpeed);
		sprite.setTextureRect(sf::IntRect((_counterWalking * 32) + (32 * 3), 0, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-_movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect((_counterWalking * 32) + (32 * 3), 32 * 1, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(_movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect((_counterWalking * 32) + (32 * 3), 32 * 2, 32, 32));
	}

	_counterWalking++;
	if (_counterWalking == 3)
	{
		_counterWalking = 0;
	}
}

//playerOne is from a texture object call
void Player::loadTexture()
{
	if (!playerTexture.loadFromFile("Finally.png"))
	{
		std::cout << "DID NOT FIND THE FILE" << std::endl;
	}

	sprite.setTexture(playerTexture);
}

void Player::drawToWindow()
{
	Display::draw(sprite);
}