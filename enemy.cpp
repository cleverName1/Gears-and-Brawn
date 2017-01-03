#include "enemy.h"



enemy::enemy()
{
	sprite.setOrigin(0, 0);
	sprite.setTextureRect(sf::IntRect(animationCounter * 0, 0, 60, 60));
}

int enemy::getHealth() {
	if (!health) {
		health = 4;
	};
	return this->health;
}

void enemy::update(int time)
{

	// 0 = Above, 1 = Below, 2 = Right, 4 = Left 

	speedY = 0;
	speedX = 0;
	direction = time;

	if (direction == 0) {
		speedY = -1;
	}
	if (direction == 1 || direction == 2) {
		speedX = -1;
		animationCounter = 0;
		sprite.setTextureRect(sf::IntRect(animationCounter * 0, 0, 60, 60));
	}
	if (direction == 3 ) {
		speedY = 1;

	}
	if (direction == 4 || direction == 5) {
		speedX = 1;
		animationCounter = 1;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 0, 60, 60));
	}


	int lastMovement = time;
	// Move enemy
	sprite.move(sf::Vector2f(speedX, speedY));
}



enemy::~enemy()
{
}
