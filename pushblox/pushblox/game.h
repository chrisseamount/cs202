#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Game
{
public:
	void start();
	void exitGame();
	bool isExiting();
private:
	enum GameState { Uninitialized, Loading, Menu, Playing, Exiting };
	GameState _gameState = Uninitialized;
	void gameLoop();
	
	
	sf::RenderWindow _mainWindow;
};