#include "world.h"



world::world(float hitboxWidth, float hitboxHeight, float hitboxX, float hitboxY)
{
	hitRect.setSize(sf::Vector2f(hitboxWidth, hitboxHeight));
	//	hitRect.setSize(sf::Vector2f(70, 50));

	hitRect.setPosition(sf::Vector2f(hitboxX, hitboxY));

	hitboxX2 = hitboxX;
	hitboxY2 = hitboxY;
}

void world::setTileIsWalkable(bool playerCanWalkHere) {
		walkable = playerCanWalkHere;
}

bool world::tileIsWalkable() {
	return walkable;
}

void world::update(float hitboxX, float hitboxY)
{
	hitRect.setPosition(sf::Vector2f(hitboxX + hitboxX2, hitboxY + hitboxY2));
}


world::~world()
{
}
