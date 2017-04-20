#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include<memory>
#include<stack>

#include"gameState.h"

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
	sf::Texture backgroundTex;
	sf::Sprite background;
};