#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<memory>

#include"display.h"
#include"game.h"
#include"MainMenuState.h"

Game::Game()
{
	Display::init();
	pushState(std::make_unique<State::MainMenuState>(*this));
}

void Game::gameLoop()
{
	sf::Clock clock;
	sf::Time dt;
	
	while (Display::isOpen())
	{
		Display::checkWindowEvents();

		Display::clear(sf::Color::Black);

		_states.top()->input(dt);
		_states.top()->update(0.0);
		_states.top()->draw();

		Display::display();

		dt = clock.restart();
		sf::sleep(sf::microseconds(1));
	}
}

void Game::pushState(std::unique_ptr<State::GameState > state)
{
	_states.push(std::move(state));
}

void Game::popState()
{
	_states.pop();
}

void Game::changeState(std::unique_ptr<State::GameState > state)
{
	popState();
	pushState(std::move(state));
}