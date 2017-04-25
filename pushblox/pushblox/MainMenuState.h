#pragma once

#include "gameState.h"
#include "entity.h"
#include <iostream>
#include <memory>

namespace State
{
	class MainMenuState : public GameState
	{
	public:
		MainMenuState(Game& game);

		void input(sf::Time dt);
		void update(double dt);
		void draw();

	private:
		sf::RectangleShape rectangle;
	};
}