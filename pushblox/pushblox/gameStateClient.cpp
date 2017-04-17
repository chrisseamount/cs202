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
		//_thread = std::make_unique<sf::Thread>(&GameStateClient::syncStatus, this);
		//_thread2 = std::make_unique<sf::Thread>(&GameStateClient::client, this);
		//_thread->launch();
		//_thread2->launch();

		_rect.setSize(sf::Vector2f(10, 10));
		_rect.setFillColor(sf::Color::Blue);
	}
	//This gets keyboard input
	void GameStateClient::input()
	{
		_playerOne.keyboardInput();

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

	//This updates the window for the objects
	void GameStateClient::update(double dt)
	{
		_playerOne.updateSpritePosition();
		_playerTwo.updateSpritePosition();
		client();
	}

	//This draws to the screen
	void GameStateClient::draw()
	{
		_playerOne.drawToWindow();
		_playerTwo.drawToWindow();
		Display::draw(_rect);
	}

	//This is a server function. It lets clients connect to the game, when before the game starts
	void GameStateClient::client()
	{
		_socket.connect(IPADDRESS, PORT);
	}

	void GameStateClient::syncStatus(void)
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
