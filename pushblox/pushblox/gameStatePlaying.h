#pragma once

#include "gameState.h"
#include "player.h"
#include "background.h"
#include <memory>

namespace State
{
	class GameStatePlaying : public GameState
	{
	public:
		GameStatePlaying(Game& game);
		~GameStatePlaying();
		
		void input(sf::Time& dt);
		void update(double dt);
		void draw();
	private:
		Player player;
		Background background;
	};
}