#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity.h"

using namespace std;

class player
{
public:
	sf::RectangleShape hitRect;


	int frameCounter = 1;
	int animationCounter = 0;
	int projectileDamage = 3;
	int projectiletype = 1;
	double speedX = 0;
	double speedY = 0;
	int direction1 = 0;
	int direction2 = 0;
	int direction3 = 0;
	int direction4 = 0;
	int facingDir = 1;

	sf::Sprite sprite;

	player();
	void update();
	void movement();
	int facingDirection();
	void collision(int direction1, int direction2, int direction3, int direction4);

	~player();
};

