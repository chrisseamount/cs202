#include "MainMenuState.h"
#include "game.h"
#include "gameStateClient.h"
#include "display.h"
#include "GameStateClient.h"
#include "GameStateServer.h"

#include <memory>
#include <iostream>
/*
Main Menu state is the main state of the game. It has a hiearchy of MainMenu to 
*/
namespace State
{
	MainMenuState::MainMenuState(Game& game) : GameState(game)
	{
		rectangle.setSize(sf::Vector2f(Display::WIDTH,Display::HEIGHT));
		rectangle.setPosition(0,0);
		rectangle.setFillColor(sf::Color::Green);

		//This is the main menu logo
		loadFont();
		_text.setFont(_font);
		_text.setCharacterSize(60);
		_text.setFillColor(sf::Color::Blue);
		_text.setString("Push Blox");
		_text.setPosition(Display::HEIGHT/2,10);
	}

	//This gets keyboard input
	void MainMenuState::input(sf::Time dt)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			_game->changeState(std::make_unique<State::GameStateServer>(*_game));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			_game->changeState(std::make_unique<State::GameStateClient>(*_game));
		}
	}

	//This updates the window for the objects
	void MainMenuState::update(double dt)
	{
		
	}

	//This draws to the screen
	void MainMenuState::draw()
	{
		//If you want to display more items, call it after a bigger object! These objects are layered.
		Display::draw(rectangle);
		Display::draw(_text);
	}
}