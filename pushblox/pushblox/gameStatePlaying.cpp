#include "gameStatePlaying.h"
#include "PausedState.h"
#include "game.h"

namespace State
{
	GameStatePlaying::GameStatePlaying(Game& game) : GameState(game)
	{
		playerOne.loadTexture();
	}

	//This gets keyboard input
	void GameStatePlaying::input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			_game->pushState(std::make_unique<State::PausedState>(*_game));
		}
		playerOne.keyboardInput();
	}

	//This updates the window for the objects
	void GameStatePlaying::update(double dt)
	{
		
		playerOne.updateSpritePosition();
	}

	//This draws to the screen
	void GameStatePlaying::draw()
	{
		playerOne.drawToWindow();
	}
}
