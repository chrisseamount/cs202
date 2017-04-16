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
	void MainMenuState::loadFont()
	{
		if (!font.loadFromFile("fdsa.ttf"))
		{
			std::cout << "Unable to load font." << std::endl;
		}
		//selecting font
		localGameText.setFont(font);
		networkGameText.setFont(font);
		settingsText.setFont(font);
		aboutText.setFont(font);
	}
	void MainMenuState::createMainMenuTexts()
	{
		//setting text
		localGameText.setString("Play a game: local");
		networkGameText.setString("Play a game: network");
		settingsText.setString("Settings");
		aboutText.setString("About");

		//text size
		localGameText.setCharacterSize(20);
		networkGameText.setCharacterSize(24);
		settingsText.setCharacterSize(24);
		aboutText.setCharacterSize(24);

		//setting text style
		localGameText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		networkGameText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		settingsText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		aboutText.setStyle(sf::Text::Bold | sf::Text::Underlined);

		//setting text position
		localGameText.setPosition(400, 300);
		networkGameText.setPosition(0, 30);
		settingsText.setPosition(0, 60);
		aboutText.setPosition(0, 90);

		//setting text color
		localGameText.setFillColor(sf::Color::Green);
		networkGameText.setFillColor(sf::Color::Green);
		settingsText.setFillColor(sf::Color::Green);
		aboutText.setFillColor(sf::Color::Green);
	}

	MainMenuState::MainMenuState(Game& game) : GameState(game)
	{
		//loadFont();
		font.loadFromFile("fdsa.ttf");
		//selecting font
		localGameText.setFont(font);
		networkGameText.setFont(font);
		settingsText.setFont(font);
		aboutText.setFont(font);

		createMainMenuTexts();

		rectangle.setSize(sf::Vector2f(Display::WIDTH, Display::HEIGHT));
		rectangle.setPosition(0, 0);
		rectangle.setFillColor(sf::Color::Red);		

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
		Display::draw(localGameText);
		Display::draw(networkGameText);
		Display::draw(aboutText);
		Display::draw(settingsText);
		
	}
}