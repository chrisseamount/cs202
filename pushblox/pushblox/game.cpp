#include"game.h"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>


void Game::start()
{
	if (_gameState != Uninitialized)
	{
		return;
	}

	_mainWindow.create(sf::VideoMode(200, 200), "PushBlox");
	_gameState = Game::Playing;

	while (!isExiting())
	{
		gameLoop();
	}

	_mainWindow.close();
}

bool Game::isExiting()
{
	if (_gameState == Game::Exiting)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::gameLoop()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (_mainWindow.isOpen())
	{
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_gameState = Game::Exiting;
				return;
			}
		}

		_mainWindow.clear();
		_mainWindow.draw(shape);
		_mainWindow.display();
	}
}