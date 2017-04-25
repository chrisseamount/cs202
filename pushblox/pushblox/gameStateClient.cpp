#include "gameStateClient.h"
#include "PausedState.h"
#include "game.h"
#include <memory>

namespace State
{
	GameStateClient::GameStateClient(Game& game) : GameState(game)
	{
		playerOne.loadTexture();
		client();
		//_thread = std::make_unique<sf::Thread>(&syncStatus);
		//_thread->launch();
	}

	//This gets keyboard input
	void GameStateClient::input()
	{
		playerOne.keyboardInput();

		std::cout << "Enter a message to send" << std::endl;
		std::cin >> _askUser;

		_globalMutex.lock();
		_msgSend = _askUser;
		_globalMutex.unlock();
	}

	//This updates the window for the objects
	void GameStateClient::update(double dt)
	{
		playerOne.updateSpritePosition();
	}

	//This draws to the screen
	void GameStateClient::draw()
	{
		playerOne.drawToWindow();
	}

	//This is a server function. It lets clients connect to the game, when before the game starts
	void GameStateClient::client()
	{
		if (_socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
		{
			std::cout << "Connected." << std::endl;
		}
	}

	void GameStateClient::syncStatus()
	{
		//This locks a message into packetsend
		_globalMutex.lock();
		_packetSend << _msgSend;
		_globalMutex.unlock();

		//This sends a packet to the Client
		_socket.send(_packetSend);

		//This recieves any packets recieved from a socket
		_socket.receive(_packetReceive);

		if (_packetReceive >> _msgReceive)
		{
			if (_oldMsg != _msgReceive)
			{
				if (!_msgReceive.empty())
				{
					std::cout << _msgReceive << std::endl;
					_oldMsg = _msgReceive;
				}
			}
		}
	}
}
