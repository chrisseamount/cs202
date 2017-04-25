#include "player.h"
#include "display.h"
#include <iostream>

Player::Player()
{
	rect.setSize(sf::Vector2f(60, 65));		//We must define the position in the states
	rect.setFillColor(sf::Color::Red);

	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.scale(2.0f, 2.0f);
}
Player::Player(bool _ifIsPlaying)
{
	rect.setSize(sf::Vector2f(60, 65));		//We must define the position in the states
	rect.setFillColor(sf::Color::Red);

	Display::setView(rect.getPosition().x, rect.getPosition().y, 1920, 1080);

	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.scale(2.0f, 2.0f);
}

//This sets the position of the sprite relative to the rectangle
void Player::updateSpritePosition()
{
	sprite.setPosition(rect.getPosition());
}

void Player::keyboardInput(sf::Time dt)
{
	_movementSpeed = 1500;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -_movementSpeed * dt.asSeconds());
		Display::changeView(0, -_movementSpeed * dt.asSeconds());
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 3, 32, 32));
		_yDirection = 1;
		_direction = 1;
		_isRunning = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, _movementSpeed * dt.asSeconds());
		Display::changeView(0, _movementSpeed * dt.asSeconds());
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 0, 32, 32));
		_yDirection = -1;
		_direction = 2;
		_isRunning = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-_movementSpeed * dt.asSeconds(), 0);
		Display::changeView(-_movementSpeed * dt.asSeconds(),0);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 1, 32, 32));
		_xDirection = -1;
		_direction = 3;
		_isRunning = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(_movementSpeed * dt.asSeconds(), 0);
		Display::changeView(_movementSpeed * dt.asSeconds(),0);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 2, 32, 32));
		_xDirection = 1;
		_direction = 4;
		_isRunning = 1;
	}

	_counterWalking++;
	if (_counterWalking == 3)
	{
		_counterWalking = 0;
	}
}
void Player::keyboardInput2(sf::Time dt)
{
	_movementSpeed = 1500;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rect.move(0, -_movementSpeed * dt.asSeconds());
		Display::changeView(0, -_movementSpeed * dt.asSeconds());
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 3, 32, 32));
		_yDirection = 1;
		_direction = 1;
		_isRunning = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rect.move(0, _movementSpeed * dt.asSeconds());
		Display::changeView(0, _movementSpeed * dt.asSeconds());
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 0, 32, 32));
		_yDirection = -1;
		_direction = 2;
		_isRunning = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rect.move(-_movementSpeed * dt.asSeconds(), 0);
		Display::changeView(-_movementSpeed * dt.asSeconds(), 0);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 1, 32, 32));
		_xDirection = -1;
		_direction = 3;
		_isRunning = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rect.move(_movementSpeed * dt.asSeconds(), 0);
		Display::changeView(_movementSpeed * dt.asSeconds(), 0);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 2, 32, 32));
		_xDirection = 1;
		_direction = 4;
		_isRunning = 1;
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

int Player::getDirection() const
{
	return _direction;
}

int Player::getIsRunning() const
{
	return _isRunning;
}