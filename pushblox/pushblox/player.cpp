#include "player.h"
#include "display.h"


Player::Player()
{
	loadTexture();
	Display::setView();
	rect.setSize(sf::Vector2f(60, 65));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Black);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.scale(2, 2);
}

Player::~Player()
{

}

void Player::update()
{
	sprite.setPosition(rect.getPosition());
}

void Player::input(sf::Time& dt)
{
	_movementSpeed = 500;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -_movementSpeed * dt.asSeconds());
		Display::changeView(0, -_movementSpeed * dt.asSeconds());
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 3, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, _movementSpeed * dt.asSeconds());
		Display::changeView(0, _movementSpeed * dt.asSeconds());
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 0, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-_movementSpeed * dt.asSeconds(), 0);
		Display::changeView(-_movementSpeed * dt.asSeconds(), 0);
		sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 1, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(_movementSpeed * dt.asSeconds(), 0);
		Display::changeView(_movementSpeed * dt.asSeconds(), 0);
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