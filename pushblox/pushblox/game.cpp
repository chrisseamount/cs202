#include"game.h"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

#include"playerlogic.h"


void Game::start()
{
	if (_gameState != Uninitialized)
	{
		return;
	}

	
	
	gameLoop();
	

	
}

void Game::exitGame()
{
	_gameState = Game::Exiting;
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
	logic();
}