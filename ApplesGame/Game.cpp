#include "Game.h"
#include <assert.h>


namespace ApplesGame
{
	void InitGame(GameState& gameState)
	{
		// Init game resources (terminate if error) - € очень долго это искал, шрифты, картинки пакмэна и €блока, последнее € заменил на банан
		assert(gameState.playerTexture.loadFromFile(RESOURCES_PATH + "Pacman.png"));
		assert(gameState.appleTexture.loadFromFile(RESOURCES_PATH + "Banana.png"));
		assert(gameState.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		InitUI(gameState.uiState, gameState.font);
		RestartGame(gameState);
	}

	void RestartGame(GameState& gameState)
	{
		// Init player
		InitPlayer(gameState.player, gameState.playerTexture);
		// Init apples
		for (int i = 0; i < NUM_APPLES; i++)
		{
			InitApple(gameState.apples[i], gameState.appleTexture);
		}

		// Init game state
		gameState.numEatenApples = 0;
		gameState.isGameOver = false;
		gameState.timeSinceGameOver = 0.f;
	}

	void HandleInput(GameState& gameState) //тут прописаны кнопки и их вли€ние на игру (пробел рестарт, вверх, вниз и пр.)
	{
		if (gameState.isGameOver)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				RestartGame(gameState);
			}

			// We don't handle input in game over state
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			gameState.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			gameState.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			gameState.player.direction = PlayerDirection::Down;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			gameState.player.direction = PlayerDirection::Left;
		}
	}

	void UpdateGame(GameState& gameState, float timeDelta)
	{
		if (!gameState.isGameOver)
		{
			// Update player - проводит проверку на столкновение с €блоком, в случае успеха спавнит новое €блоко, увеличивает статистику и увеличивает скорость)
			UpdatePlayer(gameState.player, timeDelta);

			for (int i = 0; i < NUM_APPLES; i++)
			{
				// Check collision with apple
				if (HasPlayerCollisionWithApple(gameState.player, gameState.apples[i]))
				{
					// Move apple to a new random position
					InitApple(gameState.apples[i], gameState.appleTexture);
					// Increase eaten apples counter
					gameState.numEatenApples++;
					// Increase player speed
					gameState.player.speed += ACCELERATION;
				}
			}

			// Check collision with screen border - проверка на столкновение с краем окна
			if (HasPlayerCollisionWithScreenBorder(gameState.player))
			{
				gameState.isGameOver = true;
				gameState.timeSinceGameOver = 0.f;
			}
		}
		else
		{
			gameState.timeSinceGameOver += timeDelta;
		}

		UpdateUI(gameState.uiState, gameState, timeDelta);
	}

	void DrawGame(GameState& gameState, sf::RenderWindow& window)
	{
		// Draw player
		DrawPlayer(gameState.player, window);
		// Draw apples
		for (int i = 0; i < NUM_APPLES; i++)
		{
			DrawApple(gameState.apples[i], window);
		}

		DrawUI(gameState.uiState, window);
	}
}
