#pragma once

#include "gameState.h"
#include "entity.h"
#include <iostream>
#include <memory>

namespace State
{
	class MainMenuState : public GameState
	{
	public:
		MainMenuState(Game& game);

		void input(sf::Time dt);
		void update(double dt);
		void draw();
		sf::Texture _mainMenuTexture;
	private:
		
		sf::Sprite mainMenuBackground;
		sf::RectangleShape menuBorderRect;
		sf::RectangleShape menuRect;
		sf::Text hostGameText;
		sf::Text clientGameText;
		sf::Text settingsText;
		sf::Text aboutText;
	};
}