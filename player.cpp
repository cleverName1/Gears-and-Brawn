#include "player.h"


// Constructor
player::player()
{
	sprite.setOrigin(0, 0);
	sprite.setPosition(500, 130);
	sprite.setTextureRect(sf::IntRect(animationCounter * 0, 0, 60, 60));
	hitRect.setSize(sf::Vector2f(30, 40));
	hitRect.setPosition(sf::Vector2f(sprite.getPosition().x + 10, sprite.getPosition().y + 10));
}





void player::update()
{

	hitRect.setPosition(sf::Vector2f(sprite.getPosition().x + 15, sprite.getPosition().y + 20));



	// Add friction on X and Y axis
	
	//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (speedX <= 0.4  && speedX >= 0.0) {
			speedX = 0;
		}
		if (speedX >= -0.4  && speedX <= 0.0) {
			speedX = 0;
		}
		if (speedX >= 0.2) {
			speedX -= 0.2;
		}
		if (speedX <= -0.2) {
			speedX += 0.2;
		}
	//}

	//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (speedY <= 0.4  && speedY >= 0.0) {
			speedY = 0;
		}
		if (speedY >= -0.4  && speedY <= 0.0) {
			speedY = 0;
		}
		if (speedY >= 0.2) {
			speedY -= 0.2;
		}
		if (speedY <= -0.2) {
			speedY += 0.2;
		}
		
	//}
	




	// Set max speeds
	if (speedX > 2)
	{
		speedX = 2;
	}

	if (speedX < -2)
	{
		speedX = -2;
	}
	if (speedY > 2)
	{
		speedY = 2;
	}

	if (speedY < -2)
	{
		speedY = -2;
	}

	// Move player
	sprite.move(sf::Vector2f(speedX, speedY));
}

void player::collision(int direction1, int direction2, int direction3, int direction4)
{
	// 1 = Above, 2 = Below, 3 = Right, 4 = Left 
//	std::cout << direction1 << " | " << direction2 << " | " << direction3 << " | " << direction4 << " | " << endl;

	/*
	if (direction != 1 || direction != 2 || direction != 3 || direction != 4) {
		speedY = -speedY;
		speedX = -2;
	}
	*/

	if (direction1 == 1) {
		speedY -= 2;

	}
	if (direction2 == 1) {
		speedY += 2;

	}
	if (direction3 == 1) {

		speedX -= 2;
	}
	if (direction4 == 1) {

		speedX += 2;
	}
}


void player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (animationCounter > 1) {
			animationCounter = 0;
		}
		facingDir = 0;
		speedY -= 0.5;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 240, 60, 60));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (animationCounter > 1) {
			animationCounter = 0;
		}
		facingDir = 1;
		speedY += 0.5;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 300, 60, 60));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (animationCounter > 3) {
			animationCounter = 0;
		}
		facingDir = 2;
		speedX += 0.5;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 120, 60, 60));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (animationCounter > 3) {
			animationCounter = 0;
		}
		facingDir = 3;
		speedX -= 0.5;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 180, 60, 60));

	}
	else {
		if (animationCounter > 12) {
			animationCounter = 0;
		}

		if (facingDir == 0) {

		}else if (facingDir == 1) {
			sprite.setTextureRect(sf::IntRect(animationCounter * 60, 0, 60, 60));
		}
		else if (facingDir == 2) {
			sprite.setTextureRect(sf::IntRect(3 * 60, 120, 60, 60));
		}
		else if (facingDir == 3) {
			sprite.setTextureRect(sf::IntRect(0 * 60, 180, 60, 60));
		}


	}

	// frameCounter används för att visa animationen i rätt hastighet, måste modifieras om framerate ändras.
	frameCounter++;
	if (frameCounter >= 11) {
		frameCounter = 1;
	}

	if (frameCounter == 10) {
		animationCounter++;
	}
}


int player::facingDirection() {
	if (facingDir != 0 && facingDir != 1 && facingDir != 2 && facingDir != 3) {
		facingDir = 1; 
	};
	return this->facingDir;
}


// Destructor
player::~player()
{
}
