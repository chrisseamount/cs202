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
		
		//Objects used for the Client side
		Player _playerOne;
		Player _playerTwo;
		sf::RectangleShape _rect;
		
		//Used for objects and functions
		int _counterWalking;
		char _position;
		bool _gameStopped = true;

		//Used to send packets to another person
		unsigned short int _playerOneX;
		unsigned short int _playerOneY;
		unsigned short int _playerDirection;

		//Used to turn packets into integers
		unsigned short int _playerOneXR;
		unsigned short int _playerOneYR;
		unsigned short int _playerDirectionR;

		bool _playerIsRunningR;

		//Used for networking
		const unsigned short PORT = 5042;
		const std::string IPADDRESS = "172.22.25.79";

		//Networking Objects. Important.
		sf::TcpSocket _socket;		//Used to send packets of data
		sf::Mutex _globalMutex;		//Used to protect data
		sf::TcpListener _listener;	//Used to listen to incoming clients
		std::unique_ptr<sf::Thread> _threadClient= 0; //Used to create a thread that will send and check updates
		sf::Packet _packetSend;		//This sends data to one another
		sf::Packet _packetReceive;  //This recieves any incoming packets
	};
}