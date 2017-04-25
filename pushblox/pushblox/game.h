#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<memory>
#include<stack>

#include"gameState.h"

/*
This is the logic state class. It uses a stack to store which state the game is in. 
It uses the functions to change or pause the game state that it is currently in.
*/

class Game
{
public:
	Game();
	void gameLoop();

	void pushState(std::unique_ptr<State::GameState > state);
	void popState();
	void changeState(std::unique_ptr<State::GameState > state);

private:
	std::stack<std::unique_ptr<State::GameState>> _states;
};