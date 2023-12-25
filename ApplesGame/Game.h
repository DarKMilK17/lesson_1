#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Apple.h"
#include "UI.h"
#include "GameSettings.h"

namespace ApplesGame //название переменной
{
	struct GameState //создание структуры
	{
		Player player;
		Apple apples[NUM_APPLES];
		int numEatenApples = 0;
		UIState uiState;
		bool isGameOver = false;
		float timeSinceGameOver = 0.f;

		// Game resources - хагрузка шрифтов, картинок
		sf::Font font;
		sf::Texture playerTexture;
		sf::Texture appleTexture;
	};

	void InitGame(GameState& gameState);
	void RestartGame(GameState& gameState);
	void HandleInput(GameState& gameState);
	void UpdateGame(GameState& gameState, float timeDelta);
	void DrawGame(GameState& gameState, sf::RenderWindow& window);
}
