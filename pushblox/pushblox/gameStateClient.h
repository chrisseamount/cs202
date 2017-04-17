#pragma once

#include "gameState.h"
#include "player.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <memory>
#include <String>

namespace State
{
	class GameStateClient : public GameState
	{
	public:
		GameStateClient(Game& game);

		void input();
		void update(double dt);
		void draw();

		//Network functions
		void client();
		void syncStatus();

	private:
		Player _playerOne;
		Player _playerTwo;
		//std::unique_ptr<Player> _playerTwo;
		sf::RectangleShape _rect;

		unsigned short int _msgSend;
		unsigned short int _msgReceive;
		unsigned short int _oldMsg;
		char _position;
		bool _gameStopped = true;

		const unsigned short PORT = 5042;
		const std::string IPADDRESS = "127.0.2.2";

		sf::TcpSocket _socket;		//Used to send packets of data
		sf::Mutex _globalMutex;		//Used to protect data
		sf::TcpListener _listener;	//Used to listen to incoming clients
		std::unique_ptr<sf::Thread> _thread= 0; //Used to create a thread that will send and check updates
		std::unique_ptr<sf::Thread> _thread2 = 0; //Used to create a thread that will send and check updates
		sf::Packet _packetSend;		//This sends data to one another
		sf::Packet _packetReceive;  //This recieves any incoming packets
	};
}