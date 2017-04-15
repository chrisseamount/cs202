#include "MainMenuState.h"
#include "game.h"
#include "gameStateClient.h"
#include "display.h"
#include "GameStateClient.h"
#include "GameStateServer.h"
#include "Sounds.h"

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
	}

	//This gets keyboard input
	void MainMenuState::input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			_game->changeState(std::make_unique<State::GameStateServer>(*_game));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			std::cout << "Went to Client window" << std::endl;
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
		Display::draw(rectangle);
		music.menuMusic();
	}
	/*void MainMenuState::MenuMusic() {
		Sounds::MenuMusic();
	}*/
}