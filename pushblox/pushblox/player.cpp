#include "player.h"
#include "display.h"

Player::Player()
{
	rect.setSize(sf::Vector2f(60, 65));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Black);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.scale(2, 2);
}

void Player::update()
{
	sprite.setPosition(rect.getPosition());
}

void Player::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, _movementSpeed);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 3, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, _movementSpeed);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 0, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(_movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 1, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(_movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 2, 32, 32));
	}

	_counterWalking++;
	if (_counterWalking == 2)
	{
		_counterWalking = 0;
	}
}

void Player::loadTexture()
{
	if (!playerOne.loadFromFile("Finally.png"))
	{
		return;
	}

	sprite.setTexture(playerOne);

}

void Player::draw()
{
	Display::draw(sprite);
}