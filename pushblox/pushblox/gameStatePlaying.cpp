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

		//Checks Player collision
		/*if (playerOne.rect.getGlobalBounds().intersects(playerTwo.rect.getGlobalBounds()))
		{
			switch (playerOne._direction)
			{
			case 1:	playerOne.rect.move(0, playerOne._movementSpeed); up
				break;
			case 2: playerOne.rect.move(0, -playerOne._movementSpeed); down 
				break;
			case 3: playerOne.rect.move(playerOne._movementSpeed, 0); left
				break;
			case 4: playerOne.rect.move(-playerOne._movementSpeed,0); right
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
		}*/
		if (playerOne.rect.getGlobalBounds().intersects(playerTwo.rect.getGlobalBounds()))
		{

			if (playerTwo._playerstate == 2)//if Playertwo has knockback ability
			{
				if (playerTwo._xdirection == 1)//Playertwo: Moving Right
				{
					playerOne.rect.move(playerOne._movementSpeed, 0); //Knockback PlayerOne Right 
				}
				if (playerTwo._xdirection == -1)// Playertwo: Moving Left
				{
					playerOne.rect.move(-playerOne._movementSpeed, 0); //Knockback PlayerOne Left
				}
			} else {
				if (playerOne._xdirection == 1)//Moving Right
				{
					playerOne.rect.move(-playerOne._movementSpeed, 0);
				}
				if (playerOne._xdirection == -1)//Moving Left
				{
					playerOne.rect.move(playerOne._movementSpeed, 0);
				}

				playerOne._xdirection = 0;
				playerOne._ydirection = 0;
			}
		}
		if (playerTwo.rect.getGlobalBounds().intersects(playerOne.rect.getGlobalBounds()))
		{
			if (playerTwo._xdirection == 1)//Moving Right
			{
				playerTwo.rect.move(-playerTwo._movementSpeed, 0);
			}
			if (playerTwo._xdirection == -1)//Moving Left
			{
				playerTwo.rect.move(playerTwo._movementSpeed, 0);
			}
			
			playerTwo._xdirection = 0;
			playerTwo._ydirection = 0;
		}

	}
	//This draws to the screen
	void GameStatePlaying::draw()
	{
		playerOne.drawToWindow();
		playerTwo.drawToWindow();
	}
}
