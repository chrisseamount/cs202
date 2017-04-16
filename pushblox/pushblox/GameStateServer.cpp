#include "gameStateServer.h"
#include "PausedState.h"
#include "game.h"
#include <memory>
#include "display.h"

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

		_globalMutex.lock();
		_msgSend = playerOne.rect.getPosition.x;
		_globalMutex.unlock();
	}

	//This updates the window for the objects
	void GameStateServer::update(double dt)
	{
		syncStatus();
		server();
		playerOne.updateSpritePosition();
	}

	//This draws to the screen
	void GameStateServer::draw()
	{
		playerOne.drawToWindow();
		Display::draw(_rect);
	}

	//This is a server function. It lets clients connect to the game, when before the game starts
	void GameStateServer::server()
	{
		if (!_gameStarted)
		{
			_listener.listen(PORT);
			_listener.accept(_socket);
		}
	}

	void GameStateServer::syncStatus()
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
				playerTwo.rect.setPosition(_msgReceive);
			}
		}
	}
}
