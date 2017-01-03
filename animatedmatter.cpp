#include "animatedmatter.h"



animatedmatter::animatedmatter()
{
	sprite.setOrigin(0, 0);
}

void animatedmatter::setTextureRect() {
	sprite.setTextureRect(sf::IntRect(0, 0, 140, 140));
}

void animatedmatter::update()
{

	if (animationCounter > 8) {
		animationCounter = 0;
	}

	sprite.setTextureRect(sf::IntRect(animationCounter * 140, 0, 140, 140));

	// frameCounter används för att visa animationen i rätt hastighet, måste modifieras om framerate ändras.
	frameCounter++;
	if (frameCounter >= 11) {
		frameCounter = 1;
	}

	if (frameCounter == 10) {
		animationCounter++;
	}
}


animatedmatter::~animatedmatter()
{
}
