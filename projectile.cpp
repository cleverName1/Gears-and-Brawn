#include "projectile.h"



projectile::projectile()
{
}

void projectile::update(int facingDirection) {

	// 0 = Above, 1 = Below, 2 = Right, 3 = Left 

	projectileSpeed = 5;
	projectileSpeedX = 0;
	projectileSpeedY = 0;

	if (facingDirection == 0) {
		projectileSpeedY = -projectileSpeed;
	}
	if (facingDirection == 1) {
		projectileSpeedY = projectileSpeed;
	}
	if (facingDirection == 2) {
		projectileSpeedX = projectileSpeed;
	}
	if (facingDirection == 3) {
		projectileSpeedX = -projectileSpeed;
	}


	// Move projectile
	sprite.move(sf::Vector2f(projectileSpeedX, projectileSpeedY));
}


projectile::~projectile()
{
}
