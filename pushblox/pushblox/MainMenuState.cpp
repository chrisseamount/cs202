#include "MainMenuState.h"
#include "game.h"
#include "gameStatePlaying.h"
#include "display.h"

#include <memory>

namespace State
{
	MainMenuState::MainMenuState(Game& game) : GameState(game)
	{
		rectangle.setSize(sf::Vector2f(Display::WIDTH,Display::HEIGHT));
		rectangle.setPosition(0,0);
		rectangle.setFillColor(sf::Color::Green);
	}

	//This gets keyboard input
	void MainMenuState::input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			_game->changeState(std::make_unique<State::GameStatePlaying>(*_game));
		}
	}

	//This updates the window for the objects
	void MainMenuState::update(double dt)
	{

	}

	//This draws to the screen
	void MainMenuState::draw()
	{
		Display::draw(rectangle);
	}
}