#include "MainMenuState.h"


namespace State
{
	MainMenuState::MainMenuState(Game& game) : GameState(game)
	{
		rectangle.setSize(sf::Vector2f(300, 200));
		rectangle.setPosition(400, 200);
		rectangle.setFillColor(sf::Color::Blue);
	}

	//This gets keyboard input
	void MainMenuState::input()
	{
	}

	//This updates the window for the objects
	void MainMenuState::update(double dt)
	{

	}

	//This draws to the screen
	void MainMenuState::draw()
	{
		
	}
}