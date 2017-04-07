#include <iostream>
#include <SFML/Network.hpp>

using std::string;

//Ports and a main IP Address for the application
const unsigned short PORT = 5042;
const string IPADDRESS("12.0.0.1");

sf::TcpSocket tcpsocket;
sf::Mutex globalMutex;
bool quit = false;

/*
This checks for the following:
 - Collision detection
 - Gets info from the clients

Once finished:
 - This will update the game state for each client using updateGameState()
*/
void checkPlayersAxis()
{
	
}
void updateGameState()
{

}


