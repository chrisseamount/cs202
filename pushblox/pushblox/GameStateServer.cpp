#include "gameStateServer.h"

namespace State
{
	GameStateServer::GameStateServer(Game& game) : GameState(game)
	{
		playerOne.loadTexture();
		//_thread = std::make_unique<sf::Thread>(&syncStatus);
		//_thread->launch();
	}

	//This gets keyboard input
	void GameStateServer::input()
	{
		playerOne.keyboardInput();

		std::cout << "Enter a message to send" << std::endl;
		std::cin >> _askUser;

		_globalMutex.lock();
		_msgSend = _askUser;
		_globalMutex.unlock();
	}

	//This updates the window for the objects
	void GameStateServer::update(double dt)
	{
		server();
		playerOne.updateSpritePosition();
	}

	//This draws to the screen
	void GameStateServer::draw()
	{
		playerOne.drawToWindow();
	}

	//This is a server function. It lets clients connect to the game, when before the game starts
	void GameStateServer::server()
	{
		if (!_gameStarted)
		{
			_listener.listen(PORT);
			_listener.accept(_socket);
			std::cout << "New client connected " << _socket.getRemoteAddress() << std::endl;
		}
	}

	void GameStateServer::syncStatus()
	{
		std::cout << "IT WORKED?" << std::endl;
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
