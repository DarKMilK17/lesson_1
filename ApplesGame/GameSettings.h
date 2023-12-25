#pragma once
#include <string>

namespace ApplesGame
{
	// Resources path - путь о папки с картинками и шрифтами
	const std::string RESOURCES_PATH = "Resources/";

	// Game settings constants - игровые настройки
	const float PLAYER_SIZE = 30.f; //размер пакмэна
	const float APPLE_SIZE = 30.f/1.5; //размер яблок (бананов в моем случае)
	const float INITIAL_SPEED = 100.f*1.2; //скорость пакмэна
	const float ACCELERATION = 5.f; // For each eaten apple player speed will be increased by this value - ускорение пакмэна при съедании яблока
	const int NUM_APPLES = 20; //количество яблок на экране
	const unsigned int SCREEN_WIDTH = 1920; //ширина окна
	const unsigned int SCREEN_HEGHT = 1080; //высота окна
}
