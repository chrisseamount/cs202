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

		void input();
		void update(double dt);
		void draw();
		void loadFont();
		void createMainMenuTexts();
	private:
		sf::RectangleShape rectangle;

		sf::Font font;
		//creating text objects
		sf::Text localGameText;
		sf::Text networkGameText;
		sf::Text settingsText;
		sf::Text aboutText;

	};
}
