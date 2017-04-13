#pragma once

#include "gameState.h"

namespace State
{
	class GameStatePlaying : public GameState
	{
	public:
		GameStatePlaying(Game& game);
		
		void input();
		void update(double dt);
		void draw();
	private:

	};
}