#include "entity.h"



entity::entity()
{
}


float entity::collision(float playerX, float playerY, float playerWidth, float playerHeight)
{
	float objectWidth = sprite.getGlobalBounds().width;
	float objectHeight = sprite.getGlobalBounds().height;
	float objectX = sprite.getPosition().x;
	float objectY = sprite.getPosition().y;


	// ABOVE
	if (playerY < objectY && playerY + playerHeight > objectY && playerY < objectY + objectHeight && playerX + playerWidth > objectX + 10 && playerX < objectX + objectWidth - 10) {
		return 1;
	}

	// BELOW
	if (playerY > objectY && playerY + playerHeight > objectY + objectHeight && playerX + playerWidth > objectX + 10 && playerX < objectX + objectWidth - 10) {
		return 2;
	}

	// RIGHT
	if (playerX < objectX && playerX + playerWidth > objectX && playerY + playerHeight > objectY + 10 && playerY < objectY + objectHeight - 10) {
		return 3;
	}

	// LEFT
	if (playerX > objectX && playerX < objectX + objectWidth && playerWidth + playerX > objectX + objectWidth && playerY + playerHeight > objectY + 10 && playerY < objectY + objectHeight - 10) {
		return 4;
	}

}


entity::~entity()
{
}
