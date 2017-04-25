#pragma once

#include "gameState.h"
#include "entity.h"
#include <iostream>
#include <memory>

namespace State
{
	class PausedState : public GameState
	{
	public:
		PausedState(Game& game);

		void input();
		void update(double dt);
		void draw();

	private:
		sf::RectangleShape rectangle;
	};
}