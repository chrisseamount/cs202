#pragma once

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


class Game;

namespace State
{
	class GameState
	{
	public:
		GameState(Game& game);
		virtual ~GameState();
		
		virtual void input(sf::Time& dt) = 0;
		virtual void update(double dt) = 0;
		virtual void draw() = 0;

	protected:
		Game* _game;
	};
}