#include "MainMenuState.h"
#include "ServerMenu.h"
#include "game.h"
#include "PausedState.h"
#include "display.h"

#include <memory>

//Functions

namespace State
{
	ServerStateMenu::ServerStateMenu(Game& game) : GameState(game)
	{

	}

	//This gets keyboard input
	void ServerStateMenu::input()
	{

	}

	//This updates the window for the objects
	void ServerStateMenu::update(double dt)
	{
		Display::clear(sf::Color::White);
	}

	//This draws to the screen
	void ServerStateMenu::draw()
	{
	}
}