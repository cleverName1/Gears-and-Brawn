#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "player.h"
using namespace std;

class entity
{
public:
	sf::Sprite sprite;
	float playerX = 0;
	float playerY = 0;
	float playerHeight = 0;
	float playerWidth = 0;
	double speedX = 0;
	double speedY = 0;


	entity();
	float collision(float playerX, float playerY, float playerWidth, float playerHeight);

	~entity();
};

