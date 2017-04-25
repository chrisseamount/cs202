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
	void GameState::checkCollisions(Player& playerOne, Player& playerTwo)
	{
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

			if (playerTwo._playerState == 2)//if Playertwo has knockback ability
			{
				if (playerTwo._xDirection == 1)//Playertwo: Moving Right
				{
					playerOne.rect.move(playerOne._movementSpeed, 0); //Knockback PlayerOne Right 
				}
				if (playerTwo._xDirection == -1)// Playertwo: Moving Left
				{
					playerOne.rect.move(-playerOne._movementSpeed, 0); //Knockback PlayerOne Left
				}
			}else{
				//x-axis
				if (playerOne._xDirection == 1)//Moving Right
				{
					playerOne.rect.move(-playerOne._movementSpeed, 0);
				}
				if (playerOne._xDirection == -1)//Moving Left
				{
					playerOne.rect.move(playerOne._movementSpeed, 0);
				}

				//y-axis
				if (playerOne._yDirection == 1)//Moving up
				{
					playerOne.rect.move(0, playerOne._movementSpeed);
				}
				if (playerOne._yDirection == -1)//Moving down
				{
					playerOne.rect.move(0, -playerOne._movementSpeed);
				}


			}
			playerOne._xDirection = 0;
			playerOne._yDirection = 0;
		}
		if (playerTwo.rect.getGlobalBounds().intersects(playerOne.rect.getGlobalBounds()))
		{
			//x-axis
			if (playerTwo._xDirection == 1)//Moving Right
			{
				playerTwo.rect.move(-playerTwo._movementSpeed, 0);
			}
			if (playerTwo._xDirection == -1)//Moving Left
			{
				playerTwo.rect.move(playerTwo._movementSpeed, 0);
			}

			//y-axis
			if (playerTwo._yDirection == 1)//Moving up
			{
				playerTwo.rect.move(0, playerTwo._movementSpeed);
			}
			if (playerTwo._yDirection == -1)//Moving down
			{
				playerTwo.rect.move(0, -playerTwo._movementSpeed);
			}
		}
		playerTwo._xDirection = 0;
		playerTwo._yDirection = 0;
	}
}