#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity.h"
using namespace std;

class matter: public entity
{
public:
	float hitboxX2 = 0;
	float hitboxY2 = 0;



	matter(float hitboxWidth, float hitboxHeight, float hitboxX, float hitboxY);
	void update(float hitboxX, float hitboxY);

	~matter();
};

