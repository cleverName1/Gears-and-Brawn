#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "player.h"

class projectile: public entity
{
public:
	float projectileSpeedY;
	float projectileSpeedX;
	float projectileSpeed;
	sf::Sprite sprite;

	projectile();

	void update(int facingDirection);

	~projectile();
};

