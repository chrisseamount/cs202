#include "gameStateClient.h"
#include "PausedState.h"
#include "game.h"
#include "display.h"
#include <memory>

namespace State
{
	GameStateClient::GameStateClient(Game& game) : GameState(game)
	{
		_playerOne.loadTexture();
		_playerTwo.loadTexture();
		_playerOne.rect.setPosition(400, 200);
		_playerTwo.rect.setPosition(400, 100);
		
		_threadClient = std::make_unique<sf::Thread>(&GameStateClient::client, this);
		_threadClient->launch();

		_rect.setSize(sf::Vector2f(10, 10));
		_rect.setFillColor(sf::Color::Blue);
	}
	//This gets keyboard input
	void GameStateClient::input()
	{
		_playerOne.keyboardInput();
	}

	//This updates the window for the objects
	void GameStateClient::update(double dt)
	{
		_playerOne.updateSpritePosition();
		_playerTwo.updateSpritePosition();	
	}

	//This draws to the screen
	void GameStateClient::draw()
	{
		_playerOne.drawToWindow();
		_playerTwo.drawToWindow();
		Display::draw(_rect);
		syncStatus(); //Networking function to send packets of data
	}

	//This is a server function. It lets clients connect to the game, when before the game starts
	void GameStateClient::client()
	{
		_socket.connect(IPADDRESS, PORT);
	}

	void GameStateClient::syncStatus(void)
	{
		//This gets the local player's position and sends it to the other players
		_globalMutex.lock();
		_playerOneX = (int)_playerOne.rect.getPosition().x;
		_playerOneY = (int)_playerOne.rect.getPosition().y;
		_playerDirection = (int)_playerOne.getDirection();
		_globalMutex.unlock();

		//This locks a message into a packet
		_globalMutex.lock();
		_packetSend << _playerOneX << _playerOneY << _playerDirection;
		_globalMutex.unlock();

		//This sends all the packets that are put 
		_socket.send(_packetSend);

		//This recieves any packets recieved from a socket
		_socket.receive(_packetReceive);

		/*
		Not working at the moment. The player is currently running on a side
		*/
		if (_packetReceive >> _playerOneXR >> _playerOneYR >> _playerDirectionR)
		{
			if (_playerDirectionR = 1)
			{
				_playerTwo.sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 3, 32, 32));
			}
			if (_playerDirectionR = 2)
			{
				_playerTwo.sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 0, 32, 32));
			}
			if (_playerDirectionR = 3)
			{
				_playerTwo.sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 1, 32, 32));
			}
			if (_playerDirectionR = 4)
			{
				_playerTwo.sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 2, 32, 32));
			}
			_counterWalking++;
			if (_counterWalking == 3)
			{
				_counterWalking = 0;
			}
			_playerTwo.rect.setPosition(_playerOneXR, _playerOneYR); //This may cause an issue. I'll look for a better way to set the position without screwing up
		}
		_packetSend.clear();
	}
}
