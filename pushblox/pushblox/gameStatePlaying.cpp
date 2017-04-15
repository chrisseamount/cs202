#include "gameStatePlaying.h"
#include "PausedState.h"
#include "game.h"

namespace State
{
	GameStatePlaying::GameStatePlaying(Game& game) : GameState(game)
	{
		playerOne.loadTexture();
		playerTwo.loadTexture();
		playerTwo.rect.setPosition(sf::Vector2f(400, 100));

	}
	//This gets keyboard input
	void GameStatePlaying::input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			_game->pushState(std::make_unique<State::PausedState>(*_game));
		}
		playerOne.keyboardInput();
		playerTwo.keyboardInput2();
	}

	//This updates the window for the objects
	void GameStatePlaying::update(double dt)
	{
		playerOne.updateSpritePosition();
		playerTwo.updateSpritePosition();
		if (playerOne.rect.getGlobalBounds().intersects(playerTwo.rect.getGlobalBounds()))
		{
			switch (playerOne._direction)
			{
			case 1:	playerOne.rect.move(0, playerOne._movementSpeed);
				break;
			case 2: playerOne.rect.move(0, -playerOne._movementSpeed);
				break;
			case 3: playerOne.rect.move(playerOne._movementSpeed, 0);
				break;
			case 4: playerOne.rect.move(-playerOne._movementSpeed,0);
				break;
			}
			playerOne._direction = 0;
		}
		if (playerTwo.rect.getGlobalBounds().intersects(playerOne.rect.getGlobalBounds()))
		{
			switch (playerTwo._direction)
			{
			case 1:	playerTwo.rect.move(0, playerTwo._movementSpeed);
				break;
			case 2: playerTwo.rect.move(0, -playerTwo._movementSpeed);
				break;
			case 3: playerTwo.rect.move(playerTwo._movementSpeed, 0);
				break;
			case 4: playerTwo.rect.move(-playerTwo._movementSpeed, 0);
				break;
			}
			playerTwo._direction = 0;
		}

	}
	//This draws to the screen
	void GameStatePlaying::draw()
	{
		playerOne.drawToWindow();
		playerTwo.drawToWindow();
	}
}
