#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Game
{
public:
	void start();
	
private:
	enum GameState { Uninitialized, Loading, Menu, Playing, Exiting };
	void gameLoop();
	bool isExiting();
	GameState _gameState = Uninitialized;
	sf::RenderWindow _mainWindow;
};