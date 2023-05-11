/*
* Determines if an enemy has a direct line of sight that is unobstructed by cover.
* Utilizes cross products to determine if all 4 vertices of a cover point are all on
* the same side of the line between the enemy and player
*/
#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"
#include "Cover.h"
#include <vector>

class LineOfSight : FloatFunctor {

public:

	float operator()(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers);

};
