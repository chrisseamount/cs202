#include "gameState.h"
#include "display.h"

namespace State
{
	GameState::GameState(Game& game) : _game (&game)
	{}

	void GameState::loadFont()
	{
		if (!_font.loadFromFile("Trench.ttf"))
		{}
	}
	void GameState::checkCollisionsOfPlayers(Player& playerOne, Player& playerTwo,sf::Time dt)
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
			//playerOne._movementSpeed = 500;
			
			
			//playerTwo._movementSpeed = 500;
			if (playerTwo._playerState == 2)//if Playertwo has knockback ability
			{
				if (playerTwo._xDirection == 1)//Playertwo: Moving Right
				{
					playerOne.rect.move(playerOne._movementSpeed * dt.asSeconds(), 0); //Knockback PlayerOne Right 
					Display::changeView(playerOne._movementSpeed * dt.asSeconds(), 0);
					playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY );
					Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
					//playerTwo.rect.setPosition(2900, 100);

					//playerOne.sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
					//playerOne.startPos = 96;
					//playerTwo.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
					//playerTwo.startPos = 0;
				}
				if (playerTwo._xDirection == -1)// Playertwo: Moving Left
				{
					playerOne.rect.move(-playerOne._movementSpeed * dt.asSeconds(), 0); //Knockback PlayerOne Left
					Display::changeView(-playerOne._movementSpeed * dt.asSeconds(), 0);
					playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
					Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
					
				}
			}else{
				//x-axis
				if (playerOne._xDirection == 1)//Moving Right
				{
					playerOne.rect.move(-playerOne._movementSpeed * dt.asSeconds(), 0);
					Display::changeView(-playerOne._movementSpeed * dt.asSeconds(), 0);
					playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
					Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
				}
				if (playerOne._xDirection == -1)//Moving Left
				{
					playerOne.rect.move(playerOne._movementSpeed * dt.asSeconds(), 0);
					Display::changeView(playerOne._movementSpeed * dt.asSeconds(), 0);
					playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
					Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
				}

				//y-axis
				if (playerOne._yDirection == 1)//Moving up
				{
					playerOne.rect.move(0, playerOne._movementSpeed * dt.asSeconds());
					Display::changeView(0, playerOne._movementSpeed * dt.asSeconds());
					playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
					Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
				}
				if (playerOne._yDirection == -1)//Moving down
				{
					playerOne.rect.move(0, -playerOne._movementSpeed * dt.asSeconds());
					Display::changeView(0, -playerOne._movementSpeed * dt.asSeconds());
					playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
					Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
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
				playerTwo.rect.move(-playerTwo._movementSpeed * dt.asSeconds(), 0);
				Display::changeView(-playerTwo._movementSpeed * dt.asSeconds(), 0);
				playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
				Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
			}
			if (playerTwo._xDirection == -1)//Moving Left
			{
				playerTwo.rect.move(playerTwo._movementSpeed * dt.asSeconds(), 0);
				Display::changeView(playerTwo._movementSpeed * dt.asSeconds(), 0);
				playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
				Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
			}

			//y-axis
			if (playerTwo._yDirection == 1)//Moving up
			{
				playerTwo.rect.move(0, playerTwo._movementSpeed * dt.asSeconds());
				Display::changeView(0, playerTwo._movementSpeed * dt.asSeconds());
				playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
				Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
			}
			if (playerTwo._yDirection == -1)//Moving down
			{
				playerTwo.rect.move(0, -playerTwo._movementSpeed * dt.asSeconds());
				Display::changeView(0, -playerTwo._movementSpeed * dt.asSeconds());
				playerOne.rect.setPosition(playerOne.cameraPosX, playerOne.cameraPosY);
				Display::setView(playerOne.cameraPosX, playerOne.cameraPosY, 1920, 1080);
			}
		}
		playerTwo._xDirection = 0;
		playerTwo._yDirection = 0;
	}
}