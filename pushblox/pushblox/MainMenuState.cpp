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

		if (_mainMenuTexture.loadFromFile("white-brick-wall.jpg"))
		{
			mainMenuBackground.setTexture(_mainMenuTexture); //Sprite
			//mainMenuBackground.setPosition(/*sf::Vector2f(0,0)*/);
			//mainMenuBackground.setScale(/*sf::Vector2f(100, 100)*/);
			//mainMenuBackground.setColor(/*sf::Color(0, 255, 0)*/);
		}


		//This is the main menu logo
		loadFont();
		_text.setFont(_font);
		_text.setCharacterSize(60);
		_text.setFillColor(sf::Color::Blue);
		_text.setString("Push Blox");
		_text.setPosition(Display::HEIGHT/2,10);

		//rectangle
		menuBorderRect.setSize(sf::Vector2f(315, 175));
		menuBorderRect.setFillColor(sf::Color::Black);
		menuBorderRect.setPosition(Display::HEIGHT / 2 - 15, 20);

		menuRect.setSize(sf::Vector2f(305, 165));
		menuRect.setFillColor(sf::Color::White);
		menuRect.setPosition(Display::HEIGHT/2 - 10, 25);

		//texts
		hostGameText.setFont(_font);
		hostGameText.setCharacterSize(24);
		hostGameText.setFillColor(sf::Color::Black);
		hostGameText.setString("Host a Game - Press 'H'");
		hostGameText.setPosition(Display::HEIGHT / 2, 80);

		clientGameText.setFont(_font);
		clientGameText.setCharacterSize(24);
		clientGameText.setFillColor(sf::Color::Black);
		clientGameText.setString("Connect to a Game - Press 'C'");
		clientGameText.setPosition(Display::HEIGHT / 2, 105);

		settingsText.setFont(_font);
		settingsText.setCharacterSize(24);
		settingsText.setFillColor(sf::Color::Black);
		settingsText.setString("Settings - Press 'S'");
		settingsText.setPosition(Display::HEIGHT / 2,130);

		aboutText.setFont(_font);
		aboutText.setCharacterSize(24);
		aboutText.setFillColor(sf::Color::Black);
		aboutText.setString("About - Press 'A'");
		aboutText.setPosition(Display::HEIGHT / 2, 155);
	}

	//This gets keyboard input
	void MainMenuState::input()
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
		Display::draw(mainMenuBackground);
		Display::draw(menuBorderRect);
		Display::draw(menuRect);
		Display::draw(_text);
		Display::draw(hostGameText);
		Display::draw(clientGameText);
		Display::draw(settingsText);
		Display::draw(aboutText);

	}
}