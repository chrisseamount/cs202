#pragma once

#include "gameState.h"
#include "entity.h"
#include <iostream>
#include <memory>

namespace State
{
	class ServerStateMenu : public GameState
	{
	public:
		ServerStateMenu(Game& game);

		void input();
		void update(double dt);
		void draw();

	private:
		sf::RectangleShape rectangle;
	};
}