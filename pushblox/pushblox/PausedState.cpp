#include "MainMenuState.h"
#include "game.h"
#include "PausedState.h"
#include "gameStatePlaying.h"
#include "display.h"

#include <memory>

//Functions

namespace State
{
	PausedState::PausedState(Game& game) : GameState(game)
	{
		rectangle.setSize(sf::Vector2f(Display::WIDTH, Display::HEIGHT));
		rectangle.setPosition(0, 0);
		rectangle.setFillColor(sf::Color::Blue);
	}

	//This gets keyboard input
	void PausedState::input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_game->popState();
		}
	}

	//This updates the window for the objects
	void PausedState::update(double dt)
	{

	}

	//This draws to the screen
	void PausedState::draw()
	{
		Display::draw(rectangle);
	}
}