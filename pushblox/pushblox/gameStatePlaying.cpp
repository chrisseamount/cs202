#include "gameStatePlaying.h"


namespace State
{
	GameStatePlaying::GameStatePlaying(Game& game) : GameState(game)
	{
		
	}

	//This gets keyboard input
	void GameStatePlaying::input()
	{
		playerOne.keyboardInput();
	}

	//This updates the window for the objects
	void GameStatePlaying::update(double dt)
	{
		playerOne.loadTexture();
		playerOne.updateSpritePosition();
	}

	//This draws to the screen
	void GameStatePlaying::draw()
	{
		playerOne.drawToWindow();
	}
}
