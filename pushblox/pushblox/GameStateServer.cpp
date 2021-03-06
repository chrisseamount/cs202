#include "gameStateServer.h"
#include "PausedState.h"
#include "game.h"
#include <memory>
#include "display.h"
#include <iostream>
#include <chrono>
using std::chrono::seconds;
using std::chrono::duration_cast;

namespace State
{
	GameStateServer::GameStateServer( Game& game) : GameState(game)
	{
		//This loads the texture and sets the position of the players onto the screen
		std::cout << "New Server State" << std::endl;
		_playerOne.loadTexture();
		_playerTwo.loadTexture();
		_playerOne.rect.setPosition(100, 100);
		Display::setView(100, 100, 1920, 1080);
		_playerTwo.rect.setPosition(2900, 100);

		_playerOne.sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
		_playerOne.startPos = 96;
		_playerTwo.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		_playerTwo.startPos = 0;

		//This is for the server. It listens for incoming connections
		_threadListener = std::make_unique<sf::Thread>(&GameStateServer::server, this);
		_threadListener->launch();

		//This is if any client connected. It is important
		_rect.setSize(sf::Vector2f(10, 10));
		_rect.setFillColor(sf::Color::Red);

		//This is the main menu logo
		loadFont();
		_text.setFont(_font);
		_text.setCharacterSize(60);
		_text.setFillColor(sf::Color::Blue);
		_text.setPosition(Display::HEIGHT / 2, 10);

		//This is the main menu logo
		_text2.setFont(_font);
		_text2.setCharacterSize(60);
		_text2.setFillColor(sf::Color::Blue);
		_text2.setPosition(300, 400);

		_playerOne.cameraPosX = 100;
		_playerOne.cameraPosY = 100;
		_playerTwo.cameraPosX = 2900;
		_playerTwo.cameraPosY = 100;
	}

	//This gets keyboard input
	void GameStateServer::input(sf::Time dt)
	{
		//t_round = std::chrono::steady_clock::now();
		//if (duration_cast<seconds>(t_round - t_initializer).count() % 10)
		//{
		//	std::cout << "round over" << std::endl;
		//}
		
		checkCollisionsOfPlayers(_playerOne, _playerTwo, dt);

		_playerOne.keyboardInput2(dt);
		syncStatus(); //Networking function to send packets of data

		if (_playerOne._direction == 1)
		{
			_text2.setString("Up");
		}
		if (_playerOne._direction == 2)
		{
			_text2.setString("Down");
		}
		if (_playerOne._direction == 3)
		{
			_text2.setString("Left");
		}
		if (_playerOne._direction == 4)
		{
			_text2.setString("Right");
		}

	}

	//This updates the window for the objects
	void GameStateServer::update(double dt)
	{
		_playerOne.updateSpritePosition();
		_playerTwo.updateSpritePosition();
	}

	//This draws to the screen
	void GameStateServer::draw()
	{
		//Chris's code
		background.draw();
		if (!background.checkCollisions(_playerOne))
		{
			_playerOne.rect.setPosition(100, 100);
			Display::setView(100, 100, 1920, 1080);
		}

		_playerOne.drawToWindow();
		_playerTwo.drawToWindow();
		Display::draw(_rect);
		Display::draw(_text);
		Display::draw(_text2);
		_playerOne._isRunning = 0;
	}

	//This is a server function. It lets clients connect to the game, when before the game starts
	void GameStateServer::server()
	{
		while (!_gameStarted)
		{
			if (_listener.listen(PORT) != sf::Socket::Done)
			{
				std::cout << "Player Connected" << std::endl;
				_rect.setPosition(200, 10);
				_rect.setFillColor(sf::Color::Magenta);
				//t_initializer = std::chrono::steady_clock::now();
			}
			if (_listener.accept(_socket) != sf::Socket::Done)
			{
				_rect.setPosition(400, 400);
			}
		}
	}

	void GameStateServer::syncStatus(void)
	{
		//This gets the local player's position and sends it to the other players
		_globalMutex.lock();
		_playerOneX = _playerOne.rect.getPosition().x;
		_playerOneY = _playerOne.rect.getPosition().y;
		_playerDirection = _playerOne.getDirection();
		_playerIsIt = _playerOne._ifPlayerIsIt;
		_globalMutex.unlock();

		//This locks a message into a packet
		_globalMutex.lock();
		_packetSend << _playerOneX << _playerOneY << _playerDirection << _playerIsIt;
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
			if (_playerDirectionR == 1)
			{
				_playerTwo.sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 3, 32, 32));
			}
			else if (_playerDirectionR == 2)
			{
				_playerTwo.sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 0, 32, 32));
			}
			else if (_playerDirectionR == 3)
			{
				_playerTwo.sprite.setTextureRect(sf::IntRect(_counterWalking * 32, 32 * 1, 32, 32));
			}
			else if (_playerDirectionR == 4)
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
		_packetReceive.clear();
	}
}
