#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <memory>
#include "player.h"

class Game;

/*
GameState is just a parent of all classes that every state can inherit from.
Everything is based off of namespaces, so that the main Game class can use them
to switch between states.

It has an input() function, that is used to check for user input.
It has an update() function, that is used to check the position of the rectangle.
It also has a draw() function, that is used to draw pictures to the screen.
*/

namespace State
{
	class GameState
	{
	public:
		GameState( Game& game);
		
		virtual void input(sf::Time dt) = 0;
		virtual void update(double dt) = 0;
		virtual void draw() = 0;

		void loadFont();
		void checkCollisionsOfPlayers(Player& playerOne, Player& playerTwo,sf::Time);

	protected:
		Game* _game;
		//sf::Texture _mainMenuBackground;
		sf::Text _text;
		sf::Font _font;
	};
}