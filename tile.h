#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity.h"
using namespace std;

class tile: public entity
{
public:
	tile();
	void rotate90();

	~tile();
};

