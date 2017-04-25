#pragma once

#include "gameState.h"
#include "entity.h"
#include <iostream>
#include <memory>
#include "Sounds.h"

#include "game.h"
#include "gameStateClient.h"
#include "display.h"
#include "GameStateServer.h"

#include <memory>
#include <iostream>

namespace State
{
	class MainMenuState : public GameState
	{
	public:
		MainMenuState(Game& game);

		void input();
		void update(double dt);
		void draw();
	private:
		sf::RectangleShape rectangle;
		Sounds::SoundClass music;
	};
}