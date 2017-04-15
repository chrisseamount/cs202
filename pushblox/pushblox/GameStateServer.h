#pragma once

#include "gameState.h"
#include "player.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <memory>
#include <string>

namespace State
{
	class GameStateServer : public GameState
	{
	public:
		GameStateServer(Game& game);

		void input();
		void update(double dt);
		void draw();

		//Network functions
		void server();
		void syncStatus();

	private:
		Player playerOne;
		
		std::string _msgSend;
		std::string _msgReceive;
		std::string _oldMsg;
		std::string _askUser;
		bool _gameStarted = true;

		const unsigned short PORT = 5042;
		const std::string IPADDRESS = "127.0.0.1";

		sf::TcpSocket _socket;		//Used to send packets of data
		sf::Mutex _globalMutex;		//Used to protect data
		sf::TcpListener _listener;	//Used to listen to incoming clients
		std::unique_ptr<sf::Thread> _thread; //Used to create a thread that will send and check updates
		sf::Packet _packetSend;		//This sends data to one another
		sf::Packet _packetReceive;  //This recieves any incoming packets
	};
}