#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Game
{
public:
	static void start();
	
private:
	enum GameState { Uninitialized, Loading, Menu, Playing, Exiting };
	static void gameLoop();
	static bool isExiting();
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};