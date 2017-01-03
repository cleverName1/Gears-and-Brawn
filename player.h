#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity.h"

using namespace std;

class player
{
public:
	int frameCounter = 1;
	int animationCounter = 0;
	int projectileDamage = 3;
	int projectiletype = 1;
	double speedX = 0;
	double speedY = 0;
	int direction = 0;
	int facingDir = 0;

	sf::Sprite sprite;

	player();
	void update();
	void movement();
	int facingDirection();
	void collision(int direction);

	~player();
};

