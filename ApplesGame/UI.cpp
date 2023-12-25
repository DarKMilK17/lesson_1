#include "UI.h"
#include "Game.h"
#include <string>

namespace ApplesGame
{
	void InitUI(UIState& uiState, const sf::Font& font) 
	{
		uiState.scoreText.setFont(font); //выбор шрифта, для счёта игрока, изначально желтого цвета
		uiState.scoreText.setCharacterSize(24);
		uiState.scoreText.setFillColor(sf::Color::Yellow);

		uiState.inputHintText.setFont(font);
		uiState.inputHintText.setCharacterSize(24);
		uiState.inputHintText.setFillColor(sf::Color::White);
		uiState.inputHintText.setString("Use arrow keys to move, Space to restart, ESC to exit"); // выводит эту надпись на экране
		uiState.inputHintText.setOrigin(GetTextOrigin(uiState.inputHintText, { 1.f, 0.f } )); // устанавливает местоположение на экране для надписи выше

		uiState.isGameOverTextVisible = false; //При соприкосновением с краем окра выводит надпись игра окончена красного цвета
		uiState.gameOverText.setFont(font);
		uiState.gameOverText.setCharacterSize(48);
		uiState.gameOverText.setStyle(sf::Text::Bold);
		uiState.gameOverText.setFillColor(sf::Color::Red);
		uiState.gameOverText.setString("GAME OVER");
		uiState.gameOverText.setOrigin(GetTextOrigin(uiState.gameOverText, { 0.5f, 0.5f })); // устанавливает местоположение на экране для надписи выше
	}

	void UpdateUI(UIState& uiState, const struct GameState& gameState, float timeDelta)
	{
		uiState.scoreText.setString("Bananas eaten: " + std::to_string(gameState.numEatenApples)); //замененое на бананы

		uiState.isGameOverTextVisible = gameState.isGameOver;
		sf::Color gameOverTextColor = (int)gameState.timeSinceGameOver % 2? sf::Color::Red : sf::Color::Yellow;
		uiState.gameOverText.setFillColor(gameOverTextColor);
	}

	void DrawUI(UIState& uiState, sf::RenderWindow& window)
	{
		uiState.scoreText.setPosition(10.f, 10.f); //местоположение блока счёта на экране
		window.draw(uiState.scoreText);

		uiState.inputHintText.setPosition(window.getSize().x - 10.f, 10.f); //местоположение блока управления на экране
		window.draw(uiState.inputHintText);

		if (uiState.isGameOverTextVisible)
		{
			uiState.gameOverText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); //местоположение блока конца игры на экране
			window.draw(uiState.gameOverText);
		}
	}

}

