#pragma once

#include "gameState.h"
#include "player.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <memory>
#include <string>
#include <sstream>

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

		//Objects used to for the server side
		Player _playerOne;
		Player _playerTwo;
		sf::RectangleShape _rect;
		sf::Text _text2;
		
		//Used for objects and functions
		int _counterWalking =0;
		bool _gameStarted = false;

		//Used to send packets to another person
		unsigned short int _playerOneX;
		unsigned short int _playerOneY;
		unsigned short int _playerDirection;

		//Used to turn packets into integers
		unsigned short int _playerOneXR;
		unsigned short int _playerOneYR;
		unsigned short int _playerDirectionR;
		int _playerOldDirection;

		//Used for Networking
		const unsigned short PORT = 5042;
		const std::string IPADDRESS = "172.22.25.61";

		//Networking objects. Important.
		sf::TcpSocket _socket;		//Used to send packets of data
		sf::Mutex _globalMutex;		//Used to protect data
		sf::TcpListener _listener;	//Used to listen to incoming clients
		std::unique_ptr<sf::Thread> _threadListener; //Used to create a thread that will send and check updates
		sf::Packet _packetSend;		//This sends data to one another
		sf::Packet _packetReceive;  //This recieves any incoming packets
	};
}