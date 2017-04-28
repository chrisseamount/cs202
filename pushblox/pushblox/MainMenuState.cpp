#include "MainMenuState.h"


namespace State
{
	MainMenuState::MainMenuState(Game& game) : GameState(game)
	{
		_background.setFillColor(sf::Color::White);
		_background.setSize(sf::Vector2f(Display::WIDTH,Display::HEIGHT));
	}

	void MainMenuState::input() //This gets keyboard input
	{
	}

	void MainMenuState::update(double dt) //This updates the window for the objects
	{
	}
	
	void MainMenuState::draw() //This draws to the screen
	{
		Display::draw(_background);
	}
}