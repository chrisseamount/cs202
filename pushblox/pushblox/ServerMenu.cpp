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
		rectangle.setSize(sf::Vector2f(Display::WIDTH, Display::HEIGHT));
		rectangle.setPosition(0, 0);
		rectangle.setFillColor(sf::Color::White);
	}

	//This gets keyboard input
	void ServerStateMenu::input()
	{
	}

	//This updates the window for the objects
	void ServerStateMenu::update(double dt)
	{

	}

	//This draws to the screen
	void ServerStateMenu::draw()
	{
		Display::draw(rectangle);
	}
}