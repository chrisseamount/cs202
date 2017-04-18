#include "gameState.h"

namespace State
{
	GameState::GameState(Game& game) : _game (&game)
	{}

	void GameState::loadFont()
	{
		if (!_font.loadFromFile("Trench.ttf"))
		{}
	}
}