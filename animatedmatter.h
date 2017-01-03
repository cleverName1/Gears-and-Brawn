#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity.h"
using namespace std;

class animatedmatter: public entity
{
public:
	int frameCounter = 1;
	int animationCounter = 0;


	animatedmatter();

	void update();
	void setTextureRect();

	~animatedmatter();
};

