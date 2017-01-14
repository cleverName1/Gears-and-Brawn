#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity.h"
using namespace std;

class world: public entity
{
public:
	float hitboxX2 = 0;
	float hitboxY2 = 0;
	int type;
	int tileNumber;

	bool walkable;
	world(float hitboxWidth, float hitboxHeight, float hitboxX, float hitboxY);

	void setTileIsWalkable(bool playerCanWalkHere);
	bool tileIsWalkable();
	void update(float hitboxX, float hitboxY);
	void setTileNumber(int value);
	int getTileNumber();

	~world();
};

