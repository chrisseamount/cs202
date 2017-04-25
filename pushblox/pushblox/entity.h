#pragma once

#include<SFML/Graphics.hpp>
/*
Entity is just a parent for all objects within the game. 
*/
class Entity
{
public:
	Entity()
	{}
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
};