/*
* Generates a vector of all possible cover spots on the game map given the all the Covers
* in the game and the player's position.
*/
#pragma once

#include "Cover.h"
#include "Vec2.h"
#include "Constants.h"
#include <vector>

class GenerateAllCover {

public:

	std::vector<Vec2> operator()(std::vector<Cover*> covers, Vec2 playerPos);

};