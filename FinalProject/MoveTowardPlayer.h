/*
* Checks if the destintion point given brings the enemy closer to the player
*/
#pragma once

#include "FloatFunctor.h"
#include "Vec2.h"

class MoveTowardPlayer : public FloatFunctor {

public:

	float operator()(Vec2 enemyPos, Vec2 destPos, Vec2 playerPos);
};