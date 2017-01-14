#include "matter.h"


// Constructor, shape 1 = rectangular, shape 2 = circular
matter::matter(float hitboxWidth,float hitboxHeight,float hitboxX,float hitboxY, int shape)
{
	sprite.setOrigin(0, 0);

	if (shape == 1) {

		hitRect.setSize(sf::Vector2f(hitboxWidth, hitboxHeight));
		hitRect.setPosition(sf::Vector2f(hitboxX, hitboxY));
	}

	if (shape == 2) {
		hitCirc.setRadius(hitboxWidth);
		hitCirc.setPosition(sf::Vector2f(hitboxX, hitboxY));
	}

		hitboxX2 = hitboxX;
		hitboxY2 = hitboxY;
		shapeOfHitArea = shape;
}

void matter::update(float hitboxX, float hitboxY)
{

	if (shapeOfHitArea == 1) {
		hitRect.setPosition(sf::Vector2f(hitboxX + hitboxX2, hitboxY + hitboxY2));
	}
	if (shapeOfHitArea == 2) {
		hitCirc.setPosition(sf::Vector2f(hitboxX + hitboxX2, hitboxY + hitboxY2));
	}

}

int matter::getShape() {

	return shapeOfHitArea;
}


// Destructor
matter::~matter()
{
}
