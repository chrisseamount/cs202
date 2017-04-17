#include "gameStateServer.h"
#include "PausedState.h"
#include "game.h"
#include <memory>
#include "display.h"

namespace State
{
	GameStateServer::GameStateServer(Game& game) : GameState(game)
	{
		_playerOne.loadTexture();
		_playerTwo.loadTexture();
		_thread = std::make_unique<sf::Thread>(&GameStateServer::syncStatus, this);
		_thread2 = std::make_unique<sf::Thread>(&GameStateServer::server, this);
		_thread->launch();
		_thread2->launch();

		_rect.setSize(sf::Vector2f(10, 10));
		_rect.setFillColor(sf::Color::Red);
	}

	//This gets keyboard input
	void GameStateServer::input()
	{
		_playerOne.keyboardInput2();
		//syncStatus();
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
		_playerOne.drawToWindow();
		_playerTwo.drawToWindow();
		Display::draw(_rect);
	}

	//This is a server function. It lets clients connect to the game, when before the game starts
	void GameStateServer::server()
	{
		while (!_gameStarted)
		{
			if (_listener.listen(PORT) != sf::Socket::Done)
			{
				_rect.setPosition(200, 10);
				_rect.setFillColor(sf::Color::Magenta);
			}
			if (_listener.accept(_socket) != sf::Socket::Done)
			{
				_rect.setPosition(400, 400);
			}
		}
	}

	void GameStateServer::syncStatus(void)
	{

		_globalMutex.lock();
		_msgSend = _playerOne.rect.getPosition().x;
		_globalMutex.unlock();

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
			_playerTwo.rect.setPosition(_msgReceive, 0);
		}
	}
}
