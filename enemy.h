#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity.h"

using namespace std;

class enemy: public entity
{
public:


	int frameCounter = 1;
	int animationCounter = 0;
	int attackDamage = 3;
	int health = 4;
	double speedX = 0;
	double speedY = 0;
	int direction = 9;
	int lastMovement = 0;

	sf::Sprite sprite;

	enemy();
	void update(int time);
	int getHealth();

	~enemy();
};

