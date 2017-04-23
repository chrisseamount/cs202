#include "gameStatePlaying.h"
#include "display.h"

namespace State
{
	GameStatePlaying::GameStatePlaying(Game& game) : GameState(game)
	{
		
	}

	void GameStatePlaying::input(sf::Time& dt)
	{
		player.input(dt);

		
	}

	void GameStatePlaying::update(double dt)
	{
		player.update();
	}

	void GameStatePlaying::draw()
	{
		background.draw();
		player.draw();

		if (!background.checkCollisions(player))
		{
			Display::clear();
		}
	}
}