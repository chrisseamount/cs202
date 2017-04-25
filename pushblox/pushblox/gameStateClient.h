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
		Player playerOne;

		std::string _msgSend;
		std::string _msgReceive;
		std::string _askUser;
		std::string _oldMsg;
		bool _gameStopped = true;

		const unsigned short PORT = 5042;
		const std::string IPADDRESS = "127.0.0.1";

		sf::TcpSocket _socket;		//Used to send packets of data
		sf::Mutex _globalMutex;		//Used to protect data
		sf::TcpListener _listener;	//Used to listen to incoming clients
		std::unique_ptr<sf::Thread> _thread= 0; //Used to create a thread that will send and check updates
		sf::Packet _packetSend;		//This sends data to one another
		sf::Packet _packetReceive;  //This recieves any incoming packets
	};
}