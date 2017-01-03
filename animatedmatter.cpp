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

	// frameCounter anv�nds f�r att visa animationen i r�tt hastighet, m�ste modifieras om framerate �ndras.
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
