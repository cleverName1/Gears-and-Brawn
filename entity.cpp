#include "entity.h"


entity::entity()
{
}


int * entity::collision(float playerX, float playerY, float playerWidth, float playerHeight)
{
	float objectWidth = hitRect.getGlobalBounds().width;
	float objectHeight = hitRect.getGlobalBounds().height;
	float objectX = hitRect.getPosition().x;
	float objectY = hitRect.getPosition().y;


	int directions[4] = { 0, 0, 0, 0 };
//	std::cout << objectWidth << " | " << objectHeight << " | " << objectX << " | " << objectY << " | OBJECT " << endl;
//	std::cout << playerWidth << " | " << playerHeight << " | " << playerX << " | " << playerY << " | PLAYER " << endl;



	
	// ABOVE
	if (playerY < objectY && playerY + playerHeight > objectY && playerY < objectY + objectHeight && playerX + playerWidth > objectX + 10 && playerX < objectX + objectWidth - 10) {
	//	std::cout << "1 \n";
		directions[0] = 1;
		//return 1;
		
	}

	// BELOW
	if (playerY > objectY && playerY + playerHeight > objectY + objectHeight && playerX + playerWidth > objectX + 10 && playerX < objectX + objectWidth - 10) {
	//	std::cout << "2 \n";
		directions[1] = 1;
		//return 2;

	}

	// RIGHT
	if (playerX < objectX && playerX + playerWidth > objectX && playerY + playerHeight > objectY + 10 && playerY < objectY + objectHeight - 10) {
	//	std::cout << "3 \n";
		directions[2] = 1;
		//return 3;

	}

	// LEFT
	if (playerX > objectX && playerX < objectX + objectWidth && playerWidth + playerX > objectX + objectWidth && playerY + playerHeight > objectY + 10 && playerY < objectY + objectHeight - 10) {
	//	std::cout << "4 \n";
		directions[3] = 1;
		//return 4;

	}
	
	return directions;



}





entity::~entity()
{
}
