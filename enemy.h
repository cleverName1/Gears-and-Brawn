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
	float speedX = 0;
	float speedY = 0;
	float direction = 9;
	int lastMovement = 0;

	sf::Sprite sprite;

	enemy();
	void update(float time);
	int getHealth();

	~enemy();
};

