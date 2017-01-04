#include "player.h"


// Constructor
player::player()
{
	sprite.setOrigin(0, 0);
	sprite.setPosition(100, 250);
	sprite.setTextureRect(sf::IntRect(animationCounter * 0, 0, 60, 60));
}





void player::update()
{

	// Add friction on X and Y axis

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
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
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
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
	}




	// Set max speeds
	if (speedX > 3)
	{
		speedX = 3;
	}

	if (speedX < -3)
	{
		speedX = -3;
	}
	if (speedY > 3)
	{
		speedY = 3;
	}

	if (speedY < -3)
	{
		speedY = -3;
	}

	// Move player
	sprite.move(sf::Vector2f(speedX, speedY));
}

void player::collision(int direction)
{
	// 1 = Above, 2 = Below, 3 = Right, 4 = Left 

	if (direction == 1) {
		speedY = -3;
	}
	if (direction == 2) {
		speedY = 3;
	}
	if (direction == 3) {
		speedX = -3;
	}
	if (direction == 4) {
		speedX = 3;
	}
}


void player::movement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (animationCounter > 1) {
			animationCounter = 0;
		}
		facingDir = 0;
		speedY -= 0.2;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 240, 60, 60));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (animationCounter > 1) {
			animationCounter = 0;
		}
		facingDir = 1;
		speedY += 0.2;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 300, 60, 60));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (animationCounter > 3) {
			animationCounter = 0;
		}
		facingDir = 2;
		speedX += 0.2;
		sprite.setTextureRect(sf::IntRect(animationCounter * 60, 120, 60, 60));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (animationCounter > 3) {
			animationCounter = 0;
		}
		facingDir = 3;
		speedX -= 0.2;
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
