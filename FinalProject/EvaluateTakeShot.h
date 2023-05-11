/*
* Evaluates the quality of the shot given the enemy/player positions and cover in the way
* mainly focuses on their being a line of sight to the enemy with a minor penalty for
* being at the very edge of weapon range.
*/
#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"
#include "Cover.h"
#include <vector>

class EvaluateTakeShot : FloatFunctor {

public:

	float operator()(Vec2 enemyPos, Vec2 playerPos, std::vector<Cover*> covers, float weaponRange);

};