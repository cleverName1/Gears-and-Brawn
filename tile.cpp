#include "tile.h"


// Constructor
tile::tile()
{
	sprite.setOrigin(0, 0);
}

void tile::rotate90() {
	sprite.setRotation(90);
}

// Destructor
tile::~tile()
{
}
