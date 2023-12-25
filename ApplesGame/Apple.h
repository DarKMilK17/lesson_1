#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{
	struct Apple //создаЄт структуру объедин€ющую в себе позицию и спрайт?
	{
		Position position;
		sf::Sprite sprite;
	};

	void InitApple(Apple& apple, const sf::Texture& texture); //описан в apple.cpp
	void DrawApple(Apple& apple, sf::RenderWindow& window); //описан в apple.cpp
}
