#include "matter.h"


// Constructor
matter::matter(float hitboxWidth,float hitboxHeight,float hitboxX,float hitboxY)
{
	sprite.setOrigin(0, 0);
	hitRect.setSize(sf::Vector2f(hitboxWidth, hitboxHeight));
	//	hitRect.setSize(sf::Vector2f(70, 50));
	
		hitRect.setPosition(sf::Vector2f(hitboxX, hitboxY));

		hitboxX2 = hitboxX;
		hitboxY2 = hitboxY;
}

void matter::update(float hitboxX, float hitboxY)
{
	hitRect.setPosition(sf::Vector2f(hitboxX + hitboxX2,hitboxY + hitboxY2));
}

// Destructor
matter::~matter()
{
}
