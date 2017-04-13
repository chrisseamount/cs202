#include "gameStatePlaying.h"


namespace State
{
	GameStatePlaying::GameStatePlaying(Game& game) : GameState(game)
	{

	}

	void GameStatePlaying::input()
	{
		player->input();
	}

	void GameStatePlaying::update(double dt)
	{
		player->update();
	}

	void GameStatePlaying::draw()
	{
		player->draw();
	}
}