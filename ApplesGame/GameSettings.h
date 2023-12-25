#pragma once
#include <string>

namespace ApplesGame
{
	// Resources path - ���� � ����� � ���������� � ��������
	const std::string RESOURCES_PATH = "Resources/";

	// Game settings constants - ������� ���������
	const float PLAYER_SIZE = 30.f; //������ �������
	const float APPLE_SIZE = 30.f/1.5; //������ ����� (������� � ���� ������)
	const float INITIAL_SPEED = 100.f*1.2; //�������� �������
	const float ACCELERATION = 5.f; // For each eaten apple player speed will be increased by this value - ��������� ������� ��� �������� ������
	const int NUM_APPLES = 20; //���������� ����� �� ������
	const unsigned int SCREEN_WIDTH = 1920; //������ ����
	const unsigned int SCREEN_HEGHT = 1080; //������ ����
}
